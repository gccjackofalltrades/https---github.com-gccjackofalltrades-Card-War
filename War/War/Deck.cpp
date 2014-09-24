
#include "Deck.h"
#include "Card.h"
#include <vector>
#include<ctime>
using std::vector;

Card deck::getCard(int location)
{
	return deck_of_cards[location];
}
void deck::setCard(Card c, int location)
{
	deck_of_cards[location] = c;
}

void deck::size_the_deck()
{
	deck_of_cards.resize(52);
}



void deck::create_deck()
{
	deck setter;
	setter.size_the_deck(); //set size of deck

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

	for(int i=0; (i)<decks.size();i++)
	{
		//swap the first and last elements
		if((i+1)==decks.size())
		{
			store=decks.size();
			temp=decks[store];
			decks[store]=decks[0];
			decks[0]=temp;
		}
		else
		{
			store=decks.size()-i;
			temp=decks[store];
			decks[store]=decks[i];
			decks[i]=temp;
		}
		for(int j=0;j<(decks.size()-random_number);j++)
		{
			store=decks.size()-j;
			temp=decks[store];
			decks[store]=decks[j];
			decks[j]=temp;
		}
	}


	
}

