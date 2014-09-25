#ifndef GAMEMANAGER_
#define GAMEMANAGER_

#include "Card.h"
#include "Deck.h"
#include "Player.h"

class gameManager
{
public:
	bool playerWins (Card human, Card computer);
	// Returns true if the human player's card is greater than the computer's card. returns false otherwise
	void round(player human, player computer); 
	bool isWar (Card human, Card player);
	// Returns true if the two cards are equal.
	void war(player human, player computer, Card humanCard, Card computerCard);
	bool gameOver (player human, player computer);
	// Returns true if one player is completely out of cards.
    void  deal(deck d , player& human, player& computer);
	// distributes the cards between the players.
	void printCard(Card c); // cout the value and suit of a card
};


#endif
