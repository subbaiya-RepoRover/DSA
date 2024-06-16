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

// Function to get the precedence of operators
int precedence(char operator) {
    switch (operator) {
 case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to apply an operator to two operands
int applyOperator(int operand1, char operator, int operand2) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        case '^':
            return (int)pow(operand1, operand2);
        default:
            return 0;
    }
}
/ / Function to evaluate an infix expression
int evaluateInfix(char* expression) {
    Stack operands, operators;
    initialize(&operands);
    initialize(&operators);
    
    for (int i = 0; i < strlen(expression); i++) {
        if (expression[i] == ' ')
            continue;
        
        if (isdigit(expression[i])) {
            int value = 0;
            while (i < strlen(expression) && isdigit(expression[i])) {
                value = (value * 10) + (expression[i] - '0');
                i++;
            }
            i--;
            push(&operands, value);
} else if (expression[i] == '(') {
            push(&operators, expression[i]);
        } else if (expression[i] == ')') {
            while (!isEmpty(&operators) && operators.items[operators.top] != '(') {
                int operand2 = pop(&operands);
                int operand1 = pop(&operands);
                char operator = pop(&operators);
                push(&operands, applyOperator(operand1, operator, operand2));
            }
            pop(&operators); // Remove the '('
        } else {
            while (!isEmpty(&operators) && precedence(operators.items[operators.top]) >= precedence(expression[i])) {
                int operand2 = pop(&operands);
                int operand1 = pop(&operands);
                char operator = pop(&operators);
                push(&operands, applyOperator(operand1, operator, operand2));
            }
            push(&operators, expression[i]);
        }
    }

    while (!isEmpty(&operators)) {
        int operand2 = pop(&operands);
        int operand1 = pop(&operands);
        char operator = pop(&operators);
        push(&operands, applyOperator(operand1, operator, operand2));
    }

    return pop(&operands);
}

int main() {
    char expression[MAX];
    printf("Enter the infix expression: ");
    fgets(expression, MAX, stdin);
    expression[strcspn(expression, "\n")] = '\0';

    int result = evaluateInfix(expression);
    printf("Result of infix expression evaluation: %d\n", result);

    return 0;
}

