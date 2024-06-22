/*-----------------------------------------------------------------------------
	Paper Plane xUI  Script Module				ITab(PPcƒ^ƒu)
-----------------------------------------------------------------------------*/
#define STRICT
#include <windows.h>
#include <activscp.h>
#include "ppxscr.h"
#pragma hdrstop
#include "PPxScr_TLB.h"
#include "ITab.h"

#define CLASSNAME CTab
#define CLASSNAMES "CTab"
CTab::CTab(InstanceValueStruct *InstanceValue, int paneindex)
{
	T_IUNKNOWN_INITDEFINE();
	m_typeInfo = NULL;
	m_PaneIndex = paneindex;
	m_TabIndex = -1;
	m_EnumIndex = 0;
	m_InstanceValue = InstanceValue;
	m_ppxa = &(InstanceValue->ppxa);

	if ( FAILED(::LoadTypeInfo(&m_typeInfo, CLSID_ITab_Class, 0)) ){
		::PopupMessage(InstanceValue->ppxa, UNICODESTR(CLASSNAMES) UNICODESTR(" load error"));
	}
}

//----------------------------------------------------- IUnknown
T_IUNKNOWN_ADDREFDEFINE(CLASSNAME);
T_IDISPATCH_RELEASEDEFINE(CLASSNAME);
STDMETHODIMP CTab::QueryInterface(REFIID iid, void **ppv)
{
	if ( (iid == IID_IUnknown) || (iid == IID_ITab) ){
		*ppv = static_cast<ITab*>(this);
		AddRef();
		return S_OK;
	}
	if ( iid == IID_IDispatch ){
		*ppv = static_cast<IDispatch*>(this);
		AddRef();
		return S_OK;
	}
	Debug_DispIID(CLASSNAMES "::QueryInterface - false:", iid); \
		*ppv = NULL;
	return E_NOINTERFACE;
}

//----------------------------------------------------- IDispatch
STDMETHODIMP CTab::GetTypeInfoCount(UINT *iTInfo)
{
	Debug_WriteLog(CLASSNAMES "::GetTypeInfoCount", NULL);
	if ( (DWORD_PTR)iTInfo < 0x10000 ) return E_NOTIMPL;
	*iTInfo = 1;
	return S_OK;
}

STDMETHODIMP CTab::GetTypeInfo(UINT, LCID, ITypeInfo **ppTInfo)
{
	Debug_WriteLog(CLASSNAMES "::GetTypeInfo", NULL);
	m_typeInfo->AddRef();
	*ppTInfo = m_typeInfo;
	return S_OK;
}

STDMETHODIMP CTab::GetIDsOfNames(REFIID riid, OLECHAR **rgszNames, UINT cNames, LCID, DISPID *rgDispId)
{
	Debug_WriteLog(CLASSNAMES "::GetIDsOfNames:", *rgszNames);
	if ( riid != IID_NULL ) return E_INVALIDARG;
	return DispGetIDsOfNames(m_typeInfo, rgszNames, cNames, rgDispId);
}

