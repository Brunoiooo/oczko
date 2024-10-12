#pragma once

#include "Player.hpp"
#include "Croupier.hpp"
#include "Bet.hpp"

namespace Core {
	using namespace std;

	class Core {
	private:
		Player::Player* Player;
		Croupier::Croupier* Croupier;
		vector<Bet::Bet*>* Bets;

	public:
		Core() : 
			Player(new Player::Player()), 
			Croupier(new Croupier::Croupier()), 
			Bets(new vector<Bet::Bet*>()) {}
		Core(float money) : 
			Player(new Player::Player(money)), 
			Croupier(new Croupier::Croupier()), 
			Bets(new vector<Bet::Bet*>()) {}

		void NewBet(float baseBet, Player::Player* player);
		bool CanNewBet(float baseBet, Player::Player* player);

		void Hit(Bet::Bet* bet);

		void Stand(Bet::Bet* bet);

		void Double(Bet::Bet* bet, Player::Player* player);

		void Split(Bet::Bet* bet, Player::Player* player);

		void UpdateGame();

		~Core();
	};
}