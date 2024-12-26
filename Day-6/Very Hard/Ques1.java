import java.util.*;

class Solution {
    private int count = 0;
    private Map<Integer, Integer> freqMap = new HashMap<>();

    public int countPalindromePaths(int[] parent, String s) {
        int n = parent.length;
        List<Integer>[] tree = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            tree[i] = new ArrayList<>();
        }
        for (int i = 1; i < n; i++) {
            tree[parent[i]].add(i);
        }
        dfs(tree, s, 0, 0);
        return count;
    }

    private void dfs(List<Integer>[] tree, String s, int node, int mask) {
        mask ^= 1 << (s.charAt(node) - 'a');
        count += freqMap.getOrDefault(mask, 0);
        for (int i = 0; i < 26; i++) {
            count += freqMap.getOrDefault(mask ^ (1 << i), 0);
        }
        freqMap.put(mask, freqMap.getOrDefault(mask, 0) + 1);
        for (int child : tree[node]) {
            dfs(tree, s, child, mask);
        }
        freqMap.put(mask, freqMap.get(mask) - 1);
    }
}