#include "MyForm.h"
using namespace My7collections; // ��� �������.
[STAThreadAttribute]
int main(array<System::String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm()); // ��� �����.
	return 0;
}

