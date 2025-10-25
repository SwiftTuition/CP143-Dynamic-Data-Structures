# Exercise 3: Queue Implementation (FIFO)

## Learning Objectives
By completing this exercise, you will be able to:
- Understand the First-In-First-Out (FIFO) principle
- Implement a queue using a linked list with head and tail pointers
- Perform enqueue (add to tail) and dequeue (remove from head) operations
- Peek at the front element without removing it
- Check if a queue is empty
- Properly manage memory for a queue data structure

## Difficulty Level
**Medium** - This exercise introduces queue operations with the added complexity of maintaining both head and tail pointers.

## Background
A **queue** is a linear data structure that follows the **First-In-First-Out (FIFO)** principle. Think of it like a line at a store:
- New customers join at the back of the line (**enqueue**)
- Customers are served from the front of the line (**dequeue**)
- You can see who's at the front without removing them (**peek**)

### Real-World Applications:
- Print job queue
- Task scheduling in operating systems
- Breadth-First Search (BFS) in graphs
- Buffering in data streams
- Customer service ticket systems

### Queue Operations:
1. **Enqueue**: Add an element to the tail (rear) of the queue
2. **Dequeue**: Remove and return the element from the head (front) of the queue
3. **Peek**: View the front element without removing it
4. **isEmpty**: Check if the queue is empty

### Important Difference from Stack:
- **Stack**: LIFO - like a stack of plates (last in, first out)
- **Queue**: FIFO - like a waiting line (first in, first out)

## Instructions

### Part 1: Understanding the Structure
Review the queue structure definition:
```c
typedef struct queue_node {
    int data;                    // The value stored in this node
    struct queue_node *next;     // Pointer to the next node
} queue_node_t;

typedef struct queue {
    queue_node_t *head;          // Points to the front of the queue
    queue_node_t *tail;          // Points to the back of the queue
} queue_t;
```

**Why do we need both head and tail?**
- **head**: Allows O(1) dequeue operations (remove from front)
- **tail**: Allows O(1) enqueue operations (add to back)
- Without tail, we'd need O(n) to traverse to the end for each enqueue

### Part 2: Complete the Functions
You need to implement the following functions in `starter_code.c`:

1. **init_queue()** - Initializes an empty queue
2. **enqueue()** - Adds a new element to the tail of the queue
3. **dequeue()** - Removes and returns the front element from the queue
4. **peek()** - Returns the front element without removing it
5. **is_empty()** - Checks if the queue is empty
6. **print_queue()** - Displays all elements in the queue (front to back)
7. **free_queue()** - Frees all memory allocated for the queue

### Part 3: Testing
The main function will:
1. Create an empty queue
2. Enqueue values: 10, 20, 30, 40, 50 (in that order)
3. Print the queue (should show 10 at front)
4. Dequeue two values (should remove 10 and 20)
5. Peek at the front (should show 30)
6. Print the queue again
7. Free all memory

### Expected Output
```
Enqueuing: 10
Enqueuing: 20
Enqueuing: 30
Enqueuing: 40
Enqueuing: 50

Queue contents (front to back):
10 <- 20 <- 30 <- 40 <- 50

Dequeued: 10
Dequeued: 20

Front element (peek): 30

Queue contents after dequeuing:
30 <- 40 <- 50

All memory freed successfully.
```

## Compilation
Use the provided Makefile:
```bash
make
./queue
```

Or compile manually:
```bash
gcc -Wall -Wextra -o queue starter_code.c
./queue
```

## Common Pitfalls
1. **Forgetting to update tail**: When enqueuing to an empty queue or single element queue
2. **Queue underflow**: Trying to dequeue from an empty queue
3. **Memory leaks**: Not freeing all nodes when done
4. **Dangling tail pointer**: Not setting tail to NULL when last element is dequeued
5. **Lost tail pointer**: Forgetting to update tail when adding the first element

## Tips
- When the queue is empty: both head and tail are NULL
- When the queue has one element: both head and tail point to the same node
- When enqueuing to an empty queue: set both head and tail to the new node
- When dequeuing the last element: set both head and tail to NULL
- Draw diagrams showing how head and tail change with each operation

## Comparison: Stack vs Queue

| Aspect | Stack (LIFO) | Queue (FIFO) |
|--------|--------------|--------------|
| Add | Push (top) | Enqueue (tail) |
| Remove | Pop (top) | Dequeue (head) |
| View | Peek (top) | Peek (head) |
| Pointers | 1 (top) | 2 (head, tail) |
| Order | Last-In-First-Out | First-In-First-Out |
| Example | Undo/Redo | Print queue |

## Time Complexity
- Enqueue: O(1)
- Dequeue: O(1)
- Peek: O(1)
- isEmpty: O(1)
- Print: O(n)

## Time Estimate
60-75 minutes

## References
- Lecture 28: Queues
- Exercise 1: Linked List Operations
- Exercise 2: Stack Implementation
