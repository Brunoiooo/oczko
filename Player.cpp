#include "Player.h"
#include <stdexcept>

namespace Player {
	//Methods
	float Player::GetBet() {
		return Bet;
	}

	float Player::GetMultiplier() {
		return Multiplier;
	}

	void Player::SetMultiplier(float multiplier) {
		SetMultiplier(multiplier);
	}

	List<Card::Card^>^ Player::GetCards() {
		return Cards;
	}

	int Player::GetScore()
	{
		List<Card::Card^>^ cards = GetCards();

		int score = 0;
		for (int i = 0; i < cards->Count; i++)
			score += cards[i]->GetValue();

		return score;
	}

	bool Player::GetStand()
	{
		return Stand;
	}

	void Player::SetStand()
	{
		Stand = true;
	}

	//Constructors
	Player::Player(float bet, Card::Card^ firstCard) {
		if (bet <= 0) throw std::runtime_error("Bet has to be bigger than 0.");

		Bet = bet;

		Cards = gcnew List<Card::Card^>();
		Cards->Add(firstCard);

		Multiplier = 1;

		Stand = false;
	}

	Player::Player(float bet, Card::Card^ firstCard, Card::Card^ secondCard) {
		if (bet <= 0) throw std::runtime_error("Bet has to be bigger than 0.");

		Bet = bet;

		Cards = gcnew List<Card::Card^>();
		Cards->Add(firstCard);
		Cards->Add(secondCard);

		Multiplier = 1;

		Stand = false;
	}
}