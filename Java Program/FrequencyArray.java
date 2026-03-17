import java.util.Scanner;

public class FrequencyArray {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String input = scanner.nextLine();

        input = input.toLowerCase();

        int[] freq = new int[26];

        for (int i = 0; i < input.length(); i++) {
            char ch = input.charAt(i);

            if (ch >= 'a' && ch <= 'z') {
                freq[ch - 'a']++;
            }
        }
        System.out.println("Frequencies:");
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                System.out.println((char)(i + 'a') + " : " + freq[i]);
            }
        }
        scanner.close();
    }
}
