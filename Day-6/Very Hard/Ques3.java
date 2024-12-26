import java.util.*;

class Solution {
    private int count = 0;

    public int countPossibleRoots(int[][] edges, int[][] guesses, int k) {
        int n = edges.length + 1;
        List<Integer>[] tree = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            tree[i] = new ArrayList<>();
        }
        for (int[] edge : edges) {
            tree[edge[0]].add(edge[1]);
            tree[edge[1]].add(edge[0]);
        }
        Set<String> guessSet = new HashSet<>();
        for (int[] guess : guesses) {
            guessSet.add(guess[0] + "," + guess[1]);
        }
        dfs(tree, guessSet, 0, -1, k);
        return count;
    }

    private int dfs(List<Integer>[] tree, Set<String> guessSet, int node, int parent, int k) {
        int correctGuesses = 0;
        for (int child : tree[node]) {
            if (child != parent) {
                correctGuesses += dfs(tree, guessSet, child, node, k);
            }
        }
        if (guessSet.contains(parent + "," + node)) {
            correctGuesses++;
        }
        if (correctGuesses >= k) {
            count++;
        }
        return correctGuesses;
    }
}