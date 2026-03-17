import java.util.Stack;

public class LabProgram03 {
    public static void main(String[] args) {
        // Step 1: Create a Stack of books
        Stack<String> books = new Stack<>();

        // Step 2: Push books onto the stack
        books.push("Java Basics");
        books.push("Data Structures");
        books.push("Algorithms");
        books.push("Operating Systems");

        System.out.println("Stack after pushes: " + books);

        // Step 3: Pop the top book
        String poppedBook = books.pop();
        System.out.println("Popped book: " + poppedBook);
        System.out.println("Stack after pop: " + books);

        // Step 4: Peek the top book without removing
        String topBook = books.peek();
        System.out.println("Top book (peek): " + topBook);

        // Step 5: Check if stack contains 'Data Structures'
        System.out.println("Contains 'Data Structures'? " + books.contains("Data Structures"));

        // Step 6: Iterate using for-each loop
        System.out.println("Iterating through stack:");
        for (String book : books) {
            System.out.println(book);
        }
    }
}
