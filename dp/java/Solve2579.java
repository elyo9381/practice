import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.*;

/**
 * https://www.acmicpc.net/problem/2579
 */

public class Solve2579 {

    static int N ;
    static int[][] dp;
    static int[] stair;

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N  = Integer.parseInt(st.nextToken());

        stair = new int[N+1];
        dp = new int[N+1][2];

        for(int i = 1 ; i<=N ; i++){
            stair[i]  = Integer.parseInt(br.readLine());
        }
    
        dp[1][0] = stair[1];
        dp[1][1] = 0;

        for(int i = 2 ; i <=N ; i++){
            dp[i][0] = Math.max( dp[i-2][0] , dp[i-2][1] ) + stair[i];
            dp[i][1] = dp[i-1][0] + stair[i];
        }

        System.out.println(Math.max(dp[N][0], dp[N][1]));
    }
}