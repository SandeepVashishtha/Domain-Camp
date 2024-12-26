public class class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class BinaryTreeSum {
    public int sumOfNodes(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return root.val + sumOfNodes(root.left) + sumOfNodes(root.right);
    }
}