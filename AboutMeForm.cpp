#include "AboutMeForm.h"

System::Void oczko::AboutMeForm::AboutMeForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if(e->KeyCode == Keys::Space)
		DialogResult = System::Windows::Forms::DialogResult::OK;
}
