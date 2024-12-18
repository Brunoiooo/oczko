#include "Player.hpp"

namespace Player {
	float Player::GetMoney()
	{
		return Money;
	}
	vector<Bet::Bet*>* Player::GetBets()
	{
		return Bets;
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
		if (!bet->IsStop())
			throw new runtime_error("Bet have to be finished!");

		Money += bet->GetPay();
		Bets->push_back(bet);
	}
	string Player::GetName()
	{
		return Name;
	}
	void Player::AddHand(Hand::Hand* hand)
	{
		Hands->push_back(hand);
	}
	void Player::ClearHands()
	{
		Hands->clear();
	}
	Player::~Player()
	{
		for (Bet::Bet* bet : *Bets)
			delete bet;
		delete Bets;

		for (Hand::Hand* hand : *Hands)
			delete hand;
		delete Hands;
	}
}