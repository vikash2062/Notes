#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front, rear;
} Deque;

void initDeque(Deque* dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isEmpty(Deque* dq) {
    return dq->front == -1;
}

int isFull(Deque* dq) {
    return (dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1);
}

void addFront(Deque* dq, int val) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
    } else {
        dq->front--;
    }
    dq->arr[dq->front] = val;
}

void addRear(Deque* dq, int val) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->arr[dq->rear] = val;
}

void removeFront(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Removed from front: %d\n", dq->arr[dq->front]);
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
}

void removeRear(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Removed from rear: %d\n", dq->arr[dq->rear]);
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX - 1;
    } else {
        dq->rear--;
    }
}

void display(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Current Deque: ");
    int i = dq->front;
    while (1) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Deque dq;
    initDeque(&dq);

    int choice, value;

    printf("Double-Ended Queue (Deque) Operations:\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add to Front\n");
        printf("2. Add to Rear\n");
        printf("3. Remove from Front\n");
        printf("4. Remove from Rear\n");
        printf("5. View Deque\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add at front: ");
                scanf("%d", &value);
                addFront(&dq, value);
                break;
            case 2:
                printf("Enter value to add at rear: ");
                scanf("%d", &value);
                addRear(&dq, value);
                break;
            case 3:
                removeFront(&dq);
                break;
            case 4:
                removeRear(&dq);
                break;
            case 5:
                display(&dq);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
