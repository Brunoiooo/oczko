#include "Hand.hpp"

namespace Hand {
	void Hand::AddCard(Card::Card* card)
	{
		if (!CanAdd())
			throw new runtime_error("Card can't be added!");

		Cards->push_back(card);
	}

	bool Hand::CanAdd()
	{
		return GetScore() > 21 && Cards->size() > 2 ? true : false;
	}

	Hand* Hand::Split()
	{
		if (!CanSplit())
			runtime_error("Hand can't be splited!");

		vector<Card::Card*>* cards = new vector<Card::Card*>();
		cards->push_back((*Cards)[1]);
		Cards->pop_back();

		Hand* hand = new Hand(cards);

		return hand;
	}

	bool Hand::CanSplit()
	{
		return Cards->size() == 2 && (*Cards)[0]->GetValue() == (*Cards)[1]->GetValue() ? true : false;
	}

	unsigned int Hand::GetScore()
	{
		unsigned int score = 0;

		for (Card::Card* card : *Cards)
			score += card->GetValue();

		return score;
	}

	unsigned int Hand::GetSize()
	{
		return Cards->size();
	}

	Hand::~Hand()
	{
		for (Card::Card* card : *Cards)
			delete card;
		
		delete Cards;
	}

}
