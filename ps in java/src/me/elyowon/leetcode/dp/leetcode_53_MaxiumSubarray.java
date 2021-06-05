package me.elyowon.leetcode.dp;


import static java.lang.Math.abs;

public class leetcode_53_MaxiumSubarray {


    /**
     *
     * 하나의 어레이에서 최대값을 갖는 서브어레이를 찾아라
     *
     * 이를 최적화 문제로 보아라
     * 그리고 최적화 문제를 가장 작게 나누는것이 가능한가 보자
     *
     * 매번 인덱스가 들어올때 MaxSubarray을 계산한다. 또한 전단계의 최적화를 알고있다.
     *
     * f(n) = max(input(n), input(n) + f(n-1));
     * sp는 더한값과 현재값의 계산하여 맥스값을 구하면 현재 최대 값을 알수있고 이를 통해서
     * max서브어레이를 구할수있다.
     *
     * @param args
     */
    public static void main(String[] args) {

//        int[] nums = {5,-2,9,-15,8};
        int[] nums = {-2,1,-3,4,-1,2,1,-5,4};

        int[] dp = new int[nums.length+1];

        int[] result = calMaxSubarray(nums,dp);

        for (int i : result) {
            System.out.println("i = " + i);
        }

    }

    private static int[] calMaxSubarray(int[] nums,int[] dp) {
        int[] startIdx = new int[dp.length];
        int answer = (int) -1e9;

        startIdx[0] = 0;
        dp[0] = nums[0];


        for (int i = 1; i < nums.length; i++) {
            dp[i] = Math.max(nums[i], nums[i] + dp[i-1]);
            answer = Math.max(dp[i],answer);
            if(nums[i] > nums[i] + dp[i-1]){
                startIdx[i] = i;
                continue;
            }
            startIdx[i] = startIdx[i-1];
        }

        int s = 0;
        for (int i = 0; i <dp.length; i++) {
            if (dp[i] == answer) {
                s = i;
            }
        }

        int[] ans = new int[(abs(s - startIdx[s])+1)];

        for (int i = startIdx[s],index = 0; i <=s; i++,index++) {
            ans[index] = nums[i];
        }

        return ans;

    }

}



