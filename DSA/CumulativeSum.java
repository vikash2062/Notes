import java.util.*;

public class CumulativeSum {
    public static void main(String[] args) {
        int[] arr = {1,2,3,4,5};
        int[] result = Sum(arr);
        System.out.println(Arrays.toString(result));
    }

    public static int[] Sum(int[] arr) {
        int[] result = new int[arr.length];
        int sum = 0;

        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
            result[i] = sum + (i + 1) * (i + 1);
        }

        return result;
    }
}
