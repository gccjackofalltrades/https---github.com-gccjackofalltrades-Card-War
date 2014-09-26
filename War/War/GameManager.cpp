#include "GameManager.h"
#include "Card.h"
#include "Player.h"
#include "Deck.h"
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;
using std::cin;

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

void gameManager::war(player& human, player& computer, Card humanCard, Card computerCard)
{
	int shortNum = 5;
	vector <Card> human_cards;
	vector <Card> computer_cards;
	human_cards.push_back(humanCard);
	computer_cards.push_back(computerCard);
	cout<<"War!"<<endl;
	if (human.getCardTotal() < 4) // adjusts the number of cards in the war if the human does not have enough cards for
		// full war
	{
		shortNum = human.getCardTotal();
	}
	if (shortNum == 1) // if the human has only one card, he forfeits at this point
	{
		return;
	}
	cout<<"\n"<<endl;
	cout<<"Computer's Cards"<<endl;
	for (int i = 1; i < shortNum; i++)
	{
		if (gameOver(human, computer)) // breaks out of loop if computer is out of cards
		{
			shortNum = i;
			break;
		}
		if ((computer.getHandSize() == 0) && (!gameOver(human,computer))) // shuffles computer's discard if hand runs out
		{
			computer.shuffleHand();
		}
		computer_cards.push_back(computer.playNextCard()); // adds cards to computer's cards in play in the war
		cout<<endl;
	}
	if(human.getHandSize()==0 && human.getCardTotal() != 0)
	{
		//add to shuffle if players card is out
		cout<<"Now shuffling human hand"<<endl;
		human.shuffleHand();
	}
	if(computer.getHandSize()==0 && computer.getCardTotal() != 0)
	{
		//add to shuffle if players card is out
		cout<<"Now shuffling computer's hand"<<endl;
		computer.shuffleHand();		}
	if (shortNum == 1) // if the computer only has one card, it forfeits at this point
	{
		return;
	}
	cout<<endl;
	cout<<"Human's Cards"<<endl;
	for (int i = 1; i < shortNum; i++)
	{
		if(gameOver(human, computer)) // breaks out of the loop if the human is out of cards
		{
			break;
		}
		if ((human.getHandSize() == 0) && (!gameOver(human,computer))) // shuffles the human's discard if their hand runs out
		{
			human.shuffleHand();
		}
		human_cards.push_back(human.playNextCard()); // adds cards to the human's cards in play in the war
		cout<<endl;
	}
		if(human.getHandSize()==0 && human.getCardTotal() != 0)
		{
			//add to shuffle if players card is out
			cout<<"Now shuffling human hand"<<endl;
			human.shuffleHand();
		}
		if(computer.getHandSize()==0 && computer.getCardTotal() != 0)
		{
			//add to shuffle if players card is out
			cout<<"Now shuffling computer's hand"<<endl;
			computer.shuffleHand();
		}
	if (playerWins(human_cards[human_cards.size()-1], computer_cards[computer_cards.size()-1]))
	// copies computer's cards into human's discard if human wins war
	{
		cout<<endl;
		cout << "\t \t \t Human wins the War!" << endl
			<< "\t \t Human's\t \t ";
		cout << human_cards[human_cards.size()-1].name() << endl;
		cout << "\t \t beats Computer's \t ";
		cout << computer_cards[computer_cards.size()-1].name() << endl;
		cout << endl << "Human gains: ";
		for (int i = 0; i < computer_cards.size(); i++)
		{
			cout << computer_cards[i].name();
			cout << " ";
			human.addToDiscard(computer_cards [i]);
			human.addToDiscard(human_cards[i]);
			cout<<endl;

		}
	}
	else // copies human's cards into computer's discard if computer wins war
	{
		cout << "\t \t \t Computer wins the War!" << endl
			<< "\t \t computer's \t ";
		cout << computer_cards[computer_cards.size()-1].name() << endl;
		cout << " \t \t beats human's \t ";
		cout << human_cards[human_cards.size()-1].name() << endl;
		cout << endl << "Computer gains: ";
		for (int i = 0; i < human_cards.size(); i++)
		{
			cout << human_cards[i].name();
			cout << " ";
			computer.addToDiscard(computer_cards[i]);
			computer.addToDiscard(human_cards[i]);
			cout<<endl;
		}


	}
	cout<<human.getHandSize()<<" is the hand size of player"<<endl;
	cout<<human.getDiscardSize()<<" is the player discard size"<<endl;
	cout<<human.getCardTotal()<<" is player card total"<<endl;
	cout<<computer.getHandSize()<<" is the hand size of the computer"<<endl;
	cout<<computer.getDiscardSize()<<" is the computer discard size"<<endl;
	cout<<computer.getCardTotal()<<" is computer card total"<<endl;
	return;
}

