import java.util.Scanner;

public class studendInfo {
     public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        
        System.out.print(" student name: ");
        String name = scanner.nextLine();

        System.out.print("student roll number: ");
        int roll = scanner.nextInt();

        System.out.print("student marks: "); 
        float marks = scanner.nextFloat();

        System.out.println("\n Student Information:");
        System.out.println("Name       : " + name);
        System.out.println("Roll No.   : " + roll);
        System.out.println("Marks      : " + marks);
    }
}
