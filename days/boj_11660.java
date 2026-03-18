import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;

public class boj_11660 {
    static int n , m ;


    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        
        int[][] map = new int[n+1][n+1];
        int[][] dp = new int[n+1][n+1];

        
        for(int i = 0 ;  i<n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0 ; j<n; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }            
        }

        dp[0][0] = map[0][0];
        for(int i = 1 ; i<n ; i++){
            dp[i][0] = dp[i-1][0] + map[i][0];
            dp[0][i] = dp[0][i-1] + map[0][i];
        }


        for(int i = 1; i<n; i++){
            for(int j = 1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + map[i][j];
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int i = 0 ;  i<m;i++){
            st = new StringTokenizer(br.readLine());
            int sx = Integer.parseInt(st.nextToken())-1;
            int sy = Integer.parseInt(st.nextToken())-1;
            int fx = Integer.parseInt(st.nextToken())-1;
            int fy = Integer.parseInt(st.nextToken())-1;

            int ans = dp[fx][fy]
                      - (sx > 0 ? dp[sx - 1][fy] : 0)
                      - (sy > 0 ? dp[fx][sy - 1] : 0)
                      + (sx > 0 && sy > 0 ? dp[sx - 1][sy - 1] : 0);

            sb.append(ans).append('\n');
        }   
        System.out.print(sb);
        return ;
    }
}