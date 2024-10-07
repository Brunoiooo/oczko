#include "card.h"
#include <stdexcept>

namespace Card {
	Card::Card(unsigned int color, unsigned int value) {
		if (color < 1 || 4 < color) throw std::runtime_error("Card's color has to be between 1 and 4.");
		if (value < 2 || 11 < value) throw std::runtime_error("Card's value has to be between 21 and 11.");

		this->Color = color;
		this->Value = value;
	};

	unsigned int Card::GetColor() {
		return this->Color;
	}

	unsigned int Card::GetValue() {
		return this->Value;
	}
}