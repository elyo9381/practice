package elyowon.leetcode.dp;


import java.util.Scanner;

public class leetcode_416_PartitionEqualSubsetSum {



    /**
     *
     * pb, sb 나누기
     *
     * 양의정수에 두집합을 같은 합으로나누는 문제이다.
     * 어레이때문에 배열문제라고 생각 할 수 있겠으나
     * 두 집합으로 나누려면 2,1,3 / 2,4 하나가 올수있는지 없는지 냅색으로 풀어야한다.
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



