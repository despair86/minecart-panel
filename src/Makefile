SHELL = /sbin/sh
INCS =  -I../include
CFLAGS = $(INCS)

OBJS = main.o login.o

all: $(OBJS)
	cc $(OBJS) -o minecart-panel -L../lib -lkcgihtml -lkcgi -lz -lsocket -lnsl

main.o: main.c
login.o: login.c

clean:
	find . -name \*.o -delete
	-rm minecart-panel

