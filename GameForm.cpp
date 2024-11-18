#include "GameForm.h"

namespace oczko {
	void GameForm::UpdateComponents()
	{
		UpdateStartBetButton();
		UpdateStartBetLabel();
		UpdateStartBetTextbox();
		UpdatePlayerWalletLabel();
		UpdatePlayerHandListbox();
		UpdatePlayerBetsListbox();
		UpdatePlayerHandsListbox();
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
	void GameForm::UpdatePlayerWalletLabel()
	{
		player_wallet_label->Text = "Wallet: " + core->GetPlayer()->GetMoney();
	}
	void GameForm::UpdatePlayerHandListbox()
	{
		player_hand_listview->Items->Clear();
		
		if (player_hands_listbox->SelectedIndex >= 0)
			for (Card::Card* card : *core->GetBets()->at(player_hands_listbox->SelectedIndex)->GetHand()->GetCards())
				player_hand_listview->Items->Add(card->GetColor().ToString() + card->GetValue().ToString());
		else if (player_bets_listbox->SelectedIndex >= 0)
			for (Card::Card* card : *core->GetPlayer()->GetBets()->at(player_bets_listbox->SelectedIndex)->GetHand()->GetCards())
				player_hand_listview->Items->Add(card->GetColor().ToString() + card->GetValue().ToString());
	}
	void GameForm::UpdatePlayerHandsListbox()
	{
		player_hands_listbox->Items->Clear();

		for (unsigned int i = 0; i < core->GetBets()->size(); i++)
			player_hands_listbox->Items->Add("#" + i + " Hand");
	}
	void GameForm::UpdatePlayerBetsListbox()
	{
		player_bets_listbox->Items->Clear();

		for (unsigned int i = 0; i < core->GetPlayer()->GetBets()->size(); i++)
			player_bets_listbox->Items->Add("#" + i + " Bet");
	}
}
