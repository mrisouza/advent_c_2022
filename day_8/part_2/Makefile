.PHONY: clean

CC := gcc
CCFLAGS := -O0 -g -std=c++11 -Wall -Wextra -Wshadow -pedantic -Weffc++
LDFLAGS :=
OBJFILES := grid.o main.o
TARGET := main

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CCFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -rf $(TARGET) $(OBJFILES) ~*
