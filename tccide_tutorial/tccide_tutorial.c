/***************** Automatically Created with TCC4TCL Helper and maybe TSP **********************************/
/* Compiler directives are raw estimates, please adapt to given pathstructure */

/* for gccwin32 use */
/* /host/data/tcl/tcc_0.9.27-bin/gcc/bin/gcc.exe  -s -m32 -D_WIN32 -static-libgcc  -shared -DUSE_TCL_STUBS -O2  -Iinclude -Iinclude/generic -Iinclude/generic/win -Iinclude/xlib -Itsp-package/native/clang/ -I../tccide_tutorial ../tccide_tutorial/tccide_tutorial.c -o../tccide_tutorial/tccide_tutorial.dll -Llib -ltclstub86 -ltkstub86 -Llib -L../tccide_tutorial */

/* for tccwin32 use */
/* /host/data/tcl/tcc_0.9.27-bin/tcc.exe  -m32 -D_WIN32  -shared -DUSE_TCL_STUBS -O2  -Iinclude -Iinclude/stdinc -Iinclude/generic -Iinclude/generic/win -Iinclude/xlib -Iwin32 -Iwin32/winapi  -Itsp-package/native/clang/ -I../tccide_tutorial ../tccide_tutorial/tccide_tutorial.c -o../tccide_tutorial/tccide_tutorial.dll -ltclstub86elf -ltkstub86elf -Llib -L../tccide_tutorial */

/* for gcc use */
/* /host/data/tcl/tcc_0.9.27-bin/gcc/bin/gcc.exe  -s -m32 -D_WIN32 -static-libgcc  -shared -DUSE_TCL_STUBS -O2  -Iinclude -Iinclude/generic -Iinclude/generic/win -Iinclude/xlib -Itsp-package/native/clang/ -I../tccide_tutorial ../tccide_tutorial/tccide_tutorial.c -o../tccide_tutorial/tccide_tutorial.dll -Llib -ltclstub86 -ltkstub86 -Llib -L../tccide_tutorial */

/* for tcc use */
/* /host/data/tcl/tcc_0.9.27-bin/tcc.exe  -m32 -D_WIN32  -shared -DUSE_TCL_STUBS -O2  -Iinclude -Iinclude/stdinc -Iinclude/generic -Iinclude/generic/win -Iinclude/xlib -Iwin32 -Iwin32/winapi  -Itsp-package/native/clang/ -I../tccide_tutorial ../tccide_tutorial/tccide_tutorial.c -o../tccide_tutorial/tccide_tutorial.dll -ltclstub86elf -ltkstub86elf -Llib -L../tccide_tutorial */

/***************** Automatically Created with TCC4TCL Helper and maybe TSP **********************************/
#include <tcl.h>
/* All TCL needs an interp... */
/* External callbacks won't know about an Tcl_Interp, so ...*/
/* we install a module scope global interp here ...*/
static Tcl_Interp*  mod_Tcl_interp;
static int mod_Tcl_errorCode;
static int c___loot_interp(Tcl_Interp* interp) {
   mod_Tcl_interp = interp;
    return 1;
}
int tcl___loot_interp(ClientData clientdata, Tcl_Interp *ip, int objc, Tcl_Obj *CONST objv[]) {
  int rv;
  if (objc != 1) {
    Tcl_WrongNumArgs(ip, 1, objv, "");
    return TCL_ERROR;
  }
  rv = c___loot_interp(ip);
  Tcl_SetIntObj(Tcl_GetObjResult(ip), rv);
  return TCL_OK;
}
#undef DLLEXPORT 
#undef DLLIMPORT 
/***************** DLL EXPORT MAKRO FOR TCC AND GCC ************/
#if (defined(_WIN32) && (defined(_MSC_VER)|| defined(__TINYC__)  || (defined(__BORLANDC__) && (__BORLANDC__ >= 0x0550)) || defined(__LCC__) || defined(__WATCOMC__) || (defined(__GNUC__) && defined(__declspec))))
#undef DLLIMPORT
#undef DLLEXPORT
#   define DLLIMPORT __declspec(dllimport)
#   define DLLEXPORT __declspec(dllexport)
#else
#   define DLLIMPORT 
#   if defined(__GNUC__) && __GNUC__ > 3
#       define DLLEXPORT __attribute__ ((visibility("default")))
#   else
#       define DLLEXPORT
#   endif
#endif
/***************************************************************/
/* START OF PACKAGE_HEADER */
/* don't forget to declare includedir tsp-package/native/clang/ in the right way */
#include <string.h>
#include <tclInt.h>
#include "TSP_cmd.c"
#include "TSP_func.c"
#include "TSP_util.c"
/* END OF PACKAGE_HEADER */
static char* c_cnop(Tcl_Interp* interp) {
return "compiled Fri Dec 06 23:08:09 +0100 2024 with gccwin32";
}
int tcl_cnop(ClientData clientdata, Tcl_Interp *ip, int objc, Tcl_Obj *CONST objv[]) {
  char* rv;
  if (objc != 1) {
    Tcl_WrongNumArgs(ip, 1, objv, "");
    return TCL_ERROR;
  }
  rv = c_cnop(ip);
  if (rv == NULL) {
    return(TCL_ERROR);
  }
  Tcl_SetObjResult(ip,Tcl_NewStringObj( rv, -1 ));
  return TCL_OK;
}
#undef CLEANUP
#undef RETURN_VALUE_CLEANUP
#undef RETURN_VALUE
#undef ERROR_EXIT
#define ERROR_EXIT goto error_exit
#define CLEANUP  \
\
    \
    if (_tmpVar_cmdResultObj != NULL) { Tcl_DecrRefCount(_tmpVar_cmdResultObj); _tmpVar_cmdResultObj = NULL; } \
    \
    if (_tmpVar_var_1 != NULL) { Tcl_DecrRefCount(_tmpVar_var_1); _tmpVar_var_1 = NULL; } \
    if (_tmpVar_var_2 != NULL) { Tcl_DecrRefCount(_tmpVar_var_2); _tmpVar_var_2 = NULL; } \
    \
    Tcl_DStringFree(_tmpVar_string_1);\
    Tcl_DStringFree(_tmpVar_string_2);\

