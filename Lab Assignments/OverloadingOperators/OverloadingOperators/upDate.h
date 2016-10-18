/*
 * Name: Harold Agnote
 * Student ID: 012264497
 * Class: CECS 282 - Sec. 07
 * Project Name: (Program 4 - Operator Overloading)
 * Due Date: (October 24, 2016)
 */
#ifndef UPDATE_H
#define UPDATE_H

#include <iostream>
#include <string>

using namespace std;

class upDate
{
private:
	int * dPtr;

	//static int count;
	
	void GregorianDate(int JD);

	int JulianDate(int * dPtr);

public:
	upDate();
	
	upDate(int M, int D, int Y);
	
	//~upDate();

	upDate operator+( int x );

	upDate operator++();

	upDate operator++( int dummy );

	upDate operator-( int x );

	upDate operator--();

	friend upDate operator+( int, upDate D );

	void display();

	void incrDate(int N);

	void decrDate(int N);

	int daysBetween(upDate D);

	int getMonth();

	int getDay();

	int getYear();

	int dayOfYear();

	string dayOfWeek();

	string numToMonth();

	boolean operator==( upDate D1, upDate D2 );

	friend ostream operator<<( ostream out, upDate D );

};

#endif