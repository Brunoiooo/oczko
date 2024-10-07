#pragma once

#include "Card.h"

namespace Deck {
	using namespace System::Collections::Generic;

	public ref class Deck {
		//Models
	private:
		List<Card::Card^>^ Cards;

		//Methods
	public:
		Card::Card^ Draw();
		unsigned int GetCountOfCards();

		//Constructors
	public:
		Deck();
	};
}