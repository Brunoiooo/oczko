#pragma once

#include "Card.h"

namespace Hand {
	using namespace System::Collections::Generic;

	public ref class Hand  {
	private: 
		List<Card::Card^>^ Cards;

	public:
		Hand(List<Card::Card^>^ cards);
		List<Card::Card^>^ GetCards();
		Card::Card^ StillCard(Card::Card^ card);
		void AddCart(Card::Card^ card);
		int GetScore();
	};
}