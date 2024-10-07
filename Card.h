#pragma once

namespace Card {
	public ref class Card {
	private:
		unsigned int Color;
		unsigned int Value;

	public:
		Card(unsigned int color, unsigned int value);
		unsigned int GetColor();
		unsigned int GetValue();
	};
}