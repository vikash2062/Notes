

public class RemoveDuplicatesSimple {
    public static void main(String[] args) {
        int[] arr = {0, 1, 1, 2, 2, 2, 3, 3, 4, 4, 5};
        int n = arr.length;

        // Step 1: Sort the array (Using Bubble Sort for simplicity)
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        // Step 2: Remove duplicates manually
        int[] uniqueArr = new int[n];
        int j = 0;
        uniqueArr[j++] = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[i - 1]) {
                uniqueArr[j++] = arr[i];
            }
        }

        // Step 3: Print the unique elements
        System.out.print("[ ");
        for (int i = 0; i < j; i++) {
            System.out.print(uniqueArr[i]);
            if (i < j - 1) {
                System.out.print(", ");
            }
        }
        System.out.println(" ]");
    }
}
