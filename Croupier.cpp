#include "Croupier.hpp"

namespace Croupier {
	Hand::Hand* Croupier::Croupier::NewGame()
	{
		if (CroupierHand != nullptr)
			throw new runtime_error("Game has been started!");

		Reset();

		vector<Card::Card*>* croupierCards = new vector<Card::Card*>();
		croupierCards->push_back(Draw());
		croupierCards->push_back(Draw());
		CroupierHand = new Hand::Hand(croupierCards);

		vector<Card::Card*>* playerCards = new vector<Card::Card*>();
		playerCards->push_back(Draw());
		playerCards->push_back(Draw());

		return new Hand::Hand(playerCards);
	}
	void Croupier::FillCroupierHand()
	{
		if (CroupierHand == nullptr)
			throw new runtime_error("Game has not been started!");

		while (CroupierHand->GetScore() < 17)
			CroupierHand->AddCard(Draw());

		CroupierHand = nullptr;
	}
}