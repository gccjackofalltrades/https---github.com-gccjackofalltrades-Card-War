
#ifndef PLAYER_
#define PLAYER_

#include "Card.h"
#include <vector>
using std::vector;

class player
{
public:
	player (int handTotal);
	Card getHandCard (int location);
	void setHandCard (int location, Card c);
	Card getDiscardCard(int location);
	void setDiscardCard(int location, Card c);
	int getHandSize();
	void setHandSize(int size);
	int getDiscardSize();
	void setDiscardSize();
	int getCardTotal();
	void setCardTotal(int total);
	void addToHand(Card c);
	void addToDiscard(Card c);
	Card playNextCard (); // plays a card by returning the end value of the hand vector and removing it
	// from the vector. Resizes handSize and cardTotal
	friend void shuffleHand (player shufflePlayer);
private:
	int handSize;
	int discardSize;
	int cardTotal;
	vector <Card> hand;
	vector <Card> discard;
	
};

#endif
