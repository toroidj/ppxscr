/*-----------------------------------------------------------------------------
	Paper Plane xUI  Script Module	IPPx(IScriptBase)
									(スクリプトのデフォルトオブジェクト)
-----------------------------------------------------------------------------*/
#define  STRICT
#define _WIN32_DCOM
#include <windows.h>
#include <activscp.h>
#include "ppxscr.h"
#pragma hdrstop
#include "PPxScr_TLB.h"
#include "IArguments.h"
#include "IEntry.h"
#include "IPane.h"
#include "ITab.h"
#include "IScriptBase.h"
#include "IScriptSite.h"

#define CLASSNAME CScriptBase
#define CLASSNAMES "CScriptBase"
CScriptBase::CScriptBase(InstanceValueStruct *InstanceValue)
{
	T_IUNKNOWN_INITDEFINE();

	m_InstanceValue = InstanceValue;
	ppxa = m_InstanceValue->ppxa;

	m_typeInfo = InstanceValue->BaseTypeInfo; // != NULL 確定
	m_typeInfo->AddRef();
	m_theConnection = NULL;
	m_ScriptLongResult = NULL;
	m_extract_result = NO_ERROR;
	m_EventChain.next = NULL;
}

//----------------------------------------------------- IUnknown Interfaces
T_IUNKNOWN_ADDREFDEFINE(CLASSNAME)

STDMETHODIMP_(ULONG) CScriptBase::Release()
{
	if ( --m_refCount == 0 ){
		FreeEventChainObject(&m_EventChain);
		m_typeInfo->Release();
		delete this;
		return 0;
	}
	return m_refCount;
}

STDMETHODIMP CScriptBase::QueryInterface(REFIID iid, void **ppv)
{
	if ( (iid == IID_IUnknown) || (iid == IID_IPPx) ){
		Debug_WriteLog(CLASSNAMES "::QueryInterface->IPPx", NULL);
		*ppv = static_cast<IPPx*>(this);
		AddRef();
		return S_OK;
	}
	if ( iid == IID_IDispatch ){
		Debug_WriteLog(CLASSNAMES "::QueryInterface->IDispatch", NULL);
		*ppv = static_cast<IDispatch*>(this);
		AddRef();
		return S_OK;
	}
	if ( iid == IID_IProvideMultipleClassInfo ){
		Debug_WriteLog(CLASSNAMES "::QueryInterface->IProvideMultipleClassInfo", NULL);
		*ppv = static_cast<IProvideMultipleClassInfo*>(this);
		AddRef();
		return S_OK;
	}
	if ( iid == IID_IConnectionPointContainer ){
		Debug_WriteLog(CLASSNAMES "::QueryInterface->IConnectionPointContainer", NULL);
		*ppv = static_cast<IConnectionPointContainer*>(this);
		AddRef();
		return S_OK;
	}
	if ( iid == IID_IConnectionPoint ){
		Debug_WriteLog(CLASSNAMES "::QueryInterface->IConnectionPoint", NULL);
		*ppv = static_cast<IConnectionPoint*>(this);
		AddRef();
		return S_OK;
	}
	Debug_DispIID(CLASSNAMES "::QueryInterface - false:", iid);
	*ppv = NULL;
	return E_NOINTERFACE;
}
/*
	(riid == IID_ITridentEventSink)
	(riid == IID_IActiveScriptSiteInterruptPoll)
	(riid == IID_IDispatchEx)
	(riid == IID_IBindEventHandler)
	(riid == IID_IActiveScriptSIPInfo)
*/
//--------------------------------------------------- IProvideMultipleClassInfo
STDMETHODIMP CScriptBase::GetMultiTypeInfoCount(ULONG *pcti)
{
	Debug_WriteLog(CLASSNAMES "::GetMultiTypeInfoCount", NULL);
	*pcti = 1;
	return S_OK;
}

STDMETHODIMP CScriptBase::GetInfoOfIndex(ULONG iti, DWORD dwMCIFlags, ITypeInfo **pptiCoClass, DWORD *pdwTIFlags, ULONG *pcdispidReserved, IID *piidPrimary, IID *piidSource)
{
	Debug_WriteLog(CLASSNAMES "::GetInfoOfIndex", NULL);
	if ( iti != 0 ) return E_INVALIDARG;
	if ( dwMCIFlags & MULTICLASSINFO_GETTYPEINFO ){
		HRESULT hr = GetTypeInfo(0, 0, pptiCoClass);
		if ( FAILED(hr) ) return hr;
	}
	if ( dwMCIFlags & MULTICLASSINFO_GETNUMRESERVEDDISPIDS ){
		*pdwTIFlags = 0;
		*pcdispidReserved = 0;
	}
	if ( dwMCIFlags & MULTICLASSINFO_GETIIDPRIMARY ){
		*piidPrimary = IID_IPPx;
	}
	if ( dwMCIFlags & MULTICLASSINFO_GETIIDSOURCE ){
		*piidSource = IID_IPPx;
	}
	return S_OK;
}

//--------------------------------------------------- IProvideClassInfo
STDMETHODIMP CScriptBase::GetClassInfo(ITypeInfo **ppTI)
{
	Debug_WriteLog(CLASSNAMES "::GetClassInfo", NULL);
	return GetTypeInfo(0, 0, ppTI);
}

//-------------------------------------------------- IProvideClassInfo2
STDMETHODIMP CScriptBase::GetGUID(DWORD dwGuidKind, GUID *pGUID)
{
	Debug_WriteLog(CLASSNAMES "::GetGUID", NULL);
	if ( dwGuidKind != GUIDKIND_DEFAULT_SOURCE_DISP_IID ) return E_INVALIDARG;
	*pGUID = IID_IPPx;
	return S_OK;
}

//-------------------------------------------------- IConnectionPointContainer
STDMETHODIMP CScriptBase::EnumConnectionPoints(IEnumConnectionPoints **)
{
	Debug_WriteLog(CLASSNAMES "::EnumConnectionPoints", NULL);
	return E_NOTIMPL;
}

STDMETHODIMP CScriptBase::FindConnectionPoint(REFIID riid, IConnectionPoint **ppCP)
{
	Debug_WriteLog(CLASSNAMES "::FindConnectionPoint", NULL);
	if ( riid == DIID_IPPxEvents ){
		*ppCP = static_cast<IConnectionPoint*>(this);
	}else{
		*ppCP = NULL;
		return CONNECT_E_NOCONNECTION;
	}
	static_cast<IUnknown*>(*ppCP)->AddRef();
	return S_OK;
}

//-------------------------------------------------- IConnectionPoint
STDMETHODIMP CScriptBase::GetConnectionInterface(IID *pIID)
{
	HRESULT hr = S_OK;

	Debug_WriteLog(CLASSNAMES "::GetConnectionInterface", NULL);
	if ( pIID == NULL ){
		hr = E_POINTER;
	}else{
		*pIID = DIID_IPPxEvents;
	}
	return hr;
}

STDMETHODIMP CScriptBase::GetConnectionPointContainer(IConnectionPointContainer **ppCPC)
{
	HRESULT hr = S_OK;

	Debug_WriteLog(CLASSNAMES "::GetConnectionPointContainer", NULL);
	if ( ppCPC == NULL ){
		hr = E_POINTER;
	}else{
		*ppCPC = static_cast<IConnectionPointContainer*>(this);
		static_cast<IUnknown*>(*ppCPC)->AddRef();
	}
	return hr;
}

STDMETHODIMP CScriptBase::Advise(IUnknown *pUnk, DWORD *pdwCookie)
{
	Debug_WriteLog(CLASSNAMES "::Advise", NULL);
	if ( pUnk == NULL ) return E_POINTER;
	if ( pdwCookie == NULL ) return E_POINTER;
	if ( m_theConnection != NULL ) return CONNECT_E_ADVISELIMIT;

	HRESULT hr = pUnk->QueryInterface(DIID_IPPxEvents, (void**)&m_theConnection);
	if ( FAILED(hr) ) return CONNECT_E_CANNOTCONNECT;
	*pdwCookie = 1;
	return S_OK;
}

STDMETHODIMP CScriptBase::Unadvise(DWORD dwCookie)
{
	Debug_WriteLog(CLASSNAMES "::Unadvise", NULL);
	if ( (dwCookie != 1) || (m_theConnection == NULL) ){
		return CONNECT_E_NOCONNECTION;
	}

	m_theConnection->Release();
	m_theConnection = NULL;
	return S_OK;
}

STDMETHODIMP CScriptBase::EnumConnections(IEnumConnections **)
{
	Debug_WriteLog(CLASSNAMES "::EnumConnections", NULL);
	return E_NOTIMPL;
}

//-------------------------------------------------- IDispatch
STDMETHODIMP CScriptBase::GetTypeInfoCount(UINT *iTInfo)
{
	Debug_WriteLog(CLASSNAMES "::GetTypeInfoCount", NULL);
	if ( iTInfo == NULL ) return E_NOTIMPL;
	*iTInfo = 1;
	return S_OK;
}

STDMETHODIMP CScriptBase::GetTypeInfo(UINT iTInfo, LCID, ITypeInfo **ppTInfo)
{
	Debug_WriteLog(CLASSNAMES "::GetTypeInfo", NULL);
	if ( iTInfo != 0 ){
		*ppTInfo = NULL;
		return DISP_E_BADINDEX;
	}
	*ppTInfo = m_typeInfo;
	m_typeInfo->AddRef();
	return S_OK;
}

STDMETHODIMP CScriptBase::GetIDsOfNames(REFIID riid, OLECHAR **rgszNames, UINT cNames, LCID, DISPID *rgDispId)
{
	if ( riid != IID_NULL ){
		Debug_WriteLog(CLASSNAMES "::GetIDsOfNames-Invalidarg:", *rgszNames);
		return DISP_E_UNKNOWNINTERFACE;
	}
#ifndef DEBUG
	return m_typeInfo->GetIDsOfNames(rgszNames, cNames, rgDispId);
#else
	HRESULT hr = m_typeInfo->GetIDsOfNames(rgszNames, cNames, rgDispId);
	UINT count;
	for ( count = 0; count < cNames; count++ ){
		if ( FAILED(hr) ){
			Debug_WriteLog(CLASSNAMES "::GetIDsOfNames-Failed:", rgszNames[count]);
		}else{
			Debug_WriteLog(CLASSNAMES "::GetIDsOfNames-Succesed:", rgszNames[count]);
		}
	}
	return hr;
#endif
}

