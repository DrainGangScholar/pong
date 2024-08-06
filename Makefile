CC = gcc
CFLAGS = -Wall
LIBS = -lraylib -lm
main: src/main.c
	$(CC) $(LIBS) -o main src/main.c $(LIBS)
