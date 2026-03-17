#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Global top pointer for the stack
struct Node* top = NULL;

// Function to check if stack is empty
int isEmpty() {
    return top == NULL;
}

// Function to push an element onto the stack
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", value);
}

// Function to pop the top element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return -1;
    }
    struct Node* temp = top;
    int popped = temp->data;
    top = top->next;
    free(temp);
    return popped;
}

// Function to peek at the top element of the stack
int peek() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return -1;
    }
    return top->data;
}

// Function to display the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack elements (Top to Bottom):\n");
    while (temp != NULL) {
        printf("| %d |\n", temp->data);
        temp = temp->next;
    }
}

// Main function with menu-driven interface
int main() {
    int choice, value;

    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            value = pop();
            if (value != -1)
                printf("Popped value: %d\n", value);
            break;
        case 3:
            value = peek();
            if (value != -1)
                printf("Top value: %d\n", value);
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

