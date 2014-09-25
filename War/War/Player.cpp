#include "Player.h"
#include "Card.h"
#include <vector>
#include <ctime>
using std::vector;

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

	hand.resize(discardSize);
	for (int i = 0; i < hand.size(); i++)
	{
		hand[i] = discard[i];
	}

	srand(time(0));
	int random_number=rand()%hand.size()+1;//sets up a random number based on the decks size

	for(int i=0; i<hand.size();i++)
	{

		//swap the first and last elements
		if((i+1)==hand.size())
		{
			store=hand.size();
			temp=hand[store];
			hand[store]=hand[0];
			hand[0]=temp;
		}
		else
		{
			store=hand.size()-i;
			temp=hand[store];
			hand[store]=hand[i];
			hand[i]=temp;
		}
		for(int j=0;j<(hand.size()-random_number);j++)
		{
			store=hand.size()-j;
			temp=hand[store];
			hand[store]=hand[j];
			hand[j]=temp;
		}
	}

}

void player::initial_hand_size()
{
	hand.resize(26);
}