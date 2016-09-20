// DateObject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myDate.h"
#include <iostream>

using namespace std;

int main()
{
	myDate date1(1, 1, -4712);

	date1.display();

	char a;
	cin >> a;

    return 0;
}

