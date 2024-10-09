#pragma once

#include "Hand.h"
#include "Card.h"

namespace Bet {
	using namespace System::Collections::Generic;

	public ref class Bet {
	private:		
		float BaseBet;
		bool Stop;
		bool Hit;
		Hand::Hand^ PlayerHand;
		Hand::Hand^ CroupierHand;

	public:
		Bet(float baseBet, Hand::Hand^ playerHand, Hand::Hand^ croupierHand);
		Hand::Hand^ GetPlayerHand();
		Hand::Hand^ GetCroupierHand();
		float GetBaseBet();
		void PlayHit(Card::Card^ card);
		bool IsHit();
		void PlayStand();
		void PlayDouble(Card::Card^ card);
		Card::Card^ PlaySplit();
		bool CanSplit();
		float GetMultiplier();
		bool IsStop();
		void AddPlayerCard(Card::Card ^ card);
		bool IsWin();
		bool IsLost();
		bool IsDraw();
		float Payout();
	};
}