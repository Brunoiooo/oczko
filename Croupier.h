#pragma once

#include "Card.h"
#include "Hand.h"
#include "Deck.h"

namespace Croupier {
	using namespace System::Collections::Generic;

	public ref class Croupier {
	private:
		Deck::Deck^ Deck;
		Hand::Hand^ CroupierHand;

	public:
		Croupier();

		Hand::Hand^ GetCroupierHand();
		Hand::Hand^ NewCroupierHand();

		Hand::Hand^ NewHand();
		
		void FillCroupierHand();
		Deck::Deck^ GetDeck();

	};
}