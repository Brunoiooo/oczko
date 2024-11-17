#include "MenuForm.h"
#include "Core.hpp"

#include <iostream>

using namespace oczko;
using namespace std;

[STAThreadAttribute]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MenuForm());
	return 0;
}