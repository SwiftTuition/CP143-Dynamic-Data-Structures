# CP143 Dynamic Data Structures - Quick Reference

## Exercise Summary

| # | Name | Difficulty | Time | Key Concept |
|---|------|------------|------|-------------|
| 1 | Linked List | Basic | 30-45 min | Dynamic linear structure |
| 2 | Stack | Medium | 45-60 min | LIFO (Last-In-First-Out) |
| 3 | Queue | Medium | 60-75 min | FIFO (First-In-First-Out) |
| 4 | Binary Search Tree | Hard | 75-90 min | Hierarchical structure |

---

## Compilation Quick Commands

```bash
# Exercise 1 - Linked List
cd Exercise_01_Linked_List && make solution && ./linked_list_solution

# Exercise 2 - Stack
cd Exercise_02_Stack && make solution && ./stack_solution

# Exercise 3 - Queue
cd Exercise_03_Queue && make solution && ./queue_solution

# Exercise 4 - BST
cd Exercise_04_Binary_Search_Tree && make solution && ./bst_solution
```

---

## Key Operations Comparison

### Adding Elements

**Linked List:**
```c
add_beginning(&head, value);  // O(1) - add to front
add_end(head, value);          // O(n) - traverse to end
```

**Stack:**
```c
push(&top, value);             // O(1) - add to top
```

**Queue:**
```c
enqueue(&queue, value);        // O(1) - add to tail
```

**BST:**
```c
root = insert(root, value);    // O(log n) avg - recursive insert
```

### Removing Elements

**Linked List:**
```c
remove_by_value(&head, value); // O(n) - search and remove
```

**Stack:**
```c
int val = pop(&top);           // O(1) - remove from top
```

**Queue:**
```c
int val = dequeue(&queue);     // O(1) - remove from head
```

**BST:**
```c
// Not implemented in basic exercise
```

### Viewing Elements

**Linked List:**
```c
print_list(head);              // O(n) - traverse all
```

**Stack:**
```c
int val = peek(top);           // O(1) - view top
print_stack(top);              // O(n) - view all
```

**Queue:**
```c
int val = peek(&queue);        // O(1) - view head
print_queue(&queue);           // O(n) - view all
```

**BST:**
```c
inorder_traversal(root);       // O(n) - sorted order
preorder_traversal(root);      // O(n) - root first
postorder_traversal(root);     // O(n) - root last
int found = search(root, val); // O(log n) avg
```

---

## Memory Management

### Freeing Memory

**Linked List:**
```c
void free_list(node_t *head) {
    node_t *current = head;
    node_t *next = NULL;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
```

**Stack:**
```c
void free_stack(stack_node_t *top) {
    stack_node_t *current = top;
    stack_node_t *next = NULL;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
```

**Queue:**
```c
void free_queue(queue_t *q) {
    queue_node_t *current = q->head;
    queue_node_t *next = NULL;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    q->head = NULL;
    q->tail = NULL;
}
```

**BST (Recursive - Postorder):**
```c
void free_tree(tree_node_t *root) {
    if (root == NULL) return;
    free_tree(root->left);   // Free left subtree
    free_tree(root->right);  // Free right subtree
    free(root);              // Free root
}
```

---

## Common Patterns

### Checking for Empty

**Linked List:**
```c
if (head == NULL) { /* empty */ }
```

**Stack:**
```c
int is_empty(stack_node_t *top) {
    return (top == NULL);
}
```

**Queue:**
```c
int is_empty(queue_t *q) {
    return (q->head == NULL);
}
```

**BST:**
```c
if (root == NULL) { /* empty tree */ }
```

### Traversing

**Linked List / Stack / Queue (Iterative):**
```c
node_t *current = head;
while (current != NULL) {
    // Process current->data
    current = current->next;
}
```

**BST (Recursive - Inorder):**
```c
void inorder(tree_node_t *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
```

---

## Time Complexity Cheat Sheet

| Operation | Linked List | Stack | Queue | BST (avg) | BST (worst) |
|-----------|-------------|-------|-------|-----------|-------------|
| Insert (beginning) | O(1) | O(1) | - | - | - |
| Insert (end) | O(n) | - | O(1) | - | - |
| Insert (ordered) | - | - | - | O(log n) | O(n) |
| Remove (beginning) | O(1) | O(1) | O(1) | - | - |
| Remove (specific) | O(n) | - | - | O(log n) | O(n) |
| Search | O(n) | O(n) | O(n) | O(log n) | O(n) |
| Access | O(n) | O(1) top | O(1) front | O(log n) | O(n) |

---

## Pointer Usage Patterns

