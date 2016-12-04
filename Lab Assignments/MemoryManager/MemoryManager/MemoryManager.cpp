#include "MemoryManager.h"

#include <iomanip>
#include <iostream>

using namespace std;

namespace MemoryManager
{
	const int MM_POOL_SIZE = 65536;
	char MM_pool[MM_POOL_SIZE];

	void memView( int start, int end )
	{
		const unsigned int SHIFT = 8;
		const unsigned int MASK = 1 << SHIFT - 1;

		unsigned int value;    // Used to facilitate bit shifting and masking

		cout << "         Pool                     Unsignd  Unsigned" << endl;
		cout << "Mem Add  indx   bits   Chr ASCII#  short      int    " << endl;
		cout << "-------- ---- -------- --- ------ ------- ------------" << endl;

		for ( int i = start; i <= end; i++ )
		{
			cout << (long *) ( MM_pool + i ) << ':';    // The actual address into Hexadecimal
			cout << '[' << setw( 2 ) << i << ']';    // The index into MM_pool

			value = MM_pool[i];
			cout << " ";
			for ( int j = 1; j <= SHIFT; j++ )    // The bit sequence for this byte (8 bits)
			{
				cout << ( ( value & MASK) ? '1' : '0' );
				value <<= 1;
			}
			cout << " ";

			cout << '|' << *(char*) ( MM_pool + i ) << "| (";    // The ASCII Character of the 8 Bits (1 byte)
			cout << setw( 4 ) << ( (int) ( *( (unsigned char *) ( MM_pool + i ) ) ) ) << ")";    // The ASCII Number of the Character

			cout << "  (" << setw( 5 ) << ( *(unsigned short *) ( MM_pool + i ) ) << ")";    // The unsigned short value of 16 bits (2 Bytes)
			cout << "  (" << setw( 10 ) << ( *(unsigned int *) ( MM_pool + i ) ) << ")";
			cout << endl;
		}
	}

	void initializeMemoryManager( void )
	{
		int freeHead = 0;	// starting index of the freelist
		int inUseHead = 2;	// starting index of the inUseList - allocated memory
		int usedHead = 4;	// starting index of the used list - deallocated memory

		int nextLink = 2;	// offset index of the next link
		int prevLink = 4;	// offset index of the prev link
		int dataLink = 6;	// offset index of the data

		*(unsigned short *) ( MM_pool + freeHead ) = 6;
		//cout << "Index: Freehead ( " << freeHead << " )" << " is now " << *(unsigned short *) ( MM_pool + freeHead ) << endl;
		*(unsigned int *) ( MM_pool + 6 ) = MM_POOL_SIZE - 6;
		unsigned short x = MM_POOL_SIZE - 6;
		//cout << "Total Size: " << freeMemory() << endl;
		*(unsigned short *) ( MM_pool + inUseHead ) = 0;
		//cout << "Index: inUseHead ( " << inUseHead << " )" << " is now " << *(unsigned short *) ( MM_pool + inUseHead ) << endl;
		*(unsigned short *) ( MM_pool + usedHead ) = 0;
		//cout << "Index: usedHead ( " << usedHead << " )" << " is now " << *(unsigned short *) ( MM_pool + usedHead ) << endl;

	}

	void * allocate( int aSize )
	{
		int freeHead = 0;	// starting index of the freelist
		int inUseHead = 2;	// starting index of the inUseList - allocated memory
		int usedHead = 4;	// starting index of the used list - deallocated memory

		int nextLink = 2;	// offset index of the next link
		int prevLink = 4;	// offset index of the prev link
		int dataLink = 6;	// offset index of the data
		if ( ( freeMemory() + dataLink + aSize ) > 0 )
		{
			*(unsigned short *) ( MM_pool + *( (unsigned short *) ( MM_pool + freeHead ) ) ) = aSize;
			//cout << "Assigning Size to Index:  ( " << *(unsigned short *) ( MM_pool + freeHead ) << " )" << "\nSize is now: " << *(unsigned short *) ( MM_pool + ( *(unsigned short *) ( MM_pool + freeHead ) ) ) << endl;
			*(unsigned short *) ( MM_pool + *( (unsigned short *) ( MM_pool + freeHead ) ) + nextLink ) = *(unsigned short *) ( MM_pool + inUseHead );
			//cout << "Index " << *( (unsigned short *) ( MM_pool + freeHead ) ) + nextLink << " is now " << *(unsigned short *) ( MM_pool + inUseHead ) << endl;
			*(unsigned short *) ( MM_pool + *( (unsigned short *) ( MM_pool + freeHead ) ) + prevLink ) = 0;
			//cout << "Index " << *( (unsigned short *) ( MM_pool + freeHead ) ) + prevLink << " is now " << *(unsigned short *) ( MM_pool + *( (unsigned short *) ( MM_pool + freeHead ) ) + prevLink ) << endl;

			if ( *(unsigned short *) ( MM_pool + *( (unsigned short *) ( MM_pool + freeHead ) ) + nextLink ) != 0 )
			{
				*(unsigned short *) ( MM_pool + *(unsigned short *) ( MM_pool + *( (unsigned short *) ( MM_pool + freeHead ) ) + nextLink ) + prevLink ) = *( (unsigned short *) ( MM_pool + freeHead ) );
				//cout << "Index " << *(unsigned short *) ( MM_pool + *( (unsigned short *) ( MM_pool + freeHead ) ) + nextLink ) + prevLink << " is now " << *( (unsigned short *) ( MM_pool + freeHead ) ) << endl;
			}

			*(unsigned short *) ( MM_pool + inUseHead ) = *(unsigned short *) ( MM_pool + freeHead );
			//cout << "Index: inUseHead ( " << inUseHead << " )" << " is now " << *(unsigned short *) ( MM_pool + inUseHead ) << endl;
			*(unsigned short *) ( MM_pool + freeHead ) += nextLink + prevLink + aSize;
			//cout << "Index: Freehead ( " << freeHead << " )" << " is now " << *(unsigned short *) ( MM_pool + freeHead ) << endl;
			*(unsigned int *) ( MM_pool + *(unsigned short *) ( MM_pool + freeHead ) ) = MM_POOL_SIZE - *(unsigned short *) ( MM_pool + freeHead );
			//cout << "Total Size: " << freeMemory() << endl;
			return ( MM_pool + *(unsigned short *) ( MM_pool + inUseHead ) + dataLink );
		}
		else
		{
			onOutofMemory();
			return NULL;
		}
		
	}

