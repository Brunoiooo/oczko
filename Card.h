#pragma once

namespace Card {
	public ref class Card {
	private:
		unsigned int Color;
		unsigned int Value;

	public:
		unsigned int GetColor();
		unsigned int GetValue();

	public:
		Card(unsigned int color, unsigned int value);
	};
}