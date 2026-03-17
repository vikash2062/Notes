
import java.util.Scanner;

public class SumEvenOdd {  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    
    
    System.out.print("Enter start of range: ");
    int start = scanner.nextInt();
    
    System.out.print("Enter end of range: ");
    int end = scanner.nextInt();
    
    int Even = 0, Odd = 0;
    
    for (int i = start; i <= end; i++) {
        if (i % 2 == 0) {
            Even += i;
        } else {
            Odd += i;
        }
    }
    
    
    System.out.println("Sum of even numbers: " + Even);
    System.out.println("Sum of odd numbers: " + Odd);
    
    scanner.close();
}
}