STDMETHODIMP CTab::Invoke(DISPID dispIdMember, REFIID riid, LCID lc, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO * ei, unsigned int *puArgErr)
{
	int arg;
	HRESULT hr;

	Debug_WriteLog(CLASSNAMES "::Invoke", NULL);
	if ( riid != IID_NULL ) return DISP_E_UNKNOWNINTERFACE;
									// Function/Get Properties ----------------
	if ( wFlags & (DISPATCH_PROPERTYGET | DISPATCH_METHOD) ){
		if ( pVarResult == NULL ){
			VARIANT dummyvt;

			VariantInit(&dummyvt);
			hr = Invoke(dispIdMember, riid, lc, wFlags, pDispParams, &dummyvt, ei, puArgErr);
			VariantClear(&dummyvt);
			return hr;
		}
		switch (dispIdMember){
			case 13:
				ArgsCheck(1);
				FixArgType(0, VT_BSTR);
				pVarResult->vt = VT_I4;
				return IndexFrom(pDispParams->rgvarg[0].bstrVal, &pVarResult->lVal);

			case 14:
				ArgsCheck(1);
				FixArgType(0, VT_BSTR);
				if ( wFlags & DISPATCH_METHOD ){
					if ( pVarResult != NULL ) pVarResult->vt = VT_EMPTY;
					return Execute(pDispParams->rgvarg[0].bstrVal, NULL);
				} else{
					pVarResult->vt = VT_I4;
					return Execute(pDispParams->rgvarg[0].bstrVal, &pVarResult->lVal);
				}

			case 16:
				ArgsCheck(0);
				pVarResult->vt = VT_I4;
				return moveNext(&pVarResult->lVal);

			case 17:
				ArgsCheck(0);
				pVarResult->vt = VT_I4;
				return atEnd(&pVarResult->lVal);

			case 18:
				ArgsCheck(0);
				return Reset();
		}
	}

	if ( wFlags & DISPATCH_PROPERTYGET ){
		switch ( dispIdMember ){
			case DISPID_VALUE:
			{
				int index;

				pVarResult->vt = VT_UNKNOWN;
				if ( pDispParams->cArgs == 0 ){
					index = m_TabIndex;
				} else{
					FixArgType(0, VT_I4);
					index = pDispParams->rgvarg[0].lVal;
				}
				hr = Item(index, reinterpret_cast<ITab **>(&pVarResult->punkVal));
				if ( FAILED(hr) ) pVarResult->vt = VT_EMPTY;
				return hr;
			}

			case DISPID_NEWENUM:
				pVarResult->vt = VT_UNKNOWN;
				hr = get__NewEnum(&pVarResult->punkVal);
				if ( FAILED(hr) ) pVarResult->vt = VT_EMPTY;
				return hr;

			case 1:
				pVarResult->vt = VT_I4;
				return get_Count(&pVarResult->lVal);

			case 2:
				pVarResult->vt = VT_I4;
				return get_index(&pVarResult->lVal);

			case 3:
				pVarResult->vt = VT_BSTR;
				return get_Name(&pVarResult->bstrVal);

			case 4:
				pVarResult->vt = VT_I4;
				return get_Lock(&pVarResult->lVal);

			case 5:
				pVarResult->vt = VT_BSTR;
				return get_idname(&pVarResult->bstrVal);

			case 6:
				pVarResult->vt = VT_I4;
				return get_length(&pVarResult->lVal);

			case 7:
				pVarResult->vt = VT_I4;
				return get_Type(&pVarResult->lVal);

			case 8:
				pVarResult->vt = VT_I4;
				return get_Pane(&pVarResult->lVal);

			case 9:
				pVarResult->vt = VT_I4;
				return get_TotalCount(&pVarResult->lVal);

			case 10:
				pVarResult->vt = VT_I4;
				return get_TotalPPcCount(&pVarResult->lVal);

			case 11:
				pVarResult->vt = VT_I4;
				return get_Color(&pVarResult->lVal);

			case 12:
				pVarResult->vt = VT_I4;
				return get_BackColor(&pVarResult->lVal);

			case 15:
				ArgsCheck(1);
				FixArgType(0, VT_BSTR);
				pVarResult->vt = VT_BSTR;
				return Extract(pDispParams->rgvarg[0].bstrVal, &pVarResult->bstrVal);

			case 19:
				pVarResult->vt = VT_DISPATCH;
				hr = get_Current(reinterpret_cast<ITab**>(&pVarResult->pdispVal));
				if ( FAILED(hr) ) pVarResult->vt = VT_EMPTY;
				return hr;
		}
	}
									// Put Properties(‘ã“ü) -------------------
	if ( wFlags & DISPATCH_PROPERTYPUT ){
		ArgsCheck(1);
		switch ( dispIdMember ){
			case 2:
				FixArgType(0, VT_I4);
				return set_index(pDispParams->rgvarg[0].lVal);

			case 3:
				FixArgType(0, VT_BSTR);
				return set_Name(pDispParams->rgvarg[0].bstrVal);

			case 4:
				FixArgType(0, VT_I4);
				return set_Lock(pDispParams->rgvarg[0].lVal);

			case 7:
				FixArgType(0, VT_I4);
				return set_Type(pDispParams->rgvarg[0].lVal);

			case 8:
				FixArgType(0, VT_I4);
				return set_Pane(pDispParams->rgvarg[0].lVal);

			case 11:
				FixArgType(0, VT_I4);
				return set_Color(pDispParams->rgvarg[0].lVal);

			case 12:
				FixArgType(0, VT_I4);
				return set_BackColor(pDispParams->rgvarg[0].lVal);

			case 13:
				ArgsCheck(1);
				FixArgType(0, VT_BSTR);
				return IndexFrom(pDispParams->rgvarg[0].bstrVal, NULL);
		}
	}
	Debug_InvokeUnknownDispIID(CLASSNAMES, dispIdMember, wFlags);
	return DISP_E_MEMBERNOTFOUND;

ArgConvError:
	if ( puArgErr != NULL ) *puArgErr = arg;
	return hr;
}
//----------------------------------------------------- ITab collection
STDMETHODIMP CTab::get__NewEnum(IUnknown **ppEnum)
{
	Debug_WriteLog(CLASSNAMES "::_NewEnum", NULL);
	*ppEnum = new CEnumTab(m_InstanceValue, m_PaneIndex);
	(*ppEnum)->AddRef();
	return S_OK;
}

