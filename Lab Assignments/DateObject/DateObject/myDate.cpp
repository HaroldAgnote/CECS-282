#include "stdafx.h"
#include "myDate.h"
#include <iostream>
#include <string>

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
	string monthText = numToMonth();

	cout << monthText << day << ", " << year;
}

void myDate::incrDate(int N)
{
	int julianDate = JulianDate(year, month, day);
	julianDate += N;
	GregorianDate(julianDate);
}

void myDate::decrDate(int N)
{
	int julianDate = JulianDate(year, month, day);
	julianDate -= N;
	GregorianDate(julianDate);
}

int myDate::daysBetween(myDate D)
{
	return D.JulianDate(D.getYear(),D.getMonth(),D.getDay()) - JulianDate(year, month, day);
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
	return (JulianDate(year, month, day) - JulianDate(year, 1, 1)) + 1;
}

string myDate::dayOfWeek()
{
	string dayText = "";

	int julianDate = JulianDate(year, month, day);

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
	default: dayText = "BogusDay ";
		break;
	}

	return dayText;
}

string myDate::numToMonth()
{
	string monthText;

	switch (month)
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
	default: monthText = "BogusMonth ";
		break;
	}

	return monthText;
}

int myDate::JulianDate(int year, int month, int day)
{
	int i = year;
	int j = month;
	int k = day;

	int julianDate;

	julianDate = k - 32075 + 1461 * (i + 4800 + (j - 14) / 12) / 4 + 367 * (j - 2 - (j - 14) / 12 * 12) / 12 - 3 * ((i + 4900 + (j - 14) / 12) / 100) / 4;

	return julianDate;
}

void myDate::GregorianDate(int jD)
{
	int i, j, k, l, n;

	l = jD + 68569;
	n = 4 * l / 146097;
	l = l - (146097 * n + 3) / 4;
	i = 4000 * (l + 1) / 1461001;
	l = l - 1461 * i / 4 + 31;
	j = 80 * l / 2447;
	k = l - 2447 * j / 80;
	l = j / 11;
	j = j + 2 - 12 * l;
	i = 100 * (n - 49) + i + l;

	year = i;
	month = j;
	day = k;
}