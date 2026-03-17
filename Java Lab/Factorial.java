public class Factorial {
    public static void main(String[] args) {
        int num=5;
        int Factorial=1;
        for (int i = 1; i <= num; i++) {
            Factorial *= i;
        }
        System.out.println("Factorial" + num + " is: " + Factorial);
    }
}
