 #include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Structure for DQueue
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} DQueue;

// Function to create a new DQueue
void createDQueue(DQueue *dq) {
    dq->front = -1;
    dq->rear = -1;
}

// Check if DQueue is empty
int isEmpty(DQueue *dq) {
    return (dq->front == -1 && dq->rear == -1);
}

// Check if DQueue is full
int isFull(DQueue *dq) {
    return ((dq->rear + 1) % MAX_SIZE == dq->front);
}

// Enqueue at Front
void enqueueFront(DQueue *dq, int value) {
    if (isFull(dq)) {
        printf("Overflow! Cannot insert from front.\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX_SIZE) % MAX_SIZE;
    }
    dq->items[dq->front] = value;
    printf("Inserted %d at front.\n", value);
}

// Enqueue at Rear
void enqueueRear(DQueue *dq, int value) {
    if (isFull(dq)) {
        printf("Overflow! Cannot insert from rear.\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX_SIZE;
    }
    dq->items[dq->rear] = value;
    printf("Inserted %d at rear.\n", value);
}

// Dequeue from Front
void dequeueFront(DQueue *dq) {
    if (isEmpty(dq)) {
        printf("Underflow! Cannot dequeue from front.\n");
        return;
    }
    printf("Deleted %d from front.\n", dq->items[dq->front]);
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX_SIZE;
    }
}

// Dequeue from Rear
void dequeueRear(DQueue *dq) {
    if (isEmpty(dq)) {
        printf("Underflow! Cannot dequeue from rear.\n");
        return;
    }
    printf("Deleted %d from rear.\n", dq->items[dq->rear]);
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
}

// Display elements in DQueue
void display(DQueue *dq) {
    if (isEmpty(dq)) {
        printf("DQueue is empty.\n");
        return;
    }
    printf("DQueue elements: ");
    int i = dq->front;
    while (i != dq->rear) {
        printf("%d ", dq->items[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", dq->items[dq->rear]);
}

// Main Function
int main() {
    DQueue dq;
    createDQueue(&dq);

    int choice, value;

    while (1) {
        printf("\n--- DQueue Menu ---\n");
        printf("1. Enqueue Front\n");
        printf("2. Enqueue Rear\n");
        printf("3. Dequeue Front\n");
        printf("4. Dequeue Rear\n");
        printf("5. Display DQueue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue at front: ");
                scanf("%d", &value);
                enqueueFront(&dq, value);
                break;
            case 2:
                printf("Enter value to enqueue at rear: ");
                scanf("%d", &value);
                enqueueRear(&dq, value);
                break;
            case 3:
                dequeueFront(&dq);
                break;
            case 4:
                dequeueRear(&dq);
                break;
            case 5:
                display(&dq);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

