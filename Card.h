#pragma once

namespace Card {
	public ref class Card {
		//Models
	private:
		unsigned int Color;
		unsigned int Value;

		//Methods
	public:
		unsigned int GetColor();
		unsigned int GetValue();

		//Constructors
	public:
		Card(unsigned int color, unsigned int value);
	};
}