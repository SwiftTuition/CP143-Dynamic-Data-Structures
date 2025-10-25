# Exercise 2: Stack Implementation (LIFO)

## Learning Objectives
By completing this exercise, you will be able to:
- Understand the Last-In-First-Out (LIFO) principle
- Implement a stack using a linked list
- Perform push (add to top) and pop (remove from top) operations
- Peek at the top element without removing it
- Check if a stack is empty
- Properly manage memory for a stack data structure

## Difficulty Level
**Medium** - This exercise builds on linked list knowledge to implement a specific data structure with constraints.

## Background
A **stack** is a linear data structure that follows the **Last-In-First-Out (LIFO)** principle. Think of it like a stack of plates:
- You can only add a plate to the top (**push**)
- You can only remove a plate from the top (**pop**)
- You can look at the top plate without removing it (**peek**)

### Real-World Applications:
- Function call stack in programming
- Undo/Redo functionality in text editors
- Browser back button history
- Expression evaluation and syntax parsing

### Stack Operations:
1. **Push**: Add an element to the top of the stack
2. **Pop**: Remove and return the top element
3. **Peek**: View the top element without removing it
4. **isEmpty**: Check if the stack is empty

## Instructions

### Part 1: Understanding the Structure
Review the `stack_node_t` structure definition:
```c
typedef struct stack_node {
    int data;                    // The value stored in this node
    struct stack_node *next;     // Pointer to the next node (below this one)
} stack_node_t;
```

### Part 2: Complete the Functions
You need to implement the following functions in `starter_code.c`:

1. **push()** - Adds a new element to the top of the stack
2. **pop()** - Removes and returns the top element from the stack
3. **peek()** - Returns the top element without removing it
4. **is_empty()** - Checks if the stack is empty
5. **print_stack()** - Displays all elements in the stack (top to bottom)
6. **free_stack()** - Frees all memory allocated for the stack

### Part 3: Testing
The main function will:
1. Create an empty stack
2. Push values: 10, 20, 30, 40, 50 (in that order)
3. Print the stack (should show 50 at top)
4. Pop two values (should remove 50 and 40)
5. Peek at the top (should show 30)
6. Print the stack again
7. Free all memory

### Expected Output
```
Pushing: 10
Pushing: 20
Pushing: 30
Pushing: 40
Pushing: 50

Stack contents (top to bottom):
50
40
30
20
10

Popped: 50
Popped: 40

Top element (peek): 30

Stack contents after popping:
30
20
10

All memory freed successfully.
```

## Compilation
Use the provided Makefile:
```bash
make
./stack
```

Or compile manually:
```bash
gcc -Wall -Wextra -o stack starter_code.c
./stack
```

## Common Pitfalls
1. **Stack underflow**: Trying to pop from an empty stack
2. **Memory leaks**: Not freeing all nodes when done
3. **Lost top pointer**: Forgetting to update the top pointer after push/pop
4. **Dereferencing NULL**: Trying to peek at an empty stack

## Tips
- The top of the stack is always the head of the linked list
- Push is similar to `add_beginning()` from Exercise 1
- Pop must update the top pointer and free the removed node
- Always check if the stack is empty before popping or peeking
- Draw diagrams to visualize how the top pointer changes

## Comparison with Linked List
| Operation | Stack | Linked List |
|-----------|-------|-------------|
| Add | Push (top only) | Can add anywhere |
| Remove | Pop (top only) | Can remove anywhere |
| Access | Peek (top only) | Can access any node |

## Time Complexity
- Push: O(1)
- Pop: O(1)
- Peek: O(1)
- isEmpty: O(1)
- Print: O(n)

## Time Estimate
45-60 minutes

## References
- Lecture 28: Stacks
- Exercise 1: Linked List Operations
