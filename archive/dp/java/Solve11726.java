
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * https://www.acmicpc.net/problem/11726
 */
public class Solve11726 {

    static int n;
    static int[] dp;
    static final int BIGNUM = 10007;

    public static void main(String[] args) throws IOException{ 

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        dp = new int[n+1];

        if( n == 1){ 
            System.out.println(1);
            return ;
        }
        if( n == 2 ){ 
            System.out.println(2);
            return ;
        }
        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3 ; i <=n ; i++){
            dp[i] = (dp[i-1] + dp[i-2] ) % BIGNUM;
        }
        
        System.out.println(dp[n]);
    }
}