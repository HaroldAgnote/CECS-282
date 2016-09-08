#ifndef CARD_H
#define CARD_H

class Card
{
public:
	Card();

	Card(int r, char s);

	int getValue();

	void assignRank();

	char getRank();

	char getSuit();

	void setCard(int r, char s);

	void display();

	void displayNicely();

private:
	int value;
	char rank;
	char suit;
};

#endif