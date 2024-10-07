#include "Croupier.h"
#include <stdexcept>

namespace Croupier {
	Croupier::Croupier(Card::Card^ firstCard, Card::Card^ secondCard) {
		this->Cards = gcnew List<Card::Card^>();
		this->Cards->Add(firstCard);
		this->Cards->Add(secondCard);
	}

	Croupier::~Croupier() {
		this->Cards->Clear();
	}

	List<Card::Card^>^ Croupier::GetCards() {
		return this->Cards;
	}
}