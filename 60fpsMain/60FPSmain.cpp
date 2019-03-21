//=============================================================================
// < __���O__ >
// 60FPS��Main���� [60FPSmain.cpp]
// Author : �� �F��
//
//=============================================================================
#include "60FPSmain.h"

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void Init(void);			// ������
void Uninit(void);			// �I������
void Update(void);			// �X�V����
void Draw(HWND hWnd);		// �`�揈��
void wait(void);			// �ҋ@

//*****************************************************************************
// �O���[�o���ϐ�:
//*****************************************************************************
bool msgLoop = true;

int fpsCnt = 0;

//=============================================================================
// ���C���֐�
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

	// �N���X�̓o�^
	if (!RegisterClassEx(&wcex))
	{
		return 1;
	}

	HWND hWnd;
	MSG msg;

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(CLASS_NAME,
		WINDOW_NAME,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,																			// �E�B���h�E�̍����W
		CW_USEDEFAULT,																			// �E�B���h�E�̏���W
		SCREEN_WIDTH + GetSystemMetrics(SM_CXDLGFRAME) * 2,										// �E�B���h�E����
		SCREEN_HEIGHT + GetSystemMetrics(SM_CXDLGFRAME) * 2 + GetSystemMetrics(SM_CYCAPTION),	// �E�B���h�E�c��
		NULL,
		NULL,
		hInstance,
		NULL);
	
	// ���Ԍv���p
	DWORD execLastTime;
	DWORD fpsLastTime;
	DWORD currentTime;
	DWORD frameCount;

	// �t���[���J�E���g������
	execLastTime = fpsLastTime = timeGetTime();	// �V�X�e���������~���b�P�ʂŎ擾
	currentTime = frameCount = 0;

	// �E�B���h�E�̕\��
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// ���b�Z�[�W���[�v
	while (msgLoop)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{// PostQuitMessage()���Ă΂ꂽ�烋�[�v�I��
				break;
			}
			else
			{
				// ���b�Z�[�W�̖|��ƃf�B�X�p�b�`
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			currentTime = timeGetTime();			// �V�X�e���������擾

			if ((currentTime - fpsLastTime) >= 500)	// 0.5�b���ƂɎ��s
			{
#ifdef _DEBUG
				fpsCnt = (frameCount * 1000) / (currentTime - fpsLastTime);	// FPS�𑪒�
#endif
				fpsLastTime = currentTime;	// FPS�𑪒肵��������ۑ�
				frameCount = 0;				// �J�E���g���N���A
			}

			if ((currentTime - execLastTime) >= (1000 / 60))	// 1/60�b���ƂɎ��s
			{
				execLastTime = currentTime;	// ��������������ۑ�

				Update();			// �X�V����
				Draw(hWnd);			// �`�揈��

				frameCount++;		// �����񐔂̃J�E���g�����Z
			}
		}
	}

	// �E�B���h�E�N���X�̓o�^������
	UnregisterClass(CLASS_NAME, wcex.hInstance);

	return (int)msg.wParam;
}

//=============================================================================
// �v���V�[�W��
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
// ������
//=============================================================================
void Init(void)
{

}

//=============================================================================
// �I������
//=============================================================================
void Uninit(void)
{

}

//=============================================================================
// �X�V����
//=============================================================================
void Update(void)
{
	{// 60FPS����



		//timeCnt++;
		return;
	}
}

//=============================================================================
// �`�揈��
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
// �ҋ@
//=============================================================================
void wait(void)
{

}
