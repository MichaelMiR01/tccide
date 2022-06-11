# tccide
tccide is a TCL-Starkit to make use of tcc4tcl (TinyC Compiler for TCL) and TSP (Tom Pointdexters Tcl Static Prime TCL Transpiler) 

Starkit contains a modified Version of tcc4tcl (based on tcc 0.9.26), a modified version of TSP and a small Texteditor with Console to directly start coding.

Sample code to start using tcc and TSP

#-----------------------------------------------------------
package require tsp

::tsp::init_package tnop 

set handle $tsp::TCC_HANDLE
$handle cproc cnop {Tcl_Interp* interp } char* {
     return "cnop ok";
}

::tsp::proc tspnop {} {
    #tsp::procdef void
    puts "tspnop"
}

proc tclnop {} {
    puts "tclnop "
}

::tsp::printLog 
::tsp::finalize_package tnop memory

# test
puts [cnop]
tspnop
tclnop

# should result
#cnop ok
#tspnop
#tclnop
#--------------------------------------------------
