/*-----------------------------------------------------------------------------
	Paper Plane xUI  Script Module				IEntry(éwíËÉGÉìÉgÉäèÓïÒ)
-----------------------------------------------------------------------------*/
#define STRICT
#include <windows.h>
#include <activscp.h>
#include "ppxscr.h"
#pragma hdrstop
#include "PPxScr_TLB.h"
#include "IEntry.h"

#define CLASSNAME CEntry
#define CLASSNAMES "CEntry"
CEntry::CEntry(InstanceValueStruct *InstanceValue)
{
	T_IUNKNOWN_INITDEFINE();
	m_typeInfo = NULL;
	m_InstanceValue = InstanceValue;
	m_ppxa = &(InstanceValue->ppxa);
	EnumMode = -1;
	m_index = 0;

	if ( FAILED(::LoadTypeInfo(&m_typeInfo, CLSID_IEntry_Class, 0)) ){
		::PopupMessage(InstanceValue->ppxa, UNICODESTR(CLASSNAMES) UNICODESTR(" load error"));
	}
}

//----------------------------------------------------- IUnknown
T_IUNKNOWN_ADDREFDEFINE(CLASSNAME)
T_IDISPATCH_RELEASEDEFINE(CLASSNAME)
STDMETHODIMP CEntry::QueryInterface(REFIID iid, void **ppv)
{
	if ( (iid == IID_IUnknown) || (iid == IID_IEntry) ){
		*ppv = static_cast<IEntry*>(this);
		AddRef();
		return S_OK;
	}
	if ( iid == IID_IDispatch ){
		*ppv = static_cast<IDispatch*>(this);
		AddRef();
		return S_OK;
	}
	if ( iid == IID_IProvideMultipleClassInfo ){
		*ppv = static_cast<IProvideMultipleClassInfo*>(this);
		AddRef();
		return S_OK;
	}
	Debug_WriteLog(CLASSNAMES "::QueryInterface->Unknown", NULL);
	*ppv = NULL;
	return E_NOINTERFACE;
}

//--------------------------------------------------- IProvideMultipleClassInfo
STDMETHODIMP CEntry::GetMultiTypeInfoCount(ULONG *pcti)
{
	Debug_WriteLog(CLASSNAMES "::GetMultiTypeInfoCount", NULL);
	*pcti = 1;
	return S_OK;
}

STDMETHODIMP CEntry::GetInfoOfIndex(ULONG iti, DWORD dwMCIFlags, ITypeInfo **pptiCoClass, DWORD *pdwTIFlags, ULONG *pcdispidReserved, IID *piidPrimary, IID *piidSource)
{
	Debug_WriteLog(CLASSNAMES "::GetInfoOfIndex", NULL);
	if ( iti != 0 ) return E_INVALIDARG;
	if ( dwMCIFlags & MULTICLASSINFO_GETTYPEINFO ){
		GetTypeInfo(0, 0, pptiCoClass);
	}
	if ( dwMCIFlags & MULTICLASSINFO_GETNUMRESERVEDDISPIDS ){
		*pdwTIFlags = 0;
		*pcdispidReserved = 0;
	}
	if ( dwMCIFlags & MULTICLASSINFO_GETIIDPRIMARY ){
		*piidPrimary = IID_IEntry;
	}
	if ( dwMCIFlags & MULTICLASSINFO_GETIIDSOURCE ){
		*piidSource = IID_IEntry;
	}
	return S_OK;
}

//--------------------------------------------------- IProvideClassInfo
STDMETHODIMP CEntry::GetClassInfo(ITypeInfo **ppTI)
{
	Debug_WriteLog(CLASSNAMES "::GetClassInfo", NULL);
	return GetTypeInfo(0, 0, ppTI);
}

//-------------------------------------------------- IProvideClassInfo2
STDMETHODIMP CEntry::GetGUID(DWORD dwGuidKind, GUID *pGUID)
{
	Debug_WriteLog(CLASSNAMES "::GetGUID", NULL);
	if ( dwGuidKind != GUIDKIND_DEFAULT_SOURCE_DISP_IID ) return E_INVALIDARG;
	*pGUID = IID_IEntry;
	return S_OK;
}

