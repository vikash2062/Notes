import java.util.LinkedList;

public class LabProgram02 {
    public static void main(String[] args) {
        // Step 1: Create LinkedList of cities
        LinkedList<String> cities = new LinkedList<>();

        // Step 2: Add cities
        cities.add("New York");
        cities.add("Paris");
        cities.add("London");
        cities.add("Tokyo");

        System.out.println("Initial LinkedList: " + cities);

        // Step 3: Add city at first position
        cities.addFirst("Sydney");
        System.out.println("After addFirst Sydney: " + cities);

        // Step 4: Add city at last position
        cities.addLast("Berlin");
        System.out.println("After addLast Berlin: " + cities);

        // Step 5: Remove city by index
        cities.remove(2);
        System.out.println("After removing city at index 2: " + cities);

        // Step 6: Check if list contains 'Paris'
        System.out.println("Does list contain Paris? " + cities.contains("Paris"));

        // Step 7: Iterate using for-each loop
        System.out.println("Iterating through LinkedList:");
        for (String city : cities) {
            System.out.println(city);
        }
    }
}
