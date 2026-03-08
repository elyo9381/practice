import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;

public class boj_2293 {

    static int n, k;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        int[] coin = new int[n + 1];
        int[] dp = new int[k + 1];

        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            coin[i] = Integer.parseInt(br.readLine());
        }

        for (int i = 0; i < n; i++) {
            int c = coin[i];
            for (int sum = c; sum <= k; sum++) {
                dp[sum] += dp[sum - c];
            }
        }

        System.out.println(dp[k]);
        return;
    }
}