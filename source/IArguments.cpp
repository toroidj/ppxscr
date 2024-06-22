/*-----------------------------------------------------------------------------
	Paper Plane xUI  Script Module				IArguments(実行時パラメータ)
-----------------------------------------------------------------------------*/
#define STRICT
#include <windows.h>
#include <activscp.h>
#include "ppxscr.h"
#pragma hdrstop
#include "PPxScr_TLB.h"
#include "IArguments.h"

#define CLASSNAME CArguments
#define CLASSNAMES "CArguments"
CArguments::CArguments(PPXAPPINFOW **ppxa, const WCHAR *Args, int ArgsCount)
{
	T_IUNKNOWN_INITDEFINE();
	m_ppxa = ppxa;
	m_typeInfo = NULL;
	m_Args = Args;
	m_ArgsCount = ArgsCount;
	m_EnumIndex = 0;

	if ( FAILED(::LoadTypeInfo(&m_typeInfo, CLSID_IArguments_Class, 0)) ){
		::PopupMessage(*ppxa, UNICODESTR(CLASSNAMES) UNICODESTR(" load error"));
	}
}

//----------------------------------------------------- IUnknown
T_IUNKNOWN_ADDREFDEFINE(CLASSNAME);
T_IDISPATCH_RELEASEDEFINE(CLASSNAME);
STDMETHODIMP CArguments::QueryInterface(REFIID iid, void **ppv)
{
	if ( (iid == IID_IUnknown) || (iid == IID_IArguments) ){
		*ppv = static_cast<IArguments*>(this);
		AddRef();
		return S_OK;
	}
	if ( iid == IID_IDispatch ){
		*ppv = static_cast<IDispatch*>(this);
		AddRef();
		return S_OK;
	}
	Debug_DispIID(CLASSNAMES "::QueryInterface - false:", iid);\
	*ppv = NULL;
	return E_NOINTERFACE;
}

//----------------------------------------------------- IDispatch
STDMETHODIMP CArguments::GetTypeInfoCount(UINT *iTInfo)
{
	Debug_WriteLog(CLASSNAMES "::GetTypeInfoCount", NULL);
	if ( (DWORD_PTR)iTInfo < 0x10000 ) return E_NOTIMPL;
	*iTInfo = 1;
	return S_OK;
}

STDMETHODIMP CArguments::GetTypeInfo(UINT, LCID, ITypeInfo **ppTInfo)
{
	Debug_WriteLog(CLASSNAMES "::GetTypeInfo", NULL);
	m_typeInfo->AddRef();
	*ppTInfo = m_typeInfo;
	return S_OK;
}

STDMETHODIMP CArguments::GetIDsOfNames(REFIID riid, OLECHAR **rgszNames, UINT cNames, LCID, DISPID *rgDispId)
{
	Debug_WriteLog(CLASSNAMES "::GetIDsOfNames:", *rgszNames);
	if (riid != IID_NULL) return E_INVALIDARG;
	return DispGetIDsOfNames(m_typeInfo, rgszNames, cNames, rgDispId);
}

STDMETHODIMP CArguments::Invoke(DISPID dispIdMember, REFIID riid, LCID lc, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO * ei, unsigned int *puArgErr)
{
	int arg;
	HRESULT hr;

	Debug_WriteLog(CLASSNAMES "::Invoke", NULL);
	if (riid != IID_NULL) return DISP_E_UNKNOWNINTERFACE;
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
			case 2:
				ArgsCheck(0);
				return Reset();

			case 3:
				ArgsCheck(0);
				pVarResult->vt = VT_I4;
				return moveNext(&pVarResult->lVal);

			case 4:
				ArgsCheck(0);
				pVarResult->vt = VT_I4;
				return atEnd(&pVarResult->lVal);
		}
	}
	if ( wFlags & DISPATCH_PROPERTYGET ){
		if ( pVarResult == NULL ) return E_INVALIDARG;
		switch (dispIdMember){
			case DISPID_VALUE: {
				int index;

				pVarResult->vt = VT_BSTR;
				if ( pDispParams->cArgs == 0 ){
					index = m_EnumIndex;
				}else{
					FixArgType(0, VT_I4);
					index = pDispParams->rgvarg[0].lVal;
				}
				return Item(index, &pVarResult->bstrVal);
			}
			case DISPID_NEWENUM:
				pVarResult->vt = VT_UNKNOWN;
				return get__NewEnum(&pVarResult->punkVal);

			case 1:
				pVarResult->vt = VT_I4;
				return get_Count(&pVarResult->lVal);

			case 5:
				pVarResult->vt = VT_DISPATCH;
				return get_Current(reinterpret_cast<IArguments**>(&pVarResult->pdispVal));

			case 6:
				pVarResult->vt = VT_I4;
				return get_length(&pVarResult->lVal);

			case 7:
				pVarResult->vt = VT_BSTR;
				return get_Value(&pVarResult->bstrVal);
		}
	}
	Debug_InvokeUnknownDispIID(CLASSNAMES, dispIdMember, wFlags);
	return DISP_E_MEMBERNOTFOUND;

ArgConvError:
	if ( puArgErr != NULL ) *puArgErr = arg;
	return hr;
}

//----------------------------------------------------- IArguments collection
STDMETHODIMP CArguments::get__NewEnum(IUnknown **ppEnum)
{
	Debug_WriteLog(CLASSNAMES "::_NewEnum", NULL);
	*ppEnum = new CEnumArguments(m_Args, m_ArgsCount);
	(*ppEnum)->AddRef();
	return S_OK;
}

STDMETHODIMP CArguments::get_Count(long *plCount)
{
	Debug_WriteLog(CLASSNAMES "::Count", NULL);
	*plCount = m_ArgsCount;
	return S_OK;
}

