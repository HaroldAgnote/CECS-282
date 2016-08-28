#include "stdafx.h"
#include "Deck.h"

Deck::Deck()
{
	char suits[4] = { 'd','h','s','c' };
	int r = 1;
	int s = 0;
	for (int i = 0; i < 52; i++)
	{
		if (r <= 13)
		{
			cards[i] = Card(r, suits[s]);
			r++;
		}
		else
		{
			r = 1;
			s++;
			cards[i] = Card(r, suits[s]);
			r++;
		}
	}
}

Card Deck::deal()
{
	Card give = cards[0];
	return give;
}

void Deck::shuffle()
{

}

int Deck::cardsLeft()
{
	return 0;
}

void Deck::displayCards()
{
	for (int i = 0; i < 52; i++)
	{
		cards[i].display();
	}
}