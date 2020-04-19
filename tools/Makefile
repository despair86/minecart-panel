# makefile for sqlite3 shell tool
# on solaris libedit subsumes both readline and editline from gnu

all: sqlite3

sqlite3:
	cc -O5 -xtarget=ivybridge -xvector -xipo=2 -xlinkopt=2 -xipo_build -xipo_archive=readonly -DSQLITE_DQS=0 -DSQLITE_DEFAULT_WAL_SYNCHRONOUS -DSQLITE_USE_ALLOCA \
	-DSQLITE_MAX_EXPR_DEPTH=0 -DDSQLITE_ENABLE_FTS3 -DSQLITE_OMIT_SHARED_CACHE -DSQLITE_ENABLE_FTS4 -DSQLITE_ENABLE_FTS5 -DSQLITE_ENABLE_MEMORY_MANAGEMENT \
	-DSQLITE_ENABLE_RBU -DSQLITE_ENABLE_RTREE -DSQLITE_ENABLE_JSON1 -DSQLITE_ENABLE_NULL_TRIM -DSQLITE_DEFAULT_MEMSTATUS=0 -DSQLITE_ENABLE_MEMSYS5 \
	-DSQLITE_OMIT_DEPRECATED -DHAVE_USLEEP -DHAVE_READLINE -DHAVE_EDITLINE -I../include ../src/sqlite3.c shell.c -o sqlite3 -lm -ledit -lcurses -z ignore

clean:
	-rm sqlite3
