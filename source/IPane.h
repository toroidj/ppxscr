/*-----------------------------------------------------------------------------
	Paper Plane xUI  Script Module							IPane
-----------------------------------------------------------------------------*/
#ifndef CPane_H
#define CPane_H

class CPane :
	public IPane
{
public:
	CPane(InstanceValueStruct *InstanceValue);
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
	STDMETHODIMP Item(long nIndex, IPane **pValue);
	// custom
	STDMETHODIMP get_length(long *plCount);
// IPane
	STDMETHODIMP get_index(long *Value/*[out, retval]*/);
	STDMETHODIMP set_index(long Value/*[in]*/);

	STDMETHODIMP get_Tab(ITab ** Value);

	STDMETHODIMP IndexFrom(BSTR name, LONG *moved);

	STDMETHODIMP Next(/* [in] */ULONG celt, /* [length_is][size_is][out] */VARIANT *rgvar, /* [out] */ULONG *CeltFetched);
	STDMETHODIMP Skip(/* [in] */ULONG celt);
	STDMETHODIMP Reset();

	STDMETHODIMP moveNext( long * Value );
	STDMETHODIMP atEnd(long * value );
	STDMETHODIMP get_Current(IPane ** Value );

	STDMETHODIMP get_GroupIndex(long* Value/*[out,retval]*/);
	STDMETHODIMP set_GroupIndex(long Value/*[in]*/);
	STDMETHODIMP get_GroupCount(long* Value/*[out,retval]*/);
	STDMETHODIMP get_GroupList(BSTR* list/*[out,retval]*/);
	STDMETHODIMP get_GroupName(BSTR* Value/*[out,retval]*/);
	STDMETHODIMP set_GroupName(BSTR Value/*[in]*/);

private:
// IUnknown
	int m_refCount;
// Local define
	PPXAPPINFOW **m_ppxa;
	int m_PaneIndex, m_EnumIndex;
	ITypeInfo *m_typeInfo;
	InstanceValueStruct*m_InstanceValue;
	long GetPaneIndex(void);
};

class CEnumPane :
	public IEnumVARIANT
{
public:
	CEnumPane(InstanceValueStruct *m_InstanceValue);
	~CEnumPane();
// IUnknown
	STDMETHODIMP QueryInterface(REFIID riid, void **ppvObj);
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();

// IEnumVARIANT
	STDMETHODIMP Next(/* [in] */ULONG celt, /* [length_is][size_is][out] */VARIANT *rgvar, /* [out] */ULONG *CeltFetched);
	STDMETHODIMP Skip(/* [in] */ULONG celt);
	STDMETHODIMP Reset();
	STDMETHODIMP Clone(IEnumVARIANT **ppenum);

private:
// IUnknown
	int m_refCount;
// Local define
	CPane *m_cpane;
};
#endif
