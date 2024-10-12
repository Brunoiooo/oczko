#include "Player.hpp"

namespace Player {
	float Player::GetMoney()
	{
		return Money;
	}
	void Player::Deposite(float deposite)
	{
		if (!CanDeposite(deposite))
			throw new runtime_error("Deposite can't be less than 0!");

		Money += deposite;
	}
	bool Player::CanDeposite(float deposite)
	{
		return deposite >= 0 ? true : false;
	}
	void Player::Withdrawal(float withdrawal)
	{
		if (!CanWithdrawal(withdrawal))
			throw new runtime_error("Deposite can't be less than 0!");

		Money -= withdrawal;
	}
	bool Player::CanWithdrawal(float withdrawal)
	{
		return withdrawal >= 0 && Money >= withdrawal ? true : false;
	}
	void Player::GiveBet(Bet::Bet* bet)
	{
		if (bet->IsStop())
			throw new runtime_error("Bet have to be finished!");

		Money += bet->GetPay();
		Bets->push_back(bet);
	}
	Player::~Player()
	{
		for (Bet::Bet* bet : *Bets)
			delete bet;

		delete Bets;
	}
}