#include "MenuForm.h"

namespace oczko {
	void MenuForm::MenuForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
		MessageBox::Show("Form is Loaded");
	}
}