#define RETURN_VALUE_CLEANUP
#define RETURN_VALUE
/* 
 * compiled proc implementation 
 *
 */
void
TSP_UserDirect_tspnop(Tcl_Interp* interp, int* rc   ) {
    static int directInit = 0;
    int i;          /* for loop */
    int len;        /* len, idx1, idx2, str, str2 -for use by lang_string, et.al. */
    int idx1;
    int idx2;
    char* str1;     
    char* str2;     
    char* exprErrMsg ;
    Tcl_Obj* _tmpVar_cmdResultObj = NULL;
    Tcl_CallFrame* frame; 
    Tcl_Obj*  argObjvArray_0[2];
    int       argObjc_0 = 0;
    Tcl_Obj** foreachObjv_0 = NULL;
    Tcl_Obj*  argObjvArray_1[3];
    int       argObjc_1 = 0;
    Tcl_Obj** foreachObjv_1 = NULL;
    Tcl_Obj*  argObjvArray_2[2];
    int       argObjc_2 = 0;
    Tcl_Obj** foreachObjv_2 = NULL;
    /* stack allocated strings */
    Tcl_DString Proc__tmpVar_string_1;
    Tcl_DString Proc__tmpVar_string_2;
    /* variables defined in proc, plus temp vars */
    Tcl_DString* _tmpVar_string_1;
    Tcl_DString* _tmpVar_string_2;
    Tcl_Obj* _tmpVar_var_1 = NULL;
    Tcl_Obj* _tmpVar_var_2 = NULL;
    /* constants used for direct tcl and tcl invoked commands */
    /* const: tspnop ok */
    static Tcl_Obj* _constant_1 = NULL;
    /* const: format */
    static Tcl_Obj* _constant_2 = NULL;
    /* const: seconds */
    static Tcl_Obj* _constant_3 = NULL;
    /* initialize return value */
    /* initialize string vars */
    Tcl_DStringInit(&Proc__tmpVar_string_1);
    _tmpVar_string_1 = &Proc__tmpVar_string_1;
    Tcl_DStringInit(&Proc__tmpVar_string_2);
    _tmpVar_string_2 = &Proc__tmpVar_string_2;
    /* var arguments need to be preserved, since they are released in CLEANUP */
    /* string arguments need to be copied (FIXME: investigate using COW for strings) */
    /* initialize function pointers for calling other compiled procs, constants */
    if (! directInit) {
        directInit = 1;
        _constant_1 = TSP_Util_const_string("tspnop ok");/*from create_compilable*/
        _constant_2 = TSP_Util_const_string("format");/*from create_compilable*/
        _constant_3 = TSP_Util_const_string("seconds");/*from create_compilable*/
    }
    /* Native proc, no external variables used, dropping PushCallframe/PopCallframe */
    *rc = TCL_OK;     
    /* code must return a value as defined by procdef (unless void), else will raise a compile error */
    /* does only gcc do this with the right option?  what about tcc/clang/msvc++? */
    /******** tspnop 3: puts "tspnop ok" */
    /***** ::tsp::gen_direct_tcl puts */
    argObjvArray_0[0] = NULL;
    argObjvArray_0[1] = _constant_1;
    /*  ::tsp::lang_invoke_builtin */
    if ((*rc = (TSP_Cmd_builtin_puts) ((ClientData)NULL, interp,  2, argObjvArray_0)) != TCL_OK) {
        ERROR_EXIT;
    }
    if (_tmpVar_cmdResultObj != NULL) { Tcl_DecrRefCount(_tmpVar_cmdResultObj); _tmpVar_cmdResultObj = NULL; } 
    _tmpVar_cmdResultObj = Tcl_GetObjResult(interp);
    Tcl_IncrRefCount(_tmpVar_cmdResultObj);
    /******** tspnop 4: puts "runtime: [clock format [clock seconds]]" */
    /***** ::tsp::gen_direct_tcl puts */
    argObjvArray_0[0] = NULL;
    /***** ::tsp::gen_assign_var_string_interpolated_string */
    /* ::tsp::lang_assign_empty_zero */
    Tcl_DStringSetLength(_tmpVar_string_2, 0);
    /* ::tsp::lang_assign_string_const */
    Tcl_DStringSetLength(_tmpVar_string_1,0);
    Tcl_DStringAppend(_tmpVar_string_1, "runtime: ", -1);
    /* ::tsp::lang_append_string */
    Tcl_DStringAppend(_tmpVar_string_2, Tcl_DStringValue(_tmpVar_string_1), Tcl_DStringLength(_tmpVar_string_1));
    /******** tspnop 4: clock format [clock seconds] */
    /***** ::tsp::gen_direct_tcl clock */
    argObjvArray_1[0] = NULL;
    argObjvArray_1[1] = _constant_2;
    /***** ::tsp::generate_set assign from command (set _tmpVar_var_2 = _tmpVar_cmdResultObj) */
    /******** tspnop 4: clock seconds */
    /***** ::tsp::gen_direct_tcl clock */
    argObjvArray_2[0] = NULL;
    argObjvArray_2[1] = _constant_3;
    /*  ::tsp::lang_invoke_builtin */
    if ((*rc = (TSP_Cmd_builtin_clock) ((ClientData)NULL, interp,  2, argObjvArray_2)) != TCL_OK) {
        ERROR_EXIT;
    }
    if (_tmpVar_cmdResultObj != NULL) { Tcl_DecrRefCount(_tmpVar_cmdResultObj); _tmpVar_cmdResultObj = NULL; } 
    _tmpVar_cmdResultObj = Tcl_GetObjResult(interp);
    Tcl_IncrRefCount(_tmpVar_cmdResultObj);
    /***** ::tsp::gen_assign_scalar_scalar */
    /* ::tsp::lang_assign_var_var */
    _tmpVar_var_2 = TSP_Util_lang_assign_var_var(_tmpVar_var_2, _tmpVar_cmdResultObj);
    argObjvArray_1[2] = _tmpVar_var_2;
    /*  ::tsp::lang_invoke_builtin */
    if ((*rc = (TSP_Cmd_builtin_clock) ((ClientData)NULL, interp,  3, argObjvArray_1)) != TCL_OK) {
        ERROR_EXIT;
    }
    if (_tmpVar_cmdResultObj != NULL) { Tcl_DecrRefCount(_tmpVar_cmdResultObj); _tmpVar_cmdResultObj = NULL; } 
    _tmpVar_cmdResultObj = Tcl_GetObjResult(interp);
    Tcl_IncrRefCount(_tmpVar_cmdResultObj);
    /***** ::tsp::gen_assign_scalar_scalar */
    /* ::tsp::lang_convert_string_var */
    Tcl_DStringSetLength(_tmpVar_string_1, 0);
    _tmpVar_string_1 = TSP_Util_lang_convert_string_var(_tmpVar_string_1, _tmpVar_cmdResultObj);
    /* ::tsp::lang_append_string */
    Tcl_DStringAppend(_tmpVar_string_2, Tcl_DStringValue(_tmpVar_string_1), Tcl_DStringLength(_tmpVar_string_1));
    /***** ::tsp::gen_assign_scalar_scalar */
    /* ::tsp::lang_assign_var_string */
    _tmpVar_var_1 = TSP_Util_lang_assign_var_string(_tmpVar_var_1, _tmpVar_string_2);
    argObjvArray_0[1] = _tmpVar_var_1;
    /*  ::tsp::lang_invoke_builtin */
    if ((*rc = (TSP_Cmd_builtin_puts) ((ClientData)NULL, interp,  2, argObjvArray_0)) != TCL_OK) {
        ERROR_EXIT;
    }
    if (_tmpVar_cmdResultObj != NULL) { Tcl_DecrRefCount(_tmpVar_cmdResultObj); _tmpVar_cmdResultObj = NULL; } 
    _tmpVar_cmdResultObj = Tcl_GetObjResult(interp);
    Tcl_IncrRefCount(_tmpVar_cmdResultObj);
    /* if void, then we can jump to normal_exit, if not-void, then that means the proc fell through */
    /* without returning a value.  in that case, set result and return error code*/
     goto normal_exit;    
  error_exit:
    *rc = TCL_ERROR;
  normal_exit:
    CLEANUP;
    RETURN_VALUE_CLEANUP;
    return RETURN_VALUE;
}
/* redefine macros for the Tcl interface function */
#undef CLEANUP
#undef RETURN_VALUE_CLEANUP
#undef RETURN_VALUE
#undef ERROR_EXIT
#define CLEANUP \

