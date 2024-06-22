/*-----------------------------------------------------------------------------
	Paper Plane xUI  Script Module				Main / PPxとのIF
-----------------------------------------------------------------------------*/
#define STRICT
#define _WIN32_DCOM
#include <windows.h>
#include <initguid.h>
#pragma hdrstop
#include <activscp.h>
#include "ppxscr.h"
#undef EXTDLL
#define EXTDLL
#include "PPxScr_TLB.h"
#include "IScriptBase.h"
#include "IScriptSite.h"

// Global Value
OSVERSIONINFO OSver;
HINSTANCE hDllInstance;
const WCHAR NullStr[1] = L"";
WCHAR DLLFileName[MAX_PATH];
int UseJScript9 = 0;
const WCHAR PPxScrTitle[] = L"PPxScr.dll";

long PPxVersion = 0; // 常駐機能有効の判断用
SITECHAIN StayChains = { NULL, NULL };
CRITICAL_SECTION StayLock;
DWORD StayInstanseIDserver = ScriptStay_FirstAutoID;

#define Chain_SiteChainObject(rootchain, chain, object) { (chain).site = (object); (chain).next = (rootchain).next; (rootchain).next = &(chain);}

typedef struct {
	PPXAPPINFOW* ppxa;
	ScriptArgs arg;
} OldPPxInfoStruct;

extern int RunScript(PPXAPPINFOW *ppxa, PPXMCOMMANDSTRUCT *pxc, const WCHAR *inline_type);
extern void FreeStayInstance(void);
extern PPXAPPINFOW DummyPPxAppInfo;

#ifdef __BORLANDC__
 BOOL WINAPI DllEntryPoint(HINSTANCE hInstance, unsigned long reason, void *)
#else
 BOOL APIENTRY DllMain(HINSTANCE hInstance, unsigned long reason, void *)
#endif
{
	if ( reason == DLL_PROCESS_ATTACH ){
		::hDllInstance = hInstance;
		::DLLFileName[0] = '\0';
	}else if ( reason == DLL_PROCESS_DETACH ){
		if ( PPxVersion != 0 ) DeleteCriticalSection(&StayLock);
	}
	return TRUE;
}

extern "C" EXTDLL int PPXAPI ModuleEntry(PPXAPPINFOW *ppxa, DWORD cmdID, PPXMODULEPARAM pxs)
{
	if ( (cmdID == PPXMEVENT_COMMAND) || (cmdID == PPXMEVENT_FUNCTION) ){
		switch ( pxs.command->commandhash ){
			case 0xc34c9454:
				if ( !::wcscmp(pxs.command->commandname, L"SCRIPT") ){
					return RunScript(ppxa, pxs.command, NULL);
				}
				break;

			case 0xd3251577:
				if ( !::wcscmp(pxs.command->commandname, L"SCRIPTW") ){
					return RunScript(ppxa, pxs.command, NULL);
				}
				break;

			case 0x800012d3:
				if ( !::wcscmp(pxs.command->commandname, L"JS") ){
					return RunScript(ppxa, pxs.command, L".js");
				}
				break;

			case 0x8004b4c3:
				if ( !::wcscmp(pxs.command->commandname, L"JSC") ){
					return RunScript(ppxa, pxs.command, L".jsc");
				}
				break;

			case 0x8004b4f9:
				if ( !::wcscmp(pxs.command->commandname, L"JS9") ){
					return RunScript(ppxa, pxs.command, L".js9");
				}
				break;

			case 0x800570d3:
				if ( !::wcscmp(pxs.command->commandname, L"VBS") ){
					return RunScript(ppxa, pxs.command, L".vbs");
				}
				break;
		}
		return PPXMRESULT_SKIP;
	}

	if ( cmdID == PPXMEVENT_CLEANUP ){
		// 1.97 以前は CleanUp 時に CoUninitialize() になってることがあるので無効に
		if ( PPxVersion > 19700 ) FreeStayInstance();
		return PPXMRESULT_DONE;
	}

	if ( cmdID == PPXMEVENT_CLOSETHREAD ){ // 1.97+1 から有効
		FreeStayInstance();
		return PPXMRESULT_DONE;
	}

	if ( cmdID == PPXM_INFORMATION ){
		if ( pxs.info->infotype == 0 ){
			pxs.info->typeflags = PPMTYPEFLAGS(PPXMEVENT_CLEANUP) |
					PPMTYPEFLAGS(PPXMEVENT_COMMAND) |
					PPMTYPEFLAGS(PPXMEVENT_FUNCTION);
			wcscpy(pxs.info->copyright, L"PPx Script Module R" SCRIPTMODULEVERSTR L"  Copyright (c)TORO");
			return PPXMRESULT_DONE;
		}
	}
	return PPXMRESULT_SKIP;
}

