#include "Player.h"
#include "Card.h"
#include <vector>

Card player::gethandCard (int location)
{
	return hand[location];
}

void player::sethandCard (int location, Card c)
{
	hand[location] = c;
}

Card player::getDiscardCard(int location)
{
	return discard[location];
}

void player::setDiscardCard(int location, Card d)
{
	discard[location] = d;
}

int player::getHandSize()
{
	return handSize;
}

void player::setHandSize(int size)
{
	handSize = size;
}

int player::getDiscardSize()
{
	return discardSize;
}

void player::setDiscardSize()
{
	discardSize = discard.size();
}

int player::getCardTotal()
{
	return cardTotal;
}

void player::setCardTotal(int total)
{
	cardTotal = total;
}