STDMETHODIMP CScriptBase::Invoke(DISPID dispIdMember, REFIID riid, LCID lc, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO * ei, UINT *puArgErr)
{
	HRESULT hr;
	UINT arg;

	Debug_WriteLog(CLASSNAMES "::Invoke", NULL);
	if ( riid != IID_NULL ) return DISP_E_UNKNOWNINTERFACE;

#if 0 // type library で invoke を行う場合の例
	if ( wFlags & DISPATCH_METHOD ){ // DISPID_EXECUTE と DISPID_ECHO は自前
		if ( dispIdMember == DISPID_EXECUTE ){
			:
			:
			:
		}
		if ( dispIdMember == DISPID_ECHO ){
			:
			:
			:
		}
	}
	return m_typeInfo->Invoke(static_cast<IDispatch*>(this),
			dispIdMember, wFlags, pDispParams, pVarResult, ei, puArgErr);
#else
									// Method ---------------------------------
	if ( wFlags & DISPATCH_METHOD ){
		// Debug_WriteLog(NULL, UNICODESTR(CLASSNAMES) L"::Invoke Method %d", dispIdMember);
		switch ( dispIdMember ){
			case DISPID_EXECUTE:
				ArgsCheck(1);
				FixArgType(0, VT_BSTR);
				if ( pVarResult == NULL ){
					return Execute(pDispParams->rgvarg[0].bstrVal, NULL);
				}else{
					pVarResult->vt = VT_I4;
					return Execute(pDispParams->rgvarg[0].bstrVal, &pVarResult->lVal);
				}

			case 10: //SetPopLineMessage
				ArgsCheck(1);
				FixArgType(0, VT_BSTR);
				return SetPopLineMessage(pDispParams->rgvarg[0].bstrVal);

			case 41:
				ArgsCheck(1);
				FixArgType(0, VT_BSTR);
				return lineMessage(pDispParams->rgvarg[0].bstrVal);

			case 44:
				ArgsCheck(1);
				FixArgType(0, VT_BSTR);
				return report(pDispParams->rgvarg[0].bstrVal);

			case 45:
				ArgsCheck(1);
				FixArgType(0, VT_BSTR);
				return log(pDispParams->rgvarg[0].bstrVal);

			case DISPID_CONNECTOBJECT:
				ArgsCheck(2);
				FixArgType(0, VT_BSTR);
				FixArgType(1, VT_DISPATCH);
				return ConnectObject(pDispParams->rgvarg[1].pdispVal,
						pDispParams->rgvarg[0].bstrVal);

			case DISPID_DISCONNECTOBJECT:
				ArgsCheck(1);
				FixArgType(0, VT_DISPATCH);
				return DisconnectObject(pDispParams->rgvarg[0].pdispVal);

			case DISPID_ECHO:
				if ( (pDispParams->cArgs == 1) &&
					 (pDispParams->rgvarg[0].vt == (VT_ARRAY | VT_VARIANT)) ){
					// Echo() が使用可能
					return Echo(pDispParams->rgvarg[0].parray);
				}else{
					unsigned int iArgs, magargs;
					WCHAR *msg;
					size_t msgmax = CMDLINESIZE;
					size_t msgoffset = 0;

					msg = (WCHAR *)HeapAlloc(GetProcessHeap(), 0, msgmax * sizeof(WCHAR));
					if ( msg == NULL ) return E_OUTOFMEMORY;

					magargs = pDispParams->cArgs;
					hr = S_OK;
					for ( iArgs = 0; iArgs < magargs; iArgs++ ){
						if ( FAILED(hr = CatVariantStrings(&msg, &msgoffset, &msgmax, &pDispParams->rgvarg[magargs - iArgs - 1])) ){
							break;
						}
						// 項目間の空白。CatVariantStrings でメモリ確保済み
						if ( (iArgs + 1) < magargs ) msg[msgoffset++] = L' ';
					}
					msg[msgoffset] = L'\0';

					::PopupMessage(ppxa, msg);
					HeapFree(GetProcessHeap(), 0, msg);
					return hr;
				}

			case DISPID_QUIT:
				if ( pDispParams->cArgs == 1 ){
					FixArgType(0, VT_I4);
					return Quit(pDispParams->rgvarg[0].lVal);
				}else if ( pDispParams->cArgs == 0 ){
					return Quit(PPXMRESULT_DONE);
				}
				return DISP_E_BADPARAMCOUNT;

			case DISPID_SLEEP:
				ArgsCheck(1);
				FixArgType(0, VT_UI4);
				return Sleep(pDispParams->rgvarg[0].ulVal);

			case 25:
				ArgsCheck(2);
				FixArgType(0, VT_BSTR);
				FixArgType(1, VT_I4);
				return EntryInsert(pDispParams->rgvarg[1].lVal,
						pDispParams->rgvarg[0].bstrVal);

			case 39:
				ArgsCheck(2);
				FixArgType(0, VT_BSTR);
				FixArgType(1, VT_BSTR);
				return setValue(pDispParams->rgvarg[1].bstrVal, pDispParams->rgvarg[0].bstrVal);

			case 47:
				ArgsCheck(1);
				FixArgType(0, VT_BSTR);
				return Include(pDispParams->rgvarg[0].bstrVal);

			case 48:
				ArgsCheck(2);
				FixArgType(0, VT_BSTR);
				FixArgType(1, VT_BSTR);
				return setProcessValue(pDispParams->rgvarg[1].bstrVal, pDispParams->rgvarg[0].bstrVal);

			case 50:
				ArgsCheck(2);
				FixArgType(0, VT_BSTR);
				FixArgType(1, VT_BSTR);
				return setIValue(pDispParams->rgvarg[1].bstrVal, pDispParams->rgvarg[0].bstrVal);

			case 51:
				ArgsCheck(1);
				FixArgType(0, VT_DISPATCH);
				if ( pVarResult == NULL ) return E_INVALIDARG;
				return SetVariantPtrResult(VT_DISPATCH, pVarResult, Enumerator(pDispParams->rgvarg[0].pdispVal, &pVarResult->pdispVal));

			case 53:
				ArgsCheck(1);
				if ( pVarResult == NULL ) return E_INVALIDARG;
				FixArgType(0, VT_BSTR);
				pVarResult->vt = VT_BSTR;
				return option(pDispParams->rgvarg[0].bstrVal, *pVarResult, pVarResult);

			case 54:
				ArgsCheck(1);
				if ( pVarResult == NULL ) return E_INVALIDARG;
				FixArgType(0, VT_I4);
				pVarResult->vt = VT_I4;
				return LoadCount(pDispParams->rgvarg[0].lVal, &pVarResult->lVal);
		}
	}
									// Get/Method(戻り値あり) -----------------
	if ( wFlags & (DISPATCH_PROPERTYGET | DISPATCH_METHOD) ){
		if ( pVarResult == NULL ){
			VARIANT dummyvt;

			VariantInit(&dummyvt);
			hr = Invoke(dispIdMember, riid, lc, wFlags, pDispParams, &dummyvt, ei, puArgErr);
			VariantClear(&dummyvt);
			return hr;
		}
		// Debug_WriteLog(NULL, UNICODESTR(CLASSNAMES) L"::Invoke Get/Method %d", dispIdMember);
		switch ( dispIdMember ){
			case 32:
				if ( pDispParams->cArgs == 0 ){
				pVarResult->vt = VT_I4;
					return GetComboItemCount(1, &pVarResult->lVal);
				}
				ArgsCheck(1);
				FixArgType(0, VT_I4);
				pVarResult->vt = VT_I4;
				return GetComboItemCount(pDispParams->rgvarg[0].lVal, &pVarResult->lVal);

			case DISPID_EXTRACT:
				if ( pDispParams->cArgs == 0 ){
				pVarResult->vt = VT_BSTR;
					return Extract(NULL, &pVarResult->bstrVal);
				}
				ArgsCheck(1);
				FixArgType(0, VT_BSTR);
				pVarResult->vt = VT_BSTR;
				return Extract(pDispParams->rgvarg[0].bstrVal, &pVarResult->bstrVal);

			case 20: // GetFileInformation
				if ( pDispParams->cArgs == 1 ){
					FixArgType(0, VT_BSTR);
					pVarResult->vt = VT_BSTR;
					return GetFileInformation(pDispParams->rgvarg[0].bstrVal, 0, &pVarResult->bstrVal);
				}else if ( pDispParams->cArgs == 2 ){
					FixArgType(0, VT_I4);
					FixArgType(1, VT_BSTR);
					pVarResult->vt = VT_BSTR;
					return GetFileInformation(pDispParams->rgvarg[1].bstrVal, pDispParams->rgvarg[0].lVal, &pVarResult->bstrVal);
				}
				return DISP_E_BADPARAMCOUNT;

			case 11: //EntryFirstMark
				ArgsCheck(0);
				pVarResult->vt = VT_I4;
				return EntryFirstMark(&pVarResult->lVal);

			case 12: //EntryNextMark
				ArgsCheck(0);
				pVarResult->vt = VT_I4;
				return EntryNextMark(&pVarResult->lVal);

			case 30: //EntryPrevMark
				ArgsCheck(0);
				pVarResult->vt = VT_I4;
				return EntryPrevMark(&pVarResult->lVal);

			case 31: //EntryLastMark
				ArgsCheck(0);
				pVarResult->vt = VT_I4;
				return EntryLastMark(&pVarResult->lVal);

			case DISPID_CREATEOBJECT:
				if ( pDispParams->cArgs == 1 ){
					FixArgType(0, VT_BSTR);
					hr = CreateObject(pDispParams->rgvarg[0].bstrVal,
						NULL, &pVarResult->pdispVal);
				}else if ( pDispParams->cArgs == 2 ){
					FixArgType(0, VT_BSTR);
					FixArgType(1, VT_BSTR);
					hr = CreateObject(pDispParams->rgvarg[1].bstrVal,
						pDispParams->rgvarg[0].bstrVal, &pVarResult->pdispVal);
				}else{
					hr = DISP_E_BADPARAMCOUNT;
				}
				return SetVariantPtrResult(VT_DISPATCH, pVarResult, hr);

			case DISPID_GETOBJECT:
				if ( pDispParams->cArgs == 1 ){
					FixArgType(0, VT_BSTR);
					hr = GetObject(pDispParams->rgvarg[0].bstrVal,
						0, 0, &pVarResult->pdispVal);
				}else if ( pDispParams->cArgs == 2 ){
					FixArgType(0, VT_BSTR);
					FixArgType(1, VT_BSTR);
					hr = GetObject(pDispParams->rgvarg[1].bstrVal,
						pDispParams->rgvarg[0].bstrVal, 0, &pVarResult->pdispVal);
				}else if ( pDispParams->cArgs == 3 ){
					FixArgType(0, VT_BSTR);
					FixArgType(1, VT_BSTR);
					FixArgType(2, VT_BSTR);
					hr = GetObject(pDispParams->rgvarg[2].bstrVal,
						pDispParams->rgvarg[1].bstrVal,
						pDispParams->rgvarg[0].bstrVal,
						&pVarResult->pdispVal);
				}else{
					hr = DISP_E_BADPARAMCOUNT;
				}
				return SetVariantPtrResult(VT_DISPATCH, pVarResult, hr);
									// Properties(Get) ------------------------
			case 100:
				pVarResult->vt = VT_BSTR;
				return get_EntryName(&pVarResult->bstrVal);
			case 101:
				pVarResult->vt = VT_I4;
				return get_EntryIndex(&pVarResult->lVal);
			case 102:
				pVarResult->vt = VT_I4;
				return get_EntryDisplayTop(&pVarResult->lVal);
			case 103:
				pVarResult->vt = VT_I4;
				return get_EntryDisplayX(&pVarResult->lVal);
			case 104:
				pVarResult->vt = VT_I4;
				return get_EntryDisplayY(&pVarResult->lVal);
			case 105:
				pVarResult->vt = VT_I4;
				return get_WindowDirection(&pVarResult->lVal);
			case 106:
				pVarResult->vt = VT_I4;
				return get_EntryMark(&pVarResult->lVal);
			case 107:
				pVarResult->vt = VT_BSTR;
				return get_EntryComment(&pVarResult->bstrVal);
			case 15:
				pVarResult->vt = VT_BSTR;
				return get_result(&pVarResult->bstrVal);

			case 108:
				pVarResult->vt = VT_I4;
				return get_EntryAttributes(&pVarResult->lVal);
			case 109:
				pVarResult->vt = VT_R8;
				return get_EntrySize(&pVarResult->dblVal);
			case 42:
				pVarResult->vt = VT_BSTR;
				return get_WindowIDName(&pVarResult->bstrVal);

			case 300:
				pVarResult->vt = VT_I4;
				return get_PPxVersion(&pVarResult->lVal);
			case 301:
				pVarResult->vt = VT_I4;
				return get_CodeType(&pVarResult->lVal);
			case 302:
				pVarResult->vt = VT_I4;
				return get_ModuleVersion(&pVarResult->lVal);

			case 111:
				pVarResult->vt = VT_I4;
				return get_EntryAllCount(&pVarResult->lVal);
			case 112:
				pVarResult->vt = VT_I4;
				return get_EntryDisplayCount(&pVarResult->lVal);

			case 17:
				pVarResult->vt = VT_I4;
				return get_EntryMarkCount(&pVarResult->lVal);

			case 113:
				pVarResult->vt = VT_I4;
				return get_EntryDisplayFiles(&pVarResult->lVal);
			case 114:
				pVarResult->vt = VT_I4;
				return get_EntryDisplayDirectories(&pVarResult->lVal);
			case 115:
				pVarResult->vt = VT_I4;
				return get_DirectoryType(&pVarResult->lVal);

			case 150:
				pVarResult->vt = VT_I4;
				return get_SyncView(&pVarResult->lVal);
			case 19:
				pVarResult->vt = VT_I4;
				return get_SlowMode(&pVarResult->lVal);

			case 200:
				pVarResult->vt = VT_BSTR;
				return get_ScriptFullName(&pVarResult->bstrVal);
			case 201:
				pVarResult->vt = VT_BSTR;
				return get_ScriptName(&pVarResult->bstrVal);

			case 13:
				pVarResult->vt = VT_I4;
				return get_EntryState(&pVarResult->lVal);
			case 28:
				pVarResult->vt = VT_I4;
				return get_EntryHighlight(&pVarResult->lVal);
			case 14:
				pVarResult->vt = VT_I4;
				return get_EntryExtColor(&pVarResult->lVal);

			case 21:
				pVarResult->vt = VT_BSTR;
				return get_DriveVolumeLabel(&pVarResult->bstrVal);

			case 26:
				pVarResult->vt = VT_BSTR;
				return get_Clipboard(&pVarResult->bstrVal);

			case 27:
				pVarResult->vt = VT_I4;
				return get_StayMode(&pVarResult->lVal);


			case 22:
				pVarResult->vt = VT_R8;
				return get_EntryMarkSize(&pVarResult->dblVal);

			case 23:
				pVarResult->vt = VT_R8;
				return get_DriveTotalSize(&pVarResult->dblVal);

			case 24:
				pVarResult->vt = VT_R8;
				return get_DriveFreeSize(&pVarResult->dblVal);

			case 16:
				if ( pDispParams->cArgs == 1 ){ // arg = PPx.Arguments(n)
					IArguments *argp;

					Debug_WriteLog(CLASSNAMES "::Invoke-get_Arguments(n)", NULL);
					FixArgType(0, VT_I4);
					hr = get_Arguments(&argp);
					if ( FAILED(hr) ){
						pVarResult->vt = VT_EMPTY;
						return hr;
					}
					hr = argp->Item(pDispParams->rgvarg[0].lVal, &pVarResult->bstrVal);
					argp->Release();
					pVarResult->vt = SUCCEEDED(hr) ? VT_BSTR : VT_EMPTY;
					return hr;
				}
				// arg = PPx.Arguments()
					ArgsCheck(0);
				return SetVariantPtrResult(VT_DISPATCH, pVarResult,
						get_Arguments(reinterpret_cast<IArguments**>(&pVarResult->pdispVal)));

			case 43: // Argument
				if ( pDispParams->cArgs == 1 ){
					FixArgType(0, VT_I4);
					pVarResult->vt = VT_BSTR;
					return Argument(pDispParams->rgvarg[0].lVal, &pVarResult->bstrVal);
				}else if ( pDispParams->cArgs == 0 ){
					pVarResult->vt = VT_BSTR;
					return Argument(0, &pVarResult->bstrVal);
				}
				pVarResult->vt = VT_EMPTY;
				return DISP_E_BADPARAMCOUNT;

			case 18:
				Debug_WriteLog(CLASSNAMES "::Invoke-get_Entry(n)", NULL);
				if ( pDispParams->cArgs > 1 ) return DISP_E_BADPARAMCOUNT;
				if ( pDispParams->cArgs == 1 ){
					FixArgType(0, VT_I4);
				}

				hr = get_Entry(reinterpret_cast<IEntry**>(&pVarResult->pdispVal));
				if ( FAILED(hr) ){
					pVarResult->vt = VT_EMPTY;
					return hr;
				}

				if ( pDispParams->cArgs == 1 ){
					pVarResult->vt = VT_DISPATCH;
					return reinterpret_cast<CEntry*>(pVarResult->pdispVal)->set_index(pDispParams->rgvarg[0].lVal);
				}else{ // 0
					pVarResult->vt = VT_DISPATCH;
					(reinterpret_cast<CEntry*>(pVarResult->pdispVal))->ResetIndex();
					return S_OK;
				}

			case 29:
				if ( pDispParams->cArgs > 1 ) return DISP_E_BADPARAMCOUNT;
				if ( pDispParams->cArgs == 1 ){
					FixArgType(0, VT_I4);
				}

				hr = get_Pane(reinterpret_cast<IPane**>(&pVarResult->pdispVal));
				if ( FAILED(hr) ){
					pVarResult->vt = VT_EMPTY;
					return hr;
				}

				if ( pDispParams->cArgs == 1 ){
					pVarResult->vt = VT_DISPATCH;
					return reinterpret_cast<CPane*>(pVarResult->pdispVal)->set_index(pDispParams->rgvarg[0].lVal);
				}else{ // 0
					pVarResult->vt = VT_DISPATCH;
					return S_OK;
				}

			case 33:
				pVarResult->vt = VT_BSTR;
				return get_ComboIDName(&pVarResult->bstrVal);

			case 34:
				pVarResult->vt = VT_I4;
				return get_PointType(&pVarResult->lVal);

			case 35:
				pVarResult->vt = VT_I4;
				return get_PointIndex(&pVarResult->lVal);

			case 36:
				if ( pDispParams->cArgs < 1 ) return DISP_E_BADPARAMCOUNT;
				if ( pDispParams->cArgs == 1 ){
					FixArgType(0, VT_I4);
					pVarResult->vt = VT_I4;
					return Cursor(pDispParams->rgvarg[0].lVal,
						(long)-2, &pVarResult->lVal);
				}else{
					FixArgType(0, VT_I4);
					FixArgType(1, VT_I4);
					pVarResult->vt = VT_I4;
					return Cursor(pDispParams->rgvarg[1].lVal,
						pDispParams->rgvarg[0].lVal,
						&pVarResult->lVal);
				}

			case 37:
				pVarResult->vt = VT_BSTR;
				return get_ScriptEngineName(&pVarResult->bstrVal);

			case 40:
				pVarResult->vt = VT_BSTR;
				return get_ScriptEngineVersion(&pVarResult->bstrVal);

			case 38:
				if ( pDispParams->cArgs != 1 ) return DISP_E_BADPARAMCOUNT;
				FixArgType(0, VT_BSTR);
				pVarResult->vt = VT_BSTR;
				return getValue(pDispParams->rgvarg[0].bstrVal, &pVarResult->bstrVal);
			case 46:
				if ( pDispParams->cArgs != 1 ) return DISP_E_BADPARAMCOUNT;
				FixArgType(0, VT_BSTR);
				pVarResult->vt = VT_BSTR;
				return getProcessValue(pDispParams->rgvarg[0].bstrVal, &pVarResult->bstrVal);
			case 49:
				if ( pDispParams->cArgs != 1 ) return DISP_E_BADPARAMCOUNT;
				FixArgType(0, VT_BSTR);
				pVarResult->vt = VT_BSTR;
				return getIValue(pDispParams->rgvarg[0].bstrVal, &pVarResult->bstrVal);

			case 52:
				pVarResult->vt = VT_I4;
				return get_ReentryCount(&pVarResult->lVal);
		}
	}
									// Properties(Put) ------------------------
	if ( wFlags & DISPATCH_PROPERTYPUT ){
		// Debug_WriteLog(NULL, UNICODESTR(CLASSNAMES) L"::Invoke Put %d", dispIdMember);
		ArgsCheck(1);
		switch ( dispIdMember ){
			case 101:
				FixArgType(0, VT_I4);
				return set_EntryIndex(pDispParams->rgvarg[0].lVal);
			case 102:
				FixArgType(0, VT_I4);
				return set_EntryDisplayTop(pDispParams->rgvarg[0].lVal);
			case 106:
				FixArgType(0, VT_I4);
				return set_EntryMark(pDispParams->rgvarg[0].lVal);
			case 107:
				FixArgType(0, VT_BSTR);
				return set_EntryComment(pDispParams->rgvarg[0].bstrVal);
			case 150:
				FixArgType(0, VT_I4);
				return set_SyncView(pDispParams->rgvarg[0].lVal);
			case 19:
				FixArgType(0, VT_I4);
				return set_SlowMode(pDispParams->rgvarg[0].lVal);
			case 13:
				FixArgType(0, VT_I4);
				return set_EntryState(pDispParams->rgvarg[0].lVal);
			case 14:
				FixArgType(0, VT_I4);
				return set_EntryExtColor(pDispParams->rgvarg[0].lVal);
			case 28:
				FixArgType(0, VT_I4);
				return set_EntryHighlight(pDispParams->rgvarg[0].lVal);
			case 15:
				FixArgType(0, VT_BSTR);
				return set_result(pDispParams->rgvarg[0].bstrVal);
			case 42:
				FixArgType(0, VT_BSTR);
				return set_WindowIDName(pDispParams->rgvarg[0].bstrVal);

			case 26:
				FixArgType(0, VT_BSTR);
				return set_Clipboard(pDispParams->rgvarg[0].bstrVal);
			case 27:
				FixArgType(0, VT_I4);
				return set_StayMode(pDispParams->rgvarg[0].lVal);
		}
	}
	Debug_InvokeUnknownDispIID(CLASSNAMES, dispIdMember, wFlags);
	return DISP_E_MEMBERNOTFOUND;
#endif
ArgConvError:
	if ( puArgErr != NULL ) *puArgErr = arg;
	return hr;

}

