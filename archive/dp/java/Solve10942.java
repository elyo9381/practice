import java.io.*;
import java.util.*;

/**
 * https://www.acmicpc.net/problem/10942
 */
public class Solve10942 {

    public static void main(String[] args) throws IOException {

        int n ,m ;
        boolean[][] dp;
        int[] nums;
    
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        n = Integer.parseInt(br.readLine());
        
        nums = new int[n+1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 1 ; i<=n ; i++){
            nums[i] = Integer.parseInt(st.nextToken());
        }

        dp = new boolean[n+1][n+1];

        for(int i = 1 ; i<=n ; i++){
            dp[i][i] = true;
        }

        for(int len = 2; len<=n; len++){
            for(int i = 1 ; i <= n - len + 1 ; i++){
                int j = i + len - 1;

                if (len == 2){
                    dp[i][j] = (nums[i] == nums[j]);
                } else {
                    dp[i][j] = (nums[i] == nums[j] && dp[i+1][j-1]);
                }
            }
        }

        m = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        for(int i = 0 ; i<m ; i++){
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            sb.append(dp[s][e]? 1: 0).append('\n');
        }
        System.out.print(sb);
    }
}
