CC = gcc
CFLAGS = -Wall -ansi -pedantic -O2 -g
LFLAGS = -lm
OUT = ep3
IN = ep3.c
OBJS = ep3.o StringOps.o


all: $(OUT)

clean: 
	rm -f $(OBJS) $(OUT)

$(OUT): $(OBJS) 
	$(CC) $(OBJS) $(CFLAGS) -o $(OUT)

ep3.o: $(IN)
	$(CC) $(IN) $(CFLAGS) -c -o ep3.o
	
StringOps.o: StringOps.c
	$(CC) StringOps.c $(CFLAGS) -c -o StringOps.o



