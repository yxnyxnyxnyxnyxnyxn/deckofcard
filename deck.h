#ifndef H_deck
#define H_deck
#include "card.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;
const int CARDS_PER_DECK = 52;

class Deck
{
public:
	Deck();
	void shuffle();
	card dealCard();
	void printDeck() const;
private:
	card *deck;
	int currentCard;
};

Deck::Deck()
{
	string faces[] = {"Ace","Deuce","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
	string suits[] = {"Hearts","Diamonds","Clubs","Spades"};
	deck = new card[CARDS_PER_DECK];
	currentCard = 0;
	//popultae the deck
	for (int count = 0; count < CARDS_PER_DECK; count++){
		deck[count] = card(faces[count%13], suits[count/13]);
	}
}

void Deck::printDeck() const
{
	for (int i = 0; i <CARDS_PER_DECK;i++){
		cout << setw(19) << deck[i].print();
		if ((i+1) %4 == 0) cout <<endl;
	}
}

void Deck::shuffle()
{
	currentCard = 0;
	for (int first = 0; first < CARDS_PER_DECK; first++){
		int second = (rand() + time(0)) % CARDS_PER_DECK;
		card temp = deck[first];
		deck[first] = deck[second];
		deck[second] = temp;
	}
}

card Deck::dealCard()
{
	if (currentCard > CARDS_PER_DECK) shuffle();
	if (currentCard < CARDS_PER_DECK) return (deck[currentCard++]);
	return (deck[0]);
}

#endif

