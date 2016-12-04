#include "MemoryManager.h"
#include <iostream>
using namespace std;
using namespace MemoryManager;

int maijn()
{
	initializeMemoryManager();
	char * name = (char *) allocate( 10 );
	int * grade = (int *) allocate( 4 );
	*grade = 100;
	cout << ( *grade ) << endl;
	allocate( 12 );
	deallocate( grade );
	deallocate( name );
	system( "pause" );
	return 0;
}