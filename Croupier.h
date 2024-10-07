#pragma once

#include "Card.h"
#include <stdexcept>

namespace Croupier {
	using namespace System::Collections::Generic;

	public ref class Croupier {
		//Models
	private:
		List<Card::Card^>^ Cards;

		//Methods
	public:
		List<Card::Card^>^ GetCards();

		//Constructors
	public:
		Croupier(Card::Card^ firstCard, Card::Card^ secondCard);
	};
}