// 異常終了したときにリビジョンを表示させるためのダミーAPI
#define SCRVERNAMEAPI(Ver) SCRVERNAMEAPI2(Ver)
#define SCRVERNAMEAPI2(Ver) PPxScrR##Ver
extern "C" __declspec(dllexport) BOOL PPXAPI SCRVERNAMEAPI(SCRIPTMODULEVER)(void)
{
	return FALSE;
}

void InitModule(PPXAPPINFOW *ppxa)
{
	WCHAR bufw[CMDLINESIZE];

	::OSver.dwOSVersionInfoSize = sizeof(::OSver);
	::GetVersionEx(&::OSver);

	if ( ::OSver.dwPlatformId == VER_PLATFORM_WIN32_NT ){
		::GetModuleFileNameW(::hDllInstance, ::DLLFileName, MAX_PATH);
	}else{
		char filenameA[MAX_PATH];

		::GetModuleFileNameA(::hDllInstance, filenameA, MAX_PATH);
		AnsiToUnicode(filenameA, ::DLLFileName, MAX_PATH);
	}
//	memset(StayScripts, 0, sizeof(StayScripts));
//	::OleInitialize(NULL);

	wcscpy(bufw, L"%*getcust(_others:usejs9)");
	ppxa->Function(ppxa, PPXCMDID_EXTRACT, bufw);
	if ( bufw[0] >= '1' ) UseJScript9 = bufw[0] - '0';
}

void PopupMessage(PPXAPPINFOW *ppxa, const WCHAR *message)
{
	if ( (ppxa == NULL) ||
		 (ppxa->Function == NULL) ||
		 (ppxa->Function(ppxa, PPXCMDID_MESSAGE, (void *)message) == 0) ){
		HWND hWnd = (ppxa == NULL) ? NULL : ppxa->hWnd;
		MessageBoxW(hWnd, message, PPxScrTitle, MB_OK);
	}
}
#ifndef _WIN64
void tvprintfW(WCHAR *dest, const WCHAR *format, va_list argptr)
{
	WCHAR *message = dest, chr;
	for(;;){
		if ( dest >= (message + 1024 - 2) ) break;
		chr = *format;
		if ( chr == '\0' ) break;
		if ( chr == '%' ){
			chr = *(++format);
			if ( chr == 's' ){
				WCHAR *param;
				format++;
				param = va_arg(argptr, WCHAR *);
				if ( param != NULL ) for(;;){
					if ( dest >= (message + 1024 - 2) ) break;
					chr = *param;
					if ( chr == '\0' ) break;
					*dest++ = chr;
					param++;
				}
				continue;
			}else if ( (chr == 'd') || (chr == 'u') ){
				DWORD value;
				WCHAR tmp[16], *tmpp;

				tmpp = tmp;
				format++;
				value = va_arg(argptr, DWORD);
				if ( (value & B31) && (chr == 'd') ){
					*dest++ = '-';
					value = 0 - value;
				}
				for(;;){
					chr = value % 10;
					*tmpp++ = chr + '0';
					value /= 10;
					if ( value == 0 ) break;
				}
				for(;;){
					if ( tmpp == tmp ) break;
					*dest++ = *(--tmpp);
				}
				continue;
			}else{
				va_arg(argptr, void *);
			}
		}
		*dest++ = chr;
		format++;
	}
	*dest = '\0';
}

