import java.io.*;
import java.util.*;


public class Solve2293 {

    public static void main(String[] args) throws IOException{
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n , k ;
        
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        int[][] dp = new int[n+1][k+1];
        int[] coins = new int[n+1];

        for(int i = 1 ; i<=n; i++){
            coins[i] = Integer.parseInt(br.readLine());
        }

        dp[0][0] = 1;

        for(int i = 1; i<=n; i++){
            for(int sum = 1; sum <= k; sum++){
                dp[i][sum] = dp[i-1][sum];

                if( sum >= coins[i] ) {
                    dp[i][sum] = dp[i-1][sum] + dp[i][sum-coins[i]];
                }
            }
        }

        System.out.println(dp[n][k]);
    }
}