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

		Player::Player* GetPlayer();
		Croupier::Croupier* GetCroupier();
		vector<Bet::Bet*>* GetBets();

		void NewBet(float baseBet);
		bool CanNewBet(float baseBet);

		void Hit(Bet::Bet* bet);

		void Stand(Bet::Bet* bet);

		void Double(Bet::Bet* bet);

		void Split(Bet::Bet* bet);

		void UpdateGame();

		~Core();
	};
}