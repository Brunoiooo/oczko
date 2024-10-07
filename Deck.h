#pragma once

#include "Card.h"

namespace Deck {
	using namespace System::Collections::Generic;

	public ref class Deck {
	private:
		List<Card::Card^>^ Cards;
	public:
		Deck();
		~Deck();
		Card::Card^ Draw();
		unsigned int GetCountOfCards();
	};
}