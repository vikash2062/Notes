import java.util.Arrays;

public class sum5 {
     public static void main(String[] args) {
        int[] array = {1, 2, 3, 4, 5};
        int[] sumArray = new int[array.length];

        sumArray[0] = array[0];
        for (int i = 1; i < array.length; i++) {
            sumArray[i] = sumArray[i - 1] + array[i];
        }

        
        System.out.println("Cumulative Sum: " + Arrays.toString(sumArray));
    }
}