//----------------------------------------------------- IDispatch
STDMETHODIMP CEntry::GetTypeInfoCount(UINT *iTInfo)
{
	Debug_WriteLog(CLASSNAMES "::GetTypeInfoCount", NULL);
	if ( (DWORD_PTR)iTInfo < 0x10000 ) return E_NOTIMPL;
	*iTInfo = 1;
	return S_OK;
}

STDMETHODIMP CEntry::GetTypeInfo(UINT, LCID, ITypeInfo **ppTInfo)
{
	Debug_WriteLog(CLASSNAMES "::GetTypeInfo", NULL);
	*ppTInfo = m_typeInfo;
	m_typeInfo->AddRef();
	return S_OK;
}

STDMETHODIMP CEntry::GetIDsOfNames(REFIID riid, OLECHAR **rgszNames, UINT cNames, LCID, DISPID *rgDispId)
{
	Debug_WriteLog(CLASSNAMES "::GetIDsOfNames:", *rgszNames);
	if ( riid != IID_NULL ) return E_INVALIDARG;
	return DispGetIDsOfNames(m_typeInfo, rgszNames, cNames, rgDispId);
}

STDMETHODIMP CEntry::Invoke(DISPID dispIdMember, REFIID riid, LCID lc, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO * ei, unsigned int *puArgErr)
{
	HRESULT hr;
	int arg;

	Debug_WriteLog(CLASSNAMES "::Invoke", NULL);
	if ( riid != IID_NULL ) return DISP_E_UNKNOWNINTERFACE;
/*
	Debug_InvokeUnknownDispIID(CLASSNAMES "-Check", dispIdMember, wFlags);
	hr = ::DispInvoke(this, m_typeInfo, dispIdMember,
			wFlags, pDispParams, pVarResult, pExcepInfo, puArgErr);
	return S_OK;
*/
									// Function/Get Properties(éÊìæ) ----------
	if ( wFlags & (DISPATCH_PROPERTYGET | DISPATCH_METHOD) ){
		if ( pVarResult == NULL ){
			VARIANT dummyvt;

			VariantInit(&dummyvt);
			hr = Invoke(dispIdMember, riid, lc, wFlags, pDispParams, &dummyvt, ei, puArgErr);
			VariantClear(&dummyvt);
			return hr;
		}
		switch ( dispIdMember ){
			case DISPID_NEWENUM:
				pVarResult->vt = VT_UNKNOWN;
				return get__NewEnum(&pVarResult->punkVal);

			case DISPID_VALUE:
			{
				int index;

				pVarResult->vt = VT_UNKNOWN;
				if ( pDispParams->cArgs == 0 ){
					index = -1;
				} else{
					FixArgType(0, VT_I4);
					index = pDispParams->rgvarg[0].lVal;
				}
				return Item(index, reinterpret_cast<IEntry **>(&pVarResult->punkVal));
			}

			case 1:
				pVarResult->vt = VT_I4;
				return get_Count(&pVarResult->lVal);

			case 2:
				pVarResult->vt = VT_I4;
				return get_length(&pVarResult->lVal);

			case 3:
				pVarResult->vt = VT_I4;
				return get_Highlight(&pVarResult->lVal);

			case 4:
				ArgsCheck(0);
				pVarResult->vt = VT_I4;
				return Hide();

			case 5:
				pVarResult->vt = VT_BSTR;
				return get_Name(&pVarResult->bstrVal);
			case 6:
				pVarResult->vt = VT_I4;
				return get_index(&pVarResult->lVal);
			case 7:
				pVarResult->vt = VT_I4;
				return get_Mark(&pVarResult->lVal);
			case 8:
				pVarResult->vt = VT_BSTR;
				return get_Comment(&pVarResult->bstrVal);

			case 9:
				pVarResult->vt = VT_I4;
				return get_Attributes(&pVarResult->lVal);
			case 10:
				pVarResult->vt = VT_R8;
				return get_Size(&pVarResult->dblVal);
			case 11:
				pVarResult->vt = VT_I4;
				return get_State(&pVarResult->lVal);
			case 12:
				pVarResult->vt = VT_I4;
				return get_ExtColor(&pVarResult->lVal);
			case 13: //NextMark
				ArgsCheck(0);
				pVarResult->vt = VT_I4;
				return NextMark(&pVarResult->lVal);

			case 14: //PrevMark
				ArgsCheck(0);
				pVarResult->vt = VT_I4;
				return PrevMark(&pVarResult->lVal);

			case 15:
				pVarResult->vt = VT_DATE;
				return get_DateCreated(&pVarResult->dblVal);
			case 16:
				pVarResult->vt = VT_DATE;
				return get_DateLastAccessed(&pVarResult->dblVal);
			case 17:
				pVarResult->vt = VT_DATE;
				return get_DateLastModified(&pVarResult->dblVal);
			case 18:
				pVarResult->vt = VT_BSTR;
				return get_ShortName(&pVarResult->bstrVal);
			case 19:
				ArgsCheck(0);
				pVarResult->vt = VT_BSTR;
				return Information(&pVarResult->bstrVal);

			case 20: //FirstMark
				ArgsCheck(0);
				pVarResult->vt = VT_I4;
				return FirstMark(&pVarResult->lVal);

			case 21: //LastMark
				ArgsCheck(0);
				pVarResult->vt = VT_I4;
				return LastMark(&pVarResult->lVal);

			case 22:
				ArgsCheck(1);
				FixArgType(0, VT_I4);
				pVarResult->vt = VT_BSTR;
				return GetComment(pDispParams->rgvarg[0].lVal, &pVarResult->bstrVal);
			case 23:
				ArgsCheck(2);
				FixArgType(0, VT_BSTR);
				FixArgType(1, VT_I4);
				return SetComment(pDispParams->rgvarg[1].lVal, pDispParams->rgvarg[0].bstrVal);
			case 24:
				ArgsCheck(0);
				return Reset();

			case 25:
				ArgsCheck(0);
				pVarResult->vt = VT_I4;
				return moveNext(&pVarResult->lVal);

			case 26:
				ArgsCheck(0);
				pVarResult->vt = VT_DISPATCH;
				return get_AllMark(reinterpret_cast<IEntry**>(&pVarResult->pdispVal));

			case 27:
				ArgsCheck(0);
				pVarResult->vt = VT_DISPATCH;
				return get_AllEntry(reinterpret_cast<IEntry**>(&pVarResult->pdispVal));

			case 28:
				ArgsCheck(0);
				pVarResult->vt = VT_I4;
				return atEnd(&pVarResult->lVal);

			case 29:
				ArgsCheck(0);
				pVarResult->vt = VT_DISPATCH;
				return get_Current(reinterpret_cast<IEntry**>(&pVarResult->pdispVal));

			case 30:
				ArgsCheck(1);
				FixArgType(0, VT_BSTR);
				pVarResult->vt = VT_I4;
				return IndexFrom(pDispParams->rgvarg[0].bstrVal, &pVarResult->lVal);
		}
	}
									// Put Properties(ë„ì¸) -------------------
	if ( wFlags & DISPATCH_PROPERTYPUT ){
		ArgsCheck(1);
		switch ( dispIdMember ){
			case 6:
				FixArgType(0, VT_I4);
				return set_index(pDispParams->rgvarg[0].lVal);
			case 7:
				FixArgType(0, VT_I4);
				return set_Mark(pDispParams->rgvarg[0].lVal);
			case 8:
				FixArgType(0, VT_BSTR);
				return set_Comment(pDispParams->rgvarg[0].bstrVal);
			case 11:
				FixArgType(0, VT_I4);
				return set_State(pDispParams->rgvarg[0].lVal);
			case 12:
				FixArgType(0, VT_I4);
				return set_ExtColor(pDispParams->rgvarg[0].lVal);
			case 3:
				FixArgType(0, VT_I4);
				return set_Highlight(pDispParams->rgvarg[0].lVal);
		}
	}
	Debug_InvokeUnknownDispIID(CLASSNAMES, dispIdMember, wFlags);
	return DISP_E_MEMBERNOTFOUND;

ArgConvError:
	if ( puArgErr != NULL ) *puArgErr = arg;
	return hr;
}

