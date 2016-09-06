#include "stdafx.h"
#include "Card.h"
#include <iostream>
using namespace std;

Card::Card()
{
	value = 0;
	suit = 'z';
	rank = 'z';
}

Card::Card(int v, char s)
{
	value = v;
	suit = s;
	assignRank();
}

int Card::getValue()
{
	return value;
}

char Card::getRank()
{
	return rank;
}

char Card::getSuit()
{
	return suit;
}

void Card::setCard(int v, char s)
{
	value = v;
	suit = s;
	assignRank();
}

void Card::assignRank()
{
	switch (value)
	{
	case 1: rank = 'A';
		break;
	case 2: rank = '2';
		break;
	case 3: rank = '3';
		break;
	case 4: rank = '4';
		break;
	case 5: rank = '5';
		break;
	case 6: rank = '6';
		break;
	case 7: rank = '7';
		break;
	case 8: rank = '8';
		break;
	case 9: rank = '9';
		break;
	case 10: rank = 'T';
		break;
	case 11: rank = 'J';
		break;
	case 12: rank = 'Q';
		break;
	case 13: rank = 'K';
		break;
	}
}

void Card::display()
{
	cout << rank << " of " << suit << endl;
}

