/*-----------------------------------------------------------------------------
	Paper Plane xUI  Script Module IScriptSite(Script HostエンジンとのIFを担当)
-----------------------------------------------------------------------------*/
#define  STRICT
#include <windows.h>
#include <activscp.h>
#include "ppxscr.h"
#pragma hdrstop
#include "PPxScr_TLB.h"
#include "IArguments.h"
#include "IEntry.h"
#include "IScriptBase.h"
#include "IScriptSite.h"

#define CLASSNAME CScriptSite
#define CLASSNAMES "CScriptSite"

const CLSID CLSID_JScript9 = { 0x16D51579, 0xA30B, 0x4C8B, {0xA2, 0x76, 0x0F, 0xF4, 0xDC, 0x41, 0xE7, 0x55} };
const CLSID CLSID_Chakra = { 0x1B7CD997, 0xE5FF, 0x4932, {0xA7, 0xA6, 0x2A, 0x9E, 0x63, 0x6D, 0xA3, 0x85} };

#ifndef SCRIPTPROP_INVOKEVERSIONING
#define SCRIPTPROP_INVOKEVERSIONING 0x00004000
#define SCRIPTLANGUAGEVERSION_5_8 2
#endif
#define SCRIPTLANGUAGEVERSION_ECMA5 (SCRIPTLANGUAGEVERSION_5_8 + 1)
#define SCRIPTLANGUAGEVERSION_CHAKRA (SCRIPTLANGUAGEVERSION_5_8 + 2)

int UsedJSEngine = -1;

CScriptSite::CScriptSite(PPXAPPINFOW *ppxaorg)
{
	T_IUNKNOWN_INITDEFINE();
	m_ScriptImage = NULL;

	InstanceValue.ppxa = ppxaorg;
	InstanceValue.Site = this;
	InstanceValue.Base = NULL;
	InstanceValue.Engine = NULL;
	InstanceValue.Parser = NULL;

	InstanceValue.SourceIDserver = 0;
	InstanceValue.IncludeNames = NULL;
	InstanceValue.stay.mode = ScriptStay_None;
	InstanceValue.stay.threadID = NULL;
	InstanceValue.stay.entry = 0;
	InstanceValue.stay.ppxa = NULL;

	InstanceValue.IDNameMode = 0;
	InstanceValue.Js9ForceCloseMode = 0;
}

CScriptSite::~CScriptSite()
{
	if ( InstanceValue.stay.threadID != 0 ){
		DropStayInstance(&InstanceValue);
	}

	if ( InstanceValue.Engine != NULL ){
		InstanceValue.Engine->Release();
		InstanceValue.Engine = NULL;
	}
	if ( InstanceValue.Parser != NULL ){
		InstanceValue.Parser->Release();
		InstanceValue.Parser = NULL;
	}
	if ( InstanceValue.IncludeNames != NULL ){
		delete[] InstanceValue.IncludeNames;
	}
	if ( InstanceValue.Base != NULL ){
		InstanceValue.Base->Release();
		InstanceValue.Base = NULL;
	}
	if ( InstanceValue.stay.ppxa != NULL ){
		HeapFree(GetProcessHeap(), 0, InstanceValue.stay.ppxa);
	}
	if ( m_ScriptImage != NULL ) delete[] m_ScriptImage;
}
//----------------------------------------------------- IUnknown
T_IUNKNOWN_ADDREFDEFINE(CLASSNAME);
T_IUNKNOWN_RELEASEDEFINE(CLASSNAME);
STDMETHODIMP CScriptSite::QueryInterface(REFIID iid, void **ppv)
{
	if ( (iid == IID_IUnknown) || (iid == IID_IActiveScriptSite) ){
		Debug_WriteLog(CLASSNAMES "::QueryInterface->IActiveScriptSite", NULL);
		*ppv = static_cast<IActiveScriptSite*>(this);
		AddRef();
		return S_OK;
	}
	if ( iid == IID_IActiveScriptSiteWindow ){
		Debug_WriteLog(CLASSNAMES "::QueryInterface->IActiveScriptSiteWindow", NULL);
		*ppv = static_cast<IActiveScriptSiteWindow*>(this);
		AddRef();
		return S_OK;
	}
	if ( iid == IID_IActiveScriptSiteInterruptPoll ){
		Debug_WriteLog(CLASSNAMES "::QueryInterface->IActiveScriptSiteInterruptPoll", NULL);
		*ppv = static_cast<IActiveScriptSiteInterruptPoll*>(this);
		AddRef();
		return S_OK;
	}
	Debug_DispIID(CLASSNAMES "::QueryInterface - false:", iid); \
		*ppv = NULL;
	return E_NOINTERFACE;
}

