class ListNode {
    int val;
    ListNode next;
    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class RemoveDuplicates {
    public static ListNode removeDuplicates(ListNode head) {
        if (head == null) return head;

        ListNode current = head;
        
        while (current != null && current.next != null) {
            if (current.val == current.next.val) {
                current.next = current.next.next; 
            } else {
                current = current.next; 
            }
        }

        return head;
    }

    public static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(2);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(3);
        head.next.next.next.next.next = new ListNode(4);
        head.next.next.next.next.next.next = new ListNode(5);


        System.out.println("Original List:");
        printList(head);

        head = removeDuplicates(head);

        System.out.println("List after removing duplicates:");
        printList(head);
    }
}