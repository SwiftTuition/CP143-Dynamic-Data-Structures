/* Filename: starter_code.c
 * Date: 2024-10-25
 * Name: [Your Name]
 * Student number: [Your Student Number]
 *
 * By submitting this file electronically, I declare that
 * it is my own original work, and that I have not copied
 * any part of it from another source.
 *
 * Exercise 3: Queue Implementation (FIFO)
 * This program implements a queue data structure using a linked list.
 * The queue follows the First-In-First-Out (FIFO) principle.
 */

#include <stdio.h>
#include <stdlib.h>

// Define the queue node structure
typedef struct queue_node {
    int data;
    struct queue_node *next;
} queue_node_t;

// Define the queue structure with head and tail pointers
typedef struct queue {
    queue_node_t *head;  // Front of the queue (where we dequeue)
    queue_node_t *tail;  // Back of the queue (where we enqueue)
} queue_t;

// Function prototypes
void init_queue(queue_t *q);
void enqueue(queue_t *q, int value);
int dequeue(queue_t *q);
int peek(queue_t *q);
int is_empty(queue_t *q);
void print_queue(queue_t *q);
void free_queue(queue_t *q);

int main()
{
    // Create and initialize a queue
    queue_t my_queue;
    init_queue(&my_queue);

    // Enqueue 5 values
    printf("Enqueuing: 10\n");
    enqueue(&my_queue, 10);
    printf("Enqueuing: 20\n");
    enqueue(&my_queue, 20);
    printf("Enqueuing: 30\n");
    enqueue(&my_queue, 30);
    printf("Enqueuing: 40\n");
    enqueue(&my_queue, 40);
    printf("Enqueuing: 50\n");
    enqueue(&my_queue, 50);

    // Print the queue
    printf("\nQueue contents (front to back):\n");
    print_queue(&my_queue);

    // Dequeue two values
    printf("\nDequeued: %d\n", dequeue(&my_queue));
    printf("Dequeued: %d\n", dequeue(&my_queue));

    // Peek at the front
    printf("\nFront element (peek): %d\n", peek(&my_queue));

    // Print the queue again
    printf("\nQueue contents after dequeuing:\n");
    print_queue(&my_queue);

    // Free all memory
    free_queue(&my_queue);
    printf("\nAll memory freed successfully.\n");

    return 0;
}

/**
 * init_queue - Initializes an empty queue
 * @q: Pointer to the queue structure
 */
void init_queue(queue_t *q)
{
    // TODO: Set both head and tail to NULL (empty queue)
}

/**
 * enqueue - Adds a new element to the tail of the queue
 * @q: Pointer to the queue structure
 * @value: The value to add to the queue
 */
void enqueue(queue_t *q, int value)
{
    // TODO: Allocate memory for a new node

    // TODO: Check if malloc succeeded

    // TODO: Set the data of the new node

    // TODO: Set the next pointer of the new node to NULL (it will be the last node)

    // TODO: Handle the special case of an empty queue
    //       (both head and tail should point to the new node)

    // TODO: For a non-empty queue, link the current tail to the new node
    //       and update the tail pointer
}

/**
 * dequeue - Removes and returns the front element from the queue
 * @q: Pointer to the queue structure
 * Return: The value that was dequeued, or -1 if queue is empty
 */
int dequeue(queue_t *q)
{
    // TODO: Check if the queue is empty

    // TODO: Save the value from the head node

    // TODO: Create a temporary pointer to the head node

    // TODO: Update the head pointer to point to the next node

    // TODO: Handle the special case where we just dequeued the last element
    //       (set tail to NULL as well)

    // TODO: Free the old head node

    // TODO: Return the saved value

    return -1; // Placeholder return
}

/**
 * peek - Returns the front element without removing it
 * @q: Pointer to the queue structure
 * Return: The value at the front, or -1 if queue is empty
 */
int peek(queue_t *q)
{
    // TODO: Check if the queue is empty

    // TODO: Return the data from the head node

    return -1; // Placeholder return
}

/**
 * is_empty - Checks if the queue is empty
 * @q: Pointer to the queue structure
 * Return: 1 if empty, 0 otherwise
 */
int is_empty(queue_t *q)
{
    // TODO: Return 1 if head is NULL, 0 otherwise

    return 0; // Placeholder return
}

/**
 * print_queue - Prints all elements in the queue from front to back
 * @q: Pointer to the queue structure
 */
void print_queue(queue_t *q)
{
    // TODO: Check if the queue is empty

    // TODO: Create a pointer to traverse the queue

    // TODO: Loop through the queue and print each value
    //       Use " <- " between elements to show direction
}

/**
 * free_queue - Frees all memory allocated for the queue
 * @q: Pointer to the queue structure
 */
void free_queue(queue_t *q)
{
    // TODO: Create pointers for the current node and the next node

    // TODO: Loop through the queue starting from head

    // TODO: Save the pointer to the next node before freeing current

    // TODO: Free the current node

    // TODO: Move to the next node

    // TODO: After freeing all nodes, set both head and tail to NULL
}
