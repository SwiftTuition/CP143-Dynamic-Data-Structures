# Makefile for Exercise 2: Stack Implementation (LIFO)

CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Default target - builds the starter code
all: stack

# Build the starter code
stack: starter_code.c
	$(CC) $(CFLAGS) -o stack starter_code.c

# Build the solution
solution: solution.c
	$(CC) $(CFLAGS) -o stack_solution solution.c

# Run the starter code
run: stack
	./stack

# Run the solution
run-solution: solution
	./stack_solution

# Check for memory leaks using valgrind (if available)
valgrind: stack
	valgrind --leak-check=full --show-leak-kinds=all ./stack

# Check solution for memory leaks
valgrind-solution: solution
	valgrind --leak-check=full --show-leak-kinds=all ./stack_solution

# Clean up compiled files
clean:
	rm -f stack stack_solution

# Help message
help:
	@echo "Available targets:"
	@echo "  make          - Build the starter code"
	@echo "  make solution - Build the solution"
	@echo "  make run      - Build and run the starter code"
	@echo "  make run-solution - Build and run the solution"
	@echo "  make valgrind - Run starter code with valgrind memory check"
	@echo "  make valgrind-solution - Run solution with valgrind memory check"
	@echo "  make clean    - Remove all compiled files"
	@echo "  make help     - Show this help message"

.PHONY: all solution run run-solution valgrind valgrind-solution clean help
