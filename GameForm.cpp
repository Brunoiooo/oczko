#include "GameForm.h"

namespace oczko {
	void GameForm::Deposit(float money)
	{
		Player->Deposit(money);

		UpdatePlayerMoneyLabel();
	}

	void GameForm::Withdrawal(float money)
	{
		Player->Withdrawal(money);

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
		Deposit(bet->Payout());
		OldBets->Add(bet);

		UpdateOldBetsListBox();
	}

	bool GameForm::IsHit()
	{
		try {
			if (!Bets[BetsListBox->SelectedIndex]->IsStop()) return true;
		}
		catch (Exception^ e){}

		return false;
	}

	bool GameForm::IsStand()
	{
		try {
			if (!Bets[BetsListBox->SelectedIndex]->IsStop()) return true;
		}
		catch (Exception^ e){}

		return false;
	}

	bool GameForm::IsDouble()
	{
		try {
			if (!Bets[BetsListBox->SelectedIndex]->IsStop() && 
				!Bets[BetsListBox->SelectedIndex]->IsHit() &&
				Player->CanWithdrawal(Bets[BetsListBox->SelectedIndex]->GetBaseBet()))
				return true;
		}
		catch (Exception^ e) {}

		return false;
	}

	bool GameForm::IsSplit()
	{
		try {
			if (Player->CanWithdrawal(Bets[BetsListBox->SelectedIndex]->GetBaseBet()) &&
				Bets[BetsListBox->SelectedIndex]->CanSplit())
				return true;
		}
		catch (Exception^ e) {}

		return false;
	}

	bool GameForm::IsBet()
	{
		return 0 <= BetsListBox->SelectedIndex && BetsListBox->SelectedIndex < Bets->Count ? true : false;
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
		OldBetListBox->Items->Clear();
		OldBetListBox->Hide();

		if (BetsListBox->SelectedIndex < Bets->Count){
			Bet::Bet^ oldBet = OldBets[OldBetsListBox->SelectedIndex];

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
		BetLabel->Hide();

		if (IsBet()){
			Bet::Bet^ bet = Bets[BetsListBox->SelectedIndex];
			BetLabel->Text = bet->GetBaseBet().ToString();
			BetLabel->Show();
		}
	}

	void GameForm::UpdateMultiplierLabel(){
	
		MultiplierLabel->Hide();

		if (IsBet()){
			MultiplierLabel->Text = "x" + Bets[BetsListBox->SelectedIndex]->GetMultiplier().ToString();

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

		if (IsBet()) {
			for each (Card::Card ^ card in Bets[BetsListBox->SelectedIndex]->GetPlayerHand()->GetCards())
				PlayerHandListBox->Items->Add(card->GetColor() + "|" + card->GetValue());

			PlayerHandListBox->Show();
		}
	}

	void GameForm::UpdatePlayerScoreLabel()
	{
		PlayerScoreLabel->Hide();

		if (IsBet()){
			PlayerScoreLabel->Text = Bets[BetsListBox->SelectedIndex]->GetPlayerHand()->GetScore().ToString();

			PlayerScoreLabel->Show();
		}
	}

	void GameForm::UpdateCroupierHandListBox()
	{
		CroupierHandListBox->Items->Clear();
		CroupierHandListBox->Hide();

		int doneBets = 0;
		for each (Bet::Bet ^ bet in Bets)
			if (bet->IsStop()) doneBets++;
		
		if (Croupier->GetCroupierHand()->GetCards()->Count == 2 && Bets->Count != doneBets) {
			CroupierHandListBox->Items->Add(Croupier->GetCroupierHand()->GetCards()[0]->GetColor() + "|" + Croupier->GetCroupierHand()->GetCards()[0]->GetValue());
			CroupierHandListBox->Items->Add("?|?");

			CroupierHandListBox->Show();
		}
		else {
			for each (Card::Card ^ card in Croupier->GetCroupierHand()->GetCards())
				CroupierHandListBox->Items->Add(card->GetColor() + "|" + card->GetValue());

			CroupierHandListBox->Show();
		}
	}

	void GameForm::UpdateCroupierScoreLabel()
	{
		CroupierScoreLabel->Hide();

		int doneBets = 0;
		for each (Bet::Bet ^ bet in Bets)
			if (bet->IsStop()) doneBets++;
		
		if (Croupier->GetCroupierHand()->GetCards()->Count == 2 && Bets->Count != doneBets)
			CroupierScoreLabel->Text = Croupier->GetCroupierHand()->GetCards()[0]->GetValue().ToString();
		else 
			CroupierScoreLabel->Text = Croupier->GetCroupierHand()->GetScore().ToString();

		CroupierScoreLabel->Show();
	}

	void GameForm::UpdateHitButton()
	{
		if (IsHit())
			HitButton->Show();
		else
			HitButton->Hide();
	}

	void GameForm::UpdateStandButton()
	{
		if(IsStand())
			StandButton->Show();
		else 
			StandButton->Hide();
	}

	void GameForm::UpdateDoubleButton()
	{
		if (IsDouble())
			DoubleButton->Show();
		else
			DoubleButton->Hide();
	}

	void GameForm::UpdateSplitButton()
	{
		if (IsSplit())
			SplitButton->Show();
		else
			SplitButton->Hide();
	}

	void GameForm::UpdateGame()
	{
		if (Bets->Count < 1)
			return;

		for each (Bet::Bet ^ bet in Bets)
			if (!bet->IsStop()) return;

		FillCroupierHand();

		for each (Bet::Bet ^ bet in Bets)
			AddOldBet(bet);
		
		ClearBets();
	}
}