bool gameManager::gameOver(player human, player computer)
{
	if(human.getCardTotal() == 0)
	{
		cout<<"Player loses =( Computer wins"<<endl;
		return true;
	}
	if (computer.getCardTotal() == 0)
	{
		cout<<"Player Wins! Computer loses!"<<endl;
		return true;
	}
	return false;
}

void gameManager::printCard(Card c) //there is a function string name that does this 
{
	cout << c.name() << endl; //this is that function
	//cout << c.getValue() << " of " << c.getSuit() << endl;
}

void gameManager::round(player& human, player& computer, Card humansCard, Card computersCard)
{
	char continueChar = 'a';
	//Card humansCard = human.playNextCard();
	//Card computersCard = computer.playNextCard();
	if (playerWins(humansCard, computersCard) && !isWar(humansCard,computersCard))
	{
		cout << "\tPlayer's ";
		cout << humansCard.name();
		cout << " Beats the Computer's ";
		cout << computersCard.name();
		cout << endl;
		//adds to discard pile of human
		human.addToDiscard(humansCard);
		human.addToDiscard(computersCard);

		cout<<human.getHandSize()<<" is the hand size of player"<<endl;
		cout<<human.getDiscardSize()<<" is the player discard size"<<endl;
		cout<<human.getCardTotal()<<" is player card total"<<endl;
		cout<<computer.getHandSize()<<" is the hand size of the computer"<<endl;
		cout<<computer.getDiscardSize()<<" is the computer discard size"<<endl;
		cout<<computer.getCardTotal()<<" is computer card total"<<endl;
	}

	else if(!playerWins(humansCard, computersCard))
	{
		cout << "\tComputer's ";
		cout << computersCard.name();
		cout << " Beats the Player's ";
		cout << humansCard.name();
		cout << endl;
		//adds both cards to humans discard pile
		computer.addToDiscard(humansCard);
		computer.addToDiscard(computersCard);

		cout<<endl;
		cout<<human.getHandSize()<<" is the hand size of player"<<endl;
		cout<<human.getDiscardSize()<<" is the player discard size"<<endl;
		cout<<human.getCardTotal()<<" is player card total"<<endl;
		cout<<computer.getHandSize()<<" is the hand size of the computer"<<endl;
		cout<<computer.getDiscardSize()<<" is the computer discard size"<<endl;
		cout<<computer.getCardTotal()<<" is computer card total"<<endl;
	}
		//add to shuffle if human card out
	if((human.getHandSize()==0) && (!gameOver(human,computer)))
		{
			//add to shuffle if players card is out
			cout<<"Now shuffling human hand"<<endl;
			human.shuffleHand();
		}
		//add to shuffle if computers card is out
		if((computer.getHandSize()==0) && (!gameOver(human, computer)))
		{
			cout<<"Commencing shuffling of computer hand"<<endl;
			computer.shuffleHand();
		}


	cout<<endl;
	cout << " \n Enter Q to quit, any other character to play next round" <<endl;
	cin >> continueChar;
	cout<<endl<<endl<<endl;
	continueChar = toupper(continueChar);
	if (continueChar == 'Q')
	{
		char c;
		human.setCardTotal(0);
		cout<<"Player forfeits, Computer Wins"<<endl;
		cout<<"Enter character to exit"<<endl;
		cin>>c;
		exit(0);
	}
}

void gameManager::deal(deck &d , player& human, player& computer)
{
	human.initial_hand_size();
	computer.initial_hand_size();
	human.initialize_discard_vector();
	computer.initialize_discard_vector();
	//need a call to create the deck
	for (int i = 0; i < 26; i++)
	{
		human.setHandCard(i,d.getCard(i)); 
	}
	for (int i = 26; i<52; i++)
	{
		computer.setHandCard(i-26,d.getCard(i));
	}
	human.setHandSize(26);
	human.setCardTotal(26);
	computer.setHandSize(26);
	computer.setCardTotal(26);

}