//-------------------------------------------------- WScript 系 - オブジェクト
void reportf(PPXAPPINFOW *ppxa, const WCHAR *message, ...)
{
	WCHAR bufW[0x400];
	t_va_list argptr;

	t_va_start(argptr, message);
	tvprintfW(bufW, message, argptr);
	t_va_end(argptr);
	bufW[0x400 - 1] = '\0';
	ppxa->Function(ppxa, PPXCMDID_REPORTTEXT, bufW);
}

struct DISPATCHSTRUCT;
#define DISPNAME_MAXLEN 96

class CEventSink : public IDispatch
{
private:
	IActiveScript *m_Engine;
	IConnectionPoint *m_ConnectPoint;
	ITypeInfo *m_EventType;
	int m_refCount;
	WCHAR m_prefix[DISPNAME_MAXLEN];
	DWORD m_ConnectID;
	int m_LogFire;

public:
	CEventSink(DISPATCHSTRUCT *disps, IActiveScript *Engine, BSTR prefix, FREECHAIN *EventChain);
	virtual ~CEventSink();
//----------------------------------------------------- IUnknown
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();
	STDMETHODIMP QueryInterface(REFIID riid, void **ppvObj);
//-------------------------------------------------- IDispatch
	STDMETHODIMP GetTypeInfoCount(UINT *iTInfo);
	STDMETHODIMP GetTypeInfo(UINT, LCID, ITypeInfo **ppTInfo);
	STDMETHODIMP GetIDsOfNames(REFIID riid, OLECHAR **rgszNames, UINT cNames, LCID, DISPID *rgDispId);
	STDMETHODIMP Invoke(DISPID dispIdMember, REFIID riid, LCID lc, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO * ei, UINT *puArgErr);
//-------------------------------------------------- init
	HRESULT Connect(IConnectionPoint *pPoint);
	void Disconnect();
	void SetEventInfo(ITypeInfo *pEventType);
	void SetEventTrace(int trace);
	DISPATCHSTRUCT *m_disps;
	FREECHAIN *m_EventChain;
};