void tprintfW(WCHAR *message, const WCHAR *format, ...)
{
	va_list argptr;
#if 0
	va_start(argptr, format);
	wvsprintfW(message, format, argptr);
	va_end(argptr);
	message[1024] = '\0';
#else
	va_start(argptr, format);
	tvprintfW(message, format, argptr);
	va_end(argptr);
#endif
}
#endif

void PopupMessagef(PPXAPPINFOW *ppxa, const WCHAR *format, ...)
{
	WCHAR message[1024 + 16];
	va_list argptr;
#if 0
	va_start(argptr, format);
	wvsprintfW(message, format, argptr);
	va_end(argptr);
	message[1024] = '\0';
#else
	va_start(argptr, format);
	tvprintfW(message, format, argptr);
	va_end(argptr);
#endif
	PopupMessage(ppxa, message);
}


DWORD_PTR USECDECL DummyPPxFunc(PPXAPPINFOW *, DWORD , void *)
{
	return PPXA_INVALID_FUNCTION;
}

PPXAPPINFOW DummyPPxAppInfo = { DummyPPxFunc, L"", L"", NULL };
#if 0
PPXMCOMMANDSTRUCT DummyPxc =
#ifndef _WIN64
	{L"", L"", 0, 0, NULL};
#else
	{L"", NULL, L"", 0, 0};
#endif
#endif

void SleepStayInstance(InstanceValueStruct *info, OldPPxInfoStruct *OldInfo)
{
	// appinfo が使えない状態で使われた時用のダミーを設定する。
	info->ppxa = OldInfo->ppxa; // info->stay.ppxa;
	info->arg = OldInfo->arg;
	info->stay.entry--;
	info->Base->UpdatePPxInfo();
//	PPxScript->InstanceValue.pxc = &DummyPxc;
}

// 常駐登録
int ChainStayInstance(InstanceValueStruct *InstanceValue, int mode)
{
	PPXAPPINFOW *ppxa;

	// 情報用意
	ppxa = InstanceValue->ppxa;
	InstanceValue->stay.threadID = GetCurrentThreadId();
	if ( PPxVersion == 0 ){
		InitializeCriticalSection(&StayLock);
		PPxVersion = static_cast<long>(ppxa->Function(ppxa, PPXCMDID_VERSION, NULL));
	}
	InstanceValue->stay.hWnd = ppxa->hWnd;

	// 登録
	EnterCriticalSection(&StayLock);

	if ( mode == ScriptStay_Stay ){
		mode = StayInstanseIDserver++;
		if ( mode >= ScriptStay_MaxAutoID ){
			StayInstanseIDserver = ScriptStay_FirstAutoID;
		}
	}

	Chain_SiteChainObject(StayChains, InstanceValue->stay.chain, InstanceValue->Site);
	LeaveCriticalSection(&StayLock);

	// 通知を有効に
	ppxa->Function(ppxa, PPXCMDID_REQUIRE_CLOSETHREAD, 0);
	return mode;
}

// 常駐解除
void DropStayInstance(InstanceValueStruct *InstanceValue)
{
	SITECHAIN *thischain = &InstanceValue->stay.chain;
	SITECHAIN *chain = &StayChains;
	SITECHAIN *nextchain;

	EnterCriticalSection(&StayLock);
	for(;;){
		nextchain = chain->next;
		if ( nextchain == NULL ) break;
		if ( nextchain == thischain ){
			chain->next = nextchain->next;
			break;
		}
		chain = nextchain;
	}
	InstanceValue->stay.threadID = 0;
	LeaveCriticalSection(&StayLock);
}

// １度目の常駐時の終了
void FirstStayInstance(CScriptSite *PPxScript)
{
	OldPPxInfoStruct OldInfo;

	if ( PPxScript->InstanceValue.stay.ppxa == NULL ){
		PPXCMDID_NEWAPPINFO_STRUCT pns = {0, 0, NULL, NULL};
		PPXAPPINFOW *ppxa = PPxScript->InstanceValue.ppxa;

		DWORD_PTR stayppxa = ppxa->Function(ppxa, PPXCMDID_NEWAPPINFO, &pns);
		if ( stayppxa != PPXA_INVALID_FUNCTION ){
			PPxScript->InstanceValue.stay.ppxa = (PPXAPPINFOW *)stayppxa;
		}
	}
	OldInfo.ppxa = (PPxScript->InstanceValue.stay.ppxa != NULL) ?
					PPxScript->InstanceValue.stay.ppxa : &DummyPPxAppInfo;
	OldInfo.arg.param = L"";
	OldInfo.arg.count = 0;
	OldInfo.arg.resultstring = NULL;
	SleepStayInstance(&PPxScript->InstanceValue, &OldInfo);
}

