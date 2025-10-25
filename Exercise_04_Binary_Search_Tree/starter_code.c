/* Filename: starter_code.c
 * Date: 2024-10-25
 * Name: [Your Name]
 * Student number: [Your Student Number]
 *
 * By submitting this file electronically, I declare that
 * it is my own original work, and that I have not copied
 * any part of it from another source.
 *
 * Exercise 4: Binary Search Tree (BST)
 * This program implements a binary search tree with insertion,
 * searching, and three types of traversals.
 */

#include <stdio.h>
#include <stdlib.h>

// Define the tree node structure
typedef struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
} tree_node_t;

// Function prototypes
tree_node_t* insert(tree_node_t *root, int value);
void inorder_traversal(tree_node_t *root);
void preorder_traversal(tree_node_t *root);
void postorder_traversal(tree_node_t *root);
int search(tree_node_t *root, int value);
void free_tree(tree_node_t *root);

int main()
{
    // Initialize an empty tree
    tree_node_t *root = NULL;

    // Insert values: 47, 25, 77, 11, 43, 65, 93
    printf("Inserting: 47\n");
    root = insert(root, 47);
    printf("Inserting: 25\n");
    root = insert(root, 25);
    printf("Inserting: 77\n");
    root = insert(root, 77);
    printf("Inserting: 11\n");
    root = insert(root, 11);
    printf("Inserting: 43\n");
    root = insert(root, 43);
    printf("Inserting: 65\n");
    root = insert(root, 65);
    printf("Inserting: 93\n");
    root = insert(root, 93);

    // Display all three traversals
    printf("\nInorder traversal (sorted):\n");
    inorder_traversal(root);
    printf("\n");

    printf("\nPreorder traversal:\n");
    preorder_traversal(root);
    printf("\n");

    printf("\nPostorder traversal:\n");
    postorder_traversal(root);
    printf("\n");

    // Search for values
    printf("\nSearching for 43: ");
    if (search(root, 43)) {
        printf("Found\n");
    } else {
        printf("Not found\n");
    }

    printf("Searching for 100: ");
    if (search(root, 100)) {
        printf("Found\n");
    } else {
        printf("Not found\n");
    }

    // Free all memory
    free_tree(root);
    printf("\nAll memory freed successfully.\n");

    return 0;
}

/**
 * insert - Inserts a new value into the BST while maintaining BST property
 * @root: Pointer to the root of the tree (or subtree)
 * @value: The value to insert
 * Return: Pointer to the root of the modified tree
 */
tree_node_t* insert(tree_node_t *root, int value)
{
    // TODO: Base case - if root is NULL, create a new node here
    //       Allocate memory for new node
    //       Set data, left, and right
    //       Return the new node

    // TODO: Recursive case - if value is less than root's data
    //       Insert into left subtree
    //       Update root->left with the result

    // TODO: Recursive case - if value is greater than root's data
    //       Insert into right subtree
    //       Update root->right with the result

    // TODO: Return the root (unchanged if value was inserted in subtree)

    return NULL; // Placeholder return
}

/**
 * inorder_traversal - Prints tree values in sorted order (Left-Root-Right)
 * @root: Pointer to the root of the tree (or subtree)
 */
void inorder_traversal(tree_node_t *root)
{
    // TODO: Base case - if root is NULL, return immediately

    // TODO: Recursively traverse left subtree

    // TODO: Print the current node's data followed by a space

    // TODO: Recursively traverse right subtree
}

/**
 * preorder_traversal - Prints tree values in preorder (Root-Left-Right)
 * @root: Pointer to the root of the tree (or subtree)
 */
void preorder_traversal(tree_node_t *root)
{
    // TODO: Base case - if root is NULL, return immediately

    // TODO: Print the current node's data followed by a space

    // TODO: Recursively traverse left subtree

    // TODO: Recursively traverse right subtree
}

/**
 * postorder_traversal - Prints tree values in postorder (Left-Right-Root)
 * @root: Pointer to the root of the tree (or subtree)
 */
void postorder_traversal(tree_node_t *root)
{
    // TODO: Base case - if root is NULL, return immediately

    // TODO: Recursively traverse left subtree

    // TODO: Recursively traverse right subtree

    // TODO: Print the current node's data followed by a space
}

/**
 * search - Searches for a value in the BST
 * @root: Pointer to the root of the tree (or subtree)
 * @value: The value to search for
 * Return: 1 if found, 0 if not found
 */
int search(tree_node_t *root, int value)
{
    // TODO: Base case - if root is NULL, value not found, return 0

    // TODO: If current node's data matches value, return 1

    // TODO: If value is less than current node's data, search left subtree

    // TODO: Otherwise, search right subtree

    return 0; // Placeholder return
}

/**
 * free_tree - Frees all memory allocated for the tree
 * @root: Pointer to the root of the tree (or subtree)
 *
 * IMPORTANT: Must use postorder traversal (free children before parent)
 */
void free_tree(tree_node_t *root)
{
    // TODO: Base case - if root is NULL, return immediately

    // TODO: Recursively free left subtree (postorder - children first!)

    // TODO: Recursively free right subtree

    // TODO: Free the current node (after children are freed)
}
