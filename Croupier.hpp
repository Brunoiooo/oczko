#pragma once

#include "Hand.hpp"
#include "Deck.hpp"
#include "Card.hpp"

namespace Croupier {
	using namespace std;

	class Croupier : public Deck::Deck{
	private: 
		Hand::Hand* CroupierHand;

	public:
		Croupier() : Deck::Deck(), CroupierHand(nullptr) {}
		~Croupier();
		Hand::Hand* GetCroupierHand();
		Hand::Hand* NewGame();
		void FillCroupierHand();
	};
}