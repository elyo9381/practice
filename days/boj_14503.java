import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;

public class boj_14503 {

    static int[] dx = {-1,0,1,0,};
    static int[] dy = {0,1,0,-1};
    static int n , m;

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());

        int[][] maps = new int[n][m];
        boolean[][] visited = new boolean[n][m];

        for(int i = 0 ; i<n ;i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0 ; j<m; j++){
                maps[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int count = 0;
        while(true){

            if(!visited[x][y]) {
                visited[x][y] = true;
                count++;
            }

            boolean moved = false;

            for(int i = 0 ; i<4; i++){
                d = (d -1 + 4) % 4;
                int nx = dx[d] + x; 
                int ny = dy[d] + y; 
                if( nx < 0 || ny < 0 ||  nx >=n || ny >=m ) continue;
                if( !visited[nx][ny] && maps[nx][ny] == 0 ) {
                    x = nx;
                    y = ny;
                    moved = true;
                    break;
                }
            }

            if(!moved){
                int newD = (d + 2) % 4;
                int nx = dx[newD] + x;
                int ny = dy[newD] + y;

                if( maps[nx][ny] == 0 ) {
                    x = nx;
                    y = ny;
                } else {
                    break;
                }
            }
            
        }

        System.out.println(count);
        return ;
    }
}