public class Ques9 {

    // Definition for singly-linked list.
    public static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    // Function to remove elements from linked list
    public ListNode removeElements(ListNode head, int val) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode current = dummy;
        
        while (current.next != null) {
            if (current.next.val == val) {
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }
        
        return dummy.next;
    }

    // Function to reverse linked list iteratively
    public ListNode reverseListIterative(ListNode head) {
        ListNode prev = null;
        ListNode current = head;
        
        while (current != null) {
            ListNode nextNode = current.next;
            current.next = prev;
            prev = current;
            current = nextNode;
        }
        
        return prev;
    }

    // Function to reverse linked list recursively
    public ListNode reverseListRecursive(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode newHead = reverseListRecursive(head.next);
        head.next.next = head;
        head.next = null;
        
        return newHead;
    }

    public static void main(String[] args) {
        Ques9 solution = new Ques9();

        // Example for removeElements
        ListNode head1 = new ListNode(1, new ListNode(2, new ListNode(6, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))));
        int val = 6;
        ListNode result1 = solution.removeElements(head1, val);
        printList(result1); // Output: [1, 2, 3, 4, 5]

        // Example for reverseListIterative
        ListNode head2 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
        ListNode result2 = solution.reverseListIterative(head2);
        printList(result2); // Output: [5, 4, 3, 2, 1]

        // Example for reverseListRecursive
        ListNode head3 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
        ListNode result3 = solution.reverseListRecursive(head3);
        printList(result3); // Output: [5, 4, 3, 2, 1]
    }

    // Helper function to print the linked list
    public static void printList(ListNode head) {
        ListNode current = head;
        while (current != null) {
            System.out.print(current.val + " ");
            current = current.next;
        }
        System.out.println();
    }
}