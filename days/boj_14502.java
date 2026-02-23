import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;


/**
 * 
 * 우선 막고 , 확산시키고, 마지막에 카운트 
 * 
 * 바이러스 확산은 bfs
 * 어디를 막을지는 알수없음 벽은 3개 가능이랬으니 
 * 조합은 안될거같아 0이 오지게 많은데 여기서 조합 3개 ? 
 * 0을 계산해서 3개의 조합을 찾아야할거같아 이게 맞다. 
 */

public class boj_14502 {

    static int n , m ,result = 0;
    static int[] dx = {0,1,0,-1};
    static int[] dy = {1,0,-1,0};
    static ArrayList<int[]> virus ;

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        int[][] map = new int[n][m];
        virus = new ArrayList<>();
        for(int i = 0 ; i<n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0 ; j<m; j++){
                map[i][j]  = Integer.parseInt(st.nextToken());

                if(map[i][j] == 2) virus.add(new int[]{i,j});
            }
        }


        dfs(0,map);
        System.out.println(result);
        return;
    }

    private static void dfs(int idx , int[][] map ){

        if( idx == 3){
            Queue<int[]> q = new LinkedList();
            int[][] copyMap = new int[n][m];
            for(int i=0 ;i<n;i++) copyMap[i] = map[i].clone();
            for(int[] it : virus) q.add(it);

            while(!q.isEmpty()){
                int[] cur = q.poll();
                int x = cur[0], y = cur[1];

                for(int i = 0; i<4; i++){
                    int nx = dx[i]+x;
                    int ny = dy[i]+y;

                    if( nx < 0 || ny < 0 || nx >=n || ny>=m || copyMap[nx][ny]==1)continue;
                    copyMap[nx][ny] = 2;
                    q.add(new int[]{nx,ny});
                }
            }

            int zeroCnt = 0;
            for(int i=0 ;i<n;i++) {
                for(int j=0 ;j<m;j++) {
                    if(copyMap[i][j] ==0 ) zeroCnt++;
                }
            }

            result = Math.max(result,zeroCnt);
            return ;
        }

        for(int i = 0 ; i<n; i++){
            for(int j = 0 ; j<m; j++){
                if(map[i][j] == 0 ){
                    map[i][j] = 1;
                    dfs(idx+1,map);
                    map[i][j] = 0;
                }
            }
        }
    }

}