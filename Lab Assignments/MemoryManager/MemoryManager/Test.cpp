#include "MemoryManager.h"
#include <iostream>
using namespace std;
using namespace MemoryManager;

int madin()
{
	initializeMemoryManager();
	char * name = (char *) allocate( 8 );
	name  = (char *) allocate( 16 );
	name = (char *) allocate( 5 );
	int * array = (int *) allocate( 9 * sizeof( int ) );
	deallocate(name);
	name = (char *) allocate( 6 );
	deallocate( array );
	system( "pause" );
	return 0;
}