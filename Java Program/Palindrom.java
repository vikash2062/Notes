import java.util.Scanner;

public class Palindrom {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        
        System.out.print("Enter a string: ");
        String str = scanner.nextLine();

        
        String reversed = "";
        for (int i = str.length() - 1; i >= 0; i--) {
            reversed += str.charAt(i);
        }

        
        System.out.println("Reversed string: " + reversed);

        
        if (str.equals(reversed)) {
            System.out.println(" palindrome.");
        } else {
            System.out.println("not a palindrome.");
        }

        scanner.close();
    }
}
