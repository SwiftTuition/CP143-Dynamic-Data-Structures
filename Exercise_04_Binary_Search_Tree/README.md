# Exercise 4: Binary Search Tree (BST)

## Learning Objectives
By completing this exercise, you will be able to:
- Understand the binary tree structure and BST properties
- Implement insertion in a binary search tree
- Perform tree traversals (inorder, preorder, postorder)
- Search for values in a BST
- Properly free all nodes in a tree using recursion
- Understand the relationship between tree structure and sorted order

## Difficulty Level
**Hard** - This exercise introduces hierarchical data structures and requires understanding of recursion.

## Background
A **Binary Search Tree (BST)** is a hierarchical data structure where each node has at most two children (left and right). The BST maintains a special ordering property:

### BST Property:
- **Left subtree**: All values less than the parent node
- **Right subtree**: All values greater than the parent node
- This property applies recursively to all subtrees

### Example BST:
```
        47
       /  \
     25    77
    /  \   /  \
   11  43 65  93
```

### Why Use BSTs?
- **Efficient searching**: O(log n) average case (much better than O(n) for linked lists)
- **Sorted order**: Inorder traversal gives sorted sequence
- **Dynamic**: Can grow and shrink unlike fixed arrays
- **Foundation**: Used in databases, file systems, and many algorithms

## Tree Traversal Methods

### 1. Inorder (Left-Root-Right)
Visits nodes in sorted ascending order:
```
11, 25, 43, 47, 65, 77, 93
```
**Use case**: Getting sorted data from BST

### 2. Preorder (Root-Left-Right)
Visits root before children:
```
47, 25, 11, 43, 77, 65, 93
```
**Use case**: Copying the tree, prefix expression evaluation

### 3. Postorder (Left-Right-Root)
Visits children before root:
```
11, 43, 25, 65, 93, 77, 47
```
**Use case**: Freeing tree memory, postfix expression evaluation

## Instructions

### Part 1: Understanding the Structure
Review the tree node structure definition:
```c
typedef struct tree_node {
    int data;                    // The value stored in this node
    struct tree_node *left;      // Pointer to left child (smaller values)
    struct tree_node *right;     // Pointer to right child (larger values)
} tree_node_t;
```

### Part 2: Complete the Functions
You need to implement the following functions in `starter_code.c`:

1. **insert()** - Inserts a new value while maintaining BST property
2. **inorder_traversal()** - Prints values in sorted order (Left-Root-Right)
3. **preorder_traversal()** - Prints root before children (Root-Left-Right)
4. **postorder_traversal()** - Prints children before root (Left-Right-Root)
5. **search()** - Searches for a value in the tree
6. **free_tree()** - Frees all memory allocated for the tree

### Part 3: Testing
The main function will:
1. Create an empty tree
2. Insert values: 47, 25, 77, 11, 43, 65, 93 (in that order)
3. Display all three traversals
4. Search for existing value (43)
5. Search for non-existing value (100)
6. Free all memory

### Expected Output
```
Inserting: 47
Inserting: 25
Inserting: 77
Inserting: 11
Inserting: 43
Inserting: 65
Inserting: 93

Inorder traversal (sorted):
11 25 43 47 65 77 93

Preorder traversal:
47 25 11 43 77 65 93

Postorder traversal:
11 43 25 65 93 77 47

Searching for 43: Found
Searching for 100: Not found

All memory freed successfully.
```

## Compilation
Use the provided Makefile:
```bash
make
./bst
```

Or compile manually:
```bash
gcc -Wall -Wextra -o bst starter_code.c
./bst
```

## Common Pitfalls
1. **Incorrect insertion**: Not maintaining BST property (left < root < right)
2. **Lost subtrees**: Forgetting to return the modified tree in insert function
3. **Incomplete freeing**: Not freeing all nodes (must use postorder traversal)
4. **Recursion errors**: Not handling base cases (NULL nodes) properly
5. **Memory leaks**: Freeing parent before children

## Tips
- **All tree operations use recursion** - think recursively!
- **Base case**: Always handle NULL nodes first
- **Insert**: Compare value with current node, recurse left or right
- **Free**: Must use postorder (free children before parent)
- **Inorder** gives sorted output - great for testing!
- Draw the tree on paper as you insert values

## Insertion Example
Inserting 47, 25, 77, 11, 43, 65, 93:

```
Step 1: Insert 47     Step 2: Insert 25     Step 3: Insert 77
   47                    47                     47
                        /                      /  \
                      25                     25    77

Step 4: Insert 11     Step 5: Insert 43     Step 6: Insert 65
      47                  47                     47
     /  \                /  \                   /  \
   25    77            25    77               25    77
  /                   /  \                   /  \   /
11                  11   43               11   43 65

Step 7: Insert 93 (final tree)
        47
       /  \
     25    77
    /  \   /  \
   11  43 65  93
```

## Time Complexity
| Operation | Average | Worst Case |
|-----------|---------|------------|
| Insert    | O(log n)| O(n)       |
| Search    | O(log n)| O(n)       |
| Traversal | O(n)    | O(n)       |

**Note**: Worst case O(n) occurs when tree becomes a linked list (inserting sorted values)

## Comparison with Previous Data Structures

| Structure | Insert | Search | Sorted Access |
|-----------|--------|--------|---------------|
| Linked List | O(1) at head | O(n) | O(n log n) |
| Stack | O(1) | O(n) | N/A |
| Queue | O(1) | O(n) | N/A |
| **BST** | **O(log n)** | **O(log n)** | **O(n)** |

## Time Estimate
75-90 minutes

## Challenge Extensions (Optional)
1. Implement `find_min()` - finds smallest value in tree
2. Implement `find_max()` - finds largest value in tree
3. Implement `delete()` - removes a node while maintaining BST property
4. Implement `count_nodes()` - counts total number of nodes
5. Implement `tree_height()` - calculates height of the tree

## References
- Lecture 29: Trees
- Exercise 1: Linked List Operations (foundation for tree nodes)
