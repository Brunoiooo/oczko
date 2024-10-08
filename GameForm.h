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
	private: System::Windows::Forms::Label^ MoneyLabel;
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

		//Components container
	private:
		System::ComponentModel::Container^ components;


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			HandsListBox = (gcnew System::Windows::Forms::ListBox());
			BetTextBox = (gcnew System::Windows::Forms::TextBox());
			NewBetButton = (gcnew System::Windows::Forms::Button());
			CoupierHandListBox = (gcnew System::Windows::Forms::ListBox());
			PlayerHandListBox = (gcnew System::Windows::Forms::ListBox());
			HitButton = (gcnew System::Windows::Forms::Button());
			StandButton = (gcnew System::Windows::Forms::Button());
			DoubleButton = (gcnew System::Windows::Forms::Button());
			SplitButton = (gcnew System::Windows::Forms::Button());
			BetLabel = (gcnew System::Windows::Forms::Label());
			MultiplierLabel = (gcnew System::Windows::Forms::Label());
			CardCountLabel = (gcnew System::Windows::Forms::Label());
			SplitBoxListBox = (gcnew System::Windows::Forms::ListBox());
			MoneyLabel = (gcnew System::Windows::Forms::Label());
			SuspendLayout();
			// 
			// HandsListBox
			// 
			HandsListBox->FormattingEnabled = true;
			HandsListBox->ItemHeight = 16;
			HandsListBox->Location = System::Drawing::Point(12, 12);
			HandsListBox->Name = L"HandsListBox";
			HandsListBox->Size = System::Drawing::Size(144, 164);
			HandsListBox->TabIndex = 0;
			HandsListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &GameForm::HandsListBox_SelectedIndexChanged);
			// 
			// BetTextBox
			// 
			BetTextBox->Location = System::Drawing::Point(12, 182);
			BetTextBox->Name = L"BetTextBox";
			BetTextBox->Size = System::Drawing::Size(100, 22);
			BetTextBox->TabIndex = 1;
			BetTextBox->Text = L"100";
			// 
			// NewBetButton
			// 
			NewBetButton->Location = System::Drawing::Point(12, 210);
			NewBetButton->Name = L"NewBetButton";
			NewBetButton->Size = System::Drawing::Size(75, 23);
			NewBetButton->TabIndex = 2;
			NewBetButton->Text = L"New Bet";
			NewBetButton->UseVisualStyleBackColor = true;
			NewBetButton->Click += gcnew System::EventHandler(this, &GameForm::NewBetButton_Click);
			// 
			// CoupierHandListBox
			// 
			CoupierHandListBox->FormattingEnabled = true;
			CoupierHandListBox->ItemHeight = 16;
			CoupierHandListBox->Location = System::Drawing::Point(1617, 12);
			CoupierHandListBox->Name = L"CoupierHandListBox";
			CoupierHandListBox->Size = System::Drawing::Size(158, 180);
			CoupierHandListBox->TabIndex = 3;
			// 
			// PlayerHandListBox
			// 
			PlayerHandListBox->FormattingEnabled = true;
			PlayerHandListBox->ItemHeight = 16;
			PlayerHandListBox->Location = System::Drawing::Point(1453, 12);
			PlayerHandListBox->Name = L"PlayerHandListBox";
			PlayerHandListBox->Size = System::Drawing::Size(158, 180);
			PlayerHandListBox->TabIndex = 4;
			// 
			// HitButton
			// 
			HitButton->Location = System::Drawing::Point(710, 538);
			HitButton->Name = L"HitButton";
			HitButton->Size = System::Drawing::Size(75, 23);
			HitButton->TabIndex = 5;
			HitButton->Text = L"Hit";
			HitButton->UseVisualStyleBackColor = true;
			// 
			// StandButton
			// 
			StandButton->Location = System::Drawing::Point(791, 538);
			StandButton->Name = L"StandButton";
			StandButton->Size = System::Drawing::Size(75, 23);
			StandButton->TabIndex = 6;
			StandButton->Text = L"Stand";
			StandButton->UseVisualStyleBackColor = true;
			// 
			// DoubleButton
			// 
			DoubleButton->Location = System::Drawing::Point(872, 538);
			DoubleButton->Name = L"DoubleButton";
			DoubleButton->Size = System::Drawing::Size(75, 23);
			DoubleButton->TabIndex = 7;
			DoubleButton->Text = L"Double";
			DoubleButton->UseVisualStyleBackColor = true;
			// 
			// SplitButton
			// 
			SplitButton->Location = System::Drawing::Point(953, 538);
			SplitButton->Name = L"SplitButton";
			SplitButton->Size = System::Drawing::Size(75, 23);
			SplitButton->TabIndex = 8;
			SplitButton->Text = L"Split";
			SplitButton->UseVisualStyleBackColor = true;
			// 
			// BetLabel
			// 
			BetLabel->AutoSize = true;
			BetLabel->Location = System::Drawing::Point(549, 45);
			BetLabel->Name = L"BetLabel";
			BetLabel->Size = System::Drawing::Size(27, 16);
			BetLabel->TabIndex = 9;
			BetLabel->Text = L"Bet";
			// 
			// MultiplierLabel
			// 
			MultiplierLabel->AutoSize = true;
			MultiplierLabel->Location = System::Drawing::Point(589, 45);
			MultiplierLabel->Name = L"MultiplierLabel";
			MultiplierLabel->Size = System::Drawing::Size(60, 16);
			MultiplierLabel->TabIndex = 10;
			MultiplierLabel->Text = L"Multiplier";
			MultiplierLabel->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// CardCountLabel
			// 
			CardCountLabel->AutoSize = true;
			CardCountLabel->Location = System::Drawing::Point(1359, 12);
			CardCountLabel->Name = L"CardCountLabel";
			CardCountLabel->Size = System::Drawing::Size(73, 16);
			CardCountLabel->TabIndex = 11;
			CardCountLabel->Text = L"Card Count";
			// 
			// SplitBoxListBox
			// 
			SplitBoxListBox->FormattingEnabled = true;
			SplitBoxListBox->ItemHeight = 16;
			SplitBoxListBox->Location = System::Drawing::Point(1034, 538);
			SplitBoxListBox->Name = L"SplitBoxListBox";
			SplitBoxListBox->Size = System::Drawing::Size(158, 180);
			SplitBoxListBox->TabIndex = 12;
			// 
			// MoneyLabel
			// 
			MoneyLabel->AutoSize = true;
			MoneyLabel->Location = System::Drawing::Point(162, 9);
			MoneyLabel->Name = L"MoneyLabel";
			MoneyLabel->Size = System::Drawing::Size(48, 16);
			MoneyLabel->TabIndex = 13;
			MoneyLabel->Text = L"Money";
			// 
			// GameForm
			// 
			AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			ClientSize = System::Drawing::Size(1787, 777);
			Controls->Add(MoneyLabel);
			Controls->Add(SplitBoxListBox);
			Controls->Add(CardCountLabel);
			Controls->Add(MultiplierLabel);
			Controls->Add(BetLabel);
			Controls->Add(SplitButton);
			Controls->Add(DoubleButton);
			Controls->Add(StandButton);
			Controls->Add(HitButton);
			Controls->Add(PlayerHandListBox);
			Controls->Add(CoupierHandListBox);
			Controls->Add(NewBetButton);
			Controls->Add(BetTextBox);
			Controls->Add(HandsListBox);
			Name = L"GameForm";
			Text = L"GameForm";
			ResumeLayout(false);
			PerformLayout();

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