//----------------------------------------------------- IEntry collection
STDMETHODIMP CEntry::get__NewEnum(IUnknown **ppEnum)
{
	Debug_WriteLog(CLASSNAMES "::_NewEnum", NULL);
	*ppEnum = new CEnumEntry(m_InstanceValue, EnumMode);
	(*ppEnum)->AddRef();
	return S_OK;
}

STDMETHODIMP CEntry::get_Count(long *plCount)
{
	Debug_WriteLog(CLASSNAMES "::Count", NULL);
	return ((*m_ppxa)->Function(*m_ppxa, PPXCMDID_DIRTTOTAL, plCount) == PPXA_NO_ERROR ) ?
		S_OK : DISP_E_EXCEPTION;
}

STDMETHODIMP CEntry::Item(long nIndex, IEntry **pValue)
{
	int max;

	Debug_WriteLog(CLASSNAMES "::Item", NULL);
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_DIRTTOTAL, &max);
	if ( nIndex < 0 ){
		if ( nIndex < -1 ) return 0x800A0009;
		(*m_ppxa)->Function(*m_ppxa, PPXCMDID_CSRINDEX, &nIndex);
	} else if ( nIndex >= max ){
		return 0x800A0009;
	}

	*pValue = new CEntry(m_InstanceValue);
	if ( *pValue == NULL ) return E_OUTOFMEMORY;
	(*pValue)->AddRef();
	(*pValue)->set_index(nIndex);
	return S_OK;
}

