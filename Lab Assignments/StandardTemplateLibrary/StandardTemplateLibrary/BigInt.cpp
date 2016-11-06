/*
 * Name: Harold Agnote
 * Student ID: 012264497
 * Class: CECS 282 - Sec. 07
 * Project Name: (Program 5 - Standard Template Library)
 * Due Date: (November 14, 2016)
 */
#include "BigInt.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

BigInt::BigInt()
{
	digits.push_back( 0 );
}

BigInt::BigInt( int x )
{
	do
	{
		if ( x != 0 )
		{
			digits.push_back( x % 10 );
			x = x / 10;
		}
	}
	while ( x > 0 );
}

BigInt::BigInt( BigInt & b )
{
	for ( b.it = b.digits.begin(); b.it < b.digits.end(); b.it++ )
	{
		digits.push_back( *b.it );
	}
}

void BigInt::clearZeroes()
{
	bool stopRemove = false;
	rit = digits.rbegin();
	while ( rit != digits.rend() )
	{
		int value = *rit;
		if (value == 0 )
		{
			++rit;
			if ( !stopRemove )
			{
				rit = vector<int>::reverse_iterator( digits.erase( rit.base() ) );
			}
		}
		else
		{
			stopRemove = true;
			++rit;
		}
	}
}

BigInt BigInt::operator+( BigInt b)
{
	BigInt result;
	result.digits.clear();
	bool addOne = false;
	int size;
	if ( digits.size() < b.digits.size() )
	{
		size = b.digits.size();
	}
	else
	{
		size = digits.size();
	}
	for ( int i = 0; i < size; i++ )
	{
		if ( ( i + 1 ) > b.digits.size() )
		{
			b.digits.push_back( 0 );
		}
		if ( ( i + 1 ) > digits.size() )
		{
			digits.push_back( 0 );
		}
		int add = digits[i] + b.digits[i];
		if ( addOne )
		{
			add++;
			addOne = false;
		}
		if ( add > 9 )
		{
			addOne = true;
			if ( i + 1 == size )
			{
				size++;
			}
			add = add % 10;
		}
		result.digits.push_back( add );
	}
	return result;
}

bool BigInt::operator<( BigInt & b )
{
	if ( digits.size() < b.digits.size() )
	{
		return true;
	}
	else if ( digits.size() > b.digits.size() )
	{
		return false;
	}
	rit = digits.rbegin();
	b.rit = b.digits.rbegin();
	while ( rit != digits.rend() )
	{
		if ( *rit < *b.rit )
		{
			return true;
		}
		else if ( *rit > *b.rit )
		{
			return false;
		}
		rit++;
		b.rit++;
	}
	return false;
}

ostream & operator<<( ostream & out, BigInt b )
{
	b.clearZeroes();

	for ( b.rit = b.digits.rbegin(); b.rit < b.digits.rend(); b.rit++ )
	{
		out << *b.rit;
	}
	return out;
}