
#ifndef DECK_
#define DECK_

#include "Card.h"
#include <vector>
<<<<<<< HEAD
#include "Deck and Shuffler.cpp"
using std::vector;

=======
using std::vector;
>>>>>>> 0ba59b10817471daa91a60775de09c99a5aedd81
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
