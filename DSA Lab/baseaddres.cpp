#include <stdio.h>

int main() {
    // Define array dimensions and base address
    int base_address = 300;
    int row_start = 2;
    int row_end = 11;
    int col_start = -3;
    int col_end = 4;
    int depth_start = 7;
    int depth_end = 18;
    int element_size = 3; // Bytes

    // Target element indices
    int target_row = 4;
    int target_col = -2;
    int target_depth = 12;

    // Calculate the number of elements in each dimension
    int num_rows = (row_end - row_start + 1);
    int num_cols = (col_end - col_start + 1);
    int num_depth = (depth_end - depth_start + 1);

    // Calculate the offset for each dimension (relative to the start)
    int row_offset = (target_row - row_start);
    int col_offset = (target_col - col_start);
    int depth_offset = (target_depth - depth_start);

    // Calculate the total offset in row-major order
    // For a 3D array in row-major order, the elements are stored such that the
    // last dimension changes fastest, then the second-to-last, and finally the first.
    int total_offset = (row_offset * num_cols * num_depth) +
                       (col_offset * num_depth) +
                       depth_offset;

    // Calculate the address of the target element
    int address = base_address + (total_offset * element_size);

    printf("Base Address of the array: %d\n", base_address);
    printf("Array Dimensions: arr[%d:%d][%d:%d][%d:%d]\n",
           row_start, row_end, col_start, col_end, depth_start, depth_end);
    printf("Size of each element: %d bytes\n", element_size);
    printf("\n");
    printf("Address of arr[%d][%d][%d] (using row-major order): %d\n",
           target_row, target_col, target_depth, address);

    return 0;
}
