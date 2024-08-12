/*-----------------------------------------------------------------------------
	Paper Plane xUI  Script Module							IEntry
-----------------------------------------------------------------------------*/
#ifndef CEntry_H
#define CEntry_H

class CEntry :
	public IEntry,
	public IProvideMultipleClassInfo
{
public:
	CEntry(InstanceValueStruct *InstanceValue);
// IUnknown
	STDMETHODIMP QueryInterface(REFIID riid, void **ppvObj);
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();
// IProvideMultipleClassInfo オブジェクトの受信と発信に関する型情報を公開
	STDMETHODIMP GetMultiTypeInfoCount(ULONG *pcti);
	STDMETHODIMP GetInfoOfIndex(ULONG iti, DWORD dwMCIFlags,
			ITypeInfo **pptiCoClass, DWORD *pdwTIFlags,
			ULONG *pcdispidReserved, IID *piidPrimary, IID *piidSource);
// IProvideMultipleClassInfo(IProvideClassInfo)
	STDMETHODIMP GetClassInfo(ITypeInfo **ppTI);
// IProvideMultipleClassInfo(IProvideClassInfo2)
	STDMETHODIMP GetGUID(DWORD dwGuidKind, GUID *pGUID);
// IDispatch
	STDMETHODIMP GetTypeInfoCount(UINT *iTInfo);
	STDMETHODIMP GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo);
	STDMETHODIMP GetIDsOfNames(REFIID riid, OLECHAR **rgszNames, UINT cNames,
			LCID lcid, DISPID *rgDispId);
	STDMETHODIMP Invoke(DISPID dispIdMember, REFIID riid, LCID lcid,
			WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult,
			EXCEPINFO *pExcepInfo, UINT *puArgErr);
// ICollection
	// collection
					// _NewEnumはDISPID_NEWENUM(-4)固定
	STDMETHODIMP get__NewEnum(IUnknown** ppEnum);
	STDMETHODIMP get_Count(long *plCount);
	STDMETHODIMP Item(long nIndex, IEntry **pValue);
	// custom
	STDMETHODIMP get_length(long *plCount);

// IEnumVARIANTもどき
	STDMETHODIMP Next(/* [in] */ULONG celt, /* [length_is][size_is][out] */VARIANT *rgvar, /* [out] */ULONG *CeltFetched);
	STDMETHODIMP Skip(/* [in] */ULONG celt);
	STDMETHODIMP Reset();
	STDMETHODIMP Clone(IEnumVARIANT FAR* FAR *ppenum);

// IEntry
	STDMETHODIMP get_Name(BSTR *result);
	STDMETHODIMP get_index(long *Value/*[out, retval]*/);
	STDMETHODIMP set_index(long Value/*[in]*/);
	STDMETHODIMP get_Mark(long *Value/*[out, retval]*/);
	STDMETHODIMP set_Mark(long Value/*[in]*/);
	STDMETHODIMP get_Comment(BSTR *Value/*[out, retval]*/);
	STDMETHODIMP set_Comment(BSTR Value/*[in]*/);
	STDMETHODIMP get_Attributes(long *Value/*[out, retval]*/);
	STDMETHODIMP get_Size(double *Value/*[out, retval]*/);
	STDMETHODIMP get_State(long *Value/*[out, retval]*/);
	STDMETHODIMP set_State(long Value/*[in]*/);
	STDMETHODIMP get_Highlight(long *Value/*[out, retval]*/);
	STDMETHODIMP set_Highlight(long Value/*[in]*/);
	STDMETHODIMP get_ExtColor(long *Value/*[out, retval]*/);
	STDMETHODIMP set_ExtColor(long Value/*[in]*/);
	STDMETHODIMP get_DateCreated(double *Value/*[out, retval]*/);
	STDMETHODIMP get_DateLastAccessed(double *Value/*[out, retval]*/);
	STDMETHODIMP get_DateLastModified(double *Value/*[out, retval]*/);
	STDMETHODIMP get_ShortName(BSTR *Value/*[out, retval]*/);
	STDMETHODIMP Information(BSTR *Value/*[out, retval]*/);
	STDMETHODIMP Hide();
	STDMETHODIMP FirstMark(long *result);
	STDMETHODIMP NextMark(long *result);
	STDMETHODIMP PrevMark(long *result);
	STDMETHODIMP LastMark(long *result);
	STDMETHODIMP GetComment(long id, BSTR *Value);
	STDMETHODIMP SetComment(long id, BSTR Value);
	STDMETHODIMP IndexFrom(BSTR name, long* moved);

// etc
	void ResetIndex();

	STDMETHODIMP moveNext( long * Value );
	STDMETHODIMP atEnd(long * value );
	STDMETHODIMP get_Current(IEntry ** Value );
	STDMETHODIMP get_AllEntry(IEntry ** Value );
	STDMETHODIMP get_AllMark(IEntry ** Value );

#define ENUMENTRY_WITHMARK 1 // マーク順に列挙 マーク無しの時はカーソル位置のみ
#define ENUMENTRY_MARKONLY 2 // マーク順に列挙 マーク無しの時は列挙無し
#define ENUMENTRY_INDEX 3 // index 順に列挙
	int EnumMode; // 正:列挙未開始、負:列挙中
private:
// IUnknown
	int m_refCount;
// Local define
	PPXAPPINFOW **m_ppxa;
	ITypeInfo *m_typeInfo;
	int m_index, m_next_index;
	bool CheckNextEntryAt(int newindex);
	bool IsEntryVailed(int newindex);
	InstanceValueStruct *m_InstanceValue;
};

class CEnumEntry :
	public IEnumVARIANT
{
public:
	CEnumEntry(InstanceValueStruct *InstanceValue, int EnumMode);
	~CEnumEntry();
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
	CEntry *m_centry;
};
#endif
