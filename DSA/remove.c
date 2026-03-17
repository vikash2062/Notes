#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Print the list
void printList(struct Node* head) {
    struct Node* t = head;
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

// Remove last node
void removeLastNode(struct Node** head) {
    if (*head == NULL) return;  // Empty list
    if ((*head)->next == NULL) {
        // Only one node
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);  // Free last node
    temp->next = NULL; // Set second last node's next to NULL
}

int main() {
    // Create list: 1 -> 2 -> 3 -> 4 -> 5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original list: ");
    printList(head);

    // Remove last node (5)
    removeLastNode(&head);

    printf("After removing last node: ");
    printList(head);

    return 0;
}
