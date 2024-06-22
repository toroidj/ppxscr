/*-----------------------------------------------------------------------------
	Paper Plane xUI  Script Module							CScriptBase
-----------------------------------------------------------------------------*/
#ifndef CScriptBase_H
#define CScriptBase_H

#define DISPID_CREATEOBJECT		1
#define DISPID_CONNECTOBJECT	2
#define DISPID_DISCONNECTOBJECT	3
#define DISPID_ECHO				4
#define DISPID_GETOBJECT		5
#define DISPID_QUIT				6
#define DISPID_SLEEP			7

#define DISPID_EXECUTE			8
#define DISPID_EXTRACT			9

struct FREECHAIN {
	FREECHAIN *next;
	void *value;
};

class CScriptBase :
	public IPPx,
	public IProvideMultipleClassInfo,
	public IConnectionPointContainer,
	public IConnectionPoint
{
public:
	CScriptBase(InstanceValueStruct *InstanceValue);
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
// IConnectionPointContainer オブジェクトの発信インターフェイスを公開
	STDMETHODIMP EnumConnectionPoints(IEnumConnectionPoints **ppEnum);
	STDMETHODIMP FindConnectionPoint(REFIID riid, IConnectionPoint **ppCP);
// IConnectionPoint オブジェクトの発信インターフェイスを公開
	STDMETHODIMP GetConnectionInterface(IID *pIID);
	STDMETHODIMP GetConnectionPointContainer(
			IConnectionPointContainer **ppCPC);
	STDMETHODIMP Advise(IUnknown *pUnk, DWORD *pdwCookie);
	STDMETHODIMP Unadvise(DWORD dwCookie);
	STDMETHODIMP EnumConnections(IEnumConnections **ppEnum);
// IDispatch
	STDMETHODIMP GetTypeInfoCount(UINT *iTInfo);
	STDMETHODIMP GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo);
	STDMETHODIMP GetIDsOfNames(REFIID riid, OLECHAR **rgszNames, UINT cNames,
			LCID lcid, DISPID *rgDispId);
	STDMETHODIMP Invoke(DISPID dispIdMember, REFIID riid, LCID lcid,
			WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult,
			EXCEPINFO *pExcepInfo, UINT *puArgErr);
// WScript
	STDMETHODIMP CreateObject(BSTR bstrProgId,
			BSTR bstrPrefix, IDispatch **ppObject);
	STDMETHODIMP ConnectObject(IDispatch *pObject, BSTR bstrPrefix);
	STDMETHODIMP DisconnectObject(IDispatch *pObject);
	STDMETHODIMP Echo(SAFEARRAY *parr);
	STDMETHODIMP GetObject(BSTR bstrPathName, BSTR bstrProgId,
			BSTR bstrPrefix, IDispatch **ppObject);
	STDMETHODIMP Quit(long nErrorCode);
	STDMETHODIMP Sleep(long nMilliseconds);
// PPx Methods
	STDMETHODIMP Execute(BSTR param, long *result);
	STDMETHODIMP Extract(BSTR param, BSTR *result);
	STDMETHODIMP EntryFirstMark(long *result);
	STDMETHODIMP EntryNextMark(long *result);
	STDMETHODIMP EntryPrevMark(long *result);
	STDMETHODIMP EntryLastMark(long *result);
	STDMETHODIMP lineMessage(BSTR message/*[in]*/);
	STDMETHODIMP SetPopLineMessage(BSTR message/*[in]*/);
	STDMETHODIMP report(BSTR text/*[in]*/);
	STDMETHODIMP log(BSTR text/*[in]*/);
	STDMETHODIMP GetFileInformation(BSTR param, long Mode, BSTR *result);
	STDMETHODIMP EntryInsert(long index, BSTR entryname);
	STDMETHODIMP Cursor(long x, long y, long *result); // [36]
	STDMETHODIMP option(BSTR name, VARIANT param, VARIANT *result);

	STDMETHODIMP GetComboItemCount(long id, long *result);
	STDMETHODIMP Enumerator(LPDISPATCH object, LPDISPATCH* Value);
	STDMETHODIMP Include(BSTR filename);

