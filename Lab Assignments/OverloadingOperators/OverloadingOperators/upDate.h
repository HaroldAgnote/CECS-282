/*
 * Name: Harold Agnote
 * Student ID: 012264497
 * Class: CECS 282 - Sec. 07
 * Project Name: (Program 2 - ADT(Date Object))
 * Due Date: (September 26, 2016)
 */
#ifndef UPDATE_H
#define UPDATE_H

#include <iostream>
#include <string>

using namespace std;

class upDate
{
private:
	int day;
	int month;
	int year;
	
	void GregorianDate(int JD);

	int JulianDate(int & year, int & month, int & day);

public:
	upDate();
	
	upDate(int M, int D, int Y);
	
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

};

#endif