struct DISPATCHSTRUCT {
	FREECHAIN chain;
	IDispatch *pDisp;
	CEventSink *pEventSink;
	PPXAPPINFOW *ppxa;
};

CEventSink::CEventSink(DISPATCHSTRUCT *disps, IActiveScript *Engine, BSTR prefix, FREECHAIN *EventChain)
{
	m_refCount = 1; // addref 1回分
	m_disps = disps;
	m_Engine = Engine;
	m_ConnectPoint = NULL;
	m_EventType = NULL;
	stplimcpyW(m_prefix, prefix, DISPNAME_MAXLEN); // prefix は常に非 null
	m_LogFire = FALSE;
	m_EventChain = EventChain;
}

CEventSink::~CEventSink()
{
}
//----------------------------------------------------- IUnknown
STDMETHODIMP_(ULONG) CEventSink::AddRef()
{
	return ++m_refCount;
}

STDMETHODIMP_(ULONG) CEventSink::Release()
{
	if (--m_refCount == 0){
		if ( m_ConnectPoint != NULL ) Disconnect();
		delete m_disps;
		delete this;
		return 0;
	}
	return m_refCount;
}

STDMETHODIMP CEventSink::QueryInterface(REFIID riid, void **ppvObj)
{
	if ( (riid == IID_IUnknown) || (riid == IID_IDispatch) ){
		*ppvObj = this;
		AddRef();
		return S_OK;
	}
	*ppvObj = NULL;
	return E_NOINTERFACE;
}

//-------------------------------------------------- IDispatch
STDMETHODIMP CEventSink::GetTypeInfoCount(UINT *iTInfo)
{
	if ( iTInfo == NULL ) return E_NOTIMPL;
	*iTInfo = 0;
	return S_OK;
}

STDMETHODIMP CEventSink::GetTypeInfo(UINT iTInfo, LCID, ITypeInfo **ppTInfo)
{
	*ppTInfo = NULL;
	if ( iTInfo != 0 ) return DISP_E_BADINDEX;
	return E_FAIL;
}

STDMETHODIMP CEventSink::GetIDsOfNames(REFIID, OLECHAR **, UINT , LCID, DISPID *)
{
	return DISP_E_UNKNOWNINTERFACE;
}

STDMETHODIMP CEventSink::Invoke(DISPID dispIdMember, REFIID riid, LCID lc, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO * ei, UINT *puArgErr)
{
	WCHAR funcname[DISPNAME_MAXLEN * 2];
	BSTR eventname;
	HRESULT result;

	if ( m_EventType == NULL ) return E_FAIL;

	UINT c;

	if ( FAILED(result = m_EventType->GetNames(dispIdMember, &eventname, 1, &c)) ){;
		return result;
	}

	if ( (eventname == NULL) || (eventname[0] == '\0') ){
		wsprintf(funcname, L"%s%d", m_prefix, (int)dispIdMember);
	}else{
		if ( ::SysStringLen(eventname) >= DISPNAME_MAXLEN ){
			::SysFreeString(eventname);
			return E_OUTOFMEMORY;
		}
		wsprintf(funcname, L"%s%s", m_prefix, eventname);
	}
	::SysFreeString(eventname);

	if ( m_LogFire ) reportf(m_disps->ppxa, L"[Event %s]", funcname);

	IDispatch *pDisp;
	DISPID id;
	OLECHAR *olename;
	olename = funcname;
	if ( SUCCEEDED(result = m_Engine->GetScriptDispatch(0, &pDisp)) ){
		if ( SUCCEEDED(result = pDisp->GetIDsOfNames(riid, &olename, 1, lc, &id)) ){
			result = pDisp->Invoke(id, riid, lc, wFlags, pDispParams, pVarResult, ei, puArgErr);
		}
		pDisp->Release();
	}
	return result;
}

HRESULT CEventSink::Connect(IConnectionPoint *pPoint)
{
	HRESULT hr;

	if ( SUCCEEDED(hr = pPoint->Advise(reinterpret_cast<IUnknown *>(this), &m_ConnectID)) ){
	m_ConnectPoint = pPoint;
	}else{
		m_ConnectID = 0;
		m_ConnectPoint = NULL;
		pPoint->Release();
	}
	return hr;
}

void CEventSink::Disconnect()
{
	FREECHAIN *chain, *nextchain;

	chain = m_EventChain;
	for(;;){
		nextchain = chain->next;
		if ( nextchain == NULL ) break;
		if ( nextchain == &(m_disps->chain) ){
			chain->next = nextchain->next;
			break;
		}
		chain = nextchain;
	}

	if ( m_EventType != NULL ){
		if ( m_LogFire ) reportf(m_disps->ppxa, L"[Disconnect]");
		m_EventType->Release();
		m_EventType = NULL;
	}

	if ( m_ConnectPoint == NULL ) return;
	IConnectionPoint *pConnectPoint = m_ConnectPoint;
	m_ConnectPoint = NULL;
//	reportf(m_disps->ppxa, L"**DISC**");

	// ↓の中で CEventSink->Release() x3、このため Disconnect の再帰が起きる
	pConnectPoint->Unadvise(m_ConnectID);
	pConnectPoint->Release();
}

void CEventSink::SetEventInfo(ITypeInfo *pEventType)
{
	m_EventType = pEventType;
}

void CEventSink::SetEventTrace(int trace)
{
	m_LogFire = trace;
}

// 列挙用 ITypeInfo とその TYPEATTR を取得
BOOL GetTypeInfoAttr(IDispatch *pDisp, ITypeInfo **pType, TYPEATTR **attr, ITypeInfo **pEventType, IID *eventID)
{
	ITypeLib *pTLib;
	UINT libindex;

	if ( FAILED(pDisp->GetTypeInfo(0, LOCALE_USER_DEFAULT, pType)) ){
		return FALSE;
	}
	if ( FAILED((*pType)->GetTypeAttr(attr)) ){
		(*pType)->Release();
		return FALSE;
	}

	// pType には承継元の情報が含まれていない可能性があるため、ライブラリも確認
	if ( SUCCEEDED((*pType)->GetContainingTypeLib(&pTLib, &libindex)) ){
	//	int libmax = pTLib->GetTypeInfoCount();
		ITypeInfo *pLibType;

		if ( eventID != NULL ){
			if ( FAILED(pTLib->GetTypeInfoOfGuid(*eventID, pEventType))) {
				*pEventType = NULL;
			}
		}

		if ( SUCCEEDED(pTLib->GetTypeInfo(libindex, &pLibType)) ){
			TYPEATTR *libattr;

			if ( SUCCEEDED(pLibType->GetTypeAttr(&libattr)) ){
				if ( libattr->typekind == TKIND_DISPATCH ){
					if ( ((*attr)->guid == libattr->guid) &&
						 ((*attr)->cFuncs < libattr->cFuncs) ){
						(*pType)->ReleaseTypeAttr(*attr);
						(*pType)->Release();
						*pType = pLibType;
						*attr = libattr;
						pTLib->Release();
						return TRUE;
					}
				}
				pLibType->ReleaseTypeAttr(libattr);
			}
			pLibType->Release();
		}
		pTLib->Release();
	}
	return TRUE;
}

IConnectionPoint *GetEventID(IDispatch *pDisp, IID &eventID)
{
	IConnectionPoint *pPoint = NULL;
	IConnectionPointContainer *pContainer;
	IProvideClassInfo2 *pProvider;
	IEnumConnectionPoints *pEnumPoints;

	if ( FAILED(pDisp->QueryInterface(IID_IConnectionPointContainer,
			reinterpret_cast<void**>(&pContainer))) ){
		return NULL;
	}

	if ( SUCCEEDED(pDisp->QueryInterface(IID_IProvideClassInfo2,
			reinterpret_cast<void**>(&pProvider))) ){
		if ( SUCCEEDED(pProvider->GetGUID(GUIDKIND_DEFAULT_SOURCE_DISP_IID, &eventID)) ){
			if ( FAILED(pContainer->FindConnectionPoint(eventID, &pPoint))){
				pPoint = NULL;
			}
		}
		pProvider->Release();
	}else if ( SUCCEEDED(pContainer->EnumConnectionPoints(&pEnumPoints)) ){
		if ( SUCCEEDED(pEnumPoints->Next(1, &pPoint, 0)) && (pPoint != NULL) ){
			if( FAILED(pPoint->GetConnectionInterface(&eventID)) ){
				pPoint->Release();
				pPoint = NULL;
			}
		}
		pEnumPoints->Release();
	}
	pContainer->Release();
	return pPoint;
}

void CScriptBase::FreeEventChainObject(FREECHAIN *firstchain)
{
	FREECHAIN *chain;

	for(;;){
		DISPATCHSTRUCT *disps;

		chain = firstchain->next;
		if ( chain == NULL ) break;
		disps = reinterpret_cast<DISPATCHSTRUCT *>(chain->value);
		if ( disps != NULL ) disps->pEventSink->Disconnect();
	}
}

HRESULT CScriptBase::CatVariantStrings(WCHAR **strptr, size_t *strtail, size_t *strbuflen, VARIANT *arg)
{
	VARIANTARG tmparg;
	UINT len;

	tmparg.vt = VT_EMPTY;
	if ( arg->vt == VT_BSTR ){
		len = ::SysStringLen(arg->bstrVal);
	}else{
		HRESULT hr;

		VariantInit(&tmparg);
		if ( arg->vt == VT_NULL ){
			tmparg.bstrVal = L"(null)"; // VT_EMPTY のままなので、Clearされない
			len = 6;
		}else if ( FAILED(hr = VariantChangeType(&tmparg, arg, 0, VT_BSTR)) ){
			return hr;
		}else{
			len = ::SysStringLen(tmparg.bstrVal);
		}
		arg = &tmparg;
	}

	if ( (*strtail + len + 8) >= *strbuflen ){ // 連結用の空白を含めた空き確認
		size_t newbuflen;
		WCHAR *newstr;

		newbuflen = *strbuflen + len + 8;
		newstr = (WCHAR *)HeapReAlloc(GetProcessHeap(), 0, *strptr, newbuflen * sizeof(WCHAR));
		if ( newstr == NULL ){
			if ( tmparg.vt != VT_EMPTY ) VariantClear(&tmparg);
			return E_OUTOFMEMORY;
		}
		*strptr = newstr;
		*strbuflen = newbuflen;
	}

	if ( len > 0 ){
		memcpy(*strptr + *strtail, arg->bstrVal, len * sizeof(WCHAR) + sizeof(WCHAR));
		*strtail += len;
	}
	if ( tmparg.vt != VT_EMPTY ) VariantClear(&tmparg);
	return S_OK;
}

