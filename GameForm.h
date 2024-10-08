#pragma once

#include "Deck.h"
#include "Player.h"
#include "Croupier.h"

namespace oczko {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	public ref class GameForm : public System::Windows::Forms::Form
	{
		//Models
	private:
		float Money;
		Deck::Deck^ Deck;
		List<Player::Player^>^ Players;
		int ActiveHand;
		Croupier::Croupier^ Croupier;

		//Getters and Setters
	private:
		float GetMoney();
		void SetMoney(float money);

		Deck::Deck^ GetDeck();
		void SetDeck(Deck::Deck^ deck);
		Card::Card^ Draw();

		List<Player::Player^>^ GetPlayers();
		void AddPlayer(Player::Player^ player);
		void ClearPlayer();

		Croupier::Croupier^ GetCroupier();
		void SetCroupier(Croupier::Croupier^ croupier);

		int GetActiveHand();
		void SetActiveHand(int activeHand);

		//Methods
	private:
		void StartNewGame();

		//Updaters
	private:
		void UpdateHandsListBox();
		void UpdateBetButtor();
		void UpdateNewBetTextBox();
		void UpdateMoneyLabel();
		void UpdateBetLabel();
		void UpdateMultiplierLabel();
		void UpdateCardCountLabel();
		void UpdatePlayerHandListBox();

		//Constructor
	public:
		GameForm(float money)
		{
			InitializeComponent();

			WindowState = System::Windows::Forms::FormWindowState::Maximized;

			if (money <= 0) throw gcnew System::Exception("Start money has to be bigger than 0.");

			Money = money;
			Players = gcnew List<Player::Player^>();

			ActiveHand = -1;
			MoneyLabel->Text = money.ToString();
			MultiplierLabel->Hide();
			BetLabel->Hide();
			CardCountLabel->Hide();
			PlayerHandListBox->Hide();
			CoupierHandListBox->Hide();
			HitButton->Hide();
			StandButton->Hide();
			DoubleButton->Hide();
			SplitButton->Hide();
			SplitBoxListBox->Hide();
		}

		//Destructor
	protected:
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}

		//Components
	private:
		System::Windows::Forms::ListBox^ HandsListBox;
		System::Windows::Forms::TextBox^ BetTextBox;
		System::Windows::Forms::Button^ NewBetButton;
		System::Windows::Forms::ListBox^ CoupierHandListBox;
		System::Windows::Forms::ListBox^ PlayerHandListBox;
		System::Windows::Forms::Button^ HitButton;
		System::Windows::Forms::Button^ StandButton;
		System::Windows::Forms::Button^ DoubleButton;
		System::Windows::Forms::Button^ SplitButton;
		System::Windows::Forms::Label^ BetLabel;
		System::Windows::Forms::Label^ MultiplierLabel;
		System::Windows::Forms::Label^ CardCountLabel;
		System::Windows::Forms::ListBox^ SplitBoxListBox;
		System::Windows::Forms::Label^ MoneyLabel;

