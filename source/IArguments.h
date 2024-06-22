/*-----------------------------------------------------------------------------
	Paper Plane xUI  Script Module							IArguments
-----------------------------------------------------------------------------*/
#ifndef CArguments_H
#define CArguments_H

class CArguments : public IArguments
{
public:
	CArguments(PPXAPPINFOW **ppxa, const WCHAR *Args, int ArgsCount);
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
					// _NewEnumはDISPID_NEWENUM(-4)固定
	STDMETHODIMP get__NewEnum(IUnknown** ppEnum);
	STDMETHODIMP get_Count(long *plCount);
	STDMETHODIMP Item(long nIndex, BSTR *pValue);
	// custom
	STDMETHODIMP get_length(long *plCount);
// IArguments
	// STDMETHODIMP get_Named(IArguments ** Value); // オプション一覧
	// STDMETHODIMP get_Unnamed(IArguments ** Value); // 非オプション一覧
	// STDMETHODIMP ShowUsage	// .wsfファイル上の場所

	STDMETHODIMP Reset( void );
	STDMETHODIMP moveNext( long * Value );
	STDMETHODIMP atEnd(long * value );
	STDMETHODIMP get_Current(IArguments ** Value );
	STDMETHODIMP get_Value(BSTR *pValue);

private:
// IUnknown
	int m_refCount;
// Local define
	PPXAPPINFOW **m_ppxa;
	int m_ArgsCount;		// 引数の数
	const WCHAR *m_Args;	// 引数へのポインタ
	ITypeInfo *m_typeInfo;
	int m_EnumIndex;
};

class CEnumArguments : public IEnumVARIANT
{
public:
	CEnumArguments(const WCHAR *Args, int ArgsCount);
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
	int m_ArgsCount;		// 引数の数
	const WCHAR *m_Args;	// 引数へのポインタ
	int m_EnumIndex;
};

extern STDMETHODIMP GetArgumentItem(PPXAPPINFOW *ppxa, const WCHAR *ptr, long nIndex, long nIndexMax, BSTR *Value);
#endif
