package me.elyowon.leetcode;


public class leetcode_91_dp_decodeWays {


    /**
     *
     * 문자열이 주어질때
     *
     * @param args
     */
    public static void main(String[] args) {

        String s = "212325";

        int result = decodingBtmUp(s);

        System.out.println(result);

    }

    private static int decodingBtmUp(String s) {

        int len = s.length();

        if (len == 0) return 0;

        int[] dp = new int[len + 1];
        dp[len] = 1;

        int lastChar = Integer.parseInt(String.valueOf(s.charAt(len - 1)));

        System.out.println("lastChar = " + lastChar);

        if (lastChar == 0) {
            dp[len - 1] = 0;
        } else {
            dp[len - 1] = 1;
        }


        for (int i = len - 2; i > -1; i--) {
            int singleNum = Integer.parseInt(String.valueOf(s.charAt(i)));
            int singleCount = 0;

            if (0 < singleNum) {
                singleCount = dp[i + 1];
            }

            int doubleNum = Integer.parseInt(String.valueOf(s.substring(i,i + 2)));
            int doubleCount = 0;
            if (10 <= doubleNum && doubleNum <= 26) {
                doubleCount = dp[i + 2];
            }
            int count = singleCount + doubleCount;
            System.out.println("singleCount = " + singleCount + " " + doubleCount);
            dp[i] = count;
        }
        return dp[0];
    }


}



