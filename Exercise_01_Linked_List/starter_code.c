/* Filename: starter_code.c
 * Date: 2024-10-25
 * Name: [Your Name]
 * Student number: [Your Student Number]
 *
 * By submitting this file electronically, I declare that
 * it is my own original work, and that I have not copied
 * any part of it from another source.
 *
 * Exercise 1: Basic Linked List Operations
 * This program demonstrates fundamental linked list operations including
 * adding nodes, removing nodes, and printing the list.
 */

#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the linked list
typedef struct node {
    int val;
    struct node *next;
} node_t;

// Function prototypes
void add_end(node_t *head, int val);
void add_beginning(node_t **head, int val);
void remove_by_value(node_t **head, int val);
void print_list(node_t *head);
void free_list(node_t *head);

int main()
{
    // Create the first node with value 5
    node_t *head = NULL;
    head = malloc(sizeof(node_t));
    if (head == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    head->val = 5;
    head->next = NULL;

    // Add value 10 to the end
    add_end(head, 10);

    // Add value 3 to the beginning
    add_beginning(&head, 3);

    // Add value 7 to the end
    add_end(head, 7);

    // Print the list
    printf("Initial list:\n");
    print_list(head);

    // Remove value 10
    remove_by_value(&head, 10);

    // Print the list again
    printf("\nAfter removing 10:\n");
    print_list(head);

    // Free all memory
    free_list(head);
    printf("\nAll memory freed successfully.\n");

    return 0;
}

/**
 * add_end - Adds a new node with the given value at the end of the list
 * @head: Pointer to the first node of the list
 * @val: The value to store in the new node
 */
void add_end(node_t *head, int val)
{
    // TODO: Create a pointer to traverse the list

    // TODO: Loop through the list until you find the last node (where next is NULL)

    // TODO: Allocate memory for a new node

    // TODO: Check if malloc succeeded

    // TODO: Set the value of the new node

    // TODO: Set the next pointer of the new node to NULL

    // TODO: Link the previous last node to this new node
}

/**
 * add_beginning - Adds a new node with the given value at the beginning of the list
 * @head: Pointer to the pointer to the first node (double pointer to modify head)
 * @val: The value to store in the new node
 */
void add_beginning(node_t **head, int val)
{
    // TODO: Allocate memory for a new node

    // TODO: Check if malloc succeeded

    // TODO: Set the value of the new node

    // TODO: Set the next pointer of the new node to point to the current head

    // TODO: Update the head pointer to point to the new node
}

/**
 * remove_by_value - Removes the first node with the specified value
 * @head: Pointer to the pointer to the first node
 * @val: The value to search for and remove
 */
void remove_by_value(node_t **head, int val)
{
    // TODO: Handle the special case where the list is empty

    // TODO: Handle the special case where the first node contains the value
    //       (need to update the head pointer)

    // TODO: Create pointers to traverse the list (current and previous)

    // TODO: Loop through the list to find the node with the matching value

    // TODO: When found, update the previous node's next pointer to skip the node

    // TODO: Free the memory of the removed node
}

/**
 * print_list - Prints all values in the linked list
 * @head: Pointer to the first node of the list
 */
void print_list(node_t *head)
{
    // TODO: Create a pointer to traverse the list

    // TODO: Loop through the list and print each value followed by " -> "

    // TODO: Print "NULL" at the end to show the list termination

    // TODO: Print a newline character
}

/**
 * free_list - Frees all memory allocated for the linked list
 * @head: Pointer to the first node of the list
 */
void free_list(node_t *head)
{
    // TODO: Create pointers for the current node and the next node

    // TODO: Loop through the list

    // TODO: Save the pointer to the next node before freeing current

    // TODO: Free the current node

    // TODO: Move to the next node
}