HRESULT  CScriptBase::SinkDispatch(IDispatch *pDisp, BSTR prefix, BOOL connect)
{
	IID eventID;
	HRESULT hr;

	if ( (prefix == NULL) || (prefix[0] == '\0') ){ // prefix がないとき
		return connect ? E_INVALIDARG : S_OK;
	}
	if ( pDisp == NULL ) return E_INVALIDARG;

	DISPATCHSTRUCT *disps = new DISPATCHSTRUCT;
	if ( disps == NULL ) return E_OUTOFMEMORY;

	disps->pDisp = pDisp;
	disps->pEventSink = NULL;
	disps->chain.value = NULL;
	disps->chain.next = NULL;
	disps->ppxa = ppxa;

	IConnectionPoint *pPoint = GetEventID(disps->pDisp, eventID);
	if ( pPoint != NULL ){
		disps->pEventSink = new CEventSink(disps, m_InstanceValue->Engine, prefix, &m_EventChain);
		if ( disps->pEventSink == NULL ){
			pPoint->Release();
			delete disps;
			return E_OUTOFMEMORY;
		}

		if ( FAILED(hr = disps->pEventSink->Connect(pPoint)) ){ // pPoint の生存管理は、CEventSink で行う
			disps->pEventSink->Release();
			// delete disps; // disps->pEventSink->Release で実行済み
			return hr;
		}
		disps->chain.value = reinterpret_cast<void *>(disps);
		disps->chain.next = m_EventChain.next;
		m_EventChain.next = &disps->chain;
	}else{
		delete disps;
		return connect ? CONNECT_E_NOCONNECTION : S_OK;
	}

	ITypeInfo *pType;
	ITypeInfo *pEventType = NULL;
	TYPEATTR *attr;

	if ( GetTypeInfoAttr(pDisp, &pType, &attr, &pEventType, &eventID) ){
		if ( pEventType != NULL ){
			disps->pEventSink->SetEventInfo(pEventType);
		}
		pType->ReleaseTypeAttr(attr);
		pType->Release();
	}
	return S_OK;
}

STDMETHODIMP CScriptBase::Include(BSTR filename)
{
	WCHAR *script, *IncludeNames;
	HRESULT hr;

	script = LoadScriptFile(filename);
	if ( script == NULL ) return E_ACCESSDENIED;

	// 各 SetScriptState の結果は意図して無視中。
	m_InstanceValue->Engine->SetScriptState(SCRIPTSTATE_INITIALIZED);

	int srclen = (m_InstanceValue->IncludeNames == NULL) ? 0 : wcslen(m_InstanceValue->IncludeNames);
	IncludeNames = new WCHAR[wcslen(filename) + srclen + 4];
	if ( IncludeNames == NULL ){
		delete[] script;
		return E_OUTOFMEMORY;
	}
	if ( srclen ){
		wcscpy(IncludeNames, m_InstanceValue->IncludeNames);
		IncludeNames[srclen++] = '\1';
		delete[] m_InstanceValue->IncludeNames;
	}
	m_InstanceValue->IncludeNames = IncludeNames;
	wcscpy(IncludeNames + srclen, filename);

	hr = m_InstanceValue->Parser->ParseScriptText(script, NULL, NULL, NULL,
			m_InstanceValue->SourceIDserver++, 0, SCRIPTTEXT_ISVISIBLE, NULL, NULL);
	if ( SUCCEEDED(hr) ){
		m_InstanceValue->Engine->SetScriptState(SCRIPTSTATE_STARTED);
	}
	delete[] script;
	return hr;
}

STDMETHODIMP CScriptBase::CreateObject(BSTR bstrProgId, BSTR bstrPrefix, IDispatch **ppObject)
{
	CLSID clsidObject;
	HRESULT hr;

	if ( bstrProgId == NULL ) return E_INVALIDARG;
	if ( FAILED(hr = ::CLSIDFromProgID(bstrProgId, &clsidObject)) ){
		*ppObject = NULL;
		return hr;
	}
	if ( FAILED(hr = ::CoCreateInstance(clsidObject, 0,
		CLSCTX_ALL, IID_IDispatch, reinterpret_cast<void**>(ppObject))) ){
		*ppObject = NULL;
		return hr;
	}
	if ( FAILED(hr = SinkDispatch(*ppObject, bstrPrefix, FALSE)) ){
		(*ppObject)->Release();
		*ppObject = NULL;
	}
	return hr;
}

STDMETHODIMP CScriptBase::GetObject(BSTR bstrPathName, BSTR bstrProgId, BSTR bstrPrefix, IDispatch **ppObject)
{
	HRESULT hr;

	if ( bstrPathName == NULL ) return E_INVALIDARG;
	if ( (bstrProgId == NULL) || (bstrProgId[0] == '\0') ){
		if ( FAILED(hr = ::CoGetObject(bstrPathName, 0, IID_IDispatch, reinterpret_cast<void**>(ppObject))) ){
			*ppObject = NULL;
			return hr;
		}
	}else{	// GetInstanceFromFile を使う
		CLSID clsidObject;
		MULTI_QI mq = { &IID_IDispatch, NULL, 0 };

		if ( FAILED(hr = ::CLSIDFromProgID(bstrProgId, &clsidObject)) ){
			*ppObject = NULL;
			return hr;
		}
		if ( FAILED(hr = ::CoGetInstanceFromFile(0, &clsidObject, 0, CLSCTX_ALL,
			STGM_READWRITE, bstrPathName, 1, &mq)) ){
			*ppObject = NULL;
			return hr;
		}

		if ( FAILED(mq.hr) || (mq.pItf == NULL) ){
			*ppObject = NULL;
			return FAILED(mq.hr) ? mq.hr : E_NOINTERFACE;
		}

		hr = mq.pItf->QueryInterface(IID_IDispatch,
				reinterpret_cast<void**>(ppObject));
		mq.pItf->Release();
		if ( FAILED(hr) ){
			*ppObject = NULL;
			return hr;
		}
	}
	if ( FAILED(hr = SinkDispatch(*ppObject, bstrPrefix, FALSE)) ){
		(*ppObject)->Release();
		*ppObject = NULL;
	}
	return hr;
}

CEventSink *FindCEventSink(FREECHAIN *chain, IDispatch *pObject)
{
	FREECHAIN *nextchain;

	for(;;){
		nextchain = chain->next;
		if ( nextchain == NULL ) return NULL;
		if ( reinterpret_cast<DISPATCHSTRUCT *>(nextchain->value)->pDisp == pObject ){
			return reinterpret_cast<DISPATCHSTRUCT *>(nextchain->value)->pEventSink;
		}
		chain = nextchain;
	}
}

STDMETHODIMP CScriptBase::ConnectObject(IDispatch *pObject, BSTR bstrPrefix)
{
	if ( bstrPrefix == NULL ) return E_INVALIDARG;
	if ( bstrPrefix[0] == '@' ){
		CEventSink *pSink = FindCEventSink(&m_EventChain, pObject);
		if ( pSink != NULL ){
			if ( wcscmp(bstrPrefix + 1, L"trace") == 0 ){
				pSink->SetEventTrace(1);
			}
			return S_OK;
		}
		return E_FAIL;
	}
	return SinkDispatch(pObject, bstrPrefix, TRUE);
}

STDMETHODIMP CScriptBase::DisconnectObject(IDispatch *pObject)
{
	CEventSink *pSink = FindCEventSink(&m_EventChain, pObject);
	if ( pSink != NULL ){
		pSink->Disconnect();
		return S_OK;
	}
	return E_FAIL;
}

//-------------------------------------------------- WScript 系 - その他
STDMETHODIMP CScriptBase::get_ScriptFullName(BSTR *Value)
{
	*Value = ::SysAllocString(m_InstanceValue->ScriptName);
	return S_OK;
}

STDMETHODIMP CScriptBase::get_ScriptName(BSTR *Value)
{
	*Value = ::SysAllocString(m_InstanceValue->ScriptName);
	return S_OK;
}

STDMETHODIMP CScriptBase::get_Arguments(IArguments **Value)
{
	if ( m_InstanceValue->ArgumentsTypeInfo == NULL ){
		HRESULT hr;

		if ( FAILED(hr = ::LoadSelfTypeInfo(&m_InstanceValue->ArgumentsTypeInfo, CLSID_IArguments_Class)) ){
			return hr;
		}
	}
	*Value = new CArguments(&(m_InstanceValue->ppxa), m_InstanceValue->ArgumentsTypeInfo, m_InstanceValue->arg.param, m_InstanceValue->arg.count);
	if ( *Value == NULL ) return E_OUTOFMEMORY;
	(*Value)->AddRef();
	return S_OK;
}

STDMETHODIMP CScriptBase::Argument(long itemindex, BSTR *Value)
{
	return GetArgumentItem(m_InstanceValue->ppxa, m_InstanceValue->arg.param, itemindex, m_InstanceValue->arg.count, Value);
}

STDMETHODIMP CScriptBase::Echo(SAFEARRAY *parr)
{
	long maxindex, minindex;
	VARIANT *args;
	WCHAR *msg;
	size_t msgmax = CMDLINESIZE;
	HRESULT hr;

	if ( parr == NULL ){
		::PopupMessage(ppxa, L"(null)");
		return S_OK;
	}

	hr = ::SafeArrayAccessData(parr, reinterpret_cast<void**>(&args));
	if ( FAILED(hr) ) return hr;
	if ( !(parr->fFeatures & FADF_VARIANT) ||
		 (parr->cDims != 1) ||
		 FAILED(::SafeArrayGetLBound(parr, 1, &minindex)) ||
		 FAILED(::SafeArrayGetUBound(parr, 1, &maxindex)) ){
		::SafeArrayUnaccessData(parr);
		return E_INVALIDARG;
	}
	maxindex -= minindex;

		msg = (WCHAR *)HeapAlloc(GetProcessHeap(), 0, msgmax * sizeof(WCHAR));
	if ( msg != NULL ){
		int index;
		size_t msgoffset = 0;

		for ( index = 0; index <= maxindex; index++ ){
			if ( FAILED(hr = CatVariantStrings(&msg, &msgoffset, &msgmax, &args[index])) ){
					break;
				}
			// 項目間の空白。CatVariantStrings でメモリ確保済み
				if ( index < maxindex ) msg[msgoffset++] = L' ';
			}
		msg[msgoffset] = L'\0';

		::PopupMessage(ppxa, msg);
		HeapFree(GetProcessHeap(), 0, msg);
	}else{
		hr = E_OUTOFMEMORY;
		}
		::SafeArrayUnaccessData(parr);
	return hr;
}

STDMETHODIMP CScriptBase::Quit(long nErrorCode)
{
	Var_ResultStatus = nErrorCode;

	if ( m_InstanceValue->Js9ForceCloseMode > 0 ){ // JScript9/Chakra はここでCloseを行うと、異常終了するので、エラー終了で無理矢理終わらせる
		m_InstanceValue->Js9ForceCloseMode = -1;
		return E_INVALIDARG;
	}

	// 各 SetScriptState の結果は意図して無視中。
	m_InstanceValue->Engine->SetScriptState(SCRIPTSTATE_DISCONNECTED);
	m_InstanceValue->Engine->SetScriptState(SCRIPTSTATE_CLOSED);

//	Messagef("%x", m_InstanceValue->Engine->InterruptScriptThread(SCRIPTTHREADID_BASE, NULL, 0));
//	m_Engine->InterruptScriptThread(SCRIPTTHREADID_ALL, &ei, 0)); // E_NOTIMPL
	return S_OK;
}

STDMETHODIMP CScriptBase::Sleep(long nMilliseconds)
{
	if ( nMilliseconds < 0 ) nMilliseconds = 0;
	::Sleep(nMilliseconds);
	return S_OK;
}

//-------------------------------------------------- PPx 独自系
STDMETHODIMP CScriptBase::get_WindowDirection(long *Value)
{
	ppxa->Function(ppxa, PPXCMDID_WINDOWDIR, Value);
	return S_OK;
}

STDMETHODIMP CScriptBase::get_result(BSTR *Value)
{
	const WCHAR *resulttext;

	resulttext = m_InstanceValue->arg.resultstring;
	if ( resulttext == NULL ){
		resulttext = ::NilStrW;
	}else if ( m_ScriptLongResult != NULL ){
		resulttext = m_ScriptLongResult;
	}
	*Value = ::SysAllocString(resulttext);
	return S_OK;
}

