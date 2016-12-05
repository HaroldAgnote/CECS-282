/*
 * Name: Harold Agnote
 * Student ID: 012264497
 * Class: CECS 282 - Sec. 07
 * Project Name: (Program 5 - Standard Template Library)
 * Due Date: (November 14, 2016)
 */
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

		*(unsigned short *) ( MM_pool + freeHead ) = 6;		// First Free Space is Index 6
		//cout << "Index: Freehead ( " << freeHead << " )" << " is now " << *(unsigned short *) ( MM_pool + freeHead ) << endl;
		*(unsigned int *) ( MM_pool + 6 ) = MM_POOL_SIZE - 6;	// Total Free Space Left
		//cout << "Total Size: " << freeMemory() << endl;
		*(unsigned short *) ( MM_pool + inUseHead ) = 0;	// First In Use Space is Index 0 (null)
		//cout << "Index: inUseHead ( " << inUseHead << " )" << " is now " << *(unsigned short *) ( MM_pool + inUseHead ) << endl;
		*(unsigned short *) ( MM_pool + usedHead ) = 0;		// First Used Space is Index 0 (null)
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
		if ( ( freeMemory() + dataLink + aSize ) > 0 )	// If there is still free space
		{
			*(unsigned short *) ( MM_pool + *( (unsigned short *) ( MM_pool + freeHead ) ) ) = aSize;	// Set size of Node's Data Pool to aSize
			//cout << "Assigning Size to Index:  ( " << *(unsigned short *) ( MM_pool + freeHead ) << " )" << "\nSize is now: " << *(unsigned short *) ( MM_pool + ( *(unsigned short *) ( MM_pool + freeHead ) ) ) << endl;
			*(unsigned short *) ( MM_pool + *( (unsigned short *) ( MM_pool + freeHead ) ) + nextLink ) = *(unsigned short *) ( MM_pool + inUseHead );	// Set Node's Next link to whatever is currently inUse
			//cout << "Index " << *( (unsigned short *) ( MM_pool + freeHead ) ) + nextLink << " is now " << *(unsigned short *) ( MM_pool + inUseHead ) << endl;
			*(unsigned short *) ( MM_pool + *( (unsigned short *) ( MM_pool + freeHead ) ) + prevLink ) = 0;	// Set Node's Previous Link to Index 0 (Null) since Node is most recently allocated.
			//cout << "Index " << *( (unsigned short *) ( MM_pool + freeHead ) ) + prevLink << " is now " << *(unsigned short *) ( MM_pool + *( (unsigned short *) ( MM_pool + freeHead ) ) + prevLink ) << endl;
			if ( *(unsigned short *) ( MM_pool + *( (unsigned short *) ( MM_pool + freeHead ) ) + nextLink ) != 0 )	// Check if there is something after this Node
			{
				*(unsigned short *) ( MM_pool + *(unsigned short *) ( MM_pool + *( (unsigned short *) ( MM_pool + freeHead ) ) + nextLink ) + prevLink ) = *( (unsigned short *) ( MM_pool + freeHead ) );	// Set the Previous Link of the Node after this Node to point to this Node
				//cout << "Index " << *(unsigned short *) ( MM_pool + *( (unsigned short *) ( MM_pool + freeHead ) ) + nextLink ) + prevLink << " is now " << *( (unsigned short *) ( MM_pool + freeHead ) ) << endl;
			}

			*(unsigned short *) ( MM_pool + inUseHead ) = *(unsigned short *) ( MM_pool + freeHead );	// Set the inUse to point to this Node
			//cout << "Index: inUseHead ( " << inUseHead << " )" << " is now " << *(unsigned short *) ( MM_pool + inUseHead ) << endl;
			*(unsigned short *) ( MM_pool + freeHead ) += nextLink + prevLink + aSize;	// Calculate the next Free Spot in the Memory Space
			//cout << "Index: Freehead ( " << freeHead << " )" << " is now " << *(unsigned short *) ( MM_pool + freeHead ) << endl;
			*(unsigned int *) ( MM_pool + *(unsigned short *) ( MM_pool + freeHead ) ) = MM_POOL_SIZE - *(unsigned short *) ( MM_pool + freeHead );	// Calculate the amount of free space left
			//cout << "Total Size: " << freeMemory() << endl;
			return ( MM_pool + *(unsigned short *) ( MM_pool + inUseHead ) + dataLink );	// Return this Node's Data Pool
		}
		else	// No more Memory
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

		
		//cout << ((char*) aPointer - dataLink) - MM_pool << endl;	// Prints out the starting Index of the Node to be deallocated
		
		unsigned short temp = 0;

		if ( *(unsigned short *) ( MM_pool + ( ( (char*) aPointer - dataLink ) - MM_pool ) + nextLink ) != 0)	// Checks if something is after this Node
		{
			*(unsigned short *) ( MM_pool + ( *(unsigned short *) ( MM_pool + ( ( (char*) aPointer - dataLink ) - MM_pool ) + nextLink ) ) + prevLink ) = ( *(unsigned short *) ( MM_pool + ( ( (char*) aPointer - dataLink ) - MM_pool ) + prevLink ));	// Sets the previous Link of the Next Node to point to this Node's Previous Link
		}

		if ( *(unsigned short *) ( MM_pool + ( ( (char*) aPointer - dataLink ) - MM_pool ) + prevLink ) != 0 )	// Checks if something is before this Node
		{
			*(unsigned short *) ( MM_pool + ( *(unsigned short *) ( MM_pool + ( ( (char*) aPointer - dataLink ) - MM_pool ) + prevLink ) ) + nextLink ) = ( *(unsigned short *) ( MM_pool + ( ( (char*) aPointer - dataLink ) - MM_pool ) + nextLink ));	// Sets the Next Link of the Previous Node to point to this Node's Next Link
		}
		
		if ( ( *(unsigned short *) ( MM_pool + inUseHead ) ) == ( ( ( ( (char*) aPointer - dataLink ) - MM_pool ) ) ) )	// Checks if this Node is the most recently allocated Node (inUse)
		{
			( *(unsigned short *) ( MM_pool + inUseHead ) ) = *(unsigned short *) ( MM_pool + (*(unsigned short *) (MM_pool + inUseHead)) + nextLink );	// Sets the most recently allocated Node (inUse) to this Node's next link
		}

		( *(unsigned short *) ( MM_pool + ( ( (char*) aPointer - dataLink ) - MM_pool ) + prevLink ) ) = 0;		// Sets the previous link of this deallocated Node to 0 since it is the most recent deallocated Node

		( *(unsigned short *) ( MM_pool + ( ( (char*) aPointer - dataLink ) - MM_pool ) + nextLink ) ) = *(unsigned short *) ( MM_pool + usedHead );	// Sets the next link of this deallocated Node to what was previously deallocated

		if ( *(unsigned short *) ( MM_pool + ( ( (char*) aPointer - dataLink ) - MM_pool ) + nextLink ) != 0 )	// Checks if something is after this deallocated Node
		{
			*(unsigned short *) ( MM_pool + ( *(unsigned short *) ( MM_pool + ( ( (char*) aPointer - dataLink ) - MM_pool ) + nextLink ) ) + prevLink ) = ( ( (char*) aPointer - dataLink ) - MM_pool ); // Sets the previous link of the Node after this deallocated Node to point to this deallocated Node
		}

		*(unsigned short *) ( MM_pool + usedHead ) = ( ( (char*) aPointer - dataLink ) - MM_pool );		// Updates the most recently deallocated Node (usedHead) to point to this deallocated Node

	}

	int freeMemory( void )
	{
		int size = MM_POOL_SIZE;	// Entire Size of Memory Pool
		size -= usedMemory();		// Size = Size - deallocated (used) memory
		size -= inUseMemory();		// Size = Size - allocated (inUse) memory
		size -= 6;					// Size = Size - first 6 Bytes of Memory Manager

		return size;
	}

	int usedMemory( void )
	{
		int usedHead = 4;	// starting index of the used list - deallocated memory
		int nextLink = 2;	// offset index of the next link
		int dataLink = 6;	// offset index of the data

		unsigned short nextNode = *(unsigned short *) ( MM_pool + usedHead );	// Set iterating Node to the Node that was most recently deallocated (usedHead)

		int usedTotal = 0;	// Initialize sum of usedMemory
		while ( nextNode != 0 )	// Check if the iterating Node does not point to a null location
		{
			usedTotal += dataLink;	// Add the size of first six bytes containing meta information of the Node (size of data pool (2 bytes), next link (2 bytes), prev link (2 bytes) = 6 bytes total)
			usedTotal += *(unsigned short *) ( MM_pool + nextNode );	// Add the size of this Node's data pool

			nextNode = *(unsigned short *) ( MM_pool + nextNode + nextLink );	// Set iterating Node to the next Node that this Node is pointing to.
		}

		return usedTotal;
	}

	int inUseMemory( void )
	{
		int inUseHead = 2;	// starting index of the inUseList - allocated memory
		int nextLink = 2;	// offset index of the next link
		int dataLink = 6;	// offset index of the data

		unsigned short nextNode = *(unsigned short * ) ( MM_pool + inUseHead );	// Set iterating Node to the Node that was most recently allocated (inUseHead)

		int inUseTotal = 0;	// Initialize sum of inUseMemory
		while (nextNode != 0 )	// Check if the iterating Node does not point to a null location
		{
			inUseTotal += dataLink;	// Add the size of first six bytes containing meta information of the Node (size of data pool (2 bytes), next link (2 bytes), prev link (2 bytes) = 6 bytes total)
			inUseTotal += *(unsigned short *) ( MM_pool + nextNode ) ;	// Add the size of this Node's data pool

			nextNode = *(unsigned short *) ( MM_pool + nextNode + nextLink );	// Set iterating Node to the next Node that this Node is pointing to.
		}

		return inUseTotal;
	}

	void onOutofMemory( void )
	{
		cout << "\nNO MORE MEMORY!" << endl;
	}
}