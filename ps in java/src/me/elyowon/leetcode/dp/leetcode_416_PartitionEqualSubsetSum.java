package me.elyowon.leetcode.dp;


import java.util.Scanner;

public class leetcode_416_PartitionEqualSubsetSum {



    /**
     *
     * pb, sb 나누기
     *
     *
     * @param args
     */
    public static void main(String[] args) {
        int[] nums  = {2,1,2,3,4};

        boolean result =  PartitionEqualSubsetSum(nums);

        System.out.println(result);

    }

    private static boolean PartitionEqualSubsetSum(int[] nums) {






        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        int l = nums.length;
        int colLen = sum/2;

        boolean[][] dp = new boolean[l+1][colLen+1];

        for (int rowIdx = 0; rowIdx < l + 1; rowIdx++) {
            dp[rowIdx][0] = true;
        }
        for (int colIdx = 1; colIdx < colLen + 1; colIdx++) {
            dp[0][colIdx] = false;
        }

        for (int i = 1; i <= l; i++) {
            for (int j = 1; j <= sum/2; j++) {
                dp[i][j] = (dp[i-1][j] || (j - nums[i-1] >=0 && dp[i-1][j - nums[i-1]]));
            }
        }



        return false;
    }
}



