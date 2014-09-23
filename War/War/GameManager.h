#ifndef GAMEMANAGER_
#define GAMEMANAGER_

#include "Card.h"
#include "Deck.h"
#include "Player.h"

class gameManager
{
public:
	bool playerWins (Card human, Card computer);
	bool isWar (Card human, Card player);
	void war();
	bool gameOver (int humanNum, int computerNum);
	void deal (deck d, player human, player computer);
};


#endif