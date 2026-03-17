#include <stdio.h>
#define SIZE 100

int arr[SIZE];

int n = 0; 

void insert(int value, int position) {
    if (position > n || position < 0) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = n; i > position; i--)
        arr[i] = arr[i - 1];
    arr[position] = value;
    n++;
}

void delete(int value) {
    int i, pos = -1;
    for (i = 0; i < n; i++) {
        if (arr[i] == value) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Value not found!\n");
        return;
    }
    for (i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1]; // Shift elements to the left
    n--;
}

int linear_search(int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

int binary_search(int value) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == value)
            return mid;
        else if (arr[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void display() {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void reverse() {
    int temp;
    for (int i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

void merge(int other[], int size) {
    for (int i = 0; i < size; i++) {
        arr[n++] = other[i];
    }
}

float average() {
    if (n == 0) return 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return (float)sum / n;
}

int main() {
    insert(10, 0);
    insert(20, 1);
    insert(30, 2);
    insert(40, 1);

    printf("Array after insertions: ");
    display();

    printf("Average: %.2f\n", average());

    delete (20);

    printf("Array after deletion: ");
    display();

    printf("Linear Search (30): %d\n", linear_search(30));

    
    printf("Binary Search (10): %d\n", binary_search(10));

    reverse();
    printf("Array after reversal: ");
    display();

    int other[] = {50, 60, 70};
    merge(other, 3);
    printf("Array after merging: ");
    display();
    return 0;
}
