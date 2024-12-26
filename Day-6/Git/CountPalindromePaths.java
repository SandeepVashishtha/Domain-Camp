import java.util.HashMap;
import java.util.Map;

public class CountPalindromePaths {
    private int count = 0;

    public int countPalindromePaths(int[] parent, String s) {
        Map<Integer, Integer> pathCount = new HashMap<>();
        pathCount.put(0, 1);
        dfs(0, 0, parent, s, pathCount);
        return count;
    }

    private void dfs(int node, int mask, int[] parent, String s, Map<Integer, Integer> pathCount) {
        if (node != 0) {
            mask ^= 1 << (s.charAt(node) - 'a');
        }
        count += pathCount.getOrDefault(mask, 0);
        for (int i = 0; i < 26; i++) {
            count += pathCount.getOrDefault(mask ^ (1 << i), 0);
        }
        pathCount.put(mask, pathCount.getOrDefault(mask, 0) + 1);
        for (int i = 1; i < parent.length; i++) {
            if (parent[i] == node) {
                dfs(i, mask, parent, s, pathCount);
            }
        }
        pathCount.put(mask, pathCount.get(mask) - 1);
    }

    public static void main(String[] args) {
        CountPalindromePaths cpp = new CountPalindromePaths();
        int[] parent = {-1, 0, 0, 1, 1, 2};
        String s = "acaabc";
        System.out.println(cpp.countPalindromePaths(parent, s)); // Output: 8
    }
}