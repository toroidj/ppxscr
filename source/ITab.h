/*-----------------------------------------------------------------------------
	Paper Plane xUI  Script Module							ITab
-----------------------------------------------------------------------------*/
#ifndef CTab_H
#define CTab_H

class CTab :
	public ITab
{
public:
	CTab(InstanceValueStruct *InstanceValue, int paneindex);
// IUnknown
	STDMETHODIMP QueryInterface(REFIID riid, void **ppvObj);
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();

// IDispatch
	STDMETHODIMP GetTypeInfoCount(/* [out] */UINT *iTInfo);
	STDMETHODIMP GetTypeInfo(/* [in] */UINT iTInfo, /* [in] */LCID lcid, /* [out] */ITypeInfo **ppTInfo);
	STDMETHODIMP GetIDsOfNames(/* [in] */REFIID riid, /* [size_is][in] */OLECHAR **rgszNames, /* [in] */UINT cNames, /* [in] */LCID lcid, /* [size_is][out] */DISPID *rgDispId);
	STDMETHODIMP Invoke(/* [in] */DISPID dispIdMember, /* [in] */REFIID riid, /* [in] */LCID lcid, /* [in] */WORD wFlags, /* [out][in] */DISPPARAMS *pDispParams, /* [out] */VARIANT *pVarResult, /* [out] */EXCEPINFO *pExcepInfo, /* [out] */UINT *puArgErr);

// ICollection
					// _NewEnum‚ÍDISPID_NEWENUM(-4)ŒÅ’è
	STDMETHODIMP get__NewEnum(IUnknown** ppEnum);
	STDMETHODIMP get_Count(long *plCount);
	STDMETHODIMP Item(long nIndex, ITab **pValue);
	// custom
	STDMETHODIMP get_length(long *plCount);
// ITab
	STDMETHODIMP Execute(BSTR param, long *result);
	STDMETHODIMP Extract(BSTR param, BSTR *result);

	STDMETHODIMP get_Name(BSTR *result);
	STDMETHODIMP set_Name(wchar_t *result);
	STDMETHODIMP get_idname(BSTR *result);
	STDMETHODIMP get_Lock(long *Value/*[out, retval]*/);
	STDMETHODIMP set_Lock(long Value/*[in]*/);
	STDMETHODIMP get_index(long *Value/*[out, retval]*/);
	STDMETHODIMP set_index(long Value/*[in]*/);
	STDMETHODIMP get_Color(long *Value/*[out, retval]*/);
	STDMETHODIMP set_Color(long Value/*[in]*/);
	STDMETHODIMP get_BackColor(long *Value/*[out, retval]*/);
	STDMETHODIMP set_BackColor(long Value/*[in]*/);

	STDMETHODIMP get_Type(long *Value/*[out, retval]*/);
	STDMETHODIMP set_Type(long Value/*[in]*/);
	STDMETHODIMP get_Pane(long *Value/*[out, retval]*/);
	STDMETHODIMP set_Pane(long Value/*[in]*/);
	STDMETHODIMP get_TotalCount(long *Value/*[out, retval]*/);
	STDMETHODIMP get_TotalPPcCount(long *Value/*[out, retval]*/);

	STDMETHODIMP IndexFrom(BSTR name, LONG *moved);

	STDMETHODIMP Next(/* [in] */ULONG celt, /* [length_is][size_is][out] */VARIANT *rgvar, /* [out] */ULONG *pCeltFetched);
	STDMETHODIMP Skip(/* [in] */ULONG celt);
	STDMETHODIMP Reset();

	STDMETHODIMP moveNext( long * Value );
	STDMETHODIMP atEnd(long * value );
	STDMETHODIMP get_Current(ITab ** Value );

private:
// IUnknown
	int m_refCount;
// Local define
	PPXAPPINFOW **m_ppxa;
	int m_PaneIndex, m_TabIndex, m_EnumIndex;
	ITypeInfo *m_typeInfo;
	InstanceValueStruct *m_InstanceValue;
};

class CEnumTab :
	public IEnumVARIANT
{
public:
	CEnumTab(InstanceValueStruct *InstanceValue, int paneindex);
	~CEnumTab();
// IUnknown
	STDMETHODIMP QueryInterface(REFIID riid, void **ppvObj);
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();

// IEnumVARIANT
	STDMETHODIMP Next(/* [in] */ULONG celt, /* [length_is][size_is][out] */VARIANT *rgvar, /* [out] */ULONG *pCeltFetched);
	STDMETHODIMP Skip(/* [in] */ULONG celt);
	STDMETHODIMP Reset();
	STDMETHODIMP Clone(IEnumVARIANT **ppenum);

private:
// IUnknown
	int m_refCount;
// Local define
	CTab *m_ctab;
};
#endif
