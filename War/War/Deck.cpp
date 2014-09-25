
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

	Card temp; //storage for object

	srand(time(0));
	int random_1=rand()%decks.size();//sets up a random number based on the decks size
	int random_2=rand()%decks.size();
	for(int i=0;i<200;i++)
	{
 
			temp=decks[random_1]; 
			decks[random_1]=decks[random_2]; 
			decks[random_2]=temp;

			//create new random numbers
			random_1=rand()%decks.size();
	        random_2=rand()%decks.size();
	}



}

