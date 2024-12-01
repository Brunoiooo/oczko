#pragma once

#include "Card.hpp"

#include <vector>
#include <random>

namespace Deck 
{
	using namespace std;

	class Deck 
	{
	private:
		vector<Card::Card*>* Cards;
		mt19937 Gen;

		void GenerateDeck();
		void ClearCards();

	public:
		Deck();

		Card::Card* DrawCard();

		unsigned int GetCountOfDeckCards();

		void ResetDeck();

	protected:
		~Deck();
	};
}