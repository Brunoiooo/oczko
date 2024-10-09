#include "GameForm.h"

namespace oczko {
	void GameForm::SetPlayerMoney(float money)
	{
		Player->SetMoney(money >= 0 ? money : 0);

		UpdatePlayerMoneyLabel();
	}

	Card::Card^ GameForm::DrawCard()
	{
		Card::Card^ card = Croupier->GetDeck()->Draw();

		UpdateCardCountLabel();

		return card;
	}

	Hand::Hand^ GameForm::NewCroupierHand()
	{
		Hand::Hand^ hand = Croupier->NewCroupierHand();

		UpdateCardCountLabel();
		UpdateCroupierHandListBox();
		UpdateCroupierScoreLabel();

		return hand;
	}

	Hand::Hand^ GameForm::NewHand()
	{
		Hand::Hand^ hand = Croupier->NewHand();

		UpdateCardCountLabel();

		return hand;
	}

	void GameForm::FillCroupierHand()
	{
		Croupier->FillCroupierHand();

		UpdateCardCountLabel();
		UpdateCroupierHandListBox();
		UpdateCroupierScoreLabel();
	}

	void GameForm::AddNewBet(Bet::Bet^ bet)
	{
		Bets->Add(bet);

		UpdateNewBetButton();
		UpdateBetTextBox();
		UpdateBetsListBox();
		UpdateCroupierHandListBox();
		UpdateCroupierScoreLabel();
	}

	void GameForm::ClearBets()
	{
		Bets->Clear();

		UpdateNewBetButton();
		UpdateBetTextBox();
		UpdateBetsListBox();
		UpdateBetLabel();
		UpdateMultiplierLabel();
	}

	void GameForm::AddOldBet(Bet::Bet^ bet)
	{
		SetPlayerMoney(Player->GetMoney() + bet->Payout());
		OldBets->Add(bet);

		UpdateOldBetsListBox();
	}

	void GameForm::StartNewGame()
	{
		ClearBets();

		float baseBet = Single::Parse(BetTextBox->Text);

		float money = Player->GetMoney();
		if (Player->GetMoney() < baseBet) throw gcnew System::Exception("Bet has not been bigger than the player's money.");

		SetPlayerMoney(money - baseBet);

		Hand::Hand^ croupierHand = Croupier->NewCroupierHand();
		Hand::Hand^ playerHand = Croupier->NewHand();

		Bet::Bet^ bet = gcnew Bet::Bet(baseBet, playerHand, croupierHand);

		AddNewBet(bet);

		BetsListBox->SelectedIndex = 0;
	}

	void GameForm::UpdatePlayerMoneyLabel()
	{
		PlayerMoneyLabel->Text = Player->GetMoney().ToString();
	}

	void GameForm::UpdateNewBetButton()
	{
		if (Bets->Count >= 1) NewBetButton->Hide();
		else NewBetButton->Show();
	}

	void GameForm::UpdateBetTextBox()
	{
		if (Bets->Count >= 1) BetTextBox->Hide();
		else BetTextBox->Show();
	}

	void GameForm::UpdateOldBetsListBox()
	{
		OldBetsListBox->Items->Clear();

		for each (Bet::Bet ^ oldBet in OldBets)
		{
			if (oldBet->IsWin())
				OldBetsListBox->Items->Add("Win +" + ((oldBet->GetMultiplier() * oldBet->GetBaseBet()) - oldBet->GetBaseBet()).ToString());
			else if (oldBet->IsLost())
				OldBetsListBox->Items->Add("Lost -" + oldBet->GetBaseBet().ToString());
			else
				OldBetsListBox->Items->Add("Draw");
		}
	}

	void GameForm::UpdateOldBetListBox()
	{
		int selectedIndex = OldBetsListBox->SelectedIndex;

		OldBetListBox->Items->Clear();

		if (selectedIndex < 0)
			OldBetListBox->Hide();
		else {
			Bet::Bet^ oldBet = OldBets[selectedIndex];

			OldBetListBox->Items->Add("Stop: " + oldBet->IsStop().ToString());
			OldBetListBox->Items->Add("Win: " + oldBet->IsWin().ToString());
			OldBetListBox->Items->Add("Lost: " + oldBet->IsLost().ToString());
			OldBetListBox->Items->Add("Draw: " + oldBet->IsDraw().ToString());
			OldBetListBox->Items->Add("Base bet: " + oldBet->GetBaseBet().ToString());
			OldBetListBox->Items->Add("Multiplier: " + oldBet->GetMultiplier().ToString());

			Hand::Hand^ playerHand = oldBet->GetPlayerHand();
			OldBetListBox->Items->Add("Player hand score: " + playerHand->GetScore().ToString());
			OldBetListBox->Items->Add("Player hand:");
			for each (Card::Card ^ card in playerHand->GetCards())
				OldBetListBox->Items->Add(card->GetColor() + "|" + card->GetValue());

			Hand::Hand^ croupierHand = oldBet->GetCroupierHand();
			OldBetListBox->Items->Add("Croupier hand score: " + croupierHand->GetScore().ToString());
			OldBetListBox->Items->Add("Croupier hand:");
			for each (Card::Card ^ card in croupierHand->GetCards())
				OldBetListBox->Items->Add(card->GetColor() + "|" + card->GetValue());

			OldBetListBox->Show();
		}
	}

	void GameForm::UpdateBetsListBox()
	{
		BetsListBox->Items->Clear();

		for (int i = 0; i < Bets->Count; i++)
			BetsListBox->Items->Add("#" + (i + 1).ToString() + " Bet");
	}

