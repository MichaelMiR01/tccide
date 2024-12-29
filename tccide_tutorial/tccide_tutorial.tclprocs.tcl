#  TSP Pure TCL procs for loadlib failure management
#   package tccide_tutorial
package provide tccide_tutorial 1.0
proc tspnop {} {
    #tsp::procdef void
    puts ".tspnop ok"
    puts "runtime: [clock format [clock seconds]]"
}

proc tspcalltcl {} {# call via tsp
    #tsp::procdef void
    tcl_test "tsp::tcl_test ok" 12345
}

proc tspinlinec {} {
    #tsp::procdef int -args 
    #tsp::inlinec puts(c_ctest3("from tsp::inlinec",123));
    return 0;
}

proc cnop {} {puts {Not implemented "cnop"}}

proc _getsysconfig {cvmtaobl} {puts {Not implemented "_getsysconfig"}}

proc _tclstuff_h_ {} {puts {Not implemented "_tclstuff_h_"}}

proc ctest1 {text i1} {puts {Not implemented "ctest1"}}

proc ctest2 {text i1} {puts {Not implemented "ctest2"}}

proc ctest3 {text i1} {puts {Not implemented "ctest3"}}

proc __before_tclinit {} {puts {Not implemented "__before_tclinit"}}

proc __after_tclinit {} {puts {Not implemented "__after_tclinit"}}

