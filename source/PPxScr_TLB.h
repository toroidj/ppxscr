// ************************************************************************ //
//  警告                                                                      
// ------                                                                     
// このファイルで定義されている型宣言はタイプライブラリから読み出した       //
// 値を元に作成されています。タイプライブラリエディタで作業中に [ソー       //
// スコードの更新] ボタンを押したときや，ほかのタイプライブラリが直接       //
// または間接にこのタイプライブラリを参照している場合に，このファイル       //
// はタイプライブラリの値を元に再生成されます。                             //
// この場合，このファイル自身に対する変更は失われてしまいます。             //
// ************************************************************************ //

// C++ TLBWRTR : $Revision:   1.151.1.0.1.27  $
// このファイルは以下のタイプライブラリから 2024/06/21 22:42:17 に生成されました。

// ************************************************************************  //
// Type Lib: C:\Source\module\ppxscr\PPxScr.tlb (1)
// LIBID: {605CC4A1-BC99-44BC-A9A7-F2C1EF6FC943}
// LCID: 0
// Helpfile: 
// HelpString: PPx Script Module
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINDOWS\System32\stdole2.tlb)
// ************************************************************************ //
#ifndef   PPxScr_TLBH
#define   PPxScr_TLBH

#pragma option push -b -w-inl

#include <utilcls.h>
#if !defined(__UTILCLS_H_VERSION) || (__UTILCLS_H_VERSION < 0x0600)
//
// このコードは TLIBIMP または C++Builder IDE でタイプライブラリまたは ActiveX を
// 取り込むことで作成されました。特定のバージョンの INCLUDE\VCL\UTILCLS.H を前提
// に作成されているため、古いバージョンが使われていると警告された場合には、最新の
// ライブラリを入手してください。
//
#error "新しい UTILCLS.H が必要です。C++Builder のアップデート/パッチを当ててください。"
#endif
#include <olectl.h>
#include <ocidl.h>
#if defined(USING_ATLVCL) || defined(USING_ATL)
#if !defined(__TLB_NO_EVENT_WRAPPERS)
#include <atl/atlmod.h>
#endif
#endif


// *********************************************************************//
// (STDVCL.HPP をインクルードしないための) VCL 型の forward 宣言          
// *********************************************************************//
namespace Stdvcl {class IStrings; class IStringsDisp;}
using namespace Stdvcl;
typedef TComInterface<IStrings> IStringsPtr;
typedef TComInterface<IStringsDisp> IStringsDispPtr;

namespace Ppxscr_tlb
{

// *********************************************************************//
// HelpString: PPx Script Module
// Version:    1.0
// *********************************************************************//


// *********************************************************************//
// タイプライブラリ中の GUID の定義。以下の規則が使われます。             
//   Type Libraries     : LIBID_xxxx                                      
//   CoClasses          : CLSID_xxxx                                      
//   DISPInterfaces     : DIID_xxxx                                       
//   Non-DISP interfaces: IID_xxxx                                        
// *********************************************************************//
extern "C" const __declspec(selectany) GUID LIBID_PPxScr = {0x605CC4A1, 0xBC99, 0x44BC,{ 0xA9, 0xA7, 0xF2,0xC1, 0xEF, 0x6F,0xC9, 0x43} };
extern "C" const __declspec(selectany) GUID DIID_IPPxEvents = {0xA540CECD, 0x88F0, 0x4F99,{ 0xA1, 0xFF, 0x5F,0x20, 0xBA, 0x36,0xDF, 0x9F} };
extern "C" const __declspec(selectany) GUID IID_IPPx = {0x6114B9D8, 0x86E7, 0x4D41,{ 0x95, 0xDD, 0xDB,0x72, 0x62, 0x51,0x2B, 0xA6} };
extern "C" const __declspec(selectany) GUID CLSID_PPxObject = {0xEC40005E, 0x168A, 0x4B64,{ 0x94, 0x28, 0xB7,0x94, 0x91, 0x36,0xAF, 0xD8} };
extern "C" const __declspec(selectany) GUID IID_IArguments = {0x29BA7411, 0x9168, 0x4B39,{ 0xB8, 0x78, 0xB6,0x18, 0x1C, 0x78,0x28, 0x84} };
extern "C" const __declspec(selectany) GUID IID_IEntry = {0xE64F28F2, 0xF656, 0x4F61,{ 0x8C, 0xA7, 0x2F,0x4F, 0x97, 0xAB,0x25, 0xFF} };
extern "C" const __declspec(selectany) GUID IID_IPane = {0xA682BC0E, 0x0D72, 0x4D56,{ 0x88, 0x18, 0xFE,0x2E, 0x0E, 0x49,0xAE, 0x85} };
extern "C" const __declspec(selectany) GUID IID_ITab = {0xA05A073E, 0xC9E6, 0x4742,{ 0xA6, 0xF4, 0xEC,0xD6, 0xFD, 0x86,0xE5, 0xF3} };
extern "C" const __declspec(selectany) GUID CLSID_IArguments_Class = {0x8E05B06A, 0xC72E, 0x49D4,{ 0x98, 0xD1, 0x27,0xAA, 0xCB, 0x87,0xB5, 0xAD} };
extern "C" const __declspec(selectany) GUID CLSID_IEntry_Class = {0x83F5B8D1, 0x759E, 0x48CD,{ 0xB9, 0xB5, 0x4A,0x98, 0x17, 0x09,0xE1, 0xB6} };
extern "C" const __declspec(selectany) GUID CLSID_IPane_Class = {0x7A7AFF4F, 0x0122, 0x4BB7,{ 0xB0, 0x83, 0x38,0xA5, 0x8F, 0x7E,0x5D, 0x29} };
extern "C" const __declspec(selectany) GUID CLSID_ITab_Class = {0x015921B8, 0xBA6B, 0x4C64,{ 0xA0, 0xF9, 0x31,0xE5, 0x23, 0xA9,0xF6, 0x7F} };
extern "C" const __declspec(selectany) GUID IID_IPPxEnum = {0x4EA875C7, 0x268F, 0x4439,{ 0x96, 0xEE, 0xEA,0xFA, 0x90, 0x17,0x37, 0x88} };
extern "C" const __declspec(selectany) GUID CLSID_IPPxEnum_Class = {0x4EA475C7, 0x268F, 0x4139,{ 0x96, 0xEE, 0xEA,0xFA, 0x91, 0x17,0x37, 0x88} };

// *********************************************************************//
// タイプライブラリの型宣言のための forward 宣言                          
// *********************************************************************//
interface DECLSPEC_UUID("{A540CECD-88F0-4F99-A1FF-5F20BA36DF9F}") IPPxEvents;
typedef TComInterface<IPPxEvents, &DIID_IPPxEvents> IPPxEventsPtr;

interface DECLSPEC_UUID("{6114B9D8-86E7-4D41-95DD-DB7262512BA6}") IPPx;
typedef TComInterface<IPPx, &IID_IPPx> IPPxPtr;

interface DECLSPEC_UUID("{29BA7411-9168-4B39-B878-B6181C782884}") IArguments;
typedef TComInterface<IArguments, &IID_IArguments> IArgumentsPtr;

interface DECLSPEC_UUID("{E64F28F2-F656-4F61-8CA7-2F4F97AB25FF}") IEntry;
typedef TComInterface<IEntry, &IID_IEntry> IEntryPtr;

interface DECLSPEC_UUID("{A682BC0E-0D72-4D56-8818-FE2E0E49AE85}") IPane;
typedef TComInterface<IPane, &IID_IPane> IPanePtr;

interface DECLSPEC_UUID("{A05A073E-C9E6-4742-A6F4-ECD6FD86E5F3}") ITab;
typedef TComInterface<ITab, &IID_ITab> ITabPtr;

interface DECLSPEC_UUID("{4EA875C7-268F-4439-96EE-EAFA90173788}") IPPxEnum;
typedef TComInterface<IPPxEnum, &IID_IPPxEnum> IPPxEnumPtr;


// *********************************************************************//
// Declaration of CoClasses defined in Type Library                       
// (NOTE: Here we map each CoClass to its Default Interface)              
//                                                                        
// The LIBID_OF_ macro(s) map a LIBID_OF_CoClassName to the GUID of this  
// TypeLibrary. It simplifies the updating of macros when CoClass name    
// change.                                                                
// *********************************************************************//
typedef IPPx PPxObject;
typedef IPPxPtr PPxObjectPtr;
typedef IArguments IArguments_Class;
typedef IArgumentsPtr IArguments_ClassPtr;
typedef IEntry IEntry_Class;
typedef IEntryPtr IEntry_ClassPtr;
typedef IPane IPane_Class;
typedef IPanePtr IPane_ClassPtr;
typedef ITab ITab_Class;
typedef ITabPtr ITab_ClassPtr;
typedef IPPxEnum IPPxEnum_Class;
typedef IPPxEnumPtr IPPxEnum_ClassPtr;

#define LIBID_OF_PPxObject (&LIBID_PPxScr)
#define LIBID_OF_IArguments_Class (&LIBID_PPxScr)
#define LIBID_OF_IEntry_Class (&LIBID_PPxScr)
#define LIBID_OF_IPane_Class (&LIBID_PPxScr)
#define LIBID_OF_ITab_Class (&LIBID_PPxScr)
#define LIBID_OF_IPPxEnum_Class (&LIBID_PPxScr)
// *********************************************************************//
// Interface: IPPxEvents
// Flags:     (4096) Dispatchable
// GUID:      {A540CECD-88F0-4F99-A1FF-5F20BA36DF9F}
// *********************************************************************//
interface IPPxEvents : public TDispWrapper<IDispatch>
{

};
// *********************************************************************//
// Interface: IPPx
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {6114B9D8-86E7-4D41-95DD-DB7262512BA6}
// *********************************************************************//
interface IPPx  : public IDispatch
{
public:
  virtual HRESULT STDMETHODCALLTYPE Execute(BSTR param/*[in]*/, long* result/*[out,retval]*/) = 0; // [8]
  virtual HRESULT STDMETHODCALLTYPE DisconnectObject(LPDISPATCH pObject/*[in]*/) = 0; // [3]
  virtual HRESULT STDMETHODCALLTYPE ConnectObject(LPDISPATCH pObject/*[in]*/, 
                                                  BSTR bstrPrefix/*[in]*/) = 0; // [2]
  virtual HRESULT STDMETHODCALLTYPE CreateObject(BSTR bstrProgId/*[in]*/, 
                                                 BSTR bstrPrefix/*[in,def,opt]*/, 
                                                 LPDISPATCH* ppObject/*[out,retval]*/) = 0; // [1]
  virtual HRESULT STDMETHODCALLTYPE Extract(BSTR param/*[in]*/, BSTR* result/*[out,retval]*/) = 0; // [9]
  virtual HRESULT STDMETHODCALLTYPE Sleep(long nMilliseconds/*[in,opt]*/) = 0; // [7]
  virtual HRESULT STDMETHODCALLTYPE GetObject(BSTR bstrPathName/*[in]*/, 
                                              BSTR bstrProgId/*[in,def,opt]*/, 
                                              BSTR bstrPrefix/*[in,def,opt]*/, 
                                              LPDISPATCH* ppObject/*[out,retval]*/) = 0; // [5]
  virtual HRESULT STDMETHODCALLTYPE Echo(LPSAFEARRAY parr/*[in]*/) = 0; // [4]
  virtual HRESULT STDMETHODCALLTYPE get_EntryName(BSTR* Value/*[out,retval]*/) = 0; // [100]
  virtual HRESULT STDMETHODCALLTYPE get_ScriptFullName(BSTR* Value/*[out,retval]*/) = 0; // [200]
  virtual HRESULT STDMETHODCALLTYPE get_ScriptName(BSTR* Value/*[out,retval]*/) = 0; // [201]
  virtual HRESULT STDMETHODCALLTYPE get_EntryIndex(long* Value/*[out,retval]*/) = 0; // [101]
  virtual HRESULT STDMETHODCALLTYPE get_EntryDisplayTop(long* Value/*[out,retval]*/) = 0; // [102]
  virtual HRESULT STDMETHODCALLTYPE get_EntryDisplayX(long* Value/*[out,retval]*/) = 0; // [103]
  virtual HRESULT STDMETHODCALLTYPE get_EntryDisplayY(long* Value/*[out,retval]*/) = 0; // [104]
  virtual HRESULT STDMETHODCALLTYPE get_WindowDirection(long* Value/*[out,retval]*/) = 0; // [105]
  virtual HRESULT STDMETHODCALLTYPE get_EntryMark(long* Value/*[out,retval]*/) = 0; // [106]
  virtual HRESULT STDMETHODCALLTYPE set_EntryIndex(long Value/*[in]*/) = 0; // [101]
  virtual HRESULT STDMETHODCALLTYPE set_EntryMark(long Value/*[in]*/) = 0; // [106]
  virtual HRESULT STDMETHODCALLTYPE get_EntryComment(BSTR* Value/*[out,retval]*/) = 0; // [107]
  virtual HRESULT STDMETHODCALLTYPE set_EntryComment(BSTR Value/*[in]*/) = 0; // [107]
  virtual HRESULT STDMETHODCALLTYPE get_EntryAttributes(long* Value/*[out,retval]*/) = 0; // [108]
  virtual HRESULT STDMETHODCALLTYPE get_EntrySize(double* Value/*[out,retval]*/) = 0; // [109]
  virtual HRESULT STDMETHODCALLTYPE EntryFirstMark(long* result/*[out,retval]*/) = 0; // [11]
  virtual HRESULT STDMETHODCALLTYPE EntryNextMark(long* result/*[out,retval]*/) = 0; // [12]
  virtual HRESULT STDMETHODCALLTYPE SetPopLineMessage(BSTR message/*[in]*/) = 0; // [10]
  virtual HRESULT STDMETHODCALLTYPE get_PPxVersion(long* Value/*[out,retval]*/) = 0; // [300]
  virtual HRESULT STDMETHODCALLTYPE get_CodeType(long* Value/*[out,retval]*/) = 0; // [301]
  virtual HRESULT STDMETHODCALLTYPE get_EntryAllCount(long* Value/*[out,retval]*/) = 0; // [111]
  virtual HRESULT STDMETHODCALLTYPE get_EntryDisplayCount(long* Value/*[out,retval]*/) = 0; // [112]
  virtual HRESULT STDMETHODCALLTYPE get_EntryDisplayFiles(long* Value/*[out,retval]*/) = 0; // [113]
  virtual HRESULT STDMETHODCALLTYPE get_EntryDisplayDirectories(long* Value/*[out,retval]*/) = 0; // [114]
  virtual HRESULT STDMETHODCALLTYPE get_DirectoryType(long* Value/*[out,retval]*/) = 0; // [115]
  virtual HRESULT STDMETHODCALLTYPE get_SyncView(long* Value/*[out,retval]*/) = 0; // [150]
  virtual HRESULT STDMETHODCALLTYPE set_SyncView(long Value/*[in]*/) = 0; // [150]
  virtual HRESULT STDMETHODCALLTYPE get_ModuleVersion(long* Value/*[out,retval]*/) = 0; // [302]
  virtual HRESULT STDMETHODCALLTYPE get_EntryState(long* Value/*[out,retval]*/) = 0; // [13]
  virtual HRESULT STDMETHODCALLTYPE set_EntryState(long Value/*[in]*/) = 0; // [13]
  virtual HRESULT STDMETHODCALLTYPE get_EntryExtColor(long* Value/*[out,retval]*/) = 0; // [14]
  virtual HRESULT STDMETHODCALLTYPE set_EntryExtColor(long Value/*[in]*/) = 0; // [14]
  virtual HRESULT STDMETHODCALLTYPE get_result(BSTR* Value/*[out,retval]*/) = 0; // [15]
  virtual HRESULT STDMETHODCALLTYPE set_result(BSTR Value/*[in]*/) = 0; // [15]
  virtual HRESULT STDMETHODCALLTYPE get_Arguments(Ppxscr_tlb::IArguments** Value/*[out,retval]*/) = 0; // [16]
  virtual HRESULT STDMETHODCALLTYPE Quit(long ExitCode/*[in,opt]*/) = 0; // [6]
  virtual HRESULT STDMETHODCALLTYPE get_EntryMarkCount(long* Value/*[out,retval]*/) = 0; // [17]
  virtual HRESULT STDMETHODCALLTYPE get_Entry(Ppxscr_tlb::IEntry** Value/*[out,retval]*/) = 0; // [18]
  virtual HRESULT STDMETHODCALLTYPE get_SlowMode(long* Value/*[out,retval]*/) = 0; // [19]
  virtual HRESULT STDMETHODCALLTYPE set_SlowMode(long Value/*[in]*/) = 0; // [19]
  virtual HRESULT STDMETHODCALLTYPE GetFileInformation(BSTR FileName/*[in]*/, long Mode/*[in,opt]*/, 
                                                       BSTR* Text/*[out,retval]*/) = 0; // [20]
  virtual HRESULT STDMETHODCALLTYPE get_DriveVolumeLabel(BSTR* Value/*[out,retval]*/) = 0; // [21]
  virtual HRESULT STDMETHODCALLTYPE get_EntryMarkSize(double* Value/*[out,retval]*/) = 0; // [22]
  virtual HRESULT STDMETHODCALLTYPE get_DriveTotalSize(double* Value/*[out,retval]*/) = 0; // [23]
  virtual HRESULT STDMETHODCALLTYPE get_DriveFreeSize(double* Value/*[out,retval]*/) = 0; // [24]
  virtual HRESULT STDMETHODCALLTYPE EntryInsert(long index/*[in]*/, BSTR EntryName/*[in]*/) = 0; // [25]
  virtual HRESULT STDMETHODCALLTYPE get_Clipboard(BSTR* Value/*[out,retval]*/) = 0; // [26]
  virtual HRESULT STDMETHODCALLTYPE set_Clipboard(BSTR Value/*[in]*/) = 0; // [26]
  virtual HRESULT STDMETHODCALLTYPE get_StayMode(long* Value/*[out,retval]*/) = 0; // [27]
  virtual HRESULT STDMETHODCALLTYPE set_StayMode(long Value/*[in]*/) = 0; // [27]
  virtual HRESULT STDMETHODCALLTYPE get_EntryHighlight(long* Value/*[out,retval]*/) = 0; // [28]
  virtual HRESULT STDMETHODCALLTYPE set_EntryHighlight(long Value/*[in]*/) = 0; // [28]
  virtual HRESULT STDMETHODCALLTYPE get_Pane(Ppxscr_tlb::IPane** Value/*[out,retval]*/) = 0; // [29]
  virtual HRESULT STDMETHODCALLTYPE EntryPrevMark(long* result/*[out,retval]*/) = 0; // [30]
  virtual HRESULT STDMETHODCALLTYPE EntryLastMark(long* result/*[out,retval]*/) = 0; // [31]
  virtual HRESULT STDMETHODCALLTYPE GetComboItemCount(long id/*[in]*/, long* result/*[out]*/) = 0; // [32]
  virtual HRESULT STDMETHODCALLTYPE get_ComboIDName(BSTR* Value/*[out,retval]*/) = 0; // [33]
  virtual HRESULT STDMETHODCALLTYPE get_PointType(long* Value/*[out,retval]*/) = 0; // [34]
  virtual HRESULT STDMETHODCALLTYPE get_PointIndex(long* Value/*[out,retval]*/) = 0; // [35]
  virtual HRESULT STDMETHODCALLTYPE Cursor(long x/*[in]*/, long y/*[in,def,opt]*/, 
                                           long* result/*[out,retval]*/) = 0; // [36]
  virtual HRESULT STDMETHODCALLTYPE get_ScriptEngineName(BSTR* Value/*[out,retval]*/) = 0; // [37]
  virtual HRESULT STDMETHODCALLTYPE getValue(BSTR key/*[in]*/, BSTR* result/*[out,retval]*/) = 0; // [38]
  virtual HRESULT STDMETHODCALLTYPE setValue(BSTR key/*[in]*/, BSTR Value/*[in]*/) = 0; // [39]
  virtual HRESULT STDMETHODCALLTYPE get_ScriptEngineVersion(BSTR* Value/*[out,retval]*/) = 0; // [40]
  virtual HRESULT STDMETHODCALLTYPE lineMessage(BSTR Text/*[in]*/) = 0; // [41]
  virtual HRESULT STDMETHODCALLTYPE get_WindowIDName(BSTR* Value/*[out,retval]*/) = 0; // [42]
  virtual HRESULT STDMETHODCALLTYPE set_WindowIDName(BSTR Value/*[in]*/) = 0; // [42]
  virtual HRESULT STDMETHODCALLTYPE Argument(long itemindex/*[in,def,opt]*/, 
                                             BSTR* Arg/*[out,retval]*/) = 0; // [43]
  virtual HRESULT STDMETHODCALLTYPE report(BSTR Text/*[in]*/) = 0; // [44]
  virtual HRESULT STDMETHODCALLTYPE log(BSTR Text/*[in]*/) = 0; // [45]
  virtual HRESULT STDMETHODCALLTYPE getProcessValue(BSTR key/*[in]*/, BSTR* result/*[out,retval]*/) = 0; // [46]
  virtual HRESULT STDMETHODCALLTYPE setProcessValue(BSTR key/*[in]*/, BSTR Value/*[in]*/) = 0; // [48]
  virtual HRESULT STDMETHODCALLTYPE getIValue(BSTR key/*[in]*/, BSTR* result/*[out,retval]*/) = 0; // [49]
  virtual HRESULT STDMETHODCALLTYPE setIValue(BSTR key/*[in]*/, BSTR Value/*[in]*/) = 0; // [50]
  virtual HRESULT STDMETHODCALLTYPE Enumerator(LPDISPATCH object/*[in]*/, 
                                               LPDISPATCH* Value/*[out,retval]*/) = 0; // [51]
  virtual HRESULT STDMETHODCALLTYPE Include(BSTR FileName/*[in]*/) = 0; // [47]
  virtual HRESULT STDMETHODCALLTYPE get_ReentryCount(long* Value/*[out,retval]*/) = 0; // [52]
  virtual HRESULT STDMETHODCALLTYPE option(BSTR name/*[in]*/, VARIANT param/*[in,opt]*/, 
                                           VARIANT* Value/*[out,retval]*/) = 0; // [53]

#if !defined(__TLB_NO_INTERFACE_WRAPPERS)

  long __fastcall Execute(BSTR param/*[in]*/)
  {
    long result;
    OLECHECK(this->Execute(param, (long*)&result));
    return result;
  }

  LPDISPATCH __fastcall CreateObject(BSTR bstrProgId/*[in]*/, BSTR bstrPrefix/*[in,def,opt]*/)
  {
    LPDISPATCH ppObject;
    OLECHECK(this->CreateObject(bstrProgId, bstrPrefix, (LPDISPATCH*)&ppObject));
    return ppObject;
  }

  BSTR __fastcall Extract(BSTR param/*[in]*/)
  {
    BSTR result = 0;
    OLECHECK(this->Extract(param, (BSTR*)&result));
    return result;
  }

  LPDISPATCH __fastcall GetObject(BSTR bstrPathName/*[in]*/, BSTR bstrProgId/*[in,def,opt]*/, 
                                  BSTR bstrPrefix/*[in,def,opt]*/)
  {
    LPDISPATCH ppObject;
    OLECHECK(this->GetObject(bstrPathName, bstrProgId, bstrPrefix, (LPDISPATCH*)&ppObject));
    return ppObject;
  }

  BSTR __fastcall get_EntryName(void)
  {
    BSTR Value = 0;
    OLECHECK(this->get_EntryName((BSTR*)&Value));
    return Value;
  }

  BSTR __fastcall get_ScriptFullName(void)
  {
    BSTR Value = 0;
    OLECHECK(this->get_ScriptFullName((BSTR*)&Value));
    return Value;
  }

  BSTR __fastcall get_ScriptName(void)
  {
    BSTR Value = 0;
    OLECHECK(this->get_ScriptName((BSTR*)&Value));
    return Value;
  }

  long __fastcall get_EntryIndex(void)
  {
    long Value;
    OLECHECK(this->get_EntryIndex((long*)&Value));
    return Value;
  }

  long __fastcall get_EntryDisplayTop(void)
  {
    long Value;
    OLECHECK(this->get_EntryDisplayTop((long*)&Value));
    return Value;
  }

  long __fastcall get_EntryDisplayX(void)
  {
    long Value;
    OLECHECK(this->get_EntryDisplayX((long*)&Value));
    return Value;
  }

  long __fastcall get_EntryDisplayY(void)
  {
    long Value;
    OLECHECK(this->get_EntryDisplayY((long*)&Value));
    return Value;
  }

  long __fastcall get_WindowDirection(void)
  {
    long Value;
    OLECHECK(this->get_WindowDirection((long*)&Value));
    return Value;
  }

  long __fastcall get_EntryMark(void)
  {
    long Value;
    OLECHECK(this->get_EntryMark((long*)&Value));
    return Value;
  }

  BSTR __fastcall get_EntryComment(void)
  {
    BSTR Value = 0;
    OLECHECK(this->get_EntryComment((BSTR*)&Value));
    return Value;
  }

  long __fastcall get_EntryAttributes(void)
  {
    long Value;
    OLECHECK(this->get_EntryAttributes((long*)&Value));
    return Value;
  }

  double __fastcall get_EntrySize(void)
  {
    double Value;
    OLECHECK(this->get_EntrySize((double*)&Value));
    return Value;
  }

  long __fastcall EntryFirstMark(void)
  {
    long result;
    OLECHECK(this->EntryFirstMark((long*)&result));
    return result;
  }

  long __fastcall EntryNextMark(void)
  {
    long result;
    OLECHECK(this->EntryNextMark((long*)&result));
    return result;
  }

  long __fastcall get_PPxVersion(void)
  {
    long Value;
    OLECHECK(this->get_PPxVersion((long*)&Value));
    return Value;
  }

  long __fastcall get_CodeType(void)
  {
    long Value;
    OLECHECK(this->get_CodeType((long*)&Value));
    return Value;
  }

  long __fastcall get_EntryAllCount(void)
  {
    long Value;
    OLECHECK(this->get_EntryAllCount((long*)&Value));
    return Value;
  }

  long __fastcall get_EntryDisplayCount(void)
  {
    long Value;
    OLECHECK(this->get_EntryDisplayCount((long*)&Value));
    return Value;
  }

  long __fastcall get_EntryDisplayFiles(void)
  {
    long Value;
    OLECHECK(this->get_EntryDisplayFiles((long*)&Value));
    return Value;
  }

  long __fastcall get_EntryDisplayDirectories(void)
  {
    long Value;
    OLECHECK(this->get_EntryDisplayDirectories((long*)&Value));
    return Value;
  }

  long __fastcall get_DirectoryType(void)
  {
    long Value;
    OLECHECK(this->get_DirectoryType((long*)&Value));
    return Value;
  }

  long __fastcall get_SyncView(void)
  {
    long Value;
    OLECHECK(this->get_SyncView((long*)&Value));
    return Value;
  }

  long __fastcall get_ModuleVersion(void)
  {
    long Value;
    OLECHECK(this->get_ModuleVersion((long*)&Value));
    return Value;
  }

  long __fastcall get_EntryState(void)
  {
    long Value;
    OLECHECK(this->get_EntryState((long*)&Value));
    return Value;
  }

  long __fastcall get_EntryExtColor(void)
  {
    long Value;
    OLECHECK(this->get_EntryExtColor((long*)&Value));
    return Value;
  }

  BSTR __fastcall get_result(void)
  {
    BSTR Value = 0;
    OLECHECK(this->get_result((BSTR*)&Value));
    return Value;
  }

  Ppxscr_tlb::IArguments* __fastcall get_Arguments(void)
  {
    Ppxscr_tlb::IArguments* Value;
    OLECHECK(this->get_Arguments((Ppxscr_tlb::IArguments**)&Value));
    return Value;
  }

  long __fastcall get_EntryMarkCount(void)
  {
    long Value;
    OLECHECK(this->get_EntryMarkCount((long*)&Value));
    return Value;
  }

  Ppxscr_tlb::IEntry* __fastcall get_Entry(void)
  {
    Ppxscr_tlb::IEntry* Value;
    OLECHECK(this->get_Entry((Ppxscr_tlb::IEntry**)&Value));
    return Value;
  }

  long __fastcall get_SlowMode(void)
  {
    long Value;
    OLECHECK(this->get_SlowMode((long*)&Value));
    return Value;
  }

  BSTR __fastcall GetFileInformation(BSTR FileName/*[in]*/, long Mode/*[in,opt]*/)
  {
    BSTR Text = 0;
    OLECHECK(this->GetFileInformation(FileName, Mode, (BSTR*)&Text));
    return Text;
  }

  BSTR __fastcall get_DriveVolumeLabel(void)
  {
    BSTR Value = 0;
    OLECHECK(this->get_DriveVolumeLabel((BSTR*)&Value));
    return Value;
  }

  double __fastcall get_EntryMarkSize(void)
  {
    double Value;
    OLECHECK(this->get_EntryMarkSize((double*)&Value));
    return Value;
  }

  double __fastcall get_DriveTotalSize(void)
  {
    double Value;
    OLECHECK(this->get_DriveTotalSize((double*)&Value));
    return Value;
  }

  double __fastcall get_DriveFreeSize(void)
  {
    double Value;
    OLECHECK(this->get_DriveFreeSize((double*)&Value));
    return Value;
  }

