public class Ques5 {
    static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }

        ListNode slow = head;
        ListNode fast = head.next;

        while (slow != fast) {
            if (fast == null || fast.next == null) {
                return false;
            }
            slow = slow.next;
            fast = fast.next.next;
        }

        return true;
    }

    public static void main(String[] args) {
        Ques5 solution = new Ques5();

        // Example 1
        ListNode head1 = new ListNode(3);
        head1.next = new ListNode(2);
        head1.next.next = new ListNode(0);
        head1.next.next.next = new ListNode(-4);
        head1.next.next.next.next = head1.next; // pos = 1
        System.out.println(solution.hasCycle(head1)); // Output: true

        // Example 2
        ListNode head2 = new ListNode(1);
        head2.next = new ListNode(2);
        head2.next.next = head2; // pos = 0
        System.out.println(solution.hasCycle(head2)); // Output: true

        // Example 3
        ListNode head3 = new ListNode(1); // pos = -1
        System.out.println(solution.hasCycle(head3)); // Output: false
    }
}