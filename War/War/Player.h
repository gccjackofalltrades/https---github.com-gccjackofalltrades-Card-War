
#ifndef PLAYER_
#define PLAYER_

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


#endif