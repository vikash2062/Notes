public class Min {
    public static void main(String[] args) {
        int[] nums = {-3, 2, -3, 4, 2}; 
        
        int minSum = 0, sum = 0;

        for (int num : nums) {
            sum += num;
            minSum = Math.min(minSum, sum); 
        }

       
        int minValue = 1 - minSum;
        
       
        System.out.println("Minimum  value: " + minValue);
    } 
}
