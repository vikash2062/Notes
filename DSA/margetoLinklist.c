#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Merge two sorted lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    // Dummy node to simplify logic
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    // Loop until one list becomes NULL
    while (l1 != NULL && l2 != NULL) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Attach the remaining part
    if (l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next;
}

int main() {
    // Create List 1: 1 -> 3 -> 6 -> 8 -> 10
    struct Node* l1 = createNode(1);
    l1->next = createNode(3);
    l1->next->next = createNode(6);
    l1->next->next->next = createNode(8);
    l1->next->next->next->next = createNode(10);

    // Create List 2: 2 -> 4 -> 5 -> 7 -> 9
    struct Node* l2 = createNode(2);
    l2->next = createNode(4);
    l2->next->next = createNode(5);
    l2->next->next->next = createNode(7);
    l2->next->next->next->next = createNode(9);

    // Merge the lists
    struct Node* merged = mergeLists(l1, l2);

    // Print result
    printf("Merged List: ");
    printList(merged);

    return 0;
}
