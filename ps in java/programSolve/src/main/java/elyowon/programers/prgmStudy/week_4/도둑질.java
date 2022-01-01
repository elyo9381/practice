package elyowon.programers.prgmStudy.week_4;

import java.util.Arrays;
import java.util.OptionalInt;

public class 도둑질 {
    public int solution(int[] money) {
        int n = money.length;
        int[][] dp = new int[n][2];


        dp[0][0] = money[0];
        dp[1][0] = money[1];
        dp[2][0] = dp[0][0] + money[2];

        dp[0][1] = 0;
        dp[1][1] = money[1];
        dp[2][1] = money[2];

        int max = Integer.MIN_VALUE;
        for (int i = 3; i < n; i++) {

            dp[i][1] = money[i] + Math.max(dp[i - 1][1],dp[i - 2][1]);
            max = Math.max(max,Math.max(dp[i][0],dp[i][1]));
            if(i == n-1) break;
            dp[i][0] = money[i] + Math.max(dp[i - 1][0],dp[i - 2][0]);
            max = Math.max(max,Math.max(dp[i][0],dp[i][1]));
        }

        return max;
    }
}