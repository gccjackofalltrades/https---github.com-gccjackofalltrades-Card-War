#include "GameManager.h"
#include "Card.h"
#include "Player.h"
#include "Deck.h"
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

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
	int shortNum = 5;
	vector <Card> human_cards;
	vector <Card> computer_cards;
	human_cards.push_back(humanCard);
	computer_cards.push_back(computerCard);
	if (human.getCardTotal() < 4) // adjusts the number of cards in the war if the human does not have enough cards for
		// full war
	{
		shortNum = human.getCardTotal();
	}
	if (shortNum == 1) // if the human has only one card, he forfeits at this point
	{
		return;
	}
	for (int i = 1; i < shortNum; i++)
	{
		if (gameOver(human, computer)) // breaks out of loop if computer is out of cards
		{
			shortNum = i;
			break;
		}
		if (computer.getHandSize() == 0) // shuffles computer's discard if hand runs out
		{
			computer.shuffleHand();
		}
		computer_cards.push_back(computer.playNextCard()); // adds cards to computer's cards in play in the war
	}
	if (shortNum == 1) // if the computer only has one card, it forfeits at this point
	{
		return;
	}
	for (int i = 1; i < shortNum; i++)
	{
		if(gameOver(human, computer)) // breaks out of the loop if the human is out of cards
		{
			break;
		}
		if (human.getHandSize() == 0) // shuffles the human's discard if their hand runs out
		{
			human.shuffleHand();
		}
		human_cards.push_back(human.playNextCard()); // adds cards to the human's cards in play in the war
	}
	
	if (playerWins(human_cards[human_cards.size()-1], computer_cards[computer_cards.size()-1]))
	// copies computer's cards into human's discard if human wins war
	{
		cout << "Human wins the War!" << endl
			<< "Human's ";
		printCard(human_cards[human_cards.size()-1]);
		cout << " beats computer's ";
		printCard(computer_cards[computer_cards.size()-1]);
		cout << endl << "Human gains: ";
		for (int i = 0; i < computer_cards.size(); i++)
		{
			printCard(computer_cards[i]);
			cout << " ";
			human.addToDiscard(computer_cards [i]);
			human.addToDiscard(human_cards[i]);
		}
	}
	else // copies human's cards into computer's discard if computer wins war
	{
		cout << "Computer wins the War!" << endl
			<< "computer's ";
		printCard(computer_cards[computer_cards.size()-1]);
		cout << " beats human's ";
		printCard(human_cards[human_cards.size()-1]);
		cout << endl << "Computer gains: ";
		for (int i = 0; i < human_cards.size(); i++)
		{
			printCard(human_cards[i]);
			cout << " ";
			computer.addToDiscard(computer_cards[i]);
			computer.addToDiscard(human_cards[i]);
		}
	}
	return;
}

bool gameManager::gameOver(player human, player computer)
{
	if(human.getCardTotal() == 0 || computer.getCardTotal() == 0)
	{
		return true;
	}
	return false;
}

void gameManager::printCard(Card c)
{
	cout << c.getValue() << " of " << c.getSuit() << endl;
}


void gameManager::round(player human, player computer)
{
	Card humansCard = human.playNextCard();
	Card computersCard = computer.playNextCard();
		if (playerWins(humansCard, computersCard))
		{
			cout << "Player's ";
			printCard(humansCard);
			cout << "Beats the Computer's ";
			printCard(computersCard);
			human.addToDiscard(humansCard);
			human.addToDiscard(computersCard);
		}
		else if(playerWins(computersCard, humansCard))
		{
			cout << "Computer's ";
			printCard(computersCard);
			cout << "Beats the Player's ";
			printCard(humansCard);
			computer.addToDiscard(humansCard);
			computer.addToDiscard(computersCard);
		}
}

void gameManager::deal(deck d , player& human, player& computer)
{
	human.initial_hand_size();
	computer.initial_hand_size();
	//need a call to create the deck
	for (int i = 0; i < 26; i++)
	{
		human.setHandCard(i,d.getCard(i)); 
		
	}
	for (int i = 26; i<52; i++)
	{
		computer.setHandCard(i,d.getCard(i));
	}
}
