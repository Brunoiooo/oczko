#include "Player.h"
#include <stdexcept>

namespace Player {
	Player::Player(float money) {
		Money = money >= 0 ? money : 0;

	}
	float Player::GetMoney()
	{
		return Money;
	}
	void Player::SetMoney(float money)
	{
		Money = money >= 0 ? money : 0;
	}
}