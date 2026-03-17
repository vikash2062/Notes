import java.util.Scanner;

public class CircularQueue {
    int size, front, rear;
    int[] queue;

    CircularQueue(int size) {
        this.size = size;
        queue = new int[size];
        front = -1;
        rear = -1;
    }

    // Insert an element
    void enqueue(int value) {
        if ((rear + 1) % size == front) {
            System.out.println("Queue is Full!");
            return;
        } else if (front == -1) { // First element
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        queue[rear] = value;
        System.out.println("Inserted: " + value);
    }

    // Delete an element
    void dequeue() {
        if (front == -1) {
            System.out.println("Queue is Empty!");
            return;
        }

        System.out.println("Deleted: " + queue[front]);

        if (front == rear) { // Only one element
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    // Display the queue
    void display() {
        if (front == -1) {
            System.out.println("Queue is Empty!");
            return;
        }

        System.out.print("Queue: ");
        int i = front;
        while (true) {
            System.out.print(queue[i] + " ");
            if (i == rear) break;
            i = (i + 1) % size;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        CircularQueue cq = new CircularQueue(5); // Size of queue

        while (true) {
            System.out.println("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
            System.out.print("Choose: ");
            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter value to insert: ");
                    int val = sc.nextInt();
                    cq.enqueue(val);
                    break;
                case 2:
                    cq.dequeue();
                    break;
                case 3:
                    cq.display();
                    break;
                case 4:
                    System.out.println("Exiting...");
                    return;
                default:
                    System.out.println("Invalid Choice!");
            }
        }
    }
}
