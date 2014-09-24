#include "Player.h"
#include "Card.h"
#include <vector>
using std::vector;

Card player::getHandCard (int location)
{
	return hand[location];
}

void player::setHandCard (int location, Card c)
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

Card player::playNextCard()
{
	Card holder = getHandCard(hand.size - 1);
	hand.resize(hand.size()-1);
	handSize--;
	cardTotal--;
	return holder;
}

void player::addToDiscard (Card c)
{
	discard.push_back(c);
	discardSize++;
	cardTotal++;
}

void player::addToHand (Card c)
{
	hand.push_back(c);
	handSize++;
	cardTotal++;
}
