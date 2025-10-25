# CP143 Dynamic Data Structures - Practice Exercises

## Overview
This directory contains 4 complete programming exercises designed to match the difficulty and structure of Practical 11 (2024). Each exercise builds progressively on previous concepts and provides comprehensive practice with dynamic data structures.

## Exercise Structure
Each exercise contains:
- **README.md** - Learning objectives, instructions, and expected output
- **starter_code.c** - Incomplete code with TODO comments for students to complete
- **solution.c** - Complete, working, well-commented solution
- **Makefile** - Compilation targets including valgrind memory checks
- **test_cases.txt** - Example test cases and expected outputs

## Exercises

### Exercise 1: Basic Linked List Operations
**Directory:** `Exercise_01_Linked_List/`
**Difficulty:** Basic
**Time Estimate:** 30-45 minutes

**Learning Objectives:**
- Create and initialize linked list nodes
- Add nodes to beginning and end of list
- Remove nodes by value
- Traverse and print lists
- Free all allocated memory

**Key Functions:**
- `add_end()` - Add node at end
- `add_beginning()` - Add node at beginning
- `remove_by_value()` - Remove specific value
- `print_list()` - Display all values
- `free_list()` - Free all memory

**Compilation:**
```bash
cd Exercise_01_Linked_List
make solution
./linked_list_solution
```

---

### Exercise 2: Stack Implementation (LIFO)
**Directory:** `Exercise_02_Stack/`
**Difficulty:** Medium
**Time Estimate:** 45-60 minutes

**Learning Objectives:**
- Understand Last-In-First-Out (LIFO) principle
- Implement stack using linked list
- Perform push and pop operations
- Check stack state (peek, isEmpty)
- Manage memory for stack structure

**Key Functions:**
- `push()` - Add element to top
- `pop()` - Remove from top
- `peek()` - View top without removing
- `is_empty()` - Check if empty
- `print_stack()` - Display stack
- `free_stack()` - Free all memory

**Real-World Applications:**
- Function call stack
- Undo/Redo functionality
- Browser back button
- Expression evaluation

**Compilation:**
```bash
cd Exercise_02_Stack
make solution
./stack_solution
```

---

### Exercise 3: Queue Implementation (FIFO)
**Directory:** `Exercise_03_Queue/`
**Difficulty:** Medium
**Time Estimate:** 60-75 minutes

**Learning Objectives:**
- Understand First-In-First-Out (FIFO) principle
- Implement queue with head and tail pointers
- Perform enqueue and dequeue operations
- Handle edge cases (empty queue, single element)
- Manage both head and tail pointers correctly

**Key Functions:**
- `init_queue()` - Initialize empty queue
- `enqueue()` - Add to tail
- `dequeue()` - Remove from head
- `peek()` - View head without removing
- `is_empty()` - Check if empty
- `print_queue()` - Display queue
- `free_queue()` - Free all memory

**Real-World Applications:**
- Print job queue
- Task scheduling
- Breadth-First Search
- Data stream buffering

**Compilation:**
```bash
cd Exercise_03_Queue
make solution
./queue_solution
```

---

### Exercise 4: Binary Search Tree (BST)
**Directory:** `Exercise_04_Binary_Search_Tree/`
**Difficulty:** Hard
**Time Estimate:** 75-90 minutes

**Learning Objectives:**
- Understand hierarchical data structures
- Implement BST insertion maintaining order property
- Perform three types of tree traversals
- Search efficiently using BST property
- Use recursion for tree operations
- Free tree memory using postorder traversal

**Key Functions:**
- `insert()` - Add node maintaining BST property
- `inorder_traversal()` - Left-Root-Right (sorted output)
- `preorder_traversal()` - Root-Left-Right
- `postorder_traversal()` - Left-Right-Root
- `search()` - Find value in tree
- `free_tree()` - Free all memory

**Real-World Applications:**
- Database indexing
- File systems
- Expression parsing
- Priority queues

**BST Property:**
- Left subtree: values < parent
- Right subtree: values > parent
- Enables O(log n) search in balanced trees

**Compilation:**
```bash
cd Exercise_04_Binary_Search_Tree
make solution
./bst_solution
```

---

## Comparison Table

| Exercise | Data Structure | Add Operation | Remove Operation | Search | Access Pattern |
|----------|---------------|---------------|------------------|--------|----------------|
| 1. Linked List | Linear | O(1) beginning, O(n) end | O(n) | O(n) | Sequential |
| 2. Stack | LIFO | O(1) push | O(1) pop | O(n) | Top only |
| 3. Queue | FIFO | O(1) enqueue | O(1) dequeue | O(n) | Front only |
| 4. BST | Hierarchical | O(log n) avg | N/A* | O(log n) avg | Tree traversal |

*BST deletion not implemented in basic exercise

---

## Progression Path

### Week 1: Foundations
- **Exercise 1** - Master linked list basics
- Understand dynamic memory allocation
- Practice pointer manipulation

### Week 2: Linear Structures
- **Exercise 2** - Implement stack (LIFO)
- **Exercise 3** - Implement queue (FIFO)
- Compare and contrast LIFO vs FIFO

