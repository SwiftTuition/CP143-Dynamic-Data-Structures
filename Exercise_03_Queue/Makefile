# Makefile for Exercise 3: Queue Implementation (FIFO)

CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Default target - builds the starter code
all: queue

# Build the starter code
queue: starter_code.c
	$(CC) $(CFLAGS) -o queue starter_code.c

# Build the solution
solution: solution.c
	$(CC) $(CFLAGS) -o queue_solution solution.c

# Run the starter code
run: queue
	./queue

# Run the solution
run-solution: solution
	./queue_solution

# Check for memory leaks using valgrind (if available)
valgrind: queue
	valgrind --leak-check=full --show-leak-kinds=all ./queue

# Check solution for memory leaks
valgrind-solution: solution
	valgrind --leak-check=full --show-leak-kinds=all ./queue_solution

# Clean up compiled files
clean:
	rm -f queue queue_solution

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
