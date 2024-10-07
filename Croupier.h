#pragma once

#include "Card.h"
#include <stdexcept>

namespace Croupier {
	using namespace System::Collections::Generic;

	public ref class Croupier {
	private:
		List<Card::Card^>^ Cards;
	public:
		Croupier(Card::Card^ firstCard, Card::Card^ secondCard);
		~Croupier();
		List<Card::Card^>^ GetCards();
	};
}