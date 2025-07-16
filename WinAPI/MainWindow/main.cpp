﻿#include<Windows.h>
#include<stdio.h>
#include"resource.h"

#define IDC_STATIC		1000
#define IDC_EDIT		1001
#define IDC_BUTTON		1002

CONST CHAR g_sz_CLASS_NAME[] = "My First Window";	//Абсолютно у любого класса окна есть имя.
								//Имя класса окна - это самая обычная строка.

INT WINAPI WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE pRevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	//1) Регистрация класса окна:
	WNDCLASSEX wClass;
	ZeroMemory(&wClass, sizeof(wClass));

	wClass.style = 0;
	wClass.cbSize = sizeof(wClass);	//cb - Count Bytes
	wClass.cbWndExtra = 0;
	wClass.cbClsExtra = 0;

	wClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_BITCOIN));
	wClass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_ATOM));	//Sm - Small
	//wClass.hIcon = (HICON)LoadImage(hInstance, "atom.ico", IMAGE_ICON, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE);
	//wClass.hIconSm = (HICON)LoadImage(hInstance, "bitcoin.ico", IMAGE_ICON, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE);
	//https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-loadimagea
	//wClass.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR1));
	wClass.hCursor = (HCURSOR)LoadImage
	(
		hInstance,
		"starcraft-original\\Working In Background.ani",
		IMAGE_CURSOR,
		256, 256,
		LR_LOADFROMFILE
	);

	wClass.hbrBackground = (HBRUSH)COLOR_WINDOW;

	wClass.hInstance = hInstance;
	wClass.lpfnWndProc = (WNDPROC)WndProc;
	wClass.lpszMenuName = NULL;
	wClass.lpszClassName = g_sz_CLASS_NAME;

	if (RegisterClassEx(&wClass) == NULL)
	{
		MessageBox(NULL, "Class registration failed", "", MB_OK | MB_ICONERROR);
		return 0;
	}

	//2) Создание окна:
	INT screen_width = GetSystemMetrics(SM_CXSCREEN);
	INT screen_height = GetSystemMetrics(SM_CYSCREEN);//https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getsystemmetrics#:~:text=The%20height%20of%20the%20screen%20of%20the%20primary%20display%20monitor%2C%20in%20pixels.%20This%20is%20the%20same%20value%20obtained%20by%20calling%20GetDeviceCaps%20as%20follows%3A%20GetDeviceCaps(%20hdcPrimaryMonitor%2C%20VERTRES).
	//https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getsystemmetrics
	INT window_width = screen_width * .75;
	INT window_height = screen_height * 3 / 4;
	INT window_start_x = screen_width / 8;
	INT window_start_y = screen_height / 8;
	HWND hwnd = CreateWindowEx
	(
		NULL,	//ExStyle
		g_sz_CLASS_NAME,	//ClassName
		g_sz_CLASS_NAME,	//WindowName (Title)
		WS_OVERLAPPEDWINDOW,//Такой стиль задается для всех главноых окон. 
							//Это окно будет родительским для других окон приложения.
		//WS_CHILD | WS_VISIBLE
		window_start_x, window_start_y,	//Position
		window_width, window_height,	//Size
		NULL,	//ParentWindow
		NULL,	//Строка меню для главного окна, или же ID_-ресурса для дочернего окна
		//IDOK, IDCANCEL........
		//ResourceID
		//HWND GetDlgItem()
		hInstance,	//Это экземпляр *.exe-файла нашей программы
		NULL
	);
	if (hwnd == NULL)
	{
		MessageBox(NULL, "Window creation failed", "", MB_OK | MB_ICONERROR);
		return 0;
	}
	ShowWindow(hwnd, nCmdShow);	//Задает режим отображения окна: Развернуто на весь экран, Свернуто в окно, свернуто на панель задач
	UpdateWindow(hwnd);	//Прорисовывает рабочую область окна

	//3) Запуск цикла сообщений:
	MSG msg;
	//08;
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		//Quit - Выход
		//Queue - Очередь
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	HWND_TOPMOST;
	return msg.wParam;
}

INT WINAPI WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		//A - ANSI ASCII
		//W - Wide encoding (Unicode - w_char_t)
#ifdef CHILDREN
		CreateWindowEx
		(
			NULL,
			"Static",
			"Этот StaticText создан при помощи функции CreateWindowEx().",
			//WS_-WindowStyle
			WS_CHILD | WS_VISIBLE,
			10, 10,
			550, 25,
			hwnd,
			(HMENU)IDC_STATIC,	//ResourceID
			GetModuleHandle(NULL),	//hInstance
			NULL
		);
		CreateWindowEx
		(
			NULL, "Edit", "",
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER,
			//ES_ - Edit Style
			10, 50,
			550, 22,
			hwnd,
			(HMENU)IDC_EDIT,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL, "Button", "Применить",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			450, 75,
			110, 25,
			hwnd,
			(HMENU)IDC_BUTTON,
			GetModuleHandle(NULL),
			NULL
		);
#endif // CHILDREN

		break;
	case WM_MOVE:
	case WM_SIZE:
	{
		RECT window_rect;	//Rectangle - Прямоугольник
		GetWindowRect(hwnd, &window_rect);
		INT window_width = window_rect.right - window_rect.left;
		INT window_height = window_rect.bottom - window_rect.top;
		CONST INT SIZE = 256;
		CHAR sz_title[SIZE] = {};
		sprintf
		(
			sz_title,
			"%s - Position:%ix%i, Size:%ix%i",
			g_sz_CLASS_NAME,
			window_rect.left, window_rect.top,
			window_width, window_height
		);
		SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)sz_title);
	}
	break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON:
		{
			HWND hEdit = GetDlgItem(hwnd, 1001);
			HWND hStatic = GetDlgItem(hwnd, 1000);
			CONST INT SIZE = 1024;
			CHAR sz_buffer[SIZE] = {};	//sz_ - String Zero (NULL-Terminate Line)
			SendMessage(hEdit, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)sz_buffer);
			SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)sz_buffer);
		}
		break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CLOSE:
		if (MessageBox(hwnd, "Вы действительно хотите закрыть окно", "Question", MB_YESNO | MB_ICONQUESTION) == IDYES)
			DestroyWindow(hwnd);
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return FALSE;
}