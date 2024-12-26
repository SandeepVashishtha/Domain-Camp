import java.util.*;

class Solution {
    public int numberOfGoodPaths(int[] vals, int[][] edges) {
        int n = vals.length;
        List<Integer>[] tree = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            tree[i] = new ArrayList<>();
        }
        for (int[] edge : edges) {
            tree[edge[0]].add(edge[1]);
            tree[edge[1]].add(edge[0]);
        }
        int[] parent = new int[n];
        int[] size = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        int[] count = new int[n];
        Arrays.fill(count, 1);
        int result = n;
        List<int[]> sortedNodes = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sortedNodes.add(new int[]{vals[i], i});
        }
        sortedNodes.sort(Comparator.comparingInt(a -> a[0]));
        for (int[] node : sortedNodes) {
            int value = node[0];
            int u = node[1];
            for (int v : tree[u]) {
                if (vals[v] <= value) {
                    int rootU = find(parent, u);
                    int rootV = find(parent, v);
                    if (rootU != rootV) {
                        result += count[rootU] * count[rootV];
                        parent[rootU] = rootV;
                        count[rootV] += count[rootU];
                    }
                }
            }
        }
        return result;
    }

    private int find(int[] parent, int u) {
        if (parent[u] != u) {
            parent[u] = find(parent, parent[u]);
        }
        return parent[u];
    }
}