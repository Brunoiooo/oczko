#include "Core.hpp"

namespace Core {
	void Core::NewBet(float baseBet, Player::Player* player)
	{
		if (!CanNewBet(baseBet, player))
			throw new runtime_error("New game can't be started!");

		Bets->push_back(new Bet::Bet(baseBet, Croupier->NewGame(), Croupier));
	}
	bool Core::CanNewBet(float baseBet, Player::Player* player)
	{
		return Bets->size() < 1 && player->CanWithdrawal(baseBet);
	}
	void Core::Hit(Bet::Bet* bet)
	{
		if (!bet->CanHit())
			throw new runtime_error("Hit can't be used!");

		bet->Hit();

		UpdateGame();
	}
	void Core::Stand(Bet::Bet* bet)
	{
		if (!bet->CanStand())
			throw new runtime_error("Stand can't be used!");

		bet->Stand();

		UpdateGame();
	}
	void Core::Double(Bet::Bet* bet, Player::Player* player)
	{
		if (!bet->CanDouble(player))
			throw new runtime_error("Double can't be used!");

		bet->Double(player);

		UpdateGame();
	}
	void Core::Split(Bet::Bet* bet, Player::Player* player)
	{
		if (!bet->CanSplit(player))
			throw new runtime_error("Split can't be used!");

		Bets->push_back(bet->Split(player));

		UpdateGame();
	}
	void Core::UpdateGame()
	{
		for (Bet::Bet* bet : *Bets)
			if (!bet->IsStop())
				return;

		Croupier->FillCroupierHand();

		for (Bet::Bet* bet : *Bets)
			Player->GiveBet(bet);

		Bets->clear();
	}
	Core::~Core()
	{
		delete Player;
		delete Croupier;
		for (Bet::Bet* bet : *Bets)
			delete bet;
		delete Bets;
	}
}