//----------------------------------------------------- IEntry custom
STDMETHODIMP CEntry::get_length(long *plCount)
{
	Debug_WriteLog(CLASSNAMES "::length", NULL);
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_DIRTTOTAL, plCount);
	return S_OK;
}

//----------------------------------------------------- IEntry
STDMETHODIMP CEntry::get_index(long *Value)
{
	*((long *)Value) = m_index;
	if ( (*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRY_HS_GETINDEX, Value) == 0 ){
		*Value = m_index;
	}
	return S_OK;
}

STDMETHODIMP CEntry::set_index(long Value)
{
	if ( Value >= 0 ){
		long max;

		(*m_ppxa)->Function(*m_ppxa, PPXCMDID_DIRTTOTAL, &max);
		if ( Value < max ) m_index = Value;
	}
	return S_OK;
}

STDMETHODIMP CEntry::get_Name(BSTR *Value)
{
	PPXUPTR_INDEX_UPATHW tmp;

	tmp.index = m_index;
	if ( (*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYNAME, &tmp) == PPXA_NO_ERROR ){
		*Value = ::SysAllocString(tmp.path);
		return S_OK;
	}
	return DISP_E_EXCEPTION;
}

STDMETHODIMP CEntry::get_ShortName(BSTR *Value)
{
	PPXUPTR_INDEX_UPATHW tmp;

	tmp.index = m_index;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYANAME, &tmp);
	if ( tmp.path[0] == '\0' ){
		(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYNAME, &tmp);
	}
	*Value = ::SysAllocString(tmp.path);
	return S_OK;
}

STDMETHODIMP CEntry::get_Attributes(long *Value)
{
	*((long *)Value) = m_index;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYATTR, Value);
	return S_OK;
}

STDMETHODIMP CEntry::get_Size(double *Value)
{
	DWORD size[2];

	size[0] = m_index;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYMSIZE, size);
	*Value = (double)size[0] + (double)size[1] * DWORDPP;

	return S_OK;
}

