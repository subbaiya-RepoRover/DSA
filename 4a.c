#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initialize(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Function to add an element to the stack
void push(Stack *s, int newItem) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push %d\n", newItem);
        return;
    }
    s->items[++(s->top)] = newItem;
}

// Function to remove an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop\n");
        return -1;
    }
    return s->items[(s->top)--];
}

// Function to get the top element of the stack without removing it
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot peek\n");
        return -1;
    }
    return s->items[s->top];
}

int main() {
    Stack s;
    initialize(&s);

    // Demonstrating the usage of the stack
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    printf("Top element: %d\n", peek(&s));

    printf("Popped element: %d\n", pop(&s));

    printf("Top element after pop: %d\n", peek(&s));

    return 0;
}
