public class Recursion {
    public static int first = -1;
    public static int last = -1;

    public static void findOccurrence(String str, int idx, char element) {
        if (idx == str.length()) {
            System.out.println("First occurrence: " + first);
            System.out.println("Last occurrence: " + last);
            return;
        }

        char currChar = str.charAt(idx);
        if (currChar == element) {
            if (first == -1) {
                first = idx;
            } else {
                last = idx;
            }
        }

        findOccurrence(str, idx + 1, element);
    }

    public static void main(String[] args) {
        String str = "abaacdaefaah";
        findOccurrence(str, 0, 'a');
    }
}
