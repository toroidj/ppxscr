// BC6 �ł͂��̖��O�̃w�b�_�Ɋe���`�����邪�A
// VC �ɂ͂Ȃ��̂ő�p�ɂ����w�b�_�B���@�\���Ȃ�

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
