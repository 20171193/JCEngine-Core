#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

void OnIdle(Object^ sender, EventArgs^ e) {
	// todo : 본 루프 구현
}

[STAThreadAttribute]
int main(array<String^>^ args) {
	// 윈도우 스타일 설정
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	SandBox::MyForm^ mainForm = gcnew SandBox::MyForm();
	// 루프 등록
	Application::Idle += gcnew EventHandler(&OnIdle);

	// 폼 생성 및 실행
	Application::Run(mainForm);
	return 0;
}