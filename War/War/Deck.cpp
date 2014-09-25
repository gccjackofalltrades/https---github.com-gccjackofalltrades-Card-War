
#include "Deck.h"
#include "Card.h"
#include <vector>
#include<ctime>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

Card deck::getCard(int location)
{
	return deck_of_cards[location];
}
void deck::setCard(Card c, int location)
{
	deck_of_cards[location] = c;
}

void deck::size_the_deck()//this doesn't keep the value of 52 to the deck size
{
	cout<<"resize ran"<<endl;
	deck_of_cards.resize(52); //not doing what I think it is doing
	cout<<"ideally resize finished running and resized the decjk"<<endl;
	cout<<deck_of_cards.size()<<" is the size of the deck"<<endl;
}



void deck::create_deck()
{
	deck_of_cards.resize(52); //setting the size of the deck
	deck setter;
	Value value;
	int k=0;

	for(Suit suit = clubs; suit <= spades; suit = (Suit)(static_cast<int>(suit) + 1))
	{
		for(int j=1; j<=13;j++)
		{
		  value=static_cast<Value>(j);
		  deck_of_cards[k]=Card(value,suit);
		  k++; //increment k, will go up to 52
		}
	}
	setter.shuffle_deck(deck_of_cards); //calls to shuffle the deck
}

void deck::shuffle_deck(vector<Card>& decks)
{
	int store; //temporary storage for indices

	Card temp; //storage for object

	srand(time(0));
	int random_number=rand()%decks.size()+1;//sets up a random number based on the decks size
	for(int i=0;i<decks.size();i++)
	{
		//swap the first and last elements
		if((i+1)==decks.size())
		{
			store=decks.size()-1;
			temp=decks[store];
			decks[store]=decks[0];
			decks[0]=temp;
		}
		else
		{
			store=(decks.size()-(i+1)); //last element, first time through it would be number 51
			temp=decks[store];
			decks[store]=decks[i+1];
			decks[i+1]=temp;
		}
		for(int j=0;j<(decks.size()-random_number);j++)
		{
			store=decks.size()-(j+1);
			temp=decks[store];
			decks[store]=decks[(j+1)];
			decks[(j+1)]=temp;
		}
	}


	cout<<"laughing cow cheese"<<endl;
}

