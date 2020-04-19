# Makefile for Solaris 2.x
SHELL = /sbin/sh
INCS =  -I../include
CFLAGS = $(INCS) -O5 -xtarget=ivybridge -xvector -xipo -xlinkopt -xipo_build
OBJS = main.o login.o sqlite3.o bcrypt.o crypt_gensalt.o crypt_blowfish.o x86.o wrapper.o

all: $(OBJS)
	cc $(OBJS) -O5 -xtarget=ivybridge -xvector -xipo=2 -xlinkopt=2 -xipo_build -xipo_archive=readonly -o minecart-panel -L../lib -lkcgihtml -z ignore -lkcgi -lz -lsocket -lnsl -lm

main.o: main.c
login.o: login.c
sqlite3.o: sqlite3.c
	cc $(CFLAGS) -DSQLITE_DQS=0 -DSQLITE_DEFAULT_WAL_SYNCHRONOUS -DSQLITE_USE_ALLOCA \
	-DSQLITE_MAX_EXPR_DEPTH=0 -DDSQLITE_ENABLE_FTS3 -DSQLITE_ENABLE_FTS4 -DSQLITE_ENABLE_FTS5 -DSQLITE_ENABLE_MEMORY_MANAGEMENT \
	-DSQLITE_ENABLE_RBU -DSQLITE_ENABLE_RTREE -DSQLITE_ENABLE_JSON1 -DSQLITE_OMIT_SHARED_CACHE -DSQLITE_DEFAULT_MEMSTATUS=0 -DSQLITE_ENABLE_NULL_TRIM \
	-DSQLITE_ENABLE_MEMSYS5 -DSQLITE_OMIT_DEPRECATED -DHAVE_USLEEP $< -c
crypt_blowfish.o: crypt_blowfish.c
crypt_gensalt.o: crypt_gensalt.c
bcrypt.o: bcrypt.c
x86.o: x86.S
wrapper.o: wrapper.c

clean:
	find . -name \*.o -delete
	-rm minecart-panel

