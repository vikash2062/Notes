import java.util.*;

public class MoveZeros {
    public static void main(String[] args) {
        int[] arr = {0, 1, 2, 0, 3, 5};
        moveZerosToEnd(arr);
        System.out.println(Arrays.toString(arr));
    }

    public static void moveZerosToEnd(int[] arr) {
        int index = 0;

        for (int num : arr) {
            if (num != 0) {
                arr[index++] = num;
            }
        }

        while (index < arr.length) {
            arr[index++] = 0;
        }
    }
} 