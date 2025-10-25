/* Filename: solution.c
 * Date: 2024-10-25
 * Name: Swift Tuition
 * Student number: N/A
 *
 * By submitting this file electronically, I declare that
 * it is my own original work, and that I have not copied
 * any part of it from another source.
 *
 * Exercise 1: Basic Linked List Operations - SOLUTION
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
    // Create a pointer to traverse the list
    node_t *current = head;

    // Loop through the list until you find the last node (where next is NULL)
    while (current->next != NULL) {
        current = current->next;
    }

    // Allocate memory for a new node
    current->next = malloc(sizeof(node_t));

    // Check if malloc succeeded
    if (current->next == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Set the value of the new node
    current->next->val = val;

    // Set the next pointer of the new node to NULL
    current->next->next = NULL;
}

/**
 * add_beginning - Adds a new node with the given value at the beginning of the list
 * @head: Pointer to the pointer to the first node (double pointer to modify head)
 * @val: The value to store in the new node
 */
void add_beginning(node_t **head, int val)
{
    // Allocate memory for a new node
    node_t *new_node = malloc(sizeof(node_t));

    // Check if malloc succeeded
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Set the value of the new node
    new_node->val = val;

    // Set the next pointer of the new node to point to the current head
    new_node->next = *head;

    // Update the head pointer to point to the new node
    *head = new_node;
}

/**
 * remove_by_value - Removes the first node with the specified value
 * @head: Pointer to the pointer to the first node
 * @val: The value to search for and remove
 */
void remove_by_value(node_t **head, int val)
{
    // Handle the special case where the list is empty
    if (*head == NULL) {
        printf("List is empty, cannot remove\n");
        return;
    }

    // Handle the special case where the first node contains the value
    if ((*head)->val == val) {
        node_t *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    // Create pointers to traverse the list (current and previous)
    node_t *current = *head;
    node_t *previous = NULL;

    // Loop through the list to find the node with the matching value
    while (current != NULL && current->val != val) {
        previous = current;
        current = current->next;
    }

    // If we found the node
    if (current != NULL) {
        // Update the previous node's next pointer to skip the node
        previous->next = current->next;
        // Free the memory of the removed node
        free(current);
    } else {
        printf("Value %d not found in list\n", val);
    }
}

/**
 * print_list - Prints all values in the linked list
 * @head: Pointer to the first node of the list
 */
void print_list(node_t *head)
{
    // Create a pointer to traverse the list
    node_t *current = head;

    // Loop through the list and print each value followed by " -> "
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }

    // Print "NULL" at the end to show the list termination
    printf("NULL");

    // Print a newline character
    printf("\n");
}

/**
 * free_list - Frees all memory allocated for the linked list
 * @head: Pointer to the first node of the list
 */
void free_list(node_t *head)
{
    // Create pointers for the current node and the next node
    node_t *current = head;
    node_t *next = NULL;

    // Loop through the list
    while (current != NULL) {
        // Save the pointer to the next node before freeing current
        next = current->next;

        // Free the current node
        free(current);

        // Move to the next node
        current = next;
    }
}
