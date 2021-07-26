package elyowon.leetcode.dp;


public class leetcode_518_coinChange2 {


    /**
     * pb sb
     *
     * dp[1,2,3],5
     *
     * dp [1,2],5     dp[1,2,3],2
     *
     * @param args
     */
    public static void main(String[] args) {

        int[] nums = {1,2,5};
        int amount = 5;

        int result = coinChange2(nums,amount);
        System.out.println("result = " + result);
    }

    private static int coinChange2(int[] nums,int amount) {

        int l = nums.length;

        int[][] dp = new int[l+1][amount+1];

        for (int i = 0; i <l+1; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <amount+1; i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <=l; i++) {
            for (int j = 1; j <=amount; j++) {
                if( j-nums[i-1] >= 0){
                    dp[i][j] = dp[i-1][j] + dp[i][j-nums[i-1]];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }


        return dp[l][amount];
    }

}



