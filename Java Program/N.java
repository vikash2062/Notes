import java.util.Scanner;

public class N {
    public static void main(String[] args) {
        int name;
        int roll;
        int age;
        Scanner ref=new Scanner(System.in);

        System.out.println("Enter your Name");
        String Name = ref.nextLine();

        System.out.println("Enter your rollnumber");
        roll = ref.nextInt();

        System.out.println("Enter your age");
        age = ref.nextInt();


        System.out.println(Name);
        System.out.println(roll);
        System.out.println(age);





    }
}
