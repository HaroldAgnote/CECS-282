/*
 * Name: Harold Agnote
 * Student ID: 012264497
 * Class: CECS 282 - Sec. 07
 * Project Name: (Program 4 - Operator Overloading)
 * Due Date: (October 24, 2016)
 */
#include "upDate.h"
#include <iostream>
#include <string>

using namespace std;

int upDate::count = 0;

upDate::upDate()
{
	dPtr = new int[3];
	count++;
	dPtr[0] = 11;	//Day
	dPtr[1] = 5;	//Month
	dPtr[2] = 1959;	//Year
}

upDate::upDate(int M, int D, int Y)
{
	dPtr = new int[3];
	count++;
	if (M > 12 || D <= 0 || D > 31)
	{
		dPtr[0] = 11;
		dPtr[1] = 5;
		dPtr[2] = 1959;
	}
	else
	{
		dPtr[0] = D;
		dPtr[1] = M;
		dPtr[2] = Y;
	}
}

upDate::upDate( const upDate & D )
{
	dPtr = new int[3];
	dPtr[0] = D.dPtr[0];
	dPtr[1] = D.dPtr[1];
	dPtr[2] = D.dPtr[2];
	count++;
}

upDate::~upDate()
{
	delete [] dPtr;
	count--;
}

void upDate::operator=( const upDate & D )
{
	this->dPtr[0] = D.dPtr[0];
	this->dPtr[1] = D.dPtr[1];
	this->dPtr[2] = D.dPtr[2];
}

upDate upDate::operator+( int x )
{
	upDate temp( *this );
	temp.incrDate( x );
	return temp;
}

upDate upDate::operator++()
{
	incrDate( 1 );
	return *this;
}

upDate upDate::operator++( int dummy )
{
	upDate temp( *this );
	incrDate( 1 );
	return temp;
}

upDate upDate::operator-( int x )
{
	upDate temp( *this );
	temp.decrDate( x );
	return temp;
}

int upDate::operator-( upDate D )
{
	return D.daysBetween(*this);
}

upDate upDate::operator--()
{
	decrDate( 1 );
	return *this;
}

upDate upDate::operator--( int dummy )
{
	upDate temp( *this );
	decrDate( 1 );
	return temp;
}

upDate operator+(int x, upDate D)
{
	upDate temp(D);
	temp.incrDate( x );
	return temp;
}

void upDate::display()
{
	string monthText = numToMonth();

	cout << monthText << dPtr[0] << ", " << dPtr[2];
}

void upDate::incrDate(int N)
{
	int julianDate = julian();
	julianDate += N;
	GregorianDate(julianDate);
}

void upDate::decrDate(int N)
{
	int julianDate = julian();
	julianDate -= N;
	GregorianDate(julianDate);
}

int upDate::daysBetween(upDate D)
{
	return D.JulianDate(D.dPtr) - JulianDate(dPtr);
}

int upDate::getMonth()
{
	return dPtr[1];
}

int upDate::getDay()
{
	return dPtr[0];
}

int upDate::getYear()
{
	return dPtr[2];
}

void upDate::setDate( int M, int D, int Y )
{
	dPtr[0] = D;
	dPtr[1] = M;
	dPtr[2] = Y;
}

int upDate::dayOfYear()
{
	upDate newYears(1, 1, dPtr[2]);

	return (this->julian() - newYears.julian()) + 1;
}

int upDate::julian()
{
	return JulianDate( dPtr );
}

string upDate::dayOfWeek()
{
	string dayText = "";

	int julianDate = JulianDate(dPtr);

	switch (julianDate % 7)
	{
	case 0: dayText = "Monday ";
		break;
	case 1: dayText = "Tuesday ";
		break;
	case 2: dayText = "Wednesday ";
		break;
	case 3: dayText = "Thursday ";
		break;
	case 4: dayText = "Friday ";
		break;
	case 5: dayText = "Saturday ";
		break;
	case 6: dayText = "Sunday ";
		break;
	default: dayText = "Bogusday ";
		break;
	}

	return dayText;
}

string upDate::numToMonth()
{
	string monthText;

	switch (dPtr[1])
	{
	case 1: monthText = "January ";
		break;
	case 2: monthText = "February ";
		break;
	case 3: monthText = "March ";
		break;
	case 4: monthText = "April ";
		break;
	case 5: monthText = "May ";
		break;
	case 6: monthText = "June ";
		break;
	case 7: monthText = "July ";
		break;
	case 8: monthText = "August ";
		break;
	case 9: monthText = "September ";
		break;
	case 10: monthText = "October ";
		break;
	case 11: monthText = "November ";
		break;
	case 12: monthText = "December ";
		break;
	default: monthText = "Bogusmonth ";
		break;
	}

	return monthText;
}

int upDate::JulianDate(int * dPtr)
{
	int i = dPtr[2];
	int j = dPtr[1];
	int k = dPtr[0];

	int julianDate;

	julianDate = k - 32075 + 1461 * (i + 4800 + (j - 14) / 12) / 4 + 367 * (j - 2 - (j - 14) / 12 * 12) / 12 - 3 * ((i + 4900 + (j - 14) / 12) / 100) / 4;

	return julianDate;
}

void upDate::GregorianDate(int jD)
{
	int i, j, k, l, n;
	
	l = jD + 68569;
	n = 4 * l / 146097;
	l = l - (146097 * n + 3) / 4;
	i = 4000 * (l + 1) / 1461001;
	l = l - ((1461 * i) / 4) + 31;
	j = 80 * l / 2447;
	k = l - (2447 * j) / 80;
	l = j / 11;
	j = (j + 2) - (12 * l);
	i = 100 * (n - 49) + i + l;

	dPtr[2] = i;
	dPtr[1] = j;
	dPtr[0] = k;
}

bool upDate::operator==( upDate D )
{
	return this->julian() == D.julian();
}

bool upDate::operator>( upDate D )
{
	return this->JulianDate( dPtr ) > D.JulianDate( D.dPtr );
}

bool upDate::operator<( upDate D )
{
	return this->JulianDate( dPtr ) < D.JulianDate( D.dPtr );
}

ostream & operator<<( ostream & out, upDate D )
{
	out << D.dPtr[1] << " / " << D.dPtr[0] << " / " << D.dPtr[2];
	
	return out;
	
}

int upDate::GetDateCount()
{
	return count;
}