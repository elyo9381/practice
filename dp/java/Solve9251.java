import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.*;

/**
 * https://www.acmicpc.net/problem/9251
 */
public class Solve9251 {

    static String s1 , s2;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        s1 = br.readLine();
        s2 = br.readLine();

        int n = s1.length();
        int m = s2.length();
        dp = new int[n+1][m+1];

        for(int i = 1; i<=n; i++){
            for(int j = 1 ; j <=m; j++){
                if ( s1.charAt(i-1) == s2.charAt(j-1) ){
                    dp[i][j] = dp[i-1][j-1]+1;
                } else {
                    dp[i][j] = Math.max( dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        System.out.println(dp[n][m]);
    }
}
