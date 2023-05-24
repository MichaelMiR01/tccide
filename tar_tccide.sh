now=$(date +"%y%m%d")
tar -zcf tccide_$now.tar.gz tccide.vfs/* --exclude=depr --exclude=cvs --exclude=backup_n.tcl
actdir=$(pwd)
cd  tccide.vfs/lib/
tar -zcf tcc4tcl_$now.tar.gz tcc4tcl-*/* --exclude=depr --exclude=cvs --exclude=backup_n.tcl
tar -zcf tsp-package_$now.tar.gz tsp-package/* --exclude=depr --exclude=cvs --exclude=backup_n.tcl
tar -zcf tclcinvoke_$now.tar.gz tclcinvoke/* --exclude=depr --exclude=cvs --exclude=backup_n.tcl
cd $actdir
mv -f tccide.vfs/lib/*_$now.tar.gz ./

