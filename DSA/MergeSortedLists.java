class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class MergeSortedLists {

    // Function to print the linked list
    static void printList(Node head) {
        while (head != null) {
            System.out.print(head.data + " -> ");
            head = head.next;
        }
        System.out.println("NULL");
    }

    // Function to merge two sorted linked lists
    static Node mergeLists(Node l1, Node l2) {
        // Dummy node to make merging easier
        Node dummy = new Node(0);
        Node tail = dummy;

        // Merge while both lists are not empty
        while (l1 != null && l2 != null) {
            if (l1.data < l2.data) {
                tail.next = l1;
                l1 = l1.next;
            } else {
                tail.next = l2;
                l2 = l2.next;
            }
            tail = tail.next;
        }

        // Attach remaining elements
        if (l1 != null) {
            tail.next = l1;
        } else {
            tail.next = l2;
        }

        return dummy.next;
    }

    public static void main(String[] args) {
        // Create List 1: 1 -> 3 -> 6 -> 8 -> 10
        Node l1 = new Node(1);
        l1.next = new Node(3);
        l1.next.next = new Node(6);
        l1.next.next.next = new Node(8);
        l1.next.next.next.next = new Node(10);

        // Create List 2: 2 -> 4 -> 5 -> 7 -> 9
        Node l2 = new Node(2);
        l2.next = new Node(4);
        l2.next.next = new Node(5);
        l2.next.next.next = new Node(7);
        l2.next.next.next.next = new Node(9);

        // Merge and print
        Node merged = mergeLists(l1, l2);
        System.out.print("Merged List: ");
        printList(merged);
    }
}
