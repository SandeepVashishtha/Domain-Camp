import java.util.*;

public class Solution {
    public List<Integer> bfsOfGraph(int V, List<List<Integer>> adj) {
        List<Integer> bfsTraversal = new ArrayList<>();
        boolean[] visited = new boolean[V];
        Queue<Integer> queue = new LinkedList<>();
        queue.add(0);
        visited[0] = true;

        while (!queue.isEmpty()) {
            int node = queue.poll();
            bfsTraversal.add(node);
            for (int neighbor : adj.get(node)) {
                if (!visited[neighbor]) {
                    queue.add(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        return bfsTraversal;
    }
}