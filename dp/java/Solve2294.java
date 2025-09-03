import java.io.*;
import java.util.*;

public class Solve2294 {


    public static void main(String[] args)throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n , k ;

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        
        int[] coins = new int[n+1];
        int[][] dp = new int[n+1][10001];


        for(int i = 1 ; i<=n; i++){
            coins[i] = Integer.parseInt(br.readLine());
        }

        int INF = Integer.MAX_VALUE;
        for(int i = 0 ; i<=n ; i++){
            Arrays.fill(dp[i],INF);
        }
        dp[0][0] = 0;
        
        for(int i = 1 ; i<=n; i++){
            for(int sum = 0 ; sum<=k; sum++){
                dp[i][sum] = dp[i-1][sum];

                if( sum >= coins[i] && dp[i][sum - coins[i]] != INF){
                    dp[i][sum] = Math.min( dp[i][sum] ,dp[i][sum - coins[i]] +1 );
                }
            }
        }
        System.out.println(dp[n][k] == INF ? -1 :dp[n][k]);
    }
}