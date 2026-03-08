import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;

public class boj_1450 {

    static int n, c;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken()); 
        c = Integer.parseInt(st.nextToken()); 
        
        int[] targets = new int[n];

        st = new StringTokenizer(br.readLine());
        for(int i = 0 ; i<n ;i++){
            targets[i] = Integer.parseInt(st.nextToken()); 
        }

        long[] dp = new long[c+1];
        dp[0] = 1;

        for(int t = 0 ; t < n ; t++){
            int target = targets[t];
            for(int sum = c ; sum>=target ; sum--){
                dp[sum] += dp[sum-target];
            }
        }
        long answer = 0;
        for (int i = 0; i <= c; i++) {
            answer += dp[i];
        }

        System.out.println(answer);
    }
}


