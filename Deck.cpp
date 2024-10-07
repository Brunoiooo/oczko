#include "Deck.h"
#include <stdexcept>

namespace Deck {
	//Methods
	Card::Card^ Deck::Draw() {
		if (this->Cards->Count < 1) throw std::runtime_error("Desk is empty.");

		System::Random^ random = gcnew System::Random();
		int index = random->Next(0, this->Cards->Count - 1);

		Card::Card^ card = this->Cards[index];

		return card;
	}

	unsigned int Deck::GetCountOfCards() {
		return this->Cards->Count;
	}

	//Constructors
	Deck::Deck() {
		this->Cards = gcnew List<Card::Card^>();

		for (unsigned int i = 1; i <= 4; i++)
		{
			for (unsigned int x = 2; x <= 11; x++) {
				this->Cards->Add(gcnew Card::Card(i, x));
			}
		}
	}
}