#include "card.h"
#include <stdexcept>

namespace Card {
	//Methods
	unsigned int Card::GetColor() {
		return Color;
	}

	unsigned int Card::GetValue() {
		return Value;
	}

	//Constructors
	Card::Card(unsigned int color, unsigned int value) {
		if (color < 1 || 4 < color) throw std::runtime_error("Card's color has to be between 1 and 4.");
		if (value < 2 || 11 < value) throw std::runtime_error("Card's value has to be between 21 and 11.");

		Color = color;
		Value = value;
	}
}