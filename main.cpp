#include <Windows.h>

//�E�B���h�E�v���V�[�W��
LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	//���b�Z�[�W�ɉ����ăQ�[���ŗL�̏������s��
	switch (msg)
	{
		//�E�B���h�E���j�����ꂽ
	case WM_DESTROY:
		//OS�ɑ΂��ăA�v���̏I����m�点��
		PostQuitMessage(0);
		return 0;
	}
	//�W���̃��b�Z�[�W�������s��
	return DefWindowProc(hwnd, msg, wparam, lparam);
}



//WINDOWS�A�v���ł��G���g���[�|�C���g
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//�R���\�[���ւ̕����o��
	OutputDebugStringA("Hello,DirectX!\n");

		const int window_width=1280;

		const int window_height=720;
	
		WNDCLASSEX w{};w.cbSize
		=
		sizeof(
			WNDCLASSEX
			);

	w.lpfnWndProc=(WNDPROC)WindowProc;
	
		w.lpszClassName	=L"DirectXGame";

		 w.hInstance=GetModuleHandle
		(
			nullptr
		);
	
		w.hCursor=LoadCursor
		(
			NULL,IDC_ARROW
		);
	
		RegisterClassEx(&w);
	
	RECT wrc={0,0,window_width,window_height};
	
		AdjustWindowRect(&wrc,WS_OVERLAPPEDWINDOW,false);







			HWND hwnd=CreateWindow
			(w.lpszClassName,L"DirectXGame",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,
				wrc.right-wrc.left,
			    wrc.bottom-wrc.top,
				nullptr	,
		
				nullptr,
				w.hInstance,nullptr
			);
			ShowWindow
			(
				hwnd,
				SW_SHOW
			);


	

	return 0;

}