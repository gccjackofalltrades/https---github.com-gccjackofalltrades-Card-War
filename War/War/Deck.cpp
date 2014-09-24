
#include "Deck.h"
#include "Card.h"
#include <vector>

Card deck::getCard(int location)
{
	return deck[location];
}
void deck::setCard(Card c, int location)
{
	deck[location] = c;
}


