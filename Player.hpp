#pragma once

#include "Bet.hpp"

#include <iostream>
#include <stdexcept>
#include <string>

namespace Bet 
{
	class Bet;
}

namespace Player 
{
	using namespace std;

	class Player 
	{
	private:
		float Money;
		string Name;
		vector<Bet::Bet*>* Bets;

	public:
		Player() : Name("Player"), Money(0), Bets(new vector<Bet::Bet*>()) {}
		Player(float money, string name) : Name(name), Money(money), Bets(new vector<Bet::Bet*>())
		{
			if (money < 0) 
				throw new runtime_error("Money can't be less than 0!");

			if (name.size() < 1)
				throw new runtime_error("Name can't be empty!");
		}

		float GetMoney();

		vector<Bet::Bet*>* GetBets();

		void Deposite(float deposite);
		bool CanDeposite(float deposite);

		void Withdrawal(float withdrawal);
		bool CanWithdrawal(float withdrawal);

		void GiveBet(Bet::Bet* bet);

		string GetName();

		~Player();
	};
}