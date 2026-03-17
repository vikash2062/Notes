import java.util.*;

public class FirstAndLastPositionSimple {
    public static int[] findFirstAndLast(int[] arr, int target) {
        int first = -1;
        int last = -1;

        // Loop through the array to find first and last position
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == target) {
                if (first == -1) {
                    first = i; // Set first occurrence
                }
                last = i; // Update last occurrence
            }
        }

        return new int[]{first, last};
    }

    public static void main(String[] args) {
        int[] arr = {5, 7, 7, 8, 8, 10};

        // Test cases
        int[] targets = {8, 7, 6};

        for (int target : targets) {
            int[] result = findFirstAndLast(arr, target);
            System.out.println("Target " + target + " -> " + Arrays.toString(result));
        }
    }
}
