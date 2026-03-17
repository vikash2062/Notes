#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Declare the Stack structure
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Create stack
void createStack(struct Stack *stack) {
    stack->top = -1;
}

// Check if full
bool isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Check if empty
bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Push value
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push element %d.\n", value);
    } else {
        stack->items[++stack->top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

// Pop value
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
        return -1;
    } else {
        return stack->items[stack->top--];
    }
}

// Display stack
void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements:\n");
        for (int i = stack->top; i >= 0; i--) {
            printf("%d\n", stack->items[i]);
        }
    }
}

// Main function
int main() {
    struct Stack stack;
    createStack(&stack);
    int choice, value;

    while (1) {
        printf("\n--- Stack Operation Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check Underflow (isEmpty)\n");
        printf("4. Check Overflow (isFull)\n");
        printf("5. Display Stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped element: %d\n", value);
                }
                break;
            case 3:
                if (isEmpty(&stack)) {
                    printf("Stack underflow: the stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
            case 4:
                if (isFull(&stack)) {
                    printf("Stack overflow: the stack is full.\n");
                } else {
                    printf("Stack is not full.\n");
                }
                break;
            case 5:
                display(&stack);
                break;
            case 6:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    }

    return 0;
}
