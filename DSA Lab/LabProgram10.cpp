#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define EMPTY -1

int hashTable[SIZE];

// Initialize hash table
void initHashTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

// Hash function
int hashFunction(int key) {
    return key % SIZE;
}

// Insert with Linear Probing
void insert(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 0;

    while (hashTable[index] != EMPTY) {
        index = (originalIndex + ++i) % SIZE;
        if (i == SIZE) {
            printf("Hash table is full, cannot insert %d\n", key);
            return;
        }
    }

    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

// Search with Linear Probing
int search(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 0;

    while (hashTable[index] != EMPTY) {
        if (hashTable[index] == key) {
            return index;
        }
        index = (originalIndex + ++i) % SIZE;
        if (i == SIZE) break;
    }

    return -1;
}

// Display hash table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == EMPTY)
            printf("[%d] : EMPTY\n", i);
        else
            printf("[%d] : %d\n", i, hashTable[i]);
    }
}

int main() {
    int choice, key;

    initHashTable();

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2: {
                printf("Enter key to search: ");
                scanf("%d", &key);
                int index = search(key);
                if (index != -1)
                    printf("Key %d found at index %d\n", key, index);
                else
                    printf("Key %d not found\n", key);
                break;
            }

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

