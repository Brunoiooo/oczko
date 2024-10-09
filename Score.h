#pragma once

#include "Player.h"
#include "Croupier.h"

namespace Score {
	public ref class Score {
	private:
		Player::Player^ Player;
		Croupier::Croupier^ Croupier;

	public:
		Score(Player::Player^ player, Croupier::Croupier^ croupier);
		Player::Player^ GetPlayer();
		Croupier::Croupier^ GetCroupier();
		float Withdraw();
		int IsWin();
	};
}