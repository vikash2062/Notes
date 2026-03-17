#include <stdio.h>

#define MAX 100

int main() {
    int stack1[MAX], top1 = -1;
    int stack2[MAX], top2 = -1;

    // Enqueue values
    stack1[++top1] = 10;
    stack1[++top1] = 20;
    stack1[++top1] = 30;

    // Print Queue
    printf("Queue: ");
    for (int i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }
    for (int i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
    }
    printf("\n");

    // Dequeue operation
    if (top2 == -1) {
        while (top1 != -1) {
            stack2[++top2] = stack1[top1--];
        }
    }
    if (top2 != -1) {
        printf("Dequeued: %d\n", stack2[top2--]);
    } else {
        printf("Queue is empty\n");
    }

    // Print Queue
    printf("Queue: ");
    for (int i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }
    for (int i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
    }
    printf("\n");

    // Enqueue 40
    stack1[++top1] = 40;

    // Print Queue
    printf("Queue: ");
    for (int i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }
    for (int i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
    }
    printf("\n");

    // Dequeue again
    if (top2 == -1) {
        while (top1 != -1) {
            stack2[++top2] = stack1[top1--];
        }
    }
    if (top2 != -1) {
        printf("Dequeued: %d\n", stack2[top2--]);
    } else {
        printf("Queue is empty\n");
    }

    // Another dequeue
    if (top2 == -1) {
        while (top1 != -1) {
            stack2[++top2] = stack1[top1--];
        }
    }
    if (top2 != -1) {
        printf("Dequeued: %d\n", stack2[top2--]);
    } else {
        printf("Queue is empty\n");
    }

    // Print final Queue
    printf("Queue: ");   
    for (int i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }
    for (int i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
    }
    printf("\n");

    return 0;
}
