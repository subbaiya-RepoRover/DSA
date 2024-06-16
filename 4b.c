#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Function to check if the queue is full
int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

// Function to add an element to the queue
void enqueue(Queue *q, int newItem) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d\n", newItem);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->items[++(q->rear)] = newItem;
}

// Function to remove an element from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1;
    }
int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

// Function to get the front element of the queue without removing it
int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot peek\n");
        return -1;
    }
    return q->items[q->front];
}

int main() {
    Queue q;
    initialize(&q);

    // Demonstrating the usage of the queue
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Front element: %d\n", peek(&q));

    return 0;
}
