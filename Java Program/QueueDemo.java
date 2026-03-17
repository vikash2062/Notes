import java.util.Scanner;

class LinearQueue {
    private int[] queue;
    private int front;
    private int rear;
    private int capacity;

    public LinearQueue(int capacity) {
        this.capacity = capacity;
        this.queue = new int[capacity];
        this.front = -1;
        this.rear = -1;
    }

    public boolean isEmpty() {
        return front == -1;
    }

    public boolean isFull() {
        return rear == capacity - 1;
    }

    public void enqueue(int data) {
        if (isFull()) {
            System.out.println("Linear Queue is full. Cannot enqueue " + data);
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        queue[++rear] = data;
        System.out.println(data + " enqueued into Linear Queue.");
    }

    public int dequeue() {
        if (isEmpty()) {
            System.out.println("Linear Queue is empty. Cannot dequeue.");
            return -1;
        }
        int data = queue[front++];
        if (front > rear) {
            front = rear = -1;
        }
        System.out.println(data + " dequeued from Linear Queue.");
        return data;
    }

    public void display() {
        if (isEmpty()) {
            System.out.println("Linear Queue is empty.");
            return;
        }
        System.out.println("Elements in Linear Queue:");
        for (int i = front; i <= rear; i++) {
            System.out.print(queue[i] + " ");
        }
        System.out.println();
    }
}

class CircularQueue {
    private int[] queue;
    private int front;
    private int rear;
    private int capacity;
    private int size;

    public CircularQueue(int capacity) {
        this.capacity = capacity;
        this.queue = new int[capacity];
        this.front = -1;
        this.rear = -1;
        this.size = 0;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean isFull() {
        return size == capacity;
    }

    public void enqueue(int data) {
        if (isFull()) {
            System.out.println("Circular Queue is full. Cannot enqueue " + data);
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = data;
        size++;
        System.out.println(data + " enqueued into Circular Queue.");
    }

    public int dequeue() {
        if (isEmpty()) {
            System.out.println("Circular Queue is empty. Cannot dequeue.");
            return -1;
        }
        int dequeuedElement = queue[front];
        front = (front + 1) % capacity;
        size--;
        if (isEmpty()) {
            front = -1;
            rear = -1;
        }
        System.out.println(dequeuedElement + " dequeued from Circular Queue.");
        return dequeuedElement;
    }

    public void display() {
        if (isEmpty()) {
            System.out.println("Circular Queue is empty.");
            return;
        }
        System.out.println("Elements in Circular Queue:");
        int i = front;
        int count = 0;
        while (count < size) {
            System.out.print(queue[i] + " ");
            i = (i + 1) % capacity;
            count++;
        }
        System.out.println();
    }
}

public class QueueDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinearQueue lq = new LinearQueue(5);
        CircularQueue cq = new CircularQueue(5);

        while (true) {
            System.out.println("\n--- Menu ---");
            System.out.println("1. Linear Queue Insert");
            System.out.println("2. Linear Queue Delete");
            System.out.println("3. Linear Queue Display");
            System.out.println("4. Circular Queue Insert");
            System.out.println("5. Circular Queue Delete");
            System.out.println("6. Circular Queue Display");
            System.out.println("7. Exit");
            System.out.print("Enter choice: ");
            int ch = sc.nextInt();

            switch (ch) {
                case 1:
                    System.out.print("Enter value: ");
                    lq.enqueue(sc.nextInt());
                    break;
                case 2:
                    lq.dequeue();
                    break;
                case 3:
                    lq.display();
                    break;
                case 4:
                    System.out.print("Enter value: ");
                    cq.enqueue(sc.nextInt());
                    break;
                case 5:
                    cq.dequeue();
                    break;
                case 6:
                    cq.display();
                    break;
                case 7:
                    System.out.println("Exiting...");
                    return;
                default:
                    System.out.println("Invalid choice!");
            }
        }
    }
}
