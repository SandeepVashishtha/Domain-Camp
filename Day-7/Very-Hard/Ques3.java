public class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        int[] parent = new int[edges.length + 1];
        for (int i = 0; i < parent.length; i++) {
            parent[i] = i;
        }

        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            int rootU = find(parent, u), rootV = find(parent, v);
            if (rootU == rootV) {
                return edge;
            }
            parent[rootU] = rootV;
        }
        return new int[0];
    }

    private int find(int[] parent, int u) {
        if (parent[u] != u) {
            parent[u] = find(parent, parent[u]);
        }
        return parent[u];
    }
}