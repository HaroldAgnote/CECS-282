#include "stdafx.h"
#include "UserInput.h"
#include <iostream>

using namespace std;

int UserInput::getInt()
{
	int input;

	cin >> input;

	return input;
}

int UserInput::getInt(int low, int high)
{
	return 0;
}