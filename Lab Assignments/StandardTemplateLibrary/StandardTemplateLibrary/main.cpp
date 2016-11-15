/*
 * Name: Harold Agnote
 * Student ID: 012264497
 * Class: CECS 282 - Sec. 07
 * Project Name: (Program 5 - Standard Template Library)
 * Due Date: (November 14, 2016)
 */
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
	/*
	cout << "Now Let's Do BigInts!" << endl;

	for ( int i = 0; i <= 1000; i++ )
	{
		BigInt x( i );
		int current = time( 0 );
		cout << setw( 5 ) << current - start << ":";	//print elapsed seconds
		cout << "	Gold Rabbits(" << setw( 2 ) << i << ") = ";
		cout << setw( 11 ) << goldRabbits( x ) << endl;
	}
	*/
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
/*
BigInt goldRabbits( BigInt b )
{
	static map <BigInt, BigInt> bigValues;
	map <BigInt, BigInt>::iterator it;
	it = bigValues.find( b );
	if ( it != bigValues.end() )
	{
		return bigValues[b];
	}
	else
	{
		if ( ( b == 0 ) || ( b == 1 ) )
		{
			BigInt one( 1 );
			bigValues[b] = one;
		}
		else
		{
			BigInt one( 1 );
			BigInt two( 2 );
			bigValues[b] = goldRabbits( b - one ) + goldRabbits( b - two );
		}
		return bigValues[b];
	}
}*/