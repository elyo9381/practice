import java.io.*;
import java.util.*;

/**
 * https://www.acmicpc.net/problem/12865
 */
public class Solve12865 {

    static int n , k ;
    static int[][] dp;
    static int[] w, v;

    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        w = new int[n+1];
        v = new int[n+1];
        for(int i = 0 ; i<n; i++){
            st = new StringTokenizer(br.readLine());
            w[i] = Integer.parseInt(st.nextToken());
            v[i] = Integer.parseInt(st.nextToken());
        }

        dp = new int[n+1][100001] ; 
        for(int i = 0 ; i<=n; i++){
            Arrays.fill(dp[i],Integer.MAX_VALUE);
        }

        dp[0][0] = 0;
        for(int i = 1; i<=n; i++){
            for(int cost = 0; cost<=100000; cost++){
                dp[i][cost] = dp[i-1][cost];

                if( cost >= v[i-1] ){
                    dp[i][cost] = Math.min(dp[i][cost], dp[i-1][cost - v[i-1]] + w[i-1]);
                }
            }
        }

        int answer = 0 ;
        for(int cost = 0 ; cost<= 100000; cost++){
            if( dp[n][cost] <= k){
                answer = cost;
            }
        }
        System.out.println(answer);
    }
}