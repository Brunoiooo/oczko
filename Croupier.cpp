#include "Croupier.h"
#include <stdexcept>

namespace Croupier {
	//Methods
	List<Card::Card^>^ Croupier::GetCards() {
		return Cards;
	}

	//Constructors
	Croupier::Croupier(Card::Card^ firstCard, Card::Card^ secondCard) {
		Cards = gcnew List<Card::Card^>();
		Cards->Add(firstCard);
		Cards->Add(secondCard);
	}
}