import java.util.PriorityQueue;

public class LabProgram04 {
    public static void main(String[] args) {
        // Step 1: Create a PriorityQueue of tasks with different priorities
        PriorityQueue<String> tasks = new PriorityQueue<>();

        // Step 2: Add tasks
        tasks.add("Low priority task");
        tasks.add("High priority task");
        tasks.add("Medium priority task");
        tasks.add("Urgent task");

        System.out.println("Initial PriorityQueue (natural order): " + tasks);

        // Step 3: Peek the head of the queue (lowest lexicographical order)
        System.out.println("Head of queue (peek): " + tasks.peek());

        // Step 4: Poll (remove) the head element
        String firstTask = tasks.poll();
        System.out.println("Polled task: " + firstTask);
        System.out.println("Queue after poll: " + tasks);

        // Step 5: Check if queue contains 'Medium priority task'
        System.out.println("Contains 'Medium priority task'? " + tasks.contains("Medium priority task"));

        // Step 6: Iterate over queue elements
        System.out.println("Iterating through queue:");
        for (String task : tasks) {
            System.out.println(task);
        }
    }
}
