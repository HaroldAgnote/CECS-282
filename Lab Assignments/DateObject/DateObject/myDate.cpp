#include "stdafx.h"
#include "myDate.h"
#include <iostream>

using namespace std;

myDate::myDate()
{
	day = 11;
	month = 5;
	year = 1959;
}

myDate::myDate(int M, int D, int Y)
{
	day = D;
	month = M;
	year = Y;
}

void myDate::display()
{
	string * monthText = & numToMonth();

	cout << * monthText << " " << day << ", " << year;
}

void myDate::incrDate(int N)
{

}

void myDate::decrDate(int N)
{

}

int myDate::daysBetween(myDate D)
{
	return 0;
}

int myDate::getMonth()
{
	return month;
}

int myDate::getDay()
{
	return day;
}

int myDate::getYear()
{
	return year;
}

int myDate::dayOfYear()
{
	return 0;
}

string myDate::dayOfWeek()
{
	return "hi";
}

string myDate::numToMonth()
{
	string monthText;

	switch (month)
	{
	case 1: monthText = "January";
		break;
	case 2: monthText = "February";
		break;
	case 3: monthText = "March";
		break;
	case 4: monthText = "April";
		break;
	case 5: monthText = "May";
		break;
	case 6: monthText = "June";
		break;
	case 7: monthText = "July";
		break;
	case 8: monthText = "August";
		break;
	case 9: monthText = "September";
		break;
	case 10: monthText = "October";
		break;
	case 11: monthText = "November";
		break;
	case 12: monthText = "December";
		break;

	}

	return monthText;
}

int myDate::JulianDate(int year, int month, int day)
{
	int julianDate;

	int i = year;
	int j = month;
	int k = day;

	julianDate = k - 32075 + 1461 * (i + 4800 + (j - 14) / 12) / 4 + 367 * (j - 2 - (j - 14) / 12 * 12) / 12 - 3 * ((i + 4900 + (j - 14) / 12) / 100) / 4;

	return julianDate;
}