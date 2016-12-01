#include "MemoryManager.h"

#include <iomanip>
#include <iostream>

using namespace std;

namespace MemoryManager
{
	const int MM_POOL_SIZE = 66536;
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
	}

	void * allocate( int aSize )
	{

	}

	void deallocate( void * aPointer )
	{

	}

	int freeMemory( void )
	{

	}

	int usedMemory( void )
	{

	}

	int inUseMemory( void )
	{

	}
}