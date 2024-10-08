#include "GameForm.h"

namespace oczko {
	//Getters and setters
	float GameForm::GetMoney() {
		return Money;
	}

	void GameForm::SetMoney(float money) {
		if(money < 0) System::Exception("Money can't be less than 0.");
		Money = money;

		UpdateMoneyLabel();
	}

	Deck::Deck^ GameForm::GetDeck() {
		return Deck;
	}

	void GameForm::SetDeck(Deck::Deck^ deck) {
		Deck = deck;
		UpdateCardCountLabel();
		UpdatePlayerHandListBox();
	}

	Card::Card^ GameForm::Draw() {
		Card::Card^ card = GetDeck()->Draw();
		UpdateCardCountLabel();
		UpdatePlayerHandListBox();
		return card;
	}

	List<Player::Player^>^ GameForm::GetPlayers() {
		return Players;
	}

	void GameForm::AddPlayer(Player::Player^ player) {
		Players->Add(player);
		UpdateBetButtor();
		UpdateHandsListBox();
		UpdateNewBetTextBox();
		
	}

	void GameForm::ClearPlayer() {
		Players->Clear();
		UpdateBetButtor();
		UpdateHandsListBox();
		UpdateNewBetTextBox();
	}

	Croupier::Croupier^ GameForm::GetCroupier() {
		return Croupier;
	}

	void GameForm::SetCroupier(Croupier::Croupier^ croupier) {
		Croupier = croupier;
	}

	int GameForm::GetActiveHand() {
		return ActiveHand;
	}

	void GameForm::SetActiveHand(int activeHand) {
		ActiveHand = activeHand;
		UpdateBetLabel();
		UpdateMultiplierLabel();
		UpdatePlayerHandListBox();
	}

	//Methods
	void GameForm::StartNewGame() {
		float bet = Single::Parse(BetTextBox->Text);
		if (bet <= 0) throw gcnew System::Exception("Bet's money has to be bigger than 0.");

		float money = GetMoney();
		if (money < bet) throw gcnew System::Exception("Bet has to be less than your money.");
		SetMoney(money - bet);

		Deck::Deck^ deck = gcnew Deck::Deck();
		SetDeck(deck);

		ClearPlayer();
		Player::Player^ player = gcnew Player::Player(bet, Draw(), Draw());
		AddPlayer(player);

		Croupier::Croupier^ croupier = gcnew Croupier::Croupier(Draw(), Draw());
		SetCroupier(croupier);

		SetActiveHand(0);
	}

	//Updaters
	void GameForm::UpdateHandsListBox() {
		HandsListBox->Items->Clear();

		List<Player::Player^>^ players = GetPlayers();

		for (int i = 0; i < players->Count; i++)
		{
			HandsListBox->Items->Add("Hand " + i.ToString());
		}
	}

	void GameForm::UpdateBetButtor() {
		List<Player::Player^>^ players = GetPlayers();

		if (players->Count > 0) NewBetButton->Hide();
		else NewBetButton->Show();
	}

	void GameForm::UpdateNewBetTextBox() {
		List<Player::Player^>^ players = GetPlayers();

		if (players->Count > 0) BetTextBox->Hide();
		else BetTextBox->Show();
	}

	void GameForm::UpdateMoneyLabel() {
		float money = GetMoney();

		MoneyLabel->Text = money.ToString();
	}

	void GameForm::UpdateBetLabel() {
		List<Player::Player^>^ players = GetPlayers();
		int activeHand = GetActiveHand();
		
		if (activeHand < 0 || players->Count <= activeHand) BetLabel->Hide();
		else {
			Player::Player^ player = players[activeHand];

			BetLabel->Text = player->GetBet().ToString();
			BetLabel->Show();
		}
	}

	void GameForm::UpdateMultiplierLabel() {
		List<Player::Player^>^ players = GetPlayers();
		int activeHand = GetActiveHand();
		
		if (activeHand < 0 || players->Count <= activeHand) MultiplierLabel->Hide();
		else {
			Player::Player^ player = players[activeHand];

			MultiplierLabel->Text = player->GetMultiplier().ToString();
			MultiplierLabel->Show();
		}
	}

	void GameForm::UpdateCardCountLabel() {
		List<Player::Player^>^ players = GetPlayers();

		int activeHand = GetActiveHand();

		if (players->Count < 1) CardCountLabel->Hide();
		else {
			Deck::Deck^ deck = GetDeck();

			CardCountLabel->Text = "x" + deck->GetCountOfCards().ToString();
			CardCountLabel->Show();
		}
	}

	void GameForm::UpdatePlayerHandListBox() {
		List<Player::Player^>^ players = GetPlayers();

		if (players->Count < 1) CardCountLabel->Hide();
		else {
			Deck::Deck^ deck = GetDeck();

			CardCountLabel->Text = deck->GetCountOfCards().ToString();
			CardCountLabel->Show();
		}
	}
}