SHELL = /sbin/sh
INCS =  -I../include
CFLAGS = $(INCS)

OBJS = main.o

all: $(OBJS)
	cc $(OBJS) -o minecart-panel -L../lib -lkcgihtml -lkcgi -lz -lsocket -lnsl

main.o: main.c

clean:
	find src/ -name *.*o -exec rm -f {} \;

