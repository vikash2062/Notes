import java.util.ArrayList;

public class LabProgram01{

    public static void main(String[] args) {

        // Step 1: Create an ArrayList of fruits
        ArrayList<String> fruits = new ArrayList<>();

        // Step 2: Add some fruits
        fruits.add("Apple");
        fruits.add("Banana");
        fruits.add("Orange");
        fruits.add("Orange");
        fruits.add("Apple"); // Duplicate allowed

        System.out.println("Initial List: " + fruits);

        // Step 3: Insert at a specific index
        fruits.add(1, "Mango");
        fruits.add(2, "cat");

        System.out.println("After adding Mango at index 1: " + fruits);
        System.out.println("After adding Mango at index 2: " + fruits);

        // Step 4: Remove a fruit by value

        // fruits.remove("Banana");

        // System.out.println("After removing Banana: " + fruits);

        // Step 5: Check if "Orange" is in the list
        if (fruits.contains("Orange")) {
            System.out.println("Yes, Orange is in the list.");
        }

        // Step 6: Access elements using loop
        System.out.println("Looping through the list:");
        for (int i = 0; i < fruits.size(); i++) {
            System.out.println("Index " + i + ": " + fruits.get(i));
        }
        for (String i : fruits) {
            System.out.println(i);  
        }
    }
}
