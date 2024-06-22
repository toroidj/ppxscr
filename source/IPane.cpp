/*-----------------------------------------------------------------------------
	Paper Plane xUI  Script Module				IPane(ペイン)
-----------------------------------------------------------------------------*/
#define STRICT
#include <windows.h>
#include <activscp.h>
#include "ppxscr.h"
#pragma hdrstop
#include "PPxScr_TLB.h"
#include "IPane.h"
#include "ITab.h"

#define CLASSNAME CPane
#define CLASSNAMES "CPane"
CPane::CPane(InstanceValueStruct *InstanceValue)
{
	T_IUNKNOWN_INITDEFINE();
	m_typeInfo = NULL;
	m_PaneIndex = -1; // 実行元の窓
	m_EnumIndex = 0;
	m_InstanceValue = InstanceValue;
	m_ppxa = &(InstanceValue->ppxa);

	if ( FAILED(::LoadTypeInfo(&m_typeInfo, CLSID_IPane_Class, 0)) ){
		::PopupMessage(InstanceValue->ppxa, UNICODESTR(CLASSNAMES) UNICODESTR(" load error"));
	}
}

//----------------------------------------------------- IUnknown
T_IUNKNOWN_ADDREFDEFINE(CLASSNAME);
T_IDISPATCH_RELEASEDEFINE(CLASSNAME);
STDMETHODIMP CPane::QueryInterface(REFIID iid, void **ppv)
{
	if ( (iid == IID_IUnknown) || (iid == IID_IPane) ){
		*ppv = static_cast<IPane*>(this);
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
STDMETHODIMP CPane::GetTypeInfoCount(UINT *iTInfo)
{
	Debug_WriteLog(CLASSNAMES "::GetTypeInfoCount", NULL);
	if ( (DWORD_PTR)iTInfo < 0x10000 ) return E_NOTIMPL;
	*iTInfo = 1;
	return S_OK;
}

STDMETHODIMP CPane::GetTypeInfo(UINT, LCID, ITypeInfo **ppTInfo)
{
	Debug_WriteLog(CLASSNAMES "::GetTypeInfo", NULL);
	m_typeInfo->AddRef();
	*ppTInfo = m_typeInfo;
	return S_OK;
}

STDMETHODIMP CPane::GetIDsOfNames(REFIID riid, OLECHAR **rgszNames, UINT cNames, LCID, DISPID *rgDispId)
{
	Debug_WriteLog(CLASSNAMES "::GetIDsOfNames:", *rgszNames);
	if ( riid != IID_NULL ) return E_INVALIDARG;
	return DispGetIDsOfNames(m_typeInfo, rgszNames, cNames, rgDispId);
}

STDMETHODIMP CPane::Invoke(DISPID dispIdMember, REFIID riid, LCID lc, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO * ei/*pExcepInfo*/, unsigned int *puArgErr)
{
	int arg;
	HRESULT hr;

	Debug_WriteLog(CLASSNAMES "::Invoke", NULL);
	if ( riid != IID_NULL ) return DISP_E_UNKNOWNINTERFACE;
									// Function/Get Properties ----------------

	if ( wFlags & DISPATCH_METHOD ){
		if ( pVarResult == NULL ){
			VARIANT dummyvt;

			VariantInit(&dummyvt);
			hr = Invoke(dispIdMember, riid, lc, wFlags, pDispParams, &dummyvt, ei, puArgErr);
			VariantClear(&dummyvt);
			return hr;
		}
		switch (dispIdMember){
			case 4:
				ArgsCheck(0);
				return Reset();

			case 5:
				ArgsCheck(0);
				pVarResult->vt = VT_I4;
				return moveNext(&pVarResult->lVal);

			case 8:
				ArgsCheck(1);
				FixArgType(0, VT_BSTR);
				pVarResult->vt = VT_I4;
				return IndexFrom(pDispParams->rgvarg[0].bstrVal, &pVarResult->lVal);

			case 9:
				ArgsCheck(0);
				pVarResult->vt = VT_I4;
				return atEnd(&pVarResult->lVal);
		}
	}

	if ( wFlags & DISPATCH_PROPERTYGET ){
		if ( pVarResult == NULL ){
			VARIANT dummyvt;

			VariantInit(&dummyvt);
			hr = Invoke(dispIdMember, riid, lc, wFlags, pDispParams, &dummyvt, ei, puArgErr);
			VariantClear(&dummyvt);
			return hr;
		}
		switch ( dispIdMember ){
			case DISPID_VALUE:
			{
				int index;

				pVarResult->vt = VT_UNKNOWN;
				if ( pDispParams->cArgs == 0 ){
					index = m_PaneIndex;
				} else{
					FixArgType(0, VT_I4);
					index = pDispParams->rgvarg[0].lVal;
				}
				return Item(index, reinterpret_cast<IPane **>(&pVarResult->punkVal));
			}
			case DISPID_NEWENUM:
				pVarResult->vt = VT_UNKNOWN;
				return get__NewEnum(&pVarResult->punkVal);

			case 1:
				pVarResult->vt = VT_I4;
				return get_Count(&pVarResult->lVal);

			case 2:
				pVarResult->vt = VT_I4;
				return get_index(&pVarResult->lVal);

			case 3:
				pVarResult->vt = VT_BSTR;
				return get_Name(&pVarResult->bstrVal);

			case 6:
				pVarResult->vt = VT_I4;
				return get_length(&pVarResult->lVal);

			case 7:
				if ( pDispParams->cArgs > 1 ) return DISP_E_BADPARAMCOUNT;

				pVarResult->vt = VT_DISPATCH;
				hr = get_Tab(reinterpret_cast<ITab**>(&pVarResult->pdispVal));
				if ( FAILED(hr) ) return hr;

				if ( pDispParams->cArgs == 1 ){
					FixArgType(0, VT_I4);
					return (reinterpret_cast<ITab*>(pVarResult->pdispVal))->set_index(pDispParams->rgvarg[0].lVal);
				} else{ // 0
					return S_OK;
				}

			case 10:
				pVarResult->vt = VT_DISPATCH;
				return get_Current(reinterpret_cast<IPane**>(&pVarResult->pdispVal));
		}
	}
									// Put Properties(代入) -------------------
	if ( wFlags & DISPATCH_PROPERTYPUT ){
		ArgsCheck(1);
		switch ( dispIdMember ){
			case 2:
				FixArgType(0, VT_I4);
				return set_index(pDispParams->rgvarg[0].lVal);
			case 3:
				FixArgType(0, VT_BSTR);
				return set_Name(pDispParams->rgvarg[0].bstrVal);
			case 8:
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

//----------------------------------------------------- IPane collection
STDMETHODIMP CPane::get__NewEnum(IUnknown **ppEnum)
{
	Debug_WriteLog(CLASSNAMES "::_NewEnum", NULL);
	*ppEnum = new CEnumPane(m_InstanceValue);
	(*ppEnum)->AddRef();
	return S_OK;
}

STDMETHODIMP CPane::get_Count(long *plCount)
{
	Debug_WriteLog(CLASSNAMES "::Count", NULL);
	*plCount = 0;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_COMBOSHOWPANES, plCount);
	return S_OK;
}

STDMETHODIMP CPane::Item(long nIndex, IPane **pValue)
{
	int max;

	Debug_WriteLog(CLASSNAMES "::Item", NULL);
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_COMBOSHOWPANES, &max);
	if ( (nIndex < -3) || (nIndex >= max) ) return 0x800A0009;

	*pValue = new CPane(m_InstanceValue);
	if ( *pValue == NULL ) return E_OUTOFMEMORY;
	(*pValue)->AddRef();
	(*pValue)->set_index(nIndex);
	return S_OK;
}

//----------------------------------------------------- IPane custom
STDMETHODIMP CPane::get_length(long *pcArgs)
{
	*pcArgs = 0;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_COMBOSHOWPANES, pcArgs);
	return S_OK;
}

STDMETHODIMP CPane::get_Name(BSTR *)
{
	return E_NOTIMPL;
}

STDMETHODIMP CPane::set_Name(wchar_t *)
{
	return E_NOTIMPL;
}

STDMETHODIMP CPane::IndexFrom(BSTR name, LONG *moved)
{
	m_PaneIndex = static_cast<int>((*m_ppxa)->Function(*m_ppxa, PPXCMDID_COMBOGETPANE, name));
	if ( moved != NULL ) *moved = m_PaneIndex >= 0;
	return S_OK;
}

STDMETHODIMP CPane::get_index(long *Value/*[out, retval]*/)
{
	if ( m_PaneIndex >= 0 ){
		*Value = m_PaneIndex;
	} else{
		long tmp[2];

		tmp[0] = m_PaneIndex;
		tmp[1] = 0; // 未使用であるが、念のため
		(*m_ppxa)->Function(*m_ppxa, PPXCMDID_COMBOSHOWINDEX, &tmp);
		*Value = tmp[0];
	}
	return S_OK;
}

STDMETHODIMP CPane::set_index(long Value/*[in]*/)
{
	m_PaneIndex = Value;
	return S_OK;
}

STDMETHODIMP CPane::get_Tab(ITab ** Value)
{
	*Value = new CTab(m_InstanceValue, m_PaneIndex);
	if ( *Value == NULL ) return E_OUTOFMEMORY;
	(*Value)->AddRef();
	return S_OK;
}

STDMETHODIMP CPane::Next(ULONG celt, VARIANT *rgvar, ULONG *CeltFetched)
{
	DWORD maxpane = 0;

	Debug_WriteLog(CLASSNAMES "::Next", NULL);
	if ( CeltFetched != NULL ) *CeltFetched = 0;
	if ( celt == 0 ) return S_OK;
	if ( (rgvar == NULL) || ((celt != 1) && (CeltFetched == NULL)) ){
		return E_INVALIDARG;
	}

	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_COMBOSHOWPANES, &maxpane);
	if ( (m_PaneIndex + celt) >= maxpane ) return S_FALSE;

	while ( celt-- ){
		m_PaneIndex++;
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

STDMETHODIMP CPane::Skip(ULONG celt)
{
	Debug_WriteLog(CLASSNAMES "::Skip", NULL);
	return Next(celt, NULL, NULL);
}

STDMETHODIMP CPane::Reset()
{
	Debug_WriteLog(CLASSNAMES "::Reset", NULL);
	m_PaneIndex = -1;
	m_EnumIndex = 0;
	return S_OK;
}

STDMETHODIMP CPane::moveNext( long * Value )
{
	m_EnumIndex++;
	*Value = m_EnumIndex;
	return S_OK;
}

STDMETHODIMP CPane::atEnd(long * value )
{
	int maxpanes = 0;

	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_COMBOSHOWPANES, &maxpanes);
	if ( m_EnumIndex >= maxpanes ){
		*value = 1;
	}else{
		*value = 0;
		m_PaneIndex = m_EnumIndex;
	}
	return S_OK;
}

STDMETHODIMP CPane::get_Current(IPane ** Value )
{
	*Value = new CPane(m_InstanceValue);
	if ( *Value == NULL ) return E_OUTOFMEMORY;
	(*Value)->AddRef();
	(*Value)->set_index(m_EnumIndex);
	return S_OK;
}

//============================================================================
#undef CLASSNAME
#undef CLASSNAMES
#define CLASSNAME CEnumPane
#define CLASSNAMES "CEnumPane"
CEnumPane::CEnumPane(InstanceValueStruct *InstanceValue)
{
	T_IUNKNOWN_INITDEFINE();

	m_cpane = new CPane(InstanceValue);
	m_cpane->AddRef();
	m_cpane->Reset();
}

CEnumPane::~CEnumPane()
{
	m_cpane->Release();
}

//----------------------------------------------------- IUnknown
T_IUNKNOWN_ADDREFDEFINE(CLASSNAME)
T_IUNKNOWN_RELEASEDEFINE(CLASSNAME)
T_IUNKNOWN_QUERYINTERFACEDEFINE(CLASSNAME, (riid == IID_IEnumVARIANT))

//----------------------------------------------------- IEnumVARIANT
STDMETHODIMP CEnumPane::Next(ULONG celt, VARIANT *rgvar, ULONG *CeltFetched)
{
	Debug_WriteLog(CLASSNAMES "::Next", NULL);
	return m_cpane->Next(celt, rgvar, CeltFetched);
}

STDMETHODIMP CEnumPane::Skip(ULONG celt)
{
	Debug_WriteLog(CLASSNAMES "::Skip", NULL);
	return m_cpane->Skip(celt);
}

STDMETHODIMP CEnumPane::Reset()
{
	Debug_WriteLog(CLASSNAMES "::Reset", NULL);
	return m_cpane->Reset();
}

STDMETHODIMP CEnumPane::Clone(IEnumVARIANT **)
{
	Debug_WriteLog(CLASSNAMES "::Clone", NULL);
	return E_NOTIMPL;
}
