public class primeNumber {
    public static void main(String[] args) {
        System.out.println(" Print the Prime numbers :");
        
        for (int i = 1; i <= 100; i++) {
            boolean Prime = true;
            
            for (int j = 2; j <= i / 2; j++) {
                if (i % j == 0) {
                    Prime = false;
                    break;
                }
            }
            
            if (Prime) {
                System.out.print(i + " ");
            }
        }
    }
}
