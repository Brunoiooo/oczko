#include "GameForm.h"

namespace oczko {
	void GameForm::UpdateComponents()
	{
		UpdateStartBetButton();
		UpdateStartBetLabel();
		UpdateStartBetTextbox();
	}
	void GameForm::UpdateStartBetButton()
	{
		if (core->GetBets()->size() > 0)
			start_bet_button->Hide();
		else
			start_bet_button->Show();
	}
	void GameForm::UpdateStartBetLabel()
	{
		if (core->GetBets()->size() > 0)
			start_bet_label->Hide();
		else
			start_bet_label->Show();
	}
	void GameForm::UpdateStartBetTextbox()
	{
		if (core->GetBets()->size() > 0)
			start_bet_textbox->Hide();
		else
			start_bet_textbox->Show();
	}
}
