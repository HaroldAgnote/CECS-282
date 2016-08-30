class Card
{
public:
	Card();

	Card(char r, char s);

	int getValue();

	char getRank();

	char getSuit();

	void setCard(int r, char s);

	void display();

private:
	int rank;
	char suit;
};