// 同じスレッドの常駐解放
void FreeStayInstance(void)
{
	CScriptSite *PPxScript;
	DWORD ThreadID = GetCurrentThreadId();
	SITECHAIN *chain = &StayChains, *nextchain;

	for(;;){
		nextchain = chain->next;
		if ( nextchain == NULL ) break;

		PPxScript = nextchain->site;
		if ( PPxScript->InstanceValue.stay.threadID == ThreadID ){
			chain->next = nextchain->next; // drop

			PPxScript->InstanceValue.ppxa = &DummyPPxAppInfo; // info->stay.ppxa;
			PPxScript->InstanceValue.arg.count = 0;
			PPxScript->InstanceValue.arg.resultstring = NULL;
			PPxScript->InvokeScript(L"ppx_finally", NULL, 0);
			PPxScript->QuitScript(); // ここで時間が掛かっている
			PPxScript->Release();
			chain = &StayChains;
			continue;
		}
		chain = nextchain;
	}
}

void CleanUpModule(void)
{
	if ( ::DLLFileName[0] == '\0' ) return;
	// 1.97 以前は CleanUp 時に CoUninitialize() になってることがあるので無効に
	if ( PPxVersion > 19700 ) FreeStayInstance();
//	::OleUninitialize();
	::DLLFileName[0] = '\0'; // 念のため
}

int GetIntNumberW(const WCHAR *line)
{
	int n = 0;

	for ( ;; ){
		WCHAR code;

		code = *line;
		if ( (code < '0') || (code > '9') ) break;
		n = n * 10 + (WCHAR)((BYTE)code - (BYTE)'0');
		line++;
	}
	return n;
}

BOOL RunStayScript(PPXAPPINFOW *ppxa, PPXMCOMMANDSTRUCT *pxc, int StayMode, WCHAR *InvokeName, const WCHAR *inline_type)
{
	CScriptSite *PPxScript;
	SITECHAIN *chain = &StayChains, *nextchain;
	DWORD ThreadID = GetCurrentThreadId();
	HWND hWnd = ppxa->hWnd;
	const WCHAR *source = pxc->param;

	EnterCriticalSection(&StayLock);
	for(;;){
		nextchain = chain->next;
		if ( nextchain == NULL ){
			LeaveCriticalSection(&StayLock);
			return FALSE;
		}
		PPxScript = nextchain->site;

		if ( (PPxScript->InstanceValue.stay.threadID == ThreadID) &&
			 ((StayMode >= ScriptStay_Stay) ?
			   (PPxScript->InstanceValue.stay.mode == StayMode) :
			   ((PPxScript->InstanceValue.stay.hWnd == hWnd) &&
				(wcscmp(PPxScript->InstanceValue.ScriptName, source) == 0))) ){
			break;
		}
		chain = nextchain;
	}
	LeaveCriticalSection(&StayLock);

	HRESULT result;
	const WCHAR *param = pxc->param;
	int paramcount = pxc->paramcount;
	OldPPxInfoStruct OldInfo;

	OldInfo.ppxa = PPxScript->InstanceValue.ppxa;
	OldInfo.arg = PPxScript->InstanceValue.arg;
	PPxScript->InstanceValue.stay.entry++;
	PPxScript->InstanceValue.ppxa = ppxa;
	PPxScript->InstanceValue.arg.resultstring = pxc->resultstring;

	if ( InvokeName[0] == '\0' ){ // メソッド指定が無い
		if ( (StayMode < ScriptStay_Stay) || (paramcount == 0) || (param[0] == '\0') ){
			// 例 *script "filename" / *js "script"
				// インスタンス指定が無いなら ppx_resume
			InvokeName = L"ppx_resume";
		}else{	// インスタンス指定あり & １以上パラメータ なら eval
			if ( inline_type == NULL ){
				// 例 *script ":123", "filename"
				WCHAR *ScriptImage = LoadScriptFile(param);
				if ( ScriptImage == NULL ){
					::PopupMessagef(ppxa, L"%s open error", param);
					result = E_FAIL;
				}else{
					PPxScript->EvalScript(ScriptImage);
					delete[] ScriptImage;
					result = S_OK;
				}
			}else{
				// 例 *js ":123", "script"
				PPxScript->EvalScript(param);
				result = S_OK;
			}
		}
		if ( paramcount > 0 ){
			param += wcslen(param) + 1; // source をスキップ
			paramcount--;
		}
	}else{
		// インスタンス指定無し & メソッド指定あり のときは、source 必須
		// 例 *script ":func","filename"  /  *js ":func","script"
		if ( (StayMode < ScriptStay_Stay) && (paramcount > 0) ){
			param += wcslen(param) + 1; // source をスキップ
			paramcount--;
		}
	}

	if ( InvokeName[0] != '\0' ){
		result = PPxScript->InvokeScript(InvokeName, param, paramcount);
	}
	if ( result == DISP_E_UNKNOWNNAME ){
		::PopupMessagef(ppxa, L"%s() not found", InvokeName);
	}else if ( FAILED(result) ){
		::PopupMessagef(ppxa, L"Invoke error %s(), code:%x", InvokeName, result);
	}

	if ( PPxScript->InstanceValue.stay.mode < ScriptStay_Stay ){
		PPxScript->InstanceValue.stay.entry--;
		if ( PPxScript->InstanceValue.stay.entry <= 0 ){
			PPxScript->QuitScript();
			PPxScript->Release();
		}
	}else{
		SleepStayInstance(&PPxScript->InstanceValue, &OldInfo);
	}
	return TRUE;
}