  BSTR __fastcall get_Clipboard(void)
  {
    BSTR Value = 0;
    OLECHECK(this->get_Clipboard((BSTR*)&Value));
    return Value;
  }

  long __fastcall get_StayMode(void)
  {
    long Value;
    OLECHECK(this->get_StayMode((long*)&Value));
    return Value;
  }

  long __fastcall get_EntryHighlight(void)
  {
    long Value;
    OLECHECK(this->get_EntryHighlight((long*)&Value));
    return Value;
  }

  Ppxscr_tlb::IPane* __fastcall get_Pane(void)
  {
    Ppxscr_tlb::IPane* Value;
    OLECHECK(this->get_Pane((Ppxscr_tlb::IPane**)&Value));
    return Value;
  }

  long __fastcall EntryPrevMark(void)
  {
    long result;
    OLECHECK(this->EntryPrevMark((long*)&result));
    return result;
  }

  long __fastcall EntryLastMark(void)
  {
    long result;
    OLECHECK(this->EntryLastMark((long*)&result));
    return result;
  }

  BSTR __fastcall get_ComboIDName(void)
  {
    BSTR Value = 0;
    OLECHECK(this->get_ComboIDName((BSTR*)&Value));
    return Value;
  }

  long __fastcall get_PointType(void)
  {
    long Value;
    OLECHECK(this->get_PointType((long*)&Value));
    return Value;
  }

  long __fastcall get_PointIndex(void)
  {
    long Value;
    OLECHECK(this->get_PointIndex((long*)&Value));
    return Value;
  }

  long __fastcall Cursor(long x/*[in]*/, long y/*[in,def,opt]*/)
  {
    long result;
    OLECHECK(this->Cursor(x, y, (long*)&result));
    return result;
  }

  BSTR __fastcall get_ScriptEngineName(void)
  {
    BSTR Value = 0;
    OLECHECK(this->get_ScriptEngineName((BSTR*)&Value));
    return Value;
  }

  BSTR __fastcall getValue(BSTR key/*[in]*/)
  {
    BSTR result = 0;
    OLECHECK(this->getValue(key, (BSTR*)&result));
    return result;
  }

  BSTR __fastcall get_ScriptEngineVersion(void)
  {
    BSTR Value = 0;
    OLECHECK(this->get_ScriptEngineVersion((BSTR*)&Value));
    return Value;
  }

  BSTR __fastcall get_WindowIDName(void)
  {
    BSTR Value = 0;
    OLECHECK(this->get_WindowIDName((BSTR*)&Value));
    return Value;
  }

  BSTR __fastcall Argument(long itemindex/*[in,def,opt]*/)
  {
    BSTR Arg = 0;
    OLECHECK(this->Argument(itemindex, (BSTR*)&Arg));
    return Arg;
  }

  BSTR __fastcall getProcessValue(BSTR key/*[in]*/)
  {
    BSTR result = 0;
    OLECHECK(this->getProcessValue(key, (BSTR*)&result));
    return result;
  }

  BSTR __fastcall getIValue(BSTR key/*[in]*/)
  {
    BSTR result = 0;
    OLECHECK(this->getIValue(key, (BSTR*)&result));
    return result;
  }

  LPDISPATCH __fastcall Enumerator(LPDISPATCH object/*[in]*/)
  {
    LPDISPATCH Value;
    OLECHECK(this->Enumerator(object, (LPDISPATCH*)&Value));
    return Value;
  }

  long __fastcall get_ReentryCount(void)
  {
    long Value;
    OLECHECK(this->get_ReentryCount((long*)&Value));
    return Value;
  }

  VARIANT __fastcall option(BSTR name/*[in]*/, VARIANT param/*[in,opt]*/= TNoParam())
  {
    VARIANT Value;
    OLECHECK(this->option(name, param, (VARIANT*)&Value));
    return Value;
  }


  __property   BSTR            EntryName = {read = get_EntryName};
  __property   BSTR            ScriptFullName = {read = get_ScriptFullName};
  __property   BSTR            ScriptName = {read = get_ScriptName};
  __property   long            EntryIndex = {read = get_EntryIndex, write = set_EntryIndex};
  __property   long            EntryDisplayTop = {read = get_EntryDisplayTop};
  __property   long            EntryDisplayX = {read = get_EntryDisplayX};
  __property   long            EntryDisplayY = {read = get_EntryDisplayY};
  __property   long            WindowDirection = {read = get_WindowDirection};
  __property   long            EntryMark = {read = get_EntryMark, write = set_EntryMark};
  __property   BSTR            EntryComment = {read = get_EntryComment};
  __property   long            EntryAttributes = {read = get_EntryAttributes};
  __property   double          EntrySize = {read = get_EntrySize};
  __property   long            PPxVersion = {read = get_PPxVersion};
  __property   long            CodeType = {read = get_CodeType};
  __property   long            EntryAllCount = {read = get_EntryAllCount};
  __property   long            EntryDisplayCount = {read = get_EntryDisplayCount};
  __property   long            EntryDisplayFiles = {read = get_EntryDisplayFiles};
  __property   long            EntryDisplayDirectories = {read = get_EntryDisplayDirectories};
  __property   long            DirectoryType = {read = get_DirectoryType};
  __property   long            SyncView = {read = get_SyncView, write = set_SyncView};
  __property   long            ModuleVersion = {read = get_ModuleVersion};
  __property   long            EntryState = {read = get_EntryState, write = set_EntryState};
  __property   long            EntryExtColor = {read = get_EntryExtColor, write = set_EntryExtColor};
  __property   BSTR            result = {read = get_result};
  __property   Ppxscr_tlb::IArguments* Arguments = {read = get_Arguments};
  __property   long            EntryMarkCount = {read = get_EntryMarkCount};
  __property   Ppxscr_tlb::IEntry* Entry = {read = get_Entry};
  __property   long            SlowMode = {read = get_SlowMode, write = set_SlowMode};
  __property   BSTR            DriveVolumeLabel = {read = get_DriveVolumeLabel};
  __property   double          EntryMarkSize = {read = get_EntryMarkSize};
  __property   double          DriveTotalSize = {read = get_DriveTotalSize};
  __property   double          DriveFreeSize = {read = get_DriveFreeSize};
  __property   BSTR            Clipboard = {read = get_Clipboard};
  __property   long            StayMode = {read = get_StayMode, write = set_StayMode};
  __property   long            EntryHighlight = {read = get_EntryHighlight, write = set_EntryHighlight};
  __property   Ppxscr_tlb::IPane* Pane = {read = get_Pane};
  __property   BSTR            ComboIDName = {read = get_ComboIDName};
  __property   long            PointType = {read = get_PointType};
  __property   long            PointIndex = {read = get_PointIndex};
  __property   BSTR            ScriptEngineName = {read = get_ScriptEngineName};
  __property   BSTR            ScriptEngineVersion = {read = get_ScriptEngineVersion};
  __property   BSTR            WindowIDName = {read = get_WindowIDName};
  __property   long            ReentryCount = {read = get_ReentryCount};

#endif //   __TLB_NO_INTERFACE_WRAPPERS

};

// *********************************************************************//
// Interface: IArguments
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {29BA7411-9168-4B39-B878-B6181C782884}
// *********************************************************************//
interface IArguments  : public IDispatch
{
public:
  virtual HRESULT STDMETHODCALLTYPE Item(long index/*[in,opt]*/, BSTR* out_Value/*[out,retval]*/) = 0; // [0]
  virtual HRESULT STDMETHODCALLTYPE get__NewEnum(LPUNKNOWN* out_Enum/*[out,retval]*/) = 0; // [-4]
  virtual HRESULT STDMETHODCALLTYPE get_Count(long* Value/*[out,retval]*/) = 0; // [1]
  virtual HRESULT STDMETHODCALLTYPE get_length(long* Value/*[out,retval]*/) = 0; // [6]
  virtual HRESULT STDMETHODCALLTYPE Reset(void) = 0; // [2]
  virtual HRESULT STDMETHODCALLTYPE moveNext(long* Value/*[out,retval]*/) = 0; // [3]
  virtual HRESULT STDMETHODCALLTYPE atEnd(long* Value/*[out,retval]*/) = 0; // [4]
  virtual HRESULT STDMETHODCALLTYPE get_Current(Ppxscr_tlb::IArguments** Value/*[out,retval]*/) = 0; // [5]
  virtual HRESULT STDMETHODCALLTYPE get_Value(BSTR* Value/*[out,retval]*/) = 0; // [7]

#if !defined(__TLB_NO_INTERFACE_WRAPPERS)

  BSTR __fastcall Item(long index/*[in,opt]*/)
  {
    BSTR out_Value = 0;
    OLECHECK(this->Item(index, (BSTR*)&out_Value));
    return out_Value;
  }

  LPUNKNOWN __fastcall get__NewEnum(void)
  {
    LPUNKNOWN out_Enum;
    OLECHECK(this->get__NewEnum((LPUNKNOWN*)&out_Enum));
    return out_Enum;
  }

  long __fastcall get_Count(void)
  {
    long Value;
    OLECHECK(this->get_Count((long*)&Value));
    return Value;
  }

  long __fastcall get_length(void)
  {
    long Value;
    OLECHECK(this->get_length((long*)&Value));
    return Value;
  }

  long __fastcall moveNext(void)
  {
    long Value;
    OLECHECK(this->moveNext((long*)&Value));
    return Value;
  }

  long __fastcall atEnd(void)
  {
    long Value;
    OLECHECK(this->atEnd((long*)&Value));
    return Value;
  }

  Ppxscr_tlb::IArguments* __fastcall get_Current(void)
  {
    Ppxscr_tlb::IArguments* Value;
    OLECHECK(this->get_Current((Ppxscr_tlb::IArguments**)&Value));
    return Value;
  }

  BSTR __fastcall get_Value(void)
  {
    BSTR Value = 0;
    OLECHECK(this->get_Value((BSTR*)&Value));
    return Value;
  }


  __property   LPUNKNOWN       _NewEnum = {read = get__NewEnum};
  __property   long            Count = {read = get_Count};
  __property   long            length = {read = get_length};
  __property   Ppxscr_tlb::IArguments* Current = {read = get_Current};
  __property   BSTR            Value = {read = get_Value};

#endif //   __TLB_NO_INTERFACE_WRAPPERS

};

// *********************************************************************//
// Interface: IEntry
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {E64F28F2-F656-4F61-8CA7-2F4F97AB25FF}
// *********************************************************************//
interface IEntry  : public IDispatch
{
public:
  virtual HRESULT STDMETHODCALLTYPE Item(long index/*[in,opt]*/, 
                                         Ppxscr_tlb::IEntry** out_Value/*[out,retval]*/) = 0; // [0]
  virtual HRESULT STDMETHODCALLTYPE get__NewEnum(LPUNKNOWN* out_Enum/*[out,retval]*/) = 0; // [-4]
  virtual HRESULT STDMETHODCALLTYPE get_Count(long* Value/*[out,retval]*/) = 0; // [1]
  virtual HRESULT STDMETHODCALLTYPE get_Name(BSTR* Value/*[out,retval]*/) = 0; // [5]
  virtual HRESULT STDMETHODCALLTYPE get_index(long* Value/*[out,retval]*/) = 0; // [6]
  virtual HRESULT STDMETHODCALLTYPE set_index(long Value/*[in]*/) = 0; // [6]
  virtual HRESULT STDMETHODCALLTYPE get_Mark(long* Value/*[out,retval]*/) = 0; // [7]
  virtual HRESULT STDMETHODCALLTYPE set_Mark(long Value/*[in]*/) = 0; // [7]
  virtual HRESULT STDMETHODCALLTYPE get_Comment(BSTR* Value/*[out,retval]*/) = 0; // [8]
  virtual HRESULT STDMETHODCALLTYPE set_Comment(BSTR Value/*[in]*/) = 0; // [8]
  virtual HRESULT STDMETHODCALLTYPE get_Attributes(long* Value/*[out,retval]*/) = 0; // [9]
  virtual HRESULT STDMETHODCALLTYPE get_Size(double* Value/*[out,retval]*/) = 0; // [10]
  virtual HRESULT STDMETHODCALLTYPE get_State(long* Value/*[out,retval]*/) = 0; // [11]
  virtual HRESULT STDMETHODCALLTYPE set_State(long Value/*[in]*/) = 0; // [11]
  virtual HRESULT STDMETHODCALLTYPE get_ExtColor(long* Value/*[out,retval]*/) = 0; // [12]
  virtual HRESULT STDMETHODCALLTYPE set_ExtColor(long Value/*[in]*/) = 0; // [12]
  virtual HRESULT STDMETHODCALLTYPE get_length(long* Value/*[out,retval]*/) = 0; // [2]
  virtual HRESULT STDMETHODCALLTYPE get_DateCreated(DATE* Value/*[out,retval]*/) = 0; // [15]
  virtual HRESULT STDMETHODCALLTYPE get_DateLastAccessed(DATE* Value/*[out,retval]*/) = 0; // [16]
  virtual HRESULT STDMETHODCALLTYPE get_DateLastModified(DATE* Value/*[out,retval]*/) = 0; // [17]
  virtual HRESULT STDMETHODCALLTYPE get_ShortName(BSTR* Value/*[out,retval]*/) = 0; // [18]
  virtual HRESULT STDMETHODCALLTYPE get_Highlight(long* Value/*[out,retval]*/) = 0; // [3]
  virtual HRESULT STDMETHODCALLTYPE set_Highlight(long Value/*[in]*/) = 0; // [3]
  virtual HRESULT STDMETHODCALLTYPE NextMark(long* result/*[out,retval]*/) = 0; // [13]
  virtual HRESULT STDMETHODCALLTYPE PrevMark(long* result/*[out,retval]*/) = 0; // [14]
  virtual HRESULT STDMETHODCALLTYPE Hide(void) = 0; // [4]
  virtual HRESULT STDMETHODCALLTYPE FirstMark(long* result/*[out,retval]*/) = 0; // [20]
  virtual HRESULT STDMETHODCALLTYPE LastMark(long* result/*[out,retval]*/) = 0; // [21]
  virtual HRESULT STDMETHODCALLTYPE Information(BSTR* Value/*[out,retval]*/) = 0; // [19]
  virtual HRESULT STDMETHODCALLTYPE GetComment(long id/*[in,opt]*/, BSTR* Value/*[out,retval]*/) = 0; // [22]
  virtual HRESULT STDMETHODCALLTYPE SetComment(long id/*[in]*/, BSTR Value/*[in]*/) = 0; // [23]
  virtual HRESULT STDMETHODCALLTYPE Reset(void) = 0; // [24]
  virtual HRESULT STDMETHODCALLTYPE moveNext(long* Value/*[out,retval]*/) = 0; // [25]
  virtual HRESULT STDMETHODCALLTYPE get_AllMark(Ppxscr_tlb::IEntry** out_Value/*[out,retval]*/) = 0; // [26]
  virtual HRESULT STDMETHODCALLTYPE get_AllEntry(Ppxscr_tlb::IEntry** out_Value/*[out,retval]*/) = 0; // [27]
  virtual HRESULT STDMETHODCALLTYPE atEnd(long* Value/*[out,retval]*/) = 0; // [28]
  virtual HRESULT STDMETHODCALLTYPE get_Current(Ppxscr_tlb::IEntry** Value/*[out,retval]*/) = 0; // [29]
  virtual HRESULT STDMETHODCALLTYPE IndexFrom(BSTR Name/*[in]*/, long* moved/*[out,retval]*/) = 0; // [30]

#if !defined(__TLB_NO_INTERFACE_WRAPPERS)

  Ppxscr_tlb::IEntry* __fastcall Item(long index/*[in,opt]*/)
  {
    Ppxscr_tlb::IEntry* out_Value;
    OLECHECK(this->Item(index, (Ppxscr_tlb::IEntry**)&out_Value));
    return out_Value;
  }

  LPUNKNOWN __fastcall get__NewEnum(void)
  {
    LPUNKNOWN out_Enum;
    OLECHECK(this->get__NewEnum((LPUNKNOWN*)&out_Enum));
    return out_Enum;
  }

  long __fastcall get_Count(void)
  {
    long Value;
    OLECHECK(this->get_Count((long*)&Value));
    return Value;
  }

  BSTR __fastcall get_Name(void)
  {
    BSTR Value = 0;
    OLECHECK(this->get_Name((BSTR*)&Value));
    return Value;
  }

  long __fastcall get_index(void)
  {
    long Value;
    OLECHECK(this->get_index((long*)&Value));
    return Value;
  }

  long __fastcall get_Mark(void)
  {
    long Value;
    OLECHECK(this->get_Mark((long*)&Value));
    return Value;
  }

  BSTR __fastcall get_Comment(void)
  {
    BSTR Value = 0;
    OLECHECK(this->get_Comment((BSTR*)&Value));
    return Value;
  }

  long __fastcall get_Attributes(void)
  {
    long Value;
    OLECHECK(this->get_Attributes((long*)&Value));
    return Value;
  }

  double __fastcall get_Size(void)
  {
    double Value;
    OLECHECK(this->get_Size((double*)&Value));
    return Value;
  }

  long __fastcall get_State(void)
  {
    long Value;
    OLECHECK(this->get_State((long*)&Value));
    return Value;
  }

  long __fastcall get_ExtColor(void)
  {
    long Value;
    OLECHECK(this->get_ExtColor((long*)&Value));
    return Value;
  }

  long __fastcall get_length(void)
  {
    long Value;
    OLECHECK(this->get_length((long*)&Value));
    return Value;
  }

  DATE __fastcall get_DateCreated(void)
  {
    DATE Value;
    OLECHECK(this->get_DateCreated((DATE*)&Value));
    return Value;
  }

  DATE __fastcall get_DateLastAccessed(void)
  {
    DATE Value;
    OLECHECK(this->get_DateLastAccessed((DATE*)&Value));
    return Value;
  }

  DATE __fastcall get_DateLastModified(void)
  {
    DATE Value;
    OLECHECK(this->get_DateLastModified((DATE*)&Value));
    return Value;
  }

  BSTR __fastcall get_ShortName(void)
  {
    BSTR Value = 0;
    OLECHECK(this->get_ShortName((BSTR*)&Value));
    return Value;
  }

  long __fastcall get_Highlight(void)
  {
    long Value;
    OLECHECK(this->get_Highlight((long*)&Value));
    return Value;
  }

  long __fastcall NextMark(void)
  {
    long result;
    OLECHECK(this->NextMark((long*)&result));
    return result;
  }

  long __fastcall PrevMark(void)
  {
    long result;
    OLECHECK(this->PrevMark((long*)&result));
    return result;
  }

  long __fastcall FirstMark(void)
  {
    long result;
    OLECHECK(this->FirstMark((long*)&result));
    return result;
  }

  long __fastcall LastMark(void)
  {
    long result;
    OLECHECK(this->LastMark((long*)&result));
    return result;
  }

  BSTR __fastcall Information(void)
  {
    BSTR Value = 0;
    OLECHECK(this->Information((BSTR*)&Value));
    return Value;
  }

  BSTR __fastcall GetComment(long id/*[in,opt]*/)
  {
    BSTR Value = 0;
    OLECHECK(this->GetComment(id, (BSTR*)&Value));
    return Value;
  }

  long __fastcall moveNext(void)
  {
    long Value;
    OLECHECK(this->moveNext((long*)&Value));
    return Value;
  }

  Ppxscr_tlb::IEntry* __fastcall get_AllMark(void)
  {
    Ppxscr_tlb::IEntry* out_Value;
    OLECHECK(this->get_AllMark((Ppxscr_tlb::IEntry**)&out_Value));
    return out_Value;
  }

  Ppxscr_tlb::IEntry* __fastcall get_AllEntry(void)
  {
    Ppxscr_tlb::IEntry* out_Value;
    OLECHECK(this->get_AllEntry((Ppxscr_tlb::IEntry**)&out_Value));
    return out_Value;
  }

  long __fastcall atEnd(void)
  {
    long Value;
    OLECHECK(this->atEnd((long*)&Value));
    return Value;
  }

  Ppxscr_tlb::IEntry* __fastcall get_Current(void)
  {
    Ppxscr_tlb::IEntry* Value;
    OLECHECK(this->get_Current((Ppxscr_tlb::IEntry**)&Value));
    return Value;
  }

  long __fastcall IndexFrom(BSTR Name/*[in]*/)
  {
    long moved;
    OLECHECK(this->IndexFrom(Name, (long*)&moved));
    return moved;
  }


  __property   LPUNKNOWN       _NewEnum = {read = get__NewEnum};
  __property   long            Count = {read = get_Count};
  __property   BSTR            Name = {read = get_Name};
  __property   long            index = {read = get_index, write = set_index};
  __property   long            Mark = {read = get_Mark, write = set_Mark};
  __property   BSTR            Comment = {read = get_Comment};
  __property   long            Attributes = {read = get_Attributes};
  __property   double          Size = {read = get_Size};
  __property   long            State = {read = get_State, write = set_State};
  __property   long            ExtColor = {read = get_ExtColor, write = set_ExtColor};
  __property   long            length = {read = get_length};
  __property   DATE            DateCreated = {read = get_DateCreated};
  __property   DATE            DateLastAccessed = {read = get_DateLastAccessed};
  __property   DATE            DateLastModified = {read = get_DateLastModified};
  __property   BSTR            ShortName = {read = get_ShortName};
  __property   long            Highlight = {read = get_Highlight, write = set_Highlight};
  __property   Ppxscr_tlb::IEntry* AllMark = {read = get_AllMark};
  __property   Ppxscr_tlb::IEntry* AllEntry = {read = get_AllEntry};
  __property   Ppxscr_tlb::IEntry* Current = {read = get_Current};

#endif //   __TLB_NO_INTERFACE_WRAPPERS

};

// *********************************************************************//
// Interface: IPane
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {A682BC0E-0D72-4D56-8818-FE2E0E49AE85}
// *********************************************************************//
interface IPane  : public IDispatch
{
public:
  virtual HRESULT STDMETHODCALLTYPE Item(long index/*[in,opt]*/, 
                                         Ppxscr_tlb::IPane** Value/*[out,retval]*/) = 0; // [0]
  virtual HRESULT STDMETHODCALLTYPE get__NewEnum(LPUNKNOWN* out_Enum/*[out,retval]*/) = 0; // [-4]
  virtual HRESULT STDMETHODCALLTYPE get_Count(long* Value/*[out,retval]*/) = 0; // [1]
  virtual HRESULT STDMETHODCALLTYPE get_length(long* Value/*[out,retval]*/) = 0; // [6]
  virtual HRESULT STDMETHODCALLTYPE get_index(long* Value/*[out,retval]*/) = 0; // [2]
  virtual HRESULT STDMETHODCALLTYPE set_index(long Value/*[in]*/) = 0; // [2]
  virtual HRESULT STDMETHODCALLTYPE get_Name(BSTR* Value/*[out,retval]*/) = 0; // [3]
  virtual HRESULT STDMETHODCALLTYPE set_Name(BSTR Value/*[in]*/) = 0; // [3]
  virtual HRESULT STDMETHODCALLTYPE get_Tab(Ppxscr_tlb::ITab** Value/*[out,retval]*/) = 0; // [7]
  virtual HRESULT STDMETHODCALLTYPE Reset(void) = 0; // [4]
  virtual HRESULT STDMETHODCALLTYPE moveNext(long* Value/*[out,retval]*/) = 0; // [5]
  virtual HRESULT STDMETHODCALLTYPE atEnd(long* Value/*[out,retval]*/) = 0; // [9]
  virtual HRESULT STDMETHODCALLTYPE get_Current(Ppxscr_tlb::IPane** Value/*[out,retval]*/) = 0; // [10]
  virtual HRESULT STDMETHODCALLTYPE IndexFrom(BSTR ppcid/*[in]*/, long* moved/*[out,retval]*/) = 0; // [8]

#if !defined(__TLB_NO_INTERFACE_WRAPPERS)

  Ppxscr_tlb::IPane* __fastcall Item(long index/*[in,opt]*/)
  {
    Ppxscr_tlb::IPane* Value;
    OLECHECK(this->Item(index, (Ppxscr_tlb::IPane**)&Value));
    return Value;
  }

  LPUNKNOWN __fastcall get__NewEnum(void)
  {
    LPUNKNOWN out_Enum;
    OLECHECK(this->get__NewEnum((LPUNKNOWN*)&out_Enum));
    return out_Enum;
  }

  long __fastcall get_Count(void)
  {
    long Value;
    OLECHECK(this->get_Count((long*)&Value));
    return Value;
  }

  long __fastcall get_length(void)
  {
    long Value;
    OLECHECK(this->get_length((long*)&Value));
    return Value;
  }

  long __fastcall get_index(void)
  {
    long Value;
    OLECHECK(this->get_index((long*)&Value));
    return Value;
  }

  BSTR __fastcall get_Name(void)
  {
    BSTR Value = 0;
    OLECHECK(this->get_Name((BSTR*)&Value));
    return Value;
  }

  Ppxscr_tlb::ITab* __fastcall get_Tab(void)
  {
    Ppxscr_tlb::ITab* Value;
    OLECHECK(this->get_Tab((Ppxscr_tlb::ITab**)&Value));
    return Value;
  }

  long __fastcall moveNext(void)
  {
    long Value;
    OLECHECK(this->moveNext((long*)&Value));
    return Value;
  }

  long __fastcall atEnd(void)
  {
    long Value;
    OLECHECK(this->atEnd((long*)&Value));
    return Value;
  }

  Ppxscr_tlb::IPane* __fastcall get_Current(void)
  {
    Ppxscr_tlb::IPane* Value;
    OLECHECK(this->get_Current((Ppxscr_tlb::IPane**)&Value));
    return Value;
  }

  long __fastcall IndexFrom(BSTR ppcid/*[in]*/)
  {
    long moved;
    OLECHECK(this->IndexFrom(ppcid, (long*)&moved));
    return moved;
  }


  __property   LPUNKNOWN       _NewEnum = {read = get__NewEnum};
  __property   long            Count = {read = get_Count};
  __property   long            length = {read = get_length};
  __property   long            index = {read = get_index, write = set_index};
  __property   BSTR            Name = {read = get_Name};
  __property   Ppxscr_tlb::ITab* Tab = {read = get_Tab};
  __property   Ppxscr_tlb::IPane* Current = {read = get_Current};

#endif //   __TLB_NO_INTERFACE_WRAPPERS

};

// *********************************************************************//
// Interface: ITab
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {A05A073E-C9E6-4742-A6F4-ECD6FD86E5F3}
// *********************************************************************//
interface ITab  : public IDispatch
{
public:
  virtual HRESULT STDMETHODCALLTYPE Item(long index/*[in,opt]*/, 
                                         Ppxscr_tlb::ITab** Value/*[out,retval]*/) = 0; // [0]
  virtual HRESULT STDMETHODCALLTYPE get__NewEnum(LPUNKNOWN* out_Enum/*[out,retval]*/) = 0; // [-4]
  virtual HRESULT STDMETHODCALLTYPE get_Count(long* Value/*[out,retval]*/) = 0; // [1]
  virtual HRESULT STDMETHODCALLTYPE get_length(long* Value/*[out,retval]*/) = 0; // [6]
  virtual HRESULT STDMETHODCALLTYPE get_Lock(long* Value/*[out,retval]*/) = 0; // [4]
  virtual HRESULT STDMETHODCALLTYPE set_Lock(long Value/*[in]*/) = 0; // [4]
  virtual HRESULT STDMETHODCALLTYPE get_idname(BSTR* Value/*[out,retval]*/) = 0; // [5]
  virtual HRESULT STDMETHODCALLTYPE get_index(long* Value/*[out,retval]*/) = 0; // [2]
  virtual HRESULT STDMETHODCALLTYPE set_index(long Value/*[in]*/) = 0; // [2]
  virtual HRESULT STDMETHODCALLTYPE get_Name(BSTR* Value/*[out,retval]*/) = 0; // [3]
  virtual HRESULT STDMETHODCALLTYPE set_Name(BSTR Value/*[in]*/) = 0; // [3]
  virtual HRESULT STDMETHODCALLTYPE get_Type(long* Value/*[out,retval]*/) = 0; // [7]
  virtual HRESULT STDMETHODCALLTYPE set_Type(long Value/*[in]*/) = 0; // [7]
  virtual HRESULT STDMETHODCALLTYPE get_Pane(long* Value/*[out,retval]*/) = 0; // [8]
  virtual HRESULT STDMETHODCALLTYPE set_Pane(long Value/*[in]*/) = 0; // [8]
  virtual HRESULT STDMETHODCALLTYPE get_TotalCount(long* Value/*[out,retval]*/) = 0; // [9]
  virtual HRESULT STDMETHODCALLTYPE get_TotalPPcCount(long* Value/*[out,retval]*/) = 0; // [10]
  virtual HRESULT STDMETHODCALLTYPE get_Color(long* Value/*[out,retval]*/) = 0; // [11]
  virtual HRESULT STDMETHODCALLTYPE set_Color(long Value/*[in]*/) = 0; // [11]
  virtual HRESULT STDMETHODCALLTYPE get_BackColor(long* Value/*[out,retval]*/) = 0; // [12]
  virtual HRESULT STDMETHODCALLTYPE set_BackColor(long Value/*[in]*/) = 0; // [12]
  virtual HRESULT STDMETHODCALLTYPE Execute(BSTR param/*[in]*/, long* result/*[out,retval]*/) = 0; // [14]
  virtual HRESULT STDMETHODCALLTYPE Extract(BSTR param/*[in]*/, BSTR* result/*[out,retval]*/) = 0; // [15]
  virtual HRESULT STDMETHODCALLTYPE moveNext(long* Value/*[out,retval]*/) = 0; // [16]
  virtual HRESULT STDMETHODCALLTYPE atEnd(long* Value/*[out,retval]*/) = 0; // [17]
  virtual HRESULT STDMETHODCALLTYPE Reset(void) = 0; // [18]
  virtual HRESULT STDMETHODCALLTYPE get_Current(Ppxscr_tlb::ITab** Value/*[out,retval]*/) = 0; // [19]
  virtual HRESULT STDMETHODCALLTYPE IndexFrom(BSTR ppcid/*[in]*/, long* moved/*[out,retval]*/) = 0; // [13]

#if !defined(__TLB_NO_INTERFACE_WRAPPERS)

