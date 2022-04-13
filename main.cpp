#include <Windows.h>

//ウィンドウプロシージャ
LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	//メッセージに応じてゲーム固有の処理を行う
	switch (msg)
	{
		//ウィンドウが破棄された
	case WM_DESTROY:
		//OSに対してアプリの終了を知らせる
		PostQuitMessage(0);
		return 0;
	}
	//標準のメッセージ処理を行う
	return DefWindowProc(hwnd, msg, wparam, lparam);
}



//WINDOWSアプリでもエントリーポイント
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//コンソールへの文字出力
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