#define RETURN_VALUE_CLEANUP 
#define RETURN_VALUE 
#define ERROR_EXIT goto error_exit
/* 
 * Tcl command interface 
 *
 */
int tspnop(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[]) {
    int _rc;
    int* rc = &_rc;;
    /* variables used by this command, assigned from objv array */
    /* allow other compiled procs to find the this proc function at runtime, see TSP_cmd.TSP_User_getCmd() */
    if (clientData != NULL && objc == 0) {
        void** cd = clientData;
        *cd = (void*) TSP_UserDirect_tspnop;
        return TCL_OK;
    }
    /* check arg count */
    if (objc != 1) {
        Tcl_WrongNumArgs(interp, 1, objv, "");
        return TCL_ERROR;
    }
    /* assign arg variable from objv array */
    /* invoke compiled proc method */
    _rc = TCL_OK;
    TSP_UserDirect_tspnop(interp, &_rc );
    if (_rc == TCL_OK) {
        /* ok to fall through */
    }
  error_exit:
    CLEANUP;
    return _rc;
}
char* tcl_test2(char* a, int b) {
    int tclrv;
    Tcl_Obj *rv_interp;
    char* rv;
    Tcl_Interp *ip;
    Tcl_Obj *_a, *_b;
    ip  = Tcl_CreateInterp();
    if (!ip) return(NULL);
    _a = Tcl_NewStringObj(a, -1);
    if (!Tcl_ObjSetVar2(ip, Tcl_NewStringObj("a", -1), NULL, _a, 0)) return(NULL);
    _b = Tcl_NewIntObj(b);
    if (!_b) return(NULL);
    if (!Tcl_ObjSetVar2(ip, Tcl_NewStringObj("b", -1), NULL, _b, 0)) return(NULL);
    tclrv = Tcl_Eval(ip, "\
\x23\x20\x70\x75\x72\x65\x20\x74\x63\x6c\x20\x70\x72\x6f\x63\x0a\x20\x20\x20\x20\
\x69\x66\x20\x7b\x24\x61\x20\x6e\x65\x20\x22\x22\x7d\x20\x7b\x0a\x20\x20\x20\x20\
\x20\x20\x20\x20\x72\x65\x74\x75\x72\x6e\x20\x22\x54\x43\x4c\x20\x54\x45\x53\x54\
\x20\x32\x20\x4f\x4b\x2c\x20\x5c\x6e\x24\x61\x5c\x6e\x52\x65\x73\x75\x6c\x74\x20\
\x6f\x66\x20\x33\x2a\x20\x24\x62\x20\x3d\x20\x5b\x65\x78\x70\x72\x20\x24\x62\x2a\
\x33\x5d\x22\x0a\x20\x20\x20\x20\x7d\x0a\x20\x20\x20\x20\x72\x65\x74\x75\x72\x6e\
\x20\x5b\x65\x78\x70\x72\x20\x24\x62\x2a\x33\x5d\x0a");
    if (tclrv != TCL_OK && tclrv != TCL_RETURN) return(NULL);
    if (tclrv != TCL_OK && tclrv != TCL_RETURN) return(NULL);
    rv_interp = Tcl_GetObjResult(ip);
    rv = Tcl_GetString(rv_interp);
    Tcl_DeleteInterp(ip);
    return(rv);
}
#include <stdio.h>
char* mytest1(char* text, int i) {
    Tcl_Interp* ip = mod_Tcl_interp;
    if (ip==NULL) Tcl_Panic("No interp found to call tcl routine!");
    mod_Tcl_errorCode=0;
    char buf [2048];
    Tcl_Obj*  argObjvArray [3];
    Tcl_Obj* funcname = Tcl_NewStringObj("tcl_test",-1);
    Tcl_IncrRefCount(funcname);
    argObjvArray[0] = funcname;
    Tcl_Obj* target_1 = Tcl_NewStringObj(text, -1);
    Tcl_IncrRefCount(target_1);
    argObjvArray[1] = target_1;
    Tcl_Obj* target_2 = Tcl_NewWideIntObj((Tcl_WideInt) i);
    Tcl_IncrRefCount(target_2);
    argObjvArray[2] = target_2;
    int rs = Tcl_EvalObjv(ip, 3, argObjvArray, 0);
    if(funcname!=NULL) Tcl_DecrRefCount(funcname);
    if(target_1 != NULL) Tcl_DecrRefCount(target_1);
    if(target_2 != NULL) Tcl_DecrRefCount(target_2);
    if(rs !=TCL_OK) {
        mod_Tcl_errorCode=rs;
        const char* err = Tcl_GetStringResult(ip);
        snprintf (buf, 2048, "puts {error evaluating tcl-proc tcl_test\n%s}",err);
        Tcl_Eval (ip, buf);
        Tcl_Eval (ip, "puts {STACK TRACE:}; puts $errorInfo; flush stdout;");
        return (char*) NULL ;
    }
    char* rv;
    rv=Tcl_GetStringFromObj(Tcl_GetObjResult(ip),NULL);
    if(rs !=TCL_OK) {
        mod_Tcl_errorCode=rs;
        const char* err = Tcl_GetStringResult(ip);
        sprintf (buf, "puts {error in result of tcl-proc tcl_test\n%s}",err);
        Tcl_Eval (ip, buf);
        return (char*) NULL ;
    }
    return rv;
}
char* mytest2(char* text, int i) {
    Tcl_Interp* ip = mod_Tcl_interp;
    if (ip==NULL) Tcl_Panic("No interp found to call tcl routine!");
    mod_Tcl_errorCode=0;
    char buf [2048];
    snprintf (buf, 2048, "%s \"%s\" %d", "tcl_test",text,i);
    int rs = Tcl_Eval (ip, buf);
    if(rs !=TCL_OK) {
        mod_Tcl_errorCode=rs;
        const char* err = Tcl_GetStringResult(ip);
        snprintf (buf, 2048, "puts {error evaluating tcl-proc tcl_test\n%s}",err);
        Tcl_Eval (ip, buf);
         Tcl_Eval(ip, "puts {STACK TRACE:}; puts $errorInfo; flush stdout;");
        return (char*) NULL ;
    }
    char* rv;
    rv=Tcl_GetStringFromObj(Tcl_GetObjResult(ip),NULL);
    if(rs !=TCL_OK) {
        mod_Tcl_errorCode=rs;
        const char* err = Tcl_GetStringResult(ip);
        sprintf (buf, "puts {error in result of tcl-proc tcl_test\n%s}",err);
        Tcl_Eval (ip, buf);
        return (char*) NULL ;
    }
    return rv;
}
#undef CLEANUP
#undef RETURN_VALUE_CLEANUP
#undef RETURN_VALUE
#undef ERROR_EXIT
#define ERROR_EXIT goto error_exit
#define CLEANUP  \
\
    \
    if (_tmpVar_cmdResultObj != NULL) { Tcl_DecrRefCount(_tmpVar_cmdResultObj); _tmpVar_cmdResultObj = NULL; } \
    \
    \

