import java.util.*;

public class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[][] dist = new int[m][n];
        Queue<int[]> queue = new LinkedList<>();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    queue.add(new int[]{i, j});
                } else {
                    dist[i][j] = Integer.MAX_VALUE;
                }
            }
        }

        int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            for (int[] dir : directions) {
                int r = cell[0] + dir[0];
                int c = cell[1] + dir[1];
                if (r >= 0 && r < m && c >= 0 && c < n && dist[r][c] > dist[cell[0]][cell[1]] + 1) {
                    dist[r][c] = dist[cell[0]][cell[1]] + 1;
                    queue.add(new int[]{r, c});
                }
            }
        }

        return dist;
    }
}