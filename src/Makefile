SHELL = /sbin/sh
INCS =  -I../include
CFLAGS = $(INCS) -O5 -xtarget=ivybridge -xvector -xipo -xlinkopt -xipo_build
OBJS = main.o login.o sqlite3.o bcrypt.o crypt_gensalt.o crypt_blowfish.o x86.o wrapper.o

all: $(OBJS)
	cc $(OBJS) -O5 -xtarget=ivybridge -xvector -xipo=2 -xlinkopt=2 -xipo_build -xipo_archive=readonly -o minecart-panel -L../lib -lkcgihtml -z ignore -lkcgi -lz -lsocket -lnsl

main.o: main.c
login.o: login.c
sqlite3.o: sqlite3.c
crypt_blowfish.o: crypt_blowfish.c
crypt_gensalt.o: crypt_gensalt.c
bcrypt.o: bcrypt.c
x86.o: x86.S
wrapper.o: wrapper.c

clean:
	find . -name \*.o -delete
	-rm minecart-panel

