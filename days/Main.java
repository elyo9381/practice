import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;

public class Main {

    static int[] dx = {0,1,0,-1 };
    static int[] dy = {1,0,-1,0 };
    static int[] dz = {1,-1};

    static int n , m, h;
    static int result = 98764321;

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());


        int[][][] map = new int[n][m][h];
        boolean[][][] visited = new boolean[n][m][h];
        Queue<int[]> q = new LinkedList<>();

        for(int k = 0 ; k < h; k++){
            for(int i = 0 ; i<n;i++){
                st = new StringTokenizer(br.readLine());
                for(int j = 0 ; j<m;j++){
                    map[i][j][k] = Integer.parseInt(st.nextToken());
                    if(map[i][j][k] == 1){
                        visited[i][j][k] = true;
                        q.add(new int[]{i,j,k});
                    }
                }
            }
        }
        
        while(!q.isEmpty()){

            int[] cur = q.poll();
            int x = cur[0], y = cur[1] , z = cur[2];

            for(int i = 0 ; i < 4;i++){
                int nx = dx[i] + x;
                int ny = dy[i] + y;

                if( nx < 0 || ny < 0 || nx >=n || ny >=m) continue;
                if( visited[nx][ny][z] || map[nx][ny][z] >= 1 || map[nx][ny][z] == -1) continue;

                map[nx][ny][z] = map[x][y][z] + 1;
                visited[nx][ny][z] = true;
                q.offer(new int[]{nx,ny,z});
            }

            for(int i = 0 ; i < 2;i++){
                int nz = dz[i] + z;

                if( nz < 0 || nz >=h ) continue;
                if( visited[x][y][nz] || map[x][y][nz] >= 1 || map[x][y][nz] == -1) continue;

                map[x][y][nz] = map[x][y][z] + 1;
                visited[x][y][nz] = true;
                q.offer(new int[]{x,y,nz});
            }

        }

        int ans = 0 ;
        for(int i = 0 ; i<n; i++){
            for(int j = 0 ; j<m; j++){
                for(int k = 0 ; k<h; k++){
                    if(map[i][j][k] == 0 && !visited[i][j][k]){
                        System.out.println(-1);
                        return;
                    }
                    ans = Math.max(ans,map[i][j][k]);
                }
            }
        }
        System.out.println(ans);
        return ;
    }
}