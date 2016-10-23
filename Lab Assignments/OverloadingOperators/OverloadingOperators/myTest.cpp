#include "upDate.h"
#include <iostream>
using namespace std;

int ain()
{
	upDate today( 10, 24, 2016 );

	upDate first( 1, 1, -4712 );

	cout << today.julian() << endl;

	cout << today - today.julian() << endl;

	cout << first << endl;

	cout << first.julian() << endl;

	system( "pause" );
	return 0;
}
