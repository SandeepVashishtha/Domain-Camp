import java.util.*;

class Solution {
    private int count = 0;

    public int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        List<Integer>[] tree = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            tree[i] = new ArrayList<>();
        }
        for (int[] edge : edges) {
            tree[edge[0]].add(edge[1]);
            tree[edge[1]].add(edge[0]);
        }
        dfs(tree, values, 0, -1, k);
        return count;
    }

    private int dfs(List<Integer>[] tree, int[] values, int node, int parent, int k) {
        int sum = values[node];
        for (int child : tree[node]) {
            if (child != parent) {
                sum += dfs(tree, values, child, node, k);
            }
        }
        if (sum % k == 0) {
            count++;
            return 0;
        }
        return sum;
    }
}