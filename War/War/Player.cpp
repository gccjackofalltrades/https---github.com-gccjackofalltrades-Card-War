#include "Player.h"
#include "Card.h"
#include <vector>

void player::sethandCard (int location, Card c)
{
	hand[location] = c;
}
void player::setDiscardCard(int location, Card d)
{
	discard[location] = d;
}
void player::setHandSize(int size)
{
	handSize = size;
}
void player::setDiscardSize()
{
	discardSize = discard.size();
}
void player::setCardTotal(int total)
{
	cardTotal = total;
}
