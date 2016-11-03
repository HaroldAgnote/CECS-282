#include <iostream>
#include <time.h>
#include <iomanip>
#include <vector>
#include <map>

using namespace std;

int goldRabbits( int );

int main()
{
	int const months = 12 * 10; // 10 Years
	int start = time( 0 );
	for ( int i = 0; i < months; i++ )
	{
		int current = time( 0 );
		cout << setw( 5 ) << current - start << ":";	//print elapsed seconds
		cout << "	Gold Rabbits(" << setw( 2 ) << i << ") = ";
		cout << setw( 11 ) << goldRabbits( i ) << endl;
	}

	system( "pause" );
	return 1;
}

int goldRabbits( int n )
{
	static map <int, int> values;

	if ( values.find( n ) != values.end() )	// Key found in map
	{
		return values[n];
	}
	else // Key not in Map
	{
		if ( ( n == 0 ) || ( n == 1 ) )
		{
			values.insert( pair <int, int>( n, 1 ));
		}
		else
		{
			values.insert( pair <int, int>( n, goldRabbits( n - 1 ) + goldRabbits( n - 2 ) ) );
		}
		return values[n];
	}
	
}