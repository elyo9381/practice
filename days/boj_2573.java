import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;

public class boj_2573 {

    static int[] dx = {0,1,0,-1 };
    static int[] dy = {1,0,-1,0 };

    static int n , m ;

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        int[][] map = new int[n][m];
        for(int i = 0 ; i<n ;i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0 ; j<m ;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int time = 0;
        while(true){

            // 1. 분리된것들인지 검사 분리됬으면 종료 

            int cnt = check(map);
            if(cnt >=2 ) break;
            if(cnt == 0) { time = 0; break; }

            // 각 요소마다 bfs진행해서 0과 인접하지 여부 체크후 하나씩 줄어드는거 체크 
            int zeroCnt = 0;
            int[][] melt = new int[n][m];
            for(int i = 0 ; i<n; i++){
                for(int j = 0 ; j<n; j++){
                    if( map[i][j] > 0){
                        for(int d = 0 ; d<4; d++){
                            int nx = dx[d]+i;
                            int ny = dy[d]+j;
                            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                            if (map[nx][ny] == 0) zeroCnt++;
                        }
                        melt[i][j] = zeroCnt;
                    }
                }
            }

            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j<m;j++){
                    map[i][j] = Math.max(0,map[i][j] - melt[i][j]);
                }
            }
            
            time++;
        }
        System.out.println(time);
    }

    private static int check(int[][] map){
        int answer  = 0 ;
        boolean[][] visited = new boolean[n][m];

        for(int i = 0 ; i<n; i++){
            for(int j = 0 ; j<m; j++){
                if(!visited[i][j] && map[i][j] > 0){
                    dfs(i,j,visited , map);
                    answer++;
                }
            }
        }
        return answer;
    }


    private static void dfs(int x,int y,boolean[][] visited , int[][] map){
        if(visited[x][y]) return ;
        visited[x][y] = true;
        for(int i = 0 ; i<4; i++){
            int nx = dx[i]+x;
            int ny = dy[i]+y;
            if( nx < 0 || ny < 0 || nx >=n || ny >=m) continue;
            if(visited[nx][ny] || map[nx][ny] == 0 ) continue;
            dfs(nx,ny,visited,map);
        }
    }


}