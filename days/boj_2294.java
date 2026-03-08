import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;

public class boj_2294 {

    static int n,k;


    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());


        int[] coin = new int[n];
        int[] dp = new int[k+1];
        int[] prev = new int[k+1];

        int INF = 987654321;
        Arrays.fill(dp , INF);
        Arrays.fill(prev,-1);
        dp[0] = 0; 

        for(int i = 0 ; i<n; i++){
            coin[i] = Integer.parseInt(br.readLine());
        }

        for(int i = 0 ; i < n ;i++){
            int c = coin[i];
            for(int sum = c ; sum <= k ; sum++){
                if(dp[sum - c] != INF && dp[sum] > dp[sum-c] + 1){
                    dp[sum] = dp[sum - c]+1;
                    prev[sum] = c;
                }
            }
        }

        System.out.println( (dp[k] == INF) ? -1: dp[k]);


        for(int cur = k ; cur > 0 && prev[cur] != -1 ; cur -= prev[cur]){
            System.out.println(prev[cur] + " ");
        }

        return ;
    }
}