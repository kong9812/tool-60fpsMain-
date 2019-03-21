//=============================================================================
// < __名前__ >
// 60FPSのMain処理 [60FPSmain.cpp]
// Author : 蔡 友剛
//
//=============================================================================
#include "60FPSmain.h"

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void Init(void);			// 初期化
void Uninit(void);			// 終了処理
void Update(void);			// 更新処理
void Draw(HWND hWnd);		// 描画処理
void wait(void);			// 待機

//*****************************************************************************
// グローバル変数:
//*****************************************************************************
bool msgLoop = true;

int fpsCnt = 0;

//=============================================================================
// メイン関数
//=============================================================================
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX	wcex = {
		sizeof(WNDCLASSEX),
		CS_CLASSDC,
		WndProc,
		0,
		0,
		hInstance,
		NULL,
		LoadCursor(NULL, IDC_ARROW),
		(HBRUSH)(COLOR_WINDOW + 5),
		NULL,
		CLASS_NAME,
		NULL
	};

	// クラスの登録
	if (!RegisterClassEx(&wcex))
	{
		return 1;
	}

	HWND hWnd;
	MSG msg;

	// ウィンドウの作成
	hWnd = CreateWindow(CLASS_NAME,
		WINDOW_NAME,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,																			// ウィンドウの左座標
		CW_USEDEFAULT,																			// ウィンドウの上座標
		SCREEN_WIDTH + GetSystemMetrics(SM_CXDLGFRAME) * 2,										// ウィンドウ横幅
		SCREEN_HEIGHT + GetSystemMetrics(SM_CXDLGFRAME) * 2 + GetSystemMetrics(SM_CYCAPTION),	// ウィンドウ縦幅
		NULL,
		NULL,
		hInstance,
		NULL);
	
	// 時間計測用
	DWORD execLastTime;
	DWORD fpsLastTime;
	DWORD currentTime;
	DWORD frameCount;

	// フレームカウント初期化
	execLastTime = fpsLastTime = timeGetTime();	// システム時刻をミリ秒単位で取得
	currentTime = frameCount = 0;

	// ウィンドウの表示
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// メッセージループ
	while (msgLoop)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{// PostQuitMessage()が呼ばれたらループ終了
				break;
			}
			else
			{
				// メッセージの翻訳とディスパッチ
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			currentTime = timeGetTime();			// システム時刻を取得

			if ((currentTime - fpsLastTime) >= 500)	// 0.5秒ごとに実行
			{
#ifdef _DEBUG
				fpsCnt = (frameCount * 1000) / (currentTime - fpsLastTime);	// FPSを測定
#endif
				fpsLastTime = currentTime;	// FPSを測定した時刻を保存
				frameCount = 0;				// カウントをクリア
			}

			if ((currentTime - execLastTime) >= (1000 / 60))	// 1/60秒ごとに実行
			{
				execLastTime = currentTime;	// 処理した時刻を保存

				Update();			// 更新処理
				Draw(hWnd);			// 描画処理

				frameCount++;		// 処理回数のカウントを加算
			}
		}
	}

	// ウィンドウクラスの登録を解除
	UnregisterClass(CLASS_NAME, wcex.hInstance);

	return (int)msg.wParam;
}

//=============================================================================
// プロシージャ
//=============================================================================
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

//=============================================================================
// 初期化
//=============================================================================
void Init(void)
{

}

//=============================================================================
// 終了処理
//=============================================================================
void Uninit(void)
{

}

//=============================================================================
// 更新処理
//=============================================================================
void Update(void)
{
	{// 60FPS処理



		//timeCnt++;
		return;
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void Draw(HWND hWnd)
{
	HDC hdc = GetDC(hWnd);
	char str[CHAR_MAX];
	sprintf(str, "%s%d","fps:", fpsCnt);
	TextOut(hdc, 0, 0, (LPTSTR)str, lstrlen(str));
	ReleaseDC(hWnd, hdc);
}

//=============================================================================
// 待機
//=============================================================================
void wait(void)
{

}
