OBJECTS = solver.o expression.o
TARGET = solver

CC = gcc
CFLAGS = -Wall -Wextra -Wmissing-prototypes --pedantic\
         -std=c99
.PHONY: all run clean

all: $(TARGET)
run: $(TARGET)
	./$<
clean:
	rm -f $(OBJECTS) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $@ $(CFLAGS)
expression.o: expression.c expression.h
solver.o: solver.c expression.h