### Single Pointer (for reading)
```c
void print_list(node_t *head) {
    // Can traverse but not modify head
}
```

### Double Pointer (for modifying)
```c
void add_beginning(node_t **head, int val) {
    // Can modify the head pointer itself
    node_t *new_node = malloc(sizeof(node_t));
    new_node->next = *head;
    *head = new_node;
}
```

### Structure with Pointers (Queue)
```c
typedef struct queue {
    queue_node_t *head;
    queue_node_t *tail;
} queue_t;

void enqueue(queue_t *q, int val) {
    // Can modify both head and tail through structure
}
```

---

## Data Structure Choice Guide

**Use Linked List when:**
- Need dynamic size
- Frequent insertions/deletions at beginning
- Don't need random access

**Use Stack when:**
- Need LIFO behavior
- Implementing undo functionality
- Processing in reverse order
- Managing function calls

**Use Queue when:**
- Need FIFO behavior
- Processing jobs in order
- Breadth-first traversal
- Buffering data

**Use BST when:**
- Need fast search
- Need sorted data
- Insertions/deletions are dynamic
- Data has natural ordering

---

## Common Bugs and Fixes

### Bug: Memory Leak
**Symptom:** Valgrind shows "definitely lost" memory
**Fix:** Ensure all malloc'd memory is freed

### Bug: Segmentation Fault
**Symptom:** Program crashes
**Common Causes:**
- Dereferencing NULL pointer
- Accessing freed memory
- Not checking malloc return value

### Bug: Lost Head Pointer
**Symptom:** Can't access list
**Fix:** Use double pointer when modifying head

### Bug: Dangling Tail Pointer (Queue)
**Symptom:** Crashes when accessing empty queue
**Fix:** Set tail to NULL when removing last element

### Bug: Wrong Traversal Order (BST)
**Symptom:** Tree not printing correctly
**Fix:**
- Inorder: Left-Root-Right (sorted)
- Preorder: Root-Left-Right
- Postorder: Left-Right-Root

---

## Debugging Tips

### 1. Use printf Debugging
```c
printf("DEBUG: head = %p\n", (void*)head);
printf("DEBUG: current->data = %d\n", current->data);
```

### 2. Draw It Out
- Sketch pointer connections on paper
- Track pointer changes step by step

### 3. Valgrind
```bash
make valgrind-solution
# Look for:
# - "All heap blocks were freed"
# - No "definitely lost" memory
# - No "invalid read/write"
```

### 4. GDB
```bash
gcc -g -o program starter_code.c
gdb ./program
(gdb) break main
(gdb) run
(gdb) next
(gdb) print head
```

---

## Expected Outputs

### Exercise 1 (Linked List):
```
Initial list:
3 -> 5 -> 10 -> 7 -> NULL

After removing 10:
3 -> 5 -> 7 -> NULL

All memory freed successfully.
```

### Exercise 2 (Stack):
```
Stack contents (top to bottom):
50
40
30
20
10

Popped: 50
Popped: 40
```

### Exercise 3 (Queue):
```
Queue contents (front to back):
10 <- 20 <- 30 <- 40 <- 50

Dequeued: 10
Dequeued: 20
```

### Exercise 4 (BST):
```
Inorder traversal (sorted):
11 25 43 47 65 77 93

Preorder traversal:
47 25 11 43 77 65 93

Postorder traversal:
11 43 25 65 93 77 47
```

---

## Makefile Targets Reference

```bash
make              # Compile starter_code.c
make solution     # Compile solution.c
make run          # Compile and run starter code
make run-solution # Compile and run solution
make valgrind     # Check starter code for leaks
make valgrind-solution # Check solution for leaks
make clean        # Remove compiled binaries
make help         # Show help message
```

---

## Study Tips

1. **Start Simple:** Master Exercise 1 before moving on
2. **Understand Before Coding:** Read README thoroughly
3. **Test Incrementally:** Test each function as you write it
4. **Use Valgrind:** Check for memory leaks after every change
5. **Compare Solutions:** Only after attempting yourself!
6. **Practice Edge Cases:** Empty structures, single elements
7. **Draw Diagrams:** Visualize pointer connections
8. **Time Yourself:** Practice under time pressure for tests

---

## Before Submitting

- [ ] Code compiles without warnings
- [ ] All functions implemented correctly
- [ ] Comment block at top of file complete
- [ ] Code is properly indented
- [ ] Sufficient comments explaining logic
- [ ] All test cases pass
- [ ] Valgrind shows no memory leaks
- [ ] Output matches expected format

---

**Good luck with your exercises!**
