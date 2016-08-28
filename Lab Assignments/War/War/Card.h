class Card
{
public:
	Card();

	Card(int r, char s);

	int getRank();

	char getSuit();

	void setCard(int r, char s);

	void display();

private:
	int rank;
	char suit;
};