STDMETHODIMP CEntry::get_DateCreated(double *Value)
{
	FILETIME ftime, ltime;
	SYSTEMTIME stime;

	ftime.dwLowDateTime = m_index;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYCTIME, &ftime);

	FileTimeToLocalFileTime(&ftime, &ltime);
	FileTimeToSystemTime(&ltime, &stime);
	SystemTimeToVariantTime(&stime, Value);
	return S_OK;
}

STDMETHODIMP CEntry::get_DateLastAccessed(double *Value)
{
	FILETIME ftime, ltime;
	SYSTEMTIME stime;

	ftime.dwLowDateTime = m_index;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYATIME, &ftime);

	FileTimeToLocalFileTime(&ftime, &ltime);
	FileTimeToSystemTime(&ltime, &stime);
	SystemTimeToVariantTime(&stime, Value);
	return S_OK;
}

STDMETHODIMP CEntry::get_DateLastModified(double *Value)
{
	FILETIME ftime, ltime;
	SYSTEMTIME stime;

	ftime.dwLowDateTime = m_index;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYMTIME, &ftime);

	FileTimeToLocalFileTime(&ftime, &ltime);
	FileTimeToSystemTime(&ltime, &stime);
	SystemTimeToVariantTime(&stime, Value);
	return S_OK;
}

STDMETHODIMP CEntry::get_Mark(long *Value)
{
	*Value = m_index;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYMARK, Value);
	return S_OK;
}

STDMETHODIMP CEntry::set_Mark(long Value)
{
	long nums[2];

	nums[0] = Value;
	nums[1] = m_index;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYSETMARK, nums);
	m_index = nums[1]; // â¡çHçœÇ›ÇÃílÇâÒé˚ÇµÇƒçÇë¨âª
	return S_OK;
}

STDMETHODIMP CEntry::get_State(long *Value)
{
	*Value = m_index;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYSTATE, Value);
	*Value &= 0x1f;
	return S_OK;
}

STDMETHODIMP CEntry::set_State(long Value)
{
	long nums[2];

	nums[0] = m_index;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYSTATE, &nums[0]);

	nums[0] = (nums[0] & 0xffe0) | Value;
	nums[1] = m_index;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYSETSTATE, nums);
	m_index = nums[1]; // â¡çHçœÇ›ÇÃílÇâÒé˚ÇµÇƒçÇë¨âª
	return S_OK;
}

STDMETHODIMP CEntry::get_Highlight(long *Value)
{
	*Value = m_index;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYSTATE, Value);
	*Value >>= 5;
	return S_OK;
}

STDMETHODIMP CEntry::set_Highlight(long Value)
{
	long nums[2];

	nums[0] = m_index;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYSTATE, &nums[0]);

	nums[0] = (nums[0] & 0x1f) | (Value << 5);
	nums[1] = m_index;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYSETSTATE, nums);
	m_index = nums[1]; // â¡çHçœÇ›ÇÃílÇâÒé˚ÇµÇƒçÇë¨âª
	return S_OK;
}

STDMETHODIMP CEntry::get_ExtColor(long *Value)
{
	*Value = m_index;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYEXTCOLOR, Value);
	return S_OK;
}

STDMETHODIMP CEntry::set_ExtColor(long Value)
{
	long nums[2];

	nums[0] = Value;
	nums[1] = m_index;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYSETEXTCOLOR, nums);
	m_index = nums[1]; // â¡çHçœÇ›ÇÃílÇâÒé˚ÇµÇƒçÇë¨âª
	return S_OK;
}

STDMETHODIMP CEntry::get_Comment(BSTR *Value)
{
	WCHAR bufw[CMDLINESIZE];

	*((long *)bufw) = m_index;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYCOMMENT, bufw);
	*Value = ::SysAllocString(bufw);
	return S_OK;
}

