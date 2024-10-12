#pragma once

#include "Card.hpp"

#include <vector>

namespace Hand {
	using namespace std;

	class Hand {
	private:
		vector<Card::Card*>* Cards;

	public:
		Hand() : Cards(new vector<Card::Card*>()) {}
		Hand(vector<Card::Card*>* cards) : Cards(cards) {}

		void AddCard(Card::Card* card);
		bool CanAdd();

		Hand* Split();
		bool CanSplit();

		unsigned int GetScore();

	protected:
		~Hand();
	};
}