import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class coin {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[] coins = new int[n];
        int[] dp = new int[k+1];

        st = new StringTokenizer(br.readLine());
        for(int i = 0 ; i<n; i++){
            coins[i] = Integer.parseInt(st.nextToken());
        }

        int INF = 987654321;
        Arrays.fill(dp, INF);
        dp[0] = 0 ;

        for(int i = 0; i<n; i++){
            int c = coins[i];
            for(int j = c; j<=k ; j++){
                dp[j] = Math.min(dp[j] , dp[j - c ]+1);
            }
        }

        System.out.println(dp[k] ==  INF ? -1 : dp[k]);
    }
}
