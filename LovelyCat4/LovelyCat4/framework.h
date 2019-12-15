#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容
// Windows 头文件
#include <windows.h>

extern CRITICAL_SECTION cs;
extern int DIALOG_SHOW;
extern HMODULE _hModule;
DWORD WINAPI ThreadProc(_In_ LPVOID lpParameter);
INT_PTR Dlgproc(
	HWND Arg1,
	UINT Arg2,
	WPARAM Arg3,
	LPARAM Arg4
);