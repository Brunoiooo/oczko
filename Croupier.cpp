#include "Croupier.h"

namespace Croupier {
	Croupier::Croupier() {
		Deck = gcnew Deck::Deck();
		CroupierHand = NewHand();
	}

	Hand::Hand^ Croupier::NewHand()
	{
		List<Card::Card^>^ cards = gcnew List<Card::Card^>();
		cards->Add(GetDeck()->Draw());
		cards->Add(GetDeck()->Draw());

		return gcnew Hand::Hand(cards);
	}

	Hand::Hand^ Croupier::GetCroupierHand()
	{
		return CroupierHand;
	}

	Hand::Hand^ Croupier::NewCroupierHand()
	{
		Deck->Reset();
		CroupierHand = NewHand();
		return CroupierHand;
	}

	void Croupier::FillCroupierHand()
	{
		while (CroupierHand->GetScore() < 17) 
			CroupierHand->AddCart(Deck->Draw());
	}

	Deck::Deck^ Croupier::GetDeck() {
		return Deck;
	}
}