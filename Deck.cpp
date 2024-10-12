#include "Deck.hpp"

namespace Deck {
	void Deck::GenerateDeck()
	{
		Cards = new vector<Card::Card*>();

		for (unsigned int c = 1; c <= 4; c++)
			for (unsigned int v = 2; v <= 11; v++)
				Cards->push_back(new Card::Card(c, v));
	}
	void Deck::ClearCards()
	{
		for (Card::Card* card : *Cards)
			delete card;

		delete Cards;
	}
	Deck::Deck() : Gen(std::random_device{}())
	{
		GenerateDeck();
	}
	Card::Card* Deck::DrawCard()
	{
		if (Cards->empty())
			ResetDeck();

		uniform_real_distribution<> distrib(0, Cards->size() - 1);
		unsigned int rand = distrib(Gen);

		Card::Card* card = (*Cards)[rand];
		Cards->erase(Cards->begin() + rand);

		return card;
	}
	unsigned int Deck::GetCountOfDeckCards()
	{
		return Cards->size();
	}
	void Deck::ResetDeck()
	{
		ClearCards();
		GenerateDeck();
	}
	Deck::~Deck()
	{
		ClearCards();
	}
}