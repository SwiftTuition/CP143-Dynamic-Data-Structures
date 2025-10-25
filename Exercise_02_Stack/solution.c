/* Filename: solution.c
 * Date: 2024-10-25
 * Name: Swift Tuition
 * Student number: N/A
 *
 * By submitting this file electronically, I declare that
 * it is my own original work, and that I have not copied
 * any part of it from another source.
 *
 * Exercise 2: Stack Implementation (LIFO) - SOLUTION
 * This program implements a stack data structure using a linked list.
 * The stack follows the Last-In-First-Out (LIFO) principle.
 */

#include <stdio.h>
#include <stdlib.h>

// Define the stack node structure
typedef struct stack_node {
    int data;
    struct stack_node *next;
} stack_node_t;

// Function prototypes
void push(stack_node_t **top, int value);
int pop(stack_node_t **top);
int peek(stack_node_t *top);
int is_empty(stack_node_t *top);
void print_stack(stack_node_t *top);
void free_stack(stack_node_t *top);

int main()
{
    // Initialize an empty stack (top is NULL)
    stack_node_t *top = NULL;

    // Push 5 values onto the stack
    printf("Pushing: 10\n");
    push(&top, 10);
    printf("Pushing: 20\n");
    push(&top, 20);
    printf("Pushing: 30\n");
    push(&top, 30);
    printf("Pushing: 40\n");
    push(&top, 40);
    printf("Pushing: 50\n");
    push(&top, 50);

    // Print the stack
    printf("\nStack contents (top to bottom):\n");
    print_stack(top);

    // Pop two values
    printf("\nPopped: %d\n", pop(&top));
    printf("Popped: %d\n", pop(&top));

    // Peek at the top
    printf("\nTop element (peek): %d\n", peek(top));

    // Print the stack again
    printf("\nStack contents after popping:\n");
    print_stack(top);

    // Free all memory
    free_stack(top);
    printf("\nAll memory freed successfully.\n");

    return 0;
}

/**
 * push - Adds a new element to the top of the stack
 * @top: Pointer to the pointer to the top of the stack
 * @value: The value to push onto the stack
 */
void push(stack_node_t **top, int value)
{
    // Allocate memory for a new node
    stack_node_t *new_node = malloc(sizeof(stack_node_t));

    // Check if malloc succeeded
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Set the data of the new node
    new_node->data = value;

    // Set the next pointer of the new node to point to the current top
    new_node->next = *top;

    // Update the top pointer to point to the new node
    *top = new_node;
}

/**
 * pop - Removes and returns the top element from the stack
 * @top: Pointer to the pointer to the top of the stack
 * Return: The value that was popped, or -1 if stack is empty
 */
int pop(stack_node_t **top)
{
    // Check if the stack is empty
    if (is_empty(*top)) {
        printf("Stack underflow: Cannot pop from empty stack\n");
        return -1;
    }

    // Save the value from the top node
    int popped_value = (*top)->data;

    // Create a temporary pointer to the top node
    stack_node_t *temp = *top;

    // Update the top pointer to point to the next node
    *top = (*top)->next;

    // Free the old top node
    free(temp);

    // Return the saved value
    return popped_value;
}

/**
 * peek - Returns the top element without removing it
 * @top: Pointer to the top of the stack
 * Return: The value at the top, or -1 if stack is empty
 */
int peek(stack_node_t *top)
{
    // Check if the stack is empty
    if (is_empty(top)) {
        printf("Stack is empty: Cannot peek\n");
        return -1;
    }

    // Return the data from the top node
    return top->data;
}

/**
 * is_empty - Checks if the stack is empty
 * @top: Pointer to the top of the stack
 * Return: 1 if empty, 0 otherwise
 */
int is_empty(stack_node_t *top)
{
    // Return 1 if top is NULL, 0 otherwise
    return (top == NULL);
}

/**
 * print_stack - Prints all elements in the stack from top to bottom
 * @top: Pointer to the top of the stack
 */
void print_stack(stack_node_t *top)
{
    // Check if the stack is empty
    if (is_empty(top)) {
        printf("Stack is empty\n");
        return;
    }

    // Create a pointer to traverse the stack
    stack_node_t *current = top;

    // Loop through the stack and print each value on a new line
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

/**
 * free_stack - Frees all memory allocated for the stack
 * @top: Pointer to the top of the stack
 */
void free_stack(stack_node_t *top)
{
    // Create pointers for the current node and the next node
    stack_node_t *current = top;
    stack_node_t *next = NULL;

    // Loop through the stack
    while (current != NULL) {
        // Save the pointer to the next node before freeing current
        next = current->next;

        // Free the current node
        free(current);

        // Move to the next node
        current = next;
    }
}
