/*
 * Name: Harold Agnote
 * Student ID: 012264497
 * Class: CECS 282 - Sec. 07
 * Project Name: (Program 2 - ADT(Date Object))
 * Due Date: (September 26, 2016)
 */
#ifndef MYDATE_H
#define MYDATE_H

#include <iostream>
#include <string>

using namespace std;

class myDate
{
private:
	int day;
	int month;
	int year;
	
	void GregorianDate(int JD);

	

public:
	myDate();
	
	myDate(int M, int D, int Y);
	
	void display();

	void incrDate(int N);

	void decrDate(int N);

	int daysBetween(myDate D);

	int getMonth();

	int getDay();

	int getYear();

	int dayOfYear();

	string dayOfWeek();

	string numToMonth();

	int JulianDate( int & year, int & month, int & day );

};

#endif