STDMETHODIMP CTab::get_Count(long *plCount)
{
	Debug_WriteLog(CLASSNAMES "::Count", NULL);
	*plCount = m_PaneIndex;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_COMBOTABCOUNT, plCount);
	return S_OK;
}

STDMETHODIMP CTab::Item(long nIndex, ITab **pValue)
{
	Debug_WriteLog(CLASSNAMES "::Item", NULL);
	*pValue = new CTab(m_InstanceValue, m_PaneIndex);
	if ( *pValue == NULL ) return E_OUTOFMEMORY;
	(*pValue)->AddRef();
	(*pValue)->set_index(nIndex);
	return S_OK;
}

//----------------------------------------------------- ITab custom
STDMETHODIMP CTab::get_length(long *pcArgs)
{
	*pcArgs = m_PaneIndex;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_COMBOTABCOUNT, pcArgs);
	return S_OK;
}

STDMETHODIMP CTab::get_Name(BSTR *result)
{
	DWORD buf[CMDLINESIZE / sizeof(DWORD)];

	buf[0] = m_PaneIndex;
	buf[1] = m_TabIndex;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_COMBOTABNAME, &buf);
	*result = ::SysAllocString((WCHAR *)&buf);
	return S_OK;
}

STDMETHODIMP CTab::set_Name(wchar_t *result)
{
	DWORD buf[4];

	buf[0] = m_PaneIndex;
	buf[1] = m_TabIndex;
	*(WCHAR **)&buf[2] = result;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_SETTABNAME, &buf);
	return S_OK;
}

STDMETHODIMP CTab::get_idname(BSTR *result)
{
	DWORD buf[REGEXTIDSIZE / 2];

	buf[0] = m_PaneIndex;
	buf[1] = m_TabIndex;
	if ( m_InstanceValue->IDNameMode == 0 ){
		(*m_ppxa)->Function(*m_ppxa, PPXCMDID_COMBOTABIDNAME, &buf);
	}else if ( (*m_ppxa)->Function(*m_ppxa, PPXCMDID_COMBOTABLONGID, &buf) == 0 ){
		buf[0] = m_PaneIndex;
		buf[1] = m_TabIndex;
		(*m_ppxa)->Function(*m_ppxa, PPXCMDID_COMBOTABIDNAME, &buf);
		if ( ((WCHAR *)&buf)[1] == '_' ){
			memmove(((WCHAR *)&buf) + 1, ((WCHAR *)&buf) + 2, (strlenW(((WCHAR *)&buf) + 2) + 1) * 2);
		}
	}
	*result = ::SysAllocString((WCHAR *)&buf);
	return S_OK;
}

STDMETHODIMP CTab::get_Lock(long *Value)
{
	long tmp[2];

	tmp[0] = m_PaneIndex;
	tmp[1] = m_TabIndex;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_DIRLOCK, &tmp);
	*Value = tmp[0];
	return S_OK;
}

STDMETHODIMP CTab::set_Lock(long Value)
{
	long tmp[4];

	tmp[0] = m_PaneIndex;
	tmp[1] = m_TabIndex;
	tmp[2] = Value;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_SETDIRLOCK, &tmp);
	return S_OK;
}

STDMETHODIMP CTab::get_index(long *Value)
{
	long tmp[2];

	if ( m_TabIndex >= 0 ){
		*Value = m_TabIndex;
	} else{
		tmp[0] = m_PaneIndex;
		tmp[1] = m_TabIndex;
		(*m_ppxa)->Function(*m_ppxa, PPXCMDID_COMBOTABINDEX, &tmp);
		*Value = tmp[0];
	}
	return S_OK;
}

STDMETHODIMP CTab::set_index(long Value)
{
	m_TabIndex = Value;
	return S_OK;
}

STDMETHODIMP CTab::get_Color(long *Value)
{
	long tmp[2];

	tmp[0] = m_PaneIndex;
	tmp[1] = m_TabIndex;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_TABTEXTCOLOR, &tmp);
	*Value = tmp[0];
	return S_OK;
}

STDMETHODIMP CTab::set_Color(long Value)
{
	long tmp[4];

	tmp[0] = m_PaneIndex;
	tmp[1] = m_TabIndex;
	tmp[2] = Value;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_SETTABTEXTCOLOR, &tmp);
	return S_OK;
}

