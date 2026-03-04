import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;

public class boj_16236 {

    static int[] dx = {0,1,0,-1 };
    static int[] dy = {1,0,-1,0 };

    static int n;

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());

        int[][] map = new int[n][n];
        int sx= 0 , sy = 0;
        int size = 2, eaten = 0 , time = 0 ;

        for(int i = 0 ; i<n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0 ; j<n;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                if (map[i][j] == 9 ) {
                    map[i][j] = 0 ;
                    sx = i; sy = j;
                }
            }
        }

        while(true){
            int[][] dist = new int[n][n];
            for(int[] row : dist) Arrays.fill(row ,-1);
            dist[sx][sy] = 0 ;

            Queue<int[]> q = new LinkedList<>();
            q.offer(new int[]{sx,sy});

            while(!q.isEmpty()){
                int[] cur = q.poll();
                int x = cur[0] , y = cur[1];

                for(int i = 0 ; i<4; i++){
                    int nx = dx[i]+x;
                    int ny = dy[i]+y;

                    if( nx < 0 || ny < 0 || nx >=n || ny >=n ) continue;
                    if( map[nx][ny] > size) continue;
                    if( dist[nx][ny] != -1) continue;

                    dist[nx][ny] = dist[x][y] +1;
                    q.offer(new int[]{nx,ny});
                }
            }

            ArrayList<int[]> fishs = new ArrayList<>();
            for(int i =0; i<n; i++){
                for(int j =0; j<n; j++){
                    if( map[i][j] > 0 && map[i][j] < size && dist[i][j] != -1){
                        fishs.add(new int[]{i,j,dist[i][j]});
                    }
                } 
            }

            if(fishs.isEmpty()){
                break;
            }

            fishs.sort((a,b) ->{
                if( a[2] != b[2])return a[2]-b[2];
                if( a[0] != b[0])return a[0]-b[0];
                return a[1]-b[1];
            });

            int[] target = fishs.get(0);
            time+=target[2];
            sx = target[0];
            sy = target[1];
            map[sx][sy] = 0;
            eaten++;

            if(size == eaten){
                size++;
                eaten = 0;
            }
        }

        System.out.println(time);
    }
}