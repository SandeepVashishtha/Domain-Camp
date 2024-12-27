import java.util.*;

public class Solution {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        Map<String, Map<String, Double>> graph = new HashMap<>();
        for (int i = 0; i < equations.size(); i++) {
            String a = equations.get(i).get(0);
            String b = equations.get(i).get(1);
            graph.putIfAbsent(a, new HashMap<>());
            graph.putIfAbsent(b, new HashMap<>());
            graph.get(a).put(b, values[i]);
            graph.get(b).put(a, 1.0 / values[i]);
        }

        double[] result = new double[queries.size()];
        for (int i = 0; i < queries.size(); i++) {
            String a = queries.get(i).get(0);
            String b = queries.get(i).get(1);
            if (!graph.containsKey(a) || !graph.containsKey(b)) {
                result[i] = -1.0;
            } else {
                result[i] = dfs(graph, a, b, new HashSet<>());
            }
        }

        return result;
    }

    private double dfs(Map<String, Map<String, Double>> graph, String a, String b, Set<String> visited) {
        if (a.equals(b)) return 1.0;
        visited.add(a);
        for (Map.Entry<String, Double> neighbor : graph.get(a).entrySet()) {
            if (!visited.contains(neighbor.getKey())) {
                double result = dfs(graph, neighbor.getKey(), b, visited);
                if (result != -1.0) {
                    return result * neighbor.getValue();
                }
            }
        }
        return -1.0;
    }
}