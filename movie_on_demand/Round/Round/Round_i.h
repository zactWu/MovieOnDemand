

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for Round.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __Round_i_h__
#define __Round_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IRoundobj_FWD_DEFINED__
#define __IRoundobj_FWD_DEFINED__
typedef interface IRoundobj IRoundobj;

#endif 	/* __IRoundobj_FWD_DEFINED__ */


#ifndef __Roundobj_FWD_DEFINED__
#define __Roundobj_FWD_DEFINED__

#ifdef __cplusplus
typedef class Roundobj Roundobj;
#else
typedef struct Roundobj Roundobj;
#endif /* __cplusplus */

#endif 	/* __Roundobj_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IRoundobj_INTERFACE_DEFINED__
#define __IRoundobj_INTERFACE_DEFINED__

/* interface IRoundobj */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IRoundobj;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1b8a2dff-7a75-45db-84e0-29eadad0cb92")
    IRoundobj : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ERound( 
            /* [in] */ double __MIDL__IRoundobj0000,
            /* [out] */ double *__MIDL__IRoundobj0001) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRoundobjVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRoundobj * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRoundobj * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRoundobj * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRoundobj * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRoundobj * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRoundobj * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRoundobj * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ERound )( 
            IRoundobj * This,
            /* [in] */ double __MIDL__IRoundobj0000,
            /* [out] */ double *__MIDL__IRoundobj0001);
        
        END_INTERFACE
    } IRoundobjVtbl;

    interface IRoundobj
    {
        CONST_VTBL struct IRoundobjVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRoundobj_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRoundobj_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRoundobj_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRoundobj_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRoundobj_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRoundobj_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRoundobj_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRoundobj_ERound(This,__MIDL__IRoundobj0000,__MIDL__IRoundobj0001)	\
    ( (This)->lpVtbl -> ERound(This,__MIDL__IRoundobj0000,__MIDL__IRoundobj0001) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRoundobj_INTERFACE_DEFINED__ */



#ifndef __RoundLib_LIBRARY_DEFINED__
#define __RoundLib_LIBRARY_DEFINED__

/* library RoundLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_RoundLib;

EXTERN_C const CLSID CLSID_Roundobj;

#ifdef __cplusplus

class DECLSPEC_UUID("987c5b88-4ab0-4ebe-b689-e249d0f196b4")
Roundobj;
#endif
#endif /* __RoundLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


