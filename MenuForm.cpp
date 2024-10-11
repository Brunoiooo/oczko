#include "MenuForm.h"
#include "GameForm.h"

namespace oczko {
	System::Void MenuForm::StartButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try {
			float startMoney = Single::Parse(StartMoneyTextBox->Text);

			if (startMoney <= 0) 
				throw gcnew System::Exception("Start money has to be bigger than 0.");

			Hide();
			GameForm^ gameForm = gcnew GameForm(startMoney);
			gameForm->Show();
		}
		catch (System::Exception^ e) {
			MessageBox::Show(e->Message);
		}
	}
}


