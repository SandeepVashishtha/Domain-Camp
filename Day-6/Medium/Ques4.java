class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class Solution {
    public int sumNumbers(TreeNode root) {
        return sumNumbersHelper(root, 0);
    }

    private int sumNumbersHelper(TreeNode node, int currentSum) {
        if (node == null) return 0;

        currentSum = currentSum * 10 + node.val;
        if (node.left == null && node.right == null) return currentSum;

        return sumNumbersHelper(node.left, currentSum) + sumNumbersHelper(node.right, currentSum);
    }
}