import java.util.HashMap;
import java.util.Map;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class Solution {
    private Map<Integer, Integer> inorderIndexMap;
    private int postorderIndex;

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        inorderIndexMap = new HashMap<>();
        for (int i = 0; i < inorder.length; i++) {
            inorderIndexMap.put(inorder[i], i);
        }
        postorderIndex = postorder.length - 1;
        return buildTreeHelper(postorder, 0, inorder.length - 1);
    }

    private TreeNode buildTreeHelper(int[] postorder, int left, int right) {
        if (left > right) return null;

        int rootValue = postorder[postorderIndex--];
        TreeNode root = new TreeNode(rootValue);

        root.right = buildTreeHelper(postorder, inorderIndexMap.get(rootValue) + 1, right);
        root.left = buildTreeHelper(postorder, left, inorderIndexMap.get(rootValue) - 1);

        return root;
    }
}