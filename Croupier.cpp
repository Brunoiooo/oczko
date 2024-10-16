#include "Croupier.hpp"

namespace Croupier {
	Croupier::~Croupier()
	{
		delete CroupierHand;
	}
	Hand::Hand* Croupier::GetCroupierHand()
	{
		return CroupierHand;
	}
	Hand::Hand* Croupier::Croupier::NewGame()
	{
		ResetDeck();

		vector<Card::Card*>* croupierCards = new vector<Card::Card*>();
		croupierCards->push_back(DrawCard());
		croupierCards->push_back(DrawCard());
		CroupierHand = new Hand::Hand(croupierCards);

		vector<Card::Card*>* playerCards = new vector<Card::Card*>();
		playerCards->push_back(DrawCard());
		playerCards->push_back(DrawCard());

		return new Hand::Hand(playerCards);
	}
	void Croupier::FillCroupierHand()
	{
		if (CroupierHand == nullptr)
			throw new runtime_error("Game has not been started!");

		while (CroupierHand->GetScore() < 17)
			CroupierHand->AddCard(DrawCard());
	}
}