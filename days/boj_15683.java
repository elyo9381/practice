import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;

public class boj_15683 {

    static int n,m , min = Integer.MAX_VALUE;
    static int[] dx = {0,1,0,-1};
    static int[] dy = {1,0,-1,0};

    static int[][][] dir = {
        {},
        {{0},{1},{2},{3}},
        {{0,2},{1,3}},
        {{0,1},{3,0},{1,2},{2,3}},
        {{0,1,2},{1,2,3},{2,3,0},{3,0,1}},
        {{0,1,2,3}},
    };

    static ArrayList<int[]> cctvList = new ArrayList<>();

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        int[][] map = new int[n][m];

        for(int i = 0 ; i<n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0 ; j<m;j++){
                map[i][j] = Integer.parseInt(st.nextToken());

                if( map[i][j] >= 1 && map[i][j] <=5){
                    cctvList.add(new int[]{i,j,map[i][j]});
                }
            }
        }

        dfs(0,map);
        System.out.println(min);
        return ;
    }

    private static void dfs(int idx , int[][] map){
        if(idx == cctvList.size()){
            int cnt = 0;
            for(int i = 0 ; i<n;i++){
                for(int j = 0 ; j<m;j++){
                    if(map[i][j] == 0) cnt++;
                }
            }
            min = Math.min(min,cnt);
            return;
        }

        int[] cctv = cctvList.get(idx);
        int x = cctv[0], y = cctv[1], type = cctv[2];

        for(int[] dirList: dir[type]){
            int[][] copyMap = new int[n][m];
            for(int i = 0 ; i<n ;i++) copyMap[i] = map[i].clone();

            for(int d : dirList ){
                watchMap(x,y,d,copyMap);
            }
            dfs(idx+1,copyMap);
        }
        return;
    }


    private static void  watchMap(int x, int y , int d, int[][] copyMap){
        int nx = x + dx[d];
        int ny= y + dy[d];
        while( nx >= 0 && ny >= 0 && nx < n && ny <m && copyMap[nx][ny] != 6){
            if(copyMap[nx][ny] == 0 ) copyMap[nx][ny] =-1;
            nx += dx[d];
            ny += dy[d];
        }
        return ;
    }
}