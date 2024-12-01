#include "Bet.hpp"

namespace Bet {
	Hand::Hand* Bet::GetHand()
	{
		return PlayerHand;
	}
	Hand::Hand* Bet::GetCroupierHand()
	{
		return CroupierHand;
	}
	float Bet::GetBaseBet()
	{
		return BaseBet;
	}
	float Bet::GetMultiplier()
	{
		return PlayerHand->GetScore() >= 21 && PlayerHand->GetSize() == 2 && !IsSplited ? 2.5 : 2;
	}
	void Bet::Hit(Card::Card* card)
	{
		if (!CanHit())
			throw new runtime_error("Hit can't be used!");

		PlayerHand->AddCard(card);
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
	void Bet::Double(Player::Player* player, Card::Card* card)
	{
		if (!CanDouble(player))
			throw new runtime_error("Double can't be used!");

		PlayerHand->AddCard(card);
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

		Bet* bet = new Bet(BaseBet, PlayerHand->Split(), CroupierHand, true);

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

		if (CroupierHand->GetScore() > 21 && CroupierHand->GetSize() > 2)
			return true;

		if (CroupierHand->GetScore() < PlayerHand->GetScore())
			return true;

		return false;
	}
	bool Bet::IsLost()
	{
		if (!IsStop())
			return false;

		if (PlayerHand->GetScore() > 21 && PlayerHand->GetSize() > 2)
			return true;

		if (CroupierHand->GetScore() > 21 && CroupierHand->GetSize() > 2)
			return false;

		if (CroupierHand->GetScore() > PlayerHand->GetScore())
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
		delete CroupierHand;
	}
}