import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.*;

/**
 * https://www.acmicpc.net/problem/1463
 */

public class Solve1436 {

    static int N ;
    static int[] dp;

    public void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        dp = new int[N+1];
        dp[1] = 0;
        for(int i = 2 ; i<=N ; i++){
            dp[i] = Math.min(dp[i], dp[i-1]+1);

            if( i % 2 == 0) dp[i] = Math.min(dp[i], dp[i/2]+1);
            if( i % 3 == 0) dp[i] = Math.min(dp[i], dp[i/3]+1);
        }
        
        System.out.println(dp[N]);
    }
}