#pragma once

#include "Card.h"

namespace Player {
	using namespace System::Collections::Generic;

	public ref class Player {
		//Models
	private:
		List<Card::Card^>^ Cards;
		float Bet;
		float Multiplier;
		bool Stand;

		//Methods
	public:
		float GetBet();
		float GetMultiplier();
		void SetMultiplier(float multiplier);
		List<Card::Card^>^ GetCards();
		int GetScore();
		bool GetStand();
		void SetStand();
		
			
		//Constructors
	public:
		Player(float bet, Card::Card^ firstCard);
		Player(float bet, Card::Card^ firstCard, Card::Card^ secondCard);
	};
}