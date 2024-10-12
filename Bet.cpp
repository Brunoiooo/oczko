#include "Bet.hpp"

namespace Bet {
	Hand::Hand* Bet::GetHand()
	{
		return PlayerHand;
	}
	float Bet::GetBaseBet()
	{
		return BaseBet;
	}
	float Bet::GetMultiplier()
	{
		return PlayerHand->GetScore() >= 21 && PlayerHand->GetSize() == 2 && !IsSplited ? 2.5 : 2;
	}
	void Bet::Hit()
	{
		if (!CanHit())
			throw new runtime_error("Hit can't be used!");

		PlayerHand->AddCard(Croupier->DrawCard());
		IsHitted = true;
	}
	bool Bet::CanHit()
	{
		return !IsStop();
	}
	void Bet::Stand()
	{
		if (!CanStand())
			throw new runtime_error("Stand can't be used!");

		IsStanded = true;
	}
	bool Bet::CanStand()
	{
		return !IsStop();
	}
	void Bet::Double(Player::Player* player)
	{
		if (!CanDouble(player))
			throw new runtime_error("Double can't be used!");

		PlayerHand->AddCard(Croupier->DrawCard());
		player->Withdrawal(BaseBet);
		BaseBet *= 2;
		IsDoubled = true;
	}
	bool Bet::CanDouble(Player::Player* player)
	{
		return player->CanWithdrawal(BaseBet) && !IsStop() && !IsHitted;
	}
	Bet* Bet::Split(Player::Player* player)
	{
		if (!CanSplit(player))
			throw new runtime_error("Split can't be used!");

		Bet* bet = new Bet(BaseBet, PlayerHand->Split(), Croupier, true);

		player->Withdrawal(BaseBet);
		IsSplited = true;

		return bet;
	}
	bool Bet::CanSplit(Player::Player* player)
	{
		return player->CanWithdrawal(BaseBet) && !IsSplited && !IsStop() && PlayerHand->CanSplit();
	}
	bool Bet::IsStop()
	{
		if (IsStanded)
			return true;

		if (IsDoubled)
			return true;

		if (PlayerHand->GetSize() == 2 && !IsSplited) 
			return false;
		
		if (PlayerHand->GetScore() > 21)
			return true;

		return false;
	}
	bool Bet::IsWin()
	{
		if (!IsStop())
			return false;

		if (PlayerHand->GetScore() > 21 && PlayerHand->GetSize() > 2)
			return false;

		if (Croupier->GetCroupierHand()->GetScore() > 21 && Croupier->GetCroupierHand()->GetSize() > 2)
			return true;

		if (Croupier->GetCroupierHand()->GetScore() < PlayerHand->GetScore())
			return true;

		return false;
	}
	bool Bet::IsLost()
	{
		if (!IsStop())
			return false;

		if (PlayerHand->GetScore() > 21 && PlayerHand->GetSize() > 2)
			return true;

		if (Croupier->GetCroupierHand()->GetScore() > 21 && Croupier->GetCroupierHand()->GetSize() > 2)
			return false;

		if (Croupier->GetCroupierHand()->GetScore() > PlayerHand->GetScore())
			return true;

		return false;
	}
	bool Bet::IsDraw()
	{
		if (!IsStop())
			return false;

		return !(IsWin() || IsLost());
	}
	float Bet::GetPay()
	{
		if (!IsStop())
			return 0;
		else if (IsWin())
			return GetMultiplier() * BaseBet;
		else if (IsLost())
			return 0;
		else if (IsDraw())
			return BaseBet;

		return 0;
	}
	Bet::~Bet()
	{
		delete PlayerHand;
		delete Croupier;
	}
}