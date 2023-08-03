 # ypedit.tcl --
 #    Shell procedures for Young Programmers Project:
 #    It defines several utility commands:
 #    ed       - edit a file
 #    vw       - view the contents of a file
 #

 package require Tk

 # ypshell --
 #    Namespace for the commands
 #
 namespace eval ::ypshell {

    namespace export ed vw

    variable editfile
    set editfile(count) 0
    
 }

 # ed --
 #    Edit a file
 #
 # Arguments:
 #    filename   Name of the file to edit
 #
 # Return value:
 #    None
 #
 proc ::ypshell::ed { {filename ""} } {
    ::ypshell::EditFile 1 0 $filename
 }

 # vw --
 #    View a file
 #
 # Arguments:
 #    filename   Name of the file to view
 #
 # Return value:
 #    None
 #
 proc ::ypshell::vw { filename } {
    ::ypshell::EditFile 0 0 $filename
 }

 # EditFile --
 #    Edit or view a file (actual procedure)
 #
 # Arguments:
 #    editable   Select edit mode (1=edit, 0=view)
 #    newopen    Allow new/open menu items (1=yes, 0=no)
 #    filename   Name of the file to edit/view
 #
 # Return value:
 #    None
 #
 proc ::ypshell::EditFile { editable newopen filename } {
    variable editfile

    incr editfile(count)
    set  w .edit$editfile(count)
    toplevel $w
    #wm withdraw .
    wm title $w "Edit/view: $filename"

    set  mb $w.menubar
    frame      $mb
    pack       $mb -side top -fill x -pady 0
    menubutton $mb.file   -text File   -menu $mb.file.menu    -underline 0
    menubutton $mb.edit   -text Edit   -menu $mb.edit.menu    -underline 0
    menubutton $mb.search -text Search -menu $mb.search.menu  -underline 0
    menubutton $mb.help   -text Help   -menu $mb.help.menu    -underline 0

    menu       $mb.file.menu   -tearoff false
    menu       $mb.edit.menu   -tearoff false
    menu       $mb.search.menu -tearoff false
    menu       $mb.help.menu   -tearoff false

    pack       $mb.file $mb.edit $mb.search -side left
    pack       $mb.help -side left ;# Platform-dependent!

    #
    # Set up the "File" menu
    #
    $mb.file.menu add command -label New -underline 0 \
     -command [list ::ypshell::ed]
    if { $newopen } {
       if { $editable } {
          $mb.file.menu add command -label New -underline 0 \
             -command [list ::ypshell::NewFile]
       }
       $mb.file.menu add command -label Open -underline 0 \
          -command [list ::ypshell::OpenFile]
       $mb.file.menu add separator
    }

    if { $editable } {
       $mb.file.menu add command -label Save -underline 0 \
          -command [list ::ypshell::SaveFile $w $filename 0]
       #if { $newopen } {
          $mb.file.menu add command -label "Save as ..." -underline 1 \
             -command [list ::ypshell::SaveFile $w $filename 1]
       #}
       $mb.file.menu add separator
    }
    $mb.file.menu add command -label Exit -underline 1 \
       -command [list ::ypshell::ExitEdit $w $newopen $editable $filename]

    #
    # Set up the "Edit" menu
    #
    if { $editable } {
       #$mb.edit.menu add command -label "Undo" -underline 0 \
       #   -command [list ::ypshell::UndoChange]
       #$mb.edit.menu add command -label "Redo" -underline 0 \
       #   -command [list ::ypshell::RedoChange]
       #$mb.edit.menu add separator
    }
    #$mb.edit.menu add command -label "Mark line(s)" -underline 0 \
    #   -command [list ::ypshell::MarkLines]
    #$mb.edit.menu add command -label "Unmark line(s)" -underline 1 \
    #   -command [list ::ypshell::UnmarkLines]
    $mb.edit.menu add command -label "Run line(s)" -underline 1 \
       -command [list ::ypshell::RunText $w]
    
    $mb.edit.menu add separator
    #$mb.edit.menu add command -label "Copy" -underline 0 \
    #   -command [list ::ypshell::CopyBlock]
    #if { $editable } {
    #   $mb.edit.menu add command -label "Paste" -underline 0 \
    #      -command [list ::ypshell::PasteBlock]
    #   $mb.edit.menu add separator
    #   $mb.edit.menu add command -label "Delete" -underline 0 \
    #      -command [list ::ypshell::DeleteBlock]
    #}

    #
    # Set up the "Search" menu
    #
    $mb.search.menu add command -label "Find" -underline 0 \
       -command [list ::ypshell::FindText $w]
    #if { $editable } {
    #   $mb.search.menu add command -label "Replace" -underline 0 \
    #   -command [list ::ypshell::ChangeText]
    #}

    #
    # Set up the "Help" menu
    #
    $mb.help.menu add command -label "Console" -underline 1 \
       -command [list console show]
    #$mb.help.menu add command -label "Overview" -underline 1 \
    #   -command [list ::ypshell::HelpOverview]
    #$mb.help.menu add command -label "About" -underline 0 \
    #   -command [list ::ypshell::AboutEdit]
    $mb.help.menu add command -label "Edit Config" -underline 1 \
       -command [list UserconfigEditor #auto]

    #
    # Create a thin separator
    #
    set ts $w.separator
    frame $ts -height 2 -relief sunken -borderwidth 1
    pack  $ts -side top -fill x

    #
    # Create the toolbar
    #
    set fnt       "Courier, 10"
    set fnt       "systemfixed"
    set fixedfont "systemfixed"
    set tb  $w.toolbar
    frame $tb -height 10
    button $tb.goto   -text "Go to:" -command [list ::ypshell::GotoLine $w ""]
    entry  $tb.lineno -textvariable ::ypshell::editfile(lineno,$w) \
       -width 5 -font $fnt
    button $tb.top    -text "Top"    -command [list ::ypshell::GotoLine $w 1]
    button $tb.bottom -text "Bottom" -command [list ::ypshell::GotoLine $w end]
    button $tb.run    -text "Run"    -command [list ::ypshell::RunText $w]
    label  $tb.empty1 -text " "
    label  $tb.empty2 -text " "
    label  $tb.empty3 -text " "

    set ::ypshell::editfile(lineno,$w) 1

    pack   $tb.goto $tb.lineno $tb.empty1 $tb.top $tb.bottom $tb.empty2 $tb.run $tb.empty3 -side left

    button $tb.find   -text "Find:" -command [list ::ypshell::FindText $w]
    entry  $tb.string -textvariable ::ypshell::editfile(find,$w) \
       -font $fnt
    bind $tb.string <Return> [list ::ypshell::FindText $w]
    set ypshell::editfile(find,$w) ""

    pack   $tb.goto $tb.find $tb.string -side left

    pack   $tb -fill x -side top

    #
    # Create the text widget and the scroll bars
    #
    set tf $w.textframe
    set tw $tf.text
    frame $tf
    scrollbar $tf.scrollx -orient horiz -command "$tw xview"
    scrollbar $tf.scrolly               -command "$tw yview"
    text      $tw         -yscrollcommand "$tf.scrolly set" \
                          -xscrollcommand "$tf.scrollx set" \
                          -font $fixedfont

    grid      $tw         $tf.scrolly
    grid      $tf.scrollx x
    grid      $tw         -sticky news
    grid      $tf.scrolly -sticky ns
    grid      $tf.scrollx -sticky ew

    grid columnconfigure $tf 0 -weight 1
    grid rowconfigure    $tf 0 -weight 1

    $tw configure -wrap none

    pack $tf -fill both -side top -expand 1

    set ypshell::editfile(textwidget,$w) $tw
    bind $tw <Control-Key-Return> "::ypshell::RunText $w;break;"
    bind $tw <Control-Key-l> "::ypshell::LoadFile $tw {} ;break;"
    bind $tw <Control-Key-d> "::ypshell::DeleteLine $tw ;"
    bind $tw <Control-Key-a> "::ypshell::SelectAll $tw ;break;"
    bind $tw <Control-Key-f> "::ypshell::FindText $w ;break;"
    bind $tw <Tab> "::ypshell::Softtab $tw ;break;"

    catch {
        package require hl_tcl
        #https://wiki.tcl-lang.org/page/hl%5Ftcl%2C+Tcl%2FTk+syntax+highlighter
        ::hl_tcl::hl_init $tw
        #... inserting a text into the text widget
    }
    catch {
        if {$filename!=""} {
            LoadFile $tw $filename
        }
    }
    catch {
        # start highlighting
        ::hl_tcl::hl_text $tw
    }
    
    return $tw
 }
 proc ::ypshell::AddConsole {w {tkcon 0}} {
     #
    if {$tkcon>0} {
    frame $w.consoleframe
    pack $w.consoleframe -side top -expand 1 -fill both
        ::ypshell::initTkCon $w.consoleframe.tkcon
       catch { console hide}
       return ""
    }
    frame $w.consoleframe
    pack $w.consoleframe -side top -expand 1 -fill both
    set MyConsole $w.consoleframe.tkcon
    scrollbar $w.consoleframe.sb -orient vertical -command "$MyConsole yview"
    pack $w.consoleframe.sb -side right -fill y
    text $MyConsole -font fixed -yscrollcommand "$w.consoleframe.sb set"
    pack $MyConsole -side right -fill both -expand 1
    $MyConsole configure -height 15
    bind $MyConsole <Control-Key-Return> "::ypshell::RunConsole $MyConsole;break;"
    bind $MyConsole <Return> "::ypshell::RunConsole $MyConsole;"
    
    return $MyConsole
 }
 proc ::ypshell::initTkCon {tw} {
     # tkcon.tcl should be sourced earlier
    #------------------------------------------------------
     #  The console doesn't exist yet.  If we create it
     #  with show/hide, then it flashes on the screen.
     #  So we cheat, and call tkcon internals to create
     #  the console and customize it to our application.
     #------------------------------------------------------
     set tkcon::PRIV(showOnStartup) 1
     set tkcon::PRIV(root) $tw
     set tkcon::PRIV(protocol) {}
     set tkcon::OPT(exec) ""
     set tkcon::OPT(embed) true

     tkcon::Init
     tkcon title "My Application Console"
     return tkcon
 }
 proc ::ypshell::DeleteLine {tw} {
        set cursor_pos [$tw index insert]
        set line [expr int($cursor_pos)]
        set line_text [$tw delete ${line}.0 ${line}.end]
 }     
 proc ::ypshell::SelectAll {tw} {
        $tw tag add sel "1.0" "end"
 }     
 
 # LoadFile --
 #    Load the file into the text widget
 #
 # Arguments:
 #    textw      Text widget to use
 #    filename   Name of the file to edit/view
 #
 # Return value:
 #    None
 #
 proc ::ypshell::LoadFile { textw filename } {
    if {$filename==""} {
        set ftypes {{"*" {* *} }}
        set filename [tk_getOpenFile \
            -title "Text laden" \
            -parent . \
            -initialfile "" \
            -initialdir "." \
            -filetypes $ftypes ]
    }
    if {$filename==""} {return}
    
    set infile [ open "$filename" "r" ]
    set txt ""
    while { ! [ eof $infile ] } {
       gets $infile line
       append txt $line\n
    }
   $textw insert end $txt
   #$textw insert end "\n"

    close $infile
 }
 proc ::ypshell::LoadText { textw srccode } {

    $textw insert end $srccode
    $textw insert end "\n"

 }


proc ::ypshell::Softtab {tw {ntabs 4}} {
	#emulate softtabs
	set idx [$tw index insert]
	for {set i 0} {$i<$ntabs} {incr i} {
		$tw insert $idx " "
	}
}


 # SaveFile --
 #    Save the file (possibly under a different name)
 #
 # Arguments:
 #    w          Main widget holding the text
 #    filename   Name of the file to edit/view
 #    newname    Ask for a new name or not
 #
 # Return value:
 #    None
 #
 proc ::ypshell::SaveFile { w filename newname } {
    variable editfile

    set tw $editfile(textwidget,$w)
    if {$tw == ""} {return}
    if {[catch {
        $tw get 0.0
    } e]} {puts "Err: $e";return}
    puts "Saving from $tw to $filename $newname"
    # Select a new file name -- TODO
    if {$newname} {
        set ftypes {{"*" {* *} }}
        set filename [tk_getSaveFile \
            -title "Text speichern" \
            -parent . \
            -initialfile "" \
            -initialdir "." \
            -filetypes $ftypes ]
    }
    if {$filename==""} {set filename "__lastsaved__.tcl"}
    set outfile [ open "$filename" "w" ]

    set lineno 1
    set lastline ""
    while { [$tw compare $lineno.0 < end] } {
        set pre ""
        set post ""
        set line [$tw get "$lineno.0" "$lineno.0 lineend"]
        if {[string trim $line] ne ""} {
            if {[$tw compare $lineno.0 >= end]} {
                continue
            }
           if {[string trimright $line] eq "\}"} {
               set post "\n"
           } else {
               set tok [lindex [split [string trim $line] " "] 0]
               if {[lsearch "proc class method body constructor destructor ::tsp::proc tsp::proc" $tok]>-1} {
                   if {$lastline ne "\n"} {
                       set pre "\n"
                   }
               }
           }
           puts $outfile "$pre$line$post"
           set lastline $post
        }
        incr lineno
    }

    close $outfile
 }

 # GotoLine --
 #    Go to a specified line number
 #
 # Arguments:
 #    w          Main widget containing the text widget
 #    pos        Position
 #
 # Return value:
 #    None
 #
 proc ::ypshell::GotoLine { w pos } {
    variable editfile

    set tw $editfile(textwidget,$w)
    if { $pos == "" } {
       set pos $editfile(lineno,$w)
    }

    if { $pos == "end" } {
       $tw mark set current "end linestart"
    } else {
       $tw mark set current "$pos.0"
    }
    $tw mark set insert [$tw index current]
    $tw see current

    focus $tw
 }

 # FindText --
 #    Find a text string
 #
 # Arguments:
 #    w          Main widget containing the text widget
 #
 # Return value:
 #    None
 #
 proc ::ypshell::FindText { w } {
    variable editfile

    set string $editfile(find,$w)
    set tw     $editfile(textwidget,$w)

    if { $string != "" } {
       set newpos [$editfile(textwidget,$w) search -forwards -exact -nocase -- $string "insert + 1 chars"]

       if { $newpos != "" } {
          $tw mark set current $newpos
          $tw mark set insert [$tw index current]
          $tw see current
          focus $tw
       }
    }
 }

 # ExitEdit --
 #    Exit and save the file (if wanted)
 #
 # Arguments:
 #    w          Widget from which it is called
 #    editable   Select edit mode (1=edit, 0=view)
 #    newopen    Allow new/open menu items (1=yes, 0=no)
 #    filename   Name of the file to edit/view
 #
 # Return value:
 #    None
 #
 proc ::ypshell::ExitEdit { w editable newopen filename } {
    if { $editable } {
       if { !$newopen } {
          SaveFile $w $filename 0
       } else {
          # Ask whether to save or not
       }
    }

    destroy $w
    exit
 }

 #
 # Simple test code
 #
 # namespace import ::ypshell::ed
 # namespace import ::ypshell::vw

 # ed [file join [file dirname [info script]] ypedit.tcl]
 # vw [file join [file dirname [info script]] ypedit.tcl]
 proc ::ypshell::RunText { w } {
     variable editfile
     #puts $editfile;
     SaveFile $w "__lastsaved__.tcl" 0
     set tw     $editfile(textwidget,$w)
     set cmd ""
    catch {
        set start 1.0
        set end "end"
        catch {
            set start [$tw index sel.first]
            set end [$tw index sel.last]
        }
        set cmd [$tw get $start $end]
    }
    if {$cmd==""} {
        return
    }
    #puts $cmd
    #could also use ::tsp::safeEval $cmd
    #if {[catch {
    #    set r [namespace eval :: "$cmd"]
    #    puts "Result: $r"
    #} err]} {
    #    ::ypshell::onError $err
    #}
    ::tsp::safeEval $cmd
 }     

 proc ::ypshell::onError {err} {
     puts "Eval Error: \n$err\n"
     if {[info command ::onEval_onError] eq "::onEval_onError"} {
         ::onEval_onError $err
     }
 }
 
 proc ::ypshell::RunConsole { consw } {
     set tw     $consw
     set cmd ""
     set pre "\n"
    catch {
        set line [lindex [split [$tw index insert] .] 0]
        set start "$line.0"
        set end "$line.end"
        set pre "\n\n"
        catch {
            set start [$tw index sel.first]
            set end [$tw index sel.last]
        }
        set cmd [$tw get $start $end]
    }
    if {$cmd==""} {
        return
    }

    if {[catch {
        if {$line < [expr int([$tw index end-1c])]} {
            puts "$cmd\n"
        }
        set r [namespace eval :: "$cmd"]
        puts "Result: $r"
    } err]} {
        ::ypshell::onError $err
    }
 }     




