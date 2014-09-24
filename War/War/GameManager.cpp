#include "GameManager.h"
#include "Card.h"
#include "Player.h"
#include "Deck.h"

bool gameManager::playerWins(Card player, Card computer)
{
	if (player.getValue() > computer.getValue())
	{
		return true;
	}
	return false;
}

bool gameManager::isWar(Card player, Card computer)
{
	return player.getValue()==computer.getValue();
}

void gameManager::war(player human, player computer)
{

}

bool gameManager::gameOver(player human, player computer)
{

}