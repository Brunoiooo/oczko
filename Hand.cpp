#include "Hand.h"

namespace Hand {
	Hand::Hand(List<Card::Card^>^ cards)
	{
		Cards = cards;
	}

	List<Card::Card^>^ Hand::GetCards()
	{
		return Cards;
	}

	Card::Card^ Hand::StillCard(Card::Card^ card)
	{
		Cards->Remove(card);
		return card;
	}

	void Hand::AddCart(Card::Card^ card)
	{
		Cards->Add(card);
	}

	int Hand::GetScore()
	{
		int score = 0;
		for each(Card::Card^ card in Cards) 
			score += card->GetValue();
			
		return score;
	}


}
