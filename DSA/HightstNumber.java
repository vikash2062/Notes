import java.util.Arrays;

public class HightstNumber {
    public static void main(String[] args) {
         int[] array = {-5, 1, 5, 0, -7};
        int[] sum = new int[array.length + 1];

        sum[0] = 0;
        for (int i = 1; i <= array.length; i++) {
            sum[i] = sum[i - 1] + array[i - 1];
        }
  
           
        System.out.println(" Sum: " + Arrays.toString(sum));
    }
}
