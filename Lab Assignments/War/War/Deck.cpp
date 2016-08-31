#include "stdafx.h"
#include "Deck.h"
#include <random>

Deck::Deck()
{
	index = 0;
	cardsRemain = 52;
	char suits[4] = { 'D','H','S','C' };
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
	Card give = cards[index];
	index++;
	cardsRemain--;
	return give;
}

void Deck::shuffle()
{
	for (int i = 0; i < 52; i++)
	{
		int index = i;
		int randomIndex = rand() % 52;

		Card swap = cards[i];
		cards[i] = cards[randomIndex];
		cards[randomIndex] = swap;
	}
}

int Deck::cardsLeft()
{
	return cardsRemain;
}

void Deck::displayCards()
{
	for (int i = index; i < 52; i++)
	{
		cards[i].display();
	}
}