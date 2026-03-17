#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define maximum size of the stack

int stack[MAX];
int top = -1;

// Function to create stack (just sets top to -1)
void create() {
    top = -1;
    printf("Stack created. (Empty stack)\n");
}

// Function to check if stack is full (overflow)
int isOverflow() {
    return top == MAX - 1;
}

// Function to check if stack is empty (underflow)
int isUnderflow() {
    return top == -1;
}

// PUSH operation
void push(int value) {
    if (isOverflow()) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed to stack.\n", value);
    }
}

// POP operation
void pop() {
    if (isUnderflow()) {
        printf("Stack Underflow! Nothing to pop.\n");
    } else {
        int popped = stack[top];
        top--;
        printf("%d popped from stack.\n", popped);
    }
}

// Display the stack
void display() {
    if (isUnderflow()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack contents: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    create(); // Initially create the stack

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to PUSH: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

