// Example program
/*
Swati Singh
bkhe50@umkc.edu
ECE 216
Assignment 2 - bridge.cpp
Due 06/21/17
Description: This program simulates a card game of bridge.  It takes the card rank and suit from the 
user and distributes it to the player's hand.
It also displays print card in the hand and calculates high card points and does the bidding
Inputs: CARD ,SUITS AND RANKS.
Outputs: Various status messages, to screen.
Algorithm:
1. Initialize the card class
2.Ask the user to enter the card suits and rank.
3. Initiate the hand class.
4. Pass specific card to hand.
5. If the hand is full of 13 card: then no more card will be added
6. Show the hand card, calculate high card points and make a bid.
*/

#include <iostream>

#include <string>

#include "bridge.h"
using namespace std;


int main()
{

	Card C[13];

	char s, r;

	int cards_num = 0;
	for (int i = 0; i < 13; i++)

	{
		
		cout << "Please enter rank for Card[ " << i + 1 << "]:";

		cin >> r;

		cout << "Please enter suit for Card[ " << i + 1 << "]:";

		cin >> s;

		C[i].set_rank(r);

		C[i].set_suit(s);

		cards_num++;
	}



	Hand H1;

	int CP = 0;

	for (int j = 0; j < cards_num; j++)
	{
		H1.take_card(C[j]);

	}

	H1.print_hand();

	                
	CP=H1.card_points();
	cout << CP << " High cards Points" << endl <<endl;

	H1.show_bid();

}
