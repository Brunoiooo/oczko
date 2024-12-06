#include "MenuForm.h"
#include "GameForm.h"
#include "AboutMeForm.h"

namespace oczko {
	System::Void MenuForm::StartButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try {
			float startMoney = Single::Parse(StartMoneyTextBox->Text);

			if (startMoney <= 0) 
				throw gcnew System::Exception("Start money has to be bigger than 0.");

			if (player_name_textbox->Text->Length < 1)
				throw gcnew System::Exception("Player name can't be empty.");

			Hide();
			GameForm^ gameForm = gcnew GameForm(startMoney, player_name_textbox->Text);
			gameForm->Show();
		}
		catch (System::Exception^ e) {
			MessageBox::Show(e->Message);
		}
	}
	System::Void MenuForm::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Application::Exit();
	}
	System::Void MenuForm::aboutMeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		AboutMeForm^ aboutMeForm = gcnew AboutMeForm();

		aboutMeForm->ShowDialog();
	}
}