  Ppxscr_tlb::ITab* __fastcall Item(long index/*[in,opt]*/)
  {
    Ppxscr_tlb::ITab* Value;
    OLECHECK(this->Item(index, (Ppxscr_tlb::ITab**)&Value));
    return Value;
  }

  LPUNKNOWN __fastcall get__NewEnum(void)
  {
    LPUNKNOWN out_Enum;
    OLECHECK(this->get__NewEnum((LPUNKNOWN*)&out_Enum));
    return out_Enum;
  }

  long __fastcall get_Count(void)
  {
    long Value;
    OLECHECK(this->get_Count((long*)&Value));
    return Value;
  }

  long __fastcall get_length(void)
  {
    long Value;
    OLECHECK(this->get_length((long*)&Value));
    return Value;
  }

  long __fastcall get_Lock(void)
  {
    long Value;
    OLECHECK(this->get_Lock((long*)&Value));
    return Value;
  }

  BSTR __fastcall get_idname(void)
  {
    BSTR Value = 0;
    OLECHECK(this->get_idname((BSTR*)&Value));
    return Value;
  }

  long __fastcall get_index(void)
  {
    long Value;
    OLECHECK(this->get_index((long*)&Value));
    return Value;
  }

  BSTR __fastcall get_Name(void)
  {
    BSTR Value = 0;
    OLECHECK(this->get_Name((BSTR*)&Value));
    return Value;
  }

  long __fastcall get_Type(void)
  {
    long Value;
    OLECHECK(this->get_Type((long*)&Value));
    return Value;
  }

  long __fastcall get_Pane(void)
  {
    long Value;
    OLECHECK(this->get_Pane((long*)&Value));
    return Value;
  }

  long __fastcall get_TotalCount(void)
  {
    long Value;
    OLECHECK(this->get_TotalCount((long*)&Value));
    return Value;
  }

  long __fastcall get_TotalPPcCount(void)
  {
    long Value;
    OLECHECK(this->get_TotalPPcCount((long*)&Value));
    return Value;
  }

  long __fastcall get_Color(void)
  {
    long Value;
    OLECHECK(this->get_Color((long*)&Value));
    return Value;
  }

  long __fastcall get_BackColor(void)
  {
    long Value;
    OLECHECK(this->get_BackColor((long*)&Value));
    return Value;
  }

  long __fastcall Execute(BSTR param/*[in]*/)
  {
    long result;
    OLECHECK(this->Execute(param, (long*)&result));
    return result;
  }

  BSTR __fastcall Extract(BSTR param/*[in]*/)
  {
    BSTR result = 0;
    OLECHECK(this->Extract(param, (BSTR*)&result));
    return result;
  }

  long __fastcall moveNext(void)
  {
    long Value;
    OLECHECK(this->moveNext((long*)&Value));
    return Value;
  }

  long __fastcall atEnd(void)
  {
    long Value;
    OLECHECK(this->atEnd((long*)&Value));
    return Value;
  }

  Ppxscr_tlb::ITab* __fastcall get_Current(void)
  {
    Ppxscr_tlb::ITab* Value;
    OLECHECK(this->get_Current((Ppxscr_tlb::ITab**)&Value));
    return Value;
  }

  long __fastcall IndexFrom(BSTR ppcid/*[in]*/)
  {
    long moved;
    OLECHECK(this->IndexFrom(ppcid, (long*)&moved));
    return moved;
  }


  __property   LPUNKNOWN       _NewEnum = {read = get__NewEnum};
  __property   long            Count = {read = get_Count};
  __property   long            length = {read = get_length};
  __property   long            Lock = {read = get_Lock, write = set_Lock};
  __property   BSTR            idname = {read = get_idname};
  __property   long            index = {read = get_index, write = set_index};
  __property   BSTR            Name = {read = get_Name};
  __property   long            Type = {read = get_Type, write = set_Type};
  __property   long            Pane = {read = get_Pane, write = set_Pane};
  __property   long            TotalCount = {read = get_TotalCount};
  __property   long            TotalPPcCount = {read = get_TotalPPcCount};
  __property   long            Color = {read = get_Color, write = set_Color};
  __property   long            BackColor = {read = get_BackColor, write = set_BackColor};
  __property   Ppxscr_tlb::ITab* Current = {read = get_Current};

#endif //   __TLB_NO_INTERFACE_WRAPPERS

};

// *********************************************************************//
// Interface: IPPxEnum
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {4EA875C7-268F-4439-96EE-EAFA90173788}
// *********************************************************************//
interface IPPxEnum  : public IDispatch
{
public:
  virtual HRESULT STDMETHODCALLTYPE Item(long index/*[in,opt]*/, VARIANT* Value/*[out,retval]*/) = 0; // [0]
  virtual HRESULT STDMETHODCALLTYPE moveFirst(void) = 0; // [1]
  virtual HRESULT STDMETHODCALLTYPE moveNext(long* Value/*[out,retval]*/) = 0; // [2]
  virtual HRESULT STDMETHODCALLTYPE atEnd(long* Value/*[out,retval]*/) = 0; // [3]
  virtual HRESULT STDMETHODCALLTYPE Reset(void) = 0; // [4]
  virtual HRESULT STDMETHODCALLTYPE get_index(long* Value/*[out,retval]*/) = 0; // [5]
  virtual HRESULT STDMETHODCALLTYPE set_index(long Value/*[in]*/) = 0; // [5]

#if !defined(__TLB_NO_INTERFACE_WRAPPERS)

  VARIANT __fastcall Item(long index/*[in,opt]*/)
  {
    VARIANT Value;
    OLECHECK(this->Item(index, (VARIANT*)&Value));
    return Value;
  }

  long __fastcall moveNext(void)
  {
    long Value;
    OLECHECK(this->moveNext((long*)&Value));
    return Value;
  }

  long __fastcall atEnd(void)
  {
    long Value;
    OLECHECK(this->atEnd((long*)&Value));
    return Value;
  }

  long __fastcall get_index(void)
  {
    long Value;
    OLECHECK(this->get_index((long*)&Value));
    return Value;
  }


  __property   long            index = {read = get_index, write = set_index};

#endif //   __TLB_NO_INTERFACE_WRAPPERS

};

#if !defined(__TLB_NO_INTERFACE_WRAPPERS)
// *********************************************************************//
// DispIntf:  IPPxEvents
// Flags:     (4096) Dispatchable
// GUID:      {A540CECD-88F0-4F99-A1FF-5F20BA36DF9F}
// *********************************************************************//
template <class T>
class IPPxEventsDispT : public TAutoDriver<IPPxEvents>
{
public:
  IPPxEventsDispT(){}

  void Attach(LPUNKNOWN punk)
  { m_Dispatch = static_cast<T*>(punk); }


};
typedef IPPxEventsDispT<IPPxEvents> IPPxEventsDisp;

// *********************************************************************//
// SmartIntf: TCOMIPPx
// Interface: IPPx
// *********************************************************************//
template <class T /* IPPx */ >
class TCOMIPPxT : public TComInterface<IPPx>, public TComInterfaceBase<IUnknown>
{
public:
  TCOMIPPxT() {}
  TCOMIPPxT(IPPx *intf, bool addRef = false) : TComInterface<IPPx>(intf, addRef) {}
  TCOMIPPxT(const TCOMIPPxT& src) : TComInterface<IPPx>(src) {}
  TCOMIPPxT& operator=(const TCOMIPPxT& src) { Bind(src, true); return *this;}

