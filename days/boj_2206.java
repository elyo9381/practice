import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;

public class boj_2206 {

    static int[] dx = {0,1,0, -1};
    static int[] dy = {1,0, -1,0};
    
    static int n  , m  , result = 0;

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        int[][] map = new int[n][m];
        boolean[][][] visited = new boolean[n][m][2];

        for(int i = 0 ;i <n ; i++){
            st = new StringTokenizer(br.readLine());
            String s = st.nextToken();
            for(int j = 0 ;j <m ; j++){
                map[i][j] =  s.charAt(j)- '0';
            }
        }


        //최단거리 진행

        Queue<int[]> q = new LinkedList();
        visited[0][0][0] = true;
        q.offer(new int[]{0,0,0,1});

        while(!q.isEmpty()){
            int[] cur = q.poll();
            int x = cur[0] , y = cur[1] , broken = cur[2], dist = cur[3];

            if(x == n-1 && y == m-1){
                System.out.println(dist);
                return ;
            }

            for(int i = 0 ; i<4; i++){
                int nx = dx[i] + x; 
                int ny = dy[i] + y; 

                if( nx < 0 || ny < 0 || nx >= n || ny >= m) continue ;
                if( map[nx][ny] == 1 && broken == 1 ) continue ;
                
                int newBroken = (map[nx][ny] == 1) ? 1: broken;

                if(visited[nx][ny][newBroken]) continue;
                visited[nx][ny][newBroken] = true;
        
                q.offer(new int[]{nx,ny,newBroken,dist+1});
            }
        }
        System.out.println(-1);
        return ;
    }
}