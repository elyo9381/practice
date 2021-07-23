package elyowon.leetcode.graph;


import java.util.LinkedList;
import java.util.Queue;

/**
 * 최단 거리 찾기 문제
 * bfs풀이이다.
 *
 * 하지만 더 공부해볼 여지가 있다.
 * 다익스트라, A*알고리즘을 봐보쟈
 */


public class leetcode_1091_graphShortPath {

    int[] dy = {-1,-1,-1,0,0,1,1,1};
    int[] dx = {-1,0,1,-1,1,-1,0,1};

    public int shortestPathBinaryMatrix(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0,0,0});

        while (!q.isEmpty()) {
            int[] cur = q.remove();
            if (cur[0] == m - 1 && cur[1] == n - 1) {
                return cur[2] + 1;
            }

            for (int j = 0; j < 8; j++) {
                int ny = dy[j] + cur[0];
                int nx = dx[j] + cur[1];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[ny][nx] != 0) continue;

                grid[ny][nx] = -1;
                q.add(new int[]{ny,nx,cur[2] + 1});
            }
        }
        return -1;
    }
}
