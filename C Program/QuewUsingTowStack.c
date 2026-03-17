#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack1[MAX], top1 = -1;
int stack2[MAX], top2 = -1;

// Stack operations
void push1(int x) {
    stack1[++top1] = x;
}

int pop1() {
    return stack1[top1--];
}

void push2(int x) {
    stack2[++top2] = x;
}

int pop2() {
    return stack2[top2--];
}

// Enqueue operation
void enqueue(int x) {
    push1(x);
    printf("%d enqueued\n", x);
}

// Dequeue operation
int dequeue() {
    if (top2 == -1) {
        while (top1 != -1) {
            push2(pop1());
        }
    }
    if (top2 == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    return pop2();
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1)
                    printf("Dequeued: %d\n", value);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
