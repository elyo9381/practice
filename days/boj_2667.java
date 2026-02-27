import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;

public class boj_2667 {

    static int[] dx = {0,1,0, -1};
    static int[] dy = {1,0, -1,0};
    
    static int n ;

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());


        int[][] map = new int[n][n];
        boolean[][] visited = new boolean[n][n];

        for(int i = 0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            String s= st.nextToken();
            for(int j = 0 ; j<n; j++){
                map[i][j] = s.charAt(j)-'0';
            }
        }

        ArrayList<Integer> result = new ArrayList<>();
        for(int i = 0; i<n; i++){
            for(int j = 0 ; j<n; j++){

                if(!visited[i][j] && map[i][j] != 0){
                    Queue<int[]> q= new LinkedList<>();
                    q.offer(new int[]{i,j});
                    visited[i][j] = true;
                    int cnt = 1;

                    while(!q.isEmpty()){

                        int[] cur  = q.poll();
                        int x = cur[0], y = cur[1];


                        for(int d= 0 ;d <4; d++){
                            int nx = dx[d] + x;
                            int ny = dy[d] + y;

                            if( nx < 0 || ny <0 || nx >= n || ny >= n
                                || visited[nx][ny] || map[nx][ny] == 0
                            ) continue;

                            cnt++;
                            visited[nx][ny] = true;
                            q.offer(new int[]{nx,ny});
                        }
                    }
                    result.add(cnt);
                }
            }
        }

        System.out.println(result.size());  // 추가
        result.sort(null);
        for(int it : result){
            System.out.println(it);
        }
        return ;
    }

 
}