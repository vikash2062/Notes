public class Duplicates {
    public static void removeDuplicates(String str, int idx, String newString, boolean[] map) {
        if (idx == str.length()) {
            System.out.println(newString);
            return;
        }

        char currChar = str.charAt(idx);
        if (map[currChar - 'a']) {
            removeDuplicates(str, idx + 1, newString, map);
        } else {
            map[currChar - 'a'] = true;
            removeDuplicates(str, idx + 1, newString + currChar, map);
        }
    }

    public static void main(String[] args) {
        String str = "abbccda";
        boolean[] map = new boolean[26]; // Reset for each function call
        removeDuplicates(str, 0, "", map);
    }
}
