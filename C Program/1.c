
#include <stdio.h> 
 
// (a) Calculate the average of the elements in the array 
void average(int arr[], int size) { 
    if (size == 0) { 
        prin ("Array is empty.\n"); 
        return; 
    } 
    int sum = 0; 
    for (int i = 0; i < size; i++) { 
        sum += arr[i]; 
    } 
    prin ("Average: %.2f\n", (float)sum / size); 
} 
 
// (b) Insert an element at a specified index 
void insert(int arr[], int *size, int index, int value) { 
    if (index < 0 || index > *size) { 
        prin ("Index out of bounds.\n"); 
        return; 
    } 
    for (int i = *size; i > index; i--) { 
        arr[i] = arr[i - 1]; 
    } 
    arr[index] = value; 
    (*size)++; 
} 
 
// (c) Delete an element at a specified index 
void delete(int arr[], int *size, int index) { 
    if (index < 0 || index >= *size) { 
        prin ("Index out of bounds.\n"); 
        return; 
    } 
    for (int i = index; i < *size - 1; i++) { 
        arr[i] = arr[i + 1]; 
    } 
    (*size)--; 
} 
 
// (d) Searching (Linear Search) 
int linearSearch(int arr[], int size, int target) { 
    for (int i = 0; i < size; i++) { 
        if (arr[i] == target) { 
            return i;  // Return index of found element 
        } 
    } 
    return -1;  // Return -1 if element is not found 
} 
 
// (d) Searching (Binary Search) 
int binarySearch(int arr[], int size, int target) { 
    int low = 0, high = size - 1; 
    while (low <= high) { 
        int mid = (low + high) / 2; 
        if (arr[mid] == target) { 
            return mid;  // Return index of found element 
        } else if (arr[mid] < target) { 
            low = mid + 1; 
        } else { 
            high = mid - 1; 
        } 
    } 
    return -1;  // Return -1 if element is not found 
} 
 
// (e) Display the array elements 
void display(int arr[], int size) { 
    if (size == 0) { 
        prin ("Array is empty.\n"); 
        return; 
    } 
    prin ("Array: "); 
    for (int i = 0; i < size; i++) { 
        prin ("%d ", arr[i]); 
    } 
    prin ("\n"); 
} 
 
// (f) Reverse the array 
void reverse(int arr[], int size) { 
    int le = 0, right = size - 1; 
    while (le < right) { 
        int temp = arr[le ]; 
        arr[le ] = arr[right]; 
        arr[right] = temp; 
        le ++; 
        right--; 
    } 
} 
 
// (g) Merge two arrays into one 
void merge(int arr1[], int size1, int arr2[], int size2) { 
    int mergedSize = size1 + size2; 
    int mergedArray[mergedSize]; 
    int i = 0, j = 0, k = 0; 
 
    // Merge the two arrays in sorted order 
    while (i < size1 && j < size2) { 
        if (arr1[i] < arr2[j]) { 
            mergedArray[k++] = arr1[i++]; 
        } else { 
            mergedArray[k++] = arr2[j++]; 
        } 
    } 
 
    // Add remaining elements of arr1 
    while (i < size1) { 
        mergedArray[k++] = arr1[i++]; 
    } 
 
    // Add remaining elements of arr2 
    while (j < size2) { 
        mergedArray[k++] = arr2[j++]; 
    } 
 
    // Display the merged array 
    prin ("Merged Array: "); 
    for (i = 0; i < mergedSize; i++) { 
        prin ("%d ", mergedArray[i]); 
    } 
    prin ("\n"); 
} 
 
// Driver func on to test the above opera ons 
int main() { 
    int arr[100], size = 5; 
     
    // Ini alize the array with some values 
    arr[0] = 1; 
    arr[1] = 2; 
    arr[2] = 3; 
    arr[3] = 4; 
    arr[4] = 5; 
     
    // (a) Average 
    average(arr, size); 
     
    // (b) Insert an element at index 2 
    insert(arr, &size, 2, 10);  // Insert 10 at index 2 
    prin ("A er Inser on at index 2: "); 
    display(arr, size); 
     
    // (c) Delete an element at index 3 
    delete(arr, &size, 3);  // Delete the element at index 3 
    prin ("A er Dele on at index 3: "); 
    display(arr, size); 
     
    // (d) Searching (Linear Search) 
    int target = 10; 
    int index = linearSearch(arr, size, target); 
    if (index != -1) { 
        prin ("Linear Search: Element %d found at index %d\n", target, index); 
    } else { 
        prin ("Linear Search: Element %d not found\n", target); 
    } 
     
    // (d) Searching (Binary Search) 
    // For Binary Search, we need a sorted array 
    // Sor ng the array using a simple Bubble Sort 
    int sortedArr[100]; 
    for (int i = 0; i < size; i++) { 
        sortedArr[i] = arr[i]; 
    } 
    for (int i = 0; i < size - 1; i++) { 
        for (int j = 0; j < size - i - 1; j++) { 
            if (sortedArr[j] > sortedArr[j + 1]) { 
                int temp = sortedArr[j]; 
                sortedArr[j] = sortedArr[j + 1]; 
                sortedArr[j + 1] = temp; 
            } 
        } 
    } 
    index = binarySearch(sortedArr, size, target); 
    if (index != -1) { 
        prin ("Binary Search: Element %d found at index %d\n", target, index); 
    } else { 
        prin ("Binary Search: Element %d not found\n", target); 
    } 
     
    // (e) Display the array 
    display(arr, size); 
     
    // (f) Reverse the array 
    reverse(arr, size); 
    prin ("Reversed Array: "); 
    display(arr, size); 
     
    // (g) Merging two arrays 
    int arr2[] = {6, 7, 8}; 
    int size2 = 3; 
    merge(arr, size, arr2, size2); 
     
    return 0; 
}