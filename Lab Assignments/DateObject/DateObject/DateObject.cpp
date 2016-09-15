// DateObject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myDate.h"
#include <iostream>

using namespace std;

int main()
{
	myDate date1(1, 1, -4712);

	cout << date1.JulianDate(1, 2, -4712);

	char a;
	cin >> a;

    return 0;
}