//----------------------------------------------------- IActiveScriptSite
STDMETHODIMP CScriptSite::GetLCID(LCID *)
{
	Debug_WriteLog(CLASSNAMES "::GetLCID", NULL);
	return E_NOTIMPL;
}

// ParseScriptText によるキーワードの解析時に呼び出される
STDMETHODIMP CScriptSite::GetItemInfo(LPCOLESTR pstrName, DWORD dwReturnMask, IUnknown **ppunkItem, ITypeInfo **ppTypeInfo)
{
	if ( pstrName == NULL ) return E_NOTIMPL;
	Debug_WriteLog(CLASSNAMES "::GetItemInfo ", pstrName);
	if ( !stricmpW(L"PPx", pstrName) || !stricmpW(L"WScript", pstrName) ){
		HRESULT hr = E_INVALIDARG;

		if ( dwReturnMask & SCRIPTINFO_IUNKNOWN ){
			if ( ppunkItem == NULL ) return E_INVALIDARG;
			if ( FAILED(InstanceValue.Base->QueryInterface(IID_IUnknown, (void**)ppunkItem)) ){
				return E_POINTER;
			}
			hr = S_OK;
		}
		if ( dwReturnMask & SCRIPTINFO_ITYPEINFO ){
			if ( ppTypeInfo == NULL ) return E_INVALIDARG;
			if ( FAILED(InstanceValue.Base->GetTypeInfo(0, 0, ppTypeInfo)) ){
				return E_POINTER;
			}
			hr = S_OK;
		}
		return hr;
	}		// 該当無し
	if ( dwReturnMask & SCRIPTINFO_IUNKNOWN ){
		if ( ppunkItem == NULL ) return E_INVALIDARG;
		*ppunkItem = NULL;
	}
	if ( dwReturnMask & SCRIPTINFO_ITYPEINFO ){
		if ( ppTypeInfo == NULL ) return E_INVALIDARG;
		*ppTypeInfo = NULL;
	}
	return TYPE_E_ELEMENTNOTFOUND;
}

// バージョン番号
STDMETHODIMP CScriptSite::GetDocVersionString(BSTR *pbstrVersionString)
{
	Debug_WriteLog(CLASSNAMES "::GetDocVersionString", NULL);
	*pbstrVersionString = ::SysAllocString(L"DocVersion:PPXS");
	return S_OK;
}

// 強制終了
STDMETHODIMP CScriptSite::OnScriptTerminate(const VARIANT *, const EXCEPINFO *)
{
	Debug_WriteLog(CLASSNAMES "::OnScriptTerminate", NULL);
	return S_OK;
}

// 状態変更の通知
#ifndef DEBUG
STDMETHODIMP CScriptSite::OnStateChange(SCRIPTSTATE /*ssScriptState*/)
{
	return S_OK;
}
#else
STDMETHODIMP CScriptSite::OnStateChange(SCRIPTSTATE ssScriptState)
{
	switch ( ssScriptState ){
		case SCRIPTSTATE_UNINITIALIZED:
			Debug_WriteLog(CLASSNAMES "::OnStateChange-Uninitialized", NULL);
			break;
		case SCRIPTSTATE_INITIALIZED:
			Debug_WriteLog(CLASSNAMES "::OnStateChange-Initialized", NULL);
			break;
		case SCRIPTSTATE_STARTED:
			Debug_WriteLog(CLASSNAMES "::OnStateChange-Started", NULL);
			break;
		case SCRIPTSTATE_CONNECTED:
			Debug_WriteLog(CLASSNAMES "::OnStateChange-Connected", NULL);
			break;
		case SCRIPTSTATE_DISCONNECTED:
			Debug_WriteLog(CLASSNAMES "::OnStateChange-Disconnected", NULL);
			break;
		case SCRIPTSTATE_CLOSED:
			Debug_WriteLog(CLASSNAMES "::OnStateChange-Closed", NULL);
			break;
		default:
			Debug_WriteLog(CLASSNAMES "::OnStateChange-Unknown", NULL);
	}
	return S_OK;
}
#endif