void CheckOption(PPXMCOMMANDSTRUCT *pxc, int *StayMode, WCHAR *InvokeName)
{
	WCHAR buf[256], *dest;

	pxc->param++;
	for (;;){
		dest = buf;
		for (;;){
			if ( *pxc->param == '\0' ) break;
			*dest++ = *pxc->param++;
			if ( *pxc->param != ',' ) continue;
			pxc->param++;
			break;
		}
		*dest = '\0';
		if ( buf[0] == '\0' ) break;
		if ( (buf[0] >= '0') && (buf[0] <= '9') ){
			*StayMode = GetIntNumberW(buf);
		}else{
			wcscpy(InvokeName, buf);
		}
	}
	pxc->param += wcslen(pxc->param) + 1; // ":～" をスキップ
	pxc->paramcount--;
}


int RunScript(PPXAPPINFOW *ppxa, PPXMCOMMANDSTRUCT *pxc, const WCHAR *inline_type)
{
	int result;
	CScriptSite *PPxScript;
	PPXMCOMMANDSTRUCT pxcbuf;
	int StayMode = ScriptStay_None;
	WCHAR InvokeName[256];

	InvokeName[0] = '\0';
	if ( (pxc->paramcount > 0) && (pxc->param[0] == ':') ){
		pxcbuf = *pxc;
		pxc = &pxcbuf;
		CheckOption(pxc, &StayMode, InvokeName);
	}

	if ( StayChains.next != NULL ){
		if ( RunStayScript(ppxa, pxc, StayMode, InvokeName, inline_type) ){
			return PPXMRESULT_DONE;
		}
	}
	if ( InvokeName[0] != '\0' ){
		::PopupMessage(ppxa, L"instance not found");
		return PPXMRESULT_STOP;
	}
	if ( pxc->paramcount == 0 ){
		::PopupMessage(ppxa, L"no source parameter");
		return PPXMRESULT_STOP;
	}

	if ( ::DLLFileName[0] == '\0' ) InitModule(ppxa);

	// 新規scriptを実行
	// ※ PPb/c/v/cust/tray ではCOM初期化済み
	PPxScript = new CScriptSite(ppxa);
	PPxScript->AddRef();
	result = PPxScript->InitializeScriptSite(pxc, inline_type, StayMode);
	if ( result == PPXMRESULT_DONE ){
		result = PPxScript->RunScript();
		if ( PPxScript->InstanceValue.stay.mode >= ScriptStay_Stay ){
			// ※ここで２回目実行は起きない
			FirstStayInstance(PPxScript);
			return result;
		}
		PPxScript->QuitScript();
	}
	PPxScript->InstanceValue.stay.entry--;
	PPxScript->Release();
	return result;
}

