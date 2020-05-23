#include "MyForm.h"
using namespace Лаб33Калькулятор;
int Main()
{ 
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}
