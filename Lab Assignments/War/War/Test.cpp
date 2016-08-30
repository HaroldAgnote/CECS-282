// War.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Deck.h"
#include <iostream>
using namespace std;

int main()
{
	Deck test;
	char a;
	test.displayCards();
	do
	{
		cout << "Shuffle or Deal?" << endl;
		cin >> a;
		if (a == 's')
		{
			test.shuffle();
			test.displayCards();
		}
		else if (a == 'd')
		{
			Card deal = test.deal();
			deal.display();
		}
	} while (true);

	return 0;
}
s