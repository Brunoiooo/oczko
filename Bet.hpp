#pragma once

#include "Hand.hpp"
#include "Card.hpp"
#include "Croupier.hpp"
#include "Player.hpp"

namespace Player {
	class Player;
}

namespace Hand {
	class Hand;
}

namespace Card {
	class Card;
}

namespace Croupier {
	class Croupier;
}


namespace Bet {
	using namespace std;

	class Bet {
	private:
		float BaseBet;
		Hand::Hand* PlayerHand;
		Hand::Hand* CroupierHand;
		bool IsHitted;
		bool IsStanded;
		bool IsDoubled;
		bool IsSplited;

	public:
		Bet(float baseBet, Hand::Hand* playerHand, Hand::Hand* croupierHand) : BaseBet(baseBet),
			PlayerHand(playerHand), 
			CroupierHand(croupierHand),
			IsHitted(false),
			IsStanded(false),
			IsDoubled(false),
			IsSplited(false) {
			if(baseBet < 0)
				throw std::runtime_error("Bet can't be less than 0!");
		}
		Bet(float baseBet, Hand::Hand* playerHand, Hand::Hand* croupierHand, bool IsSplited) : BaseBet(baseBet),
			PlayerHand(playerHand), 
			CroupierHand(croupierHand),
			IsHitted(false),
			IsStanded(false),
			IsDoubled(false),
			IsSplited(IsSplited) {
			if (baseBet < 0) 
				throw std::runtime_error("Bet can't be less than 0!");
		}
		
		Hand::Hand* GetHand();

		Hand::Hand* GetCroupierHand();

		float GetBaseBet();

		float GetMultiplier();

		void Hit(Card::Card* card);
		bool CanHit();

		void Stand();
		bool CanStand();

		void Double(Player::Player* player, Card::Card* card);
		bool CanDouble(Player::Player* player);

		Bet* Split(Player::Player* player);
		bool CanSplit(Player::Player* player);

		bool IsStop();

		bool IsWin();
		bool IsLost();
		bool IsDraw();

		float GetPay();

		~Bet();
	};
}