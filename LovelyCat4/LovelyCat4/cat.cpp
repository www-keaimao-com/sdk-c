//#define _CRT_SECURE_NO_WARNINGS
#include "framework.h"
#include <stdio.h>
#include <stdlib.h>
#include <atlstr.h>
#include "cat.h"
#include "resource.h"
#include <jni.h>
int AutoCode;
typedef int(_stdcall* Api_Initialize)(int, char*);
typedef void(_stdcall* Api_AppendLogs)(int, char*);

typedef int(_stdcall* _JNI_CreateJavaVM)(JavaVM** pvm, void** penv, void* args);

HMODULE coupler = LoadLibrary("coupler.dll");

int Cat_Initialize(char* json, int session) {
	Api_Initialize _Api_Initialize = NULL;
	if (coupler != NULL) {
		_Api_Initialize = (Api_Initialize)GetProcAddress(coupler, "Api_Initialize");
	}
	if (_Api_Initialize != NULL) {
		return _Api_Initialize(session, json);
	}
	else {
	}
	return -1;
}
void Cat_AppendLogs(int Code, char * msg) {
	Api_AppendLogs _Api_AppendLogs = NULL;
	if (coupler != NULL) {
		_Api_AppendLogs = (Api_AppendLogs)GetProcAddress(coupler, "Api_AppendLogs");
	}
	if (_Api_AppendLogs != NULL) {
		return _Api_AppendLogs(AutoCode, msg);
	}
	else {
	}
	return;
}


int __stdcall LoadingInfo(int lApiString) {
	HRSRC h = FindResource(_hModule, MAKEINTRESOURCE(IDR_TXT1), "TXT");
	if (h != 0) {
		DWORD size = SizeofResource(NULL, h);
		HGLOBAL hbl = LoadResource(_hModule, h);
		if (hbl != 0) {
			LPVOID fid2 = LockResource(hbl);
			if (fid2 != NULL) {
				//MessageBox(NULL, (char*)fid2, "资源文件里获取的内容", 0);
				AutoCode = Cat_Initialize((char*)fid2, lApiString);
				Cat_AppendLogs(AutoCode, (char*)fid2);
			}
		}
	}
	Cat_AppendLogs(AutoCode, "LoadingInfo 事件...");
	//startThread();
	
	return AutoCode;
}


int __stdcall EventInit() {
	//startThread();
	Cat_AppendLogs(AutoCode, "EventInit 事件...");
	return 0;
}


int __stdcall EventEnable() {
	// TODO Auto-generated method stub
	return 0;
}


int __stdcall EventStop() {
	// TODO Auto-generated method stub
	return 0;
}


int __stdcall EventLogin() {
	// TODO Auto-generated method stub
	return 0;
}


int __stdcall EventGroupMsg(char* robot_wxid, int type, char* from_wxid, char* from_name, char* final_from_wxid,
	char* final_from_name, char* to_wxid, char* msg) {
	// TODO Auto-generated method stub
	return 0;
}


int __stdcall EventFriendMsg(char* robot_wxid, int type, char* from_wxid, char* from_name, char* to_wxid,
	char* msg) {
	// TODO Auto-generated method stub
	return 0;
}


int __stdcall EventReceivedTransfer(char* robot_wxid, char* from_wxid, char* from_name, char* to_wxid,
	char* money, char* json_msg) {
	// TODO Auto-generated method stub
	return 0;
}


int __stdcall EventScanCashMoney(char* robot_wxid, char* pay_wxid, char* pay_name, char* money, char* json_msg) {
	// TODO Auto-generated method stub
	return 0;
}


int __stdcall EventFriendVerify(char* robot_wxid, char* from_wxid, char* from_name, char* to_wxid,
	char* json_msg) {
	// TODO Auto-generated method stub
	return 0;
}


int __stdcall EventContactsChange(char* robot_wxid, int type, char* from_wxid, char* from_name, char* msg) {
	// TODO Auto-generated method stub
	return 0;
}


int __stdcall EventGroupMemberAdd(char* robot_wxid, char* from_wxid, char* from_name, char* json_msg) {
	// TODO Auto-generated method stub
	return 0;
}


int __stdcall EventGroupMemberDecrease(char* robot_wxid, char* from_wxid, char* from_name, char* json_msg) {
	// TODO Auto-generated method stub
	return 0;
}


int __stdcall EventSysMsg(char* robot_wxid, int type, char* json_msg) {
	// TODO Auto-generated method stub
	return 0;
}


void __stdcall Menu() {
	// TODO Auto-generated method stub
	if (!DIALOG_SHOW) {
		CreateThread(NULL, 0, LPTHREAD_START_ROUTINE(ThreadProc), _hModule, NULL, NULL);
	}
	
}
