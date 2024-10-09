#pragma once

#include "Card.h"
#include "Hand.h"

namespace Player {
	using namespace System::Collections::Generic;

	public ref class Player{
	private:
		float Money;

	public:
		Player(float money);
		float GetMoney();
		void SetMoney(float money);
	};
}