//		BOOL GetPreObject(LPCOLESTR bstrPrefix, IDispatch **ppObject);
	// PPx Properties
	STDMETHODIMP get_ScriptFullName(BSTR *Value/*[out, retval]*/);
	STDMETHODIMP get_ScriptName(BSTR *Value/*[out, retval]*/);

	STDMETHODIMP get_ModuleVersion(long *Value);
	STDMETHODIMP get_PPxVersion(long *Value);
	STDMETHODIMP get_CodeType(long *Value);
	STDMETHODIMP get_EntryAllCount(long *Value);
	STDMETHODIMP get_EntryDisplayCount(long *Value);
	STDMETHODIMP get_EntryMarkCount(long *Value);
	STDMETHODIMP get_EntryDisplayFiles(long *Value);
	STDMETHODIMP get_EntryDisplayDirectories(long *Value);
	STDMETHODIMP get_DirectoryType(long *Value);
	STDMETHODIMP get_SyncView(long *Value);
	STDMETHODIMP set_SyncView(long Value);
	STDMETHODIMP get_SlowMode(long *Value);
	STDMETHODIMP set_SlowMode(long Value);

	STDMETHODIMP get_result(BSTR *Value/*[out, retval]*/);
	STDMETHODIMP set_result(BSTR Value/*[in]*/);

	STDMETHODIMP get_Arguments(IArguments ** Value);
	STDMETHODIMP Argument(long intemindex, BSTR * Value);
	STDMETHODIMP get_Entry(IEntry ** Value);
	STDMETHODIMP get_Pane(IPane ** Value);

	STDMETHODIMP get_EntryName(BSTR *result);
	STDMETHODIMP get_EntryIndex(long *Value/*[out, retval]*/);
	STDMETHODIMP set_EntryIndex(long Value/*[in]*/);
	STDMETHODIMP get_EntryDisplayTop(long *Value/*[out, retval]*/);
	STDMETHODIMP set_EntryDisplayTop(long Value/*[in]*/);
	STDMETHODIMP get_EntryDisplayX(long *Value/*[out, retval]*/);
	STDMETHODIMP get_EntryDisplayY(long *Value/*[out, retval]*/);
	STDMETHODIMP get_WindowDirection(long *Value/*[out, retval]*/);
	STDMETHODIMP get_EntryMark(long *Value/*[out, retval]*/);
	STDMETHODIMP set_EntryMark(long Value/*[in]*/);
	STDMETHODIMP get_EntryComment(BSTR *Value/*[out, retval]*/);
	STDMETHODIMP set_EntryComment(BSTR Value/*[in]*/);
	STDMETHODIMP get_EntryAttributes(long *Value/*[out, retval]*/);
	STDMETHODIMP get_EntrySize(double *Value/*[out, retval]*/);
	STDMETHODIMP get_WindowIDName(BSTR *Value/*[out, retval]*/);
	STDMETHODIMP set_WindowIDName(BSTR Value/*[in]*/);
	STDMETHODIMP get_EntryState(long *Value/*[out, retval]*/);
	STDMETHODIMP set_EntryState(long Value/*[in]*/);
	STDMETHODIMP get_EntryHighlight(long *Value/*[out, retval]*/);
	STDMETHODIMP set_EntryHighlight(long Value/*[in]*/);
	STDMETHODIMP get_EntryExtColor(long *Value/*[out, retval]*/);
	STDMETHODIMP set_EntryExtColor(long Value/*[in]*/);

	STDMETHODIMP get_DriveVolumeLabel(BSTR *Value/*[out, retval]*/);
	STDMETHODIMP get_EntryMarkSize(double *Value/*[out, retval]*/);
	STDMETHODIMP get_DriveTotalSize(double *Value/*[out, retval]*/);
	STDMETHODIMP get_DriveFreeSize(double *Value/*[out, retval]*/);

	STDMETHODIMP get_Clipboard(BSTR *Value/*[out, retval]*/);
	STDMETHODIMP set_Clipboard(BSTR Value/*[in]*/);
	STDMETHODIMP get_StayMode(long *Value/*[out, retval]*/);
	STDMETHODIMP set_StayMode(long Value/*[in]*/);
	STDMETHODIMP get_PointType(long *Value/*[out, retval]*/);
	STDMETHODIMP get_PointIndex(long *Value/*[out, retval]*/);

	STDMETHODIMP get_ComboIDName(BSTR *Value/*[out, retval]*/);

	STDMETHODIMP get_ScriptEngineName(BSTR *Value/*[out, retval]*/);
	STDMETHODIMP get_ScriptEngineVersion(BSTR *Value/*[out, retval]*/);
	STDMETHODIMP getValue(BSTR key, BSTR * result);
	STDMETHODIMP setValue(BSTR key, BSTR value);
	STDMETHODIMP getProcessValue(BSTR key, BSTR * result);
	STDMETHODIMP setProcessValue(BSTR key, BSTR value);
	STDMETHODIMP getIValue(BSTR key, BSTR * result);
	STDMETHODIMP setIValue(BSTR key, BSTR value);
	STDMETHODIMP get_ReentryCount(long *Value/*[out, retval]*/);

// PPx Internal
	void SetResult();
	void UpdatePPxInfo();

// Local define
	int Var_ResultStatus; // 実行結果のステータス

private:
// IUnknown
	int m_refCount;
// Local define
	PPXAPPINFOW *ppxa;

	ITypeInfo *m_typeInfo;
	IPPxEvents *m_theConnection;
	BSTR m_ScriptLongResult;
	InstanceValueStruct *m_InstanceValue;
	ERRORCODE m_extract_result;
	void SinkDispatch(IDispatch *pDisp, BSTR prefix);
	FREECHAIN m_EventChain;
};
#endif