  HRESULT         __fastcall Execute(BSTR param/*[in]*/, long* result/*[out,retval]*/);
  long            __fastcall Execute(BSTR param/*[in]*/);
  HRESULT         __fastcall DisconnectObject(LPDISPATCH pObject/*[in]*/);
  HRESULT         __fastcall ConnectObject(LPDISPATCH pObject/*[in]*/, BSTR bstrPrefix/*[in]*/);
  HRESULT         __fastcall CreateObject(BSTR bstrProgId/*[in]*/, BSTR bstrPrefix/*[in,def,opt]*/, 
                                          LPDISPATCH* ppObject/*[out,retval]*/);
  LPDISPATCH      __fastcall CreateObject(BSTR bstrProgId/*[in]*/, BSTR bstrPrefix/*[in,def,opt]*/);
  HRESULT         __fastcall Extract(BSTR param/*[in]*/, BSTR* result/*[out,retval]*/);
  BSTR            __fastcall Extract(BSTR param/*[in]*/);
  HRESULT         __fastcall Sleep(long nMilliseconds/*[in,opt]*/);
  HRESULT         __fastcall GetObject(BSTR bstrPathName/*[in]*/, BSTR bstrProgId/*[in,def,opt]*/, 
                                       BSTR bstrPrefix/*[in,def,opt]*/, 
                                       LPDISPATCH* ppObject/*[out,retval]*/);
  LPDISPATCH      __fastcall GetObject(BSTR bstrPathName/*[in]*/, BSTR bstrProgId/*[in,def,opt]*/, 
                                       BSTR bstrPrefix/*[in,def,opt]*/);
  HRESULT         __fastcall Echo(LPSAFEARRAY parr/*[in]*/);
  HRESULT         __fastcall get_EntryName(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_EntryName(void);
  HRESULT         __fastcall get_ScriptFullName(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_ScriptFullName(void);
  HRESULT         __fastcall get_ScriptName(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_ScriptName(void);
  HRESULT         __fastcall get_EntryIndex(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryIndex(void);
  HRESULT         __fastcall get_EntryDisplayTop(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryDisplayTop(void);
  HRESULT         __fastcall get_EntryDisplayX(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryDisplayX(void);
  HRESULT         __fastcall get_EntryDisplayY(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryDisplayY(void);
  HRESULT         __fastcall get_WindowDirection(long* Value/*[out,retval]*/);
  long            __fastcall get_WindowDirection(void);
  HRESULT         __fastcall get_EntryMark(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryMark(void);
  HRESULT         __fastcall set_EntryIndex(long Value/*[in]*/);
  HRESULT         __fastcall set_EntryMark(long Value/*[in]*/);
  HRESULT         __fastcall get_EntryComment(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_EntryComment(void);
  HRESULT         __fastcall set_EntryComment(BSTR Value/*[in]*/);
  HRESULT         __fastcall get_EntryAttributes(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryAttributes(void);
  HRESULT         __fastcall get_EntrySize(double* Value/*[out,retval]*/);
  double          __fastcall get_EntrySize(void);
  HRESULT         __fastcall EntryFirstMark(long* result/*[out,retval]*/);
  long            __fastcall EntryFirstMark(void);
  HRESULT         __fastcall EntryNextMark(long* result/*[out,retval]*/);
  long            __fastcall EntryNextMark(void);
  HRESULT         __fastcall SetPopLineMessage(BSTR message/*[in]*/);
  HRESULT         __fastcall get_PPxVersion(long* Value/*[out,retval]*/);
  long            __fastcall get_PPxVersion(void);
  HRESULT         __fastcall get_CodeType(long* Value/*[out,retval]*/);
  long            __fastcall get_CodeType(void);
  HRESULT         __fastcall get_EntryAllCount(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryAllCount(void);
  HRESULT         __fastcall get_EntryDisplayCount(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryDisplayCount(void);
  HRESULT         __fastcall get_EntryDisplayFiles(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryDisplayFiles(void);
  HRESULT         __fastcall get_EntryDisplayDirectories(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryDisplayDirectories(void);
  HRESULT         __fastcall get_DirectoryType(long* Value/*[out,retval]*/);
  long            __fastcall get_DirectoryType(void);
  HRESULT         __fastcall get_SyncView(long* Value/*[out,retval]*/);
  long            __fastcall get_SyncView(void);
  HRESULT         __fastcall set_SyncView(long Value/*[in]*/);
  HRESULT         __fastcall get_ModuleVersion(long* Value/*[out,retval]*/);
  long            __fastcall get_ModuleVersion(void);
  HRESULT         __fastcall get_EntryState(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryState(void);
  HRESULT         __fastcall set_EntryState(long Value/*[in]*/);
  HRESULT         __fastcall get_EntryExtColor(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryExtColor(void);
  HRESULT         __fastcall set_EntryExtColor(long Value/*[in]*/);
  HRESULT         __fastcall get_result(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_result(void);
  HRESULT         __fastcall set_result(BSTR Value/*[in]*/);
  HRESULT         __fastcall get_Arguments(Ppxscr_tlb::IArguments** Value/*[out,retval]*/);
  HRESULT         __fastcall get_Arguments(Ppxscr_tlb::IArgumentsPtr* Value/*[out,retval]*/);
  Ppxscr_tlb::IArgumentsPtr __fastcall get_Arguments(void);
  HRESULT         __fastcall Quit(long ExitCode/*[in,opt]*/);
  HRESULT         __fastcall get_EntryMarkCount(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryMarkCount(void);
  HRESULT         __fastcall get_Entry(Ppxscr_tlb::IEntry** Value/*[out,retval]*/);
  HRESULT         __fastcall get_Entry(Ppxscr_tlb::IEntryPtr* Value/*[out,retval]*/);
  Ppxscr_tlb::IEntryPtr __fastcall get_Entry(void);
  HRESULT         __fastcall get_SlowMode(long* Value/*[out,retval]*/);
  long            __fastcall get_SlowMode(void);
  HRESULT         __fastcall set_SlowMode(long Value/*[in]*/);
  HRESULT         __fastcall GetFileInformation(BSTR FileName/*[in]*/, long Mode/*[in,opt]*/, 
                                                BSTR* Text/*[out,retval]*/);
  BSTR            __fastcall GetFileInformation(BSTR FileName/*[in]*/, long Mode/*[in,opt]*/);
  HRESULT         __fastcall get_DriveVolumeLabel(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_DriveVolumeLabel(void);
  HRESULT         __fastcall get_EntryMarkSize(double* Value/*[out,retval]*/);
  double          __fastcall get_EntryMarkSize(void);
  HRESULT         __fastcall get_DriveTotalSize(double* Value/*[out,retval]*/);
  double          __fastcall get_DriveTotalSize(void);
  HRESULT         __fastcall get_DriveFreeSize(double* Value/*[out,retval]*/);
  double          __fastcall get_DriveFreeSize(void);
  HRESULT         __fastcall EntryInsert(long index/*[in]*/, BSTR EntryName/*[in]*/);
  HRESULT         __fastcall get_Clipboard(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_Clipboard(void);
  HRESULT         __fastcall set_Clipboard(BSTR Value/*[in]*/);
  HRESULT         __fastcall get_StayMode(long* Value/*[out,retval]*/);
  long            __fastcall get_StayMode(void);
  HRESULT         __fastcall set_StayMode(long Value/*[in]*/);
  HRESULT         __fastcall get_EntryHighlight(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryHighlight(void);
  HRESULT         __fastcall set_EntryHighlight(long Value/*[in]*/);
  HRESULT         __fastcall get_Pane(Ppxscr_tlb::IPane** Value/*[out,retval]*/);
  HRESULT         __fastcall get_Pane(Ppxscr_tlb::IPanePtr* Value/*[out,retval]*/);
  Ppxscr_tlb::IPanePtr __fastcall get_Pane(void);
  HRESULT         __fastcall EntryPrevMark(long* result/*[out,retval]*/);
  long            __fastcall EntryPrevMark(void);
  HRESULT         __fastcall EntryLastMark(long* result/*[out,retval]*/);
  long            __fastcall EntryLastMark(void);
  HRESULT         __fastcall GetComboItemCount(long id/*[in]*/, long* result/*[out]*/);
  HRESULT         __fastcall get_ComboIDName(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_ComboIDName(void);
  HRESULT         __fastcall get_PointType(long* Value/*[out,retval]*/);
  long            __fastcall get_PointType(void);
  HRESULT         __fastcall get_PointIndex(long* Value/*[out,retval]*/);
  long            __fastcall get_PointIndex(void);
  HRESULT         __fastcall Cursor(long x/*[in]*/, long y/*[in,def,opt]*/, 
                                    long* result/*[out,retval]*/);
  long            __fastcall Cursor(long x/*[in]*/, long y/*[in,def,opt]*/);
  HRESULT         __fastcall get_ScriptEngineName(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_ScriptEngineName(void);
  HRESULT         __fastcall getValue(BSTR key/*[in]*/, BSTR* result/*[out,retval]*/);
  BSTR            __fastcall getValue(BSTR key/*[in]*/);
  HRESULT         __fastcall setValue(BSTR key/*[in]*/, BSTR Value/*[in]*/);
  HRESULT         __fastcall get_ScriptEngineVersion(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_ScriptEngineVersion(void);
  HRESULT         __fastcall lineMessage(BSTR Text/*[in]*/);
  HRESULT         __fastcall get_WindowIDName(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_WindowIDName(void);
  HRESULT         __fastcall set_WindowIDName(BSTR Value/*[in]*/);
  HRESULT         __fastcall Argument(long itemindex/*[in,def,opt]*/, BSTR* Arg/*[out,retval]*/);
  BSTR            __fastcall Argument(long itemindex/*[in,def,opt]*/);
  HRESULT         __fastcall report(BSTR Text/*[in]*/);
  HRESULT         __fastcall log(BSTR Text/*[in]*/);
  HRESULT         __fastcall getProcessValue(BSTR key/*[in]*/, BSTR* result/*[out,retval]*/);
  BSTR            __fastcall getProcessValue(BSTR key/*[in]*/);
  HRESULT         __fastcall setProcessValue(BSTR key/*[in]*/, BSTR Value/*[in]*/);
  HRESULT         __fastcall getIValue(BSTR key/*[in]*/, BSTR* result/*[out,retval]*/);
  BSTR            __fastcall getIValue(BSTR key/*[in]*/);
  HRESULT         __fastcall setIValue(BSTR key/*[in]*/, BSTR Value/*[in]*/);
  HRESULT         __fastcall Enumerator(LPDISPATCH object/*[in]*/, LPDISPATCH* Value/*[out,retval]*/);
  LPDISPATCH      __fastcall Enumerator(LPDISPATCH object/*[in]*/);
  HRESULT         __fastcall Include(BSTR FileName/*[in]*/);
  HRESULT         __fastcall get_ReentryCount(long* Value/*[out,retval]*/);
  long            __fastcall get_ReentryCount(void);
  HRESULT         __fastcall option(BSTR name/*[in]*/, VARIANT param/*[in,opt]*/, 
                                    VARIANT* Value/*[out,retval]*/);
  VARIANT         __fastcall option(BSTR name/*[in]*/, VARIANT param/*[in,opt]*/= TNoParam());

  __property   BSTR            EntryName = {read = get_EntryName};
  __property   BSTR            ScriptFullName = {read = get_ScriptFullName};
  __property   BSTR            ScriptName = {read = get_ScriptName};
  __property   long            EntryIndex = {read = get_EntryIndex, write = set_EntryIndex};
  __property   long            EntryDisplayTop = {read = get_EntryDisplayTop};
  __property   long            EntryDisplayX = {read = get_EntryDisplayX};
  __property   long            EntryDisplayY = {read = get_EntryDisplayY};
  __property   long            WindowDirection = {read = get_WindowDirection};
  __property   long            EntryMark = {read = get_EntryMark, write = set_EntryMark};
  __property   BSTR            EntryComment = {read = get_EntryComment};
  __property   long            EntryAttributes = {read = get_EntryAttributes};
  __property   double          EntrySize = {read = get_EntrySize};
  __property   long            PPxVersion = {read = get_PPxVersion};
  __property   long            CodeType = {read = get_CodeType};
  __property   long            EntryAllCount = {read = get_EntryAllCount};
  __property   long            EntryDisplayCount = {read = get_EntryDisplayCount};
  __property   long            EntryDisplayFiles = {read = get_EntryDisplayFiles};
  __property   long            EntryDisplayDirectories = {read = get_EntryDisplayDirectories};
  __property   long            DirectoryType = {read = get_DirectoryType};
  __property   long            SyncView = {read = get_SyncView, write = set_SyncView};
  __property   long            ModuleVersion = {read = get_ModuleVersion};
  __property   long            EntryState = {read = get_EntryState, write = set_EntryState};
  __property   long            EntryExtColor = {read = get_EntryExtColor, write = set_EntryExtColor};
  __property   BSTR            result = {read = get_result};
  __property   Ppxscr_tlb::IArgumentsPtr Arguments = {read = get_Arguments};
  __property   long            EntryMarkCount = {read = get_EntryMarkCount};
  __property   Ppxscr_tlb::IEntryPtr Entry = {read = get_Entry};
  __property   long            SlowMode = {read = get_SlowMode, write = set_SlowMode};
  __property   BSTR            DriveVolumeLabel = {read = get_DriveVolumeLabel};
  __property   double          EntryMarkSize = {read = get_EntryMarkSize};
  __property   double          DriveTotalSize = {read = get_DriveTotalSize};
  __property   double          DriveFreeSize = {read = get_DriveFreeSize};
  __property   BSTR            Clipboard = {read = get_Clipboard};
  __property   long            StayMode = {read = get_StayMode, write = set_StayMode};
  __property   long            EntryHighlight = {read = get_EntryHighlight, write = set_EntryHighlight};
  __property   Ppxscr_tlb::IPanePtr Pane = {read = get_Pane};
  __property   BSTR            ComboIDName = {read = get_ComboIDName};
  __property   long            PointType = {read = get_PointType};
  __property   long            PointIndex = {read = get_PointIndex};
  __property   BSTR            ScriptEngineName = {read = get_ScriptEngineName};
  __property   BSTR            ScriptEngineVersion = {read = get_ScriptEngineVersion};
  __property   BSTR            WindowIDName = {read = get_WindowIDName};
  __property   long            ReentryCount = {read = get_ReentryCount};
};
typedef TCOMIPPxT<IPPx> TCOMIPPx;

// *********************************************************************//
// DispIntf:  IPPx
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {6114B9D8-86E7-4D41-95DD-DB7262512BA6}
// *********************************************************************//
template<class T>
class IPPxDispT : public TAutoDriver<IPPx>
{
public:
  IPPxDispT(){}

  IPPxDispT(IPPx *pintf)
  {
    TAutoDriver<IPPx>::Bind(pintf, false);
  }

  IPPxDispT(IPPxPtr pintf)
  {
    TAutoDriver<IPPx>::Bind(pintf, true);
  }

  IPPxDispT& operator=(IPPx *pintf)
  {
    TAutoDriver<IPPx>::Bind(pintf, false);
    return *this;
  }

  IPPxDispT& operator=(IPPxPtr pintf)
  {
    TAutoDriver<IPPx>::Bind(pintf, true);
    return *this;
  }

  HRESULT BindDefault()
  {
    return OLECHECK(Bind(CLSID_PPxObject));
  }

  HRESULT BindRunning()
  {
    return BindToActive(CLSID_PPxObject);
  }

  HRESULT         __fastcall Execute(BSTR param/*[in]*/, long* result/*[out,retval]*/);
  long            __fastcall Execute(BSTR param/*[in]*/);
  HRESULT         __fastcall DisconnectObject(LPDISPATCH pObject/*[in]*/);
  HRESULT         __fastcall ConnectObject(LPDISPATCH pObject/*[in]*/, BSTR bstrPrefix/*[in]*/);
  HRESULT         __fastcall CreateObject(BSTR bstrProgId/*[in]*/, BSTR bstrPrefix/*[in,def,opt]*/, 
                                          LPDISPATCH* ppObject/*[out,retval]*/);
  LPDISPATCH      __fastcall CreateObject(BSTR bstrProgId/*[in]*/, BSTR bstrPrefix/*[in,def,opt]*/);
  HRESULT         __fastcall Extract(BSTR param/*[in]*/, BSTR* result/*[out,retval]*/);
  BSTR            __fastcall Extract(BSTR param/*[in]*/);
  HRESULT         __fastcall Sleep(long nMilliseconds/*[in,opt]*/);
  HRESULT         __fastcall GetObject(BSTR bstrPathName/*[in]*/, BSTR bstrProgId/*[in,def,opt]*/, 
                                       BSTR bstrPrefix/*[in,def,opt]*/, 
                                       LPDISPATCH* ppObject/*[out,retval]*/);
  LPDISPATCH      __fastcall GetObject(BSTR bstrPathName/*[in]*/, BSTR bstrProgId/*[in,def,opt]*/, 
                                       BSTR bstrPrefix/*[in,def,opt]*/);
  HRESULT         __fastcall Echo(LPSAFEARRAY parr/*[in]*/);
  HRESULT         __fastcall get_EntryName(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_EntryName(void);
  HRESULT         __fastcall get_ScriptFullName(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_ScriptFullName(void);
  HRESULT         __fastcall get_ScriptName(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_ScriptName(void);
  HRESULT         __fastcall get_EntryIndex(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryIndex(void);
  HRESULT         __fastcall get_EntryDisplayTop(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryDisplayTop(void);
  HRESULT         __fastcall get_EntryDisplayX(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryDisplayX(void);
  HRESULT         __fastcall get_EntryDisplayY(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryDisplayY(void);
  HRESULT         __fastcall get_WindowDirection(long* Value/*[out,retval]*/);
  long            __fastcall get_WindowDirection(void);
  HRESULT         __fastcall get_EntryMark(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryMark(void);
  HRESULT         __fastcall set_EntryIndex(long Value/*[in]*/);
  HRESULT         __fastcall set_EntryMark(long Value/*[in]*/);
  HRESULT         __fastcall get_EntryComment(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_EntryComment(void);
  HRESULT         __fastcall set_EntryComment(BSTR Value/*[in]*/);
  HRESULT         __fastcall get_EntryAttributes(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryAttributes(void);
  HRESULT         __fastcall get_EntrySize(double* Value/*[out,retval]*/);
  double          __fastcall get_EntrySize(void);
  HRESULT         __fastcall EntryFirstMark(long* result/*[out,retval]*/);
  long            __fastcall EntryFirstMark(void);
  HRESULT         __fastcall EntryNextMark(long* result/*[out,retval]*/);
  long            __fastcall EntryNextMark(void);
  HRESULT         __fastcall SetPopLineMessage(BSTR message/*[in]*/);
  HRESULT         __fastcall get_PPxVersion(long* Value/*[out,retval]*/);
  long            __fastcall get_PPxVersion(void);
  HRESULT         __fastcall get_CodeType(long* Value/*[out,retval]*/);
  long            __fastcall get_CodeType(void);
  HRESULT         __fastcall get_EntryAllCount(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryAllCount(void);
  HRESULT         __fastcall get_EntryDisplayCount(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryDisplayCount(void);
  HRESULT         __fastcall get_EntryDisplayFiles(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryDisplayFiles(void);
  HRESULT         __fastcall get_EntryDisplayDirectories(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryDisplayDirectories(void);
  HRESULT         __fastcall get_DirectoryType(long* Value/*[out,retval]*/);
  long            __fastcall get_DirectoryType(void);
  HRESULT         __fastcall get_SyncView(long* Value/*[out,retval]*/);
  long            __fastcall get_SyncView(void);
  HRESULT         __fastcall set_SyncView(long Value/*[in]*/);
  HRESULT         __fastcall get_ModuleVersion(long* Value/*[out,retval]*/);
  long            __fastcall get_ModuleVersion(void);
  HRESULT         __fastcall get_EntryState(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryState(void);
  HRESULT         __fastcall set_EntryState(long Value/*[in]*/);
  HRESULT         __fastcall get_EntryExtColor(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryExtColor(void);
  HRESULT         __fastcall set_EntryExtColor(long Value/*[in]*/);
  HRESULT         __fastcall get_result(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_result(void);
  HRESULT         __fastcall set_result(BSTR Value/*[in]*/);
  HRESULT         __fastcall get_Arguments(Ppxscr_tlb::IArguments** Value/*[out,retval]*/);
  Ppxscr_tlb::IArguments* __fastcall get_Arguments(void);
  HRESULT         __fastcall Quit(long ExitCode/*[in,opt]*/);
  HRESULT         __fastcall get_EntryMarkCount(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryMarkCount(void);
  HRESULT         __fastcall get_Entry(Ppxscr_tlb::IEntry** Value/*[out,retval]*/);
  Ppxscr_tlb::IEntry* __fastcall get_Entry(void);
  HRESULT         __fastcall get_SlowMode(long* Value/*[out,retval]*/);
  long            __fastcall get_SlowMode(void);
  HRESULT         __fastcall set_SlowMode(long Value/*[in]*/);
  HRESULT         __fastcall GetFileInformation(BSTR FileName/*[in]*/, long Mode/*[in,opt]*/, 
                                                BSTR* Text/*[out,retval]*/);
  BSTR            __fastcall GetFileInformation(BSTR FileName/*[in]*/, long Mode/*[in,opt]*/);
  HRESULT         __fastcall get_DriveVolumeLabel(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_DriveVolumeLabel(void);
  HRESULT         __fastcall get_EntryMarkSize(double* Value/*[out,retval]*/);
  double          __fastcall get_EntryMarkSize(void);
  HRESULT         __fastcall get_DriveTotalSize(double* Value/*[out,retval]*/);
  double          __fastcall get_DriveTotalSize(void);
  HRESULT         __fastcall get_DriveFreeSize(double* Value/*[out,retval]*/);
  double          __fastcall get_DriveFreeSize(void);
  HRESULT         __fastcall EntryInsert(long index/*[in]*/, BSTR EntryName/*[in]*/);
  HRESULT         __fastcall get_Clipboard(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_Clipboard(void);
  HRESULT         __fastcall set_Clipboard(BSTR Value/*[in]*/);
  HRESULT         __fastcall get_StayMode(long* Value/*[out,retval]*/);
  long            __fastcall get_StayMode(void);
  HRESULT         __fastcall set_StayMode(long Value/*[in]*/);
  HRESULT         __fastcall get_EntryHighlight(long* Value/*[out,retval]*/);
  long            __fastcall get_EntryHighlight(void);
  HRESULT         __fastcall set_EntryHighlight(long Value/*[in]*/);
  HRESULT         __fastcall get_Pane(Ppxscr_tlb::IPane** Value/*[out,retval]*/);
  Ppxscr_tlb::IPane* __fastcall get_Pane(void);
  HRESULT         __fastcall EntryPrevMark(long* result/*[out,retval]*/);
  long            __fastcall EntryPrevMark(void);
  HRESULT         __fastcall EntryLastMark(long* result/*[out,retval]*/);
  long            __fastcall EntryLastMark(void);
  HRESULT         __fastcall GetComboItemCount(long id/*[in]*/, long* result/*[out]*/);
  HRESULT         __fastcall get_ComboIDName(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_ComboIDName(void);
  HRESULT         __fastcall get_PointType(long* Value/*[out,retval]*/);
  long            __fastcall get_PointType(void);
  HRESULT         __fastcall get_PointIndex(long* Value/*[out,retval]*/);
  long            __fastcall get_PointIndex(void);
  HRESULT         __fastcall Cursor(long x/*[in]*/, long y/*[in,def,opt]*/, 
                                    long* result/*[out,retval]*/);
  long            __fastcall Cursor(long x/*[in]*/, long y/*[in,def,opt]*/);
  HRESULT         __fastcall get_ScriptEngineName(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_ScriptEngineName(void);
  HRESULT         __fastcall getValue(BSTR key/*[in]*/, BSTR* result/*[out,retval]*/);
  BSTR            __fastcall getValue(BSTR key/*[in]*/);
  HRESULT         __fastcall setValue(BSTR key/*[in]*/, BSTR Value/*[in]*/);
  HRESULT         __fastcall get_ScriptEngineVersion(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_ScriptEngineVersion(void);
  HRESULT         __fastcall lineMessage(BSTR Text/*[in]*/);
  HRESULT         __fastcall get_WindowIDName(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_WindowIDName(void);
  HRESULT         __fastcall set_WindowIDName(BSTR Value/*[in]*/);
  HRESULT         __fastcall Argument(long itemindex/*[in,def,opt]*/, BSTR* Arg/*[out,retval]*/);
  BSTR            __fastcall Argument(long itemindex/*[in,def,opt]*/);
  HRESULT         __fastcall report(BSTR Text/*[in]*/);
  HRESULT         __fastcall log(BSTR Text/*[in]*/);
  HRESULT         __fastcall getProcessValue(BSTR key/*[in]*/, BSTR* result/*[out,retval]*/);
  BSTR            __fastcall getProcessValue(BSTR key/*[in]*/);
  HRESULT         __fastcall setProcessValue(BSTR key/*[in]*/, BSTR Value/*[in]*/);
  HRESULT         __fastcall getIValue(BSTR key/*[in]*/, BSTR* result/*[out,retval]*/);
  BSTR            __fastcall getIValue(BSTR key/*[in]*/);
  HRESULT         __fastcall setIValue(BSTR key/*[in]*/, BSTR Value/*[in]*/);
  HRESULT         __fastcall Enumerator(LPDISPATCH object/*[in]*/, LPDISPATCH* Value/*[out,retval]*/);
  LPDISPATCH      __fastcall Enumerator(LPDISPATCH object/*[in]*/);
  HRESULT         __fastcall Include(BSTR FileName/*[in]*/);
  HRESULT         __fastcall get_ReentryCount(long* Value/*[out,retval]*/);
  long            __fastcall get_ReentryCount(void);
  HRESULT         __fastcall option(BSTR name/*[in]*/, VARIANT param/*[in,opt]*/, 
                                    VARIANT* Value/*[out,retval]*/);
  VARIANT         __fastcall option(BSTR name/*[in]*/, VARIANT param/*[in,opt]*/= TNoParam());

  __property   BSTR            EntryName = {read = get_EntryName};
  __property   BSTR            ScriptFullName = {read = get_ScriptFullName};
  __property   BSTR            ScriptName = {read = get_ScriptName};
  __property   long            EntryIndex = {read = get_EntryIndex, write = set_EntryIndex};
  __property   long            EntryDisplayTop = {read = get_EntryDisplayTop};
  __property   long            EntryDisplayX = {read = get_EntryDisplayX};
  __property   long            EntryDisplayY = {read = get_EntryDisplayY};
  __property   long            WindowDirection = {read = get_WindowDirection};
  __property   long            EntryMark = {read = get_EntryMark, write = set_EntryMark};
  __property   BSTR            EntryComment = {read = get_EntryComment};
  __property   long            EntryAttributes = {read = get_EntryAttributes};
  __property   double          EntrySize = {read = get_EntrySize};
  __property   long            PPxVersion = {read = get_PPxVersion};
  __property   long            CodeType = {read = get_CodeType};
  __property   long            EntryAllCount = {read = get_EntryAllCount};
  __property   long            EntryDisplayCount = {read = get_EntryDisplayCount};
  __property   long            EntryDisplayFiles = {read = get_EntryDisplayFiles};
  __property   long            EntryDisplayDirectories = {read = get_EntryDisplayDirectories};
  __property   long            DirectoryType = {read = get_DirectoryType};
  __property   long            SyncView = {read = get_SyncView, write = set_SyncView};
  __property   long            ModuleVersion = {read = get_ModuleVersion};
  __property   long            EntryState = {read = get_EntryState, write = set_EntryState};
  __property   long            EntryExtColor = {read = get_EntryExtColor, write = set_EntryExtColor};
  __property   BSTR            result = {read = get_result};
  __property   Ppxscr_tlb::IArguments* Arguments = {read = get_Arguments};
  __property   long            EntryMarkCount = {read = get_EntryMarkCount};
  __property   Ppxscr_tlb::IEntry* Entry = {read = get_Entry};
  __property   long            SlowMode = {read = get_SlowMode, write = set_SlowMode};
  __property   BSTR            DriveVolumeLabel = {read = get_DriveVolumeLabel};
  __property   double          EntryMarkSize = {read = get_EntryMarkSize};
  __property   double          DriveTotalSize = {read = get_DriveTotalSize};
  __property   double          DriveFreeSize = {read = get_DriveFreeSize};
  __property   BSTR            Clipboard = {read = get_Clipboard};
  __property   long            StayMode = {read = get_StayMode, write = set_StayMode};
  __property   long            EntryHighlight = {read = get_EntryHighlight, write = set_EntryHighlight};
  __property   Ppxscr_tlb::IPane* Pane = {read = get_Pane};
  __property   BSTR            ComboIDName = {read = get_ComboIDName};
  __property   long            PointType = {read = get_PointType};
  __property   long            PointIndex = {read = get_PointIndex};
  __property   BSTR            ScriptEngineName = {read = get_ScriptEngineName};
  __property   BSTR            ScriptEngineVersion = {read = get_ScriptEngineVersion};
  __property   BSTR            WindowIDName = {read = get_WindowIDName};
  __property   long            ReentryCount = {read = get_ReentryCount};
};
typedef IPPxDispT<IPPx> IPPxDisp;

// *********************************************************************//
// SmartIntf: TCOMIArguments
// Interface: IArguments
// *********************************************************************//
template <class T /* IArguments */ >
class TCOMIArgumentsT : public TComInterface<IArguments>, public TComInterfaceBase<IUnknown>
{
public:
  TCOMIArgumentsT() {}
  TCOMIArgumentsT(IArguments *intf, bool addRef = false) : TComInterface<IArguments>(intf, addRef) {}
  TCOMIArgumentsT(const TCOMIArgumentsT& src) : TComInterface<IArguments>(src) {}
  TCOMIArgumentsT& operator=(const TCOMIArgumentsT& src) { Bind(src, true); return *this;}

  HRESULT         __fastcall Item(long index/*[in,opt]*/, BSTR* out_Value/*[out,retval]*/);
  BSTR            __fastcall Item(long index/*[in,opt]*/);
  HRESULT         __fastcall get__NewEnum(LPUNKNOWN* out_Enum/*[out,retval]*/);
  LPUNKNOWN       __fastcall get__NewEnum(void);
  HRESULT         __fastcall get_Count(long* Value/*[out,retval]*/);
  long            __fastcall get_Count(void);
  HRESULT         __fastcall get_length(long* Value/*[out,retval]*/);
  long            __fastcall get_length(void);
  HRESULT         __fastcall Reset(void);
  HRESULT         __fastcall moveNext(long* Value/*[out,retval]*/);
  long            __fastcall moveNext(void);
  HRESULT         __fastcall atEnd(long* Value/*[out,retval]*/);
  long            __fastcall atEnd(void);
  HRESULT         __fastcall get_Current(Ppxscr_tlb::IArguments** Value/*[out,retval]*/);
  HRESULT         __fastcall get_Current(Ppxscr_tlb::IArgumentsPtr* Value/*[out,retval]*/);
  Ppxscr_tlb::IArgumentsPtr __fastcall get_Current(void);
  HRESULT         __fastcall get_Value(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_Value(void);

  __property   LPUNKNOWN       _NewEnum = {read = get__NewEnum};
  __property   long            Count = {read = get_Count};
  __property   long            length = {read = get_length};
  __property   Ppxscr_tlb::IArgumentsPtr Current = {read = get_Current};
  __property   BSTR            Value = {read = get_Value};
};
typedef TCOMIArgumentsT<IArguments> TCOMIArguments;

// *********************************************************************//
// DispIntf:  IArguments
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {29BA7411-9168-4B39-B878-B6181C782884}
// *********************************************************************//
template<class T>
class IArgumentsDispT : public TAutoDriver<IArguments>
{
public:
  IArgumentsDispT(){}

  IArgumentsDispT(IArguments *pintf)
  {
    TAutoDriver<IArguments>::Bind(pintf, false);
  }

  IArgumentsDispT(IArgumentsPtr pintf)
  {
    TAutoDriver<IArguments>::Bind(pintf, true);
  }

  IArgumentsDispT& operator=(IArguments *pintf)
  {
    TAutoDriver<IArguments>::Bind(pintf, false);
    return *this;
  }

  IArgumentsDispT& operator=(IArgumentsPtr pintf)
  {
    TAutoDriver<IArguments>::Bind(pintf, true);
    return *this;
  }

  HRESULT BindDefault()
  {
    return OLECHECK(Bind(CLSID_IArguments_Class));
  }

  HRESULT BindRunning()
  {
    return BindToActive(CLSID_IArguments_Class);
  }

  HRESULT         __fastcall Item(long index/*[in,opt]*/, BSTR* out_Value/*[out,retval]*/);
  BSTR            __fastcall Item(long index/*[in,opt]*/);
  HRESULT         __fastcall get__NewEnum(LPUNKNOWN* out_Enum/*[out,retval]*/);
  LPUNKNOWN       __fastcall get__NewEnum(void);
  HRESULT         __fastcall get_Count(long* Value/*[out,retval]*/);
  long            __fastcall get_Count(void);
  HRESULT         __fastcall get_length(long* Value/*[out,retval]*/);
  long            __fastcall get_length(void);
  HRESULT         __fastcall Reset();
  HRESULT         __fastcall moveNext(long* Value/*[out,retval]*/);
  long            __fastcall moveNext(void);
  HRESULT         __fastcall atEnd(long* Value/*[out,retval]*/);
  long            __fastcall atEnd(void);
  HRESULT         __fastcall get_Current(Ppxscr_tlb::IArguments** Value/*[out,retval]*/);
  Ppxscr_tlb::IArguments* __fastcall get_Current(void);
  HRESULT         __fastcall get_Value(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_Value(void);

  __property   LPUNKNOWN       _NewEnum = {read = get__NewEnum};
  __property   long            Count = {read = get_Count};
  __property   long            length = {read = get_length};
  __property   Ppxscr_tlb::IArguments* Current = {read = get_Current};
  __property   BSTR            Value = {read = get_Value};
};
typedef IArgumentsDispT<IArguments> IArgumentsDisp;

// *********************************************************************//
// SmartIntf: TCOMIEntry
// Interface: IEntry
// *********************************************************************//
template <class T /* IEntry */ >
class TCOMIEntryT : public TComInterface<IEntry>, public TComInterfaceBase<IUnknown>
{
public:
  TCOMIEntryT() {}
  TCOMIEntryT(IEntry *intf, bool addRef = false) : TComInterface<IEntry>(intf, addRef) {}
  TCOMIEntryT(const TCOMIEntryT& src) : TComInterface<IEntry>(src) {}
  TCOMIEntryT& operator=(const TCOMIEntryT& src) { Bind(src, true); return *this;}

  HRESULT         __fastcall Item(long index/*[in,opt]*/, 
                                  Ppxscr_tlb::IEntry** out_Value/*[out,retval]*/);
  Ppxscr_tlb::IEntry* __fastcall Item(long index/*[in,opt]*/);
  HRESULT         __fastcall get__NewEnum(LPUNKNOWN* out_Enum/*[out,retval]*/);
  LPUNKNOWN       __fastcall get__NewEnum(void);
  HRESULT         __fastcall get_Count(long* Value/*[out,retval]*/);
  long            __fastcall get_Count(void);
  HRESULT         __fastcall get_Name(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_Name(void);
  HRESULT         __fastcall get_index(long* Value/*[out,retval]*/);
  long            __fastcall get_index(void);
  HRESULT         __fastcall set_index(long Value/*[in]*/);
  HRESULT         __fastcall get_Mark(long* Value/*[out,retval]*/);
  long            __fastcall get_Mark(void);
  HRESULT         __fastcall set_Mark(long Value/*[in]*/);
  HRESULT         __fastcall get_Comment(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_Comment(void);
  HRESULT         __fastcall set_Comment(BSTR Value/*[in]*/);
  HRESULT         __fastcall get_Attributes(long* Value/*[out,retval]*/);
  long            __fastcall get_Attributes(void);
  HRESULT         __fastcall get_Size(double* Value/*[out,retval]*/);
  double          __fastcall get_Size(void);
  HRESULT         __fastcall get_State(long* Value/*[out,retval]*/);
  long            __fastcall get_State(void);
  HRESULT         __fastcall set_State(long Value/*[in]*/);
  HRESULT         __fastcall get_ExtColor(long* Value/*[out,retval]*/);
  long            __fastcall get_ExtColor(void);
  HRESULT         __fastcall set_ExtColor(long Value/*[in]*/);
  HRESULT         __fastcall get_length(long* Value/*[out,retval]*/);
  long            __fastcall get_length(void);
  HRESULT         __fastcall get_DateCreated(DATE* Value/*[out,retval]*/);
  DATE            __fastcall get_DateCreated(void);
  HRESULT         __fastcall get_DateLastAccessed(DATE* Value/*[out,retval]*/);
  DATE            __fastcall get_DateLastAccessed(void);
  HRESULT         __fastcall get_DateLastModified(DATE* Value/*[out,retval]*/);
  DATE            __fastcall get_DateLastModified(void);
  HRESULT         __fastcall get_ShortName(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_ShortName(void);
  HRESULT         __fastcall get_Highlight(long* Value/*[out,retval]*/);
  long            __fastcall get_Highlight(void);
  HRESULT         __fastcall set_Highlight(long Value/*[in]*/);
  HRESULT         __fastcall NextMark(long* result/*[out,retval]*/);
  long            __fastcall NextMark(void);
  HRESULT         __fastcall PrevMark(long* result/*[out,retval]*/);
  long            __fastcall PrevMark(void);
  HRESULT         __fastcall Hide(void);
  HRESULT         __fastcall FirstMark(long* result/*[out,retval]*/);
  long            __fastcall FirstMark(void);
  HRESULT         __fastcall LastMark(long* result/*[out,retval]*/);
  long            __fastcall LastMark(void);
  HRESULT         __fastcall Information(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall Information(void);
  HRESULT         __fastcall GetComment(long id/*[in,opt]*/, BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall GetComment(long id/*[in,opt]*/);
  HRESULT         __fastcall SetComment(long id/*[in]*/, BSTR Value/*[in]*/);
  HRESULT         __fastcall Reset(void);
  HRESULT         __fastcall moveNext(long* Value/*[out,retval]*/);
  long            __fastcall moveNext(void);
  HRESULT         __fastcall get_AllMark(Ppxscr_tlb::IEntry** out_Value/*[out,retval]*/);
  HRESULT         __fastcall get_AllMark(Ppxscr_tlb::IEntryPtr* out_Value/*[out,retval]*/);
  Ppxscr_tlb::IEntryPtr __fastcall get_AllMark(void);
  HRESULT         __fastcall get_AllEntry(Ppxscr_tlb::IEntry** out_Value/*[out,retval]*/);
  HRESULT         __fastcall get_AllEntry(Ppxscr_tlb::IEntryPtr* out_Value/*[out,retval]*/);
  Ppxscr_tlb::IEntryPtr __fastcall get_AllEntry(void);
  HRESULT         __fastcall atEnd(long* Value/*[out,retval]*/);
  long            __fastcall atEnd(void);
  HRESULT         __fastcall get_Current(Ppxscr_tlb::IEntry** Value/*[out,retval]*/);
  HRESULT         __fastcall get_Current(Ppxscr_tlb::IEntryPtr* Value/*[out,retval]*/);
  Ppxscr_tlb::IEntryPtr __fastcall get_Current(void);
  HRESULT         __fastcall IndexFrom(BSTR Name/*[in]*/, long* moved/*[out,retval]*/);
  long            __fastcall IndexFrom(BSTR Name/*[in]*/);

  __property   LPUNKNOWN       _NewEnum = {read = get__NewEnum};
  __property   long            Count = {read = get_Count};
  __property   BSTR            Name = {read = get_Name};
  __property   long            index = {read = get_index, write = set_index};
  __property   long            Mark = {read = get_Mark, write = set_Mark};
  __property   BSTR            Comment = {read = get_Comment};
  __property   long            Attributes = {read = get_Attributes};
  __property   double          Size = {read = get_Size};
  __property   long            State = {read = get_State, write = set_State};
  __property   long            ExtColor = {read = get_ExtColor, write = set_ExtColor};
  __property   long            length = {read = get_length};
  __property   DATE            DateCreated = {read = get_DateCreated};
  __property   DATE            DateLastAccessed = {read = get_DateLastAccessed};
  __property   DATE            DateLastModified = {read = get_DateLastModified};
  __property   BSTR            ShortName = {read = get_ShortName};
  __property   long            Highlight = {read = get_Highlight, write = set_Highlight};
  __property   Ppxscr_tlb::IEntryPtr AllMark = {read = get_AllMark};
  __property   Ppxscr_tlb::IEntryPtr AllEntry = {read = get_AllEntry};
  __property   Ppxscr_tlb::IEntryPtr Current = {read = get_Current};
};
typedef TCOMIEntryT<IEntry> TCOMIEntry;

// *********************************************************************//
// DispIntf:  IEntry
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {E64F28F2-F656-4F61-8CA7-2F4F97AB25FF}
// *********************************************************************//
template<class T>
class IEntryDispT : public TAutoDriver<IEntry>
{
public:
  IEntryDispT(){}

  IEntryDispT(IEntry *pintf)
  {
    TAutoDriver<IEntry>::Bind(pintf, false);
  }

  IEntryDispT(IEntryPtr pintf)
  {
    TAutoDriver<IEntry>::Bind(pintf, true);
  }

  IEntryDispT& operator=(IEntry *pintf)
  {
    TAutoDriver<IEntry>::Bind(pintf, false);
    return *this;
  }

  IEntryDispT& operator=(IEntryPtr pintf)
  {
    TAutoDriver<IEntry>::Bind(pintf, true);
    return *this;
  }

  HRESULT BindDefault()
  {
    return OLECHECK(Bind(CLSID_IEntry_Class));
  }

  HRESULT BindRunning()
  {
    return BindToActive(CLSID_IEntry_Class);
  }

  HRESULT         __fastcall Item(long index/*[in,opt]*/, 
                                  Ppxscr_tlb::IEntry** out_Value/*[out,retval]*/);
  Ppxscr_tlb::IEntry* __fastcall Item(long index/*[in,opt]*/);
  HRESULT         __fastcall get__NewEnum(LPUNKNOWN* out_Enum/*[out,retval]*/);
  LPUNKNOWN       __fastcall get__NewEnum(void);
  HRESULT         __fastcall get_Count(long* Value/*[out,retval]*/);
  long            __fastcall get_Count(void);
  HRESULT         __fastcall get_Name(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_Name(void);
  HRESULT         __fastcall get_index(long* Value/*[out,retval]*/);
  long            __fastcall get_index(void);
  HRESULT         __fastcall set_index(long Value/*[in]*/);
  HRESULT         __fastcall get_Mark(long* Value/*[out,retval]*/);
  long            __fastcall get_Mark(void);
  HRESULT         __fastcall set_Mark(long Value/*[in]*/);
  HRESULT         __fastcall get_Comment(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_Comment(void);
  HRESULT         __fastcall set_Comment(BSTR Value/*[in]*/);
  HRESULT         __fastcall get_Attributes(long* Value/*[out,retval]*/);
  long            __fastcall get_Attributes(void);
  HRESULT         __fastcall get_Size(double* Value/*[out,retval]*/);
  double          __fastcall get_Size(void);
  HRESULT         __fastcall get_State(long* Value/*[out,retval]*/);
  long            __fastcall get_State(void);
  HRESULT         __fastcall set_State(long Value/*[in]*/);
  HRESULT         __fastcall get_ExtColor(long* Value/*[out,retval]*/);
  long            __fastcall get_ExtColor(void);
  HRESULT         __fastcall set_ExtColor(long Value/*[in]*/);
  HRESULT         __fastcall get_length(long* Value/*[out,retval]*/);
  long            __fastcall get_length(void);
  HRESULT         __fastcall get_DateCreated(DATE* Value/*[out,retval]*/);
  DATE            __fastcall get_DateCreated(void);
  HRESULT         __fastcall get_DateLastAccessed(DATE* Value/*[out,retval]*/);
  DATE            __fastcall get_DateLastAccessed(void);
  HRESULT         __fastcall get_DateLastModified(DATE* Value/*[out,retval]*/);
  DATE            __fastcall get_DateLastModified(void);
  HRESULT         __fastcall get_ShortName(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_ShortName(void);
  HRESULT         __fastcall get_Highlight(long* Value/*[out,retval]*/);
  long            __fastcall get_Highlight(void);
  HRESULT         __fastcall set_Highlight(long Value/*[in]*/);
  HRESULT         __fastcall NextMark(long* result/*[out,retval]*/);
  long            __fastcall NextMark(void);
  HRESULT         __fastcall PrevMark(long* result/*[out,retval]*/);
  long            __fastcall PrevMark(void);
  HRESULT         __fastcall Hide();
  HRESULT         __fastcall FirstMark(long* result/*[out,retval]*/);
  long            __fastcall FirstMark(void);
  HRESULT         __fastcall LastMark(long* result/*[out,retval]*/);
  long            __fastcall LastMark(void);
  HRESULT         __fastcall Information(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall Information(void);
  HRESULT         __fastcall GetComment(long id/*[in,opt]*/, BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall GetComment(long id/*[in,opt]*/);
  HRESULT         __fastcall SetComment(long id/*[in]*/, BSTR Value/*[in]*/);
  HRESULT         __fastcall Reset();
  HRESULT         __fastcall moveNext(long* Value/*[out,retval]*/);
  long            __fastcall moveNext(void);
  HRESULT         __fastcall get_AllMark(Ppxscr_tlb::IEntry** out_Value/*[out,retval]*/);
  Ppxscr_tlb::IEntry* __fastcall get_AllMark(void);
  HRESULT         __fastcall get_AllEntry(Ppxscr_tlb::IEntry** out_Value/*[out,retval]*/);
  Ppxscr_tlb::IEntry* __fastcall get_AllEntry(void);
  HRESULT         __fastcall atEnd(long* Value/*[out,retval]*/);
  long            __fastcall atEnd(void);
  HRESULT         __fastcall get_Current(Ppxscr_tlb::IEntry** Value/*[out,retval]*/);
  Ppxscr_tlb::IEntry* __fastcall get_Current(void);
  HRESULT         __fastcall IndexFrom(BSTR Name/*[in]*/, long* moved/*[out,retval]*/);
  long            __fastcall IndexFrom(BSTR Name/*[in]*/);

  __property   LPUNKNOWN       _NewEnum = {read = get__NewEnum};
  __property   long            Count = {read = get_Count};
  __property   BSTR            Name = {read = get_Name};
  __property   long            index = {read = get_index, write = set_index};
  __property   long            Mark = {read = get_Mark, write = set_Mark};
  __property   BSTR            Comment = {read = get_Comment};
  __property   long            Attributes = {read = get_Attributes};
  __property   double          Size = {read = get_Size};
  __property   long            State = {read = get_State, write = set_State};
  __property   long            ExtColor = {read = get_ExtColor, write = set_ExtColor};
  __property   long            length = {read = get_length};
  __property   DATE            DateCreated = {read = get_DateCreated};
  __property   DATE            DateLastAccessed = {read = get_DateLastAccessed};
  __property   DATE            DateLastModified = {read = get_DateLastModified};
  __property   BSTR            ShortName = {read = get_ShortName};
  __property   long            Highlight = {read = get_Highlight, write = set_Highlight};
  __property   Ppxscr_tlb::IEntry* AllMark = {read = get_AllMark};
  __property   Ppxscr_tlb::IEntry* AllEntry = {read = get_AllEntry};
  __property   Ppxscr_tlb::IEntry* Current = {read = get_Current};
};
typedef IEntryDispT<IEntry> IEntryDisp;

// *********************************************************************//
// SmartIntf: TCOMIPane
// Interface: IPane
// *********************************************************************//
template <class T /* IPane */ >
class TCOMIPaneT : public TComInterface<IPane>, public TComInterfaceBase<IUnknown>
{
public:
  TCOMIPaneT() {}
  TCOMIPaneT(IPane *intf, bool addRef = false) : TComInterface<IPane>(intf, addRef) {}
  TCOMIPaneT(const TCOMIPaneT& src) : TComInterface<IPane>(src) {}
  TCOMIPaneT& operator=(const TCOMIPaneT& src) { Bind(src, true); return *this;}

  HRESULT         __fastcall Item(long index/*[in,opt]*/, Ppxscr_tlb::IPane** Value/*[out,retval]*/);
  Ppxscr_tlb::IPane* __fastcall Item(long index/*[in,opt]*/);
  HRESULT         __fastcall get__NewEnum(LPUNKNOWN* out_Enum/*[out,retval]*/);
  LPUNKNOWN       __fastcall get__NewEnum(void);
  HRESULT         __fastcall get_Count(long* Value/*[out,retval]*/);
  long            __fastcall get_Count(void);
  HRESULT         __fastcall get_length(long* Value/*[out,retval]*/);
  long            __fastcall get_length(void);
  HRESULT         __fastcall get_index(long* Value/*[out,retval]*/);
  long            __fastcall get_index(void);
  HRESULT         __fastcall set_index(long Value/*[in]*/);
  HRESULT         __fastcall get_Name(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_Name(void);
  HRESULT         __fastcall set_Name(BSTR Value/*[in]*/);
  HRESULT         __fastcall get_Tab(Ppxscr_tlb::ITab** Value/*[out,retval]*/);
  HRESULT         __fastcall get_Tab(Ppxscr_tlb::ITabPtr* Value/*[out,retval]*/);
  Ppxscr_tlb::ITabPtr __fastcall get_Tab(void);
  HRESULT         __fastcall Reset(void);
  HRESULT         __fastcall moveNext(long* Value/*[out,retval]*/);
  long            __fastcall moveNext(void);
  HRESULT         __fastcall atEnd(long* Value/*[out,retval]*/);
  long            __fastcall atEnd(void);
  HRESULT         __fastcall get_Current(Ppxscr_tlb::IPane** Value/*[out,retval]*/);
  HRESULT         __fastcall get_Current(Ppxscr_tlb::IPanePtr* Value/*[out,retval]*/);
  Ppxscr_tlb::IPanePtr __fastcall get_Current(void);
  HRESULT         __fastcall IndexFrom(BSTR ppcid/*[in]*/, long* moved/*[out,retval]*/);
  long            __fastcall IndexFrom(BSTR ppcid/*[in]*/);

  __property   LPUNKNOWN       _NewEnum = {read = get__NewEnum};
  __property   long            Count = {read = get_Count};
  __property   long            length = {read = get_length};
  __property   long            index = {read = get_index, write = set_index};
  __property   BSTR            Name = {read = get_Name};
  __property   Ppxscr_tlb::ITabPtr Tab = {read = get_Tab};
  __property   Ppxscr_tlb::IPanePtr Current = {read = get_Current};
};
typedef TCOMIPaneT<IPane> TCOMIPane;

// *********************************************************************//
// DispIntf:  IPane
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {A682BC0E-0D72-4D56-8818-FE2E0E49AE85}
// *********************************************************************//
template<class T>
class IPaneDispT : public TAutoDriver<IPane>
{
public:
  IPaneDispT(){}

  IPaneDispT(IPane *pintf)
  {
    TAutoDriver<IPane>::Bind(pintf, false);
  }

  IPaneDispT(IPanePtr pintf)
  {
    TAutoDriver<IPane>::Bind(pintf, true);
  }

  IPaneDispT& operator=(IPane *pintf)
  {
    TAutoDriver<IPane>::Bind(pintf, false);
    return *this;
  }

  IPaneDispT& operator=(IPanePtr pintf)
  {
    TAutoDriver<IPane>::Bind(pintf, true);
    return *this;
  }

  HRESULT BindDefault()
  {
    return OLECHECK(Bind(CLSID_IPane_Class));
  }

  HRESULT BindRunning()
  {
    return BindToActive(CLSID_IPane_Class);
  }

  HRESULT         __fastcall Item(long index/*[in,opt]*/, Ppxscr_tlb::IPane** Value/*[out,retval]*/);
  Ppxscr_tlb::IPane* __fastcall Item(long index/*[in,opt]*/);
  HRESULT         __fastcall get__NewEnum(LPUNKNOWN* out_Enum/*[out,retval]*/);
  LPUNKNOWN       __fastcall get__NewEnum(void);
  HRESULT         __fastcall get_Count(long* Value/*[out,retval]*/);
  long            __fastcall get_Count(void);
  HRESULT         __fastcall get_length(long* Value/*[out,retval]*/);
  long            __fastcall get_length(void);
  HRESULT         __fastcall get_index(long* Value/*[out,retval]*/);
  long            __fastcall get_index(void);
  HRESULT         __fastcall set_index(long Value/*[in]*/);
  HRESULT         __fastcall get_Name(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_Name(void);
  HRESULT         __fastcall set_Name(BSTR Value/*[in]*/);
  HRESULT         __fastcall get_Tab(Ppxscr_tlb::ITab** Value/*[out,retval]*/);
  Ppxscr_tlb::ITab* __fastcall get_Tab(void);
  HRESULT         __fastcall Reset();
  HRESULT         __fastcall moveNext(long* Value/*[out,retval]*/);
  long            __fastcall moveNext(void);
  HRESULT         __fastcall atEnd(long* Value/*[out,retval]*/);
  long            __fastcall atEnd(void);
  HRESULT         __fastcall get_Current(Ppxscr_tlb::IPane** Value/*[out,retval]*/);
  Ppxscr_tlb::IPane* __fastcall get_Current(void);
  HRESULT         __fastcall IndexFrom(BSTR ppcid/*[in]*/, long* moved/*[out,retval]*/);
  long            __fastcall IndexFrom(BSTR ppcid/*[in]*/);

  __property   LPUNKNOWN       _NewEnum = {read = get__NewEnum};
  __property   long            Count = {read = get_Count};
  __property   long            length = {read = get_length};
  __property   long            index = {read = get_index, write = set_index};
  __property   BSTR            Name = {read = get_Name};
  __property   Ppxscr_tlb::ITab* Tab = {read = get_Tab};
  __property   Ppxscr_tlb::IPane* Current = {read = get_Current};
};
typedef IPaneDispT<IPane> IPaneDisp;

// *********************************************************************//
// SmartIntf: TCOMITab
// Interface: ITab
// *********************************************************************//
template <class T /* ITab */ >
class TCOMITabT : public TComInterface<ITab>, public TComInterfaceBase<IUnknown>
{
public:
  TCOMITabT() {}
  TCOMITabT(ITab *intf, bool addRef = false) : TComInterface<ITab>(intf, addRef) {}
  TCOMITabT(const TCOMITabT& src) : TComInterface<ITab>(src) {}
  TCOMITabT& operator=(const TCOMITabT& src) { Bind(src, true); return *this;}

  HRESULT         __fastcall Item(long index/*[in,opt]*/, Ppxscr_tlb::ITab** Value/*[out,retval]*/);
  Ppxscr_tlb::ITab* __fastcall Item(long index/*[in,opt]*/);
  HRESULT         __fastcall get__NewEnum(LPUNKNOWN* out_Enum/*[out,retval]*/);
  LPUNKNOWN       __fastcall get__NewEnum(void);
  HRESULT         __fastcall get_Count(long* Value/*[out,retval]*/);
  long            __fastcall get_Count(void);
  HRESULT         __fastcall get_length(long* Value/*[out,retval]*/);
  long            __fastcall get_length(void);
  HRESULT         __fastcall get_Lock(long* Value/*[out,retval]*/);
  long            __fastcall get_Lock(void);
  HRESULT         __fastcall set_Lock(long Value/*[in]*/);
  HRESULT         __fastcall get_idname(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_idname(void);
  HRESULT         __fastcall get_index(long* Value/*[out,retval]*/);
  long            __fastcall get_index(void);
  HRESULT         __fastcall set_index(long Value/*[in]*/);
  HRESULT         __fastcall get_Name(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_Name(void);
  HRESULT         __fastcall set_Name(BSTR Value/*[in]*/);
  HRESULT         __fastcall get_Type(long* Value/*[out,retval]*/);
  long            __fastcall get_Type(void);
  HRESULT         __fastcall set_Type(long Value/*[in]*/);
  HRESULT         __fastcall get_Pane(long* Value/*[out,retval]*/);
  long            __fastcall get_Pane(void);
  HRESULT         __fastcall set_Pane(long Value/*[in]*/);
  HRESULT         __fastcall get_TotalCount(long* Value/*[out,retval]*/);
  long            __fastcall get_TotalCount(void);
  HRESULT         __fastcall get_TotalPPcCount(long* Value/*[out,retval]*/);
  long            __fastcall get_TotalPPcCount(void);
  HRESULT         __fastcall get_Color(long* Value/*[out,retval]*/);
  long            __fastcall get_Color(void);
  HRESULT         __fastcall set_Color(long Value/*[in]*/);
  HRESULT         __fastcall get_BackColor(long* Value/*[out,retval]*/);
  long            __fastcall get_BackColor(void);
  HRESULT         __fastcall set_BackColor(long Value/*[in]*/);
  HRESULT         __fastcall Execute(BSTR param/*[in]*/, long* result/*[out,retval]*/);
  long            __fastcall Execute(BSTR param/*[in]*/);
  HRESULT         __fastcall Extract(BSTR param/*[in]*/, BSTR* result/*[out,retval]*/);
  BSTR            __fastcall Extract(BSTR param/*[in]*/);
  HRESULT         __fastcall moveNext(long* Value/*[out,retval]*/);
  long            __fastcall moveNext(void);
  HRESULT         __fastcall atEnd(long* Value/*[out,retval]*/);
  long            __fastcall atEnd(void);
  HRESULT         __fastcall Reset(void);
  HRESULT         __fastcall get_Current(Ppxscr_tlb::ITab** Value/*[out,retval]*/);
  HRESULT         __fastcall get_Current(Ppxscr_tlb::ITabPtr* Value/*[out,retval]*/);
  Ppxscr_tlb::ITabPtr __fastcall get_Current(void);
  HRESULT         __fastcall IndexFrom(BSTR ppcid/*[in]*/, long* moved/*[out,retval]*/);
  long            __fastcall IndexFrom(BSTR ppcid/*[in]*/);

  __property   LPUNKNOWN       _NewEnum = {read = get__NewEnum};
  __property   long            Count = {read = get_Count};
  __property   long            length = {read = get_length};
  __property   long            Lock = {read = get_Lock, write = set_Lock};
  __property   BSTR            idname = {read = get_idname};
  __property   long            index = {read = get_index, write = set_index};
  __property   BSTR            Name = {read = get_Name};
  __property   long            Type = {read = get_Type, write = set_Type};
  __property   long            Pane = {read = get_Pane, write = set_Pane};
  __property   long            TotalCount = {read = get_TotalCount};
  __property   long            TotalPPcCount = {read = get_TotalPPcCount};
  __property   long            Color = {read = get_Color, write = set_Color};
  __property   long            BackColor = {read = get_BackColor, write = set_BackColor};
  __property   Ppxscr_tlb::ITabPtr Current = {read = get_Current};
};
typedef TCOMITabT<ITab> TCOMITab;

// *********************************************************************//
// DispIntf:  ITab
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {A05A073E-C9E6-4742-A6F4-ECD6FD86E5F3}
// *********************************************************************//
template<class T>
class ITabDispT : public TAutoDriver<ITab>
{
public:
  ITabDispT(){}

  ITabDispT(ITab *pintf)
  {
    TAutoDriver<ITab>::Bind(pintf, false);
  }

  ITabDispT(ITabPtr pintf)
  {
    TAutoDriver<ITab>::Bind(pintf, true);
  }

  ITabDispT& operator=(ITab *pintf)
  {
    TAutoDriver<ITab>::Bind(pintf, false);
    return *this;
  }

  ITabDispT& operator=(ITabPtr pintf)
  {
    TAutoDriver<ITab>::Bind(pintf, true);
    return *this;
  }

  HRESULT BindDefault()
  {
    return OLECHECK(Bind(CLSID_ITab_Class));
  }

  HRESULT BindRunning()
  {
    return BindToActive(CLSID_ITab_Class);
  }

  HRESULT         __fastcall Item(long index/*[in,opt]*/, Ppxscr_tlb::ITab** Value/*[out,retval]*/);
  Ppxscr_tlb::ITab* __fastcall Item(long index/*[in,opt]*/);
  HRESULT         __fastcall get__NewEnum(LPUNKNOWN* out_Enum/*[out,retval]*/);
  LPUNKNOWN       __fastcall get__NewEnum(void);
  HRESULT         __fastcall get_Count(long* Value/*[out,retval]*/);
  long            __fastcall get_Count(void);
  HRESULT         __fastcall get_length(long* Value/*[out,retval]*/);
  long            __fastcall get_length(void);
  HRESULT         __fastcall get_Lock(long* Value/*[out,retval]*/);
  long            __fastcall get_Lock(void);
  HRESULT         __fastcall set_Lock(long Value/*[in]*/);
  HRESULT         __fastcall get_idname(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_idname(void);
  HRESULT         __fastcall get_index(long* Value/*[out,retval]*/);
  long            __fastcall get_index(void);
  HRESULT         __fastcall set_index(long Value/*[in]*/);
  HRESULT         __fastcall get_Name(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_Name(void);
  HRESULT         __fastcall set_Name(BSTR Value/*[in]*/);
  HRESULT         __fastcall get_Type(long* Value/*[out,retval]*/);
  long            __fastcall get_Type(void);
  HRESULT         __fastcall set_Type(long Value/*[in]*/);
  HRESULT         __fastcall get_Pane(long* Value/*[out,retval]*/);
  long            __fastcall get_Pane(void);
  HRESULT         __fastcall set_Pane(long Value/*[in]*/);
  HRESULT         __fastcall get_TotalCount(long* Value/*[out,retval]*/);
  long            __fastcall get_TotalCount(void);
  HRESULT         __fastcall get_TotalPPcCount(long* Value/*[out,retval]*/);
  long            __fastcall get_TotalPPcCount(void);
  HRESULT         __fastcall get_Color(long* Value/*[out,retval]*/);
  long            __fastcall get_Color(void);
  HRESULT         __fastcall set_Color(long Value/*[in]*/);
  HRESULT         __fastcall get_BackColor(long* Value/*[out,retval]*/);
  long            __fastcall get_BackColor(void);
  HRESULT         __fastcall set_BackColor(long Value/*[in]*/);
  HRESULT         __fastcall Execute(BSTR param/*[in]*/, long* result/*[out,retval]*/);
  long            __fastcall Execute(BSTR param/*[in]*/);
  HRESULT         __fastcall Extract(BSTR param/*[in]*/, BSTR* result/*[out,retval]*/);
  BSTR            __fastcall Extract(BSTR param/*[in]*/);
  HRESULT         __fastcall moveNext(long* Value/*[out,retval]*/);
  long            __fastcall moveNext(void);
  HRESULT         __fastcall atEnd(long* Value/*[out,retval]*/);
  long            __fastcall atEnd(void);
  HRESULT         __fastcall Reset();
  HRESULT         __fastcall get_Current(Ppxscr_tlb::ITab** Value/*[out,retval]*/);
  Ppxscr_tlb::ITab* __fastcall get_Current(void);
  HRESULT         __fastcall IndexFrom(BSTR ppcid/*[in]*/, long* moved/*[out,retval]*/);
  long            __fastcall IndexFrom(BSTR ppcid/*[in]*/);

  __property   LPUNKNOWN       _NewEnum = {read = get__NewEnum};
  __property   long            Count = {read = get_Count};
  __property   long            length = {read = get_length};
  __property   long            Lock = {read = get_Lock, write = set_Lock};
  __property   BSTR            idname = {read = get_idname};
  __property   long            index = {read = get_index, write = set_index};
  __property   BSTR            Name = {read = get_Name};
  __property   long            Type = {read = get_Type, write = set_Type};
  __property   long            Pane = {read = get_Pane, write = set_Pane};
  __property   long            TotalCount = {read = get_TotalCount};
  __property   long            TotalPPcCount = {read = get_TotalPPcCount};
  __property   long            Color = {read = get_Color, write = set_Color};
  __property   long            BackColor = {read = get_BackColor, write = set_BackColor};
  __property   Ppxscr_tlb::ITab* Current = {read = get_Current};
};
typedef ITabDispT<ITab> ITabDisp;

// *********************************************************************//
// SmartIntf: TCOMIPPxEnum
// Interface: IPPxEnum
// *********************************************************************//
template <class T /* IPPxEnum */ >
class TCOMIPPxEnumT : public TComInterface<IPPxEnum>, public TComInterfaceBase<IUnknown>
{
public:
  TCOMIPPxEnumT() {}
  TCOMIPPxEnumT(IPPxEnum *intf, bool addRef = false) : TComInterface<IPPxEnum>(intf, addRef) {}
  TCOMIPPxEnumT(const TCOMIPPxEnumT& src) : TComInterface<IPPxEnum>(src) {}
  TCOMIPPxEnumT& operator=(const TCOMIPPxEnumT& src) { Bind(src, true); return *this;}

  HRESULT         __fastcall Item(long index/*[in,opt]*/, VARIANT* Value/*[out,retval]*/);
  VARIANT         __fastcall Item(long index/*[in,opt]*/);
  HRESULT         __fastcall moveFirst(void);
  HRESULT         __fastcall moveNext(long* Value/*[out,retval]*/);
  long            __fastcall moveNext(void);
  HRESULT         __fastcall atEnd(long* Value/*[out,retval]*/);
  long            __fastcall atEnd(void);
  HRESULT         __fastcall Reset(void);
  HRESULT         __fastcall get_index(long* Value/*[out,retval]*/);
  long            __fastcall get_index(void);
  HRESULT         __fastcall set_index(long Value/*[in]*/);

  __property   long            index = {read = get_index, write = set_index};
};
typedef TCOMIPPxEnumT<IPPxEnum> TCOMIPPxEnum;

// *********************************************************************//
// DispIntf:  IPPxEnum
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {4EA875C7-268F-4439-96EE-EAFA90173788}
// *********************************************************************//
template<class T>
class IPPxEnumDispT : public TAutoDriver<IPPxEnum>
{
public:
  IPPxEnumDispT(){}

  IPPxEnumDispT(IPPxEnum *pintf)
  {
    TAutoDriver<IPPxEnum>::Bind(pintf, false);
  }

  IPPxEnumDispT(IPPxEnumPtr pintf)
  {
    TAutoDriver<IPPxEnum>::Bind(pintf, true);
  }

  IPPxEnumDispT& operator=(IPPxEnum *pintf)
  {
    TAutoDriver<IPPxEnum>::Bind(pintf, false);
    return *this;
  }

  IPPxEnumDispT& operator=(IPPxEnumPtr pintf)
  {
    TAutoDriver<IPPxEnum>::Bind(pintf, true);
    return *this;
  }

  HRESULT BindDefault()
  {
    return OLECHECK(Bind(CLSID_IPPxEnum_Class));
  }

  HRESULT BindRunning()
  {
    return BindToActive(CLSID_IPPxEnum_Class);
  }

  HRESULT         __fastcall Item(long index/*[in,opt]*/, VARIANT* Value/*[out,retval]*/);
  VARIANT         __fastcall Item(long index/*[in,opt]*/);
  HRESULT         __fastcall moveFirst();
  HRESULT         __fastcall moveNext(long* Value/*[out,retval]*/);
  long            __fastcall moveNext(void);
  HRESULT         __fastcall atEnd(long* Value/*[out,retval]*/);
  long            __fastcall atEnd(void);
  HRESULT         __fastcall Reset();
  HRESULT         __fastcall get_index(long* Value/*[out,retval]*/);
  long            __fastcall get_index(void);
  HRESULT         __fastcall set_index(long Value/*[in]*/);

  __property   long            index = {read = get_index, write = set_index};
};
typedef IPPxEnumDispT<IPPxEnum> IPPxEnumDisp;

// *********************************************************************//
// DispIntf:  IPPxEvents
// Flags:     (4096) Dispatchable
// GUID:      {A540CECD-88F0-4F99-A1FF-5F20BA36DF9F}
// *********************************************************************//
// *********************************************************************//
// SmartIntf: TCOMIPPx
// Interface: IPPx
// *********************************************************************//
template <class T> HRESULT __fastcall
TCOMIPPxT<T>::Execute(BSTR param/*[in]*/, long* result/*[out,retval]*/)
{
  return (*this)->Execute(param, result);
}

template <class T> long __fastcall
TCOMIPPxT<T>::Execute(BSTR param/*[in]*/)
{
  long result;
  OLECHECK(this->Execute(, (long*)&result));
  return result;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::DisconnectObject(LPDISPATCH pObject/*[in]*/)
{
  return (*this)->DisconnectObject(pObject);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::ConnectObject(LPDISPATCH pObject/*[in]*/, BSTR bstrPrefix/*[in]*/)
{
  return (*this)->ConnectObject(pObject, bstrPrefix);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::CreateObject(BSTR bstrProgId/*[in]*/, BSTR bstrPrefix/*[in,def,opt]*/, 
                           LPDISPATCH* ppObject/*[out,retval]*/)
{
  return (*this)->CreateObject(bstrProgId, bstrPrefix, ppObject);
}

template <class T> LPDISPATCH __fastcall
TCOMIPPxT<T>::CreateObject(BSTR bstrProgId/*[in]*/, BSTR bstrPrefix/*[in,def,opt]*/)
{
  LPDISPATCH ppObject;
  OLECHECK(this->CreateObject(, (LPDISPATCH*)&ppObject));
  return ppObject;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::Extract(BSTR param/*[in]*/, BSTR* result/*[out,retval]*/)
{
  return (*this)->Extract(param, result);
}

template <class T> BSTR __fastcall
TCOMIPPxT<T>::Extract(BSTR param/*[in]*/)
{
  BSTR result = 0;
  OLECHECK(this->Extract(, (BSTR*)&result));
  return result;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::Sleep(long nMilliseconds/*[in,opt]*/)
{
  return (*this)->Sleep(nMilliseconds);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::GetObject(BSTR bstrPathName/*[in]*/, BSTR bstrProgId/*[in,def,opt]*/, 
                        BSTR bstrPrefix/*[in,def,opt]*/, LPDISPATCH* ppObject/*[out,retval]*/)
{
  return (*this)->GetObject(bstrPathName, bstrProgId, bstrPrefix, ppObject);
}

template <class T> LPDISPATCH __fastcall
TCOMIPPxT<T>::GetObject(BSTR bstrPathName/*[in]*/, BSTR bstrProgId/*[in,def,opt]*/, 
                        BSTR bstrPrefix/*[in,def,opt]*/)
{
  LPDISPATCH ppObject;
  OLECHECK(this->GetObject(, (LPDISPATCH*)&ppObject));
  return ppObject;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::Echo(LPSAFEARRAY parr/*[in]*/)
{
  return (*this)->Echo(parr);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_EntryName(BSTR* Value/*[out,retval]*/)
{
  return (*this)->get_EntryName(Value);
}

template <class T> BSTR __fastcall
TCOMIPPxT<T>::get_EntryName(void)
{
  BSTR Value = 0;
  OLECHECK(this->get_EntryName((BSTR*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_ScriptFullName(BSTR* Value/*[out,retval]*/)
{
  return (*this)->get_ScriptFullName(Value);
}

template <class T> BSTR __fastcall
TCOMIPPxT<T>::get_ScriptFullName(void)
{
  BSTR Value = 0;
  OLECHECK(this->get_ScriptFullName((BSTR*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_ScriptName(BSTR* Value/*[out,retval]*/)
{
  return (*this)->get_ScriptName(Value);
}

template <class T> BSTR __fastcall
TCOMIPPxT<T>::get_ScriptName(void)
{
  BSTR Value = 0;
  OLECHECK(this->get_ScriptName((BSTR*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_EntryIndex(long* Value/*[out,retval]*/)
{
  return (*this)->get_EntryIndex(Value);
}

template <class T> long __fastcall
TCOMIPPxT<T>::get_EntryIndex(void)
{
  long Value;
  OLECHECK(this->get_EntryIndex((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_EntryDisplayTop(long* Value/*[out,retval]*/)
{
  return (*this)->get_EntryDisplayTop(Value);
}

template <class T> long __fastcall
TCOMIPPxT<T>::get_EntryDisplayTop(void)
{
  long Value;
  OLECHECK(this->get_EntryDisplayTop((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_EntryDisplayX(long* Value/*[out,retval]*/)
{
  return (*this)->get_EntryDisplayX(Value);
}

template <class T> long __fastcall
TCOMIPPxT<T>::get_EntryDisplayX(void)
{
  long Value;
  OLECHECK(this->get_EntryDisplayX((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_EntryDisplayY(long* Value/*[out,retval]*/)
{
  return (*this)->get_EntryDisplayY(Value);
}

template <class T> long __fastcall
TCOMIPPxT<T>::get_EntryDisplayY(void)
{
  long Value;
  OLECHECK(this->get_EntryDisplayY((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_WindowDirection(long* Value/*[out,retval]*/)
{
  return (*this)->get_WindowDirection(Value);
}

template <class T> long __fastcall
TCOMIPPxT<T>::get_WindowDirection(void)
{
  long Value;
  OLECHECK(this->get_WindowDirection((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_EntryMark(long* Value/*[out,retval]*/)
{
  return (*this)->get_EntryMark(Value);
}

template <class T> long __fastcall
TCOMIPPxT<T>::get_EntryMark(void)
{
  long Value;
  OLECHECK(this->get_EntryMark((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::set_EntryIndex(long Value/*[in]*/)
{
  return (*this)->set_EntryIndex(Value);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::set_EntryMark(long Value/*[in]*/)
{
  return (*this)->set_EntryMark(Value);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_EntryComment(BSTR* Value/*[out,retval]*/)
{
  return (*this)->get_EntryComment(Value);
}

template <class T> BSTR __fastcall
TCOMIPPxT<T>::get_EntryComment(void)
{
  BSTR Value = 0;
  OLECHECK(this->get_EntryComment((BSTR*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::set_EntryComment(BSTR Value/*[in]*/)
{
  return (*this)->set_EntryComment(Value);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_EntryAttributes(long* Value/*[out,retval]*/)
{
  return (*this)->get_EntryAttributes(Value);
}

template <class T> long __fastcall
TCOMIPPxT<T>::get_EntryAttributes(void)
{
  long Value;
  OLECHECK(this->get_EntryAttributes((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_EntrySize(double* Value/*[out,retval]*/)
{
  return (*this)->get_EntrySize(Value);
}

template <class T> double __fastcall
TCOMIPPxT<T>::get_EntrySize(void)
{
  double Value;
  OLECHECK(this->get_EntrySize((double*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::EntryFirstMark(long* result/*[out,retval]*/)
{
  return (*this)->EntryFirstMark(result);
}

template <class T> long __fastcall
TCOMIPPxT<T>::EntryFirstMark(void)
{
  long result;
  OLECHECK(this->EntryFirstMark((long*)&result));
  return result;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::EntryNextMark(long* result/*[out,retval]*/)
{
  return (*this)->EntryNextMark(result);
}

template <class T> long __fastcall
TCOMIPPxT<T>::EntryNextMark(void)
{
  long result;
  OLECHECK(this->EntryNextMark((long*)&result));
  return result;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::SetPopLineMessage(BSTR message/*[in]*/)
{
  return (*this)->SetPopLineMessage(message);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_PPxVersion(long* Value/*[out,retval]*/)
{
  return (*this)->get_PPxVersion(Value);
}

template <class T> long __fastcall
TCOMIPPxT<T>::get_PPxVersion(void)
{
  long Value;
  OLECHECK(this->get_PPxVersion((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_CodeType(long* Value/*[out,retval]*/)
{
  return (*this)->get_CodeType(Value);
}

template <class T> long __fastcall
TCOMIPPxT<T>::get_CodeType(void)
{
  long Value;
  OLECHECK(this->get_CodeType((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_EntryAllCount(long* Value/*[out,retval]*/)
{
  return (*this)->get_EntryAllCount(Value);
}

template <class T> long __fastcall
TCOMIPPxT<T>::get_EntryAllCount(void)
{
  long Value;
  OLECHECK(this->get_EntryAllCount((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_EntryDisplayCount(long* Value/*[out,retval]*/)
{
  return (*this)->get_EntryDisplayCount(Value);
}

template <class T> long __fastcall
TCOMIPPxT<T>::get_EntryDisplayCount(void)
{
  long Value;
  OLECHECK(this->get_EntryDisplayCount((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_EntryDisplayFiles(long* Value/*[out,retval]*/)
{
  return (*this)->get_EntryDisplayFiles(Value);
}

template <class T> long __fastcall
TCOMIPPxT<T>::get_EntryDisplayFiles(void)
{
  long Value;
  OLECHECK(this->get_EntryDisplayFiles((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_EntryDisplayDirectories(long* Value/*[out,retval]*/)
{
  return (*this)->get_EntryDisplayDirectories(Value);
}

template <class T> long __fastcall
TCOMIPPxT<T>::get_EntryDisplayDirectories(void)
{
  long Value;
  OLECHECK(this->get_EntryDisplayDirectories((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_DirectoryType(long* Value/*[out,retval]*/)
{
  return (*this)->get_DirectoryType(Value);
}

template <class T> long __fastcall
TCOMIPPxT<T>::get_DirectoryType(void)
{
  long Value;
  OLECHECK(this->get_DirectoryType((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_SyncView(long* Value/*[out,retval]*/)
{
  return (*this)->get_SyncView(Value);
}

template <class T> long __fastcall
TCOMIPPxT<T>::get_SyncView(void)
{
  long Value;
  OLECHECK(this->get_SyncView((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::set_SyncView(long Value/*[in]*/)
{
  return (*this)->set_SyncView(Value);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_ModuleVersion(long* Value/*[out,retval]*/)
{
  return (*this)->get_ModuleVersion(Value);
}

template <class T> long __fastcall
TCOMIPPxT<T>::get_ModuleVersion(void)
{
  long Value;
  OLECHECK(this->get_ModuleVersion((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_EntryState(long* Value/*[out,retval]*/)
{
  return (*this)->get_EntryState(Value);
}

template <class T> long __fastcall
TCOMIPPxT<T>::get_EntryState(void)
{
  long Value;
  OLECHECK(this->get_EntryState((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::set_EntryState(long Value/*[in]*/)
{
  return (*this)->set_EntryState(Value);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_EntryExtColor(long* Value/*[out,retval]*/)
{
  return (*this)->get_EntryExtColor(Value);
}

template <class T> long __fastcall
TCOMIPPxT<T>::get_EntryExtColor(void)
{
  long Value;
  OLECHECK(this->get_EntryExtColor((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::set_EntryExtColor(long Value/*[in]*/)
{
  return (*this)->set_EntryExtColor(Value);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_result(BSTR* Value/*[out,retval]*/)
{
  return (*this)->get_result(Value);
}

template <class T> BSTR __fastcall
TCOMIPPxT<T>::get_result(void)
{
  BSTR Value = 0;
  OLECHECK(this->get_result((BSTR*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::set_result(BSTR Value/*[in]*/)
{
  return (*this)->set_result(Value);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_Arguments(Ppxscr_tlb::IArguments** Value/*[out,retval]*/)
{
  return (*this)->get_Arguments(Value);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_Arguments(Ppxscr_tlb::IArgumentsPtr* Value/*[out,retval]*/)
{
  return (*this)->get_Arguments(IArguments**)Value);
}

template <class T> Ppxscr_tlb::IArgumentsPtr __fastcall
TCOMIPPxT<T>::get_Arguments(void)
{
  Ppxscr_tlb::IArguments* Value;
  OLECHECK(this->get_Arguments((Ppxscr_tlb::IArguments**)&Value));
  return (Ppxscr_tlb::IArgumentsPtr)Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::Quit(long ExitCode/*[in,opt]*/)
{
  return (*this)->Quit(ExitCode);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_EntryMarkCount(long* Value/*[out,retval]*/)
{
  return (*this)->get_EntryMarkCount(Value);
}

template <class T> long __fastcall
TCOMIPPxT<T>::get_EntryMarkCount(void)
{
  long Value;
  OLECHECK(this->get_EntryMarkCount((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_Entry(Ppxscr_tlb::IEntry** Value/*[out,retval]*/)
{
  return (*this)->get_Entry(Value);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_Entry(Ppxscr_tlb::IEntryPtr* Value/*[out,retval]*/)
{
  return (*this)->get_Entry(IEntry**)Value);
}

template <class T> Ppxscr_tlb::IEntryPtr __fastcall
TCOMIPPxT<T>::get_Entry(void)
{
  Ppxscr_tlb::IEntry* Value;
  OLECHECK(this->get_Entry((Ppxscr_tlb::IEntry**)&Value));
  return (Ppxscr_tlb::IEntryPtr)Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_SlowMode(long* Value/*[out,retval]*/)
{
  return (*this)->get_SlowMode(Value);
}

template <class T> long __fastcall
TCOMIPPxT<T>::get_SlowMode(void)
{
  long Value;
  OLECHECK(this->get_SlowMode((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::set_SlowMode(long Value/*[in]*/)
{
  return (*this)->set_SlowMode(Value);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::GetFileInformation(BSTR FileName/*[in]*/, long Mode/*[in,opt]*/, 
                                 BSTR* Text/*[out,retval]*/)
{
  return (*this)->GetFileInformation(FileName, Mode, Text);
}

template <class T> BSTR __fastcall
TCOMIPPxT<T>::GetFileInformation(BSTR FileName/*[in]*/, long Mode/*[in,opt]*/)
{
  BSTR Text = 0;
  OLECHECK(this->GetFileInformation(, (BSTR*)&Text));
  return Text;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_DriveVolumeLabel(BSTR* Value/*[out,retval]*/)
{
  return (*this)->get_DriveVolumeLabel(Value);
}

template <class T> BSTR __fastcall
TCOMIPPxT<T>::get_DriveVolumeLabel(void)
{
  BSTR Value = 0;
  OLECHECK(this->get_DriveVolumeLabel((BSTR*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_EntryMarkSize(double* Value/*[out,retval]*/)
{
  return (*this)->get_EntryMarkSize(Value);
}

template <class T> double __fastcall
TCOMIPPxT<T>::get_EntryMarkSize(void)
{
  double Value;
  OLECHECK(this->get_EntryMarkSize((double*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_DriveTotalSize(double* Value/*[out,retval]*/)
{
  return (*this)->get_DriveTotalSize(Value);
}

template <class T> double __fastcall
TCOMIPPxT<T>::get_DriveTotalSize(void)
{
  double Value;
  OLECHECK(this->get_DriveTotalSize((double*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_DriveFreeSize(double* Value/*[out,retval]*/)
{
  return (*this)->get_DriveFreeSize(Value);
}

template <class T> double __fastcall
TCOMIPPxT<T>::get_DriveFreeSize(void)
{
  double Value;
  OLECHECK(this->get_DriveFreeSize((double*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::EntryInsert(long index/*[in]*/, BSTR EntryName/*[in]*/)
{
  return (*this)->EntryInsert(index, EntryName);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_Clipboard(BSTR* Value/*[out,retval]*/)
{
  return (*this)->get_Clipboard(Value);
}

template <class T> BSTR __fastcall
TCOMIPPxT<T>::get_Clipboard(void)
{
  BSTR Value = 0;
  OLECHECK(this->get_Clipboard((BSTR*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::set_Clipboard(BSTR Value/*[in]*/)
{
  return (*this)->set_Clipboard(Value);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_StayMode(long* Value/*[out,retval]*/)
{
  return (*this)->get_StayMode(Value);
}

template <class T> long __fastcall
TCOMIPPxT<T>::get_StayMode(void)
{
  long Value;
  OLECHECK(this->get_StayMode((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::set_StayMode(long Value/*[in]*/)
{
  return (*this)->set_StayMode(Value);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_EntryHighlight(long* Value/*[out,retval]*/)
{
  return (*this)->get_EntryHighlight(Value);
}

template <class T> long __fastcall
TCOMIPPxT<T>::get_EntryHighlight(void)
{
  long Value;
  OLECHECK(this->get_EntryHighlight((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::set_EntryHighlight(long Value/*[in]*/)
{
  return (*this)->set_EntryHighlight(Value);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_Pane(Ppxscr_tlb::IPane** Value/*[out,retval]*/)
{
  return (*this)->get_Pane(Value);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_Pane(Ppxscr_tlb::IPanePtr* Value/*[out,retval]*/)
{
  return (*this)->get_Pane(IPane**)Value);
}

template <class T> Ppxscr_tlb::IPanePtr __fastcall
TCOMIPPxT<T>::get_Pane(void)
{
  Ppxscr_tlb::IPane* Value;
  OLECHECK(this->get_Pane((Ppxscr_tlb::IPane**)&Value));
  return (Ppxscr_tlb::IPanePtr)Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::EntryPrevMark(long* result/*[out,retval]*/)
{
  return (*this)->EntryPrevMark(result);
}

template <class T> long __fastcall
TCOMIPPxT<T>::EntryPrevMark(void)
{
  long result;
  OLECHECK(this->EntryPrevMark((long*)&result));
  return result;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::EntryLastMark(long* result/*[out,retval]*/)
{
  return (*this)->EntryLastMark(result);
}

template <class T> long __fastcall
TCOMIPPxT<T>::EntryLastMark(void)
{
  long result;
  OLECHECK(this->EntryLastMark((long*)&result));
  return result;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::GetComboItemCount(long id/*[in]*/, long* result/*[out]*/)
{
  return (*this)->GetComboItemCount(id, result);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_ComboIDName(BSTR* Value/*[out,retval]*/)
{
  return (*this)->get_ComboIDName(Value);
}

template <class T> BSTR __fastcall
TCOMIPPxT<T>::get_ComboIDName(void)
{
  BSTR Value = 0;
  OLECHECK(this->get_ComboIDName((BSTR*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_PointType(long* Value/*[out,retval]*/)
{
  return (*this)->get_PointType(Value);
}

template <class T> long __fastcall
TCOMIPPxT<T>::get_PointType(void)
{
  long Value;
  OLECHECK(this->get_PointType((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_PointIndex(long* Value/*[out,retval]*/)
{
  return (*this)->get_PointIndex(Value);
}

template <class T> long __fastcall
TCOMIPPxT<T>::get_PointIndex(void)
{
  long Value;
  OLECHECK(this->get_PointIndex((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::Cursor(long x/*[in]*/, long y/*[in,def,opt]*/, long* result/*[out,retval]*/)
{
  return (*this)->Cursor(x, y, result);
}

template <class T> long __fastcall
TCOMIPPxT<T>::Cursor(long x/*[in]*/, long y/*[in,def,opt]*/)
{
  long result;
  OLECHECK(this->Cursor(, (long*)&result));
  return result;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_ScriptEngineName(BSTR* Value/*[out,retval]*/)
{
  return (*this)->get_ScriptEngineName(Value);
}

template <class T> BSTR __fastcall
TCOMIPPxT<T>::get_ScriptEngineName(void)
{
  BSTR Value = 0;
  OLECHECK(this->get_ScriptEngineName((BSTR*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::getValue(BSTR key/*[in]*/, BSTR* result/*[out,retval]*/)
{
  return (*this)->getValue(key, result);
}

template <class T> BSTR __fastcall
TCOMIPPxT<T>::getValue(BSTR key/*[in]*/)
{
  BSTR result = 0;
  OLECHECK(this->getValue(, (BSTR*)&result));
  return result;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::setValue(BSTR key/*[in]*/, BSTR Value/*[in]*/)
{
  return (*this)->setValue(key, Value);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_ScriptEngineVersion(BSTR* Value/*[out,retval]*/)
{
  return (*this)->get_ScriptEngineVersion(Value);
}

template <class T> BSTR __fastcall
TCOMIPPxT<T>::get_ScriptEngineVersion(void)
{
  BSTR Value = 0;
  OLECHECK(this->get_ScriptEngineVersion((BSTR*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::lineMessage(BSTR Text/*[in]*/)
{
  return (*this)->lineMessage(Text);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_WindowIDName(BSTR* Value/*[out,retval]*/)
{
  return (*this)->get_WindowIDName(Value);
}

template <class T> BSTR __fastcall
TCOMIPPxT<T>::get_WindowIDName(void)
{
  BSTR Value = 0;
  OLECHECK(this->get_WindowIDName((BSTR*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::set_WindowIDName(BSTR Value/*[in]*/)
{
  return (*this)->set_WindowIDName(Value);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::Argument(long itemindex/*[in,def,opt]*/, BSTR* Arg/*[out,retval]*/)
{
  return (*this)->Argument(itemindex, Arg);
}

template <class T> BSTR __fastcall
TCOMIPPxT<T>::Argument(long itemindex/*[in,def,opt]*/)
{
  BSTR Arg = 0;
  OLECHECK(this->Argument(, (BSTR*)&Arg));
  return Arg;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::report(BSTR Text/*[in]*/)
{
  return (*this)->report(Text);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::log(BSTR Text/*[in]*/)
{
  return (*this)->log(Text);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::getProcessValue(BSTR key/*[in]*/, BSTR* result/*[out,retval]*/)
{
  return (*this)->getProcessValue(key, result);
}

template <class T> BSTR __fastcall
TCOMIPPxT<T>::getProcessValue(BSTR key/*[in]*/)
{
  BSTR result = 0;
  OLECHECK(this->getProcessValue(, (BSTR*)&result));
  return result;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::setProcessValue(BSTR key/*[in]*/, BSTR Value/*[in]*/)
{
  return (*this)->setProcessValue(key, Value);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::getIValue(BSTR key/*[in]*/, BSTR* result/*[out,retval]*/)
{
  return (*this)->getIValue(key, result);
}

template <class T> BSTR __fastcall
TCOMIPPxT<T>::getIValue(BSTR key/*[in]*/)
{
  BSTR result = 0;
  OLECHECK(this->getIValue(, (BSTR*)&result));
  return result;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::setIValue(BSTR key/*[in]*/, BSTR Value/*[in]*/)
{
  return (*this)->setIValue(key, Value);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::Enumerator(LPDISPATCH object/*[in]*/, LPDISPATCH* Value/*[out,retval]*/)
{
  return (*this)->Enumerator(object, Value);
}

template <class T> LPDISPATCH __fastcall
TCOMIPPxT<T>::Enumerator(LPDISPATCH object/*[in]*/)
{
  LPDISPATCH Value;
  OLECHECK(this->Enumerator(, (LPDISPATCH*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::Include(BSTR FileName/*[in]*/)
{
  return (*this)->Include(FileName);
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::get_ReentryCount(long* Value/*[out,retval]*/)
{
  return (*this)->get_ReentryCount(Value);
}

template <class T> long __fastcall
TCOMIPPxT<T>::get_ReentryCount(void)
{
  long Value;
  OLECHECK(this->get_ReentryCount((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxT<T>::option(BSTR name/*[in]*/, VARIANT param/*[in,opt]*/, VARIANT* Value/*[out,retval]*/)
{
  return (*this)->option(name, param, Value);
}

template <class T> VARIANT __fastcall
TCOMIPPxT<T>::option(BSTR name/*[in]*/, VARIANT param/*[in,opt]*/)
{
  VARIANT Value;
  OLECHECK(this->option(, (VARIANT*)&Value));
  return Value;
}

// *********************************************************************//
// DispIntf:  IPPx
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {6114B9D8-86E7-4D41-95DD-DB7262512BA6}
// *********************************************************************//
template <class T> HRESULT __fastcall
IPPxDispT<T>::Execute(BSTR param/*[in]*/, long* result/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Execute"), DISPID(8));
  TAutoArgs<1> _args;
  _args[1] = param /*[VT_BSTR:0]*/;
  return OutRetValSetterPtr(result /*[VT_I4:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::Execute(BSTR param/*[in]*/)
{
  long result;
  this->Execute(param, (long*)&result);
  return result;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::DisconnectObject(LPDISPATCH pObject/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("DisconnectObject"), DISPID(3));
  TAutoArgs<1> _args;
  _args[1] = pObject /*[VT_DISPATCH:0]*/;
  return OleFunction(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::ConnectObject(LPDISPATCH pObject/*[in]*/, BSTR bstrPrefix/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("ConnectObject"), DISPID(2));
  TAutoArgs<2> _args;
  _args[1] = pObject /*[VT_DISPATCH:0]*/;
  _args[2] = bstrPrefix /*[VT_BSTR:0]*/;
  return OleFunction(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::CreateObject(BSTR bstrProgId/*[in]*/, BSTR bstrPrefix/*[in,def,opt]*/, 
                           LPDISPATCH* ppObject/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("CreateObject"), DISPID(1));
  TAutoArgs<2> _args;
  _args[1] = bstrProgId /*[VT_BSTR:0]*/;
  _args[2] = bstrPrefix /*[VT_BSTR:0]*/;
  return OutRetValSetterPtr(ppObject /*[VT_DISPATCH:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> LPDISPATCH __fastcall
IPPxDispT<T>::CreateObject(BSTR bstrProgId/*[in]*/, BSTR bstrPrefix/*[in,def,opt]*/)
{
  LPDISPATCH ppObject;
  this->CreateObject(bstrProgId, bstrPrefix, (LPDISPATCH*)&ppObject);
  return ppObject;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::Extract(BSTR param/*[in]*/, BSTR* result/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Extract"), DISPID(9));
  TAutoArgs<1> _args;
  _args[1] = param /*[VT_BSTR:0]*/;
  return OutRetValSetterPtr(result /*[VT_BSTR:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> BSTR __fastcall
IPPxDispT<T>::Extract(BSTR param/*[in]*/)
{
  BSTR result;
  this->Extract(param, (BSTR*)&result);
  return result;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::Sleep(long nMilliseconds/*[in,opt]*/)
{
  _TDispID _dispid(*this, OLETEXT("Sleep"), DISPID(7));
  TAutoArgs<1> _args;
  _args[1] = nMilliseconds /*[VT_I4:0]*/;
  return OleFunction(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::GetObject(BSTR bstrPathName/*[in]*/, BSTR bstrProgId/*[in,def,opt]*/, 
                        BSTR bstrPrefix/*[in,def,opt]*/, LPDISPATCH* ppObject/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("GetObject"), DISPID(5));
  TAutoArgs<3> _args;
  _args[1] = bstrPathName /*[VT_BSTR:0]*/;
  _args[2] = bstrProgId /*[VT_BSTR:0]*/;
  _args[3] = bstrPrefix /*[VT_BSTR:0]*/;
  return OutRetValSetterPtr(ppObject /*[VT_DISPATCH:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> LPDISPATCH __fastcall
IPPxDispT<T>::GetObject(BSTR bstrPathName/*[in]*/, BSTR bstrProgId/*[in,def,opt]*/, 
                        BSTR bstrPrefix/*[in,def,opt]*/)
{
  LPDISPATCH ppObject;
  this->GetObject(bstrPathName, bstrProgId, bstrPrefix, (LPDISPATCH*)&ppObject);
  return ppObject;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::Echo(LPSAFEARRAY parr/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("Echo"), DISPID(4));
  TAutoArgs<1> _args;
  _args[1] = parr /*[VT_SAFEARRAY:0]*/;
  return OleFunction(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_EntryName(BSTR* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryName"), DISPID(100));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BSTR:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> BSTR __fastcall
IPPxDispT<T>::get_EntryName(void)
{
  BSTR Value;
  this->get_EntryName((BSTR*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_ScriptFullName(BSTR* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("ScriptFullName"), DISPID(200));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BSTR:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> BSTR __fastcall
IPPxDispT<T>::get_ScriptFullName(void)
{
  BSTR Value;
  this->get_ScriptFullName((BSTR*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_ScriptName(BSTR* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("ScriptName"), DISPID(201));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BSTR:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> BSTR __fastcall
IPPxDispT<T>::get_ScriptName(void)
{
  BSTR Value;
  this->get_ScriptName((BSTR*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_EntryIndex(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryIndex"), DISPID(101));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::get_EntryIndex(void)
{
  long Value;
  this->get_EntryIndex((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_EntryDisplayTop(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryDisplayTop"), DISPID(102));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::get_EntryDisplayTop(void)
{
  long Value;
  this->get_EntryDisplayTop((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_EntryDisplayX(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryDisplayX"), DISPID(103));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::get_EntryDisplayX(void)
{
  long Value;
  this->get_EntryDisplayX((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_EntryDisplayY(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryDisplayY"), DISPID(104));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::get_EntryDisplayY(void)
{
  long Value;
  this->get_EntryDisplayY((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_WindowDirection(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("WindowDirection"), DISPID(105));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::get_WindowDirection(void)
{
  long Value;
  this->get_WindowDirection((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_EntryMark(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryMark"), DISPID(106));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::get_EntryMark(void)
{
  long Value;
  this->get_EntryMark((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::set_EntryIndex(long Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryIndex"), DISPID(101));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_I4:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::set_EntryMark(long Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryMark"), DISPID(106));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_I4:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_EntryComment(BSTR* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryComment"), DISPID(107));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BSTR:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> BSTR __fastcall
IPPxDispT<T>::get_EntryComment(void)
{
  BSTR Value;
  this->get_EntryComment((BSTR*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::set_EntryComment(BSTR Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryComment"), DISPID(107));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_BSTR:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_EntryAttributes(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryAttributes"), DISPID(108));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::get_EntryAttributes(void)
{
  long Value;
  this->get_EntryAttributes((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_EntrySize(double* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntrySize"), DISPID(109));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_R8:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> double __fastcall
IPPxDispT<T>::get_EntrySize(void)
{
  double Value;
  this->get_EntrySize((double*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::EntryFirstMark(long* result/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryFirstMark"), DISPID(11));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(result /*[VT_I4:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::EntryFirstMark(void)
{
  long result;
  this->EntryFirstMark((long*)&result);
  return result;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::EntryNextMark(long* result/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryNextMark"), DISPID(12));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(result /*[VT_I4:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::EntryNextMark(void)
{
  long result;
  this->EntryNextMark((long*)&result);
  return result;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::SetPopLineMessage(BSTR message/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("SetPopLineMessage"), DISPID(10));
  TAutoArgs<1> _args;
  _args[1] = message /*[VT_BSTR:0]*/;
  return OleFunction(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_PPxVersion(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("PPxVersion"), DISPID(300));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::get_PPxVersion(void)
{
  long Value;
  this->get_PPxVersion((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_CodeType(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("CodeType"), DISPID(301));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::get_CodeType(void)
{
  long Value;
  this->get_CodeType((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_EntryAllCount(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryAllCount"), DISPID(111));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::get_EntryAllCount(void)
{
  long Value;
  this->get_EntryAllCount((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_EntryDisplayCount(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryDisplayCount"), DISPID(112));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::get_EntryDisplayCount(void)
{
  long Value;
  this->get_EntryDisplayCount((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_EntryDisplayFiles(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryDisplayFiles"), DISPID(113));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::get_EntryDisplayFiles(void)
{
  long Value;
  this->get_EntryDisplayFiles((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_EntryDisplayDirectories(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryDisplayDirectories"), DISPID(114));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::get_EntryDisplayDirectories(void)
{
  long Value;
  this->get_EntryDisplayDirectories((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_DirectoryType(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("DirectoryType"), DISPID(115));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::get_DirectoryType(void)
{
  long Value;
  this->get_DirectoryType((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_SyncView(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("SyncView"), DISPID(150));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::get_SyncView(void)
{
  long Value;
  this->get_SyncView((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::set_SyncView(long Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("SyncView"), DISPID(150));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_I4:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_ModuleVersion(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("ModuleVersion"), DISPID(302));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::get_ModuleVersion(void)
{
  long Value;
  this->get_ModuleVersion((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_EntryState(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryState"), DISPID(13));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::get_EntryState(void)
{
  long Value;
  this->get_EntryState((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::set_EntryState(long Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryState"), DISPID(13));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_I4:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_EntryExtColor(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryExtColor"), DISPID(14));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::get_EntryExtColor(void)
{
  long Value;
  this->get_EntryExtColor((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::set_EntryExtColor(long Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryExtColor"), DISPID(14));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_I4:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_result(BSTR* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("result"), DISPID(15));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BSTR:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> BSTR __fastcall
IPPxDispT<T>::get_result(void)
{
  BSTR Value;
  this->get_result((BSTR*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::set_result(BSTR Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("result"), DISPID(15));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_BSTR:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_Arguments(Ppxscr_tlb::IArguments** Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Arguments"), DISPID(16));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr((LPDISPATCH*)(Ppxscr_tlb::IArguments**)Value /*[VT_USERDEFINED:2]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> Ppxscr_tlb::IArguments* __fastcall
IPPxDispT<T>::get_Arguments(void)
{
  Ppxscr_tlb::IArguments* Value;
  this->get_Arguments((Ppxscr_tlb::IArguments**)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::Quit(long ExitCode/*[in,opt]*/)
{
  _TDispID _dispid(*this, OLETEXT("Quit"), DISPID(6));
  TAutoArgs<1> _args;
  _args[1] = ExitCode /*[VT_I4:0]*/;
  return OleFunction(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_EntryMarkCount(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryMarkCount"), DISPID(17));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::get_EntryMarkCount(void)
{
  long Value;
  this->get_EntryMarkCount((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_Entry(Ppxscr_tlb::IEntry** Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Entry"), DISPID(18));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr((LPDISPATCH*)(Ppxscr_tlb::IEntry**)Value /*[VT_USERDEFINED:2]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> Ppxscr_tlb::IEntry* __fastcall
IPPxDispT<T>::get_Entry(void)
{
  Ppxscr_tlb::IEntry* Value;
  this->get_Entry((Ppxscr_tlb::IEntry**)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_SlowMode(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("SlowMode"), DISPID(19));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::get_SlowMode(void)
{
  long Value;
  this->get_SlowMode((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::set_SlowMode(long Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("SlowMode"), DISPID(19));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_I4:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::GetFileInformation(BSTR FileName/*[in]*/, long Mode/*[in,opt]*/, 
                                 BSTR* Text/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("GetFileInformation"), DISPID(20));
  TAutoArgs<2> _args;
  _args[1] = FileName /*[VT_BSTR:0]*/;
  _args[2] = Mode /*[VT_I4:0]*/;
  return OutRetValSetterPtr(Text /*[VT_BSTR:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> BSTR __fastcall
IPPxDispT<T>::GetFileInformation(BSTR FileName/*[in]*/, long Mode/*[in,opt]*/)
{
  BSTR Text;
  this->GetFileInformation(FileName, Mode, (BSTR*)&Text);
  return Text;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_DriveVolumeLabel(BSTR* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("DriveVolumeLabel"), DISPID(21));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BSTR:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> BSTR __fastcall
IPPxDispT<T>::get_DriveVolumeLabel(void)
{
  BSTR Value;
  this->get_DriveVolumeLabel((BSTR*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_EntryMarkSize(double* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryMarkSize"), DISPID(22));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_R8:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> double __fastcall
IPPxDispT<T>::get_EntryMarkSize(void)
{
  double Value;
  this->get_EntryMarkSize((double*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_DriveTotalSize(double* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("DriveTotalSize"), DISPID(23));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_R8:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> double __fastcall
IPPxDispT<T>::get_DriveTotalSize(void)
{
  double Value;
  this->get_DriveTotalSize((double*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_DriveFreeSize(double* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("DriveFreeSize"), DISPID(24));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_R8:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> double __fastcall
IPPxDispT<T>::get_DriveFreeSize(void)
{
  double Value;
  this->get_DriveFreeSize((double*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::EntryInsert(long index/*[in]*/, BSTR EntryName/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryInsert"), DISPID(25));
  TAutoArgs<2> _args;
  _args[1] = index /*[VT_I4:0]*/;
  _args[2] = EntryName /*[VT_BSTR:0]*/;
  return OleFunction(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_Clipboard(BSTR* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Clipboard"), DISPID(26));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BSTR:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> BSTR __fastcall
IPPxDispT<T>::get_Clipboard(void)
{
  BSTR Value;
  this->get_Clipboard((BSTR*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::set_Clipboard(BSTR Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("Clipboard"), DISPID(26));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_BSTR:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_StayMode(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("StayMode"), DISPID(27));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::get_StayMode(void)
{
  long Value;
  this->get_StayMode((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::set_StayMode(long Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("StayMode"), DISPID(27));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_I4:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_EntryHighlight(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryHighlight"), DISPID(28));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::get_EntryHighlight(void)
{
  long Value;
  this->get_EntryHighlight((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::set_EntryHighlight(long Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryHighlight"), DISPID(28));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_I4:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_Pane(Ppxscr_tlb::IPane** Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Pane"), DISPID(29));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr((LPDISPATCH*)(Ppxscr_tlb::IPane**)Value /*[VT_USERDEFINED:2]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> Ppxscr_tlb::IPane* __fastcall
IPPxDispT<T>::get_Pane(void)
{
  Ppxscr_tlb::IPane* Value;
  this->get_Pane((Ppxscr_tlb::IPane**)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::EntryPrevMark(long* result/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryPrevMark"), DISPID(30));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(result /*[VT_I4:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::EntryPrevMark(void)
{
  long result;
  this->EntryPrevMark((long*)&result);
  return result;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::EntryLastMark(long* result/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("EntryLastMark"), DISPID(31));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(result /*[VT_I4:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::EntryLastMark(void)
{
  long result;
  this->EntryLastMark((long*)&result);
  return result;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::GetComboItemCount(long id/*[in]*/, long* result/*[out]*/)
{
  _TDispID _dispid(*this, OLETEXT("GetComboItemCount"), DISPID(32));
  TAutoArgs<2> _args;
  _args[1] = id /*[VT_I4:0]*/;
  _args[2] = result /*[VT_I4:1]*/;
  return OleFunction(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_ComboIDName(BSTR* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("ComboIDName"), DISPID(33));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BSTR:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> BSTR __fastcall
IPPxDispT<T>::get_ComboIDName(void)
{
  BSTR Value;
  this->get_ComboIDName((BSTR*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_PointType(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("PointType"), DISPID(34));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::get_PointType(void)
{
  long Value;
  this->get_PointType((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_PointIndex(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("PointIndex"), DISPID(35));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::get_PointIndex(void)
{
  long Value;
  this->get_PointIndex((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::Cursor(long x/*[in]*/, long y/*[in,def,opt]*/, long* result/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Cursor"), DISPID(36));
  TAutoArgs<2> _args;
  _args[1] = x /*[VT_I4:0]*/;
  _args[2] = y /*[VT_I4:0]*/;
  return OutRetValSetterPtr(result /*[VT_I4:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::Cursor(long x/*[in]*/, long y/*[in,def,opt]*/)
{
  long result;
  this->Cursor(x, y, (long*)&result);
  return result;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_ScriptEngineName(BSTR* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("ScriptEngineName"), DISPID(37));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BSTR:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> BSTR __fastcall
IPPxDispT<T>::get_ScriptEngineName(void)
{
  BSTR Value;
  this->get_ScriptEngineName((BSTR*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::getValue(BSTR key/*[in]*/, BSTR* result/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("getValue"), DISPID(38));
  TAutoArgs<1> _args;
  _args[1] = key /*[VT_BSTR:0]*/;
  return OutRetValSetterPtr(result /*[VT_BSTR:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> BSTR __fastcall
IPPxDispT<T>::getValue(BSTR key/*[in]*/)
{
  BSTR result;
  this->getValue(key, (BSTR*)&result);
  return result;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::setValue(BSTR key/*[in]*/, BSTR Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("setValue"), DISPID(39));
  TAutoArgs<2> _args;
  _args[1] = key /*[VT_BSTR:0]*/;
  _args[2] = Value /*[VT_BSTR:0]*/;
  return OleFunction(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_ScriptEngineVersion(BSTR* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("ScriptEngineVersion"), DISPID(40));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BSTR:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> BSTR __fastcall
IPPxDispT<T>::get_ScriptEngineVersion(void)
{
  BSTR Value;
  this->get_ScriptEngineVersion((BSTR*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::lineMessage(BSTR Text/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("lineMessage"), DISPID(41));
  TAutoArgs<1> _args;
  _args[1] = Text /*[VT_BSTR:0]*/;
  return OleFunction(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_WindowIDName(BSTR* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("WindowIDName"), DISPID(42));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BSTR:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> BSTR __fastcall
IPPxDispT<T>::get_WindowIDName(void)
{
  BSTR Value;
  this->get_WindowIDName((BSTR*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::set_WindowIDName(BSTR Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("WindowIDName"), DISPID(42));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_BSTR:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::Argument(long itemindex/*[in,def,opt]*/, BSTR* Arg/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Argument"), DISPID(43));
  TAutoArgs<1> _args;
  _args[1] = itemindex /*[VT_I4:0]*/;
  return OutRetValSetterPtr(Arg /*[VT_BSTR:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> BSTR __fastcall
IPPxDispT<T>::Argument(long itemindex/*[in,def,opt]*/)
{
  BSTR Arg;
  this->Argument(itemindex, (BSTR*)&Arg);
  return Arg;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::report(BSTR Text/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("report"), DISPID(44));
  TAutoArgs<1> _args;
  _args[1] = Text /*[VT_BSTR:0]*/;
  return OleFunction(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::log(BSTR Text/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("log"), DISPID(45));
  TAutoArgs<1> _args;
  _args[1] = Text /*[VT_BSTR:0]*/;
  return OleFunction(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::getProcessValue(BSTR key/*[in]*/, BSTR* result/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("getProcessValue"), DISPID(46));
  TAutoArgs<1> _args;
  _args[1] = key /*[VT_BSTR:0]*/;
  return OutRetValSetterPtr(result /*[VT_BSTR:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> BSTR __fastcall
IPPxDispT<T>::getProcessValue(BSTR key/*[in]*/)
{
  BSTR result;
  this->getProcessValue(key, (BSTR*)&result);
  return result;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::setProcessValue(BSTR key/*[in]*/, BSTR Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("setProcessValue"), DISPID(48));
  TAutoArgs<2> _args;
  _args[1] = key /*[VT_BSTR:0]*/;
  _args[2] = Value /*[VT_BSTR:0]*/;
  return OleFunction(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::getIValue(BSTR key/*[in]*/, BSTR* result/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("getIValue"), DISPID(49));
  TAutoArgs<1> _args;
  _args[1] = key /*[VT_BSTR:0]*/;
  return OutRetValSetterPtr(result /*[VT_BSTR:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> BSTR __fastcall
IPPxDispT<T>::getIValue(BSTR key/*[in]*/)
{
  BSTR result;
  this->getIValue(key, (BSTR*)&result);
  return result;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::setIValue(BSTR key/*[in]*/, BSTR Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("setIValue"), DISPID(50));
  TAutoArgs<2> _args;
  _args[1] = key /*[VT_BSTR:0]*/;
  _args[2] = Value /*[VT_BSTR:0]*/;
  return OleFunction(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::Enumerator(LPDISPATCH object/*[in]*/, LPDISPATCH* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Enumerator"), DISPID(51));
  TAutoArgs<1> _args;
  _args[1] = object /*[VT_DISPATCH:0]*/;
  return OutRetValSetterPtr(Value /*[VT_DISPATCH:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> LPDISPATCH __fastcall
IPPxDispT<T>::Enumerator(LPDISPATCH object/*[in]*/)
{
  LPDISPATCH Value;
  this->Enumerator(object, (LPDISPATCH*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::Include(BSTR FileName/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("Include"), DISPID(47));
  TAutoArgs<1> _args;
  _args[1] = FileName /*[VT_BSTR:0]*/;
  return OleFunction(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::get_ReentryCount(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("ReentryCount"), DISPID(52));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxDispT<T>::get_ReentryCount(void)
{
  long Value;
  this->get_ReentryCount((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxDispT<T>::option(BSTR name/*[in]*/, VARIANT param/*[in,opt]*/, VARIANT* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("option"), DISPID(53));
  TAutoArgs<2> _args;
  _args[1] = name /*[VT_BSTR:0]*/;
  _args[2] = param /*[VT_VARIANT:0]*/;
  return OutRetValSetterPtr(Value /*[VT_VARIANT:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> VARIANT __fastcall
IPPxDispT<T>::option(BSTR name/*[in]*/, VARIANT param/*[in,opt]*/)
{
  VARIANT Value;
  this->option(name, param, (VARIANT*)&Value);
  return Value;
}

// *********************************************************************//
// SmartIntf: TCOMIArguments
// Interface: IArguments
// *********************************************************************//
template <class T> HRESULT __fastcall
TCOMIArgumentsT<T>::Item(long index/*[in,opt]*/, BSTR* out_Value/*[out,retval]*/)
{
  return (*this)->Item(index, out_Value);
}

template <class T> BSTR __fastcall
TCOMIArgumentsT<T>::Item(long index/*[in,opt]*/)
{
  BSTR out_Value = 0;
  OLECHECK(this->Item(, (BSTR*)&out_Value));
  return out_Value;
}

template <class T> HRESULT __fastcall
TCOMIArgumentsT<T>::get__NewEnum(LPUNKNOWN* out_Enum/*[out,retval]*/)
{
  return (*this)->get__NewEnum(out_Enum);
}

template <class T> LPUNKNOWN __fastcall
TCOMIArgumentsT<T>::get__NewEnum(void)
{
  LPUNKNOWN out_Enum;
  OLECHECK(this->get__NewEnum((LPUNKNOWN*)&out_Enum));
  return out_Enum;
}

template <class T> HRESULT __fastcall
TCOMIArgumentsT<T>::get_Count(long* Value/*[out,retval]*/)
{
  return (*this)->get_Count(Value);
}

template <class T> long __fastcall
TCOMIArgumentsT<T>::get_Count(void)
{
  long Value;
  OLECHECK(this->get_Count((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIArgumentsT<T>::get_length(long* Value/*[out,retval]*/)
{
  return (*this)->get_length(Value);
}

template <class T> long __fastcall
TCOMIArgumentsT<T>::get_length(void)
{
  long Value;
  OLECHECK(this->get_length((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIArgumentsT<T>::Reset(void)
{
  return (*this)->Reset();
}

template <class T> HRESULT __fastcall
TCOMIArgumentsT<T>::moveNext(long* Value/*[out,retval]*/)
{
  return (*this)->moveNext(Value);
}

template <class T> long __fastcall
TCOMIArgumentsT<T>::moveNext(void)
{
  long Value;
  OLECHECK(this->moveNext((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIArgumentsT<T>::atEnd(long* Value/*[out,retval]*/)
{
  return (*this)->atEnd(Value);
}

template <class T> long __fastcall
TCOMIArgumentsT<T>::atEnd(void)
{
  long Value;
  OLECHECK(this->atEnd((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIArgumentsT<T>::get_Current(Ppxscr_tlb::IArguments** Value/*[out,retval]*/)
{
  return (*this)->get_Current(Value);
}

template <class T> HRESULT __fastcall
TCOMIArgumentsT<T>::get_Current(Ppxscr_tlb::IArgumentsPtr* Value/*[out,retval]*/)
{
  return (*this)->get_Current(IArguments**)Value);
}

template <class T> Ppxscr_tlb::IArgumentsPtr __fastcall
TCOMIArgumentsT<T>::get_Current(void)
{
  Ppxscr_tlb::IArguments* Value;
  OLECHECK(this->get_Current((Ppxscr_tlb::IArguments**)&Value));
  return (Ppxscr_tlb::IArgumentsPtr)Value;
}

template <class T> HRESULT __fastcall
TCOMIArgumentsT<T>::get_Value(BSTR* Value/*[out,retval]*/)
{
  return (*this)->get_Value(Value);
}

template <class T> BSTR __fastcall
TCOMIArgumentsT<T>::get_Value(void)
{
  BSTR Value = 0;
  OLECHECK(this->get_Value((BSTR*)&Value));
  return Value;
}

// *********************************************************************//
// DispIntf:  IArguments
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {29BA7411-9168-4B39-B878-B6181C782884}
// *********************************************************************//
template <class T> HRESULT __fastcall
IArgumentsDispT<T>::Item(long index/*[in,opt]*/, BSTR* out_Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Item"), DISPID(0));
  TAutoArgs<1> _args;
  _args[1] = index /*[VT_I4:0]*/;
  return OutRetValSetterPtr(out_Value /*[VT_BSTR:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> BSTR __fastcall
IArgumentsDispT<T>::Item(long index/*[in,opt]*/)
{
  BSTR out_Value;
  this->Item(index, (BSTR*)&out_Value);
  return out_Value;
}

template <class T> HRESULT __fastcall
IArgumentsDispT<T>::get__NewEnum(LPUNKNOWN* out_Enum/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("_NewEnum"), DISPID(-4));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(out_Enum /*[VT_UNKNOWN:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> LPUNKNOWN __fastcall
IArgumentsDispT<T>::get__NewEnum(void)
{
  LPUNKNOWN out_Enum;
  this->get__NewEnum((LPUNKNOWN*)&out_Enum);
  return out_Enum;
}

template <class T> HRESULT __fastcall
IArgumentsDispT<T>::get_Count(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Count"), DISPID(1));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IArgumentsDispT<T>::get_Count(void)
{
  long Value;
  this->get_Count((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IArgumentsDispT<T>::get_length(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("length"), DISPID(6));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IArgumentsDispT<T>::get_length(void)
{
  long Value;
  this->get_length((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IArgumentsDispT<T>::Reset()
{
  _TDispID _dispid(*this, OLETEXT("Reset"), DISPID(2));
  return OleFunction(_dispid);
}

template <class T> HRESULT __fastcall
IArgumentsDispT<T>::moveNext(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("moveNext"), DISPID(3));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> long __fastcall
IArgumentsDispT<T>::moveNext(void)
{
  long Value;
  this->moveNext((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IArgumentsDispT<T>::atEnd(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("atEnd"), DISPID(4));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> long __fastcall
IArgumentsDispT<T>::atEnd(void)
{
  long Value;
  this->atEnd((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IArgumentsDispT<T>::get_Current(Ppxscr_tlb::IArguments** Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Current"), DISPID(5));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr((LPDISPATCH*)(Ppxscr_tlb::IArguments**)Value /*[VT_USERDEFINED:2]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> Ppxscr_tlb::IArguments* __fastcall
IArgumentsDispT<T>::get_Current(void)
{
  Ppxscr_tlb::IArguments* Value;
  this->get_Current((Ppxscr_tlb::IArguments**)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IArgumentsDispT<T>::get_Value(BSTR* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Value"), DISPID(7));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BSTR:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> BSTR __fastcall
IArgumentsDispT<T>::get_Value(void)
{
  BSTR Value;
  this->get_Value((BSTR*)&Value);
  return Value;
}

// *********************************************************************//
// SmartIntf: TCOMIEntry
// Interface: IEntry
// *********************************************************************//
template <class T> HRESULT __fastcall
TCOMIEntryT<T>::Item(long index/*[in,opt]*/, Ppxscr_tlb::IEntry** out_Value/*[out,retval]*/)
{
  return (*this)->Item(index, out_Value);
}

template <class T> Ppxscr_tlb::IEntry* __fastcall
TCOMIEntryT<T>::Item(long index/*[in,opt]*/)
{
  Ppxscr_tlb::IEntry* out_Value;
  OLECHECK(this->Item(, (Ppxscr_tlb::IEntry**)&out_Value));
  return out_Value;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::get__NewEnum(LPUNKNOWN* out_Enum/*[out,retval]*/)
{
  return (*this)->get__NewEnum(out_Enum);
}

template <class T> LPUNKNOWN __fastcall
TCOMIEntryT<T>::get__NewEnum(void)
{
  LPUNKNOWN out_Enum;
  OLECHECK(this->get__NewEnum((LPUNKNOWN*)&out_Enum));
  return out_Enum;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::get_Count(long* Value/*[out,retval]*/)
{
  return (*this)->get_Count(Value);
}

template <class T> long __fastcall
TCOMIEntryT<T>::get_Count(void)
{
  long Value;
  OLECHECK(this->get_Count((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::get_Name(BSTR* Value/*[out,retval]*/)
{
  return (*this)->get_Name(Value);
}

template <class T> BSTR __fastcall
TCOMIEntryT<T>::get_Name(void)
{
  BSTR Value = 0;
  OLECHECK(this->get_Name((BSTR*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::get_index(long* Value/*[out,retval]*/)
{
  return (*this)->get_index(Value);
}

template <class T> long __fastcall
TCOMIEntryT<T>::get_index(void)
{
  long Value;
  OLECHECK(this->get_index((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::set_index(long Value/*[in]*/)
{
  return (*this)->set_index(Value);
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::get_Mark(long* Value/*[out,retval]*/)
{
  return (*this)->get_Mark(Value);
}

template <class T> long __fastcall
TCOMIEntryT<T>::get_Mark(void)
{
  long Value;
  OLECHECK(this->get_Mark((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::set_Mark(long Value/*[in]*/)
{
  return (*this)->set_Mark(Value);
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::get_Comment(BSTR* Value/*[out,retval]*/)
{
  return (*this)->get_Comment(Value);
}

template <class T> BSTR __fastcall
TCOMIEntryT<T>::get_Comment(void)
{
  BSTR Value = 0;
  OLECHECK(this->get_Comment((BSTR*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::set_Comment(BSTR Value/*[in]*/)
{
  return (*this)->set_Comment(Value);
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::get_Attributes(long* Value/*[out,retval]*/)
{
  return (*this)->get_Attributes(Value);
}

template <class T> long __fastcall
TCOMIEntryT<T>::get_Attributes(void)
{
  long Value;
  OLECHECK(this->get_Attributes((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::get_Size(double* Value/*[out,retval]*/)
{
  return (*this)->get_Size(Value);
}

template <class T> double __fastcall
TCOMIEntryT<T>::get_Size(void)
{
  double Value;
  OLECHECK(this->get_Size((double*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::get_State(long* Value/*[out,retval]*/)
{
  return (*this)->get_State(Value);
}

template <class T> long __fastcall
TCOMIEntryT<T>::get_State(void)
{
  long Value;
  OLECHECK(this->get_State((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::set_State(long Value/*[in]*/)
{
  return (*this)->set_State(Value);
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::get_ExtColor(long* Value/*[out,retval]*/)
{
  return (*this)->get_ExtColor(Value);
}

template <class T> long __fastcall
TCOMIEntryT<T>::get_ExtColor(void)
{
  long Value;
  OLECHECK(this->get_ExtColor((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::set_ExtColor(long Value/*[in]*/)
{
  return (*this)->set_ExtColor(Value);
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::get_length(long* Value/*[out,retval]*/)
{
  return (*this)->get_length(Value);
}

template <class T> long __fastcall
TCOMIEntryT<T>::get_length(void)
{
  long Value;
  OLECHECK(this->get_length((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::get_DateCreated(DATE* Value/*[out,retval]*/)
{
  return (*this)->get_DateCreated(Value);
}

template <class T> DATE __fastcall
TCOMIEntryT<T>::get_DateCreated(void)
{
  DATE Value;
  OLECHECK(this->get_DateCreated((DATE*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::get_DateLastAccessed(DATE* Value/*[out,retval]*/)
{
  return (*this)->get_DateLastAccessed(Value);
}

template <class T> DATE __fastcall
TCOMIEntryT<T>::get_DateLastAccessed(void)
{
  DATE Value;
  OLECHECK(this->get_DateLastAccessed((DATE*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::get_DateLastModified(DATE* Value/*[out,retval]*/)
{
  return (*this)->get_DateLastModified(Value);
}

template <class T> DATE __fastcall
TCOMIEntryT<T>::get_DateLastModified(void)
{
  DATE Value;
  OLECHECK(this->get_DateLastModified((DATE*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::get_ShortName(BSTR* Value/*[out,retval]*/)
{
  return (*this)->get_ShortName(Value);
}

template <class T> BSTR __fastcall
TCOMIEntryT<T>::get_ShortName(void)
{
  BSTR Value = 0;
  OLECHECK(this->get_ShortName((BSTR*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::get_Highlight(long* Value/*[out,retval]*/)
{
  return (*this)->get_Highlight(Value);
}

template <class T> long __fastcall
TCOMIEntryT<T>::get_Highlight(void)
{
  long Value;
  OLECHECK(this->get_Highlight((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::set_Highlight(long Value/*[in]*/)
{
  return (*this)->set_Highlight(Value);
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::NextMark(long* result/*[out,retval]*/)
{
  return (*this)->NextMark(result);
}

template <class T> long __fastcall
TCOMIEntryT<T>::NextMark(void)
{
  long result;
  OLECHECK(this->NextMark((long*)&result));
  return result;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::PrevMark(long* result/*[out,retval]*/)
{
  return (*this)->PrevMark(result);
}

template <class T> long __fastcall
TCOMIEntryT<T>::PrevMark(void)
{
  long result;
  OLECHECK(this->PrevMark((long*)&result));
  return result;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::Hide(void)
{
  return (*this)->Hide();
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::FirstMark(long* result/*[out,retval]*/)
{
  return (*this)->FirstMark(result);
}

template <class T> long __fastcall
TCOMIEntryT<T>::FirstMark(void)
{
  long result;
  OLECHECK(this->FirstMark((long*)&result));
  return result;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::LastMark(long* result/*[out,retval]*/)
{
  return (*this)->LastMark(result);
}

template <class T> long __fastcall
TCOMIEntryT<T>::LastMark(void)
{
  long result;
  OLECHECK(this->LastMark((long*)&result));
  return result;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::Information(BSTR* Value/*[out,retval]*/)
{
  return (*this)->Information(Value);
}

template <class T> BSTR __fastcall
TCOMIEntryT<T>::Information(void)
{
  BSTR Value = 0;
  OLECHECK(this->Information((BSTR*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::GetComment(long id/*[in,opt]*/, BSTR* Value/*[out,retval]*/)
{
  return (*this)->GetComment(id, Value);
}

template <class T> BSTR __fastcall
TCOMIEntryT<T>::GetComment(long id/*[in,opt]*/)
{
  BSTR Value = 0;
  OLECHECK(this->GetComment(, (BSTR*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::SetComment(long id/*[in]*/, BSTR Value/*[in]*/)
{
  return (*this)->SetComment(id, Value);
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::Reset(void)
{
  return (*this)->Reset();
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::moveNext(long* Value/*[out,retval]*/)
{
  return (*this)->moveNext(Value);
}

template <class T> long __fastcall
TCOMIEntryT<T>::moveNext(void)
{
  long Value;
  OLECHECK(this->moveNext((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::get_AllMark(Ppxscr_tlb::IEntry** out_Value/*[out,retval]*/)
{
  return (*this)->get_AllMark(out_Value);
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::get_AllMark(Ppxscr_tlb::IEntryPtr* out_Value/*[out,retval]*/)
{
  return (*this)->get_AllMark(IEntry**)out_Value);
}

template <class T> Ppxscr_tlb::IEntryPtr __fastcall
TCOMIEntryT<T>::get_AllMark(void)
{
  Ppxscr_tlb::IEntry* out_Value;
  OLECHECK(this->get_AllMark((Ppxscr_tlb::IEntry**)&out_Value));
  return (Ppxscr_tlb::IEntryPtr)out_Value;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::get_AllEntry(Ppxscr_tlb::IEntry** out_Value/*[out,retval]*/)
{
  return (*this)->get_AllEntry(out_Value);
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::get_AllEntry(Ppxscr_tlb::IEntryPtr* out_Value/*[out,retval]*/)
{
  return (*this)->get_AllEntry(IEntry**)out_Value);
}

template <class T> Ppxscr_tlb::IEntryPtr __fastcall
TCOMIEntryT<T>::get_AllEntry(void)
{
  Ppxscr_tlb::IEntry* out_Value;
  OLECHECK(this->get_AllEntry((Ppxscr_tlb::IEntry**)&out_Value));
  return (Ppxscr_tlb::IEntryPtr)out_Value;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::atEnd(long* Value/*[out,retval]*/)
{
  return (*this)->atEnd(Value);
}

template <class T> long __fastcall
TCOMIEntryT<T>::atEnd(void)
{
  long Value;
  OLECHECK(this->atEnd((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::get_Current(Ppxscr_tlb::IEntry** Value/*[out,retval]*/)
{
  return (*this)->get_Current(Value);
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::get_Current(Ppxscr_tlb::IEntryPtr* Value/*[out,retval]*/)
{
  return (*this)->get_Current(IEntry**)Value);
}

template <class T> Ppxscr_tlb::IEntryPtr __fastcall
TCOMIEntryT<T>::get_Current(void)
{
  Ppxscr_tlb::IEntry* Value;
  OLECHECK(this->get_Current((Ppxscr_tlb::IEntry**)&Value));
  return (Ppxscr_tlb::IEntryPtr)Value;
}

template <class T> HRESULT __fastcall
TCOMIEntryT<T>::IndexFrom(BSTR Name/*[in]*/, long* moved/*[out,retval]*/)
{
  return (*this)->IndexFrom(Name, moved);
}

template <class T> long __fastcall
TCOMIEntryT<T>::IndexFrom(BSTR Name/*[in]*/)
{
  long moved;
  OLECHECK(this->IndexFrom(, (long*)&moved));
  return moved;
}

// *********************************************************************//
// DispIntf:  IEntry
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {E64F28F2-F656-4F61-8CA7-2F4F97AB25FF}
// *********************************************************************//
template <class T> HRESULT __fastcall
IEntryDispT<T>::Item(long index/*[in,opt]*/, Ppxscr_tlb::IEntry** out_Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Item"), DISPID(0));
  TAutoArgs<1> _args;
  _args[1] = index /*[VT_I4:0]*/;
  return OutRetValSetterPtr((LPDISPATCH*)(Ppxscr_tlb::IEntry**)out_Value /*[VT_USERDEFINED:2]*/, _args, OleFunction(_dispid, _args));
}

template <class T> Ppxscr_tlb::IEntry* __fastcall
IEntryDispT<T>::Item(long index/*[in,opt]*/)
{
  Ppxscr_tlb::IEntry* out_Value;
  this->Item(index, (Ppxscr_tlb::IEntry**)&out_Value);
  return out_Value;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::get__NewEnum(LPUNKNOWN* out_Enum/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("_NewEnum"), DISPID(-4));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(out_Enum /*[VT_UNKNOWN:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> LPUNKNOWN __fastcall
IEntryDispT<T>::get__NewEnum(void)
{
  LPUNKNOWN out_Enum;
  this->get__NewEnum((LPUNKNOWN*)&out_Enum);
  return out_Enum;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::get_Count(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Count"), DISPID(1));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IEntryDispT<T>::get_Count(void)
{
  long Value;
  this->get_Count((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::get_Name(BSTR* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Name"), DISPID(5));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BSTR:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> BSTR __fastcall
IEntryDispT<T>::get_Name(void)
{
  BSTR Value;
  this->get_Name((BSTR*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::get_index(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("index"), DISPID(6));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IEntryDispT<T>::get_index(void)
{
  long Value;
  this->get_index((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::set_index(long Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("index"), DISPID(6));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_I4:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::get_Mark(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Mark"), DISPID(7));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IEntryDispT<T>::get_Mark(void)
{
  long Value;
  this->get_Mark((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::set_Mark(long Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("Mark"), DISPID(7));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_I4:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::get_Comment(BSTR* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Comment"), DISPID(8));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BSTR:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> BSTR __fastcall
IEntryDispT<T>::get_Comment(void)
{
  BSTR Value;
  this->get_Comment((BSTR*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::set_Comment(BSTR Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("Comment"), DISPID(8));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_BSTR:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::get_Attributes(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Attributes"), DISPID(9));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IEntryDispT<T>::get_Attributes(void)
{
  long Value;
  this->get_Attributes((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::get_Size(double* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Size"), DISPID(10));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_R8:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> double __fastcall
IEntryDispT<T>::get_Size(void)
{
  double Value;
  this->get_Size((double*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::get_State(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("State"), DISPID(11));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IEntryDispT<T>::get_State(void)
{
  long Value;
  this->get_State((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::set_State(long Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("State"), DISPID(11));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_I4:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::get_ExtColor(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("ExtColor"), DISPID(12));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IEntryDispT<T>::get_ExtColor(void)
{
  long Value;
  this->get_ExtColor((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::set_ExtColor(long Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("ExtColor"), DISPID(12));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_I4:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::get_length(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("length"), DISPID(2));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IEntryDispT<T>::get_length(void)
{
  long Value;
  this->get_length((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::get_DateCreated(DATE* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("DateCreated"), DISPID(15));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_DATE:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> DATE __fastcall
IEntryDispT<T>::get_DateCreated(void)
{
  DATE Value;
  this->get_DateCreated((DATE*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::get_DateLastAccessed(DATE* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("DateLastAccessed"), DISPID(16));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_DATE:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> DATE __fastcall
IEntryDispT<T>::get_DateLastAccessed(void)
{
  DATE Value;
  this->get_DateLastAccessed((DATE*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::get_DateLastModified(DATE* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("DateLastModified"), DISPID(17));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_DATE:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> DATE __fastcall
IEntryDispT<T>::get_DateLastModified(void)
{
  DATE Value;
  this->get_DateLastModified((DATE*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::get_ShortName(BSTR* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("ShortName"), DISPID(18));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BSTR:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> BSTR __fastcall
IEntryDispT<T>::get_ShortName(void)
{
  BSTR Value;
  this->get_ShortName((BSTR*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::get_Highlight(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Highlight"), DISPID(3));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IEntryDispT<T>::get_Highlight(void)
{
  long Value;
  this->get_Highlight((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::set_Highlight(long Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("Highlight"), DISPID(3));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_I4:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::NextMark(long* result/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("NextMark"), DISPID(13));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(result /*[VT_I4:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> long __fastcall
IEntryDispT<T>::NextMark(void)
{
  long result;
  this->NextMark((long*)&result);
  return result;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::PrevMark(long* result/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("PrevMark"), DISPID(14));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(result /*[VT_I4:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> long __fastcall
IEntryDispT<T>::PrevMark(void)
{
  long result;
  this->PrevMark((long*)&result);
  return result;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::Hide()
{
  _TDispID _dispid(*this, OLETEXT("Hide"), DISPID(4));
  return OleFunction(_dispid);
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::FirstMark(long* result/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("FirstMark"), DISPID(20));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(result /*[VT_I4:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> long __fastcall
IEntryDispT<T>::FirstMark(void)
{
  long result;
  this->FirstMark((long*)&result);
  return result;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::LastMark(long* result/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("LastMark"), DISPID(21));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(result /*[VT_I4:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> long __fastcall
IEntryDispT<T>::LastMark(void)
{
  long result;
  this->LastMark((long*)&result);
  return result;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::Information(BSTR* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Information"), DISPID(19));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BSTR:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> BSTR __fastcall
IEntryDispT<T>::Information(void)
{
  BSTR Value;
  this->Information((BSTR*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::GetComment(long id/*[in,opt]*/, BSTR* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("GetComment"), DISPID(22));
  TAutoArgs<1> _args;
  _args[1] = id /*[VT_I4:0]*/;
  return OutRetValSetterPtr(Value /*[VT_BSTR:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> BSTR __fastcall
IEntryDispT<T>::GetComment(long id/*[in,opt]*/)
{
  BSTR Value;
  this->GetComment(id, (BSTR*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::SetComment(long id/*[in]*/, BSTR Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("SetComment"), DISPID(23));
  TAutoArgs<2> _args;
  _args[1] = id /*[VT_I4:0]*/;
  _args[2] = Value /*[VT_BSTR:0]*/;
  return OleFunction(_dispid, _args);
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::Reset()
{
  _TDispID _dispid(*this, OLETEXT("Reset"), DISPID(24));
  return OleFunction(_dispid);
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::moveNext(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("moveNext"), DISPID(25));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> long __fastcall
IEntryDispT<T>::moveNext(void)
{
  long Value;
  this->moveNext((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::get_AllMark(Ppxscr_tlb::IEntry** out_Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("AllMark"), DISPID(26));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr((LPDISPATCH*)(Ppxscr_tlb::IEntry**)out_Value /*[VT_USERDEFINED:2]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> Ppxscr_tlb::IEntry* __fastcall
IEntryDispT<T>::get_AllMark(void)
{
  Ppxscr_tlb::IEntry* out_Value;
  this->get_AllMark((Ppxscr_tlb::IEntry**)&out_Value);
  return out_Value;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::get_AllEntry(Ppxscr_tlb::IEntry** out_Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("AllEntry"), DISPID(27));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr((LPDISPATCH*)(Ppxscr_tlb::IEntry**)out_Value /*[VT_USERDEFINED:2]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> Ppxscr_tlb::IEntry* __fastcall
IEntryDispT<T>::get_AllEntry(void)
{
  Ppxscr_tlb::IEntry* out_Value;
  this->get_AllEntry((Ppxscr_tlb::IEntry**)&out_Value);
  return out_Value;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::atEnd(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("atEnd"), DISPID(28));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> long __fastcall
IEntryDispT<T>::atEnd(void)
{
  long Value;
  this->atEnd((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::get_Current(Ppxscr_tlb::IEntry** Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Current"), DISPID(29));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr((LPDISPATCH*)(Ppxscr_tlb::IEntry**)Value /*[VT_USERDEFINED:2]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> Ppxscr_tlb::IEntry* __fastcall
IEntryDispT<T>::get_Current(void)
{
  Ppxscr_tlb::IEntry* Value;
  this->get_Current((Ppxscr_tlb::IEntry**)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEntryDispT<T>::IndexFrom(BSTR Name/*[in]*/, long* moved/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("IndexFrom"), DISPID(30));
  TAutoArgs<1> _args;
  _args[1] = Name /*[VT_BSTR:0]*/;
  return OutRetValSetterPtr(moved /*[VT_I4:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> long __fastcall
IEntryDispT<T>::IndexFrom(BSTR Name/*[in]*/)
{
  long moved;
  this->IndexFrom(Name, (long*)&moved);
  return moved;
}

// *********************************************************************//
// SmartIntf: TCOMIPane
// Interface: IPane
// *********************************************************************//
template <class T> HRESULT __fastcall
TCOMIPaneT<T>::Item(long index/*[in,opt]*/, Ppxscr_tlb::IPane** Value/*[out,retval]*/)
{
  return (*this)->Item(index, Value);
}

template <class T> Ppxscr_tlb::IPane* __fastcall
TCOMIPaneT<T>::Item(long index/*[in,opt]*/)
{
  Ppxscr_tlb::IPane* Value;
  OLECHECK(this->Item(, (Ppxscr_tlb::IPane**)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPaneT<T>::get__NewEnum(LPUNKNOWN* out_Enum/*[out,retval]*/)
{
  return (*this)->get__NewEnum(out_Enum);
}

template <class T> LPUNKNOWN __fastcall
TCOMIPaneT<T>::get__NewEnum(void)
{
  LPUNKNOWN out_Enum;
  OLECHECK(this->get__NewEnum((LPUNKNOWN*)&out_Enum));
  return out_Enum;
}

template <class T> HRESULT __fastcall
TCOMIPaneT<T>::get_Count(long* Value/*[out,retval]*/)
{
  return (*this)->get_Count(Value);
}

template <class T> long __fastcall
TCOMIPaneT<T>::get_Count(void)
{
  long Value;
  OLECHECK(this->get_Count((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPaneT<T>::get_length(long* Value/*[out,retval]*/)
{
  return (*this)->get_length(Value);
}

template <class T> long __fastcall
TCOMIPaneT<T>::get_length(void)
{
  long Value;
  OLECHECK(this->get_length((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPaneT<T>::get_index(long* Value/*[out,retval]*/)
{
  return (*this)->get_index(Value);
}

template <class T> long __fastcall
TCOMIPaneT<T>::get_index(void)
{
  long Value;
  OLECHECK(this->get_index((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPaneT<T>::set_index(long Value/*[in]*/)
{
  return (*this)->set_index(Value);
}

template <class T> HRESULT __fastcall
TCOMIPaneT<T>::get_Name(BSTR* Value/*[out,retval]*/)
{
  return (*this)->get_Name(Value);
}

template <class T> BSTR __fastcall
TCOMIPaneT<T>::get_Name(void)
{
  BSTR Value = 0;
  OLECHECK(this->get_Name((BSTR*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPaneT<T>::set_Name(BSTR Value/*[in]*/)
{
  return (*this)->set_Name(Value);
}

template <class T> HRESULT __fastcall
TCOMIPaneT<T>::get_Tab(Ppxscr_tlb::ITab** Value/*[out,retval]*/)
{
  return (*this)->get_Tab(Value);
}

template <class T> HRESULT __fastcall
TCOMIPaneT<T>::get_Tab(Ppxscr_tlb::ITabPtr* Value/*[out,retval]*/)
{
  return (*this)->get_Tab(ITab**)Value);
}

template <class T> Ppxscr_tlb::ITabPtr __fastcall
TCOMIPaneT<T>::get_Tab(void)
{
  Ppxscr_tlb::ITab* Value;
  OLECHECK(this->get_Tab((Ppxscr_tlb::ITab**)&Value));
  return (Ppxscr_tlb::ITabPtr)Value;
}

template <class T> HRESULT __fastcall
TCOMIPaneT<T>::Reset(void)
{
  return (*this)->Reset();
}

template <class T> HRESULT __fastcall
TCOMIPaneT<T>::moveNext(long* Value/*[out,retval]*/)
{
  return (*this)->moveNext(Value);
}

template <class T> long __fastcall
TCOMIPaneT<T>::moveNext(void)
{
  long Value;
  OLECHECK(this->moveNext((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPaneT<T>::atEnd(long* Value/*[out,retval]*/)
{
  return (*this)->atEnd(Value);
}

template <class T> long __fastcall
TCOMIPaneT<T>::atEnd(void)
{
  long Value;
  OLECHECK(this->atEnd((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPaneT<T>::get_Current(Ppxscr_tlb::IPane** Value/*[out,retval]*/)
{
  return (*this)->get_Current(Value);
}

template <class T> HRESULT __fastcall
TCOMIPaneT<T>::get_Current(Ppxscr_tlb::IPanePtr* Value/*[out,retval]*/)
{
  return (*this)->get_Current(IPane**)Value);
}

template <class T> Ppxscr_tlb::IPanePtr __fastcall
TCOMIPaneT<T>::get_Current(void)
{
  Ppxscr_tlb::IPane* Value;
  OLECHECK(this->get_Current((Ppxscr_tlb::IPane**)&Value));
  return (Ppxscr_tlb::IPanePtr)Value;
}

template <class T> HRESULT __fastcall
TCOMIPaneT<T>::IndexFrom(BSTR ppcid/*[in]*/, long* moved/*[out,retval]*/)
{
  return (*this)->IndexFrom(ppcid, moved);
}

template <class T> long __fastcall
TCOMIPaneT<T>::IndexFrom(BSTR ppcid/*[in]*/)
{
  long moved;
  OLECHECK(this->IndexFrom(, (long*)&moved));
  return moved;
}

// *********************************************************************//
// DispIntf:  IPane
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {A682BC0E-0D72-4D56-8818-FE2E0E49AE85}
// *********************************************************************//
template <class T> HRESULT __fastcall
IPaneDispT<T>::Item(long index/*[in,opt]*/, Ppxscr_tlb::IPane** Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Item"), DISPID(0));
  TAutoArgs<1> _args;
  _args[1] = index /*[VT_I4:0]*/;
  return OutRetValSetterPtr((LPDISPATCH*)(Ppxscr_tlb::IPane**)Value /*[VT_USERDEFINED:2]*/, _args, OleFunction(_dispid, _args));
}

template <class T> Ppxscr_tlb::IPane* __fastcall
IPaneDispT<T>::Item(long index/*[in,opt]*/)
{
  Ppxscr_tlb::IPane* Value;
  this->Item(index, (Ppxscr_tlb::IPane**)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPaneDispT<T>::get__NewEnum(LPUNKNOWN* out_Enum/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("_NewEnum"), DISPID(-4));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(out_Enum /*[VT_UNKNOWN:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> LPUNKNOWN __fastcall
IPaneDispT<T>::get__NewEnum(void)
{
  LPUNKNOWN out_Enum;
  this->get__NewEnum((LPUNKNOWN*)&out_Enum);
  return out_Enum;
}

template <class T> HRESULT __fastcall
IPaneDispT<T>::get_Count(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Count"), DISPID(1));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPaneDispT<T>::get_Count(void)
{
  long Value;
  this->get_Count((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPaneDispT<T>::get_length(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("length"), DISPID(6));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPaneDispT<T>::get_length(void)
{
  long Value;
  this->get_length((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPaneDispT<T>::get_index(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("index"), DISPID(2));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPaneDispT<T>::get_index(void)
{
  long Value;
  this->get_index((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPaneDispT<T>::set_index(long Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("index"), DISPID(2));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_I4:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPaneDispT<T>::get_Name(BSTR* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Name"), DISPID(3));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BSTR:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> BSTR __fastcall
IPaneDispT<T>::get_Name(void)
{
  BSTR Value;
  this->get_Name((BSTR*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPaneDispT<T>::set_Name(BSTR Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("Name"), DISPID(3));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_BSTR:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IPaneDispT<T>::get_Tab(Ppxscr_tlb::ITab** Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Tab"), DISPID(7));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr((LPDISPATCH*)(Ppxscr_tlb::ITab**)Value /*[VT_USERDEFINED:2]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> Ppxscr_tlb::ITab* __fastcall
IPaneDispT<T>::get_Tab(void)
{
  Ppxscr_tlb::ITab* Value;
  this->get_Tab((Ppxscr_tlb::ITab**)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPaneDispT<T>::Reset()
{
  _TDispID _dispid(*this, OLETEXT("Reset"), DISPID(4));
  return OleFunction(_dispid);
}

template <class T> HRESULT __fastcall
IPaneDispT<T>::moveNext(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("moveNext"), DISPID(5));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> long __fastcall
IPaneDispT<T>::moveNext(void)
{
  long Value;
  this->moveNext((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPaneDispT<T>::atEnd(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("atEnd"), DISPID(9));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> long __fastcall
IPaneDispT<T>::atEnd(void)
{
  long Value;
  this->atEnd((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPaneDispT<T>::get_Current(Ppxscr_tlb::IPane** Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Current"), DISPID(10));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr((LPDISPATCH*)(Ppxscr_tlb::IPane**)Value /*[VT_USERDEFINED:2]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> Ppxscr_tlb::IPane* __fastcall
IPaneDispT<T>::get_Current(void)
{
  Ppxscr_tlb::IPane* Value;
  this->get_Current((Ppxscr_tlb::IPane**)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPaneDispT<T>::IndexFrom(BSTR ppcid/*[in]*/, long* moved/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("IndexFrom"), DISPID(8));
  TAutoArgs<1> _args;
  _args[1] = ppcid /*[VT_BSTR:0]*/;
  return OutRetValSetterPtr(moved /*[VT_I4:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> long __fastcall
IPaneDispT<T>::IndexFrom(BSTR ppcid/*[in]*/)
{
  long moved;
  this->IndexFrom(ppcid, (long*)&moved);
  return moved;
}

// *********************************************************************//
// SmartIntf: TCOMITab
// Interface: ITab
// *********************************************************************//
template <class T> HRESULT __fastcall
TCOMITabT<T>::Item(long index/*[in,opt]*/, Ppxscr_tlb::ITab** Value/*[out,retval]*/)
{
  return (*this)->Item(index, Value);
}

template <class T> Ppxscr_tlb::ITab* __fastcall
TCOMITabT<T>::Item(long index/*[in,opt]*/)
{
  Ppxscr_tlb::ITab* Value;
  OLECHECK(this->Item(, (Ppxscr_tlb::ITab**)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::get__NewEnum(LPUNKNOWN* out_Enum/*[out,retval]*/)
{
  return (*this)->get__NewEnum(out_Enum);
}

template <class T> LPUNKNOWN __fastcall
TCOMITabT<T>::get__NewEnum(void)
{
  LPUNKNOWN out_Enum;
  OLECHECK(this->get__NewEnum((LPUNKNOWN*)&out_Enum));
  return out_Enum;
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::get_Count(long* Value/*[out,retval]*/)
{
  return (*this)->get_Count(Value);
}

template <class T> long __fastcall
TCOMITabT<T>::get_Count(void)
{
  long Value;
  OLECHECK(this->get_Count((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::get_length(long* Value/*[out,retval]*/)
{
  return (*this)->get_length(Value);
}

template <class T> long __fastcall
TCOMITabT<T>::get_length(void)
{
  long Value;
  OLECHECK(this->get_length((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::get_Lock(long* Value/*[out,retval]*/)
{
  return (*this)->get_Lock(Value);
}

template <class T> long __fastcall
TCOMITabT<T>::get_Lock(void)
{
  long Value;
  OLECHECK(this->get_Lock((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::set_Lock(long Value/*[in]*/)
{
  return (*this)->set_Lock(Value);
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::get_idname(BSTR* Value/*[out,retval]*/)
{
  return (*this)->get_idname(Value);
}

template <class T> BSTR __fastcall
TCOMITabT<T>::get_idname(void)
{
  BSTR Value = 0;
  OLECHECK(this->get_idname((BSTR*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::get_index(long* Value/*[out,retval]*/)
{
  return (*this)->get_index(Value);
}

template <class T> long __fastcall
TCOMITabT<T>::get_index(void)
{
  long Value;
  OLECHECK(this->get_index((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::set_index(long Value/*[in]*/)
{
  return (*this)->set_index(Value);
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::get_Name(BSTR* Value/*[out,retval]*/)
{
  return (*this)->get_Name(Value);
}

template <class T> BSTR __fastcall
TCOMITabT<T>::get_Name(void)
{
  BSTR Value = 0;
  OLECHECK(this->get_Name((BSTR*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::set_Name(BSTR Value/*[in]*/)
{
  return (*this)->set_Name(Value);
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::get_Type(long* Value/*[out,retval]*/)
{
  return (*this)->get_Type(Value);
}

template <class T> long __fastcall
TCOMITabT<T>::get_Type(void)
{
  long Value;
  OLECHECK(this->get_Type((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::set_Type(long Value/*[in]*/)
{
  return (*this)->set_Type(Value);
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::get_Pane(long* Value/*[out,retval]*/)
{
  return (*this)->get_Pane(Value);
}

template <class T> long __fastcall
TCOMITabT<T>::get_Pane(void)
{
  long Value;
  OLECHECK(this->get_Pane((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::set_Pane(long Value/*[in]*/)
{
  return (*this)->set_Pane(Value);
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::get_TotalCount(long* Value/*[out,retval]*/)
{
  return (*this)->get_TotalCount(Value);
}

template <class T> long __fastcall
TCOMITabT<T>::get_TotalCount(void)
{
  long Value;
  OLECHECK(this->get_TotalCount((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::get_TotalPPcCount(long* Value/*[out,retval]*/)
{
  return (*this)->get_TotalPPcCount(Value);
}

template <class T> long __fastcall
TCOMITabT<T>::get_TotalPPcCount(void)
{
  long Value;
  OLECHECK(this->get_TotalPPcCount((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::get_Color(long* Value/*[out,retval]*/)
{
  return (*this)->get_Color(Value);
}

template <class T> long __fastcall
TCOMITabT<T>::get_Color(void)
{
  long Value;
  OLECHECK(this->get_Color((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::set_Color(long Value/*[in]*/)
{
  return (*this)->set_Color(Value);
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::get_BackColor(long* Value/*[out,retval]*/)
{
  return (*this)->get_BackColor(Value);
}

template <class T> long __fastcall
TCOMITabT<T>::get_BackColor(void)
{
  long Value;
  OLECHECK(this->get_BackColor((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::set_BackColor(long Value/*[in]*/)
{
  return (*this)->set_BackColor(Value);
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::Execute(BSTR param/*[in]*/, long* result/*[out,retval]*/)
{
  return (*this)->Execute(param, result);
}

template <class T> long __fastcall
TCOMITabT<T>::Execute(BSTR param/*[in]*/)
{
  long result;
  OLECHECK(this->Execute(, (long*)&result));
  return result;
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::Extract(BSTR param/*[in]*/, BSTR* result/*[out,retval]*/)
{
  return (*this)->Extract(param, result);
}

template <class T> BSTR __fastcall
TCOMITabT<T>::Extract(BSTR param/*[in]*/)
{
  BSTR result = 0;
  OLECHECK(this->Extract(, (BSTR*)&result));
  return result;
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::moveNext(long* Value/*[out,retval]*/)
{
  return (*this)->moveNext(Value);
}

template <class T> long __fastcall
TCOMITabT<T>::moveNext(void)
{
  long Value;
  OLECHECK(this->moveNext((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::atEnd(long* Value/*[out,retval]*/)
{
  return (*this)->atEnd(Value);
}

template <class T> long __fastcall
TCOMITabT<T>::atEnd(void)
{
  long Value;
  OLECHECK(this->atEnd((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::Reset(void)
{
  return (*this)->Reset();
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::get_Current(Ppxscr_tlb::ITab** Value/*[out,retval]*/)
{
  return (*this)->get_Current(Value);
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::get_Current(Ppxscr_tlb::ITabPtr* Value/*[out,retval]*/)
{
  return (*this)->get_Current(ITab**)Value);
}

template <class T> Ppxscr_tlb::ITabPtr __fastcall
TCOMITabT<T>::get_Current(void)
{
  Ppxscr_tlb::ITab* Value;
  OLECHECK(this->get_Current((Ppxscr_tlb::ITab**)&Value));
  return (Ppxscr_tlb::ITabPtr)Value;
}

template <class T> HRESULT __fastcall
TCOMITabT<T>::IndexFrom(BSTR ppcid/*[in]*/, long* moved/*[out,retval]*/)
{
  return (*this)->IndexFrom(ppcid, moved);
}

template <class T> long __fastcall
TCOMITabT<T>::IndexFrom(BSTR ppcid/*[in]*/)
{
  long moved;
  OLECHECK(this->IndexFrom(, (long*)&moved));
  return moved;
}

// *********************************************************************//
// DispIntf:  ITab
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {A05A073E-C9E6-4742-A6F4-ECD6FD86E5F3}
// *********************************************************************//
template <class T> HRESULT __fastcall
ITabDispT<T>::Item(long index/*[in,opt]*/, Ppxscr_tlb::ITab** Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Item"), DISPID(0));
  TAutoArgs<1> _args;
  _args[1] = index /*[VT_I4:0]*/;
  return OutRetValSetterPtr((LPDISPATCH*)(Ppxscr_tlb::ITab**)Value /*[VT_USERDEFINED:2]*/, _args, OleFunction(_dispid, _args));
}

template <class T> Ppxscr_tlb::ITab* __fastcall
ITabDispT<T>::Item(long index/*[in,opt]*/)
{
  Ppxscr_tlb::ITab* Value;
  this->Item(index, (Ppxscr_tlb::ITab**)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
ITabDispT<T>::get__NewEnum(LPUNKNOWN* out_Enum/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("_NewEnum"), DISPID(-4));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(out_Enum /*[VT_UNKNOWN:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> LPUNKNOWN __fastcall
ITabDispT<T>::get__NewEnum(void)
{
  LPUNKNOWN out_Enum;
  this->get__NewEnum((LPUNKNOWN*)&out_Enum);
  return out_Enum;
}

template <class T> HRESULT __fastcall
ITabDispT<T>::get_Count(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Count"), DISPID(1));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
ITabDispT<T>::get_Count(void)
{
  long Value;
  this->get_Count((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
ITabDispT<T>::get_length(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("length"), DISPID(6));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
ITabDispT<T>::get_length(void)
{
  long Value;
  this->get_length((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
ITabDispT<T>::get_Lock(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Lock"), DISPID(4));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
ITabDispT<T>::get_Lock(void)
{
  long Value;
  this->get_Lock((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
ITabDispT<T>::set_Lock(long Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("Lock"), DISPID(4));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_I4:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
ITabDispT<T>::get_idname(BSTR* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("idname"), DISPID(5));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BSTR:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> BSTR __fastcall
ITabDispT<T>::get_idname(void)
{
  BSTR Value;
  this->get_idname((BSTR*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
ITabDispT<T>::get_index(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("index"), DISPID(2));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
ITabDispT<T>::get_index(void)
{
  long Value;
  this->get_index((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
ITabDispT<T>::set_index(long Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("index"), DISPID(2));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_I4:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
ITabDispT<T>::get_Name(BSTR* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Name"), DISPID(3));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BSTR:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> BSTR __fastcall
ITabDispT<T>::get_Name(void)
{
  BSTR Value;
  this->get_Name((BSTR*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
ITabDispT<T>::set_Name(BSTR Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("Name"), DISPID(3));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_BSTR:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
ITabDispT<T>::get_Type(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Type"), DISPID(7));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
ITabDispT<T>::get_Type(void)
{
  long Value;
  this->get_Type((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
ITabDispT<T>::set_Type(long Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("Type"), DISPID(7));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_I4:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
ITabDispT<T>::get_Pane(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Pane"), DISPID(8));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
ITabDispT<T>::get_Pane(void)
{
  long Value;
  this->get_Pane((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
ITabDispT<T>::set_Pane(long Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("Pane"), DISPID(8));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_I4:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
ITabDispT<T>::get_TotalCount(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("TotalCount"), DISPID(9));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
ITabDispT<T>::get_TotalCount(void)
{
  long Value;
  this->get_TotalCount((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
ITabDispT<T>::get_TotalPPcCount(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("TotalPPcCount"), DISPID(10));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
ITabDispT<T>::get_TotalPPcCount(void)
{
  long Value;
  this->get_TotalPPcCount((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
ITabDispT<T>::get_Color(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Color"), DISPID(11));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
ITabDispT<T>::get_Color(void)
{
  long Value;
  this->get_Color((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
ITabDispT<T>::set_Color(long Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("Color"), DISPID(11));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_I4:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
ITabDispT<T>::get_BackColor(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("BackColor"), DISPID(12));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
ITabDispT<T>::get_BackColor(void)
{
  long Value;
  this->get_BackColor((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
ITabDispT<T>::set_BackColor(long Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("BackColor"), DISPID(12));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_I4:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
ITabDispT<T>::Execute(BSTR param/*[in]*/, long* result/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Execute"), DISPID(14));
  TAutoArgs<1> _args;
  _args[1] = param /*[VT_BSTR:0]*/;
  return OutRetValSetterPtr(result /*[VT_I4:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> long __fastcall
ITabDispT<T>::Execute(BSTR param/*[in]*/)
{
  long result;
  this->Execute(param, (long*)&result);
  return result;
}

template <class T> HRESULT __fastcall
ITabDispT<T>::Extract(BSTR param/*[in]*/, BSTR* result/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Extract"), DISPID(15));
  TAutoArgs<1> _args;
  _args[1] = param /*[VT_BSTR:0]*/;
  return OutRetValSetterPtr(result /*[VT_BSTR:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> BSTR __fastcall
ITabDispT<T>::Extract(BSTR param/*[in]*/)
{
  BSTR result;
  this->Extract(param, (BSTR*)&result);
  return result;
}

template <class T> HRESULT __fastcall
ITabDispT<T>::moveNext(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("moveNext"), DISPID(16));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> long __fastcall
ITabDispT<T>::moveNext(void)
{
  long Value;
  this->moveNext((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
ITabDispT<T>::atEnd(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("atEnd"), DISPID(17));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> long __fastcall
ITabDispT<T>::atEnd(void)
{
  long Value;
  this->atEnd((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
ITabDispT<T>::Reset()
{
  _TDispID _dispid(*this, OLETEXT("Reset"), DISPID(18));
  return OleFunction(_dispid);
}

template <class T> HRESULT __fastcall
ITabDispT<T>::get_Current(Ppxscr_tlb::ITab** Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Current"), DISPID(19));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr((LPDISPATCH*)(Ppxscr_tlb::ITab**)Value /*[VT_USERDEFINED:2]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> Ppxscr_tlb::ITab* __fastcall
ITabDispT<T>::get_Current(void)
{
  Ppxscr_tlb::ITab* Value;
  this->get_Current((Ppxscr_tlb::ITab**)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
ITabDispT<T>::IndexFrom(BSTR ppcid/*[in]*/, long* moved/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("IndexFrom"), DISPID(13));
  TAutoArgs<1> _args;
  _args[1] = ppcid /*[VT_BSTR:0]*/;
  return OutRetValSetterPtr(moved /*[VT_I4:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> long __fastcall
ITabDispT<T>::IndexFrom(BSTR ppcid/*[in]*/)
{
  long moved;
  this->IndexFrom(ppcid, (long*)&moved);
  return moved;
}

// *********************************************************************//
// SmartIntf: TCOMIPPxEnum
// Interface: IPPxEnum
// *********************************************************************//
template <class T> HRESULT __fastcall
TCOMIPPxEnumT<T>::Item(long index/*[in,opt]*/, VARIANT* Value/*[out,retval]*/)
{
  return (*this)->Item(index, Value);
}

template <class T> VARIANT __fastcall
TCOMIPPxEnumT<T>::Item(long index/*[in,opt]*/)
{
  VARIANT Value;
  OLECHECK(this->Item(, (VARIANT*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxEnumT<T>::moveFirst(void)
{
  return (*this)->moveFirst();
}

template <class T> HRESULT __fastcall
TCOMIPPxEnumT<T>::moveNext(long* Value/*[out,retval]*/)
{
  return (*this)->moveNext(Value);
}

template <class T> long __fastcall
TCOMIPPxEnumT<T>::moveNext(void)
{
  long Value;
  OLECHECK(this->moveNext((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxEnumT<T>::atEnd(long* Value/*[out,retval]*/)
{
  return (*this)->atEnd(Value);
}

template <class T> long __fastcall
TCOMIPPxEnumT<T>::atEnd(void)
{
  long Value;
  OLECHECK(this->atEnd((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxEnumT<T>::Reset(void)
{
  return (*this)->Reset();
}

template <class T> HRESULT __fastcall
TCOMIPPxEnumT<T>::get_index(long* Value/*[out,retval]*/)
{
  return (*this)->get_index(Value);
}

template <class T> long __fastcall
TCOMIPPxEnumT<T>::get_index(void)
{
  long Value;
  OLECHECK(this->get_index((long*)&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIPPxEnumT<T>::set_index(long Value/*[in]*/)
{
  return (*this)->set_index(Value);
}

// *********************************************************************//
// DispIntf:  IPPxEnum
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {4EA875C7-268F-4439-96EE-EAFA90173788}
// *********************************************************************//
template <class T> HRESULT __fastcall
IPPxEnumDispT<T>::Item(long index/*[in,opt]*/, VARIANT* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("Item"), DISPID(0));
  TAutoArgs<1> _args;
  _args[1] = index /*[VT_I4:0]*/;
  return OutRetValSetterPtr(Value /*[VT_VARIANT:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> VARIANT __fastcall
IPPxEnumDispT<T>::Item(long index/*[in,opt]*/)
{
  VARIANT Value;
  this->Item(index, (VARIANT*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxEnumDispT<T>::moveFirst()
{
  _TDispID _dispid(*this, OLETEXT("moveFirst"), DISPID(1));
  return OleFunction(_dispid);
}

template <class T> HRESULT __fastcall
IPPxEnumDispT<T>::moveNext(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("moveNext"), DISPID(2));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> long __fastcall
IPPxEnumDispT<T>::moveNext(void)
{
  long Value;
  this->moveNext((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxEnumDispT<T>::atEnd(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("atEnd"), DISPID(3));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OleFunction(_dispid, _args));
}

template <class T> long __fastcall
IPPxEnumDispT<T>::atEnd(void)
{
  long Value;
  this->atEnd((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxEnumDispT<T>::Reset()
{
  _TDispID _dispid(*this, OLETEXT("Reset"), DISPID(4));
  return OleFunction(_dispid);
}

template <class T> HRESULT __fastcall
IPPxEnumDispT<T>::get_index(long* Value/*[out,retval]*/)
{
  _TDispID _dispid(*this, OLETEXT("index"), DISPID(5));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IPPxEnumDispT<T>::get_index(void)
{
  long Value;
  this->get_index((long*)&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IPPxEnumDispT<T>::set_index(long Value/*[in]*/)
{
  _TDispID _dispid(*this, OLETEXT("index"), DISPID(5));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_I4:0]*/;
  return OlePropertyPut(_dispid, _args);
}

// *********************************************************************//
// The following typedefs expose classes (named CoCoClassName) that       
// provide static Create() and CreateRemote(LPWSTR machineName) methods   
// for creating an instance of an exposed object. These functions can     
// be used by client wishing to automate CoClasses exposed by this        
// typelibrary.                                                           
// *********************************************************************//

// *********************************************************************//
// COCLASS DEFAULT INTERFACE CREATOR
// CoClass  : PPxObject
// Interface: TCOMIPPx
// *********************************************************************//
typedef TCoClassCreatorT<TCOMIPPx, IPPx, &CLSID_PPxObject, &IID_IPPx> CoPPxObject;

// *********************************************************************//
// COCLASS DEFAULT INTERFACE CREATOR
// CoClass  : IArguments_Class
// Interface: TCOMIArguments
// *********************************************************************//
typedef TCoClassCreatorT<TCOMIArguments, IArguments, &CLSID_IArguments_Class, &IID_IArguments> CoIArguments_Class;

// *********************************************************************//
// COCLASS DEFAULT INTERFACE CREATOR
// CoClass  : IEntry_Class
// Interface: TCOMIEntry
// *********************************************************************//
typedef TCoClassCreatorT<TCOMIEntry, IEntry, &CLSID_IEntry_Class, &IID_IEntry> CoIEntry_Class;

// *********************************************************************//
// COCLASS DEFAULT INTERFACE CREATOR
// CoClass  : IPane_Class
// Interface: TCOMIPane
// *********************************************************************//
typedef TCoClassCreatorT<TCOMIPane, IPane, &CLSID_IPane_Class, &IID_IPane> CoIPane_Class;

// *********************************************************************//
// COCLASS DEFAULT INTERFACE CREATOR
// CoClass  : ITab_Class
// Interface: TCOMITab
// *********************************************************************//
typedef TCoClassCreatorT<TCOMITab, ITab, &CLSID_ITab_Class, &IID_ITab> CoITab_Class;

// *********************************************************************//
// COCLASS DEFAULT INTERFACE CREATOR
// CoClass  : IPPxEnum_Class
// Interface: TCOMIPPxEnum
// *********************************************************************//
typedef TCoClassCreatorT<TCOMIPPxEnum, IPPxEnum, &CLSID_IPPxEnum_Class, &IID_IPPxEnum> CoIPPxEnum_Class;
#endif  //   __TLB_NO_INTERFACE_WRAPPERS


#if !defined(__TLB_NO_EVENT_WRAPPERS) && defined(USING_ATLVCL)
// *********************************************************************//
// CONNECTIONPOINT/EVENT PROXY
// CoClass         : PPxObject
// Event Interface : IPPxEvents
// *********************************************************************//
template <class T>
class TEvents_PPxObject : public IConnectionPointImpl<T,
                                                 &DIID_IPPxEvents,
                                                 CComUnkArray<CONNECTIONPOINT_ARRAY_SIZE> >
 /* Note: if encountering problems with events, please change CComUnkArray to CComDynamicUnkArray in the line above. */
{
public:
protected:
  IPPxEventsDisp m_EventIntfObj;
};

#endif  //   __TLB_NO_EVENT_WRAPPERS

};     // namespace Ppxscr_tlb

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using  namespace Ppxscr_tlb;
#endif

#pragma option pop

#endif // PPxScr_TLBH
