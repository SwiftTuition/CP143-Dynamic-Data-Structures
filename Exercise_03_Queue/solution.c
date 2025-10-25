/* Filename: solution.c
 * Date: 2024-10-25
 * Name: Swift Tuition
 * Student number: N/A
 *
 * By submitting this file electronically, I declare that
 * it is my own original work, and that I have not copied
 * any part of it from another source.
 *
 * Exercise 3: Queue Implementation (FIFO) - SOLUTION
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
    // Set both head and tail to NULL (empty queue)
    q->head = NULL;
    q->tail = NULL;
}

/**
 * enqueue - Adds a new element to the tail of the queue
 * @q: Pointer to the queue structure
 * @value: The value to add to the queue
 */
void enqueue(queue_t *q, int value)
{
    // Allocate memory for a new node
    queue_node_t *new_node = malloc(sizeof(queue_node_t));

    // Check if malloc succeeded
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Set the data of the new node
    new_node->data = value;

    // Set the next pointer of the new node to NULL (it will be the last node)
    new_node->next = NULL;

    // Handle the special case of an empty queue
    if (is_empty(q)) {
        // Both head and tail should point to the new node
        q->head = new_node;
        q->tail = new_node;
    } else {
        // For a non-empty queue, link the current tail to the new node
        q->tail->next = new_node;
        // Update the tail pointer
        q->tail = new_node;
    }
}

/**
 * dequeue - Removes and returns the front element from the queue
 * @q: Pointer to the queue structure
 * Return: The value that was dequeued, or -1 if queue is empty
 */
int dequeue(queue_t *q)
{
    // Check if the queue is empty
    if (is_empty(q)) {
        printf("Queue underflow: Cannot dequeue from empty queue\n");
        return -1;
    }

    // Save the value from the head node
    int dequeued_value = q->head->data;

    // Create a temporary pointer to the head node
    queue_node_t *temp = q->head;

    // Update the head pointer to point to the next node
    q->head = q->head->next;

    // Handle the special case where we just dequeued the last element
    if (q->head == NULL) {
        // Set tail to NULL as well
        q->tail = NULL;
    }

    // Free the old head node
    free(temp);

    // Return the saved value
    return dequeued_value;
}

/**
 * peek - Returns the front element without removing it
 * @q: Pointer to the queue structure
 * Return: The value at the front, or -1 if queue is empty
 */
int peek(queue_t *q)
{
    // Check if the queue is empty
    if (is_empty(q)) {
        printf("Queue is empty: Cannot peek\n");
        return -1;
    }

    // Return the data from the head node
    return q->head->data;
}

/**
 * is_empty - Checks if the queue is empty
 * @q: Pointer to the queue structure
 * Return: 1 if empty, 0 otherwise
 */
int is_empty(queue_t *q)
{
    // Return 1 if head is NULL, 0 otherwise
    return (q->head == NULL);
}

/**
 * print_queue - Prints all elements in the queue from front to back
 * @q: Pointer to the queue structure
 */
void print_queue(queue_t *q)
{
    // Check if the queue is empty
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return;
    }

    // Create a pointer to traverse the queue
    queue_node_t *current = q->head;

    // Loop through the queue and print each value
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" <- ");
        }
        current = current->next;
    }
    printf("\n");
}

/**
 * free_queue - Frees all memory allocated for the queue
 * @q: Pointer to the queue structure
 */
void free_queue(queue_t *q)
{
    // Create pointers for the current node and the next node
    queue_node_t *current = q->head;
    queue_node_t *next = NULL;

    // Loop through the queue starting from head
    while (current != NULL) {
        // Save the pointer to the next node before freeing current
        next = current->next;

        // Free the current node
        free(current);

        // Move to the next node
        current = next;
    }

    // After freeing all nodes, set both head and tail to NULL
    q->head = NULL;
    q->tail = NULL;
}
