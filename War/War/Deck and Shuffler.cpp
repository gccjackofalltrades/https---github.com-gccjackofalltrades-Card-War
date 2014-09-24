// CARDS.cpp : Defines the entry point for the console application.
//Deck and Shuffler
//creates and shuffles the deck, and nothing more
#ifndef CARD_H
#define CARD_H

#include <ctime> 
#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "Card.cpp"
using std::string;
using std::vector;
using std::cout;
using std::endl;


class deck
{
public:
	Card getCard (int location);
	void setCard (Card c, int location);
	//gives the deck a size, called in create_deck
	void size_the_deck();
	//calling it creates the deck
    void create_deck(); //creates deck using value_setter and Suit_setter, store into a vector deck_of_cards
    void shuffle_deck();//shuffles the deck through swapping index values
	
private:
	vector <Card> deck_of_cards;
};

Value value_setter(int j);//accepts index j, goes from 0 to 12, returns appropriate card value
Suit suit_setter(int i); //accepts index i, goes from 0 to 3, returns appropriate suit value



void deck::size_the_deck()
{
	deck_of_cards.resize(52);
}

void deck::create_deck()
{
	deck::size_the_deck(); //calls to size_the_deck
	Card cards;
	Suit suit;
	Value value;
	int k=0;
	for(int i=0; i<4;i++)
	{
		suit=suit_setter(i);
		for(int j=0; j<13;j++)
		{
		  value=value_setter(j);
		  deck_of_cards[k]=Card(value,suit);
		  k++; //increment k, will go up to 52
		}
	}
}

void deck::shuffle_deck()
{
	Card temp;//stores the card object
	int index=0;//think of index as k, the index of the deck_of_cards_vector that holds an object
	int index_storer [51]={53}; //all elements set to 53
	bool if_switch=true; 
	srand(time(0));

	//fill up the random index
	for(int i=0;i++;i<52)
	{
		index=rand()%52+1;//generate random index

		//check to make sure the number hasn't come before
		for(int j=0;j<52;j++)
		{
			if(index_storer[j]==index) //run throuhg all 52 value in index sorter, if one equals if return false
			{
				if_switch=false;
			} 
			else if(j==51)//ran through all 52 cards and haven't found a match
			{
				if_switch=true;
			}
		}
		if(if_switch)
		{
			index_storer[i]=index;//store the value
			i++; //allow the loop to move on
		}
		else
			i--; //don't allow the loop to move on
	}

	//swap values
	for(int i=51;i<=0;i--)
	{
		//swaps value with random value
		temp=deck_of_cards[i];
		deck_of_cards[i]=deck_of_cards[index];
		deck_of_cards[index]=temp;

	}
}

Value value_setter(int j)
{
	Value value;
	if(j==0)
	{
	 value=ace;
	 return value;
	}
	if(j==1)
	{
	 value=deuce;
	 return value;
	}
	if(j==2)
	{
	 value=trey;
	 return value;
	}
	if(j==3)
	{
	 value=four;
	 return value;
	}
	if(j==4)
	{
	 value=five;
	 return value;
	}
	if(j==5)
	{
	 value=six;
	 return value;
	}
	if(j==6)
	{
	 value=seven;
	 return value;
	}
	if(j==7)
	{
	 value=eight;
	 return value;
	}
	if(j==8)
	{
	 value=nine;
	 return value;
	}
	if(j==9)
	{
	 value=ten;
	 return value;
	}
	if(j==10)
	{
	 value=jack;
	 return value;
	}
	if(j==11)
	{
	 value=queen;
	 return value;
	}
	if(j==12)
	{
	 value=king;
	 return value;
	}
}

Suit suit_setter(int i)
{
	Suit suit;
	if(i==0)
	{
	 suit=clubs;
	 return suit;
	}
	if(i==1)
	{
	 suit=diamonds;
	 return suit;
	}
	if(i==2)
	{
	 suit=hearts;
	 return suit;
	}
	if(i==3)
	{
	 suit=spades;
	 return suit;
	}

}
#endif 