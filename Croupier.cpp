#include "Croupier.h"
#include <stdexcept>

namespace Croupier {
	//Methods
	List<Card::Card^>^ Croupier::GetCards() {
		return this->Cards;
	}

	//Constructors
	Croupier::Croupier(Card::Card^ firstCard, Card::Card^ secondCard) {
		this->Cards = gcnew List<Card::Card^>();
		this->Cards->Add(firstCard);
		this->Cards->Add(secondCard);
	}
}