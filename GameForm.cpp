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
	}

	Card::Card^ GameForm::Draw() {
		Card::Card^ card = GetDeck()->Draw();
		UpdateCardCountLabel();
		UpdatePlayerHandListBox();
		UpdateCroupierHandListBox();
		UpdateHitButton();
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

	void GameForm::AddPlayerCard()
	{
		GetPlayers()[GetActiveHand()]
			->GetCards()
			->Add(Draw());
		UpdatePlayerHandListBox();
		UpdateHitButton();
		UpdatePlayerScoreLabel();
		UpdateStandButton();
	}

	void GameForm::StandPlayer()
	{
		GetPlayers()[GetActiveHand()]
			->SetStand();
		UpdateHitButton();
		UpdateStandButton();
	}

	Croupier::Croupier^ GameForm::GetCroupier() {
		return Croupier;
	}

	void GameForm::SetCroupier(Croupier::Croupier^ croupier) {
		Croupier = croupier;
		UpdateCroupierHandListBox();
	}

	int GameForm::GetActiveHand() {
		return ActiveHand;
	}

	void GameForm::SetActiveHand(int activeHand) {
		ActiveHand = activeHand;
		UpdateBetLabel();
		UpdateMultiplierLabel();
		UpdatePlayerHandListBox();
		UpdateHitButton();
		UpdatePlayerScoreLabel();
		UpdateStandButton();
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

			MultiplierLabel->Text = "x" + player->GetMultiplier().ToString();
			MultiplierLabel->Show();
		}
	}

	void GameForm::UpdateCardCountLabel() {
		List<Player::Player^>^ players = GetPlayers();
		int activeHand = GetActiveHand();
		Deck::Deck^ deck = GetDeck();

		if (players->Count < 1 || deck == nullptr) CardCountLabel->Hide();
		else {
			CardCountLabel->Text = deck->GetCountOfCards().ToString();
			CardCountLabel->Show();
		}
	}

	void GameForm::UpdatePlayerHandListBox() {
		PlayerHandListBox->Items->Clear();

		List<Player::Player^>^ players = GetPlayers();

		int activeHand = GetActiveHand();

		if (players->Count < 1 || activeHand < 0 || players->Count <= activeHand) PlayerHandListBox->Hide();
		else {
			Player::Player^ player = players[activeHand];

			List<Card::Card^>^ cards = player->GetCards();

			for(int i = 0; i < cards->Count; i++)
				PlayerHandListBox->Items->Add(cards[i]->GetColor() + "|" + cards[i]->GetValue());
			PlayerHandListBox->Show();
		}
	}

	void GameForm::UpdateCroupierHandListBox() {
		CoupierHandListBox->Items->Clear();

		Croupier::Croupier^ croupier = GetCroupier();
		List<Player::Player^>^ players = GetPlayers();

		if (players->Count < 1 || croupier == nullptr) CoupierHandListBox->Hide();
		else {
			List<Card::Card^>^ cards = croupier->GetCards();

			for (int i = 0; i < cards->Count; i++) {
				if(i == 0) CoupierHandListBox->Items->Add(cards[i]->GetColor() + "|" + cards[i]->GetValue());
				else CoupierHandListBox->Items->Add("?");
			}

			CoupierHandListBox->Show();
		}
	}

	void GameForm::UpdateHitButton() {
		int activeHand = GetActiveHand();
		List<Player::Player^>^ players = GetPlayers();

		if (players->Count < 1 || 
			activeHand < 0 || 
			players->Count <= activeHand || 
			players[activeHand]->GetScore() >= 21 ||
			players[activeHand]->GetStand())
				HitButton->Hide();
		else HitButton->Show();
	}

	void GameForm::UpdatePlayerScoreLabel() {
		int activeHand = GetActiveHand();
		List<Player::Player^>^ players = GetPlayers();

		if (players->Count < 1 ||
			activeHand < 0 ||
			players->Count <= activeHand)
			PlayerScoreLabel->Hide();
		else {
			PlayerScoreLabel->Text = "Score: " + players[activeHand]->GetScore().ToString();
			PlayerScoreLabel->Show();
		}
	}
	void GameForm::UpdateStandButton()
	{
		int activeHand = GetActiveHand();
		List<Player::Player^>^ players = GetPlayers();

		if (players->Count < 1 ||
			activeHand < 0 ||
			players->Count <= activeHand)
			StandButton->Hide();
		else if(players[activeHand]->GetStand())
			StandButton->Hide();
		else if(players[activeHand]->GetCards()->Count == 2 && 
			players[activeHand]->GetScore() == 22) 
			StandButton->Show();
		else if(players[activeHand]->GetScore() <= 21) 
			StandButton->Show();
		else StandButton->Hide();
	}
}