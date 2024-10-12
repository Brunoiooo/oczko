#pragma once

#include "Bet.hpp"

#include <iostream>
#include <stdexcept>

namespace Player {
	using namespace std;

	class Player {
	private:
		float Money;
		vector<Bet::Bet*>* Bets;

	public:
		Player() : Money(0), Bets(new vector<Bet::Bet*>()) {}
		Player(float money) : Money(money), Bets(new vector<Bet::Bet*>()) {
			if (money < 0) throw new std::runtime_error("Money can't be less than 0!");
		}

		float GetMoney();

		void Deposite(float deposite);
		bool CanDeposite(float deposite);

		void Withdrawal(float withdrawal);
		bool CanWithdrawal(float withdrawal);

		void GiveBet(Bet::Bet* bet);

		~Player();
	};
}