STDMETHODIMP CScriptBase::set_result(BSTR Value)
{
	WCHAR *resulttext;

	resulttext = m_InstanceValue->arg.resultstring;
	if ( resulttext == NULL ) return S_OK;
	if ( m_ScriptLongResult != NULL ){
		::SysFreeString(m_ScriptLongResult);
		m_ScriptLongResult = NULL;
	}
	if ( Value == NULL ){
		resulttext[0] = '\0';
	}else if ( wcslen(Value) >= (CMDLINESIZE - 1) ){
		m_ScriptLongResult = ::SysAllocString(Value);
		if ( m_ScriptLongResult == NULL ) return E_OUTOFMEMORY;
		resulttext[0] = '\0';
	}else{
		wcscpy(resulttext, Value);
	}
	return S_OK;
}

STDMETHODIMP CScriptBase::get_DirectoryType(long *Value)
{
	ppxa->Function(ppxa, PPXCMDID_DIRTYPE, Value);
	return S_OK;
}

STDMETHODIMP CScriptBase::get_SyncView(long *Value)
{
	ppxa->Function(ppxa, PPXCMDID_SYNCVIEW, Value);
	return S_OK;
}

STDMETHODIMP CScriptBase::set_SyncView(long Value)
{
	ppxa->Function(ppxa, PPXCMDID_SETSYNCVIEW, &Value);
	return S_OK;
}

STDMETHODIMP CScriptBase::get_SlowMode(long *Value)
{
	ppxa->Function(ppxa, PPXCMDID_SLOWMODE, Value);
	return S_OK;
}

STDMETHODIMP CScriptBase::set_SlowMode(long Value)
{
	ppxa->Function(ppxa, PPXCMDID_SETSLOWMODE, &Value);
	return S_OK;
}

STDMETHODIMP CScriptBase::get_ModuleVersion(long *Value)
{
	*Value = SCRIPTMODULEVER;
	return S_OK;
}

STDMETHODIMP CScriptBase::get_PPxVersion(long *Value)
{
	*Value = static_cast<long>(ppxa->Function(ppxa, PPXCMDID_VERSION, NULL));
	return S_OK;
}

STDMETHODIMP CScriptBase::get_CodeType(long *Value)
{
	*Value = static_cast<long>(ppxa->Function(ppxa, PPXCMDID_CHARTYPE, NULL));
	return S_OK;
}

STDMETHODIMP CScriptBase::get_EntryDisplayTop(long *Value)
{
	ppxa->Function(ppxa, PPXCMDID_CSRDINDEX, Value);
	return S_OK;
}

STDMETHODIMP CScriptBase::set_EntryDisplayTop(long Value)
{
	ppxa->Function(ppxa, PPXCMDID_CSRSETDINDEX, &Value);
	return S_OK;
}

STDMETHODIMP CScriptBase::get_EntryDisplayX(long *Value)
{
	ppxa->Function(ppxa, PPXCMDID_CSRDISPW, Value);
	return S_OK;
}

STDMETHODIMP CScriptBase::get_EntryDisplayY(long *Value)
{
	ppxa->Function(ppxa, PPXCMDID_CSRDISPH, Value);
	return S_OK;
}

STDMETHODIMP CScriptBase::get_WindowIDName(BSTR *Value)
{
	WCHAR bufW[REGEXTIDSIZE];

	if ( m_InstanceValue->IDNameMode == 0 ){
		*Value = ::SysAllocString(ppxa->RegID);
		return S_OK;
	}
	if ( (ppxa->Function(ppxa, PPXCMDID_GETSUBID, &bufW) == PPXA_INVALID_FUNCTION) || ((UTCHAR)bufW[0] > 'z') ){
		if ( ppxa->RegID[1] != '_' ){
			*Value = ::SysAllocString(ppxa->RegID);
			return S_OK;
		}
		bufW[0] = ppxa->RegID[0];
		strcpyW(bufW + 1, ppxa->RegID + 2);
	}
	*Value = ::SysAllocString(bufW);
	return S_OK;
}

STDMETHODIMP CScriptBase::set_WindowIDName(BSTR Value)
{
	m_InstanceValue->IDNameMode = ((Value != NULL) && Value[0] == '_') ? 0 : 1;
	return S_OK;
}

STDMETHODIMP CScriptBase::Execute(BSTR param, long *result)
{
	ERRORCODE resultcode;

	if ( param == NULL ){
		if ( result != NULL ) *result = NO_ERROR;
		return S_OK;
	}
	resultcode = static_cast<ERRORCODE>(ppxa->Function(ppxa, PPXCMDID_EXECUTE, param));
	if ( result != NULL ){
		if ( resultcode <= 1 ) resultcode ^= 1;
		*result = resultcode;
	}
	return S_OK;
}

STDMETHODIMP CScriptBase::SetPopLineMessage(BSTR message)
{
	ppxa->Function(ppxa, PPXCMDID_SETPOPLINE, (message != NULL) ? message : L"");
	return S_OK;
}

STDMETHODIMP CScriptBase::lineMessage(BSTR message)
{
	ppxa->Function(ppxa, PPXCMDID_SETPOPLINE, (message != NULL) ? message : L"");
	return S_OK;
}

STDMETHODIMP CScriptBase::report(BSTR message)
{
	ppxa->Function(ppxa, PPXCMDID_REPORTTEXT, (message != NULL) ? message : L"");
	return S_OK;
}

STDMETHODIMP CScriptBase::log(BSTR message)
{
	ppxa->Function(ppxa, PPXCMDID_DEBUGLOG, (message != NULL) ? message : L"");
	return S_OK;
}

STDMETHODIMP CScriptBase::Extract(BSTR param, BSTR *result)
{
	WCHAR *bufw, bufwtmp[CMDLINESIZE];
	size_t paramlen;

	if ( param == NULL ){
		tprintfW(bufwtmp, L"%d", m_extract_result);
		*result = ::SysAllocString(bufwtmp);
		return S_OK;
	}

	paramlen = wcslen(param) + 1;
	bufw = (paramlen < CMDLINESIZE) ? bufwtmp : new WCHAR[paramlen];
	wcscpy(bufw, param);

		// 1.92 以降
	*result = (BSTR)ppxa->Function(ppxa, PPXCMDID_LONG_EXTRACT_E, bufw);
	if ( *result == NULL ){ // 1.69 以降にフォールバック
		*result = (BSTR)ppxa->Function(ppxa, PPXCMDID_LONG_EXTRACT, bufw);
		if ( *result == NULL ){ // 1.68 以前にフォールバック
			ppxa->Function(ppxa, PPXCMDID_EXTRACT, bufw);
			*result = ::SysAllocString(bufw);
			if ( bufw != bufwtmp ) delete[] bufw;
			return S_OK;
		}
	}

	if ( bufw != bufwtmp ) delete[] bufw;

	if ( ((DWORD_PTR)*result & ~(DWORD_PTR)0xffff) == 0 ){
		// *result は 16bit に収まるエラーコード
		m_extract_result = (ERRORCODE)(DWORD_PTR)*result;
		*result = ::SysAllocString(::NilStrW);
	}else{
		// *result は BSTR の結果
		m_extract_result = NO_ERROR;
	}
	return S_OK;
}

STDMETHODIMP CScriptBase::GetFileInformation(BSTR param, long Mode, BSTR *result)
{
	WCHAR bufw[CMDLINESIZE];

	if ( param == NULL ){
		*result = NULL;
		return E_INVALIDARG;
	}
	*(DWORD *)bufw = Mode;
	bufw[sizeof(DWORD) / sizeof(WCHAR)] = '\0';
	stplimcpyW(bufw + 2, param, CMDLINESIZE - 2);
	ppxa->Function(ppxa, PPXCMDID_GETFILEINFO, bufw);
	*result = ::SysAllocString(bufw + 2);
	return S_OK;
}

STDMETHODIMP CScriptBase::option(BSTR, VARIANT, VARIANT *result)
{
	result->vt = VT_NULL;
	return S_OK;
}

STDMETHODIMP CScriptBase::LoadCount(long type, long *count)
{
	*count = type;
	ppxa->Function(ppxa, PPXCMDID_DIRLOADCOUNT, count);
	return S_OK;
}

STDMETHODIMP CScriptBase::GetComboItemCount(long id, long *result)
{
	long buf;

	buf = id;
	ppxa->Function(ppxa, PPXCMDID_COMBOIDCOUNT, &buf);
	*result = buf;
	return S_OK;
}

STDMETHODIMP CScriptBase::get_EntryAllCount(long *Value)
{
	ppxa->Function(ppxa, PPXCMDID_DIRTOTAL, Value);
	return S_OK;
}

STDMETHODIMP CScriptBase::get_EntryDisplayCount(long *Value)
{
	ppxa->Function(ppxa, PPXCMDID_DIRTTOTAL, Value);
	return S_OK;
}

STDMETHODIMP CScriptBase::get_EntryMarkCount(long *Value)
{
	ppxa->Function(ppxa, PPXCMDID_DIRMARKS, Value);
	return S_OK;
}

STDMETHODIMP CScriptBase::get_EntryDisplayFiles(long *Value)
{
	ppxa->Function(ppxa, PPXCMDID_DIRTTOTALFILE, Value);
	return S_OK;
}

STDMETHODIMP CScriptBase::get_EntryDisplayDirectories(long *Value)
{
	ppxa->Function(ppxa, PPXCMDID_DIRTTOTALDIR, Value);
	return S_OK;
}

STDMETHODIMP CScriptBase::get_Entry(IEntry ** Value)
{
	if ( m_InstanceValue->EntryTypeInfo == NULL ){
		HRESULT hr;

		if ( FAILED(hr = ::LoadSelfTypeInfo(&m_InstanceValue->EntryTypeInfo, CLSID_IEntry_Class)) ){
			return hr;
		}
	}
	*Value = new CEntry(m_InstanceValue);
	if ( *Value == NULL ) return E_OUTOFMEMORY;
	(*Value)->AddRef();
	return S_OK;
}

STDMETHODIMP CScriptBase::get_Pane(IPane **Value)
{
	if ( m_InstanceValue->PaneTypeInfo == NULL ){
		HRESULT hr;

		if ( FAILED(hr = ::LoadSelfTypeInfo(&m_InstanceValue->PaneTypeInfo, CLSID_IPane_Class)) ){
			return hr;
		}
	}
	*Value = new CPane(m_InstanceValue);
	if ( *Value == NULL ) return E_OUTOFMEMORY;
	(*Value)->AddRef();
	return S_OK;
}

//-------------------------------------------------- PPx 独自系 - カーソル位置
STDMETHODIMP CScriptBase::get_EntryIndex(long *Value)
{
	ppxa->Function(ppxa, PPXCMDID_CSRINDEX, Value);
	return S_OK;
}

STDMETHODIMP CScriptBase::set_EntryIndex(long Value)
{
	ppxa->Function(ppxa, PPXCMDID_CSRSETINDEX, &Value);
	return S_OK;
}

STDMETHODIMP CScriptBase::get_EntryName(BSTR *result)
{
	WCHAR bufw[CMDLINESIZE];
	PPXCMDENUMSTRUCTW info;

	bufw[0] = '\0';
	info.buffer = bufw;
	ppxa->Function(ppxa, 'R', &info);
	*result = ::SysAllocString(bufw);
	return S_OK;
}

STDMETHODIMP CScriptBase::get_ComboIDName(BSTR *Value)
{
	WCHAR bufw[REGEXTIDSIZE];

	bufw[0] = '\0';
	ppxa->Function(ppxa, PPXCMDID_COMBOIDNAME, bufw);
	*Value = ::SysAllocString(bufw);
	return S_OK;
}

