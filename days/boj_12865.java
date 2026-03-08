import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;

public class boj_12865 {

    static int n,k;

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        int[] values = new int[n];
        int[] weights = new int[n];
        int[] dp = new int[k+1];

        for(int i = 0 ; i<n; i++){
            st = new StringTokenizer(br.readLine());

            weights[i] = Integer.parseInt(st.nextToken());
            values[i] = Integer.parseInt(st.nextToken());
        }

        for(int i = 0 ; i<n;i++){
            int w = weights[i];
            int v = values[i];

            for(int cur = k; cur >= w; cur--){
                dp[cur] = Math.max(dp[cur], dp[cur - w] + v);
            }
        }

        System.out.println(dp[k]);
    }
}
