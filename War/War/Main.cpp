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
	void sethandCard (int location, Card c);
	Card getDiscardCard(int location);
	void setDiscardCard(int location);
	int getHandSize();
	void setHandSize(int size);
	int getDiscardSize();
	void setDiscardSize();
	int getCardTotal();
	void setCardTotal(int total);
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
