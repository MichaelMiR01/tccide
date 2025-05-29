#some demo code for tcc4tcl and tsp
# get compiler from user
# proc ask_compiler is defined in tccide!
# set compiler [ask_compiler]
set ct [clock seconds]
set compiletime [clock format $ct]
package require tsp
#tsp::debug ./dbg
#::tsp::init_package {packagename {packagenamespace ""} {packageversion 1.0} {tclversion TCL_VERSION}} 
::tsp::init_package tccide_tutorial 
set handle $::tsp::TCC_HANDLE
#$handle add_library_path /usr/lib/x86_64-linux-gnu
set compilerinfo $::compiler
if {$::compiler=="intern"||$::compiler=="export"} {
    set compilerinfo "$::compiler ($TCC_VERSION)"
}

# create a simple cproc from a constant string
set _cstring "return \"compiled $::compiletime with $compilerinfo\";\n"
$handle cproc cnop {} char* $_cstring
# a transpiled procedure

::tsp::proc tspnop {} {
    #tsp::procdef void 
    #tsp::string s c f
    set s "string 1"
    set c "string 2"
    set s "append $s and $c ok"
    puts ".tspnop ok $s"
    puts "runtime: [clock format [clock seconds]]"
}

::tsp::proc tspnop_ar {} {
    #tsp::procdef void
    #tsp::array fl 
    #tsp::boolean bool
    #tsp::int i
    #tsp::string s s2 ix
    puts "tspnop"
    set fl(ok) flok
    set ix "ok"
    puts "ix is $ix"
    set bool [info exists fl(ok)]
    puts "flok is $fl(ok) ... $bool"
    set s $fl($ix)
    puts "###fl of $ix is $s = $fl($ix) $fl(ok)"
    puts "ready"
}

::tsp::proc testar {} {
    #tsp::procdef void
    #tsp::int i _i
    #tsp::string _s s
    #tsp::var  mytest m1 m2
    #tsp::array myarr
    set mytest "mytest ok"
    puts $mytest
    lset mytest 0 "also"
    puts $mytest
    for {set i 0} {$i<10} {incr i} {
        set myarr($i) $i
    }
    set s "ab"
    set s "$s de"
    set s $s$s
    set myarr($s) "ok"
    puts "myarr($s) is $myarr($s)"
    for {set i 0} {$i<10} {incr i} {
        set _i $myarr($i)
        if {$_i != $i} {
            puts "failed array test myarr($i) is not $i but $myarr($i)"
        }
    }
    for {set i 0} {$i<10} {incr i} {
        set myarr($i) "text with $i"
    }
    for {set i 0} {$i<10} {incr i} {
        set _s $myarr($i)
        set s "text with $i"
        if {$_s != $s} {
            puts "failed array test myarr($i) is not $_s but $s"
        }
    }
    for {set i 0} {$i<10} {incr i} {
        set s "..$i"
        puts $i
        puts $s
    }
}

# a pure tcl proc

proc tclnop {} {
    puts "tclnop ok"
}

# howto bind a pure tcl proc into c-code
# first we define the proc

proc tcl_test {a b} {# pure tcl proc
    if {$a ne ""} {
        return "TCL TEST OK, \n$a\nResult of 2* $b = [expr $b*2]"
    }
    return [expr $b*2]
}

#
# let's try precompiled string evaled proc from tcc4tcl
# this should be callable by name from c
#
$handle proc tcl_test2 {char* a int b} char* {# pure tcl proc
    if {$a ne ""} {
        return "TCL TEST 2 OK, \n$a\nResult of 3* $b = [expr $b*3]"
    }
    return [expr $b*3]
}

# bind via c wraped tcl procs
# via $handle tclwrap tcl_test {char* text int i} char* mytest1
#
$handle tclwrap tcl_test {char* text int i} char* mytest1
$handle tclwrap_eval tcl_test {char* text int i} char* mytest2
#
# first: call from tsp
# easy, just call the tcl name of proc
#
# via tsp

