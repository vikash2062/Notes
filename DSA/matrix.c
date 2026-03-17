
#include <stdio.h>

int main() {
    int matrix[5][5] = {
        {3, 5, 7, 9, 11},
        {13, 15, 17, 19, 21},
        {23, 25, 27, 29, 31},
        {33, 35, 37, 39, 41},
        {43, 45, 47, 49, 51}
    };
    
    int top = 0, bottom = 4, left = 0, right = 4;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) printf("%d ", matrix[top][i]);
        top++;
        for (int i = top; i <= bottom; i++) printf("%d ", matrix[i][right]);
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) printf("%d ", matrix[bottom][i]);
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) printf("%d ", matrix[i][left]);
            left++;
        }
    }

    printf("\n");
    return 0;
}
