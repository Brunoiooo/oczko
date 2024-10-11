#include "Bet.h"

namespace Bet {
	Bet::Bet(float baseBet, Hand::Hand^ croupierHand, Hand::Hand^ playerHand)
	{
		BaseBet = baseBet >= 0 ? baseBet : 0;
		Stop = false;
		Hit = false;
		PlayerHand = playerHand;
		CroupierHand = croupierHand;
	}
	Hand::Hand^ Bet::GetPlayerHand()
	{
		return PlayerHand;
	}
	Hand::Hand^ Bet::GetCroupierHand()
	{
		return CroupierHand;
	}
	float Bet::GetBaseBet()
	{
		return BaseBet;
	}
	void Bet::PlayHit(Card::Card^ card)
	{
		if (Stop)
			throw gcnew System::Exception("Game is stopped.");

		Hit = true;

		AddPlayerCard(card);
	}

	bool Bet::IsHit()
	{
		return Hit;
	}

	void Bet::PlayStand()
	{
		Stop = true;
	}

	void Bet::PlayDouble(Card::Card^ card)
	{
		if (Stop)
			throw gcnew System::Exception("Game is stopped.");
		if (Hit)
			throw gcnew System::Exception("Hit had played.");

		Stop = true;
		BaseBet += BaseBet;
		AddPlayerCard(card);
	}

	Card::Card^ Bet::PlaySplit()
	{
		if(!CanSplit())
			throw gcnew System::Exception("Split can't be used.");

		return PlayerHand->StillCard(PlayerHand->GetCards()[0]);

	}

	bool Bet::CanSplit()
	{
		return (Stop ||
			Hit ||
			PlayerHand->GetCards()->Count != 2 ||
			(PlayerHand->GetCards()[0]->GetValue() != PlayerHand->GetCards()[1]->GetValue())) ? false : true;
	}
	
	float Bet::GetMultiplier()
	{
		return (PlayerHand->GetScore() == 21 || PlayerHand->GetScore() == 22) && PlayerHand->GetCards()->Count == 2 ? 2.5 : 2;
	}
	bool Bet::IsStop()
	{
		return Stop;
	}
	void Bet::AddPlayerCard(Card::Card^ card)
	{
		PlayerHand->AddCart(card);
		
		if (PlayerHand->GetScore() > 21 && PlayerHand->GetCards()->Count > 2) Stop = true;
	}
	bool Bet::IsWin()
	{
		if (!Stop) 
			return false;

		if (PlayerHand->GetScore() > 21 && PlayerHand->GetCards()->Count > 2)
			return false;

		if (CroupierHand->GetScore() > 21 && CroupierHand->GetCards()->Count > 2)
			return true;

		if (CroupierHand->GetScore() < PlayerHand->GetScore())
			return true;

		return false;
	}
	bool Bet::IsLost()
	{
		if (!Stop)
			return false;

		if (PlayerHand->GetScore() > 21 && PlayerHand->GetCards()->Count > 2)
			return true;

		if (CroupierHand->GetScore() > 21 && CroupierHand->GetCards()->Count > 2)
			return false;

		if (CroupierHand->GetScore() > PlayerHand->GetScore())
			return true;

		return false;
	}
	bool Bet::IsDraw()
	{
		if (!Stop)
			return false;

		return !(IsWin() || IsLost());
	}
	float Bet::Payout()
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
}