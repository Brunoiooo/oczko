#include "MenuForm.h"
#include "Core.hpp"

#include <iostream>

using namespace oczko;
using namespace std;

[STAThreadAttribute]
int main()
{
	Core::Core* core = new Core::Core(1000);

	while (true) {
		try {
			system("cls");
			Player::Player* player = core->GetPlayer();
			cout << "Player's money: " << player->GetMoney() << endl;
			cout << "Player's bets: " << endl;
			for (Bet::Bet* bet : *player->GetBets()) {
				cout << "#";
				if (bet->IsWin()) cout << "WIn +" << bet->GetBaseBet() << endl;
				if (bet->IsLost()) cout << "Lost -" << bet->GetBaseBet() << endl;
				if (bet->IsDraw()) cout << "Draw" << endl;
			}
				

			if (core->GetBets()->size() < 1) {
				cout << "Bet: ";
				float baseBet;
				cin >> baseBet;

				core->NewBet(baseBet);
			}
			else {
				for (unsigned int i = 0; i < core->GetBets()->size(); i++)
					if (!(*core->GetBets())[i]->IsStop())
						cout << "#" << i << " Hand" << endl;

				cout << "Choice hand: ";
				unsigned int betIndex;
				cin >> betIndex;

				Bet::Bet* bet = (*core->GetBets())[betIndex];

				cout << "Player Score: " << bet->GetHand()->GetScore() << endl;
				cout << "Croupier Score: " << core->GetCroupier()->GetCroupierHand()->GetScore() << endl;

				cout << "Actions: ";
				if (bet->CanHit())
					cout << "hit, ";
				if (bet->CanStand())
					cout << "stand, ";
				if (bet->CanDouble(core->GetPlayer()))
					cout << "double, ";
				if (bet->CanSplit(core->GetPlayer()))
					cout << "split, ";
				cout << "back" << endl;

				string action;
				cin >> action;

				if (action == "hit")
					core->Hit(bet);
				if (action == "stand")
					core->Stand(bet);
				if (action == "double")
					core->Double(bet);
				if (action == "split")
					core->Split(bet);
			}
		}
		catch (runtime_error $e) {
			cout << $e.what() << endl;
		}
	}

	/*Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MenuForm());*/
	return 0;
}