#include "Deck.h"
#include <stdexcept>

namespace Deck {
	//Methods
	Card::Card^ Deck::Draw() {
		if (Cards->Count < 1) throw std::runtime_error("Desk is empty.");

		System::Random^ random = gcnew System::Random();
		int index = random->Next(0, Cards->Count - 1);

		Card::Card^ card = Cards[index];
		Cards->Remove(card);

		return card;
	}

	unsigned int Deck::GetCountOfCards() {
		return Cards->Count;
	}

	//Constructors
	Deck::Deck() {
		Cards = gcnew List<Card::Card^>();

		for (unsigned int i = 1; i <= 4; i++)
		{
			for (unsigned int x = 2; x <= 11; x++) {
				Cards->Add(gcnew Card::Card(i, x));
			}
		}
	}
}