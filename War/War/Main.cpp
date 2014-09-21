#include <iostream>
#include <vector>
#include "Card.h"

using std::cout;
using std::cin;
using std::vector;
using std::endl;

class player
{
public:
	player (int handTotal);
	Card gethandCard (int location);
	void sethandCard (int location, Card c, player p)
	{
		p.hand[location] = c;
	}
	Card getDiscardCard(int location);
	void setDiscardCard(int location, Card d, player p)
	{
		p.discard[location] = d;
	}
	int getHandSize();
	void setHandSize(player p)
	{
		p.handSize = p.hand.size();
	}
	int getDiscardSize();
	void setDiscardSize(player p)
	{
		p.discardSize = p.discard.size();
	}
	int getCardTotal();
	void setCardTotal(player p)
	{
		p.cardTotal = p.handSize + p.discardSize;
	}
	friend void shuffleHand ();
private:
	int handSize;
	int discardSize;
	int cardTotal;
	vector <Card> hand;
	vector <Card> discard;
};

class deck
{
public:
	Card getCard (int location);
	void setCard (Card c, int location);
	friend void shuffleDeck();
private:
	vector <Card> deck;
};

class gameManager
{
public:
	bool playerWins (Card human, Card computer);
	bool isWar (Card human, Card player);
	void war();
	bool gameOver (int humanNum, int computerNum);
	void deal (deck d, player human, player computer);
};
