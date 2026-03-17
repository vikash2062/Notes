import java.util.*;

public class positionelement {

    // Helper function to find the first occurrence of the target
    public static int findFirst(int[] arr, int target) {
        int left = 0, right = arr.length - 1, result = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                result = mid; // Record position
                right = mid - 1; // Search left part
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }

    // Helper function to find the last occurrence of the target
    public static int findLast(int[] arr, int target) {
        int left = 0, right = arr.length - 1, result = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                result = mid; // Record position
                left = mid + 1; // Search right part
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }

    // Main function to find the first and last position of a target
    public static int[] searchRange(int[] arr, int target) {
        int first = findFirst(arr, target);
        int last = findLast(arr, target);
        return new int[]{first, last};
    }

    public static void main(String[] args) {
        int[] arr = {5, 7, 7, 8, 8, 10};

        // Test cases
        int[][] targets = {{8}, {7}, {6}};

        for (int[] target : targets) {
            int[] result = searchRange(arr, target[0]);
            System.out.println("Target " + target[0] + " -> " + Arrays.toString(result));
        }
    }
}
