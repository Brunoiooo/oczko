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

	List<Player::Player^>^ GameForm::GetPlayers() {
		return Players;
	}

	void GameForm::AddPlayer(Player::Player^ player) {
		Players->Add(player);

		UpdateBetButtor();
		UpdateHandsListBox();
		UpdateNewBetTextBox();
		UpdateCardCountLabel();
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
			->Add(GetDeck()->Draw());

		UpdatePlayerHandListBox();
		UpdateHitButton();
		UpdatePlayerScoreLabel();
		UpdateStandButton();
		UpdateCardCountLabel();
		CheckGame();
	}

	void GameForm::StandPlayer()
	{
		GetPlayers()[GetActiveHand()]
			->SetStand();

		UpdateHitButton();
		UpdateStandButton();
		CheckGame();
	}

	Croupier::Croupier^ GameForm::GetCroupier() {
		return Croupier;
	}

	void GameForm::SetCroupier(Croupier::Croupier^ croupier) {
		Croupier = croupier;

		UpdateCroupierHandListBox();
		UpdateCardCountLabel();
		UpdateCroupierScoreLabel();
	}

	void GameForm::AddCroupierCard()
	{
		GetCroupier()
			->GetCards()
			->Add(GetDeck()->Draw());

		UpdateCardCountLabel();
		UpdateCroupierHandListBox();
		UpdateCroupierScoreLabel();
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

	int GameForm::GetActiveScore()
	{
		return ActiveScore;
	}

	void GameForm::SetActiveScore(int activeScore)
	{
		ActiveScore = activeScore;

		UpdateScoreListBox();
	}

	List<Score::Score^>^ GameForm::GetTable()
	{
		return Table;
	}

	void GameForm::SetTable(List<Score::Score^>^ table)
	{
		Table = table;

		UpdateTableListBox();
	}

	void GameForm::AddTableScore(Score::Score^ score)
	{
		GetTable()->Add(score);

		UpdateTableListBox();
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
		Player::Player^ player = gcnew Player::Player(bet, deck->Draw(), deck->Draw());
		AddPlayer(player);

		Croupier::Croupier^ croupier = gcnew Croupier::Croupier(deck->Draw(), deck->Draw());
		SetCroupier(croupier);

		SetActiveHand(0);
	}

	void GameForm::CheckGame()
	{
		List<Player::Player^>^ players = GetPlayers();
		int donePlayers = 0;

		for each (Player::Player^ player in players)
		{
			if (player->GetStand()) donePlayers++;
			else if (player->GetScore() >= 23) donePlayers++;
			else if (player->GetScore() == 22 && player->GetCards()->Count != 2) donePlayers++;
		}

		if (players->Count != donePlayers) return;

		Croupier::Croupier^ croupier = GetCroupier();
		while (croupier->GetScore() < 17) {
			AddCroupierCard();
		}

		for each (Player::Player^ player in players)
		{
			Score::Score^ score = gcnew Score::Score(player, croupier);

			SetMoney(GetMoney() + score->Withdraw());

			AddTableScore(score);
		}

		ClearPlayer();
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
				if(i == 0 || cards->Count > 2) CoupierHandListBox->Items->Add(cards[i]->GetColor() + "|" + cards[i]->GetValue());
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
	void GameForm::UpdateCroupierScoreLabel()
	{
		Croupier::Croupier^ croupier = GetCroupier();

		if (croupier == nullptr)
			CroupierScoreLabel->Hide();
		else if(croupier->GetCards()->Count == 2) {
			CroupierScoreLabel->Text = "Score: " + croupier->GetCards()[0]->GetValue().ToString();
			CroupierScoreLabel->Show();
		}
		else {
			CroupierScoreLabel->Text = "Score: " + croupier->GetScore().ToString();
			CroupierScoreLabel->Show();
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
	void GameForm::UpdateTableListBox()
	{
		List<Score::Score^>^ table = GetTable();

		TableListBox->Items->Clear();

		for (int i = 0; i < table->Count; i++) {
			Score::Score^ score = table[i];

			String^ result = "Draw";
			if (score->IsWin() > 0) {
				result = "Win +" + (score->Withdraw() - score->GetPlayer()->GetBet()).ToString();
			}
			else if (score->IsWin() < 0) {
				result = "Lost -" + score->GetPlayer()->GetBet();
			}

			TableListBox->Items->Add("#" + i.ToString() + " " + result);
		}
			
	}
	void GameForm::UpdateScoreListBox()
	{
		ScoreListBox->Items->Clear();

		int activeScore = GetActiveScore();
		List<Score::Score^>^ table = GetTable();

		if (activeScore < 0) ScoreListBox->Hide();
		else {
			Score::Score^ score = table[activeScore];

			Player::Player^ player = score->GetPlayer();

			Croupier::Croupier^ croupier = score->GetCroupier();
			
			int withdraw = score->Withdraw();

			List<Card::Card^>^ playerCards = player->GetCards();
			List<Card::Card^>^ croupierCards = croupier->GetCards();

			ScoreListBox->Items->Add("Bet: " + player->GetBet().ToString());
			ScoreListBox->Items->Add("Multiplier: " + player->GetMultiplier().ToString());
			ScoreListBox->Items->Add("Withdraw: " + withdraw.ToString());
			ScoreListBox->Items->Add("Player score: " + player->GetScore().ToString());
			ScoreListBox->Items->Add("Player cards:");
			for each (Card::Card ^ card in playerCards)
				ScoreListBox->Items->Add(card->GetColor().ToString() + "|" + card->GetValue().ToString());
			ScoreListBox->Items->Add("Croupier score: " + croupier->GetScore().ToString());
			ScoreListBox->Items->Add("Croupier cards:");
			for each (Card::Card ^ card in croupierCards)
				ScoreListBox->Items->Add(card->GetColor().ToString() + "|" + card->GetValue().ToString());
			ScoreListBox->Show();
		}
	}
}