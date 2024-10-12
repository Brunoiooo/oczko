#pragma once

#include <iostream>
#include <stdexcept>

namespace Card {
	class Card {
	private:
		unsigned int Color;
		unsigned int Value;

	public:
		Card() : Color(0), Value(0) {}
		Card(unsigned int color, unsigned int value) : Color(color), Value(value) {
			if (1 > color || color > 4) throw new std::runtime_error("Color have to be between 1 and 4!");
			if (1 > value || value > 4) throw new std::runtime_error("Value have to be between 2 and 11!");
		}

		unsigned int GetColor();
		unsigned int GetValue();
	};
}