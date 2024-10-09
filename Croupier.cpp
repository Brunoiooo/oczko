#include "Croupier.h"
#include <stdexcept>

namespace Croupier {
	//Methods
	List<Card::Card^>^ Croupier::GetCards() {
		return Cards;
	}

	int Croupier::GetScore()
	{
		List<Card::Card^>^ cards = GetCards();

		int score = 0;
		for (int i = 0; i < cards->Count; i++)
			score += cards[i]->GetValue();

		return score;
	}

	//Constructors
	Croupier::Croupier(Card::Card^ firstCard, Card::Card^ secondCard) {
		Cards = gcnew List<Card::Card^>();
		Cards->Add(firstCard);
		Cards->Add(secondCard);
	}
}