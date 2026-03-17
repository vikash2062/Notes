#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // Define the maximum size of the stack

// Structure to represent the stack
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initializeStack(struct Stack *s) {
    s->top = -1; // Initialize top to -1, indicating an empty stack
}

// Function to check if the stack is full
int isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        s->items[++(s->top)] = value; // Increment top and then add the value
        printf("%d pushed onto the stack\n", value);
    }
}

// Function to pop an element from the stack
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop from an empty stack\n");
        return -1; // Return a sentinel value to indicate an error
    } else {
        return s->items[(s->top)--]; // Return the top element and then decrement top
    }
}

// Function to peek at the top element of the stack
int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot peek.\n");
        return -1; // Return a sentinel value to indicate an error
    } else {
        return s->items[s->top];
    }
}

// Function to display the elements of the stack
void displayStack(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack1;
    initializeStack(&stack1);

    int numElements;
    printf("Enter the number of elements to push onto the stack: ");
    scanf("%d", &numElements);

    if (numElements > MAX_SIZE) {
        printf("Error: Cannot push more than %d elements.\n", MAX_SIZE);
        return 1; // Indicate an error
    }

    for (int i = 0; i < numElements; i++) {
        int value;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        push(&stack1, value);
    }

    displayStack(&stack1);

    if (!isEmpty(&stack1)) {
        printf("Top element: %d\n", peek(&stack1));
        printf("Popped element: %d\n", pop(&stack1));
        displayStack(&stack1);
    }

    return 0;
}