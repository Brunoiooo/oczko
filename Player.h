#pragma once

#include "Card.h"

namespace Player {
	using namespace System::Collections::Generic;

	public ref class Player {
		//Models
	private:
		List<Card::Card^>^ Cards;
		float Bet;

		//Methods
	public:
		void SetBet(float bet);
		List<Card::Card^>^ GetCards();

		//Constructors
	public:
		Player(float bet, Card::Card^ firstCard);
		Player(float bet, Card::Card^ firstCard, Card::Card^ secondCard);
	};
}