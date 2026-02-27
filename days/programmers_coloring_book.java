import java.util.*;

class Solution {

    int[] dx = {1,0,-1,0};
    int[] dy = {0,-1,0,1};

    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;

        boolean[][] visited = new boolean[m][n];

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && picture[i][j] > 0){
                    Queue<int[]> q = new LinkedList<>();
                    q.offer(new int[]{i,j});
                    visited[i][j] = true;
                    numberOfArea++;

                    int areaCnt = 1;
                    while(!q.isEmpty()){
                        int[] cur = q.poll();
                        int x = cur[0], y = cur[1];

                        for(int d = 0; d < 4; d++){
                            int nx = dx[d] + x;
                            int ny = dy[d] + y;

                            if(nx < 0 || ny < 0 || nx >= m || ny >= n
                              || visited[nx][ny] || picture[nx][ny] != picture[x][y]) continue;

                            areaCnt++;
                            q.offer(new int[]{nx,ny});
                            visited[nx][ny] = true;
                        }
                        maxSizeOfOneArea = Math.max(maxSizeOfOneArea, areaCnt);
                    }
                }
            }
        }

        return new int[]{numberOfArea, maxSizeOfOneArea};
    }
}
