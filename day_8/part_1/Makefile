.PHONY: clean

CC := gcc
CCFLAGS := -O0 -g -std=c99 -Wall -Wextra -Wshadow -pedantic
LDFLAGS := 
OBJ_FILES := grid.o main.o
TARGET := main

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CCFLAGS) -o $(TARGET) $(OBJ_FILES) $(LDFLAGS) 

clean:
	rm -rf $(TARGET) $(OBJ_FILES) ~*
