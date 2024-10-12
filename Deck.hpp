#pragma once

#include "Card.hpp"

#include <vector>
#include <random>

namespace Deck {
	using namespace std;

	class Deck {
	private:
		vector<Card::Card*>* Cards;
		mt19937 Gen;

		void GenerateDeck();
		void ClearCards();

	public:
		Deck();

		Card::Card* Draw();

		unsigned int GetCountOfCards();

		void Reset();

	protected:
		~Deck();
	};
}