#ifndef H_card
#define H_card
#include <string>
#include <iostream>

using namespace std;

class card
{
public:
	//constructor
	card();
	//constructor with parameter
	card(string cardFace, string cardSuit);
	//function to print card
	string print() const;
	
private:
	string face;
	string suit;
};

card::card()
{
}

card::card(string cardFace, string cardSuit)
{
	face = cardFace;
	suit = cardSuit;
}

string card::print() const
{
	return (face + " of " + suit);
}

#endif
