// War.cpp : Defines the entry point for the console application.
//

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
			case 1:
			{
				Deck replace;
				play = replace;
				break;
			}
			case 2:
			{
				play.displayCards();
				break;
			}
			case 3:
			{
				play.shuffle();
				break;
			}
			case 4:
			{
				play = war(play);
				break;
			}
			case 5:
			{
				done = true;
				break;
			}
		}

	}
	while (!done);

	cout << "Thank you for playing War!" << endl;
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
	bool play = true;
	char yesNo;
	do
	{
		Card player = d.deal();
		Card computer = d.deal();
		int playerValue = player.getValue();
		int computerValue = computer.getValue();
		int cardsLeft = d.cardsLeft();

		cout << "Player drew a";
		player.display();
		cout << "Computer drew a";
		computer.display();

		if (playerValue > computerValue)
		{
			cout << "You win!" << endl;
		}
		else if (playerValue < computerValue)
		{
			cout << "You lose!" << endl;
		}
		else
		{
			cout << "It's a tie!" << endl;
		}

		if (cardsLeft > 0)
		{
			cout << "Do you want to play again?" << endl;
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
	while (play);

	return d;
}

