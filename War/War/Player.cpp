#include "Player.h"
#include "Card.h"
#include <vector>
#include <ctime>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

//constructor
player::player(int handTotal)
{
	handSize=handTotal;
}

Card player::getHandCard (int location)
{
	return hand[location];
}

void player::setHandCard (int location, Card c)
{
	hand[location]=c;
}

Card player::getDiscardCard(int location)
{
	return discard[location];
}

void player::setDiscardCard(int location, Card d)
{
	discard[location]=d;
}

int player::getHandSize()
{
	return handSize;
}

void player::setHandSize(int size)
{
	handSize = size;
}

int player::getDiscardSize()
{
	return discardSize;
}

void player::setDiscardSize()
{
	discardSize = discard.size();
}

int player::getCardTotal()
{
	return cardTotal;
}

void player::setCardTotal(int total)
{
	cardTotal = total;
}

Card player::playNextCard()
{
	Card holder = getHandCard(hand.size() - 1);
	hand.resize(hand.size()-1);
	handSize--;
	cardTotal--;
	cout << holder.name() << " ";
	return holder;
}

void player::addToDiscard (Card c)
{
	discard.push_back(c);
	discardSize++;
	cardTotal++;
}

void player::addToHand (Card c)
{
	hand.push_back(c);
	handSize++;
	cardTotal++;
}

void player::shuffleHand ()
{
	int store; //temporary storage for indices

	Card temp; //storage for object
	cout<<"banana"<<endl;
	hand.resize(discardSize);
	for (int i = 0; i < hand.size(); i++)
	{
		cout<<"apple"<<endl;
		hand[i] = discard[i];
	}

	srand(time(0));
	int random_1=rand()%hand.size();//sets up a random number based on the decks size
	int random_2=rand()%hand.size();
	for(int i=0;i<200;i++)

	int random_number=rand()%hand.size()+1;//sets up a random number based on the decks size
	for(int i=0;i<hand.size();i++)

	{
 
			temp=hand[random_1]; 
			hand[random_1]=hand[random_2]; 
			hand[random_2]=temp;

			//create new random numbers
			random_1=rand()%hand.size();
	        random_2=rand()%hand.size();
	}

}

void player::initial_hand_size()
{
	hand.resize(26);
}
