#ifndef DECK_
#define DECK_

class deck
{
public:
	Card getCard (int location);
	void setCard (Card c, int location);
	friend void shuffleDeck();
private:
	vector <Card> deck;
};

#endif