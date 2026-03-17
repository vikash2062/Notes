#include <stdio.h>

int main() {
    // Declare and initialize the array
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements
    int sum = 0;
    float average;
    int i;

    // Calculate the sum of array elements
    for (i = 0; i < n; i++) {
        sum = sum + arr[i];
    }

    // Calculate the average
    average = (float)sum / n;

    // Print the average
    printf("The elements of the array are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("The sum of the array elements is: %d\n", sum);
    printf("The average value of the array elements is: %.2f\n", average);

    return 0;
}
