# Exercise 1: Basic Linked List Operations

## Learning Objectives
By completing this exercise, you will be able to:
- Create and initialize a linked list node structure
- Add nodes to the beginning and end of a linked list
- Remove nodes with specific values from a linked list
- Traverse and print all elements in a linked list
- Properly free all allocated memory to prevent memory leaks

## Difficulty Level
**Basic** - This exercise introduces fundamental linked list operations that form the foundation for more complex data structures.

## Background
A **linked list** is a dynamic data structure where each element (node) contains:
1. Data (in this case, an integer value)
2. A pointer to the next node in the sequence

Unlike arrays, linked lists can grow and shrink dynamically, and insertions/deletions can happen at any position without shifting elements.

## Instructions

### Part 1: Understanding the Structure
Review the `node_t` structure definition:
```c
typedef struct node {
    int val;           // The data stored in this node
    struct node *next; // Pointer to the next node
} node_t;
```

### Part 2: Complete the Functions
You need to implement the following functions in `starter_code.c`:

1. **add_end()** - Adds a new node with a given value at the end of the list
2. **add_beginning()** - Adds a new node with a given value at the beginning of the list
3. **remove_by_value()** - Removes the first node with a specific value
4. **print_list()** - Displays all values in the list
5. **free_list()** - Frees all memory allocated for the list

### Part 3: Testing
The main function will:
1. Create a list with initial value 5
2. Add value 10 to the end
3. Add value 3 to the beginning
4. Add value 7 to the end
5. Print the list (should show: 3 -> 5 -> 10 -> 7)
6. Remove value 10
7. Print the list again (should show: 3 -> 5 -> 7)
8. Free all memory

### Expected Output
```
Initial list:
3 -> 5 -> 10 -> 7 -> NULL

After removing 10:
3 -> 5 -> 7 -> NULL

All memory freed successfully.
```

## Compilation
Use the provided Makefile:
```bash
make
./linked_list
```

Or compile manually:
```bash
gcc -Wall -Wextra -o linked_list starter_code.c
./linked_list
```

## Common Pitfalls
1. **Memory leaks**: Always free all allocated memory
2. **Dereferencing NULL pointers**: Check if a pointer is NULL before accessing it
3. **Lost head pointer**: When adding to the beginning, update the head pointer correctly
4. **Dangling pointers**: After freeing memory, avoid accessing it

## Tips
- Draw diagrams on paper to visualize pointer changes
- Use `valgrind` to check for memory leaks: `valgrind ./linked_list`
- Test each function individually before combining them

## Related Concepts
- Dynamic memory allocation (`malloc`, `free`)
- Pointers and pointer arithmetic
- Pass-by-reference (using double pointers)

## Time Estimate
30-45 minutes

## References
- Practical 11 (2024) - Question A
- Lecture 27: Linked Lists