STDMETHODIMP CEntry::set_Comment(BSTR Value)
{
	WCHAR bufw[CMDLINESIZE];
	UINT len;

	*((long *)bufw) = m_index;
	len = SysStringLen(Value);
	if ( len != 0 ) memcpy(bufw + 2, Value, sizeof(WCHAR) * len);
	bufw[len + 2] = '\0';
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYSETCOMMENT, bufw);
	return S_OK;
}

STDMETHODIMP CEntry::Information(BSTR *Value)
{
	PPXUPTR_ENTRYINFOW entryinfo;

	entryinfo.index = m_index;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYINFO, &entryinfo);
	if ( (DWORD_PTR)entryinfo.result < 0x10000 ) return E_NOTIMPL;
	*Value = ::SysAllocString(entryinfo.result);
	HeapFree(GetProcessHeap(), 0, entryinfo.result);
	return S_OK;
}

STDMETHODIMP CEntry::GetComment(long id, BSTR *Value)
{
	ENTRYEXTDATASTRUCT eeds;
	WCHAR bufw[CMDLINESIZE];

	eeds.entry = m_index;
	eeds.id = (id > 100) ? id : (DFC_COMMENTEX_MAX - (id - 1));
	eeds.size = sizeof(bufw);
	eeds.data = (BYTE *)bufw;
	if ( (*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYEXTDATA_GETDATA, &eeds) == 0 ){
		bufw[0] = '\0';
	}
	*Value = ::SysAllocString(bufw);
	return S_OK;
}

STDMETHODIMP CEntry::SetComment(long id, BSTR Value)
{
	ENTRYEXTDATASTRUCT eeds;

	eeds.entry = m_index;
	eeds.id = (id > 100) ? id : (DFC_COMMENTEX_MAX - (id - 1));
	if ( Value != NULL ){
		eeds.size = (SysStringLen(Value) + 1) * sizeof(WCHAR);
		if ( eeds.size == sizeof(WCHAR) ){ // ãÛï∂éöóÒ
			eeds.data = (BYTE *)L"";
		} else{
			eeds.data = (BYTE *)Value;
		}
	}else{
		eeds.size = sizeof(WCHAR);
		eeds.data = (BYTE *)L"";
	}
	if ( (*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYEXTDATA_SETDATA, &eeds) == 0 ){
		return E_NOTIMPL;
	}
	return S_OK;
}

STDMETHODIMP CEntry::IndexFrom(BSTR name, LONG *moved)
{
	PPXUPTR_ENTRYINFOW info;

	info.result = name;
	if ( PPXA_NO_ERROR == (*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYFROMNAME, &info) ){
		*moved = 1;
		m_index = info.index;
	}else{
		*moved = 0;
	}
	return S_OK;
}

//----------------------------------------------------- IEnumVARIANT
STDMETHODIMP CEntry::Next(ULONG celt, VARIANT *rgvar, ULONG *CeltFetched)
{
	int maxindex;

	Debug_WriteLog(CLASSNAMES "::Next", NULL);
	if ( CeltFetched != NULL ) *CeltFetched = 0;
	if ( celt == 0 ) return S_OK;
	if ( (rgvar == NULL) || ((celt != 1) && (CeltFetched == NULL)) ){
		return E_INVALIDARG;
	}
	if ( m_index == -2 ){ // ç≈èâÇ©ÇÁ
		if ( EnumMode == 2 ){
			m_next_index = 0;
		}else{
			if ( (*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYMARKFIRST_HS, &m_next_index) == 0 ){
				if ( (*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYMARKFIRST, &m_next_index) == 0 ){
					return S_FALSE;
				}
			}
			if ( m_next_index == -1 ){
				if ( EnumMode == 1 ) return S_FALSE;
				ResetIndex();
				m_next_index = m_index;
			}
		}
	}
	if ( EnumMode == 2 ) (*m_ppxa)->Function(*m_ppxa, PPXCMDID_DIRTTOTAL, &maxindex);

	while ( celt-- ){
		if ( m_index == -1 ) return S_FALSE;
		m_index = m_next_index;
		if ( m_index == -1 ) return S_FALSE;

		if ( IsEntryVailed(m_index) == false ){
			celt++;
		}else{
			if ( rgvar != NULL ){
				rgvar->vt = VT_DISPATCH;
				rgvar->pdispVal = this;
				AddRef();
				rgvar++;
				if ( CeltFetched != NULL ) (*CeltFetched)++;
			}
		}
		if ( EnumMode == 2 ){
			m_next_index++;
			if ( m_next_index >= maxindex ) m_next_index = -1;
		}else{
			if ( (*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYMARKNEXT_HS, &m_next_index) == 0 ){
				(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYMARKNEXT, &m_next_index);
			}
		}
	}
	return S_OK;
}

