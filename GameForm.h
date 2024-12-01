#pragma once

#include "Core.hpp"
#include "Bet.hpp"
#include "Card.hpp"

namespace oczko {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace std;
	using namespace System::IO;

	public ref class GameForm : public System::Windows::Forms::Form
	{
	private:
		Core::Core* core;
		void UpdateEverything(bool isRefesh);
		void UpdateStartBetButton();
		void UpdateStartBetLabel();
		void UpdateStartBetTextbox();
		void UpdatePlayerWalletLabel();
		void UpdatePlayerHandListview();
		void UpdateCroupierHandListview();
		void UpdatePlayerHandsListbox(bool isRefesh);
		void UpdatePlayerBetsListbox();
		void UpdateHitButton();
		void UpdateStandButton();
		void UpdateDoubleButton();
		void UpdateSplitButton();
		void UpdateBaseBetLabel();
		void UpdatePlayerHandScore();
		void UpdateCroupierHandScore();

	public:
		GameForm(float money)
		{
			core = new Core::Core(money);

			InitializeComponent();

			UpdateEverything(true);

			WindowState = System::Windows::Forms::FormWindowState::Maximized;
		}

	protected:
		~GameForm()
		{
			if (components)
				delete components;
			
			if (core)
				delete core;
		}

	private: System::Windows::Forms::Button^ start_bet_button;
	private: System::Windows::Forms::TextBox^ start_bet_textbox;
	private: System::Windows::Forms::Label^ start_bet_label;
	private: System::Windows::Forms::Label^ player_wallet_label;
	private: System::Windows::Forms::ListBox^ player_bets_listbox;
	private: System::Windows::Forms::ListBox^ player_hands_listbox;
	private: System::Windows::Forms::ImageList^ cards_imagelist;
	private: System::Windows::Forms::ListView^ player_hand_listview;
	private: System::Windows::Forms::Button^ hit_button;
	private: System::Windows::Forms::Button^ stand_button;
	private: System::Windows::Forms::Button^ double_button;
	private: System::Windows::Forms::Button^ split_button;
	private: System::Windows::Forms::ListView^ croupier_hand_listview;
	private: System::Windows::Forms::Label^ player_hand_label;
	private: System::Windows::Forms::Label^ croupier_hand_label;
	private: System::Windows::Forms::Label^ player_hands_label;
	private: System::Windows::Forms::Label^ player_bets_label;
	private: System::Windows::Forms::Label^ base_bet_label;
	private: System::Windows::Forms::Label^ croupier_hand_score_label;
	private: System::Windows::Forms::Label^ player_hand_score_label;


	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GameForm::typeid));
			this->start_bet_button = (gcnew System::Windows::Forms::Button());
			this->start_bet_textbox = (gcnew System::Windows::Forms::TextBox());
			this->start_bet_label = (gcnew System::Windows::Forms::Label());
			this->player_wallet_label = (gcnew System::Windows::Forms::Label());
			this->player_bets_listbox = (gcnew System::Windows::Forms::ListBox());
			this->player_hands_listbox = (gcnew System::Windows::Forms::ListBox());
			this->cards_imagelist = (gcnew System::Windows::Forms::ImageList(this->components));
			this->player_hand_listview = (gcnew System::Windows::Forms::ListView());
			this->hit_button = (gcnew System::Windows::Forms::Button());
			this->stand_button = (gcnew System::Windows::Forms::Button());
			this->double_button = (gcnew System::Windows::Forms::Button());
			this->split_button = (gcnew System::Windows::Forms::Button());
			this->croupier_hand_listview = (gcnew System::Windows::Forms::ListView());
			this->player_hand_label = (gcnew System::Windows::Forms::Label());
			this->croupier_hand_label = (gcnew System::Windows::Forms::Label());
			this->player_hands_label = (gcnew System::Windows::Forms::Label());
			this->player_bets_label = (gcnew System::Windows::Forms::Label());
			this->base_bet_label = (gcnew System::Windows::Forms::Label());
			this->croupier_hand_score_label = (gcnew System::Windows::Forms::Label());
			this->player_hand_score_label = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// start_bet_button
			// 
			this->start_bet_button->Location = System::Drawing::Point(12, 625);
			this->start_bet_button->Name = L"start_bet_button";
			this->start_bet_button->Size = System::Drawing::Size(410, 140);
			this->start_bet_button->TabIndex = 0;
			this->start_bet_button->Text = L"Start next bet";
			this->start_bet_button->UseVisualStyleBackColor = true;
			this->start_bet_button->Click += gcnew System::EventHandler(this, &GameForm::start_bet_button_Click);
			// 
			// start_bet_textbox
			// 
			this->start_bet_textbox->Location = System::Drawing::Point(12, 597);
			this->start_bet_textbox->Name = L"start_bet_textbox";
			this->start_bet_textbox->Size = System::Drawing::Size(410, 22);
			this->start_bet_textbox->TabIndex = 1;
			// 
			// start_bet_label
			// 
			this->start_bet_label->AutoSize = true;
			this->start_bet_label->Location = System::Drawing::Point(9, 578);
			this->start_bet_label->Name = L"start_bet_label";
			this->start_bet_label->Size = System::Drawing::Size(105, 16);
			this->start_bet_label->TabIndex = 2;
			this->start_bet_label->Text = L"Value of next bet";
			// 
			// player_wallet_label
			// 
			this->player_wallet_label->AutoSize = true;
			this->player_wallet_label->Location = System::Drawing::Point(12, 9);
			this->player_wallet_label->Name = L"player_wallet_label";
			this->player_wallet_label->Size = System::Drawing::Size(0, 16);
			this->player_wallet_label->TabIndex = 3;
			// 
			// player_bets_listbox
			// 
			this->player_bets_listbox->FormattingEnabled = true;
			this->player_bets_listbox->ItemHeight = 16;
			this->player_bets_listbox->Location = System::Drawing::Point(12, 40);
			this->player_bets_listbox->Name = L"player_bets_listbox";
			this->player_bets_listbox->Size = System::Drawing::Size(120, 84);
			this->player_bets_listbox->TabIndex = 5;
			this->player_bets_listbox->SelectedIndexChanged += gcnew System::EventHandler(this, &GameForm::player_bets_listbox_SelectedIndexChanged);
			// 
			// player_hands_listbox
			// 
			this->player_hands_listbox->FormattingEnabled = true;
			this->player_hands_listbox->ItemHeight = 16;
			this->player_hands_listbox->Location = System::Drawing::Point(1488, 40);
			this->player_hands_listbox->Name = L"player_hands_listbox";
			this->player_hands_listbox->Size = System::Drawing::Size(120, 84);
			this->player_hands_listbox->TabIndex = 6;
			this->player_hands_listbox->SelectedIndexChanged += gcnew System::EventHandler(this, &GameForm::player_hands_listbox_SelectedIndexChanged);
			// 
			// cards_imagelist
			// 
			this->cards_imagelist->ColorDepth = System::Windows::Forms::ColorDepth::Depth8Bit;
			this->cards_imagelist->ImageSize = System::Drawing::Size(16, 16);
			this->cards_imagelist->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// player_hand_listview
			// 
			this->player_hand_listview->HideSelection = false;
			this->player_hand_listview->Location = System::Drawing::Point(342, 40);
			this->player_hand_listview->Name = L"player_hand_listview";
			this->player_hand_listview->OwnerDraw = true;
			this->player_hand_listview->Size = System::Drawing::Size(567, 420);
			this->player_hand_listview->TabIndex = 7;
			this->player_hand_listview->UseCompatibleStateImageBehavior = false;
			this->player_hand_listview->DrawItem += gcnew System::Windows::Forms::DrawListViewItemEventHandler(this, &GameForm::player_hand_listview_DrawItem);
			// 
			// hit_button
			// 
			this->hit_button->Location = System::Drawing::Point(505, 484);
			this->hit_button->Name = L"hit_button";
			this->hit_button->Size = System::Drawing::Size(171, 67);
			this->hit_button->TabIndex = 8;
			this->hit_button->Text = L"Hit";
			this->hit_button->UseVisualStyleBackColor = true;
			this->hit_button->Click += gcnew System::EventHandler(this, &GameForm::hit_button_Click);
			// 
			// stand_button
			// 
			this->stand_button->Location = System::Drawing::Point(682, 484);
			this->stand_button->Name = L"stand_button";
			this->stand_button->Size = System::Drawing::Size(171, 67);
			this->stand_button->TabIndex = 9;
			this->stand_button->Text = L"Stand";
			this->stand_button->UseVisualStyleBackColor = true;
			this->stand_button->Click += gcnew System::EventHandler(this, &GameForm::stand_button_Click);
			// 
			// double_button
			// 
			this->double_button->Location = System::Drawing::Point(859, 484);
			this->double_button->Name = L"double_button";
			this->double_button->Size = System::Drawing::Size(171, 67);
			this->double_button->TabIndex = 10;
			this->double_button->Text = L"Double";
			this->double_button->UseVisualStyleBackColor = true;
			this->double_button->Click += gcnew System::EventHandler(this, &GameForm::double_button_Click);
			// 
			// split_button
			// 
			this->split_button->Location = System::Drawing::Point(1036, 484);
			this->split_button->Name = L"split_button";
			this->split_button->Size = System::Drawing::Size(171, 67);
			this->split_button->TabIndex = 11;
			this->split_button->Text = L"Split";
			this->split_button->UseVisualStyleBackColor = true;
			this->split_button->Click += gcnew System::EventHandler(this, &GameForm::split_button_Click);
			// 
			// croupier_hand_listview
			// 
			this->croupier_hand_listview->HideSelection = false;
			this->croupier_hand_listview->Location = System::Drawing::Point(915, 40);
			this->croupier_hand_listview->Name = L"croupier_hand_listview";
			this->croupier_hand_listview->OwnerDraw = true;
			this->croupier_hand_listview->Size = System::Drawing::Size(567, 420);
			this->croupier_hand_listview->TabIndex = 12;
			this->croupier_hand_listview->UseCompatibleStateImageBehavior = false;
			this->croupier_hand_listview->DrawItem += gcnew System::Windows::Forms::DrawListViewItemEventHandler(this, &GameForm::croupier_hand_listview_DrawItem);
			// 
			// player_hand_label
			// 
			this->player_hand_label->AutoSize = true;
			this->player_hand_label->Location = System::Drawing::Point(339, 21);
			this->player_hand_label->Name = L"player_hand_label";
			this->player_hand_label->Size = System::Drawing::Size(79, 16);
			this->player_hand_label->TabIndex = 13;
			this->player_hand_label->Text = L"Player hand";
			// 
			// croupier_hand_label
			// 
			this->croupier_hand_label->AutoSize = true;
			this->croupier_hand_label->Location = System::Drawing::Point(912, 21);
			this->croupier_hand_label->Name = L"croupier_hand_label";
			this->croupier_hand_label->Size = System::Drawing::Size(91, 16);
			this->croupier_hand_label->TabIndex = 14;
			this->croupier_hand_label->Text = L"Croupier hand";
			// 
			// player_hands_label
			// 
			this->player_hands_label->AutoSize = true;
			this->player_hands_label->Location = System::Drawing::Point(1485, 21);
			this->player_hands_label->Name = L"player_hands_label";
			this->player_hands_label->Size = System::Drawing::Size(81, 16);
			this->player_hands_label->TabIndex = 15;
			this->player_hands_label->Text = L"Actived bets";
			// 
			// player_bets_label
			// 
			this->player_bets_label->AutoSize = true;
			this->player_bets_label->Location = System::Drawing::Point(12, 21);
			this->player_bets_label->Name = L"player_bets_label";
			this->player_bets_label->Size = System::Drawing::Size(75, 16);
			this->player_bets_label->TabIndex = 16;
			this->player_bets_label->Text = L"Player bets";
			// 
			// base_bet_label
			// 
			this->base_bet_label->AutoSize = true;
			this->base_bet_label->Location = System::Drawing::Point(1485, 127);
			this->base_bet_label->Name = L"base_bet_label";
			this->base_bet_label->Size = System::Drawing::Size(0, 16);
			this->base_bet_label->TabIndex = 17;
			// 
			// croupier_hand_score_label
			// 
			this->croupier_hand_score_label->AutoSize = true;
			this->croupier_hand_score_label->Location = System::Drawing::Point(912, 463);
			this->croupier_hand_score_label->Name = L"croupier_hand_score_label";
			this->croupier_hand_score_label->Size = System::Drawing::Size(0, 20);
			this->croupier_hand_score_label->TabIndex = 18;
			// 
			// player_hand_score_label
			// 
			this->player_hand_score_label->AutoSize = true;
			this->player_hand_score_label->Location = System::Drawing::Point(339, 463);
			this->player_hand_score_label->Name = L"player_hand_score_label";
			this->player_hand_score_label->Size = System::Drawing::Size(0, 20);
			this->player_hand_score_label->TabIndex = 19;
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1787, 777);
			this->Controls->Add(this->player_hand_score_label);
			this->Controls->Add(this->croupier_hand_score_label);
			this->Controls->Add(this->base_bet_label);
			this->Controls->Add(this->player_bets_label);
			this->Controls->Add(this->player_hands_label);
			this->Controls->Add(this->croupier_hand_label);
			this->Controls->Add(this->player_hand_label);
			this->Controls->Add(this->croupier_hand_listview);
			this->Controls->Add(this->split_button);
			this->Controls->Add(this->double_button);
			this->Controls->Add(this->stand_button);
			this->Controls->Add(this->hit_button);
			this->Controls->Add(this->player_hand_listview);
			this->Controls->Add(this->player_hands_listbox);
			this->Controls->Add(this->player_bets_listbox);
			this->Controls->Add(this->player_wallet_label);
			this->Controls->Add(this->start_bet_label);
			this->Controls->Add(this->start_bet_textbox);
			this->Controls->Add(this->start_bet_button);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"GameForm";
			this->Text = L"GameForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void start_bet_button_Click(System::Object^ sender, System::EventArgs^ e) {
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
	private: System::Void player_bets_listbox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
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
			Console::WriteLine(e->Message);
			Console::WriteLine(e->StackTrace);
		}
	}
	private: System::Void player_hands_listbox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
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
			Console::WriteLine(e->Message);
			Console::WriteLine(e->StackTrace);
		}
	}
	private: System::Void player_hand_listview_DrawItem(System::Object^ sender, System::Windows::Forms::DrawListViewItemEventArgs^ e) {
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
private: System::Void hit_button_Click(System::Object^ sender, System::EventArgs^ e) {
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
private: System::Void stand_button_Click(System::Object^ sender, System::EventArgs^ e) {
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
		Console::WriteLine(e->Message);
		Console::WriteLine(e->StackTrace);
	}
}
private: System::Void double_button_Click(System::Object^ sender, System::EventArgs^ e) {
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
private: System::Void split_button_Click(System::Object^ sender, System::EventArgs^ e) {
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
private: System::Void croupier_hand_listview_DrawItem(System::Object^ sender, System::Windows::Forms::DrawListViewItemEventArgs^ e) {
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
};
}
