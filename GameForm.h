#pragma once

#include "Deck.h"
#include "Player.h"
#include "Croupier.h"
#include "Bet.h"

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
	private:
		Player::Player^ Player;
		Croupier::Croupier^ Croupier;
		List<Bet::Bet^>^ Bets;
		List<Bet::Bet^>^ OldBets;

	private:
		void Deposit(float money);
		void Withdrawal(float money);

		Card::Card^ DrawCard();
		Hand::Hand^ NewCroupierHand();
		Hand::Hand^ NewHand();
		void FillCroupierHand();

		void AddNewBet(Bet::Bet^ bet);
		void ClearBets();
		
		void AddOldBet(Bet::Bet^ bet);

	private:
		bool IsHit();
		bool IsStand();
		bool IsDouble();
		bool IsSplit();
		bool IsBet();

	private:
		void UpdatePlayerMoneyLabel();
		void UpdateNewBetButton();
		void UpdateBetTextBox();
		void UpdateOldBetsListBox();
		void UpdateOldBetListBox();
		void UpdateBetsListBox();
		void UpdateBetLabel();
		void UpdateMultiplierLabel();
		void UpdateCardCountLabel();
		void UpdatePlayerHandListBox();
		void UpdatePlayerScoreLabel();
		void UpdateCroupierHandListBox();
		void UpdateCroupierScoreLabel();
		void UpdateHitButton();
		void UpdateStandButton();
		void UpdateDoubleButton();
		void UpdateSplitButton();
		void UpdateGame();

	public:
		GameForm(float money)
		{
			InitializeComponent();

			WindowState = System::Windows::Forms::FormWindowState::Maximized;

			Player = gcnew Player::Player(money);
			Croupier = gcnew Croupier::Croupier();
			Bets = gcnew List<Bet::Bet^>();
			OldBets = gcnew List<Bet::Bet^>();

			PlayerMoneyLabel->Text = Player->GetMoney().ToString();
			MultiplierLabel->Hide();
			CardCountLabel->Hide();
			BetLabel->Hide();
			PlayerHandListBox->Hide();
			PlayerScoreLabel->Hide();
			CroupierHandListBox->Hide();
			CroupierScoreLabel->Hide();
			HitButton->Hide();
			StandButton->Hide();
			DoubleButton->Hide();
			SplitButton->Hide();
			OldBetListBox->Hide();
		}

	protected:
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}

		System::Windows::Forms::ListBox^ BetsListBox;
		System::Windows::Forms::TextBox^ BetTextBox;
		System::Windows::Forms::Button^ NewBetButton;
		System::Windows::Forms::ListBox^ CroupierHandListBox;
		System::Windows::Forms::ListBox^ PlayerHandListBox;
		System::Windows::Forms::Button^ HitButton;
		System::Windows::Forms::Button^ StandButton;
		System::Windows::Forms::Button^ DoubleButton;
		System::Windows::Forms::Button^ SplitButton;
		System::Windows::Forms::Label^ BetLabel;
		System::Windows::Forms::Label^ MultiplierLabel;
		System::Windows::Forms::Label^ CardCountLabel;
		System::Windows::Forms::Label^ PlayerMoneyLabel;
		System::Windows::Forms::Label^ PlayerScoreLabel;
		System::Windows::Forms::Label^ CroupierScoreLabel;
		System::Windows::Forms::ListBox^ OldBetsListBox;
		System::Windows::Forms::ListBox^ OldBetListBox;
		System::ComponentModel::Container^ components;


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->BetsListBox = (gcnew System::Windows::Forms::ListBox());
			this->BetTextBox = (gcnew System::Windows::Forms::TextBox());
			this->NewBetButton = (gcnew System::Windows::Forms::Button());
			this->CroupierHandListBox = (gcnew System::Windows::Forms::ListBox());
			this->PlayerHandListBox = (gcnew System::Windows::Forms::ListBox());
			this->HitButton = (gcnew System::Windows::Forms::Button());
			this->StandButton = (gcnew System::Windows::Forms::Button());
			this->DoubleButton = (gcnew System::Windows::Forms::Button());
			this->SplitButton = (gcnew System::Windows::Forms::Button());
			this->BetLabel = (gcnew System::Windows::Forms::Label());
			this->MultiplierLabel = (gcnew System::Windows::Forms::Label());
			this->CardCountLabel = (gcnew System::Windows::Forms::Label());
			this->PlayerMoneyLabel = (gcnew System::Windows::Forms::Label());
			this->PlayerScoreLabel = (gcnew System::Windows::Forms::Label());
			this->CroupierScoreLabel = (gcnew System::Windows::Forms::Label());
			this->OldBetsListBox = (gcnew System::Windows::Forms::ListBox());
			this->OldBetListBox = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// BetsListBox
			// 
			this->BetsListBox->FormattingEnabled = true;
			this->BetsListBox->ItemHeight = 16;
			this->BetsListBox->Location = System::Drawing::Point(385, 9);
			this->BetsListBox->Name = L"BetsListBox";
			this->BetsListBox->Size = System::Drawing::Size(144, 260);
			this->BetsListBox->TabIndex = 0;
			this->BetsListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &GameForm::BetsListBox_SelectedIndexChanged);
			// 
			// BetTextBox
			// 
			this->BetTextBox->Location = System::Drawing::Point(12, 275);
			this->BetTextBox->Name = L"BetTextBox";
			this->BetTextBox->Size = System::Drawing::Size(100, 22);
			this->BetTextBox->TabIndex = 1;
			this->BetTextBox->Text = L"100";
			// 
			// NewBetButton
			// 
			this->NewBetButton->Location = System::Drawing::Point(12, 303);
			this->NewBetButton->Name = L"NewBetButton";
			this->NewBetButton->Size = System::Drawing::Size(75, 23);
			this->NewBetButton->TabIndex = 2;
			this->NewBetButton->Text = L"New Bet";
			this->NewBetButton->UseVisualStyleBackColor = true;
			this->NewBetButton->Click += gcnew System::EventHandler(this, &GameForm::NewBetButton_Click);
			// 
			// CroupierHandListBox
			// 
			this->CroupierHandListBox->FormattingEnabled = true;
			this->CroupierHandListBox->ItemHeight = 16;
			this->CroupierHandListBox->Location = System::Drawing::Point(1617, 12);
			this->CroupierHandListBox->Name = L"CroupierHandListBox";
			this->CroupierHandListBox->Size = System::Drawing::Size(158, 180);
			this->CroupierHandListBox->TabIndex = 3;
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
			this->HitButton->Click += gcnew System::EventHandler(this, &GameForm::HitButton_Click);
			// 
			// StandButton
			// 
			this->StandButton->Location = System::Drawing::Point(791, 538);
			this->StandButton->Name = L"StandButton";
			this->StandButton->Size = System::Drawing::Size(75, 23);
			this->StandButton->TabIndex = 6;
			this->StandButton->Text = L"Stand";
			this->StandButton->UseVisualStyleBackColor = true;
			this->StandButton->Click += gcnew System::EventHandler(this, &GameForm::StandButton_Click);
			// 
			// DoubleButton
			// 
			this->DoubleButton->Location = System::Drawing::Point(872, 538);
			this->DoubleButton->Name = L"DoubleButton";
			this->DoubleButton->Size = System::Drawing::Size(75, 23);
			this->DoubleButton->TabIndex = 7;
			this->DoubleButton->Text = L"Double";
			this->DoubleButton->UseVisualStyleBackColor = true;
			this->DoubleButton->Click += gcnew System::EventHandler(this, &GameForm::DoubleButton_Click);
			// 
			// SplitButton
			// 
			this->SplitButton->Location = System::Drawing::Point(953, 538);
			this->SplitButton->Name = L"SplitButton";
			this->SplitButton->Size = System::Drawing::Size(75, 23);
			this->SplitButton->TabIndex = 8;
			this->SplitButton->Text = L"Split";
			this->SplitButton->UseVisualStyleBackColor = true;
			this->SplitButton->Click += gcnew System::EventHandler(this, &GameForm::SplitButton_Click);
			// 
			// BetLabel
			// 
			this->BetLabel->AutoSize = true;
			this->BetLabel->Location = System::Drawing::Point(675, 49);
			this->BetLabel->Name = L"BetLabel";
			this->BetLabel->Size = System::Drawing::Size(27, 16);
			this->BetLabel->TabIndex = 9;
			this->BetLabel->Text = L"Bet";
			// 
			// MultiplierLabel
			// 
			this->MultiplierLabel->AutoSize = true;
			this->MultiplierLabel->Location = System::Drawing::Point(715, 49);
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
			// PlayerMoneyLabel
			// 
			this->PlayerMoneyLabel->AutoSize = true;
			this->PlayerMoneyLabel->Location = System::Drawing::Point(118, 275);
			this->PlayerMoneyLabel->Name = L"PlayerMoneyLabel";
			this->PlayerMoneyLabel->Size = System::Drawing::Size(87, 16);
			this->PlayerMoneyLabel->TabIndex = 13;
			this->PlayerMoneyLabel->Text = L"PlayerMoney";
			// 
			// PlayerScoreLabel
			// 
			this->PlayerScoreLabel->AutoSize = true;
			this->PlayerScoreLabel->Location = System::Drawing::Point(1450, 195);
			this->PlayerScoreLabel->Name = L"PlayerScoreLabel";
			this->PlayerScoreLabel->Size = System::Drawing::Size(82, 16);
			this->PlayerScoreLabel->TabIndex = 14;
			this->PlayerScoreLabel->Text = L"PlayerScore";
			// 
			// CroupierScoreLabel
			// 
			this->CroupierScoreLabel->AutoSize = true;
			this->CroupierScoreLabel->Location = System::Drawing::Point(1614, 195);
			this->CroupierScoreLabel->Name = L"CroupierScoreLabel";
			this->CroupierScoreLabel->Size = System::Drawing::Size(94, 16);
			this->CroupierScoreLabel->TabIndex = 15;
			this->CroupierScoreLabel->Text = L"CroupierScore";
			// 
			// OldBetsListBox
			// 
			this->OldBetsListBox->FormattingEnabled = true;
			this->OldBetsListBox->ItemHeight = 16;
			this->OldBetsListBox->Location = System::Drawing::Point(12, 9);
			this->OldBetsListBox->Name = L"OldBetsListBox";
			this->OldBetsListBox->Size = System::Drawing::Size(144, 260);
			this->OldBetsListBox->TabIndex = 17;
			this->OldBetsListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &GameForm::OldBetsListBox_SelectedIndexChanged);
			// 
			// OldBetListBox
			// 
			this->OldBetListBox->FormattingEnabled = true;
			this->OldBetListBox->ItemHeight = 16;
			this->OldBetListBox->Location = System::Drawing::Point(162, 9);
			this->OldBetListBox->Name = L"OldBetListBox";
			this->OldBetListBox->Size = System::Drawing::Size(217, 260);
			this->OldBetListBox->TabIndex = 18;
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1787, 777);
			this->Controls->Add(this->OldBetListBox);
			this->Controls->Add(this->OldBetsListBox);
			this->Controls->Add(this->CroupierScoreLabel);
			this->Controls->Add(this->PlayerScoreLabel);
			this->Controls->Add(this->PlayerMoneyLabel);
			this->Controls->Add(this->CardCountLabel);
			this->Controls->Add(this->MultiplierLabel);
			this->Controls->Add(this->BetLabel);
			this->Controls->Add(this->SplitButton);
			this->Controls->Add(this->DoubleButton);
			this->Controls->Add(this->StandButton);
			this->Controls->Add(this->HitButton);
			this->Controls->Add(this->PlayerHandListBox);
			this->Controls->Add(this->CroupierHandListBox);
			this->Controls->Add(this->NewBetButton);
			this->Controls->Add(this->BetTextBox);
			this->Controls->Add(this->BetsListBox);
			this->Name = L"GameForm";
			this->Text = L"GameForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: 
			System::Void NewBetButton_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				ClearBets();

				float baseBet = Single::Parse(BetTextBox->Text);

				Withdrawal(baseBet);

				AddNewBet(gcnew Bet::Bet(baseBet, Croupier->NewCroupierHand(), Croupier->NewHand()));
				
				BetsListBox->SelectedIndex = 0;
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}

		private: System::Void BetsListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			UpdateBetLabel();
			UpdateMultiplierLabel();

			UpdatePlayerHandListBox();
			UpdatePlayerScoreLabel();
			UpdateHitButton();
			UpdateStandButton();
			UpdateDoubleButton();
			UpdateSplitButton();
		}

		private: System::Void HitButton_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				if (!IsHit()) throw gcnew Exception("Wrong action!");

				Bets[BetsListBox->SelectedIndex]->PlayHit(DrawCard());
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}

			UpdatePlayerHandListBox();
			UpdatePlayerScoreLabel();
			UpdateHitButton();
			UpdateStandButton();
			UpdateDoubleButton();
			UpdateSplitButton();
			UpdateGame();
		}


		private: System::Void StandButton_Click(System::Object^ sender, System::EventArgs^ e) {
		
			try {
				if (!IsStand())
					throw gcnew Exception("Wrong action!");

				Bets[BetsListBox->SelectedIndex]->PlayStand();
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
			
			UpdateHitButton();
			UpdateStandButton();
			UpdateDoubleButton();
			UpdateSplitButton();
			UpdateGame();
		}

	

		private: System::Void DoubleButton_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				if (!IsDouble())
					throw gcnew Exception("Wrong action!");

				Withdrawal(Bets[BetsListBox->SelectedIndex]->GetBaseBet());
				Bets[BetsListBox->SelectedIndex]->PlayDouble(DrawCard());

			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}

			UpdateBetLabel();
			UpdatePlayerHandListBox();
			UpdatePlayerScoreLabel();
			UpdateHitButton();
			UpdateStandButton();
			UpdateDoubleButton();
			UpdateSplitButton();
			UpdateGame();

		}
		private: System::Void SplitButton_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				if (!IsSplit())
					throw gcnew Exception("Wrong action!");

				Withdrawal(Bets[BetsListBox->SelectedIndex]->GetBaseBet());

				List<Card::Card^>^ cards = gcnew List<Card::Card^>();
				cards->Add(Bets[BetsListBox->SelectedIndex]->PlaySplit());

				Bet::Bet^ newBet = gcnew Bet::Bet(Bets[BetsListBox->SelectedIndex]->GetBaseBet(), Croupier->GetCroupierHand(), gcnew Hand::Hand(cards));
				AddNewBet(newBet);
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}

			BetsListBox->SelectedIndex = 0;

			UpdatePlayerHandListBox();
			UpdatePlayerScoreLabel();
			UpdateHitButton();
			UpdateStandButton();
			UpdateDoubleButton();
			UpdateSplitButton();
			UpdateGame();
		}

		private: System::Void OldBetsListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			UpdateOldBetListBox();
		}
};
}
