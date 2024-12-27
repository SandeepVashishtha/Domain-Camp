import java.util.*;

public class Solution {
    public List<Integer> dfsOfGraph(int V, List<List<Integer>> adj) {
        List<Integer> dfsTraversal = new ArrayList<>();
        boolean[] visited = new boolean[V];
        dfs(0, adj, visited, dfsTraversal);
        return dfsTraversal;
    }

    private void dfs(int node, List<List<Integer>> adj, boolean[] visited, List<Integer> dfsTraversal) {
        visited[node] = true;
        dfsTraversal.add(node);
        for (int neighbor : adj.get(node)) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, dfsTraversal);
            }
        }
    }
}