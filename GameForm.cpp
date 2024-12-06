#include "GameForm.h"

namespace oczko {
	void GameForm::UpdateEverything(bool isRefesh)
	{
		UpdatePlayerHandsListbox(isRefesh);
		UpdatePlayerBetsListbox();
		UpdateStartBetButton();
		UpdateStartBetLabel();
		UpdateStartBetTextbox();
		UpdatePlayerWalletLabel();
		UpdatePlayerHandListview();
		UpdateCroupierHandListview();
		UpdateHitButton();
		UpdateStandButton();
		UpdateDoubleButton();
		UpdateSplitButton();
		UpdateBaseBetLabel();
		UpdatePlayerHandScore();
		UpdateCroupierHandScore();
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
	void GameForm::UpdatePlayerHandListview()
	{
		player_hand_listview->Items->Clear();
		
		if (player_hands_listbox->SelectedIndex >= 0)
			for (Card::Card* card : *core->GetBets()->at(player_hands_listbox->SelectedIndex)->GetHand()->GetCards())
				player_hand_listview->Items->Add(card->GetColor().ToString() + card->GetValue().ToString());
		else if (player_bets_listbox->SelectedIndex >= 0)
			for (Card::Card* card : *core->GetPlayer()->GetBets()->at(player_bets_listbox->SelectedIndex)->GetHand()->GetCards())
				player_hand_listview->Items->Add(card->GetColor().ToString() + card->GetValue().ToString());
	}
	void GameForm::UpdateCroupierHandListview()
	{
		croupier_hand_listview->Items->Clear();

		if (player_hands_listbox->SelectedIndex >= 0) {
			Card::Card* card = core->GetCroupier()->GetCroupierHand()->GetCards()->at(0);
			croupier_hand_listview->Items->Add(card->GetColor().ToString() + card->GetValue().ToString());
		}
		else if (player_bets_listbox->SelectedIndex >= 0)
			for (Card::Card* card : *core->GetPlayer()->GetBets()->at(player_bets_listbox->SelectedIndex)->GetCroupierHand()->GetCards())
				croupier_hand_listview->Items->Add(card->GetColor().ToString() + card->GetValue().ToString());
	}
	void GameForm::UpdatePlayerHandsListbox(bool isRefesh)
	{
		if (!isRefesh)
			return;

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
	void GameForm::UpdateHitButton()
	{
		if (player_hands_listbox->SelectedIndex >= 0 && core->GetBets()->at(player_hands_listbox->SelectedIndex)->CanHit())
			hit_button->Show();
		else
			hit_button->Hide();
	}
	void GameForm::UpdateStandButton()
	{
		if (player_hands_listbox->SelectedIndex >= 0 && core->GetBets()->at(player_hands_listbox->SelectedIndex)->CanStand())
			stand_button->Show();
		else
			stand_button->Hide();
	}
	void GameForm::UpdateDoubleButton()
	{
		if (player_hands_listbox->SelectedIndex >= 0 && core->GetBets()->at(player_hands_listbox->SelectedIndex)->CanDouble(core->GetPlayer()))
			double_button->Show();
		else
			double_button->Hide();
	}
	void GameForm::UpdateSplitButton()
	{
		if (player_hands_listbox->SelectedIndex >= 0 && core->GetBets()->at(player_hands_listbox->SelectedIndex)->CanSplit(core->GetPlayer()))
			split_button->Show();
		else
			split_button->Hide();
	}
	void GameForm::UpdateBaseBetLabel()
	{
		base_bet_label->Text = "";
		
		if (player_bets_listbox->SelectedIndex >= 0)
			base_bet_label->Text = "Base bet: " + (core->GetPlayer()->GetBets()->at(player_bets_listbox->SelectedIndex)->GetBaseBet()).ToString();
		else if (player_hands_listbox->SelectedIndex >= 0)
			base_bet_label->Text = "Base bet: " + (core->GetBets()->at(player_hands_listbox->SelectedIndex)->GetBaseBet()).ToString();
	}
	void GameForm::UpdatePlayerHandScore()
	{
		player_hand_score_label->Text = "";
		if (player_bets_listbox->SelectedIndex >= 0)
			player_hand_score_label->Text = "Score: " + (core->GetPlayer()->GetBets()->at(player_bets_listbox->SelectedIndex)->GetHand()->GetScore()).ToString();
		else if (player_hands_listbox->SelectedIndex >= 0)
			player_hand_score_label->Text = "Score: " + (core->GetBets()->at(player_hands_listbox->SelectedIndex)->GetHand()->GetScore()).ToString();
	}
	void GameForm::UpdateCroupierHandScore()
	{
		croupier_hand_score_label->Text = "";

		if (player_bets_listbox->SelectedIndex >= 0)
			croupier_hand_score_label->Text = "Score: " + (core->GetPlayer()->GetBets()->at(player_bets_listbox->SelectedIndex)->GetCroupierHand()->GetScore()).ToString();
		else if (player_hands_listbox->SelectedIndex >= 0)
			croupier_hand_score_label->Text = "Score: " + (core->GetBets()->at(player_hands_listbox->SelectedIndex)->GetCroupierHand()->GetCards()->at(0)->GetValue()).ToString();
	}
	System::Void GameForm::start_bet_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try {
			float money = float::Parse(start_bet_textbox->Text);

			if (money <= 0)
				throw gcnew Exception("Value of bet have to be bigger than 0.");
			if (!core->CanNewBet(money))
				throw gcnew Exception("Player doesn't have enough money to place the bet.");

			core->NewBet(money);

			UpdateEverything(true);
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
		}
	}
	System::Void GameForm::player_bets_listbox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		try {
			player_hands_listbox->SelectedIndex = -1;

			UpdatePlayerHandListview();
			UpdateCroupierHandListview();
			UpdateHitButton();
			UpdateStandButton();
			UpdateDoubleButton();
			UpdateSplitButton();

			UpdateBaseBetLabel();

			UpdatePlayerHandScore();
			UpdateCroupierHandScore();
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
		}
	}
	System::Void GameForm::player_hands_listbox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		try {
			player_bets_listbox->SelectedIndex = -1;

			UpdatePlayerHandListview();
			UpdateCroupierHandListview();
			UpdateHitButton();
			UpdateStandButton();
			UpdateDoubleButton();
			UpdateSplitButton();

			UpdateBaseBetLabel();

			UpdatePlayerHandScore();
			UpdateCroupierHandScore();
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
		}
	}
	System::Void GameForm::player_hand_listview_DrawItem(System::Object^ sender, System::Windows::Forms::DrawListViewItemEventArgs^ e)
	{
		try {
			if (e->ItemIndex < 0)
				return;

			e->DrawBackground();

			String^ imagePath = Path::Combine("cards/", e->Item->Text + ".png");
			Image^ image = Image::FromFile(imagePath);
			e->Graphics->DrawImage(image, e->Bounds.X, e->Bounds.Y, 100, 100);
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
		}
	}
	System::Void GameForm::hit_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try {
			core->Hit(core->GetBets()->at(player_hands_listbox->SelectedIndex));

			UpdatePlayerBetsListbox();
			UpdatePlayerHandsListbox(core->GetBets()->size() > 0 ? false : true);

			UpdatePlayerHandListview();
			UpdateCroupierHandListview();

			UpdateHitButton();
			UpdateStandButton();
			UpdateDoubleButton();
			UpdateSplitButton();

			UpdateStartBetButton();
			UpdateStartBetLabel();
			UpdateStartBetTextbox();

			UpdateBaseBetLabel();

			UpdatePlayerHandScore();
			UpdateCroupierHandScore();
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
		}
	}
	System::Void GameForm::stand_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try {
			core->Stand(core->GetBets()->at(player_hands_listbox->SelectedIndex));

			UpdatePlayerBetsListbox();
			UpdatePlayerHandsListbox(true);

			UpdatePlayerHandListview();
			UpdateCroupierHandListview();

			UpdateHitButton();
			UpdateStandButton();
			UpdateDoubleButton();
			UpdateSplitButton();

			UpdateStartBetButton();
			UpdateStartBetLabel();
			UpdateStartBetTextbox();

			UpdateBaseBetLabel();

			UpdatePlayerHandScore();
			UpdateCroupierHandScore();
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
		}
	}
	System::Void GameForm::double_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try {
			core->Double(core->GetBets()->at(player_hands_listbox->SelectedIndex));

			UpdatePlayerBetsListbox();
			UpdatePlayerHandsListbox(true);

			UpdatePlayerHandListview();
			UpdateCroupierHandListview();

			UpdateHitButton();
			UpdateStandButton();
			UpdateDoubleButton();
			UpdateSplitButton();

			UpdateStartBetButton();
			UpdateStartBetLabel();
			UpdateStartBetTextbox();

			UpdateBaseBetLabel();

			UpdatePlayerHandScore();
			UpdateCroupierHandScore();
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
		}
	}
	System::Void GameForm::split_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try {
			core->Split(core->GetBets()->at(player_hands_listbox->SelectedIndex));

			UpdatePlayerBetsListbox();
			UpdatePlayerHandsListbox(true);

			UpdatePlayerHandListview();
			UpdateCroupierHandListview();

			UpdateHitButton();
			UpdateStandButton();
			UpdateDoubleButton();
			UpdateSplitButton();

			UpdateStartBetButton();
			UpdateStartBetLabel();
			UpdateStartBetTextbox();

			UpdateBaseBetLabel();

			UpdatePlayerHandScore();
			UpdateCroupierHandScore();
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
		}
	}
	System::Void GameForm::croupier_hand_listview_DrawItem(System::Object^ sender, System::Windows::Forms::DrawListViewItemEventArgs^ e)
	{
		try {
			if (e->ItemIndex < 0)
				return;

			e->DrawBackground();

			String^ imagePath = Path::Combine("cards/", e->Item->Text + ".png");
			Image^ image = Image::FromFile(imagePath);
			e->Graphics->DrawImage(image, e->Bounds.X, e->Bounds.Y, 100, 100);
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
		}
	}
	System::Void GameForm::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Application::Exit();
	}
	System::Void GameForm::aboutMeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		AboutMeForm^ aboutMeForm = gcnew AboutMeForm();

		aboutMeForm->ShowDialog();
	}
}