STDMETHODIMP LoadTypeInfo(ITypeInfo** pptinfo, REFCLSID clsid, LCID lcid)
{
	HRESULT hr;
	LPTYPELIB ptlib = NULL;
	LPTYPEINFO ptinfo = NULL;
	*pptinfo = NULL;
										// 一般のタイプライブラリ
	hr = ::LoadRegTypeLib(LIBID_PPxScr, 2, 0, lcid, &ptlib);
	if ( FAILED(hr) ){					// 内蔵のタイプライブラリ
		hr = ::LoadTypeLib(DLLFileName, &ptlib);
		if ( FAILED(hr) ) return hr;	// 何処にもなかった
	}
	hr = ptlib->GetTypeInfoOfGuid(clsid, &ptinfo);
	if ( FAILED(hr) ){
		ptlib->Release();
		return hr;
	}
	ptlib->Release();
	*pptinfo = ptinfo;
	return S_OK;
}

// レジストリから文字列を得る -------------------------------------------------
// ※ path と dest が同じ変数でも問題無い
BOOL GetRegStringW(HKEY hKey, const WCHAR *path, const WCHAR *name, WCHAR *dest, DWORD size)
{
	HKEY HK;
	DWORD t, s;

	if ( ::OSver.dwPlatformId == VER_PLATFORM_WIN32_NT ){
		if ( ::RegOpenKeyExW(hKey, path, 0, KEY_READ, &HK) == ERROR_SUCCESS ){
			s = size;
			if (::RegQueryValueExW(HK, name, NULL, &t, (LPBYTE)dest, &s)
					== ERROR_SUCCESS){
				::RegCloseKey(HK);
				return TRUE;
			}
			::RegCloseKey(HK);
		}
	}else{
		char in[MAX_PATH], out[MAX_PATH];

		UnicodeToAnsi(path, in, MAX_PATH);
		if ( ::RegOpenKeyExA(hKey, in, 0, KEY_READ, &HK) == ERROR_SUCCESS ){
			UnicodeToAnsi(name, in, MAX_PATH);
			s = size;
			if ( ::RegQueryValueExA(HK, in, NULL, &t,
					(LPBYTE)out, &s) == ERROR_SUCCESS){
				AnsiToUnicode(out, dest, MAX_PATH);
				::RegCloseKey(HK);
				return TRUE;
			}
			::RegCloseKey(HK);
		}
	}
	return FALSE;
}