#define RETURN_VALUE_CLEANUP
#define RETURN_VALUE
/* 
 * compiled proc implementation 
 *
 */
void
TSP_UserDirect_tspcalltcl(Tcl_Interp* interp, int* rc   ) {
    static int directInit = 0;
    int i;          /* for loop */
    int len;        /* len, idx1, idx2, str, str2 -for use by lang_string, et.al. */
    int idx1;
    int idx2;
    char* str1;     
    char* str2;     
    char* exprErrMsg ;
    Tcl_Obj* _tmpVar_cmdResultObj = NULL;
    Tcl_CallFrame* frame; 
    Tcl_Obj*  argObjvArray_0[3];
    int       argObjc_0 = 0;
    Tcl_Obj** foreachObjv_0 = NULL;
    /* stack allocated strings */
    /* variables defined in proc, plus temp vars */
    /* constants used for direct tcl and tcl invoked commands */
    /* const: tcl_test */
    static Tcl_Obj* _constant_1 = NULL;
    /* const: tsp::tcl_test ok */
    static Tcl_Obj* _constant_2 = NULL;
    /* const: 12345 */
    static Tcl_Obj* _constant_3 = NULL;
    /* initialize return value */
    /* initialize string vars */
    /* var arguments need to be preserved, since they are released in CLEANUP */
    /* string arguments need to be copied (FIXME: investigate using COW for strings) */
    /* initialize function pointers for calling other compiled procs, constants */
    if (! directInit) {
        directInit = 1;
        _constant_1 = TSP_Util_const_string("tcl_test");/*from create_compilable*/
        _constant_2 = TSP_Util_const_string("tsp::tcl_test ok");/*from create_compilable*/
        _constant_3 = TSP_Util_const_int((Tcl_WideInt) 12345LL);
    }
    /* Native proc, no external variables used, dropping PushCallframe/PopCallframe */
    *rc = TCL_OK;     
    /* code must return a value as defined by procdef (unless void), else will raise a compile error */
    /* does only gcc do this with the right option?  what about tcc/clang/msvc++? */
    /******** tspcalltcl 3: tcl_test "tsp::tcl_test ok" 12345 */
    /***** ::tsp::gen_invoke_tcl tcl_test */
    argObjvArray_0[0] = _constant_1;
    argObjvArray_0[1] = _constant_2;
    argObjvArray_0[2] = _constant_3;
    /*  ::tsp::lang_invoke_tcl */
    if ((*rc = Tcl_EvalObjv(interp, 3, argObjvArray_0, 0)) != TCL_OK) {
        ERROR_EXIT;
    }
    if (_tmpVar_cmdResultObj != NULL) { Tcl_DecrRefCount(_tmpVar_cmdResultObj); _tmpVar_cmdResultObj = NULL; } 
    _tmpVar_cmdResultObj = Tcl_GetObjResult(interp);
    Tcl_IncrRefCount(_tmpVar_cmdResultObj);
    /* if void, then we can jump to normal_exit, if not-void, then that means the proc fell through */
    /* without returning a value.  in that case, set result and return error code*/
     goto normal_exit;    
  error_exit:
    *rc = TCL_ERROR;
  normal_exit:
    CLEANUP;
    RETURN_VALUE_CLEANUP;
    return RETURN_VALUE;
}
/* redefine macros for the Tcl interface function */
#undef CLEANUP
#undef RETURN_VALUE_CLEANUP
#undef RETURN_VALUE
#undef ERROR_EXIT
#define CLEANUP \

