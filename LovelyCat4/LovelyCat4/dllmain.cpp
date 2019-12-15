// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "framework.h"
#include <Windows.h>
#include "resource.h"
#include "cat.h"
int DIALOG_SHOW = 0;
HMODULE _hModule;
CRITICAL_SECTION cs;
INT_PTR Dlgproc(
	HWND Arg1,
	UINT Arg2,
	WPARAM Arg3,
	LPARAM Arg4
)
{
	switch (Arg2)
	{
	case WM_INITDIALOG:
		DIALOG_SHOW = 1;
		break;
	case WM_COMMAND:
		//if (Arg3 == LOADJVM) {
		//	//mainV();
		//	MessageBox(NULL, "LOADJVM", "提示", 0);
		//}
		break;
	case WM_CLOSE:
		EndDialog(Arg1, 0);
		DIALOG_SHOW = 0;
		break;
	default:
		break;
	}
	return FALSE;
}

DWORD WINAPI ThreadProc(
	_In_ LPVOID lpParameter
);
DWORD WINAPI ThreadProc(_In_ LPVOID lpParameter)
{
	DialogBox(_hModule, MAKEINTRESOURCE(MAIN), NULL, (DLGPROC)Dlgproc);
	return 0;
}
BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		_hModule = hModule;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

