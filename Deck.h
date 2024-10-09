#pragma once

#include "Card.h"

namespace Deck {
	using namespace System::Collections::Generic;

	public ref class Deck {
		//Models
	private:
		List<Card::Card^>^ Cards;
		System::Random^ Random;

		//Methods
	public:
		Card::Card^ Draw();
		unsigned int GetCountOfCards();
		void Reset();

		//Constructors
	public:
		Deck();
	};
}