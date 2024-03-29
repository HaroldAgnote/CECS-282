/*
 * Name: Harold
 * Class: CECS 282 - Sec. 07
 * Project Name: (Prog 1 - War)
 * Due Date: (09/12/2016)
 */
#include "stdafx.h"
#include "Deck.h"
#include <iostream>
using namespace std;

void displayMenu();
Deck war(Deck d);

int main()
{
	Deck play;
	int choice;
	bool done = false;

	cout << "Welcome to War!" << endl;

	do
	{
		displayMenu();
		cin >> choice;
		switch (choice)
		{
			case 1: play.initializeDeck();
					break;
			case 2: play.displayCards();
					break;
			case 3: play.shuffle();
					break;
			case 4: play = war(play);
					break;
			case 5: done = true;
					break;
		}

	}
	while (!done);

	cout << "Thank you for playing War!" << endl;

	return 0;
}

void displayMenu()
{
	cout << "What would you like to do" << endl;
	cout << "1. Get a new Deck" << endl;
	cout << "2. Show all cards remaining in the Deck" << endl;
	cout << "3. Shuffle the Deck" << endl;
	cout << "4. Play War!" << endl;
	cout << "5. Quit" << endl;
}

Deck war(Deck d)
{
	bool play;

	if (d.cardsLeft() > 0)
	{
		play = true;
	}
	else
	{
		cout << "There are no more cards left in the deck!" << endl;
		cout << "You need a new deck to play again..." << endl;
		play = false;
	}
	char yesNo;
	while (play)
	{
		Card player = d.deal();
		Card computer = d.deal();

		cout << "Player drew a \n";
		player.displayNicely();
		player.display();
		cout << "Computer drew a \n";
		computer.displayNicely();
		computer.display();

		if (player.getValue() > computer.getValue())
		{
			cout << "You win!" << endl;
		}
		else if (player.getValue() < computer.getValue())
		{
			cout << "You lose!" << endl;
		}
		else
		{
			cout << "It's a tie!" << endl;
		}

		if (d.cardsLeft() > 0)
		{
			cout << "Do you want to play again? (Y/N)" << endl;
			cin >> yesNo;
			if (yesNo == 'n')
			{
				play = false;
			}
		}
		else
		{
			cout << "No more cards left" << endl;
			play = false;
		}
	}

	return d;
}