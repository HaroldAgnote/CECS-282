#include "BigInt.h"
#include <vector>
#include <iostream>

using namespace std;

int msain()
{
	while ( true )
	{
		int xNum;
		int yNum;
		cout << "Enter number for x" << endl;
		cin >> xNum;
		cout << "Enter number for y" << endl;
		cin >> yNum;

		BigInt x( xNum );
		BigInt y( yNum );

		cout << x << " - " << y << " = " << x - y << endl;

	}

	system( "pause" );
	return 0;
}