STDMETHODIMP CEntry::Skip(ULONG celt)
{
	Debug_WriteLog(CLASSNAMES "::Skip", NULL);
	return Next(celt, NULL, NULL);
}

STDMETHODIMP CEntry::Reset()
{
	Debug_WriteLog(CLASSNAMES "::Reset", NULL);
	m_index = -2;
	m_next_index = -2;
	return S_OK;
}

STDMETHODIMP CEntry::Clone(IEnumVARIANT FAR* FAR*)
{
	Debug_WriteLog(CLASSNAMES "::Clone", NULL);
	return E_NOTIMPL;
}

void CEntry::ResetIndex()
{
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_CSRINDEX, &m_index); // ÉJÅ[É\Éãà íuÇèâä˙âª
	return;
}

STDMETHODIMP CEntry::Hide()
{
	Debug_WriteLog(CLASSNAMES "::Hide", NULL);
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYHIDEENTRY, &m_index);
	return S_OK;
}

STDMETHODIMP CEntry::FirstMark(long *result)
{
	Debug_WriteLog(CLASSNAMES "::FirstMark", NULL);

	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYMARKFIRST_HS, result);
	if ( *result == -1 ){
		*result = 0;
	} else{
		m_index = *result;
		*result = 1;
	}
	return S_OK;
}

STDMETHODIMP CEntry::NextMark(long *result)
{
	Debug_WriteLog(CLASSNAMES "::Next", NULL);

	*result = m_index;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYMARKNEXT_HS, result);
	if ( *result == -1 ){
		*result = 0;
	} else{
		m_index = *result;
		*result = 1;
	}
	return S_OK;
}

STDMETHODIMP CEntry::PrevMark(long *result)
{
	Debug_WriteLog(CLASSNAMES "::Prev", NULL);

	*result = m_index;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYMARKPREV_HS, result);
	if ( *result == -1 ){
		*result = 0;
	} else{
		m_index = *result;
		*result = 1;
	}
	return S_OK;
}

STDMETHODIMP CEntry::LastMark(long *result)
{
	Debug_WriteLog(CLASSNAMES "::Prev", NULL);

	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYMARKLAST_HS, result);
	if ( *result == -1 ){
		*result = 0;
	} else{
		m_index = *result;
		*result = 1;
	}
	return S_OK;
}

bool CEntry::IsEntryVailed(int newindex)
{
	int state;
	WCHAR bufW[CMDLINESIZE];

	state = newindex;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYSTATE, &state);
	if ( (state & 7) < 2 ) return false; // < ECS_NORMAL

	*(DWORD *)bufW = newindex;
	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYNAME, &bufW);
	if ( (bufW[0] == '.') &&
		 ((bufW[1] == '\0') ||
		  ((bufW[1] == '.') && (bufW[2] == '\0') ) ) ){ // . or ..
		return false;
	}
	return true;
}

bool CEntry::CheckNextEntryAt(int newindex)
{
	int maxindex;

	(*m_ppxa)->Function(*m_ppxa, PPXCMDID_DIRTTOTAL, &maxindex);
	for(;;){
		if ( newindex >= maxindex ) return true;
		if ( IsEntryVailed(newindex) == true ){
			m_index = newindex;
			return false;
		}
		newindex++;
	}
}

