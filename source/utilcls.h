// BC6 ではこの名前のヘッダに各種定義があるが、
// VC にはないので代用につかうヘッダ。※機能しない

#define __UTILCLS_H_VERSION 0x600

template <class T, const IID *piid = &GUID_NULL>
class TComInterface
{
};

template <class T>
class TDispWrapper : public T
{
//  void	Attach(DISPINTF *pintf){ m_Dispatch = pintf;}
	void	Detach() { m_Dispatch = 0; }
//	DISPINTF	*m_Dispatch;
	LCID		m_lcid;
	EXCEPINFO	m_ExcepInfo;
	UINT		m_ErrArg;
public:
	HRESULT __fastcall OleProcedure(DISPID dispid);
 /*
	HRESULT __fastcall OleProcedure(DISPID dispid, TAutoArgsBase& args);
	HRESULT __fastcall OleFunction(DISPID dispid, TAutoArgsBase& args);
	HRESULT __fastcall OleFunction(DISPID dispid);
	HRESULT __fastcall OlePropertyPut(DISPID dispid, TAutoArgsBase& args);
	HRESULT __fastcall OlePropertyGet(DISPID dispid, TAutoArgsBase& args);
 */
};
#define _TDispID int
