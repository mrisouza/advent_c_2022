.PHONY: clean

CC := gcc
CCFLAGS := -O0 -g -std=c99 -Wall -Wextra -Wshadow -pedantic
LDFLAGS := 
OBJFILES := file_handler.o main.o
TARGET := main

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CCFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -rf $(TARGET) $(OBJFILES) ~*