STDMETHODIMP CTab::get_BackColor(long *Value)
{
	long tmp[2];

	tmp[0] = m_PaneIndex;
	tmp[1] = m_TabIndex;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_TABBACKCOLOR, &tmp);
	*Value = tmp[0];
	return S_OK;
}

STDMETHODIMP CTab::set_BackColor(long Value)
{
	long tmp[4];

	tmp[0] = m_PaneIndex;
	tmp[1] = m_TabIndex;
	tmp[2] = Value;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_SETTABBACKCOLOR, &tmp);
	return S_OK;
}

STDMETHODIMP CTab::get_Type(long *Value)
{
	long tmp[2];

	tmp[0] = m_PaneIndex;
	tmp[1] = m_TabIndex;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_COMBOWNDTYPE, &tmp);
	*Value = tmp[0];
	return S_OK;
}

STDMETHODIMP CTab::set_Type(long Value/*[in]*/)
{
	long tmp[4];

	tmp[0] = m_PaneIndex;
	tmp[1] = m_TabIndex;
	tmp[2] = Value;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_SETCOMBOWNDTYPE, &tmp);
	return S_OK;
}

STDMETHODIMP CTab::get_Pane(long *Value/*[out, retval]*/)
{
	long tmp[2];

	if ( m_PaneIndex >= 0 ){
		*Value = m_PaneIndex;
	} else{
		tmp[0] = m_PaneIndex;
		tmp[1] = m_TabIndex;
		(*m_ppxa)->Function(*m_ppxa, PPXCMDID_COMBOTABPANE, &tmp);
		*Value = tmp[0];
	}
	return S_OK;
}

STDMETHODIMP CTab::set_Pane(long Value/*[in]*/)
{
	long tmp[4];

	tmp[0] = m_PaneIndex;
	tmp[1] = m_TabIndex;
	tmp[2] = Value;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_SETCOMBOTABPANE, &tmp);
	return S_OK;
}

STDMETHODIMP CTab::get_TotalCount(long *Value/*[out, retval]*/)
{
	long tmp[2];

	tmp[0] = m_PaneIndex;
	tmp[1] = m_TabIndex;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_COMBOTABCOUNT, &tmp);
	*Value = tmp[0];
	return S_OK;
}

STDMETHODIMP CTab::get_TotalPPcCount(long *)
{
	return E_NOTIMPL;
}

STDMETHODIMP CTab::Next(ULONG celt, VARIANT *rgvar, ULONG *CeltFetched)
{
	DWORD maxtabs = 0;

	Debug_WriteLog(CLASSNAMES "::Next", NULL);
	if ( CeltFetched != NULL ) *CeltFetched = 0;
	if ( celt == 0 ) return S_OK;
	if ( (rgvar == NULL) || ((celt != 1) && (CeltFetched == NULL)) ){
		return E_INVALIDARG;
	}

	maxtabs = m_PaneIndex;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_COMBOTABCOUNT, &maxtabs);
	if ( (m_TabIndex + celt) >= maxtabs ) return S_FALSE;

	while ( celt-- ){
		m_TabIndex++;
		if ( rgvar != NULL ){
			rgvar->vt = VT_DISPATCH;
			rgvar->pdispVal = this;
			AddRef();
			rgvar++;
			if ( CeltFetched != NULL ) (*CeltFetched)++;
		}
	}
	return S_OK;
}

STDMETHODIMP CTab::IndexFrom(BSTR name, LONG *moved)
{
	PPXUPTR_TABINDEXSTRW tmp;
	DWORD_PTR result;

	tmp.pane = m_PaneIndex;
	tmp.tab = m_TabIndex;
	tmp.str = name;
	result = (*m_ppxa)->Function(*m_ppxa, PPXCMDID_COMBOGETTAB, &tmp);
	m_PaneIndex = tmp.pane;
	m_TabIndex = tmp.tab;
	if ( moved != NULL ) *moved = result == PPXA_NO_ERROR;
	return S_OK;
}

STDMETHODIMP CTab::Skip(ULONG celt)
{
	Debug_WriteLog(CLASSNAMES "::Skip", NULL);
	return Next(celt, NULL, NULL);
}

STDMETHODIMP CTab::Reset()
{
	Debug_WriteLog(CLASSNAMES "::Reset", NULL);
	m_TabIndex = -1;
	m_EnumIndex = 0;
	return S_OK;
}

