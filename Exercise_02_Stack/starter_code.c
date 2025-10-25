/* Filename: starter_code.c
 * Date: 2024-10-25
 * Name: [Your Name]
 * Student number: [Your Student Number]
 *
 * By submitting this file electronically, I declare that
 * it is my own original work, and that I have not copied
 * any part of it from another source.
 *
 * Exercise 2: Stack Implementation (LIFO)
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
    // TODO: Allocate memory for a new node

    // TODO: Check if malloc succeeded

    // TODO: Set the data of the new node

    // TODO: Set the next pointer of the new node to point to the current top

    // TODO: Update the top pointer to point to the new node
}

/**
 * pop - Removes and returns the top element from the stack
 * @top: Pointer to the pointer to the top of the stack
 * Return: The value that was popped, or -1 if stack is empty
 */
int pop(stack_node_t **top)
{
    // TODO: Check if the stack is empty (use is_empty function)

    // TODO: Save the value from the top node

    // TODO: Create a temporary pointer to the top node

    // TODO: Update the top pointer to point to the next node

    // TODO: Free the old top node

    // TODO: Return the saved value

    return -1; // Placeholder return
}

/**
 * peek - Returns the top element without removing it
 * @top: Pointer to the top of the stack
 * Return: The value at the top, or -1 if stack is empty
 */
int peek(stack_node_t *top)
{
    // TODO: Check if the stack is empty

    // TODO: Return the data from the top node

    return -1; // Placeholder return
}

/**
 * is_empty - Checks if the stack is empty
 * @top: Pointer to the top of the stack
 * Return: 1 if empty, 0 otherwise
 */
int is_empty(stack_node_t *top)
{
    // TODO: Return 1 if top is NULL, 0 otherwise

    return 0; // Placeholder return
}

/**
 * print_stack - Prints all elements in the stack from top to bottom
 * @top: Pointer to the top of the stack
 */
void print_stack(stack_node_t *top)
{
    // TODO: Check if the stack is empty

    // TODO: Create a pointer to traverse the stack

    // TODO: Loop through the stack and print each value on a new line
}

/**
 * free_stack - Frees all memory allocated for the stack
 * @top: Pointer to the top of the stack
 */
void free_stack(stack_node_t *top)
{
    // TODO: Create pointers for the current node and the next node

    // TODO: Loop through the stack

    // TODO: Save the pointer to the next node before freeing current

    // TODO: Free the current node

    // TODO: Move to the next node
}