STDMETHODIMP CScriptBase::get_EntryAttributes(long *Value)
{
	ppxa->Function(ppxa, PPXCMDID_CSRATTR, Value);
	return S_OK;
}

STDMETHODIMP CScriptBase::get_EntrySize(double *Value)
{
	DWORD size[2];

	ppxa->Function(ppxa, PPXCMDID_CSRMSIZE, size);
	*Value = (double)size[0] + (double)size[1] * DWORDPP;

	return S_OK;
}

STDMETHODIMP CScriptBase::get_EntryMark(long *Value)
{
	ppxa->Function(ppxa, PPXCMDID_CSRMARK, Value);
	return S_OK;
}
STDMETHODIMP CScriptBase::set_EntryMark(long Value)
{
	ppxa->Function(ppxa, PPXCMDID_CSRSETMARK, &Value);
	return S_OK;
}

STDMETHODIMP CScriptBase::get_EntryState(long *Value)
{
	ppxa->Function(ppxa, PPXCMDID_CSRSTATE, Value);
	*Value &= 0x1f;
	return S_OK;
}

STDMETHODIMP CScriptBase::set_EntryState(long Value)
{
	long tmpvalue;

	ppxa->Function(ppxa, PPXCMDID_CSRSTATE, &tmpvalue);
	Value = (tmpvalue & 0xffe0) | Value;
	ppxa->Function(ppxa, PPXCMDID_CSRSETSTATE, &Value);
	return S_OK;
}

STDMETHODIMP CScriptBase::get_EntryHighlight(long *Value)
{
	ppxa->Function(ppxa, PPXCMDID_CSRSTATE, Value);
	*Value >>= 5;
	return S_OK;
}

STDMETHODIMP CScriptBase::set_EntryHighlight(long Value)
{
	long tmpvalue;

	ppxa->Function(ppxa, PPXCMDID_CSRSTATE, &tmpvalue);
	Value = (tmpvalue & 0x1f) | (Value << 5);
	ppxa->Function(ppxa, PPXCMDID_CSRSETSTATE, &Value);
	return S_OK;
}

STDMETHODIMP CScriptBase::get_EntryExtColor(long *Value)
{
	ppxa->Function(ppxa, PPXCMDID_CSREXTCOLOR, Value);
	return S_OK;
}

STDMETHODIMP CScriptBase::set_EntryExtColor(long Value)
{
	ppxa->Function(ppxa, PPXCMDID_CSRSETEXTCOLOR, &Value);
	return S_OK;
}

STDMETHODIMP CScriptBase::get_EntryComment(BSTR *Value)
{
	WCHAR bufw[CMDLINESIZE];

	bufw[0] = '\0';
	ppxa->Function(ppxa, PPXCMDID_CSRCOMMENT, bufw);
	*Value = ::SysAllocString(bufw);
	return S_OK;
}

STDMETHODIMP CScriptBase::set_EntryComment(BSTR Value)
{
	if ( PPXA_NO_ERROR == ppxa->Function(ppxa, PPXCMDID_CSRSETCOMMENT, (Value != NULL) ? Value : L"") ){
		return S_OK;
	}else{
		return E_FAIL;
	}
}

STDMETHODIMP CScriptBase::EntryFirstMark(long *result)
{
	if ( PPXA_NO_ERROR == ppxa->Function(ppxa, PPXCMDID_CSRMARKFIRST, result) ){
		return S_OK;
	}else{
		return E_FAIL;
	}
}

STDMETHODIMP CScriptBase::EntryNextMark(long *result)
{
	if ( PPXA_NO_ERROR == ppxa->Function(ppxa, PPXCMDID_CSRMARKNEXT, result) ){
		return S_OK;
	}else{
		return E_FAIL;
	}
}

STDMETHODIMP CScriptBase::EntryPrevMark(long *result)
{
	if ( PPXA_NO_ERROR == ppxa->Function(ppxa, PPXCMDID_CSRMARKPREV, result) ){
		return S_OK;
	}else{
		return E_FAIL;
	}
}

STDMETHODIMP CScriptBase::EntryLastMark(long *result)
{
	if ( PPXA_NO_ERROR == ppxa->Function(ppxa, PPXCMDID_CSRMARKLAST, result) ){
		return S_OK;
	}else{
		return E_FAIL;
	}
}

STDMETHODIMP CScriptBase::get_DriveVolumeLabel(BSTR *Value)
{
	WCHAR bufw[CMDLINESIZE];

	bufw[0] = '\0';
	ppxa->Function(ppxa, PPXCMDID_DRIVELABEL, bufw);
	*Value = ::SysAllocString(bufw);
	return S_OK;
}

STDMETHODIMP CScriptBase::get_EntryMarkSize(double *Value)
{
	DWORD size[2];

	ppxa->Function(ppxa, PPXCMDID_DIRMARKSIZE, size);
	*Value = (double)size[0] + (double)size[1] * DWORDPP;

	return S_OK;
}

STDMETHODIMP CScriptBase::get_DriveTotalSize(double *Value)
{
	DWORD size[2];

	ppxa->Function(ppxa, PPXCMDID_DRIVETOTALSIZE, size);
	*Value = (double)size[0] + (double)size[1] * DWORDPP;

	return S_OK;
}

STDMETHODIMP CScriptBase::get_DriveFreeSize(double *Value)
{
	DWORD size[2];

	ppxa->Function(ppxa, PPXCMDID_DRIVEFREE, size);
	*Value = (double)size[0] + (double)size[1] * DWORDPP;

	return S_OK;
}

STDMETHODIMP CScriptBase::EntryInsert(long index, BSTR entryname)
{
	DWORD_PTR dptrs[2];

	dptrs[0] = static_cast<DWORD_PTR>(index);
	dptrs[1] = (DWORD_PTR)(BSTR)((entryname != NULL) ? entryname : L"");
	ppxa->Function(ppxa, PPXCMDID_ENTRYINSERTMSG, dptrs);
	return S_OK;
}

BOOL TryOpenClipboard(HWND hWnd)
{
	int trycount = 6;

	for (;;){
		if ( IsTrue(OpenClipboard(hWnd)) ) return TRUE;
		if ( --trycount == 0 ) return FALSE;
		Sleep(20);
	}
}

STDMETHODIMP CScriptBase::get_Clipboard(BSTR *Value)
{
	HANDLE clipdata;
	WCHAR *src;

	*Value = NULL;
	if ( TryOpenClipboard(ppxa->hWnd) != FALSE ){
		clipdata = GetClipboardData(CF_UNICODETEXT);
		if ( clipdata != NULL ){
			src = (WCHAR *)GlobalLock(clipdata);
			if ( src != NULL ){
				*Value = ::SysAllocString(src);
				GlobalUnlock(clipdata);
			}
		}
		CloseClipboard();
	}
	if ( *Value != NULL ) return S_OK;
	*Value = ::SysAllocString(::NilStrW);
	return S_FALSE;
}

STDMETHODIMP CScriptBase::set_Clipboard(BSTR Value)
{
	HGLOBAL hm;
	size_t len;
	WCHAR *dest;

	len = SysStringByteLen(Value) + sizeof(WCHAR); // NIL分を追加する
	hm = GlobalAlloc(GMEM_MOVEABLE, len);
	if ( hm == NULL ) return E_OUTOFMEMORY;
	dest = (WCHAR *)GlobalLock(hm);
	if ( dest != NULL ){
		if ( Value != NULL ){
			memcpy(dest, Value, len);
		}else{
			dest[0] = '\0';
		}
		GlobalUnlock(hm);
		if ( TryOpenClipboard(ppxa->hWnd) != FALSE ){
			if ( EmptyClipboard() ){
				if ( SetClipboardData(CF_UNICODETEXT, hm) ) hm = NULL;
			}
			CloseClipboard();
		}
	}
	if ( hm == NULL ) return S_OK; // hm がなくなった: SetClipboardData が成功
	// hm が残っている: SetClipboardData が成功していない
	GlobalFree(hm);
	return S_FALSE;
}

STDMETHODIMP CScriptBase::get_StayMode(long *Value)
{
	*Value = m_InstanceValue->stay.mode;
	return S_OK;
}

STDMETHODIMP CScriptBase::set_StayMode(long Value)
{
	if ( Value < 0 ) return E_INVALIDARG;

	if ( Value >= ScriptStay_Stay ){
		if ( m_InstanceValue->stay.threadID == 0 ){
			Value = ChainStayInstance(m_InstanceValue, Value);
		}else{
			return S_OK; // 常駐済み、m_InstanceValue->stay.mode を変更しない
		}
	}else{
		if ( m_InstanceValue->stay.threadID != 0 ){
			DropStayInstance(m_InstanceValue);
		}
	}
	m_InstanceValue->stay.mode = Value;
	return S_OK;
}

STDMETHODIMP CScriptBase::get_PointType(long *Value)
{
	long var[3];

	if ( PPXA_NO_ERROR == ppxa->Function(ppxa, PPXCMDID_POINTINFO, var) ){
		*Value = var[0];
		return S_OK;
	}else{
		return E_INVALIDARG;
	}
}

STDMETHODIMP CScriptBase::get_PointIndex(long *Value)
{
	long var[3];

	if ( PPXA_NO_ERROR == ppxa->Function(ppxa, PPXCMDID_POINTINFO, var) ){
		*Value = var[1];
		return S_OK;
	}else{
		return E_INVALIDARG;
	}
}

STDMETHODIMP CScriptBase::Cursor(long x, long y, long *result) // [36]
{
	long var[4];

	if ( x < -1 ){
		if ( PPXA_NO_ERROR != ppxa->Function(ppxa, PPXCMDID_CSRLOCATE, var) ){
			return E_INVALIDARG;
		}
		if ( x == -2 ){
			*result = var[0];
		}else{
			*result = var[1];
		}
	}else{
		var[0] = x;
		var[1] = y;
		var[2] = 0;
		var[3] = 0;
		if ( PPXA_NO_ERROR == ppxa->Function(ppxa, PPXCMDID_CSRSETLOCATE, var) ){
			*result = 0;
		}else{
			return E_INVALIDARG;
		}
	}
	return S_OK;
}

STDMETHODIMP CScriptBase::get_ScriptEngineName(BSTR *Value) // [37]
{
	IActiveScriptProperty *ScriptProperty;

	*Value = NULL;
	if ( SUCCEEDED(m_InstanceValue->Engine->QueryInterface(IID_IActiveScriptProperty, (void**)&ScriptProperty)) ){
		VARIANT dummyvt;

		VariantInit(&dummyvt);
		dummyvt.vt = VT_BSTR;
		dummyvt.bstrVal = NULL;
		if ( SUCCEEDED(ScriptProperty->GetProperty(SCRIPTPROP_NAME, NULL, &dummyvt)) ){
			*Value = ::SysAllocString(dummyvt.bstrVal);
		}
		VariantClear(&dummyvt);
		ScriptProperty->Release();
	}
	return S_OK;
}

