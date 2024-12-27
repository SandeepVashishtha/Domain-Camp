public class Solution {
    public int maxNumEdgesToRemove(int n, int[][] edges) {
        UnionFind alice = new UnionFind(n);
        UnionFind bob = new UnionFind(n);
        int removedEdges = 0;

        for (int[] edge : edges) {
            if (edge[0] == 3) {
                boolean aliceUnion = alice.union(edge[1], edge[2]);
                boolean bobUnion = bob.union(edge[1], edge[2]);
                if (!aliceUnion && !bobUnion) {
                    removedEdges++;
                }
            }
        }

        for (int[] edge : edges) {
            if (edge[0] == 1) {
                if (!alice.union(edge[1], edge[2])) {
                    removedEdges++;
                }
            } else if (edge[0] == 2) {
                if (!bob.union(edge[1], edge[2])) {
                    removedEdges++;
                }
            }
        }

        if (alice.count != 1 || bob.count != 1) {
            return -1;
        }

        return removedEdges;
    }

    class UnionFind {
        int[] parent;
        int[] rank;
        int count;

        public UnionFind(int n) {
            parent = new int[n + 1];
            rank = new int[n + 1];
            count = n;
            for (int i = 1; i <= n; i++) {
                parent[i] = i;
            }
        }

        public int find(int u) {
            if (parent[u] != u) {
                parent[u] = find(parent[u]);
            }
            return parent[u];
        }

        public boolean union(int u, int v) {
            int rootU = find(u);
            int rootV = find(v);
            if (rootU == rootV) {
                return false;
            }
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
            count--;
            return true;
        }
    }
}