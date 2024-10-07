#include "Player.h"
#include <stdexcept>

namespace Player {
	Player::Player(float bet, Card::Card^ firstCard) {
		if (bet <= 0) throw std::runtime_error("Bet has to be bigger than 0.");

		this->Bet = bet;

		this->Cards = gcnew List<Card::Card^>();
		this->Cards->Add(firstCard);
	}

	Player::Player(float bet, Card::Card^ firstCard, Card::Card^ secondCard) {
		if (bet <= 0) throw std::runtime_error("Bet has to be bigger than 0.");

		this->Bet = bet;

		this->Cards = gcnew List<Card::Card^>();
		this->Cards->Add(firstCard);
		this->Cards->Add(secondCard);
	}

	Player::~Player() {
		this->Cards->Clear();
	}

	void Player::SetBet(float bet) {
		if (bet <= 0) throw std::runtime_error("Bet has to be bigger than 0.");

		this->Bet = bet;
	}

	List<Card::Card^>^ Player::GetCards() {
		return this->Cards;
	}
}