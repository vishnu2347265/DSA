#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int array[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = value;
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1; // Assuming -1 represents an error or an invalid value
    }
    return stack->array[stack->top--];
}

int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; // Assuming -1 represents an error or an invalid value
    }
    return stack->array[stack->top];
}

int main() {
    struct Stack myStack;
    initialize(&myStack);

    int choice, value;

    do {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&myStack, value);
                break;
            case 2:
                printf("Popped element: %d\n", pop(&myStack));
                break;
            case 3:
                printf("Top element: %d\n", peek(&myStack));
                break;
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}
