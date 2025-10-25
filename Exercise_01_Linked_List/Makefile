# Makefile for Exercise 1: Basic Linked List Operations

CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Default target - builds the starter code
all: linked_list

# Build the starter code
linked_list: starter_code.c
	$(CC) $(CFLAGS) -o linked_list starter_code.c

# Build the solution
solution: solution.c
	$(CC) $(CFLAGS) -o linked_list_solution solution.c

# Run the starter code
run: linked_list
	./linked_list

# Run the solution
run-solution: solution
	./linked_list_solution

# Check for memory leaks using valgrind (if available)
valgrind: linked_list
	valgrind --leak-check=full --show-leak-kinds=all ./linked_list

# Check solution for memory leaks
valgrind-solution: solution
	valgrind --leak-check=full --show-leak-kinds=all ./linked_list_solution

# Clean up compiled files
clean:
	rm -f linked_list linked_list_solution

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
