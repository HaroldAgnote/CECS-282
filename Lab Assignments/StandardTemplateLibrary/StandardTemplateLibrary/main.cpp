#include <iostream>
#include <time.h>
#include <iomanip>
#include <map>
#include "BigInt.h"

using namespace std;

BigInt goldRabbits( int );

int main()
{
	int start = time( 0 );
	for ( int i = 0; i <= 1000; i++ )
	{
		int current = time( 0 );
		cout << setw( 5 ) << current - start << ":";	//print elapsed seconds
		cout << "	Gold Rabbits(" << setw( 2 ) << i << ") = ";
		cout << setw( 11 ) << goldRabbits( i ) << endl;
	}

	system( "pause" );
	return 1;
}

BigInt goldRabbits( int n )
{
	static map <int, BigInt> values;
	map <int, BigInt>::iterator it;
	it = values.find( n );
	if ( it != values.end() )	// Key found in map
	{
		return values[n];
	}
	else // Key not in Map
	{
		if ( ( n == 0 ) || ( n == 1 ) )
		{
			BigInt one( 1 );
			values[n] = one;
		}
		else
		{
			values[n] = goldRabbits( n - 1 ) + goldRabbits( n - 2 );
		}
		return values[n];
	}
	
}