	void deallocate( void * aPointer )
	{
		int freeHead = 0;	// starting index of the freelist
		int inUseHead = 2;	// starting index of the inUseList - allocated memory
		int usedHead = 4;	// starting index of the used list - deallocated memory

		int nextLink = 2;	// offset index of the next link
		int prevLink = 4;	// offset index of the prev link
		int dataLink = 6;	// offset index of the data

		
		//cout << ((char*) aPointer - dataLink) - MM_pool << endl;
		
		unsigned short temp = 0;

		if ( *(unsigned short *) ( MM_pool + ( ( (char*) aPointer - dataLink ) - MM_pool ) + nextLink ) != 0)
		{
			*(unsigned short *) ( MM_pool + ( *(unsigned short *) ( MM_pool + ( ( (char*) aPointer - dataLink ) - MM_pool ) + nextLink ) ) + prevLink ) = ( *(unsigned short *) ( MM_pool + ( ( (char*) aPointer - dataLink ) - MM_pool ) + prevLink ));
		}

		if ( *(unsigned short *) ( MM_pool + ( ( (char*) aPointer - dataLink ) - MM_pool ) + prevLink ) != 0 )
		{
			*(unsigned short *) ( MM_pool + ( *(unsigned short *) ( MM_pool + ( ( (char*) aPointer - dataLink ) - MM_pool ) + prevLink ) ) + nextLink ) = ( *(unsigned short *) ( MM_pool + ( ( (char*) aPointer - dataLink ) - MM_pool ) + nextLink ));
		}
		
		if ( ( *(unsigned short *) ( MM_pool + inUseHead ) ) == ( ( ( ( (char*) aPointer - dataLink ) - MM_pool ) ) ) )
		{
			( *(unsigned short *) ( MM_pool + inUseHead ) ) = *(unsigned short *) ( MM_pool + (*(unsigned short *) (MM_pool + inUseHead)) + nextLink );
		}

		( *(unsigned short *) ( MM_pool + ( ( (char*) aPointer - dataLink ) - MM_pool ) + prevLink ) ) = 0;

		( *(unsigned short *) ( MM_pool + ( ( (char*) aPointer - dataLink ) - MM_pool ) + nextLink ) ) = *(unsigned short *) ( MM_pool + usedHead );

		if ( *(unsigned short *) ( MM_pool + ( ( (char*) aPointer - dataLink ) - MM_pool ) + nextLink ) != 0 )
		{
			*(unsigned short *) ( MM_pool + ( *(unsigned short *) ( MM_pool + ( ( (char*) aPointer - dataLink ) - MM_pool ) + nextLink ) ) + prevLink ) = ( ( (char*) aPointer - dataLink ) - MM_pool );
		}

		*(unsigned short *) ( MM_pool + usedHead ) = ( ( (char*) aPointer - dataLink ) - MM_pool );
		//cout << "Hello!\n";

	}

	int freeMemory( void )
	{
		int size = MM_POOL_SIZE;
		size -= usedMemory();
		size -= inUseMemory();
		size -= 6;

		return size;
	}

	int usedMemory( void )
	{
		int usedHead = 4;	// starting index of the used list - deallocated memory
		int nextLink = 2;	// offset index of the next link
		int dataLink = 6;	// offset index of the data

		unsigned short nextNode = *(unsigned short *) ( MM_pool + usedHead );

		int usedTotal = 0;
		while ( nextNode != 0 )
		{
			usedTotal += dataLink;
			usedTotal += *(unsigned short *) ( MM_pool + nextNode );

			nextNode = *(unsigned short *) ( MM_pool + nextNode + nextLink );
		}

		return usedTotal;
	}

	int inUseMemory( void )
	{
		int inUseHead = 2;	// starting index of the inUseList - allocated memory
		int nextLink = 2;	// offset index of the next link
		int dataLink = 6;	// offset index of the data

		unsigned short nextNode = *(unsigned short * ) ( MM_pool + inUseHead );

		int inUseTotal = 0;
		while (nextNode != 0 )
		{
			inUseTotal += dataLink;
			inUseTotal += *(unsigned short *) ( MM_pool + nextNode ) ;

			nextNode = *(unsigned short *) ( MM_pool + nextNode + nextLink );
		}

		return inUseTotal;
	}

	void onOutofMemory( void )
	{
		cout << "NO MORE MEMORY!" << endl;
	}
}