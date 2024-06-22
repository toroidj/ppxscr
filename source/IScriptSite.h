/*-----------------------------------------------------------------------------
	Paper Plane xUI  Script Module							IScriptSite
-----------------------------------------------------------------------------*/
#ifndef CScriptSite_H
#define CScriptSite_H

class CScriptSite :
	public IActiveScriptSite,
	public IActiveScriptSiteWindow,
	public IActiveScriptSiteInterruptPoll
{
public:
	CScriptSite(PPXAPPINFOW *ppxaorg);
	~CScriptSite();
// IUnknown
	STDMETHODIMP QueryInterface(REFIID riid, void **ppvObj);
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();
// IActiveScriptSite
	STDMETHODIMP GetLCID(LCID *plcid);
	STDMETHODIMP GetItemInfo(LPCOLESTR pstrName, DWORD dwReturnMask,
			IUnknown **ppunkItem, ITypeInfo **ppTypeInfo);
	STDMETHODIMP GetDocVersionString(BSTR *pbstrVersionString);
	STDMETHODIMP OnScriptTerminate(
		const VARIANT *pvarResult, const EXCEPINFO *pexcepinfo);
	STDMETHODIMP OnStateChange(SCRIPTSTATE ssScriptState);
	STDMETHODIMP OnScriptError(IActiveScriptError *pase);
	STDMETHODIMP OnEnterScript(void);
	STDMETHODIMP OnLeaveScript(void);
// IActiveScriptSiteWindow
	STDMETHODIMP GetWindow(HWND *phwnd);
	STDMETHODIMP EnableModeless(BOOL fEnable);
// IActiveScriptSiteInterruptPoll
	STDMETHODIMP QueryContinue(void);
// Local define
	ERRORCODE result;

	int InitializeScriptSite(PPXMCOMMANDSTRUCT *pxc, const WCHAR *inline_type, int StayMode);
	int RunScript();
	void QuitScript();
	HRESULT InvokeScript(const WCHAR *funcname, const WCHAR *param, int paramcount);
	HRESULT CScriptSite::EvalScript(const WCHAR *script);
	InstanceValueStruct InstanceValue;

private:
// IUnknown
	int m_refCount;
// Local define
	WCHAR *m_ScriptImage;	//スクリプトファイル保存領域
};
#endif
