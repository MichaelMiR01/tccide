# tccide
tccide is a TCL-Starkit to make use of tcc4tcl (TinyC Compiler for TCL) and TSP (Tom Pointdexters Tcl Static Prime TCL Transpiler) 

Starkit contains a modified Version of tcc4tcl (based on tcc 0.9.26), a modified version of TSP and a small Texteditor with Console to directly start coding. This should work with TCL/Tk 8.6 and contains binaries for Win32 and Linux64 (Lin32 is missing, sorry, didn't compile this :-)

The modified sources for TCC and TSP are 
https://github.com/MichaelMiR01/tcc4tcl
https://github.com/MichaelMiR01/tsp

This repo contains also a tar.gz of the complete starkits vfs. I additionally fleshed out tcc4tcl (binary package), tcc4tcl_helper and TSP-Package. This is the heart of the tccide, use these 3 packages together to Transpile and Add C-Code and build TCL/C Mixed Packages.

Documentation is actually lacking behind, sorry.


Sample code to start using tcc and TSP
```
#-----------------------------------------------------------
package require tsp

# init package with packagename
::tsp::init_package tnop 

# we want to add some bare c-code, so we get the tcc-handle
set handle $tsp::TCC_HANDLE
$handle cproc cnop {Tcl_Interp* interp } char* {
     return "cnop ok";
}

# now let's transpile some simple tcl-code
# see Tom Pointdexters Docs with the TSP Project
::tsp::proc tspnop {} {
    #tsp::procdef void
    puts "tspnop"
}

# this will be a pure TCL-proc
proc tclnop {} {
    puts "tclnop "
}

::tsp::printLog 

# finalize the package... compile into memory
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
```
More info in howto_tccide
