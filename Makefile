CC = cc
CFLAGS = -Wall -I/include
LDFLAGS = -L/lib -lraylib -lm

main: src/main.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o main src/main.c
