
#ifndef DECK_
#define DECK_

#include "Card.h"
#include <vector>
using std::vector;

using std::vector;
class deck
{
public:
	Card getCard (int location);
	void setCard (Card c, int location);
    void create_deck(); //creates deck using value_setter and Suit_setter, store into a vector deck_of_cards
	void shuffle_deck(vector<Card>& decks);//shuffles the deck through swapping index values
	void size_the_deck();//set the deck size to 52
private:
	vector<Card> deck_of_cards;
};




#endif
