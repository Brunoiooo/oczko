#include "Croupier.hpp"

namespace Croupier {
	Croupier::~Croupier()
	{
		if(CroupierHand)
			delete CroupierHand;

		delete Deck;
	}
	Hand::Hand* Croupier::GetCroupierHand()
	{
		return CroupierHand;
	}
	Hand::Hand* Croupier::Croupier::NewGame()
	{
		Deck->ResetDeck();

		vector<Card::Card*>* croupierCards = new vector<Card::Card*>();
		croupierCards->push_back(Deck->DrawCard());
		croupierCards->push_back(Deck->DrawCard());
		CroupierHand = new Hand::Hand(croupierCards);

		vector<Card::Card*>* playerCards = new vector<Card::Card*>();
		playerCards->push_back(Deck->DrawCard());
		playerCards->push_back(Deck->DrawCard());

		return new Hand::Hand(playerCards);
	}
	void Croupier::FillCroupierHand()
	{
		if (CroupierHand == nullptr)
			throw new runtime_error("Game has not been started!");

		while (CroupierHand->GetScore() < 17)
			CroupierHand->AddCard(Deck->DrawCard());
	}
	Card::Card* Croupier::DrawCard()
	{
		return Deck->DrawCard();
	}
}