STDMETHODIMP CTab::Execute(BSTR param, long *result)
{
	ERRORCODE resultcode;
	PPXUPTR_TABINDEXSTRW tmp;

	if ( param == NULL ) return S_OK;
	tmp.pane = m_PaneIndex;
	tmp.tab = m_TabIndex;
	tmp.str = param;
	resultcode = static_cast<ERRORCODE>((*m_ppxa)->Function(*m_ppxa, PPXCMDID_COMBOTABEXECUTE, &tmp));
	if ( result != NULL ){
		if ( resultcode == 1 ) resultcode = NO_ERROR;
		*result = resultcode;
	}
	return S_OK;
}

STDMETHODIMP CTab::Extract(BSTR param, BSTR *result)
{
	WCHAR *bufw;
	LONG_PTR long_result;
	size_t paramlen;
	PPXUPTR_TABINDEXSTRW tmp;

	if ( param == NULL ){
//		tprintfW(bufwtmp, L"%d", m_extract_result);
		*result = ::SysAllocString(L"");
		return S_OK;
	}

	paramlen = wcslen(param) + 1;
	if ( paramlen < CMDLINESIZE ) paramlen = CMDLINESIZE;
	bufw = new WCHAR[paramlen];

	tmp.pane = m_PaneIndex;
	tmp.tab = m_TabIndex;
	wcscpy(bufw, param);
	tmp.str = bufw;
	long_result = (*m_ppxa)->Function(*m_ppxa, PPXCMDID_COMBOTABEXTRACTLONG, &tmp);
	if ( long_result >= 0x10000 ){
		*result = (BSTR)long_result;
		delete[] bufw;
		return S_OK;
	}

	tmp.pane = m_PaneIndex;
	tmp.tab = m_TabIndex;
	tmp.str = bufw;
	wcscpy(bufw, param);
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_COMBOTABEXTRACT, &tmp);
	*result = ::SysAllocString(bufw);
	delete[] bufw;
	return S_OK;
}

STDMETHODIMP CTab::moveNext( long * Value )
{
	m_EnumIndex++;
	*Value = m_EnumIndex;
	return S_OK;
}

STDMETHODIMP CTab::atEnd(long * value )
{
	int maxtabs = 0;

	maxtabs = m_PaneIndex;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_COMBOTABCOUNT, &maxtabs);
	if ( m_EnumIndex >= maxtabs ){
		*value = 1;
	}else{
		*value = 0;
		m_TabIndex = m_EnumIndex;
	}
	return S_OK;
}

STDMETHODIMP CTab::get_Current(ITab ** Value )
{
	*Value = new CTab(m_InstanceValue, m_PaneIndex);
	if ( *Value == NULL ) return E_OUTOFMEMORY;
	(*Value)->AddRef();
	(*Value)->set_index(m_EnumIndex);
	return S_OK;
}

//=================================================================== CEnumTab
#undef CLASSNAME
#undef CLASSNAMES
#define CLASSNAME CEnumTab
#define CLASSNAMES "CEnumTab"
CEnumTab::CEnumTab(InstanceValueStruct *InstanceValue, int paneindex)
{
	T_IUNKNOWN_INITDEFINE();

	m_ctab = new CTab(InstanceValue, paneindex);
	m_ctab->AddRef();
	m_ctab->Reset();
}
CEnumTab::~CEnumTab()
{
	m_ctab->Release();
}
//----------------------------------------------------- IUnknown
T_IUNKNOWN_ADDREFDEFINE(CLASSNAME)
T_IUNKNOWN_RELEASEDEFINE(CLASSNAME)
T_IUNKNOWN_QUERYINTERFACEDEFINE(CLASSNAME, (riid == IID_IEnumVARIANT))

//----------------------------------------------------- IEnumVARIANT
STDMETHODIMP CEnumTab::Next(ULONG celt, VARIANT *rgvar, ULONG *pCeltFetched)
{
	Debug_WriteLog(CLASSNAMES "::Next", NULL);
	return m_ctab->Next(celt, rgvar, pCeltFetched);
}

STDMETHODIMP CEnumTab::Skip(ULONG celt)
{
	Debug_WriteLog(CLASSNAMES "::Skip", NULL);
	return m_ctab->Skip(celt);
}

STDMETHODIMP CEnumTab::Reset()
{
	Debug_WriteLog(CLASSNAMES "::Reset", NULL);
	return m_ctab->Reset();
}

STDMETHODIMP CEnumTab::Clone(IEnumVARIANT **)
{
	Debug_WriteLog(CLASSNAMES "::Clone", NULL);
	return E_NOTIMPL;
}