#define RETURN_VALUE_CLEANUP 
#define RETURN_VALUE 
#define ERROR_EXIT goto error_exit
/* 
 * Tcl command interface 
 *
 */
int tspcalltcl(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[]) {
    int _rc;
    int* rc = &_rc;;
    /* variables used by this command, assigned from objv array */
    /* allow other compiled procs to find the this proc function at runtime, see TSP_cmd.TSP_User_getCmd() */
    if (clientData != NULL && objc == 0) {
        void** cd = clientData;
        *cd = (void*) TSP_UserDirect_tspcalltcl;
        return TCL_OK;
    }
    /* check arg count */
    if (objc != 1) {
        Tcl_WrongNumArgs(interp, 1, objv, "");
        return TCL_ERROR;
    }
    /* assign arg variable from objv array */
    /* invoke compiled proc method */
    _rc = TCL_OK;
    TSP_UserDirect_tspcalltcl(interp, &_rc );
    if (_rc == TCL_OK) {
        /* ok to fall through */
    }
  error_exit:
    CLEANUP;
    return _rc;
}
/* int puts const char* string 
*/
int _tcl_puts(const char* string) {
    Tcl_Interp* ip = mod_Tcl_interp;
    if (ip==NULL) Tcl_Panic("No interp found to call tcl routine!");
    mod_Tcl_errorCode=0;
    Tcl_Obj*  argObjvArray [2];
    Tcl_Obj* funcname = Tcl_NewStringObj("puts",-1);
    Tcl_IncrRefCount(funcname);
    argObjvArray[0] = funcname;
    Tcl_Obj* target_1 = Tcl_NewStringObj(string,-1);
    Tcl_IncrRefCount(target_1);
    argObjvArray[1] = target_1;
    int rs = Tcl_EvalObjv(ip, 2, argObjvArray, 0);
    if(funcname!=NULL) Tcl_DecrRefCount(funcname);
    if(target_1 != NULL) Tcl_DecrRefCount(target_1);
    if(rs !=TCL_OK) {
        mod_Tcl_errorCode=rs;
        Tcl_Eval (ip, "puts {Error evaluating TCL-Function puts}; puts $errorInfo; flush stdout;");
        return EOF;
    }
    return 1; 
}
#define puts _tcl_puts
/* TCL char* _getsysconfig char* cvmtaobl
*/
/* get some information from the host compiler for configure */
/*
_getsysconfig compiler|version|minor|bigendian|triplet|arch|os|lparch c-vm t(ao)-l(b)
*/
char* _getsysconfig(char *cvmtaobl)
{
/* Define architecture */
#if defined(__i386__) || defined _M_IX86
# define TRIPLET_ARCH "i386"
#elif defined(__x86_64__) || defined _M_AMD64
# define TRIPLET_ARCH "x86_64"
#elif defined(__arm__)
# define TRIPLET_ARCH "arm"
#elif defined(__aarch64__)
# define TRIPLET_ARCH "aarch64"
#elif defined(__riscv) && defined(__LP64__)
# define TRIPLET_ARCH "riscv64"
#else
# define TRIPLET_ARCH "unknown"
#endif
/* Define OS */
#if defined (__linux__)
# define TRIPLET_OS "linux"
#elif defined (__FreeBSD__) || defined (__FreeBSD_kernel__)
# define TRIPLET_OS "kfreebsd"
#elif defined(__NetBSD__)
# define TRIPLET_OS "netbsd"
#elif defined(__OpenBSD__)
# define TRIPLET_OS "openbsd"
#elif defined(_WIN32)
# define TRIPLET_OS "win32"
#elif defined(__APPLE__)
# define TRIPLET_OS "darwin"
#elif !defined (__GNU__)
# define TRIPLET_OS "unknown"
#endif
#if defined __ANDROID__
# define ABI_PREFIX "android"
#else
# define ABI_PREFIX "gnu"
#endif
/* Define calling convention and ABI */
#if defined (__ARM_EABI__)
# if defined (__ARM_PCS_VFP)
#  define TRIPLET_ABI ABI_PREFIX"eabihf"
# else
#  define TRIPLET_ABI ABI_PREFIX"eabi"
# endif
#else
# define TRIPLET_ABI ABI_PREFIX
#endif
#if defined _WIN32
# define TRIPLET TRIPLET_ARCH "-" TRIPLET_OS
#elif defined __GNU__
# define TRIPLET TRIPLET_ARCH "-" TRIPLET_ABI
#else
# define TRIPLET TRIPLET_ARCH "-" TRIPLET_OS "-" TRIPLET_ABI
#endif
#include "stdint.h"
#if INTPTR_MAX == INT32_MAX
    //#define THIS_IS_32_BIT_ENVIRONMENT
    #define SIZEOF_VOID_P 4
    //#define INTTYPE int
    #define LPARCH "ILP32"
#elif INTPTR_MAX == INT64_MAX
    //#define THIS_IS_64_BIT_ENVIRONMENT
    #define SIZEOF_VOID_P 8
    #if SIZEOF_VOID_P == __SIZEOF_LONG__
        //#define INTTYPE long
        #define LPARCH "LP64"
    #else
        //#define INTTYPE long long
        #define LPARCH "LLP64"
    #endif
#else
    #define LPARCH "unknown"
    #error "Environment not 32 or 64-bit."
#endif
    char buf[128];
    char outbuf [2024];
    char req;
    unsigned int i;
    i=0;
    outbuf[0]='\0';
    while (i<strlen(cvmtaobl)) {
        req=cvmtaobl[i];
        i++;
    switch(req) {
        case 'b'://igendian
        {
            volatile unsigned foo = 0x01234567;
            sprintf(buf,*(unsigned char*)&foo == 0x67 ? "no" : "yes");
            break;
        }
#if defined(__clang__)
        case 'm'://inor
            sprintf(buf,"%d", __clang_minor__);
            break;
        case 'v'://ersion
            sprintf(buf,"%d", __clang_major__);
            break;
#elif defined(__TINYC__)
        case 'v'://ersion
            #define __tinyc_major__ (__TINYC__/10000)
            sprintf(buf,"%d", __tinyc_major__);
            break;
        case 'm'://inor
            sprintf(buf,"%d", __TINYC__);
            break;
#elif defined(_MSC_VER)
        case 'v'://ersion
            sprintf(buf,"0");
            break;
        case 'm'://inor
            sprintf(buf,"%d", _MSC_VER);
            break;
#elif defined(__GNUC__) && defined(__GNUC_MINOR__)
        /* GNU comes last as other compilers may add 'GNU' compatibility */
        case 'm'://inor
            sprintf(buf,"%d", __GNUC_MINOR__);
            break;
        case 'v'://ersion
            sprintf(buf,"%d", __GNUC__);
            break;
#else
        case 'm'://inor
        case 'v'://ersion
            sprintf(buf,"0");
            break;
#endif
        case 't'://riplet
            sprintf(buf,TRIPLET);
            break;
        case 'o'://s
            sprintf(buf,TRIPLET_OS);
            break;
        case 'a'://rch
            sprintf(buf,TRIPLET_ARCH);
            break;
        case 'c'://ompiler
#if defined(__clang__)
            sprintf(buf,"clang");
#elif defined(__TINYC__)
            sprintf(buf,"tcc");
#elif defined(_MSC_VER)
            sprintf(buf,"msvc");
#elif defined(__GNUC__)
            sprintf(buf,"gcc");
#else
            sprintf(buf,"unknown");
#endif
            break;
        case 'l'://LPARCH
            sprintf(buf,LPARCH);
            break;
        default:
            buf[0]=req;
            buf[1]='\0';
            break;
    }
    snprintf(outbuf + strlen(outbuf), 2024 - strlen(outbuf), "%s", buf);
    }
    return strdup(outbuf);
}
char* _getsysconfig(char* cvmtaobl);
int tcl__getsysconfig(ClientData clientdata, Tcl_Interp *ip, int objc, Tcl_Obj *CONST objv[]) {
  char* _cvmtaobl;
  char* rv;
  if (objc != 2) {
    Tcl_WrongNumArgs(ip, 1, objv, "cvmtaobl");
    return TCL_ERROR;
  }
  _cvmtaobl = Tcl_GetString(objv[1]);
  rv = _getsysconfig(_cvmtaobl);
  if (rv == NULL) {
    return(TCL_ERROR);
  }
  Tcl_SetObjResult(ip,Tcl_NewStringObj( rv, -1 ));
  return TCL_OK;
}
static char* c_ctest1(char* text, int i1) {
    char buf[256];
    for(int i=0;i<100;i++) mytest1(text,i1);
    puts (text);
    sprintf (buf,"size of double %d",sizeof(double));
    puts (buf);
    puts ("Calling tcl evalobjv");
    return mytest1(text,i1); 
}
int tcl_ctest1(ClientData clientdata, Tcl_Interp *ip, int objc, Tcl_Obj *CONST objv[]) {
  char* _text;
  int _i1;
  char* rv;
  if (objc != 3) {
    Tcl_WrongNumArgs(ip, 1, objv, "text i1");
    return TCL_ERROR;
  }
  _text = Tcl_GetString(objv[1]);
  if (Tcl_GetIntFromObj(ip, objv[2], &_i1) != TCL_OK)    return TCL_ERROR;
  rv = c_ctest1(_text, _i1);
  if (rv == NULL) {
    return(TCL_ERROR);
  }
  Tcl_SetObjResult(ip,Tcl_NewStringObj( rv, -1 ));
  return TCL_OK;
}
static char* c_ctest2(char* text, int i1) {
    for(int i=0;i<100;i++) mytest2(text,i1);
    puts (text);
    puts ("Testing LP-Arch");
#ifdef __LP64__ 
    puts ("__LP64__");
#else
    puts ("NOT LP64");
#endif
#ifdef __ILP32__
    puts ("__ILP32__");
#endif
#ifdef LPARCH
    puts (LPARCH);
#endif
    puts ("Calling tcl eval");
    return mytest2(text,i1);
}
int tcl_ctest2(ClientData clientdata, Tcl_Interp *ip, int objc, Tcl_Obj *CONST objv[]) {
  char* _text;
  int _i1;
  char* rv;
  if (objc != 3) {
    Tcl_WrongNumArgs(ip, 1, objv, "text i1");
    return TCL_ERROR;
  }
  _text = Tcl_GetString(objv[1]);
  if (Tcl_GetIntFromObj(ip, objv[2], &_i1) != TCL_OK)    return TCL_ERROR;
  rv = c_ctest2(_text, _i1);
  if (rv == NULL) {
    return(TCL_ERROR);
  }
  Tcl_SetObjResult(ip,Tcl_NewStringObj( rv, -1 ));
  return TCL_OK;
}
static char* c_ctest3(char* text, int i1) {
    char buf[256];
    for(int i=0;i<100;i++) tcl_test2 (text,i1);
    puts (text);
    puts ("Calling tcl proc");
    return tcl_test2 (text,i1); 
}
int tcl_ctest3(ClientData clientdata, Tcl_Interp *ip, int objc, Tcl_Obj *CONST objv[]) {
  char* _text;
  int _i1;
  char* rv;
  if (objc != 3) {
    Tcl_WrongNumArgs(ip, 1, objv, "text i1");
    return TCL_ERROR;
  }
  _text = Tcl_GetString(objv[1]);
  if (Tcl_GetIntFromObj(ip, objv[2], &_i1) != TCL_OK)    return TCL_ERROR;
  rv = c_ctest3(_text, _i1);
  if (rv == NULL) {
    return(TCL_ERROR);
  }
  Tcl_SetObjResult(ip,Tcl_NewStringObj( rv, -1 ));
  return TCL_OK;
}
static void c___before_tclinit(Tcl_Interp* interp) {
    Tcl_SetVar(interp,  "::TCC_COVERSION1", "...before", 0);    
    Tcl_AppendResult(interp, "...before init", NULL);
}
int tcl___before_tclinit(ClientData clientdata, Tcl_Interp *ip, int objc, Tcl_Obj *CONST objv[]) {
  if (objc != 1) {
    Tcl_WrongNumArgs(ip, 1, objv, "");
    return TCL_ERROR;
  }
c___before_tclinit(ip);
  return TCL_OK;
}
static void c___after_tclinit(Tcl_Interp* interp) {
    Tcl_SetVar(interp,  "::TCC_COVERSION2", "...after", 0);    
    Tcl_AppendResult(interp, "...after init", NULL);
}
int tcl___after_tclinit(ClientData clientdata, Tcl_Interp *ip, int objc, Tcl_Obj *CONST objv[]) {
  if (objc != 1) {
    Tcl_WrongNumArgs(ip, 1, objv, "");
    return TCL_ERROR;
  }
c___after_tclinit(ip);
  return TCL_OK;
}
#ifndef DLLEXPORT 
#define DLLEXPORT __declspec(dllexport)
#endif
DLLEXPORT 
int Tccide_tutorial_Init(Tcl_Interp *interp) {
#ifdef USE_TCL_STUBS
  if (Tcl_InitStubs(interp, TCL_VERSION, 0) == 0L) {
    return TCL_ERROR;
  }
#endif
#ifdef USE_TK_STUBS
  if (Tk_InitStubs(interp, TCL_VERSION, 0) == 0L) {
    return TCL_ERROR;
  }
#endif
   c___before_tclinit (interp);//init
  Tcl_CreateObjCommand(interp, "cnop", tcl_cnop, NULL, NULL);
  Tcl_CreateObjCommand(interp, "::tspnop", tspnop, NULL, NULL);
  Tcl_CreateObjCommand(interp, "::tspcalltcl", tspcalltcl, NULL, NULL);
  Tcl_CreateObjCommand(interp, "_getsysconfig", tcl__getsysconfig, NULL, NULL);
  Tcl_CreateObjCommand(interp, "ctest1", tcl_ctest1, NULL, NULL);
  Tcl_CreateObjCommand(interp, "ctest2", tcl_ctest2, NULL, NULL);
  Tcl_CreateObjCommand(interp, "ctest3", tcl_ctest3, NULL, NULL);
  Tcl_PkgProvide(interp, "tccide_tutorial", "1.0");
  mod_Tcl_interp = interp;
   c___after_tclinit  (interp);
  return(TCL_OK);
}

