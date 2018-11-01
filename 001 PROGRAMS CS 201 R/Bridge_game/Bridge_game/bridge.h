
#include <iostream>

using namespace std;
// Defining Card Class


class Card {

	char suit; // Defining Suit Variable

	char rank; // Defining rank variable

public:

	Card(); // Defining Card Default Constructor

	Card(char, char); // Defining Overloaded Constructor

	~Card(); // Defining Deconstructor;

	char get_suit() const; // Defining get suit function

	char get_rank() const; // Defining get rank function

	bool set_suit(char s); // Defining boolen set suit function

	bool set_rank(char r); // Defining boolen set rank function

	int  get_sort_value(char r) const; // defining int sort value function

};



//Default constructor defination   

Card::Card()

{

	suit = ' ';

	rank = ' ';

}

//Destructor for Deleting The Card Objects

Card::~Card()
{

	cout << " I am in Card Deconstructor";
}


//Constructor Overloading for Card


Card::Card(char s, char r)

{

	// Evalution of valid Suit i.r 'S' 'D' 'H' 'C'


	if ((s == 'S' || s == 'D' || s == 'H' || s == 'C') && (r == '2' || r == '3' || r == '4' || r == '5' || r == '6' || r == '7' || r == '8' || r == '9' || r == 'T' || r == 'J' || r == 'Q' || r == 'K' || r == 'A'))

	{

		suit = s;

		rank = r;

	}

	else {

		cout << "Please enter valid suit and rank";

	}


}


// Defining get suit function

char Card::get_suit() const {

	return suit;

}


// Defining get rank function
char Card::get_rank() const {

	return rank;

}

// Defining get suit function
bool Card::set_suit(char s)

{


	if (s == 'S' || s == 'D' || s == 'H' || s == 'C')

	{

		suit = s;

		return true;
	}
	else

	{

		return false;

	}

}


// Defining set rank function
bool Card::set_rank(char r)

{

	if (r == '2' || r == '3' || r == '4' || r == '5' || r == '6' || r == '7' || r == '8' || r == '9' || r == 'T' || r == 'J' || r == 'Q' || r == 'K' || r == 'A')

	{

		rank = r;

		return true;

	}
	else
	{

		return false;

	}

}




// Defining sort value function
int Card::get_sort_value(char r) const

{

	// Please check how to get rank in parameter for card?

	switch (rank)

	{

	case '2':

		return 2;

		break;

	case '3':

		return 3;

		break;

	case '4':

		return 4;

		break;

	case '5':

		return 5;

		break;

	case '6':

		return 6;

		break;

	case '7':

		return 7;

		break;

	case '8':

		return 8;

		break;

	case '9':

		return 9;

		break;

	case 'T':

		return 10;

		break;

	case 'J':

		return 11;

		break;

	case 'Q':

		return 12;

		break;

	case 'K':

		return 13;

		break;

	case 'A':

		return 14;

		break;

	default:

		return 0;

	}

}


// Defining maximum hand size for Hand Class
const int HAND_SIZE = 13;


// Declaring and Defining Hand Class

class Hand{


	Card cards[HAND_SIZE]; // Number of Cards in Hand

	int count = 0; // Hand Card Counter


public:

	Hand(); // Hand Constructor

	void take_card(const Card& c);// Declaring take_card in hand function

	void print_hand(); // Declaring print hand function 

	int card_points(); // Declaring card point function for calulating High card points

	void show_bid(); // Declaring  show bid function for calculating bids
};


// defining hand Class Constructor

Hand::Hand()

{

	count = 0;

}


// Defining take card function
void Hand::take_card(const Card& c)

{
	if (count < 13)

	{

		cards[count] = c;

		count++;

	}

	else

	{

		cout << "Hand already full";

	}

}


// Definig print hand function 
void Hand::print_hand()

{
	cout << "Number of Card in Hand is :" << count << endl;

	for (int p = 0; p < count; p++)
	{
		cout << cards[p].get_rank() << cards[p].get_suit() << '\t';
	}

	cout << endl;

}

// Definig card point class

int Hand::card_points(){

	char rk;
	int card_points = 0;
	for (int p = 0; p < count; p++)
	{
		rk = cards[p].get_rank();


		if (rk == 'A'){
			card_points += 4;
		}
		else if (rk == 'K')
		{
			card_points += 3;
		}
		else if (rk == 'Q')
		{
			card_points += 2;
		}
		else if (rk == 'J')
		{
			card_points += 1;
		}
		else
		{
			card_points += 0;
		}

	}

	return card_points;


}

// Defining show bid fucntion
void Hand::show_bid()
{

	char su;
	int spade_points = 0;
	int heart_points = 0;
	int daimond_points = 0;
	int club_points = 0;
	string bid;
	int suit_sum = 0;
	for (int p = 0; p < count; p++)
	{
		su = cards[p].get_suit();


		if (su == 'S')
		{
			spade_points += 1;
		}
		else if (su == 'H')
		{
			heart_points += 1;
		}
		else if (su == 'D')
		{
			daimond_points += 1;
		}
		else if (su == 'C')
		{
			club_points += 1;
		}
	}

	suit_sum = club_points + spade_points + heart_points + daimond_points;

	char rk;
	int card_points = 0;
	for (int q = 0; q < count; q++)
	{
		rk = cards[q].get_rank();


		if (rk == 'A'){
			card_points += 4;
		}
		else if (rk == 'K')
		{
			card_points += 3;
		}
		else if (rk == 'Q')
		{
			card_points += 2;
		}
		else if (rk == 'J')
		{
			card_points += 1;
		}
		else
		{
			card_points += 0;
		}
	}

	cout << spade_points << '\t' << "Spades" << endl;
	cout << heart_points << '\t' << "Hearts" << endl;
	cout << daimond_points << '\t' << "Diamonds" << endl;
	cout << club_points << '\t' << "Clubs" << endl;

	if ((spade_points >= 5 || heart_points >= 5 || daimond_points >= 5 || club_points >= 5) && (card_points >= 13))
	{
		if ((spade_points > heart_points) && (spade_points > daimond_points) && (spade_points > club_points))
		{
			bid = "SPADES";
		}
		else if ((heart_points > spade_points) && (heart_points > daimond_points) && (heart_points > club_points))
		{
			bid = "HEARTS";
		}
		else if ((daimond_points > spade_points) && (daimond_points > heart_points) && (daimond_points > club_points))
		{
			bid = "DAIMONDS";
		}
		else if ((club_points > spade_points) && (club_points > daimond_points) && (club_points > heart_points))
		{
			bid = "CLUBS";
		}
		else
		{
			bid = "SPADES";
		}
	}
	else if ((card_points >= 16 && card_points <= 18) && ((spade_points >= 3) && (heart_points >= 3) && (daimond_points >= 3) &&
		(club_points >= 3)))
	{
		bid = "NO TRUMP";

	}
	else if (suit_sum >= 19)
	{
		if ((spade_points > heart_points) && (spade_points > daimond_points) && (spade_points > club_points))
		{
			bid = "SPADES";
		}
		else if ((heart_points > spade_points) && (heart_points > daimond_points) && (heart_points > club_points))
		{
			bid = "HEARTS";
		}
		else if ((daimond_points > spade_points) && (daimond_points > heart_points) && (daimond_points > club_points))
		{
			bid = "DAIMONDS";
		}
		else if ((club_points > spade_points) && (club_points > daimond_points) && (club_points > heart_points))
		{
			bid = "CLUBS";
		}
		else
		{
			bid = "SPADES";
		}
	}
	else
	{
		bid = "PASS";
	}

	cout << "Bid : " << bid;


}

