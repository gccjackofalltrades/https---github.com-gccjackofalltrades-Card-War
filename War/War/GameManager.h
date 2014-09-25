#ifndef GAMEMANAGER_
#define GAMEMANAGER_

#include "Card.h"
#include "Deck.h"
#include "Player.h"

class gameManager
{
public:
	// Returns true if the human player's card is greater than the computer's card. returns false otherwise
	bool playerWins (Card human, Card computer);
	void round(player human, player computer, Card humansCard, Card computersCard); 
	// Returns true if the two cards are equal.
	bool isWar (Card human, Card player);
	void war(player human, player computer, Card humanCard, Card computerCard);
	// Returns true if one player is completely out of cards.
	bool gameOver (player human, player computer);
	// distributes the cards between the players.
    void  deal(deck& d , player& human, player& computer);
	void printCard(Card c);
};


#endif
