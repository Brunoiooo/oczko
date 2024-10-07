#include "GameForm.h"

namespace oczko {
	//Getters and setters
	float GameForm::GetMoney() {
		return this->Money;
	}

	void GameForm::SetMoney(float money) {
		if(money < 0) System::Exception("Money can't be less than 0.");
		this->Money = money;
	}

	Deck::Deck^ GameForm::GetDeck() {
		return this->Deck;
	}

	void GameForm::SetDeck(Deck::Deck^ deck) {
		this->Deck = deck;
	}

	Card::Card^ GameForm::Draw() {
		Deck::Deck^ deck = this->GetDeck();
		return deck->Draw();
	}

	List<Player::Player^>^ GameForm::GetPlayers() {
		return this->Players;
	}

	void GameForm::AddPlayer(Player::Player^ player) {
		this->Players->Add(player);
		this->UpdateHandsListBox();
	}

	void GameForm::ClearPlayer() {
		this->Players->Clear();
		this->UpdateHandsListBox();
	}

	Croupier::Croupier^ GameForm::GetCroupier() {
		return this->Croupier;
	}

	void GameForm::SetCroupier(Croupier::Croupier^ croupier) {
		this->Croupier = croupier;
	}

	//Methods
	void GameForm::StartNewGame(float bet) {
		if (bet <= 0) throw gcnew System::Exception("Bet's money has to be bigger than 0.");

		float money = this->GetMoney();
		if (money < bet) throw gcnew System::Exception("Bet has to be less than your money.");
		this->SetMoney(money - bet);

		Deck::Deck^ deck = gcnew Deck::Deck();
		this->SetDeck(deck);

		this->ClearPlayer();
		Player::Player^ player = gcnew Player::Player(bet, this->Draw(), this->Draw());
		this->AddPlayer(player);

		Croupier::Croupier^ croupier = gcnew Croupier::Croupier(this->Draw(), this->Draw());
		this->SetCroupier(croupier);
	}

	void GameForm::UpdateHandsListBox() {
		this->HandsListBox->Items->Clear();

		List<Player::Player^>^ players = this->GetPlayers();

		for(int i = 0; i < players->Count; i++)
		{
			this->HandsListBox->Items->Add("Hand " + i.ToString());
		}
	}

}