
import java.util.Scanner;

public class ReverseNumber {
    public static void main(String[] args) {
        int i=10 ;

        System.out.println("Enter the number");
        Scanner ref=new Scanner(System.in);
        i=ref.nextInt();

        for(i=1;i<10;i--){
            System.out.print(i);
        }

    }
}
