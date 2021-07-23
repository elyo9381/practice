package elyowon.leetcode.dp;


import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

public class leetcode_knapsack {


    /**
     * 냅색
     * pb, sb를 구하자
     * <p>
     * 4 7
     * 6 13
     * 4 8
     * 3 6
     * 5 12
     *
     * @param args
     */
    public static void main(String[] args) {

        int[] w = {1,2,3,4};
        int[] v = {30,20,40,10};

        int result = knapsack(v,w,5);

        System.out.println("result = " + result);
    }

    private static int knapsack(int[] v,int[] w,int limit) {
        int n = v.length;

        int[][] dp = new int[n + 1][limit + 1];

        for (int rowIdx = 0; rowIdx < n + 1; rowIdx++) {
            dp[rowIdx][0] = 0;
        }
        for (int colIdx = 0; colIdx < limit + 1; colIdx++) {
            dp[0][colIdx] = 0;
        }

        int max = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= limit; j++) {
                if (w[i - 1] <= j) {
                    dp[i][j] = Math.max(v[i - 1] + dp[i - 1][j - w[i - 1]],dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
                max = Math.max(dp[i][j],max);
            }
        }


        return max;
    }

}



