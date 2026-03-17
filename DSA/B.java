import java.util.LinkedList;
import java.util.Queue;

class Node {
    int data;
    Node next;
    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class B {

    // 1. Bubble Sort
    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        for(int i = 0; i < n-1; i++)
            for(int j = 0; j < n-i-1; j++)
                if(arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
    }

    // 2. Insertion Sort
    public static void insertionSort(int[] arr) {
        for(int i = 1; i < arr.length; i++) {
            int key = arr[i];
            int j = i - 1;
            while(j >= 0 && arr[j] > key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }

    // 3. Selection Sort
    public static void selectionSort(int[] arr) {
        for(int i = 0; i < arr.length - 1; i++) {
            int minIdx = i;
            for(int j = i + 1; j < arr.length; j++)
                if(arr[j] < arr[minIdx])
                    minIdx = j;

            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }

    // 4. Merge Sort
    public static void mergeSort(int[] arr, int left, int right) {
        if(left < right) {
            int mid = (left + right) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid+1, right);
            merge(arr, left, mid, right);
        }
    }

    public static void merge(int[] arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int[] L = new int[n1];
        int[] R = new int[n2];
        for(int i = 0; i < n1; i++) L[i] = arr[left + i];
        for(int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while(i < n1 && j < n2)
            arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
        while(i < n1) arr[k++] = L[i++];
        while(j < n2) arr[k++] = R[j++];
    }

    // 5. Queue using LinkedList
    public static void demonstrateQueue() {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(10);
        queue.add(20);
        queue.add(30);
        System.out.println("Queue Front: " + queue.peek());
        queue.remove();
        System.out.println("Queue After Removal: " + queue.peek());
    }

    // 6. Linked List Search
    Node head;

    public void addToLinkedList(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }

    public boolean searchLinkedList(int key) {
        Node current = head;
        while(current != null) {
            if(current.data == key)
                return true;
            current = current.next;
        }
        return false;
    }

    // Utility to print arrays
    public static void printArray(String msg, int[] arr) {
        System.out.print(msg);
        for(int n : arr) System.out.print(n + " ");
        System.out.println();
    }

    // MAIN
    public static void main(String[] args) {
        AlgorithmsDemo demo = new AlgorithmsDemo();

        int[] array1 = {64, 34, 25, 12, 22, 11, 90};
        int[] array2 = array1.clone();
        int[] array3 = array1.clone();
        int[] array4 = array1.clone();

        // Bubble Sort
        bubbleSort(array1);
        printArray("Bubble Sorted: ", array1);

        // Insertion Sort
        insertionSort(array2);
        printArray("Insertion Sorted: ", array2);

        // Selection Sort
        selectionSort(array3);
        printArray("Selection Sorted: ", array3);

        // Merge Sort
        mergeSort(array4, 0, array4.length - 1);
        printArray("Merge Sorted: ", array4);

        // Queue
        System.out.println("\nQueue Demo:");
        demonstrateQueue();

        // Linked List and Search
        System.out.println("\nLinked List Search:");
        demo.addToLinkedList(30);
        demo.addToLinkedList(20);
        demo.addToLinkedList(10);
        System.out.println("Search 20: " + demo.searchLinkedList(20));
        System.out.println("Search 40: " + demo.searchLinkedList(40));
    }
}
