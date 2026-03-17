#include <stdio.h>
#define MAX_SIZE 100

int arr[MAX_SIZE];
int size = 0;

// Function to display the array
void display() {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a given position
void insert(int value, int position) {
    if (size >= MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    if (position < 0 || position > size) {
        printf("Invalid position for insertion.\n");
        return;
    }
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    size++;
    printf("%d inserted at position %d.\n", value, position);
}

// Function to delete an element by value
void deleteByValue(int value) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            printf("%d deleted from the array.\n", value);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("%d not found in the array.\n", value);
    }
}

// Function for linear search
int linearSearch(int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function for binary search (assuming the array is sorted)
int binarySearch(int value) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2; // To avoid potential overflow
        if (arr[mid] == value) {
            return mid; // Return the index if found
        } else if (arr[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Return -1 if not found
}

// Function to reverse the array
void reverse() {
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
    printf("Array reversed.\n");
}

// Function to calculate the average of array elements
float average() {
    if (size == 0) {
        return 0;
    }
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (float)sum / size;
}

// Function to merge another array into the current array
void merge(int otherArr[], int otherSize) {
    if (size + otherSize > MAX_SIZE) {
        printf("Cannot merge. Resulting array would exceed maximum size.\n");
        return;
    }
    for (int i = 0; i < otherSize; i++) {
        arr[size++] = otherArr[i];
    }
    printf("Arrays merged.\n");
}

int main() {
    int choice, value, position, searchResult;
    int otherArr[MAX_SIZE], otherSize;

    do {
        printf("\nArray Operations Menu:\n");
        printf("1. Display Array\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element by Value\n");
        printf("4. Linear Search\n");
        printf("5. Binary Search (for sorted array)\n");
        printf("6. Reverse Array\n");
        printf("7. Calculate Average\n");
        printf("8. Merge Another Array\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display();
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert (0 to %d): ", size);
                scanf("%d", &position);
                insert(value, position);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(value);
                break;
            case 4:
                printf("Enter value to search using Linear Search: ");
                scanf("%d", &value);
                searchResult = linearSearch(value);
                if (searchResult != -1) {
                    printf("%d found at index %d (Linear Search).\n", value, searchResult);
                } else {
                    printf("%d not found in the array (Linear Search).\n", value);
                }
                break;
            case 5:
                printf("Enter value to search using Binary Search: ");
                scanf("%d", &value);
                printf("Note: Binary Search requires the array to be sorted.\n");
                searchResult = binarySearch(value);
                if (searchResult != -1) {
                    printf("%d found at index %d (Binary Search).\n", value, searchResult);
                } else {
                    printf("%d not found in the array (Binary Search).\n", value);
                }
                break;
            case 6:
                reverse();
                break;
            case 7:
                printf("Average of array elements: %.2f\n", average());
                break;
            case 8:
                printf("Enter the size of the array to merge: ");
                scanf("%d", &otherSize);
                if (otherSize > 0 && size + otherSize <= MAX_SIZE) {
                    printf("Enter the elements of the array to merge:\n");
                    for (int i = 0; i < otherSize; i++) {
                        scanf("%d", &otherArr[i]);
                    }
                    merge(otherArr, otherSize);
                } else if (size + otherSize > MAX_SIZE) {
                    printf("Cannot merge. Resulting array would exceed maximum size.\n");
                } else {
                    printf("Invalid size for merging array.\n");
                }
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
