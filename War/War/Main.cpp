#include <iostream>
#include <vector>
#include "Card.h"
#include "Player.h"
#include "GameManager.h"
#include "Deck.h"

using std::cout;
using std::cin;
using std::vector;
using std::endl;

int main()
{
	deck theDeck;
	player p1(26);
	player computer(26);
	gameManager overLord;
	overLord.deal(theDeck, p1, computer);
	Card playersNextCard = p1.playNextCard();
	Card computersNextCard = computer.playNextCard();
	while(!overLord.gameOver(p1, computer))
	{

		if(overLord.isWar(playersNextCard, computersNextCard))
		{
			overLord.war(p1, computer, playersNextCard, computersNextCard);
			if (overLord.gameOver(p1, computer))
			{
				break;
			}
		}
		else if (overLord.playerWins(playersNextCard, computersNextCard))
		{
			cout << "Player's ";
			overLord.printCard(playersNextCard);
			cout << "Beats the Computer's ";
			overLord.printCard(computersNextCard);
			p1.addToDiscard(playersNextCard);
			p1.addToDiscard(computersNextCard);
		}
		else if(overLord.playerWins(computersNextCard, playersNextCard))
		{
			cout << "Computer's ";
			overLord.printCard(playersNextCard);
			cout << "Beats the Player's ";
			overLord.printCard(computersNextCard);
			computer.addToDiscard(playersNextCard);
			computer.addToDiscard(computersNextCard);
		}

	}
	return 0;
}

