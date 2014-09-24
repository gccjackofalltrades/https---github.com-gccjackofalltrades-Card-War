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

void gameManager::war(player human, player computer, Card humanCard, Card computerCard)
{
	Card human_cards [4];
	Card computer_cards [4];
	human_cards[0] = humanCard;
	computer_cards[0] = computerCard;
	for (int i = 1; i < 4; i++)
	{
		if (computer.getCardTotal(); i++)
		{
			if(computer.getHandSize() == 0)
			{
				shuffleHand(
			}
		}
	}
}

bool gameManager::gameOver(player human, player computer)
{
	if(human.getCardTotal() == 0 || computer.getCardTotal() == 0)
	{
		return true;
	}
	return false;
}
