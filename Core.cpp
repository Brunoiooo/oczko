#include "Core.hpp"

namespace Core {
	Player::Player* Core::GetPlayer()
	{
		return Player;
	}
	Croupier::Croupier* Core::GetCroupier()
	{
		return Croupier;
	}
	vector<Bet::Bet*>* Core::GetBets()
	{
		return Bets;
	}
	void Core::NewBet(float baseBet)
	{
		if (!CanNewBet(baseBet))
			throw new runtime_error("New game can't be started!");

		Bets->push_back(new Bet::Bet(baseBet, Croupier->NewGame(), Croupier));
		Player->Withdrawal(baseBet);
	}
	bool Core::CanNewBet(float baseBet)
	{
		return Bets->size() < 1 && Player->CanWithdrawal(baseBet);
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
	void Core::Double(Bet::Bet* bet)
	{
		if (!bet->CanDouble(Player))
			throw new runtime_error("Double can't be used!");

		bet->Double(Player);

		UpdateGame();
	}
	void Core::Split(Bet::Bet* bet)
	{
		if (!bet->CanSplit(Player))
			throw new runtime_error("Split can't be used!");

		Bets->push_back(bet->Split(Player));

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
