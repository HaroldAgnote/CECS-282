// War.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	Deck test;

	cout << test.cardsLeft() << endl;

    return 0;
}


class Deck
{
public:
	Deck()
	{
		
	}

	Card deal()
	{
		return cards[0];
	}
	void shuffle()
	{

	}
	int cardsLeft()
	{
		int c = 0;
		int sum = 0;
		while (cards[c] = NULL)
		{
			sum++;
			c++;
		};
		return sum;
	}

	void displayDeck()
	{

	}

private:
	Card cards[];
};

class Card
{
public:
	Card(int r, char s)
	{
		rank = r;
		suit = s;
	}
	int getRank()
	{
		return rank;
	}
	char getSuit()
	{
		return suit;
	}
	void setCard(int r, char s)
	{
		rank = r;
		suit = s;
	}
	void display()
	{
		cout << "Not ready yet, teehee" << endl;
	}
private:
	int rank;
	char suit;
};

