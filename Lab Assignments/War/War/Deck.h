#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck
{
public:
	Deck();
	
	void initializeDeck();

	Card deal();

	void shuffle();

	int cardsLeft();

	void displayCards();

private:
	Card cards[52];
	int cardsRemain;
	int counter;
};

#endif