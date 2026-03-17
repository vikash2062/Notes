#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    printf("Inserted %d at the beginning.\n", data);
}

// Insert at the end
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Inserted %d at the end.\n", data);
}

// Insert at a specific position (1-based index)
void insertAtPosition(int data, int pos) {
    if (pos <= 0) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }

    struct Node* temp = head;
    int i = 1;
    while (i < pos - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    if (i != pos - 1) {
        printf("Position out of range.\n");
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted %d at position %d.\n", data, pos);
}

// Delete at a specific position (1-based index)
void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos <= 0) {
        printf("Invalid position!\n");
        return;
    }

    struct Node* temp = head;

    // Deleting head node
    if (pos == 1) {
        if (head->next == head) {
            printf("Deleted node with data %d from position 1.\n", head->data);
            free(head);
            head = NULL;
            return;
        }
        struct Node* last = head;
        while (last->next != head)
            last = last->next;

        printf("Deleted node with data %d from position 1.\n", head->data);
        last->next = head->next;
        free(head);
        head = last->next;
        return;
    }

    // Deleting any other position
    int i = 1;
    while (i < pos - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    if (temp->next == head || temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }

    struct Node* del = temp->next;
    temp->next = del->next;
    printf("Deleted node with data %d from position %d.\n", del->data, pos);
    free(del);
}

// Display the circular linked list
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Main menu
int main() {
    int choice, data, position;

    do {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Position\n");
        printf("4. Delete at Any Position\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 5:
                displayList();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}

