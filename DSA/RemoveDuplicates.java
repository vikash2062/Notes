class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class RemoveDuplicates {

    // Function to remove duplicates from sorted linked list
    static Node removeDuplicates(Node head) {
        Node current = head;

        // Traverse the list
        while (current != null && current.next != null) {
            if (current.data == current.next.data) {
                // Skip the duplicate node
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }
        return head;
    }

    // Print the linked list
    static void printList(Node head) {
        while (head != null) {
            System.out.print(head.data + " -> ");
            head = head.next;
        }
        System.out.println("NULL");
    }

    public static void main(String[] args) {
        // Create sorted list: 1 -> 1 -> 2 -> 3 -> 3 -> 4 -> 5 -> 5
        Node head = new Node(1);
        head.next = new Node(1);
        head.next.next = new Node(2);
        head.next.next.next = new Node(3);
        head.next.next.next.next = new Node(3);
        head.next.next.next.next.next = new Node(4);
        head.next.next.next.next.next.next = new Node(5);
        head.next.next.next.next.next.next.next = new Node(5);

        System.out.println("Original List:");
        printList(head);

        // Remove duplicates
        head = removeDuplicates(head);

        System.out.println("List After Removing Duplicates:");
        printList(head);
    }
}
