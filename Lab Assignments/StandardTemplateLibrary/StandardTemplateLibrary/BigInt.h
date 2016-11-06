/*
 * Name: Harold Agnote
 * Student ID: 012264497
 * Class: CECS 282 - Sec. 07
 * Project Name: (Program 5 - Standard Template Library)
 * Due Date: (November 14, 2016)
 */
#ifndef BIGINT_H
#define BIGINT_H

#include <vector>

using namespace std;

class BigInt
{
private:
	vector <int> digits;
	vector <int>::iterator it;
	vector <int>::reverse_iterator rit;
	bool positive;

public:
	BigInt();
	BigInt( int );
	BigInt( string );
	BigInt( BigInt & );

	void clearZeroes();

	BigInt operator+( BigInt );
	BigInt operator-( BigInt );

	bool operator<( BigInt &);

	friend ostream & operator<<( ostream &, BigInt );

};



#endif // !1

