#ifndef DECK_
#define DECK_

#include "Card.h"
#include <vector>
#include "Deck and Shuffler.cpp"
using std::vector;

class deck
{
public:
	Card getCard (int location);
	void setCard (Card c, int location);
	friend void shuffle_deck();
private:
	vector<Card> deck_of_cards;
};

#endif