::tsp::proc tspcalltcl {} {# call via tsp
    #tsp::procdef void
    tcl_test "tsp::tcl_test ok" 12345
}

# for the follwoing c-code we invoke some helper funcs
#
# invoke puts as helperfunc
# $handle tclhelperfunc puts
# tclhelperfunc is defined in tcl_helpers.tcl wich is part of tccide
# same can be achieved by binding via
# 
# $handle ccode {#define puts tclputs}
# $handle tclwrap puts {char* text} char* tclputs
#
$handle tclhelperfunc puts
$handle tclhelperfunc printf
$handle tclhelperfunc _getsysconfig
$handle tclhelperfunc _tclstuff_h_
# some c procs to demonstrate different calling mechanisms
$handle cproc ctest1 {Tcl_Interp* interp char* text int i1} char* {
    char buf[256];
    for(int i=0;i<100;i++) mytest1(text,i1);
    puts ("#---");
    puts (text);
    printf ("printf size of double %d\n",sizeof(double));
    puts ("Calling tcl evalobjv");
    //puts (buf);
    return mytest1(text,i1); 
}

$handle cproc ctest2 {char* text int i1} char* {
    for(int i=0;i<100;i++) mytest2(text,i1);
    puts ("#---");
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

$handle cproc ctest3 {char* text int i1} char* {
    char buf[256];
    for(int i=0;i<100;i++) tcl_test2 (text,i1);
    puts ("#---");
    puts (text);
    puts ("Calling tcl proc");
    return tcl_test2 (text,i1); 
}

# dynamic lib packages get loaded and initialised 
# you can insert c-code before and after module initialisation
# with __before_tclinit and __after_tclinit
$handle cproc __before_tclinit {Tcl_Interp* interp} void {
    Tcl_SetVar(interp,  "::TCC_COVERSION1", "...before", 0);    
    Tcl_AppendResult(interp, "...before init", NULL);
}

$handle cproc __after_tclinit {Tcl_Interp* interp} void {
    Tcl_SetVar(interp,  "::TCC_COVERSION2", "...after", 0);    
    Tcl_AppendResult(interp, "...after init", NULL);
}

# {packagename]_pkgInit proc will get called last, after loading all other stuff
set ::TCC_COVERSION3 "-"

proc tccide_tutorial_pkgInit {} {
    set ::TCC_COVERSION3 "...tcl aFTER"  
    puts "initialised!"  
}

set cc [$handle code]
::tsp::printLog 
# ::tsp::finalize_package {{packagedir ""} {compiler none}} 
puts [$handle add_library_path ]
::tsp::finalize_package tccide_tutorial $compiler
# compiler can be intern or export (uses tcc4tcl) or tccwin32 // gccwin32 // gcclin64 etc (will try using external build environment)
# [ask_compiler] is built into tccide and will open a dialog to choose from
# some testing routines

proc test_intern {} {
# test module init
    puts "Coversions: $::TCC_COVERSION1 $::TCC_COVERSION2 $::TCC_COVERSION3"
# test helperfunc directly
    puts [_getsysconfig c-vm-aol]
# test c, tsp and tcl based procedures
    puts [cnop];tspnop;tclnop;
# test different caller for tcl proc from c
    puts [ctest1 tclobj 1234]
    puts [ctest2 tcleval 1234]
    puts [ctest3 tclproc 1234]
    puts [tcl_test tclpure 1234]
    puts [tspcalltcl]
    puts [testar]
    tccide_tutorial_help
}

proc test_extern {} {
    ::tsp::test_packageX tccide_tutorial [info body test_intern]
}

# and choosing from tests by compiler
# setting compiler to empty will compile intern and run no test
if {$compiler=="intern"} {
    test_intern
} else {
    if {$compiler!=""} {
        puts exported
        test_extern
    }
}