#ifdef DEBUG
BOOL Debug_WriteLog(const char *mesA, const WCHAR *mesW, ...)
{
	WCHAR bufW[0x1000];
	char buf[0x1000];
	DWORD size;
	SYSTEMTIME ltime;
	HANDLE hFile;

	::GetModuleFileName(NULL, buf, sizeof(buf));
	strcpy(strrchr(buf, '\\'), "\\SCR.LOG");
												// log を開く -----------------
	hFile = ::CreateFile(buf, GENERIC_WRITE, FILE_SHARE_READ, NULL,
			OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if ( hFile == INVALID_HANDLE_VALUE ) return FALSE;
												// 末尾に移動 -----------------
	size = 0;
	::SetFilePointer(hFile, 0, (PLONG)&size, FILE_END);
												// 時刻を出力 -----------------
	::GetLocalTime(&ltime);
	size = ::wsprintf(buf, "%4d-%2d-%2d %2d:%02d:%02d\t",
			ltime.wYear, ltime.wMonth, ltime.wDay,
			ltime.wHour, ltime.wMinute, ltime.wSecond);
	::WriteFile(hFile, buf, size, &size, NULL);
												// 内容を出力 -----------------
	if ( mesA != NULL ){
		size = strlen(mesA);
		if ( size ) ::WriteFile(hFile, mesA, size, &size, NULL);
	}
	if ( mesW != NULL ){
		va_list argptr;

		va_start(argptr, mesW);
		tvprintfW(bufW, mesW, argptr);
		va_end(argptr);

		size = wcslen(bufW);
		if ( size ){
			UnicodeToAnsi(bufW, buf, sizeof(buf));
			::WriteFile(hFile, buf, strlen(buf), &size, NULL);
		}
	}
	::WriteFile(hFile, "\r\n", 2, &size, NULL);
	::CloseHandle(hFile);
	return TRUE;
}

void Debug_DispIID(const char *mesA, REFIID riid)
{
	WCHAR *iidstring, path[MAX_PATH], name[MAX_PATH];

	StringFromIID(riid, &iidstring);
	tprintfW(path, L"Interface\\%s", iidstring);
	CoTaskMemFree(iidstring);
	if ( GetRegStringW(HKEY_CLASSES_ROOT, path, ::NullStr, name, sizeof(name)) ){
		Debug_WriteLog(mesA, name);
	}else{
		Debug_WriteLog(mesA, path);
	}
}

void Debug_InvokeUnknownDispIID(char *classname, DISPID dispIdMember, WORD wFlags)
{
	char buf[150];

	wsprintf(buf, "%s::Invoke-Unknown ID-%d(%c%c%c)", classname, dispIdMember,
		((wFlags & DISPATCH_METHOD) ? 'M' : ' '),
		((wFlags & DISPATCH_PROPERTYGET) ? 'G' : ' '),
		((wFlags & DISPATCH_PROPERTYPUT) ? 'P' : ' ')
	);
}
#endif

WCHAR *LoadScriptFile(const WCHAR *filename)
{
	HANDLE hFile;
	DWORD sizeL;		// ファイルの大きさ
	int margin = 32;
	char *TextImageA;
	WCHAR *TextImageW;

#ifdef _WIN64										// ファイルを開く
	hFile = ::CreateFileW(filename, GENERIC_READ,
			FILE_SHARE_WRITE | FILE_SHARE_READ,
			NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
#else
	if ( ::OSver.dwPlatformId == VER_PLATFORM_WIN32_NT ){
		hFile = ::CreateFileW(filename, GENERIC_READ,
				FILE_SHARE_WRITE | FILE_SHARE_READ,
				NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	} else{
		char paramA[MAX_PATH];

		UnicodeToAnsi(filename, paramA, MAX_PATH);
		hFile = ::CreateFileA(paramA, GENERIC_READ,
				FILE_SHARE_WRITE | FILE_SHARE_READ,
				NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	}
#endif
	if ( hFile == INVALID_HANDLE_VALUE ) return NULL;

										// ファイルサイズの確認 ---------------
	sizeL = ::GetFileSize(hFile, NULL);
										// 読み込み準備 -----------------------
	TextImageA = new char[sizeL + margin];
	if ( TextImageA == NULL ){
		::CloseHandle(hFile);
		return NULL;
	}
										// 読み込み & 0 padding ---------------
	if ( FALSE == ::ReadFile(hFile, TextImageA, sizeL, &sizeL, NULL) ){
		sizeL = 0;
	}
	::CloseHandle(hFile);
	::memset(TextImageA + sizeL, 0, margin);

	if ( memcmp(TextImageA, UTF8HEADER, UTF8HEADERSIZE) == 0 ){ // UTF-8
		sizeL = ::MultiByteToWideChar(CP_UTF8, 0, TextImageA + UTF8HEADERSIZE, -1, NULL, 0);
		TextImageW = new WCHAR[sizeL];
		::MultiByteToWideChar(CP_UTF8, 0, TextImageA + UTF8HEADERSIZE, -1, TextImageW, sizeL);
	} else{ // ANSI
		sizeL = ::MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, TextImageA, -1, 0, 0) + 1;
		TextImageW = new WCHAR[sizeL];
		::MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, TextImageA, -1, TextImageW, sizeL);
	}
	delete[] TextImageA;
	return TextImageW;
}
