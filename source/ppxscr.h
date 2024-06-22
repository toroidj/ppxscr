/*-----------------------------------------------------------------------------
	Paper Plane xUI  Script Module
-----------------------------------------------------------------------------*/
// TOROWIN.H, PPCOMMON.H は PPx のソースから流用する
#include "../../ppx/TOROWIN.H"
#include "../../ppx/PPCOMMON.H"
#define TOSTRMACRO(item)	#item

#define SCRIPTMODULEVER		21  // Release number
#define SCRIPTMODULEVERSTR	UNICODESTR(TOSTRMACRO(21))


#define DWORDPP 4294967296.	// 0x1 0000 0000 (DWORD で扱えない最少数)
#define __TLB_NO_INTERFACE_WRAPPERS

// BCC builder で余分な警告を出ないようにする定義。不都合有るなら除去が必要
#define __INC_CRTDBG
#define _ASSERTE_(str)

// Global Value
extern OSVERSIONINFO OSver;
extern const WCHAR NullStr[];
extern int UseJScript9; // JScript9.DLL を使用するか／Scriptのモード
//extern HINSTANCE hDllInstance;	// 現在ppxscr.cpp内で完結
//extern WCHAR DLLFileName[MAX_PATH];	// 現在ppxscr.cpp内で完結

class CScriptSite;
class CScriptBase;

typedef struct tagSITECHAIN {
	struct tagSITECHAIN *next;
	CScriptSite *site;
} SITECHAIN;

typedef struct {
	const WCHAR *param;
	WCHAR *resultstring;
	int count;
} ScriptArgs;

// Instance value(CScriptSite が管理)
typedef struct {
	PPXAPPINFOW *ppxa;
	IActiveScript *Engine;
	IActiveScriptParse *Parser;
	CScriptSite *Site;
	CScriptBase *Base;
	ScriptArgs arg; // PPXMCOMMANDSTRUCT
	WCHAR ScriptName[VFPS];
	// include 管理用
	int SourceIDserver; // IncludeNames 内の位置を示す ID を払い出すカウンタ
	WCHAR *IncludeNames; // include したソースの名前を記憶する \1 区切りの文字列

	struct {
		PPXAPPINFOW *ppxa; // 非アクティブ時に使用する ppxa 要 HeapFree
		HWND hWnd;
		SITECHAIN chain;
		#define ScriptStay_None		0
		#define ScriptStay_Cache	1
		#define ScriptStay_Stay		2
		// ID 0-9999 setting
		// ID 2000-999999999 user
		#define ScriptStay_FirstUserID 2000
		#define ScriptStay_FirstAutoID 0x40000000
		#define ScriptStay_MaxAutoID 0x7fffff00
		long mode;

		DWORD threadID;
		int entry; // 使用中カウンタ
	} stay;
	// 設定
	int IDNameMode; // 0: C_A  1: CA
	int Js9ForceCloseMode;
} InstanceValueStruct;

extern PPXAPPINFOW DummyPPxAppInfo;

// Function
extern STDMETHODIMP LoadTypeInfo(ITypeInfo** pptinfo, REFCLSID clsid, LCID lcid);
extern BOOL GetRegStringW(HKEY hKey, const WCHAR *path, const WCHAR *name, WCHAR *dest, DWORD size);
extern WCHAR *LoadScriptFile(const WCHAR *filename);
extern void PopupMessage(PPXAPPINFOW *ppxa, const WCHAR *message);
extern void PopupMessagef(PPXAPPINFOW *ppxa, const WCHAR *format, ...);

extern int ChainStayInstance(InstanceValueStruct *InstanceValue, int mode);
extern void DropStayInstance(InstanceValueStruct *InstanceValue);

#ifdef _WIN64
#define tprintfW wsprintfW
#define tvprintfW wvsprintfW
#else // Win9x で使用できる WCHAR 版 wsprintf サブセット
extern void tprintfW(WCHAR *message, const WCHAR *format, ...);
extern void tvprintfW(WCHAR *dest, const WCHAR *format, va_list argptr);
#endif

// IUnknown
#define T_IUNKNOWN_INITDEFINE() m_refCount = 0;

#define T_IUNKNOWN_ADDREFDEFINE(classname) \
STDMETHODIMP_(ULONG) classname::AddRef()\
{\
	return ++m_refCount;\
}

#define T_IUNKNOWN_RELEASEDEFINE(classname) \
STDMETHODIMP_(ULONG) classname::Release()\
{\
	if (--m_refCount == 0){\
		delete this;\
		return 0;\
	}\
	return m_refCount;\
}

#define T_IDISPATCH_RELEASEDEFINE(classname) \
STDMETHODIMP_(ULONG) classname::Release()\
{\
	if (--m_refCount == 0){\
		m_typeInfo->Release();\
		delete this;\
		return 0;\
	}\
	return m_refCount;\
}

#define T_IUNKNOWN_QUERYINTERFACEDEFINE(classname, checkriid) \
STDMETHODIMP classname::QueryInterface(REFIID riid, void **ppvObj)\
{\
	if ( (riid == IID_IUnknown) || checkriid ){\
		Debug_DispIID(CLASSNAMES "::QueryInterface - true:", riid);\
		*ppvObj = this;\
		AddRef();\
		return S_OK;\
	}\
	Debug_DispIID(CLASSNAMES "::QueryInterface - false:", riid);\
	*ppvObj = NULL;\
	return E_NOINTERFACE;\
}

// IDispatch
#define FixArgType(iArgs, type) \
	if ( pDispParams->rgvarg[iArgs].vt != type ){\
		hr = ::VariantChangeType(&pDispParams->rgvarg[iArgs],\
				&pDispParams->rgvarg[iArgs], 0, type);\
		if ( FAILED(hr) ){ arg = iArgs; goto ArgConvError;}\
	}

#define ArgsCheck(n) if ( pDispParams->cArgs != n ){\
		return DISP_E_BADPARAMCOUNT;\
	}

// Debug 用
#ifndef DEBUG
#define Debug_WriteLog(mesA, mesW)
#define Debug_DispIID(mes, riid)
#define Debug_InvokeUnknownDispIID(classname, dispIdMember, wFlags);
#else
extern BOOL Debug_WriteLog(const char *mesA, const WCHAR *mesW, ...);

extern void Debug_DispIID(const char *mesA, REFIID riid);
extern void Debug_InvokeUnknownDispIID(char *classname, DISPID dispIdMember, WORD wFlags);
#endif