		//Components container
	private:
		System::ComponentModel::Container^ components;


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->HandsListBox = (gcnew System::Windows::Forms::ListBox());
			this->BetTextBox = (gcnew System::Windows::Forms::TextBox());
			this->NewBetButton = (gcnew System::Windows::Forms::Button());
			this->CoupierHandListBox = (gcnew System::Windows::Forms::ListBox());
			this->PlayerHandListBox = (gcnew System::Windows::Forms::ListBox());
			this->HitButton = (gcnew System::Windows::Forms::Button());
			this->StandButton = (gcnew System::Windows::Forms::Button());
			this->DoubleButton = (gcnew System::Windows::Forms::Button());
			this->SplitButton = (gcnew System::Windows::Forms::Button());
			this->BetLabel = (gcnew System::Windows::Forms::Label());
			this->MultiplierLabel = (gcnew System::Windows::Forms::Label());
			this->CardCountLabel = (gcnew System::Windows::Forms::Label());
			this->SplitBoxListBox = (gcnew System::Windows::Forms::ListBox());
			this->MoneyLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// HandsListBox
			// 
			this->HandsListBox->FormattingEnabled = true;
			this->HandsListBox->ItemHeight = 16;
			this->HandsListBox->Location = System::Drawing::Point(12, 12);
			this->HandsListBox->Name = L"HandsListBox";
			this->HandsListBox->Size = System::Drawing::Size(144, 164);
			this->HandsListBox->TabIndex = 0;
			this->HandsListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &GameForm::HandsListBox_SelectedIndexChanged);
			// 
			// BetTextBox
			// 
			this->BetTextBox->Location = System::Drawing::Point(12, 182);
			this->BetTextBox->Name = L"BetTextBox";
			this->BetTextBox->Size = System::Drawing::Size(100, 22);
			this->BetTextBox->TabIndex = 1;
			this->BetTextBox->Text = L"100";
			// 
			// NewBetButton
			// 
			this->NewBetButton->Location = System::Drawing::Point(12, 210);
			this->NewBetButton->Name = L"NewBetButton";
			this->NewBetButton->Size = System::Drawing::Size(75, 23);
			this->NewBetButton->TabIndex = 2;
			this->NewBetButton->Text = L"New Bet";
			this->NewBetButton->UseVisualStyleBackColor = true;
			this->NewBetButton->Click += gcnew System::EventHandler(this, &GameForm::NewBetButton_Click);
			// 
			// CoupierHandListBox
			// 
			this->CoupierHandListBox->FormattingEnabled = true;
			this->CoupierHandListBox->ItemHeight = 16;
			this->CoupierHandListBox->Location = System::Drawing::Point(1617, 12);
			this->CoupierHandListBox->Name = L"CoupierHandListBox";
			this->CoupierHandListBox->Size = System::Drawing::Size(158, 180);
			this->CoupierHandListBox->TabIndex = 3;
			// 
			// PlayerHandListBox
			// 
			this->PlayerHandListBox->FormattingEnabled = true;
			this->PlayerHandListBox->ItemHeight = 16;
			this->PlayerHandListBox->Location = System::Drawing::Point(1453, 12);
			this->PlayerHandListBox->Name = L"PlayerHandListBox";
			this->PlayerHandListBox->Size = System::Drawing::Size(158, 180);
			this->PlayerHandListBox->TabIndex = 4;
			// 
			// HitButton
			// 
			this->HitButton->Location = System::Drawing::Point(710, 538);
			this->HitButton->Name = L"HitButton";
			this->HitButton->Size = System::Drawing::Size(75, 23);
			this->HitButton->TabIndex = 5;
			this->HitButton->Text = L"Hit";
			this->HitButton->UseVisualStyleBackColor = true;
			// 
			// StandButton
			// 
			this->StandButton->Location = System::Drawing::Point(791, 538);
			this->StandButton->Name = L"StandButton";
			this->StandButton->Size = System::Drawing::Size(75, 23);
			this->StandButton->TabIndex = 6;
			this->StandButton->Text = L"Stand";
			this->StandButton->UseVisualStyleBackColor = true;
			// 
			// DoubleButton
			// 
			this->DoubleButton->Location = System::Drawing::Point(872, 538);
			this->DoubleButton->Name = L"DoubleButton";
			this->DoubleButton->Size = System::Drawing::Size(75, 23);
			this->DoubleButton->TabIndex = 7;
			this->DoubleButton->Text = L"Double";
			this->DoubleButton->UseVisualStyleBackColor = true;
			// 
			// SplitButton
			// 
			this->SplitButton->Location = System::Drawing::Point(953, 538);
			this->SplitButton->Name = L"SplitButton";
			this->SplitButton->Size = System::Drawing::Size(75, 23);
			this->SplitButton->TabIndex = 8;
			this->SplitButton->Text = L"Split";
			this->SplitButton->UseVisualStyleBackColor = true;
			// 
			// BetLabel
			// 
			this->BetLabel->AutoSize = true;
			this->BetLabel->Location = System::Drawing::Point(549, 45);
			this->BetLabel->Name = L"BetLabel";
			this->BetLabel->Size = System::Drawing::Size(27, 16);
			this->BetLabel->TabIndex = 9;
			this->BetLabel->Text = L"Bet";
			// 
			// MultiplierLabel
			// 
			this->MultiplierLabel->AutoSize = true;
			this->MultiplierLabel->Location = System::Drawing::Point(589, 45);
			this->MultiplierLabel->Name = L"MultiplierLabel";
			this->MultiplierLabel->Size = System::Drawing::Size(60, 16);
			this->MultiplierLabel->TabIndex = 10;
			this->MultiplierLabel->Text = L"Multiplier";
			this->MultiplierLabel->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// CardCountLabel
			// 
			this->CardCountLabel->AutoSize = true;
			this->CardCountLabel->Location = System::Drawing::Point(1359, 12);
			this->CardCountLabel->Name = L"CardCountLabel";
			this->CardCountLabel->Size = System::Drawing::Size(73, 16);
			this->CardCountLabel->TabIndex = 11;
			this->CardCountLabel->Text = L"Card Count";
			// 
			// SplitBoxListBox
			// 
			this->SplitBoxListBox->FormattingEnabled = true;
			this->SplitBoxListBox->ItemHeight = 16;
			this->SplitBoxListBox->Location = System::Drawing::Point(1034, 538);
			this->SplitBoxListBox->Name = L"SplitBoxListBox";
			this->SplitBoxListBox->Size = System::Drawing::Size(158, 180);
			this->SplitBoxListBox->TabIndex = 12;
			// 
			// MoneyLabel
			// 
			this->MoneyLabel->AutoSize = true;
			this->MoneyLabel->Location = System::Drawing::Point(162, 9);
			this->MoneyLabel->Name = L"MoneyLabel";
			this->MoneyLabel->Size = System::Drawing::Size(48, 16);
			this->MoneyLabel->TabIndex = 13;
			this->MoneyLabel->Text = L"Money";
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1787, 777);
			this->Controls->Add(MoneyLabel);
			this->Controls->Add(SplitBoxListBox);
			this->Controls->Add(CardCountLabel);
			this->Controls->Add(MultiplierLabel);
			this->Controls->Add(BetLabel);
			this->Controls->Add(SplitButton);
			this->Controls->Add(DoubleButton);
			this->Controls->Add(StandButton);
			this->Controls->Add(HitButton);
			this->Controls->Add(PlayerHandListBox);
			this->Controls->Add(CoupierHandListBox);
			this->Controls->Add(NewBetButton);
			this->Controls->Add(BetTextBox);
			this->Controls->Add(HandsListBox);
			this->Name = L"GameForm";
			this->Text = L"GameForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void NewBetButton_Click(System::Object^ sender, System::EventArgs^ e) {
		StartNewGame();
	}
	private: System::Void HandsListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		SetActiveHand(PlayerHandListBox->SelectedIndex);
	}
};
}
