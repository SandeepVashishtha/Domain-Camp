public class Ques3 {
    public static void main(String[] args) {
        int[] nums1 = {-10, -3, 0, 5, 9};
        TreeNode root1 = sortedArrayToBST(nums1);
        printTree(root1);

        int[] nums2 = {1, 3};
        TreeNode root2 = sortedArrayToBST(nums2);
        printTree(root2);
    }

    public static TreeNode sortedArrayToBST(int[] nums) {
        if (nums == null || nums.length == 0) {
            return null;
        }
        return helper(nums, 0, nums.length - 1);
    }

    private static TreeNode helper(int[] nums, int left, int right) {
        if (left > right) {
            return null;
        }
        int mid = left + (right - left) / 2;
        TreeNode node = new TreeNode(nums[mid]);
        node.left = helper(nums, left, mid - 1);
        node.right = helper(nums, mid + 1, right);
        return node;
    }

    private static void printTree(TreeNode root) {
        if (root != null) {
            System.out.print(root.val + " ");
            printTree(root.left);
            printTree(root.right);
        }
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}