// エラーの通知
STDMETHODIMP CScriptSite::OnScriptError(IActiveScriptError *ase)
{
	WCHAR source[0x300];
	EXCEPINFO ei;
	DWORD SourceContext;
	ULONG line;
	LONG column;

	Debug_WriteLog(CLASSNAMES "::OnScriptError", NULL);
	if ( InstanceValue.Js9ForceCloseMode < 0 ) return S_OK; // JScript9 はエラー終了で無理矢理終わらせることがあるので、ここで判別
	memset(&ei, 0, sizeof(ei));
	if ( SUCCEEDED(ase->GetExceptionInfo(&ei)) ){
		source[0] = '\0';
		ase->GetSourcePosition(&SourceContext, &line, &column);
		if ( SourceContext > 0 ){
			WCHAR *srcptr = InstanceValue.IncludeNames;
			WCHAR *nextptr;
			for (;; ){
				nextptr = wcschr(srcptr, '\1');
				if ( (--SourceContext == 0) || (nextptr == NULL) ) break;
				srcptr = nextptr + 1;
			}
			if ( nextptr != NULL ) *nextptr = '\0';
			wsprintf(source, L"<%s>", srcptr);
			if ( nextptr != NULL ) *nextptr = '\1';
		}
		PopupMessagef(InstanceValue.ppxa,
				L"Script error \"%s\" %sline:%u, col:%u\n%s(code: %d)",
				InstanceValue.ScriptName,
				source,
				line + 1, column + 1,
				ei.bstrDescription, ei.wCode);

		SysFreeString(ei.bstrSource);
		SysFreeString(ei.bstrDescription);
		SysFreeString(ei.bstrHelpFile);
	}
	return S_OK;
}

// スクリプト実行開始
STDMETHODIMP CScriptSite::OnEnterScript(void)
{
	Debug_WriteLog(CLASSNAMES "::OnEnterScript", NULL);
	return S_OK;
}

// スクリプト実行終了
STDMETHODIMP CScriptSite::OnLeaveScript(void)
{
	Debug_WriteLog(CLASSNAMES "::OnLeaveScript", NULL);
	return S_OK;
}

//----------------------------------------------------- IActiveScriptSiteWindow
STDMETHODIMP CScriptSite::GetWindow(HWND *phwnd)
{
	Debug_WriteLog(CLASSNAMES "::GetWindow", NULL);
	*phwnd = InstanceValue.ppxa->hWnd;
	return S_OK;
}

