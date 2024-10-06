#include "MenuForm.h"

using namespace oczko;

[STAThreadAttribute]
int main(array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MenuForm());
	return 0;
}