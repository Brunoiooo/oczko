#pragma once

#include "Hand.hpp"
#include "Deck.hpp"
#include "Card.hpp"

namespace Croupier 
{
	using namespace std;

	class Croupier
	{
	private: 
		Hand::Hand* CroupierHand;
		Deck::Deck* Deck;

	public:
		Croupier() : CroupierHand(nullptr), Deck(new Deck::Deck()) {}
		~Croupier();
		Hand::Hand* GetCroupierHand();
		Hand::Hand* NewGame();
		void FillCroupierHand();
		Card::Card* DrawCard();
	};
}