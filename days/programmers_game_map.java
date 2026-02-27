import java.util.*;

class Solution {

    int[] dx = {1,0,-1,0};
    int[] dy = {0,-1,0,1};

    public int solution(int[][] maps) {
        int n = maps.length;
        int m = maps[0].length;

        boolean[][] visited = new boolean[n][m];
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{0,0});
        visited[0][0] = true;

        while(!q.isEmpty()){
            int[] cur = q.poll();
            int x = cur[0], y = cur[1];

            for(int i = 0; i < 4; i++){
                int nx = dx[i] + x;
                int ny = dy[i] + y;

                if(nx < 0 || ny < 0 || nx >= n || ny >= m
                  || visited[nx][ny] || maps[nx][ny] == 0) continue;

                maps[nx][ny] = maps[x][y] + 1;
                visited[nx][ny] = true;
                q.offer(new int[]{nx,ny});
            }
        }

        return maps[n-1][m-1] == 1 ? -1 : maps[n-1][m-1];
    }
}
