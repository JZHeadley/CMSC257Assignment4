

INCLUDES=-I.
CC=gcc
CFLAGS=-I. -c -g -Wall $(INCLUDES)
LINKARGS=-lm
LIBS=-lm

all : clean jzshell 

jzshell : jzshell.o jzshell_support.o
	$(CC) $(LINKARGS) $^ -o $@ $(LIBS)

jzshell.o : jzshell.c jzshell.h
	$(CC) $(CFLAGS) $< -o $@

jzshell_support.o : jzshell_support.c jzshell.h
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm -f jzshell_support.o jzshell.o jzshell

run : all
	sh run.sh
