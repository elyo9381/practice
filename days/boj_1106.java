import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;

public class boj_1106 {

    static int n, c;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        c = Integer.parseInt(st.nextToken()); // 목표 고객 수 C
        n = Integer.parseInt(st.nextToken()); // 광고 종류 N

        int[] people = new int[n];
        int[] cost = new int[n];
        int maxPeople = 0;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            cost[i] = Integer.parseInt(st.nextToken());
            people[i] = Integer.parseInt(st.nextToken());
            maxPeople = Math.max(maxPeople, people[i]);
        }

        // 마지막 한 번의 광고로 최대 maxPeople만큼만 더할 수 있으므로
        // 답은 [c, c + maxPeople - 1] 구간 안에서 항상 존재
        int LIMIT = c + maxPeople;
        int INF = 987654321;
        int[] dp = new int[LIMIT + 1];
        Arrays.fill(dp, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int p = people[i];
            int cnt = cost[i];
            for (int sum = p; sum <= LIMIT; sum++) {
                if (dp[sum - p] != INF) {
                    dp[sum] = Math.min(dp[sum], dp[sum - p] + cnt);
                }
            }
        }

        int answer = INF;
        for (int i = c; i <= LIMIT; i++) {
            answer = Math.min(answer, dp[i]);
        }

        System.out.println(answer == INF ? -1 : answer);
    }
}


