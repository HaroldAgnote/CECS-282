#include "stdafx.h"
#include "Card.h"
#include <iostream>
using namespace std;

Card::Card()
{

}

Card::Card(int r, char s)
{
	rank = r;
	suit = s;
}

int Card::getValue()
{
	return rank;
}

int Card::getRank()
{
	return rank;
}

char Card::getSuit()
{
	return suit;
}

void Card::setCard(int r, char s)
{
	rank = r;
	suit = s;
}

void Card::display()
{
	cout << "I am a " << rank << " of " << suit << endl;
}