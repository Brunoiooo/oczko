#include "Player.h"
#include <stdexcept>

namespace Player {
	Player::Player(float money) {
		Money = 0;
		Deposit(money);
	}
	float Player::GetMoney()
	{
		return Money;
	}
	bool Player::CanWithdrawal(float money)
	{
		return money > 0 && Money >= money ? true : false;
	}
	void Player::Deposit(float money)
	{
		if (money < 0)
			throw gcnew System::Exception("Money can't be less than 0!");

		Money += money;
	}
	void Player::Player::Withdrawal(float money)
	{
		if (!CanWithdrawal(money))
			throw gcnew System::Exception("Wrong value!");

		Money -= money;
	}
}