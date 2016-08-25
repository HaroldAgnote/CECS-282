// SumApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
    int a,b,c;
	cout << "Enter Two Numbers" << endl;
	cin >> a >> b;
	c = a + b;
	cout << "The sum of " << a << " and " << b << " is " << c << "." << endl;
	cin >> a;
}

