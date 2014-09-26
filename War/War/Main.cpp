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
	theDeck.create_deck();
	player p1(26);
	player computer(26);
	gameManager overLord;
	overLord.deal(theDeck, p1, computer);

	while(!overLord.gameOver(p1, computer))
	{
		if (p1.getHandSize() == 0)
		{
			p1.shuffleHand();
		}
		if (computer.getHandSize() == 0)
		{
			computer.shuffleHand();
		}
		cout << "Player plays ";
		Card playersNextCard = p1.playNextCard();

		cout <<" \t \t \t"<< "Computer plays ";
		Card computersNextCard = computer.playNextCard();
		cout << endl<<endl;
		

		if(overLord.isWar(playersNextCard, computersNextCard))
		{
			overLord.war(p1, computer, playersNextCard, computersNextCard);

		}
		else
		{
			overLord.round(p1, computer, playersNextCard, computersNextCard);
		}
		if (overLord.gameOver(p1, computer))
		{
			break;
		}


	}
	return 0;
}

