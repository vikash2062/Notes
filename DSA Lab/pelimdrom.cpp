#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a node in a doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to check if the doubly linked list is a palindrome
bool isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return true; // Empty list or single node is a palindrome
    }

    struct Node* front = head;
    struct Node* back = head;

    // Move 'back' pointer to the end of the list
    while (back->next != NULL) {
        back = back->next;
    }

    // Compare elements from both ends
    while (front != back && front->prev != back) {
        if (front->data != back->data) {
            return false; // Not a palindrome
        }
        front = front->next;
        back = back->prev;
    }

    return true; // It's a palindrome
}

// Function to print the doubly linked list (for verification)
void printList(struct Node* head) {
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main() {
    struct Node* head = NULL;

    // Example 1: Palindrome
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 2);
    insertEnd(&head, 1);
    printList(head);
    if (isPalindrome(head)) {
        printf("The doubly linked list is a palindrome.\n");
    } else {
        printf("The doubly linked list is not a palindrome.\n");
    }
    freeList(head);
    head = NULL; // Reset head for the next example
    printf("\n");

    // Example 2: Not a palindrome
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);
    printList(head);
    if (isPalindrome(head)) {
        printf("The doubly linked list is a palindrome.\n");
    } else {
        printf("The doubly linked list is not a palindrome.\n");
    }
    freeList(head);
    head = NULL;
    printf("\n");

    // Example 3: Empty list (considered a palindrome)
    printList(head);
    if (isPalindrome(head)) {
        printf("The doubly linked list is a palindrome.\n");
    } else {
        printf("The doubly linked list is not a palindrome.\n");
    }
    printf("\n");

    // Example 4: Single node (considered a palindrome)
    insertEnd(&head, 10);
    printList(head);
    if (isPalindrome(head)) {
        printf("The doubly linked list is a palindrome.\n");
    } else {
        printf("The doubly linked list is not a palindrome.\n");
    }
    freeList(head);

    return 0;
}
