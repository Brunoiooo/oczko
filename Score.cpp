#include "Score.h"

namespace Score {
	Score::Score(Player::Player^ player, Croupier::Croupier^ croupier)
	{
		Player = player;
		Croupier = croupier;

		if (IsWin() > 0 &&
			player->GetCards()->Count == 2 &&
			(player->GetScore() == 21 || player->GetScore() == 22))
			player->SetMultiplier(player->GetMultiplier() + 0.5);
	}
	Player::Player^ Score::GetPlayer()
	{
		return Player;
	}
	Croupier::Croupier^ Score::GetCroupier()
	{
		return Croupier;
	}
	float Score::Withdraw()
	{
		Player::Player^ player = GetPlayer();

		if (IsWin() > 0) {
			return player->GetBet() * player->GetMultiplier();
		}
		else if (IsWin() == 0) {
			return player->GetBet();
		}
		else {
			return 0;
		}
	}
	int Score::IsWin()
	{
		Player::Player^ player = GetPlayer();
		Croupier::Croupier^ croupier = GetCroupier();

		if (player->GetScore() == 22 && player->GetCards()->Count == 2 &&
			croupier->GetScore() == 22 && croupier->GetCards()->Count == 2)
			return 0;
		else if (player->GetScore() == 22 && player->GetCards()->Count == 2)
			return 1;
		else if (player->GetScore() >= 22) 
			return -1;
		else if (croupier->GetScore() >= 22) 
			return 1;
		else if (player->GetScore() == croupier->GetScore()) 
			return 0;
		else if (player->GetScore() > croupier->GetScore()) 
			return 1;
		else 
			return -1;
	}
}