STDMETHODIMP CEntry::moveNext( long * Value )
{
	*Value = m_index;
	return S_OK;
}

STDMETHODIMP CEntry::atEnd(long * value )
{
	int result;

	if ( EnumMode < 0 ){ // èâÇﬂÇƒ
		EnumMode = -EnumMode - 1;
		if ( EnumMode == 2 ){
			*value = CheckNextEntryAt(0);
			return S_OK;
		}

		(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYMARKFIRST_HS, &result);
		if ( result == -1 ){
			if ( EnumMode == 0 ){
				(*m_ppxa)->Function(*m_ppxa, PPXCMDID_CSRINDEX, &result);
				m_index = result;
			}else{
				*value = 1;
				return S_OK;
			}
		} else{
			m_index = result;
		}
		if ( IsEntryVailed(m_index) == true ){
			*value = 0;
			return S_OK;
		}
	}

	// ÇQâÒñ⁄à»ç~
	if ( EnumMode == 2 ){
		*value = CheckNextEntryAt(m_index + 1);
		return S_OK;
	}
	for (;;){
		result = m_index;
		(*m_ppxa)->Function(*m_ppxa, PPXCMDID_ENTRYMARKNEXT_HS, &result);
		if ( result == -1 ){
			*value = 1;
			return S_OK;
		}
		m_index = result;
		if ( IsEntryVailed(result) == true ){
			*value = 0;
			return S_OK;
		}
	}
}
STDMETHODIMP CEntry::get_Current(IEntry ** Value )
{
	return Item(-1, Value);
}
STDMETHODIMP CEntry::get_AllMark(IEntry ** Value )
{
	HRESULT result = Item(-1, Value);
	if ( FAILED(result) ) return result;
	static_cast<CEntry *>(*Value)->EnumMode = -2;
	return result;
}
STDMETHODIMP CEntry::get_AllEntry(IEntry ** Value )
{
	HRESULT result = Item(-1, Value);
	if ( FAILED(result) ) return result;
	static_cast<CEntry *>(*Value)->EnumMode = -3;
	return result;
}

//================================================================== CEnumEntry
#undef CLASSNAME
#define CLASSNAME CEnumEntry
#undef CLASSNAMES
#define CLASSNAMES "CEnumEntry"

CEnumEntry::CEnumEntry(InstanceValueStruct *InstanceValue, int EnumMode)
{
	T_IUNKNOWN_INITDEFINE();

	m_centry = new CEntry(InstanceValue);
	m_centry->AddRef();
	if ( EnumMode < 0 ) EnumMode = -EnumMode - 1;
	m_centry->EnumMode = EnumMode;
	m_centry->Reset();
}

CEnumEntry::~CEnumEntry()
{
	m_centry->Release();
}

//----------------------------------------------------- IUnknown
T_IUNKNOWN_ADDREFDEFINE(CLASSNAME)
T_IUNKNOWN_RELEASEDEFINE(CLASSNAME)
T_IUNKNOWN_QUERYINTERFACEDEFINE(CLASSNAME, (riid == IID_IEnumVARIANT))

//----------------------------------------------------- IEnumVARIANT
STDMETHODIMP CEnumEntry::Next(ULONG celt, VARIANT *rgvar, ULONG *CeltFetched)
{
	Debug_WriteLog(CLASSNAMES "::Next", NULL);
	return m_centry->Next(celt, rgvar, CeltFetched);
}

STDMETHODIMP CEnumEntry::Skip(ULONG celt)
{
	Debug_WriteLog(CLASSNAMES "::Skip", NULL);
	return m_centry->Skip(celt);
}

STDMETHODIMP CEnumEntry::Reset()
{
	Debug_WriteLog(CLASSNAMES "::Reset", NULL);
	return m_centry->Reset();
}

STDMETHODIMP CEnumEntry::Clone(IEnumVARIANT **)
{
	Debug_WriteLog(CLASSNAMES "::Clone", NULL);
	return E_NOTIMPL;
}
