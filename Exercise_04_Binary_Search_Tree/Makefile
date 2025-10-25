# Makefile for Exercise 4: Binary Search Tree (BST)

CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Default target - builds the starter code
all: bst

# Build the starter code
bst: starter_code.c
	$(CC) $(CFLAGS) -o bst starter_code.c

# Build the solution
solution: solution.c
	$(CC) $(CFLAGS) -o bst_solution solution.c

# Run the starter code
run: bst
	./bst

# Run the solution
run-solution: solution
	./bst_solution

# Check for memory leaks using valgrind (if available)
valgrind: bst
	valgrind --leak-check=full --show-leak-kinds=all ./bst

# Check solution for memory leaks
valgrind-solution: solution
	valgrind --leak-check=full --show-leak-kinds=all ./bst_solution

# Clean up compiled files
clean:
	rm -f bst bst_solution

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