STDMETHODIMP CScriptSite::EnableModeless(BOOL fEnable)
{
	Debug_WriteLog(CLASSNAMES "::EnableModeless", NULL);
	EnableWindow(InstanceValue.ppxa->hWnd, fEnable);
	return S_OK;
}
//----------------------------------------------- IActiveScriptSiteInterruptPoll
STDMETHODIMP CScriptSite::QueryContinue(void)
{
	Debug_WriteLog(CLASSNAMES "::QueryContinue", NULL);
	return S_OK;
}
//----------------------------------------------------- Local define
// ActiveX Scripting Engine を初期化
int CScriptSite::InitializeScriptSite(PPXMCOMMANDSTRUCT *pxc, const WCHAR *inline_type, int StayMode)
{
	WCHAR scripttype[MAX_PATH];
	const WCHAR *ScriptText;
	const WCHAR *extp;

	if ( pxc->resultstring != NULL ) pxc->resultstring[0] = '\0';
									// 言語エンジン初期化 ---------------------
									// 言語を決定
	wcscpy(scripttype, L"VBScript");
	extp = (inline_type == NULL) ? wcsrchr(pxc->param, '.') : inline_type;

	if ( (extp != NULL) && (*(extp + 1) == 'j') ){
		int js_type = 0;

		if ( wcscmp(extp + 2, L"s9") == 0 ){ // .js9
			js_type = SCRIPTLANGUAGEVERSION_ECMA5;
		}else if ( wcscmp(extp + 2, L"sc") == 0 ){ // .jsc
			js_type = SCRIPTLANGUAGEVERSION_CHAKRA;
		}else if ( UseJScript9 && stricmpW(extp + 2, L"s") == 0 ){ //.js
			js_type = UseJScript9;
		}
		if ( js_type != 0 ){
			if ( (UsedJSEngine > 0) && (js_type != UsedJSEngine) ){
				PopupMessage(InstanceValue.ppxa, L"Can't use JScript9 'and' Chakra.");
				return PPXMRESULT_STOP;
			}

			if ( FAILED(CoCreateInstance(
					(js_type == SCRIPTLANGUAGEVERSION_CHAKRA) ?
					CLSID_Chakra : CLSID_JScript9,
					NULL, CLSCTX_INPROC_SERVER,
					IID_IActiveScript, (void **)&InstanceValue.Engine)) ){
				InstanceValue.Engine = NULL;
				extp = L".js";
			} else{
				IActiveScriptProperty *ScriptProperty;

				InstanceValue.Js9ForceCloseMode = 1;
				if ( js_type < SCRIPTLANGUAGEVERSION_CHAKRA ){
					if ( SUCCEEDED(InstanceValue.Engine->QueryInterface(IID_IActiveScriptProperty, (void**)&ScriptProperty)) ){
						VARIANT dummyvt;

						VariantInit(&dummyvt);
						dummyvt.vt = VT_I4;
						dummyvt.lVal = js_type;
						ScriptProperty->SetProperty(SCRIPTPROP_INVOKEVERSIONING, NULL, &dummyvt);
						VariantClear(&dummyvt);
						ScriptProperty->Release();
					} else{
						InstanceValue.Engine->Release();
						InstanceValue.Engine = NULL;
					}
				}
				UsedJSEngine = js_type;
			}
		}
	}
	if ( InstanceValue.Engine == NULL ){
		CLSID m_EngineClsid;

		if ( extp != NULL ){
			WCHAR extname[MAX_PATH];

			if ( FALSE != ::GetRegStringW(HKEY_CLASSES_ROOT, extp, ::NullStr, extname, sizeof(extname)) ){
				wcscat(extname, L"\\ScriptEngine");
				::GetRegStringW(HKEY_CLASSES_ROOT, extname, ::NullStr, scripttype, sizeof(scripttype));
/*
				if ( scripttype[0] != '{' ){
					wcscpy(extname, scripttype);
					wcscat(extname, L"\\CLSID");
					::GetRegStringW(HKEY_CLASSES_ROOT, extname, ::NullStr, scripttype, sizeof(scripttype));
					Debug_WriteLog(CLASSNAMES "::InitializeScriptSite :", L" %s ", scripttype);
				}
*/
			}
		}
		if ( FAILED(CLSIDFromProgID(scripttype, &m_EngineClsid)) ){
			::PopupMessage(InstanceValue.ppxa, L"Failed to create scripting engine.");
			return PPXMRESULT_STOP;
		}
									// IActiveScript にエンジン登録
		if ( FAILED(CoCreateInstance(m_EngineClsid, NULL, CLSCTX_INPROC_SERVER,
			IID_IActiveScript, (void **)&InstanceValue.Engine)) ){
			::PopupMessage(InstanceValue.ppxa, L"Failed to create scripting engine.");
			return PPXMRESULT_STOP;
		}
		InstanceValue.Engine->SetScriptState(SCRIPTSTATE_UNINITIALIZED);
	}
	wcscpy(InstanceValue.ScriptName, pxc->param);
	InstanceValue.arg.param = pxc->param;
	InstanceValue.arg.count = pxc->paramcount - 1;
	InstanceValue.arg.resultstring = pxc->resultstring;
	InstanceValue.stay.mode = StayMode;

	InstanceValue.Base = new CScriptBase(&InstanceValue);
	InstanceValue.Base->AddRef();

	/*hr = */InstanceValue.Engine->SetScriptSite(this);
	InstanceValue.Engine->SetScriptState(SCRIPTSTATE_INITIALIZED);

	/*hr = */InstanceValue.Engine->QueryInterface(IID_IActiveScriptParse, (void**)&InstanceValue.Parser);
	if ( FAILED(InstanceValue.Parser->InitNew()) ){
		::PopupMessage(InstanceValue.ppxa, L"Error calling Parser.");
		return PPXMRESULT_STOP;
	}
									// スクリプト読み込み ---------------------
	if ( inline_type != NULL ){
		ScriptText = pxc->param;
	}else{
		m_ScriptImage = LoadScriptFile(pxc->param);
		if ( m_ScriptImage == NULL ){
			::PopupMessagef(InstanceValue.ppxa, L"%s open error", pxc->param);
			return PPXMRESULT_STOP;
		}
		ScriptText = m_ScriptImage;
	}

	// Ruby は、SCRIPTITEM_GLOBALMEMBERS を指定すると落ちる？
	InstanceValue.Engine->AddNamedItem(L"PPx", SCRIPTITEM_GLOBALMEMBERS | SCRIPTITEM_ISPERSISTENT | SCRIPTITEM_ISVISIBLE);

	HRESULT hr = InstanceValue.Parser->ParseScriptText(ScriptText, NULL,
			NULL, NULL, InstanceValue.SourceIDserver++, 0,
			SCRIPTTEXT_ISVISIBLE, NULL, NULL);
	if ( FAILED(hr) ) return PPXMRESULT_STOP;

	if ( StayMode >= ScriptStay_Stay ){
		ChainStayInstance(&InstanceValue, StayMode);
	}
	return PPXMRESULT_DONE;
}
// スクリプトを実行する -------------------------------------------------------
int CScriptSite::RunScript()
{
	SCRIPTSTATE sstate;

	Debug_WriteLog(CLASSNAMES "::RunScript", NULL);
	// スクリプトの解析
	InstanceValue.Base->Var_ResultStatus = PPXMRESULT_DONE;
	InstanceValue.Engine->SetScriptState(SCRIPTSTATE_STARTED);
	InstanceValue.Engine->SetScriptState(SCRIPTSTATE_CONNECTED); // 実行開始
	Debug_WriteLog(CLASSNAMES "::RunScript-start ending", NULL);
	InstanceValue.Engine->GetScriptState(&sstate);

	if ( InstanceValue.stay.mode == 0 ){
		if ( sstate < SCRIPTSTATE_CLOSED ){
			if ( sstate < SCRIPTSTATE_DISCONNECTED ){
				InstanceValue.Engine->SetScriptState(SCRIPTSTATE_DISCONNECTED);
			}
			InstanceValue.Engine->SetScriptState(SCRIPTSTATE_CLOSED);
		}
	}
	Debug_WriteLog(CLASSNAMES "::RunScript-end ending", NULL);
	return InstanceValue.Base->Var_ResultStatus;
}
// スクリプトを終了 -----------------------------------------------------------
void CScriptSite::QuitScript()
{
	Debug_WriteLog(CLASSNAMES "::QuitScript", NULL);
	InstanceValue.Base->SetResult();
	InstanceValue.Engine->Close();
}

