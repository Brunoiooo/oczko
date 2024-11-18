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
		void UpdateComponents();
		void UpdateStartBetButton();
		void UpdateStartBetLabel();
		void UpdateStartBetTextbox();
		void UpdatePlayerWalletLabel();
		void UpdatePlayerHandListbox();
		void UpdatePlayerHandsListbox();
		void UpdatePlayerBetsListbox();

	public:
		GameForm(float money)
		{
			core = new Core::Core(money);

			InitializeComponent();

			UpdateComponents();

			WindowState = System::Windows::Forms::FormWindowState::Maximized;
		}

	protected:
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ start_bet_button;
	private: System::Windows::Forms::TextBox^ start_bet_textbox;
	private: System::Windows::Forms::Label^ start_bet_label;
	private: System::Windows::Forms::Label^ player_wallet_label;
	private: System::Windows::Forms::ListBox^ player_bets_listbox;
	private: System::Windows::Forms::ListBox^ player_hands_listbox;
	private: System::Windows::Forms::ImageList^ cards_imagelist;
	private: System::Windows::Forms::ListView^ player_hand_listview;
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
			this->player_bets_listbox->Location = System::Drawing::Point(12, 28);
			this->player_bets_listbox->Name = L"player_bets_listbox";
			this->player_bets_listbox->Size = System::Drawing::Size(120, 84);
			this->player_bets_listbox->TabIndex = 5;
			this->player_bets_listbox->SelectedIndexChanged += gcnew System::EventHandler(this, &GameForm::player_bets_listbox_SelectedIndexChanged);
			// 
			// player_hands_listbox
			// 
			this->player_hands_listbox->FormattingEnabled = true;
			this->player_hands_listbox->ItemHeight = 16;
			this->player_hands_listbox->Location = System::Drawing::Point(1529, 12);
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
			this->player_hand_listview->Location = System::Drawing::Point(342, 12);
			this->player_hand_listview->Name = L"player_hand_listview";
			this->player_hand_listview->OwnerDraw = true;
			this->player_hand_listview->Size = System::Drawing::Size(1003, 420);
			this->player_hand_listview->TabIndex = 7;
			this->player_hand_listview->UseCompatibleStateImageBehavior = false;
			this->player_hand_listview->DrawItem += gcnew System::Windows::Forms::DrawListViewItemEventHandler(this, &GameForm::player_hand_listview_DrawItem);
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1787, 777);
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

			UpdateComponents();
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
		}
	}
	private: System::Void player_bets_listbox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		try {
			player_hands_listbox->SelectedIndex = -1;

			UpdatePlayerHandListbox();
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
		}
	}
	private: System::Void player_hands_listbox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		try {
			player_bets_listbox->SelectedIndex = -1;

			UpdatePlayerHandListbox();
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
		}
	}
	private: System::Void player_hand_listview_DrawItem(System::Object^ sender, System::Windows::Forms::DrawListViewItemEventArgs^ e) {
		try {
			Console::WriteLine(e->ItemIndex);

			if (e->ItemIndex < 0)
				return;

			Card::Card* card;
			if (player_hands_listbox->SelectedIndex >= 0)
				card = core->GetBets()->at(player_hands_listbox->SelectedIndex)->GetHand()->GetCards()->at(e->ItemIndex);
			else if (player_bets_listbox->SelectedIndex >= 0)
				card = core->GetPlayer()->GetBets()->at(player_bets_listbox->SelectedIndex)->GetHand()->GetCards()->at(e->ItemIndex);
			else
				return;

			e->DrawBackground();

			String^ imagePath = Path::Combine("cards/", card->GetColor().ToString() + card->GetValue().ToString() + ".png");
			Image^ image = Image::FromFile(imagePath);
			e->Graphics->DrawImage(image, e->Bounds.X, e->Bounds.Y, 100, 100);
		}
		catch (Exception^ e) {
			MessageBox::Show(e->Message);
		}
	}
};
}
