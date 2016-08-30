#include "Card.h"

class Deck
{
public:
	Deck();

	Card deal();

	void shuffle();

	int cardsLeft();

	void displayCards();

private:
	Card cards[52];
	int cardsRemain;
	int index;
};