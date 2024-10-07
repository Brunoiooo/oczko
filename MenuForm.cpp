#include "MenuForm.h"
#include "GameForm.h"
#include <stdexcept>

namespace oczko {
	//Handlers
	System::Void MenuForm::StartButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try {
			float startMoney = Single::Parse(this->StartMoneyTextBox->Text);

			if (startMoney <= 0) throw gcnew System::Exception("Start money has to be bigger than 0.");

			this->Hide();
			GameForm^ gameForm = gcnew GameForm(startMoney);
			gameForm->Show();
		}
		catch (System::Exception^ e) {
			MessageBox::Show(e->Message);
		}
		
		return System::Void();
	}
}


