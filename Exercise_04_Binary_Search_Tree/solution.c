/* Filename: solution.c
 * Date: 2024-10-25
 * Name: Swift Tuition
 * Student number: N/A
 *
 * By submitting this file electronically, I declare that
 * it is my own original work, and that I have not copied
 * any part of it from another source.
 *
 * Exercise 4: Binary Search Tree (BST) - SOLUTION
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
    // Base case - if root is NULL, create a new node here
    if (root == NULL) {
        // Allocate memory for new node
        tree_node_t *new_node = malloc(sizeof(tree_node_t));

        // Check if malloc succeeded
        if (new_node == NULL) {
            printf("Memory allocation failed\n");
            return NULL;
        }

        // Set data, left, and right
        new_node->data = value;
        new_node->left = NULL;
        new_node->right = NULL;

        // Return the new node
        return new_node;
    }

    // Recursive case - if value is less than root's data
    if (value < root->data) {
        // Insert into left subtree
        // Update root->left with the result
        root->left = insert(root->left, value);
    }
    // Recursive case - if value is greater than root's data
    else if (value > root->data) {
        // Insert into right subtree
        // Update root->right with the result
        root->right = insert(root->right, value);
    }
    // If value equals root->data, we don't insert duplicates (optional behavior)

    // Return the root (unchanged if value was inserted in subtree)
    return root;
}

/**
 * inorder_traversal - Prints tree values in sorted order (Left-Root-Right)
 * @root: Pointer to the root of the tree (or subtree)
 */
void inorder_traversal(tree_node_t *root)
{
    // Base case - if root is NULL, return immediately
    if (root == NULL) {
        return;
    }

    // Recursively traverse left subtree
    inorder_traversal(root->left);

    // Print the current node's data followed by a space
    printf("%d ", root->data);

    // Recursively traverse right subtree
    inorder_traversal(root->right);
}

/**
 * preorder_traversal - Prints tree values in preorder (Root-Left-Right)
 * @root: Pointer to the root of the tree (or subtree)
 */
void preorder_traversal(tree_node_t *root)
{
    // Base case - if root is NULL, return immediately
    if (root == NULL) {
        return;
    }

    // Print the current node's data followed by a space
    printf("%d ", root->data);

    // Recursively traverse left subtree
    preorder_traversal(root->left);

    // Recursively traverse right subtree
    preorder_traversal(root->right);
}

/**
 * postorder_traversal - Prints tree values in postorder (Left-Right-Root)
 * @root: Pointer to the root of the tree (or subtree)
 */
void postorder_traversal(tree_node_t *root)
{
    // Base case - if root is NULL, return immediately
    if (root == NULL) {
        return;
    }

    // Recursively traverse left subtree
    postorder_traversal(root->left);

    // Recursively traverse right subtree
    postorder_traversal(root->right);

    // Print the current node's data followed by a space
    printf("%d ", root->data);
}

/**
 * search - Searches for a value in the BST
 * @root: Pointer to the root of the tree (or subtree)
 * @value: The value to search for
 * Return: 1 if found, 0 if not found
 */
int search(tree_node_t *root, int value)
{
    // Base case - if root is NULL, value not found
    if (root == NULL) {
        return 0;
    }

    // If current node's data matches value, return 1
    if (root->data == value) {
        return 1;
    }

    // If value is less than current node's data, search left subtree
    if (value < root->data) {
        return search(root->left, value);
    }

    // Otherwise, search right subtree
    return search(root->right, value);
}

/**
 * free_tree - Frees all memory allocated for the tree
 * @root: Pointer to the root of the tree (or subtree)
 *
 * IMPORTANT: Must use postorder traversal (free children before parent)
 */
void free_tree(tree_node_t *root)
{
    // Base case - if root is NULL, return immediately
    if (root == NULL) {
        return;
    }

    // Recursively free left subtree (postorder - children first!)
    free_tree(root->left);

    // Recursively free right subtree
    free_tree(root->right);

    // Free the current node (after children are freed)
    free(root);
}
