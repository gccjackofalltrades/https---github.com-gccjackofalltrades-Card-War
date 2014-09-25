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
	/*deck test;
	test.create_deck();*/
	deck theDeck;
	theDeck.create_deck();
	player p1(26);
	player computer(26);
	gameManager overLord;
	overLord.deal(theDeck, p1, computer);
	cout << "Player plays ";
	Card playersNextCard = p1.playNextCard();
	cout << endl << "Computer plays ";
	Card computersNextCard = computer.playNextCard();
	cout << endl;
	while(!overLord.gameOver(p1, computer))
	{
		//it runs through this area

		if(overLord.isWar(playersNextCard, computersNextCard))
		{
			overLord.war(p1, computer, playersNextCard, computersNextCard);

		}
		else
		{
			//it does only run through this
			overLord.round(p1, computer, playersNextCard, computersNextCard);
		}
		if (overLord.gameOver(p1, computer))
		{
			break;
		}
		cout << "Player plays ";
		playersNextCard = p1.playNextCard();
		cout << endl << "Computer plays ";
		computersNextCard = computer.playNextCard();
		cout << endl;
	}
	return 0;
}

