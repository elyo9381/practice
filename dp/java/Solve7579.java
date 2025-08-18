package practice.dp.java;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solve7579 {


    static int n , M;
    static int[] m, c;
    static int[][] dp;

    public static void main(String[] args) throws IOException{ 

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        n = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        m = new int[n+1];
        c = new int[n+1];

        dp = new int[n+1][10001];

        st = new StringTokenizer(br.readLine());
        for(int i = 1; i<=n;i++){
            m[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for(int i = 1; i<=n;i++){
            c[i] = Integer.parseInt(st.nextToken());
        }


        for(int i = 1; i<=n ; i++){
            for(int cost = 0 ; cost <= 10000; cost++){
                dp[i][cost] = dp[i-1][cost]; // 선택하지 않으면 이전 선택의 값을 가져오는거야 

                if( cost >= c[i] ){
                    dp[i][cost] = Math.max(dp[i][cost] , dp[i-1][cost-c[i]]+m[i] );
                }
            }
        }


        int answer = Integer.MAX_VALUE;
        for(int cost = 0 ; cost<=10000; cost++){
            if(dp[n][cost] >= M) {
                answer = Math.min(answer, cost);
            }
        }
        System.out.println(answer);
    }
}