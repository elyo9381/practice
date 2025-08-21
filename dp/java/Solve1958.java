import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.*;

/**
 * https://www.acmicpc.net/problem/1958
 */
public class Solve1958 {

    static String s1, s2, s3 ;
    static int[][][] dp;
    
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        s1 = br.readLine();
        s2 = br.readLine();
        s3 = br.readLine();


        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();

        dp = new int[n1+1][n2+1][n3+1];

        for(int i = 1; i <=n1; i++){
            for(int j = 1; j <=n2; j++){
                for(int k = 1; k <=n3; k++){
                    // 이런 방법도 존재한다 하지만 이건 효율적이지 못하다 6개를 계속 계산해야하니 말이다. 
                    // dp[i][j][k] = Arrays.stream(
                    //     new int[]{ dp[i-1][j-1][k], dp[i][j][k-1], dp[i][j-1][k-1],
                    //         dp[i-1][j][k], dp[i-1][j][k-1], dp[i][j-1][k] }).max().getAsInt();
                    
                    if( s1.charAt(i-1) == s2.charAt(j-1) && s2.charAt(j-1) == s3.charAt(k-1)){
                        dp[i][j][k] = dp[i-1][j-1][k-1]+1;
                    } 
                    
                    else if( s1.charAt(i-1) == s2.charAt(j-1) ){
                        dp[i][j][k] = Math.max(dp[i-1][j-1][k],dp[i][j][k-1]);
                    } else if(s2.charAt(j-1) == s3.charAt(k-1)){
                        dp[i][j][k] = Math.max(dp[i][j-1][k-1],dp[i-1][j][k]);
                    } else if (s1.charAt(i-1) == s3.charAt(k-1)){
                        dp[i][j][k] = Math.max(dp[i-1][j][k-1],dp[i][j-1][k]);
                    } else {
                        dp[i][j][k] = Math.max(dp[i-1][j][k],Math.max(dp[i][j][k-1],dp[i][j-1][k]));
                    }
                }
            }
        }
        System.out.println(dp[n1][n2][n3]);
    }
}