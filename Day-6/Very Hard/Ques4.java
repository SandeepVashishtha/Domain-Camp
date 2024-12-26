import java.util.*;

class Solution {
    private int maxLength = 0;

    public int longestPath(int[] parent, String s) {
        int n = parent.length;
        List<Integer>[] tree = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            tree[i] = new ArrayList<>();
        }
        for (int i = 1; i < n; i++) {
            tree[parent[i]].add(i);
        }
        dfs(tree, s, 0);
        return maxLength;
    }

    private int dfs(List<Integer>[] tree, String s, int node) {
        int max1 = 0, max2 = 0;
        for (int child : tree[node]) {
            int length = dfs(tree, s, child);
            if (s.charAt(node) != s.charAt(child)) {
                if (length > max1) {
                    max2 = max1;
                    max1 = length;
                } else if (length > max2) {
                    max2 = length;
                }
            }
        }
        maxLength = Math.max(maxLength, max1 + max2 + 1);
        return max1 + 1;
    }
}