	void GameForm::UpdateBetLabel()
	{
		int selectedIndex = BetsListBox->SelectedIndex;
		if (selectedIndex < 0)
			BetLabel->Hide();
		else {
			Bet::Bet^ bet = Bets[selectedIndex];
			BetLabel->Text = bet->GetBaseBet().ToString();
			BetLabel->Show();
		}
	}

	void GameForm::UpdateMultiplierLabel()
	{
		int selectedIndex = BetsListBox->SelectedIndex;
		if (selectedIndex < 0)
			MultiplierLabel->Hide();
		else {
			Bet::Bet^ bet = Bets[selectedIndex];
			MultiplierLabel->Text = "x" + bet->GetMultiplier().ToString();
			MultiplierLabel->Show();
		}
	}

	void GameForm::UpdateCardCountLabel()
	{
		CardCountLabel->Text = Croupier->GetDeck()->GetCountOfCards().ToString();
	}

	void GameForm::UpdatePlayerHandListBox()
	{
		PlayerScoreLabel->Hide();
		PlayerHandListBox->Items->Clear();

		int selectedIndex = BetsListBox->SelectedIndex;
		if (selectedIndex >= 0) {
			Bet::Bet^ bet = Bets[selectedIndex];

			for each (Card::Card ^ card in bet->GetPlayerHand()->GetCards())
				PlayerHandListBox->Items->Add(card->GetColor() + "|" + card->GetValue());

			PlayerHandListBox->Show();
		}
	}

	void GameForm::UpdatePlayerScoreLabel()
	{
		PlayerScoreLabel->Hide();

		int selectedIndex = BetsListBox->SelectedIndex;
		if (selectedIndex >= 0){
			Bet::Bet^ bet = Bets[selectedIndex];

			PlayerScoreLabel->Text = bet->GetPlayerHand()->GetScore().ToString();

			PlayerScoreLabel->Show();
		}
	}

	void GameForm::UpdateCroupierHandListBox()
	{
		CroupierHandListBox->Items->Clear();
		CroupierHandListBox->Hide();

		Hand::Hand^ hand = Croupier->GetCroupierHand();
		List<Card::Card^>^ cards = hand->GetCards();

		int doneBets = 0;
		for each (Bet::Bet ^ bet in Bets)
		{
			if (bet->IsStop()) doneBets++;
		}

		if (cards->Count == 2 && Bets->Count != doneBets) {
			CroupierHandListBox->Items->Add(cards[0]->GetColor() + "|" + cards[0]->GetValue());
			CroupierHandListBox->Items->Add("?|?");

			CroupierHandListBox->Show();

		}
		else {
			for each (Card::Card ^ card in cards)
				CroupierHandListBox->Items->Add(card->GetColor() + "|" + card->GetValue());

			CroupierHandListBox->Show();
		}
	}

	void GameForm::UpdateCroupierScoreLabel()
	{
		CroupierScoreLabel->Hide();

		Hand::Hand^ hand = Croupier->GetCroupierHand();
		List<Card::Card^>^ cards = hand->GetCards();

		int doneBets = 0;
		for each (Bet::Bet ^ bet in Bets)
		{
			if (bet->IsStop()) doneBets++;
		}

		if (cards->Count == 2 && Bets->Count != doneBets) {
			CroupierScoreLabel->Text = cards[0]->GetValue().ToString();

			CroupierScoreLabel->Show();
		}
		else {
			CroupierScoreLabel->Text = hand->GetScore().ToString();

			CroupierScoreLabel->Show();
		}
	}

	void GameForm::UpdateHitButton()
	{
		HitButton->Hide();

		int selectedIndex = BetsListBox->SelectedIndex;
		if (selectedIndex < 0)
			return;

		if (Bets->Count < 1)
			return;

		Bet::Bet^ bet = Bets[selectedIndex];

		if (bet->IsStop())
			return;

		HitButton->Show();
	}

	void GameForm::UpdateStandButton()
	{
		StandButton->Hide();

		int selectedIndex = BetsListBox->SelectedIndex;
		if (selectedIndex < 0)
			return;

		if (Bets->Count < 1)
			return;

		Bet::Bet^ bet = Bets[selectedIndex];

		if (bet->IsStop())
			return;

		StandButton->Show();
	}

	void GameForm::UpdateDoubleButton()
	{
		DoubleButton->Hide();

		int selectedIndex = BetsListBox->SelectedIndex;
		if (selectedIndex < 0)
			return;

		if (Bets->Count < 1)
			return;

		Bet::Bet^ bet = Bets[selectedIndex];

		if (bet->IsStop())
			return;

		if (bet->IsHit())
			return;

		DoubleButton->Show();
	}

	void GameForm::UpdateSplitButton()
	{
		SplitButton->Hide();

		int selectedIndex = BetsListBox->SelectedIndex;

		if (selectedIndex < 0)
			return;

		if (Bets->Count < 1)
			return;

		Bet::Bet^ bet = Bets[selectedIndex];

		if (Player->GetMoney() < bet->GetBaseBet())
			return;

		if (!bet->CanSplit())
			return;

		SplitButton->Show();
	}

	void GameForm::UpdateGame()
	{
		if (Bets->Count < 1)
			return;

		int doneBets = 0;
		for each (Bet::Bet ^ bet in Bets)
		{
			if (bet->IsStop()) doneBets++;
		}
		if (Bets->Count != doneBets) return;

		FillCroupierHand();

		for each (Bet::Bet ^ bet in Bets)
		{
			AddOldBet(bet);
		}
		ClearBets();
	}
}