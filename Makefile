CC = cc
CFLAGS = -Wall 
LDFLAGS =  -lraylib -lm

main: src/main.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o main src/main.c
