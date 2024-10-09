#pragma once

#include "Card.h"

namespace Deck {
	using namespace System::Collections::Generic;

	public ref class Deck {
	private:
		List<Card::Card^>^ Cards;
		System::Random^ Random;

	public:
		Card::Card^ Draw();
		unsigned int GetCountOfCards();
		void Reset();

	public:
		Deck();
	};
}