STDMETHODIMP CArguments::Item(long nIndex, BSTR *pValue)
{
	return GetArgumentItem(*m_ppxa, m_Args, nIndex, m_ArgsCount, pValue);
}

//----------------------------------------------------- IArguments custom
STDMETHODIMP CArguments::get_length(long *pcArgs)
{
	Debug_WriteLog(CLASSNAMES "::length", NULL);
	*pcArgs = m_ArgsCount;
	return S_OK;
}

STDMETHODIMP CArguments::Reset( void )
{
	m_EnumIndex = 0;
	return S_OK;
}

STDMETHODIMP CArguments::moveNext( long * Value )
{
	if ( m_EnumIndex < m_ArgsCount ) m_EnumIndex++;
	*Value = m_EnumIndex;
	return S_OK;
}

STDMETHODIMP CArguments::atEnd(long * value )
{
	*value = (m_EnumIndex < m_ArgsCount) ? 0 : 1;
	return S_OK;
}

STDMETHODIMP CArguments::get_Current(IArguments ** Value )
{
	*Value = new CArguments(m_ppxa, m_Args, m_ArgsCount);
	if ( *Value == NULL ) return E_OUTOFMEMORY;
	(*Value)->AddRef();
	return S_OK;
}

STDMETHODIMP CArguments::get_Value(BSTR *pValue)
{
	return GetArgumentItem(*m_ppxa, m_Args, m_EnumIndex, m_ArgsCount, pValue);
}

//============================================================== CEnumArguments
#undef CLASSNAME
#undef CLASSNAMES
#define CLASSNAME CEnumArguments
#define CLASSNAMES "CEnumArguments"
CEnumArguments::CEnumArguments(const WCHAR *Args, int ArgsCount)
{
	T_IUNKNOWN_INITDEFINE();
	m_Args = Args;
	m_ArgsCount = ArgsCount;
	m_EnumIndex = 0;
}

//----------------------------------------------------- IUnknown
T_IUNKNOWN_ADDREFDEFINE(CLASSNAME)
T_IUNKNOWN_RELEASEDEFINE(CLASSNAME)
T_IUNKNOWN_QUERYINTERFACEDEFINE(CLASSNAME, (riid == IID_IEnumVARIANT))

//----------------------------------------------------- IEnumVARIANT
STDMETHODIMP CEnumArguments::Next(ULONG celt, VARIANT *rgvar, ULONG *CeltFetched)
{
	const WCHAR *p;
	int i;

	Debug_WriteLog(CLASSNAMES "::Next", NULL);
	if ( CeltFetched != NULL ) *CeltFetched = 0;
	if ( celt == 0 ) return S_OK;
	if ( (rgvar == NULL) || ((celt != 1) && (CeltFetched == NULL)) ){
		return E_INVALIDARG;
	}
	if ( m_EnumIndex >= m_ArgsCount ) return S_FALSE;

	p = m_Args;
	for ( i = 0 ; i <= m_EnumIndex ; i++ ){
		p += wcslen(p) + 1;
	}

	while( celt-- ){
		if ( m_EnumIndex >= m_ArgsCount ) return S_FALSE;
		rgvar->vt = VT_BSTR;
		rgvar->bstrVal = ::SysAllocString(p);
		rgvar++;
		m_EnumIndex++;
		if ( CeltFetched != NULL ) (*CeltFetched)++;
		p += wcslen(p) + 1;
	}
	return S_OK;
}

STDMETHODIMP CEnumArguments::Skip(ULONG celt)
{
	Debug_WriteLog(CLASSNAMES "::Skip", NULL);
	m_EnumIndex += celt;
	if ( m_EnumIndex >= m_ArgsCount ){
		m_EnumIndex = m_ArgsCount;
		return S_FALSE;
	}
	return S_OK;
}

STDMETHODIMP CEnumArguments::Reset()
{
	Debug_WriteLog(CLASSNAMES "::Reset", NULL);
	m_EnumIndex = 0;
	return S_OK;
}

STDMETHODIMP CEnumArguments::Clone(IEnumVARIANT FAR* FAR*)
{
	Debug_WriteLog(CLASSNAMES "::Clone", NULL);
	return E_NOTIMPL;
}

STDMETHODIMP GetArgumentItem(PPXAPPINFOW *ppxa, const WCHAR *ptr, long nIndex, long nIndexMax, BSTR *pValue)
{
	int i;

	// パースあり
	if ( (nIndex >= 0) && (nIndex < nIndexMax) ){
		for ( i = 0 ; i <= nIndex ; i++ ){
			ptr += wcslen(ptr) + 1;
		}

		*pValue = ::SysAllocString(ptr);
		return S_OK;
	}
	// パースなし / 範囲外
	if ( nIndex == -1 ){
		BSTR param;

		param = (BSTR)ppxa->Function(ppxa, PPXCMDID_GETRAWPARAM, NULL);
		if ( param == NULL ){
			*pValue = ::SysAllocString(L"");
			return S_OK;
		}

		*pValue = param;

		ptr = param;
		while ( (*ptr == ' ') || (*ptr == '\t') ) ptr++;
		if ( *ptr == '\"' ){
			ptr++;
			for (;;){
				if ( *ptr == '\0' ) break;
				if ( *ptr++ == '\"' ) break;
			}
			while ( (*ptr == ' ') || (*ptr == '\t') ) ptr++;
		}else{
			for (;;){
				if ( (*ptr == '\0') || (*ptr == ',') ) break;
				ptr++;
			}
		}
		if ( *ptr == ',' ) ptr++;
		*pValue = ::SysAllocString(ptr);
		::SysFreeString(param);
		return S_OK;
	}
	return 0x800A0009;
}
