#include "MyForm.h"
#include <windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>

using namespace System;
using namespace System::Windows::Forms;

HDC hDC;	// 윈도우 핸들
HGLRC hRC;	// OpenGL 컨텍스트 전역

void SetupOpenGL(HWND hWnd) {
	hDC = GetDC(hWnd);		// 디바이스 컨텍스트 할당

	// 픽셀 포맷 구조체 옵션
	PIXELFORMATDESCRIPTOR pfd = { 0 };
	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;

	// 상세 속성 (Quality Settings)
	pfd.dwFlags = PFD_DRAW_TO_WINDOW	// 메모리가 아닌 윈도우 창에 렌더링
		| PFD_SUPPORT_OPENGL			// OpenGL 명령어 지원
		| PFD_DOUBLEBUFFER;				// 더블 버퍼링 (깜빡임 방지)
	pfd.iPixelType = PFD_TYPE_RGBA;		// 색상 모델 : RGBA
	pfd.cColorBits = 32;				// 색상 표현 : 32bit
	pfd.cDepthBits = 24;				// Depth(Z) 버퍼 비트 : 24비트

	// 윈도우 포맷 설정
	int format = ChoosePixelFormat(hDC, &pfd);	
	SetPixelFormat(hDC, format, &pfd);

	// 그래픽 명령을 hDC의 RC에 적용
 	hRC = wglCreateContext(hDC);
	wglMakeCurrent(hDC, hRC);
}

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