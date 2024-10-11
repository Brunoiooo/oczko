#include "card.h"

namespace Card {
	unsigned int Card::GetColor() {
		return Color;
	}

	unsigned int Card::GetValue() {
		return Value;
	}

	Card::Card(unsigned int color, unsigned int value) {
		Color = color;
		Value = value;
	}
}