STDMETHODIMP CScriptBase::get_ScriptEngineVersion(BSTR *Value) // [40]
{
	IActiveScriptProperty *ScriptProperty;
	WCHAR buf[32];
	int major = 0, minor = 0, build = 0;

	if ( SUCCEEDED(m_InstanceValue->Engine->QueryInterface(IID_IActiveScriptProperty, (void**)&ScriptProperty)) ){
		VARIANT dummyvt;

		VariantInit(&dummyvt);
		dummyvt.vt = VT_I4;
		if ( SUCCEEDED(ScriptProperty->GetProperty(SCRIPTPROP_MAJORVERSION, NULL, &dummyvt)) ){
			major = dummyvt.lVal;
		}
		if ( SUCCEEDED(ScriptProperty->GetProperty(SCRIPTPROP_MINORVERSION, NULL, &dummyvt)) ){
			minor = dummyvt.lVal;
		}
		if ( SUCCEEDED(ScriptProperty->GetProperty(SCRIPTPROP_BUILDNUMBER, NULL, &dummyvt)) ){
			build = dummyvt.lVal;
		}
		VariantClear(&dummyvt);
		ScriptProperty->Release();
	}
	buf[0] = '\0';
	tprintfW(buf, L"%d.%d.%d", major, minor, build);
	*Value = ::SysAllocString(buf);
	return S_OK;
}

STDMETHODIMP CScriptBase::getValue(BSTR key, BSTR *Value)
{
	WCHAR *uptr[2], buf[CMDLINESIZE];

	if ( key == NULL ){
		*Value = NULL;
		return E_INVALIDARG;
	}
	uptr[0] = key;
	uptr[1] = buf;
	if ( PPXA_INVALID_FUNCTION == ppxa->Function(ppxa, PPXCMDID_GETPROCVARIABLEDATA, uptr) ){
		buf[0] = '\0';
	}
	*Value = ::SysAllocString(uptr[1]);
	if ( uptr[1] != buf ) HeapFree(GetProcessHeap(), 0, uptr[1]);
	return S_OK;
}

STDMETHODIMP CScriptBase::setValue(BSTR key, BSTR value)
{
	WCHAR *uptr[2];

	if ( key == NULL ) return E_INVALIDARG;
	uptr[0] = key;
	uptr[1] = (value != NULL) ? value : L"";
	ppxa->Function(ppxa, PPXCMDID_SETPROCVARIABLEDATA, uptr);
	return S_OK;
}

STDMETHODIMP CScriptBase::setProcessValue(BSTR key, BSTR value)
{
	return setValue(key, value);
}

STDMETHODIMP CScriptBase::getProcessValue(BSTR key, BSTR *Value)
{
	return getValue(key, Value);
}

STDMETHODIMP CScriptBase::setIValue(BSTR key, BSTR value)
{
	WCHAR *uptr[2];

	if ( key == NULL ) return E_INVALIDARG;
	uptr[0] = key;
	uptr[1] = (value != NULL) ? value : L"";
	ppxa->Function(ppxa, PPXCMDID_SETWNDVARIABLEDATA, uptr);
	return S_OK;
}

STDMETHODIMP CScriptBase::getIValue(BSTR key, BSTR *Value)
{
	WCHAR *uptr[2], buf[CMDLINESIZE];

	if ( key == NULL ){
		*Value = NULL;
		return E_INVALIDARG;
	}
	uptr[0] = key;
	uptr[1] = buf;
	if ( PPXA_INVALID_FUNCTION == ppxa->Function(ppxa, PPXCMDID_GETWNDVARIABLEDATA, uptr) ){
		buf[0] = '\0';
	}
	*Value = ::SysAllocString(uptr[1]);
	if ( uptr[1] != buf ) HeapFree(GetProcessHeap(), 0, uptr[1]);
	return S_OK;
}

void CScriptBase::SetResult(void)
{
	if ( m_ScriptLongResult != NULL ){
		WCHAR *resulttext;

		resulttext = m_InstanceValue->arg.resultstring;
		if ( resulttext != NULL ){
			if ( PPXA_NO_ERROR == ppxa->Function(ppxa, PPXCMDID_LONG_RESULT, m_ScriptLongResult) ){
				resulttext[0] = '\0';
			}else{
				wcscpy(resulttext, L"<length over>");
			}
		}
		::SysFreeString(m_ScriptLongResult);
		m_ScriptLongResult = NULL;
	}
}

STDMETHODIMP CScriptBase::get_ReentryCount(long *Value)
{
	*Value = m_InstanceValue->stay.entry;
	return S_OK;
}

void CScriptBase::UpdatePPxInfo(void)
{
	ppxa = m_InstanceValue->ppxa;
}

//=========================================================== PPx.Enumerator
class CPPxEnum : public IPPxEnum
{
public:
	CPPxEnum(IEnumVARIANT *object, ITypeInfo *EnumTypeInfo){
		m_refCount = 0;
		m_valid = -1;
		m_typeInfo = EnumTypeInfo;
		m_typeInfo->AddRef();
		VariantInit(&m_Item); // VT_EMPTY
		m_Enum = object;
		m_Enum->AddRef();
	}

// IUnknown
	STDMETHODIMP QueryInterface(REFIID iid, void **ppvObj)
	{
		if ( (iid == IID_IUnknown) || (iid == IID_IDispatch) ){
			*ppvObj = static_cast<IDispatch*>(this);
			AddRef();
			return S_OK;
		}
		*ppvObj = NULL;
		return E_NOINTERFACE;
	}

	STDMETHODIMP_(ULONG) AddRef(){
		return ++m_refCount;
	}

	STDMETHODIMP_(ULONG) Release(){
		if (--m_refCount == 0){
			VariantClear(&m_Item);
			m_Enum->Release();
			m_typeInfo->Release();
			delete this;
			return 0;
		}
		return m_refCount;
	}

// IDispatch
	STDMETHODIMP GetTypeInfoCount(UINT *iTInfo)
	{
		if ( iTInfo == NULL ) return E_NOTIMPL;
		*iTInfo = 1;
		return S_OK;
	}

	STDMETHODIMP GetTypeInfo(UINT iTInfo, LCID, ITypeInfo **ppTInfo)
	{
		if ( iTInfo != 0 ){
			*ppTInfo = NULL;
			return DISP_E_BADINDEX;
		}
		*ppTInfo = m_typeInfo;
		m_typeInfo->AddRef();
		return S_OK;
	}

	STDMETHODIMP GetIDsOfNames(REFIID riid, OLECHAR **rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId)
	{
		if ( riid != IID_NULL ) return E_INVALIDARG;
		return DispGetIDsOfNames(m_typeInfo, rgszNames, cNames, rgDispId);
	}

	STDMETHODIMP Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr);

	void getItem(void)
	{
		VARIANT value;
		HRESULT result;
		ULONG c = 0;

		VariantInit(&value);
		result = m_Enum->Next(1, &value, &c);
		if ( SUCCEEDED(result) && (c > 0) ){
			VariantClear(&m_Item);
			m_Item = value;
			m_valid = 1;
		}else{
			m_valid = 0;
		}
	}

// Enumerator
	STDMETHODIMP moveFirst(void)
	{
		VariantClear(&m_Item);
		m_valid = -1;

		HRESULT hr = m_Enum->Reset();
		if ( FAILED(hr) ) return hr;
		return S_OK;
	}

	STDMETHODIMP moveNext(long *Value)
	{
		if ( m_valid < 0 ) getItem(); // 未取得
		if ( m_valid == 0 ){
			*Value = 0;
		}else{
			VariantClear(&m_Item);
			m_valid = -1;
			*Value = 1;
		}
		return S_OK;
	}

	STDMETHODIMP atEnd(long *Value)
	{
		if ( m_valid == 0 ){ // 末尾到達済み
			*Value = 1;
		}else{
			if ( m_valid < 0 ) getItem(); // 未取得
			*Value = (m_valid <= 0) ? 1 : 0;
		}
		return S_OK;
	}

	STDMETHODIMP Item(long index, VARIANT* Value);

// その他
	STDMETHODIMP get_index(long *Value)
	{
		return E_NOTIMPL;
	}

	STDMETHODIMP set_index(long Value)
	{
		return E_NOTIMPL;
	}

	STDMETHODIMP Reset()
	{
		return moveFirst();
	}

private:
	IEnumVARIANT *m_Enum;
	VARIANT m_Item;
	ITypeInfo *m_typeInfo;
	int m_refCount;
	int m_valid; // m_Item の状態, 負: 未取得, 0: 末尾到着, 正: 取得済み
};

STDMETHODIMP CPPxEnum::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr)
{
	int arg;
	HRESULT hr;

	if ( riid != IID_NULL ) return DISP_E_UNKNOWNINTERFACE;
									// Function/Get Properties ----------------
	if ( wFlags & (DISPATCH_PROPERTYGET | DISPATCH_METHOD) ){
		if ( pVarResult == NULL ){
			VARIANT dummyvt;

			VariantInit(&dummyvt);
			hr = Invoke(dispIdMember, riid, lcid, wFlags, pDispParams, &dummyvt, pExcepInfo, puArgErr);
			VariantClear(&dummyvt);
			return hr;
		}

		switch (dispIdMember){
			case DISPID_VALUE:
			{
				int index;

				if ( pDispParams->cArgs == 0 ){
					index = -1;
				}else{
					FixArgType(0, VT_I4);
					index = pDispParams->rgvarg[0].lVal;
				}
				return Item(index, pVarResult);
			}

			case 1:
				ArgsCheck(0);
				return moveFirst();

			case 2:
				ArgsCheck(0);
				pVarResult->vt = VT_I4;
				return moveNext(&pVarResult->lVal);

			case 3:
				ArgsCheck(0);
				pVarResult->vt = VT_I4;
				return atEnd(&pVarResult->lVal);

			case 4:
				ArgsCheck(0);
				return Reset();
		}
	}
	Debug_InvokeUnknownDispIID(CLASSNAMES, dispIdMember, wFlags);
	return DISP_E_MEMBERNOTFOUND;

ArgConvError:
	if ( puArgErr != NULL ) *puArgErr = arg;
	return hr;
}

// 現在 index による指定は未実装
STDMETHODIMP CPPxEnum::Item(long index, VARIANT *Value)
{
	if ( index >= 0 ) return E_NOTIMPL;
	if ( m_valid <= 0 ){
		if ( m_valid == 0 ) return E_FAIL;
		getItem();
		if ( m_valid == 0 ) return E_FAIL;
	}
	return VariantCopy(Value, &m_Item);
}

STDMETHODIMP CScriptBase::Enumerator(LPDISPATCH object, LPDISPATCH *Value)
{
	DISPPARAMS params;
	HRESULT result;
	VARIANT resultvalue;
	IEnumVARIANT *pEnumVariant = NULL;

	if ( object == NULL ) return E_INVALIDARG;
	if ( m_InstanceValue->PPxEnumTypeInfo == NULL ){
		if ( FAILED(result = ::LoadSelfTypeInfo(&m_InstanceValue->PPxEnumTypeInfo, CLSID_IPPxEnum_Class)) ){
			return result;
		}
	}

	params.rgvarg = NULL;
	params.rgdispidNamedArgs = NULL;
	params.cArgs = 0;
	params.cNamedArgs = 0;
	VariantInit(&resultvalue);

	result = object->Invoke(DISPID_NEWENUM, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &params, &resultvalue, NULL, NULL);
	if ( FAILED(result) ) return result;

	if ( ((resultvalue.vt == VT_UNKNOWN) || (resultvalue.vt == VT_DISPATCH)) &&
		 (resultvalue.punkVal != NULL) ){
		result = resultvalue.punkVal->QueryInterface(IID_IEnumVARIANT, (void **)&pEnumVariant);
	}else{
		result = E_NOINTERFACE;
	}
	VariantClear(&resultvalue);

	if ( FAILED(result) ) return result;
	if ( pEnumVariant == NULL ) return E_NOINTERFACE;

	*Value = new CPPxEnum(pEnumVariant, m_InstanceValue->PPxEnumTypeInfo);
	pEnumVariant->Release();
	if ( *Value == NULL ) return E_OUTOFMEMORY;
	(*Value)->AddRef();
	return S_OK;
}
