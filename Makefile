CC = cc
CFLAGS = -Wall -Iyour_project_folder/include
LDFLAGS = -Lyour_project_folder/lib -lraylib -lm

main: src/main.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o main src/main.c
