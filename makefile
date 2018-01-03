CC = gcc
CFLAGS = -Wall -std=c99 -pedantic

BIN = ./bin/

SOURCE_FILES = ./src/LinkedListAPI.c ./src/PriorityQueueAPI.c ./src/Patient.c

main:
	$(CC) $(CFLAGS) $(SOURCE_FILES) ./src/main.c -Iinclude -o ./bin/main

testing:
	$(CC) $(CFLAGS) $(SOURCE_FILES) ./src/testMain.c -Iinclude -o ./bin/testing

clean:
	rm $(wildcard $(BIN)*)