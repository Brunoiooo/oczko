#include "Deck.h"
#include <stdexcept>

namespace Deck {
	Card::Card^ Deck::Draw() {
		if (Cards->Count < 1) Reset();

		Card::Card^ card = Cards[Random->Next(0, Cards->Count - 1)];
		Cards->Remove(card);

		return card;
	}

	unsigned int Deck::GetCountOfCards() {
		return Cards->Count;
	}

	void Deck::Reset()
	{
		Cards = gcnew List<Card::Card^>();
		for (unsigned int i = 1; i <= 4; i++)
			for (unsigned int x = 2; x <= 11; x++) 
				Cards->Add(gcnew Card::Card(i, x));
	}

	Deck::Deck() {
		Random = gcnew System::Random();
		Cards = gcnew List<Card::Card^>();

		Reset();
	}
}