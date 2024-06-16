#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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

// Function to push an element onto the stack
void push(Stack *s, int newItem) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push %d\n", newItem);
        return;
}
    s->items[++(s->top)] = newItem;
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop\n");
        return -1;
    }
    return s->items[(s->top)--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char *exp) {
    Stack s;
    initialize(&s);

    for (int i = 0; exp[i]; i++) {
        if (isdigit(exp[i])) {
            push(&s, exp[i] - '0');
        } else {
            int val2 = pop(&s);
            int val1 = pop(&s);
            switch (exp[i]) {
                case '+': push(&s, val1 + val2); break;
                case '-': push(&s, val1 - val2); break;
                case '*': push(&s, val1 * val2); break;
                case '/': push(&s, val1 / val2); break;
            }
        }
    }
    return pop(&s);
}
// Function to evaluate a prefix expression
int evaluatePrefix(char *exp) {
    Stack s;
    initialize(&s);
    int length = strlen(exp);
for (int i = length - 1; i >= 0; i--) {
        if (isdigit(exp[i])) {
            push(&s, exp[i] - '0');
        } else {
 int val1 = pop(&s);
            int val2 = pop(&s);
            switch (exp[i]) {
                case '+': push(&s, val1 + val2); break;
                case '-': push(&s, val1 - val2); break;
                case '*': push(&s, val1 * val2); break;
                case '/': push(&s, val1 / val2); break;
            }
        }
    }
    return pop(&s);
}

int main() {
    char postfixExp[] = "53+82-*";
    char prefixExp[] = "-+5382";

    int postfixResult = evaluatePostfix(postfixExp);
    int prefixResult = evaluatePrefix(prefixExp);

    printf("Postfix expression evaluation: %d\n", postfixResult);
    printf("Prefix expression evaluation: %d\n", prefixResult);

    return 0;
}
