#pragma once

#include "Card.h"

namespace Player {
	using namespace System::Collections::Generic;

	public ref class Player {
	private:
		List<Card::Card^>^ Cards;
		float Bet;
	public:
		Player(float bet, Card::Card^ firstCard);
		Player(float bet, Card::Card^ firstCard, Card::Card^ secondCard);
		~Player();
		void SetBet(float bet);
		List<Card::Card^>^ GetCards();
	};
}