### Week 3: Advanced
- **Exercise 4** - Implement BST
- Master recursion
- Understand tree traversals

---

## Common Makefile Targets

All exercises support these targets:
```bash
make              # Build starter code
make solution     # Build solution
make run          # Build and run starter code
make run-solution # Build and run solution
make valgrind     # Check starter code for memory leaks
make valgrind-solution # Check solution for memory leaks
make clean        # Remove compiled files
make help         # Show help message
```

---

## Memory Management Best Practices

All exercises emphasize proper memory management:

1. **Always check malloc return value**
   ```c
   node_t *new_node = malloc(sizeof(node_t));
   if (new_node == NULL) {
       printf("Memory allocation failed\n");
       return;
   }
   ```

2. **Free all allocated memory**
   - Use valgrind to verify: `make valgrind-solution`
   - Expected: "All heap blocks were freed -- no leaks are possible"

3. **Free in correct order**
   - Lists/Stacks/Queues: Iterative freeing is fine
   - Trees: MUST use postorder (free children before parent)

4. **Avoid dangling pointers**
   - Don't access memory after freeing
   - Set pointers to NULL after freeing (good practice)

---

## Testing Strategy

### 1. Compile First
Ensure code compiles without warnings:
```bash
make solution
```

### 2. Run Normal Test Case
Test with provided main function:
```bash
./solution_binary
```

### 3. Test Edge Cases
Refer to `test_cases.txt` for edge cases:
- Empty structures
- Single element
- Removing all elements
- Adding after emptying

### 4. Memory Check
Always verify no memory leaks:
```bash
make valgrind-solution
```

---

## Common Pitfalls to Avoid

### Exercise 1 (Linked List):
- Losing the head pointer
- Not updating links when removing nodes
- Memory leaks from not freeing all nodes

### Exercise 2 (Stack):
- Forgetting to update top pointer
- Not checking for empty stack before pop
- Not freeing popped nodes

### Exercise 3 (Queue):
- Not updating tail pointer correctly
- Forgetting to set tail to NULL when empty
- Not handling single-element queue case

### Exercise 4 (BST):
- Not maintaining BST property
- Freeing parent before children
- Not returning modified tree in insert
- Base case errors in recursion

---

## Additional Resources

### Reference Material:
- **Lecture 27:** Linked Lists
- **Lecture 28:** Stacks and Queues
- **Lecture 29:** Trees
- **Practical 11 (2024):** Example format and style

### Online Tools:
- **Visualgo:** Visualize data structures (visualgo.net)
- **Valgrind:** Memory leak detection
- **GDB:** Debugging

### Recommended Practice Order:
1. Complete Exercise 1 first (foundation)
2. Do Exercises 2 and 3 in any order (both medium)
3. Finish with Exercise 4 (requires recursion understanding)

---

## Submission Guidelines

When submitting your work:

1. **Comment block at top:**
   ```c
   /* Filename: starter_code.c
    * Date: 2024-10-25
    * Name: [Your Name]
    * Student number: [Your Number]
    *
    * By submitting this file electronically, I declare that
    * it is my own original work, and that I have not copied
    * any part of it from another source.
    *
    * [Description]
    */
   ```

2. **Code standards:**
   - Proper indentation (4 spaces or 1 tab)
   - Meaningful variable names
   - Sufficient comments
   - No compiler warnings

3. **Testing:**
   - All test cases pass
   - No memory leaks (valgrind clean)
   - Expected output matches

---

## Quick Start Guide

### For Students Starting from Scratch:
```bash
# Navigate to base directory
cd "/workspaces/swift-tuition-2025/Stellies/CP143/Swift Tuition's CP143 Notes/Dynamic_Data_Structures"

# Start with Exercise 1
cd Exercise_01_Linked_List
cat README.md  # Read instructions
make solution  # Build and test solution
./linked_list_solution

# Try to complete the starter code
# Edit starter_code.c and fill in TODOs
make           # Build your code
./linked_list  # Test your code
make valgrind  # Check for memory leaks
```

### For Instructors/TAs:
All solutions are provided and tested:
- Solutions compile with `-Wall -Wextra` without warnings
- All solutions pass valgrind memory checks
- Test cases cover normal operation and edge cases
- READMEs provide clear learning objectives

---

## Contact and Support

**Course:** CP143 - Stellenbosch University
**Topic:** Dynamic Data Structures
**Based on:** Practical 11 (2024)

**Created by:** Swift Tuition
**Date:** October 2024

For additional help:
- Review lecture slides (Lectures 27-29)
- Check test_cases.txt for examples
- Compare your code with solution.c (after attempting!)
- Use valgrind to find memory issues

---

## Summary

These 4 exercises provide comprehensive practice with:
- Dynamic memory allocation
- Pointer manipulation
- Linear data structures (linked lists, stacks, queues)
- Hierarchical data structures (binary search trees)
- Recursion
- Memory management
- Time complexity analysis

Master these exercises to build a strong foundation in data structures!
