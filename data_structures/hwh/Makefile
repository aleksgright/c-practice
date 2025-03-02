.PHONY: all clean build debug
FOLDER = out
TARGET = $(FOLDER)/app
SOURCE = main.c hash_map.c hash_map_tests.c
CC = gcc

all: build

build: $(TARGET)

$(TARGET): $(SOURCE)
	mkdir $(FOLDER)
	$(CC) -Wall $(SOURCE) -o $(TARGET)

debug: $(SOURCE)
	mkdir $(FOLDER)
	$(CC) -Wall $(SOURCE) -g -o $(TARGET)

check_leaks: debug
	valgrind --leak-check=full $(TARGET)

clean:
	rm -rf out