HRESULT CScriptSite::InvokeScript(const WCHAR *funcname, const WCHAR *param, int paramcount)
{
	HRESULT result;
	IDispatch *pDisp;
	DISPID id;

//	InstanceValue.Engine->SetScriptState(SCRIPTSTATE_INITIALIZED);
//	InstanceValue.Engine->SetScriptState(SCRIPTSTATE_STARTED);

	if ( SUCCEEDED(result = InstanceValue.Engine->GetScriptDispatch(0, &pDisp)) ){
		OLECHAR *olename, name[0x100];
		wcscpy(name, funcname);
		olename = name;

		if ( SUCCEEDED(result = pDisp->GetIDsOfNames(IID_NULL, &olename, 1, LOCALE_USER_DEFAULT, &id)) ){
			DISPPARAMS dispParams;
			EXCEPINFO exceptions;
			UINT error = 0;

			VARIANT *inputp, output, *outputp;

			if ( paramcount > 0 ){
				inputp = new VARIANT[paramcount];

				for ( int c = paramcount - 1; c >= 0; c--){ // 順番反転
					inputp[c].vt = VT_BSTR;
					inputp[c].bstrVal = ::SysAllocString(param);
					param += wcslen(param) + 1;
				}
			}else{
				inputp = NULL;
			}

			dispParams.rgvarg = inputp;
			dispParams.rgdispidNamedArgs = NULL;
			dispParams.cArgs = paramcount;
			dispParams.cNamedArgs = 0;

			if ( InstanceValue.arg.resultstring != NULL ){
				VariantInit(&output);
				outputp = &output;
			}else{
				outputp = NULL;
			}

			InstanceValue.Base->UpdatePPxInfo();
			result = pDisp->Invoke(id, IID_NULL, LOCALE_USER_DEFAULT,
					DISPATCH_METHOD, &dispParams, outputp, &exceptions, &error);
			if ( inputp != NULL ){
				for ( int c = 0 ; c < paramcount; c++ ) VariantClear(&inputp[c]);
				delete[] inputp;
			}

			if ( outputp != NULL ){
				if ( SUCCEEDED(::VariantChangeType(&output, &output, 0, VT_BSTR)) ){
					InstanceValue.Base->set_result(output.bstrVal);
				}
				VariantClear(outputp);
			}
		}
		pDisp->Release();
	}
	return result;
}

HRESULT CScriptSite::EvalScript(const WCHAR *script)
{
	HRESULT result;

	InstanceValue.Base->UpdatePPxInfo();
	result = InstanceValue.Parser->ParseScriptText(script, NULL, NULL,
			NULL, 0, 0, SCRIPTTEXT_ISVISIBLE, NULL, NULL);
	if ( SUCCEEDED(result) ){
		InstanceValue.Engine->SetScriptState(SCRIPTSTATE_STARTED);
	}
	return result;
}
