package me.elyowon.leetcode.dp;


import me.elyowon.leetcode.Pos;

import java.util.Arrays;

import static java.lang.Math.max;
import static java.lang.Math.min;

public class leetcode_5_LogestPalindromicSubstring {


    /**
     * 647 비슷한 문제
     *
     * palindrom을 dp 로 푼 문제
     * 문제 각 문자가 하나일때는 2개일때 팰린드롬을 계산하고
     * 이를 바탕으로 이전 팰린드롬 확인후 좌우 글자가 같은지 확인한다.
     *
     * 배열의 인덱스 이동을 잘보자..!
     *
     * @param args
     */
    public static void main(String[] args) {

        String s = "baaac";

        String result = dpPalindrom(s);

        System.out.println(result);

    }

    private static String dpPalindrom(String s) {

        String ret = "";
        char[] chr = s.toCharArray();
        int l =chr.length;
        int[][] dp = new int[chr.length][chr.length];

        if (s.length() == 1) {
            return s;
        }

        for (int i = 0; i < l; i++) {
            dp[i][i] = 1;
        }

        for (int i = 0; i < l - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                dp[i][i + 1] = 2;
            }
        }

        for(int j = 2; j < l; j++){
            for (int i = 0; i + j < l; i++) {
                if (dp[i + 1][i + j - 1] != 0 && s.charAt(i) == s.charAt(i + j))
                    dp[i][i + j] = dp[i+1][i+j-1] +2;
            }
        }

//        for (int j = 2; j < l; j++) {
//            int row = 0;
//            int col = j ;
//            while( col < s.length()){
//                int start = s.charAt(row);
//                int end = s.charAt(col);
//                int prevCount = dp[row+1][col-1];
//                if(start == end && prevCount !=0){
//                    dp[row][col] = prevCount +2;
//                }
//                row +=1;
//                col +=1;
//            }
//        }

        System.out.println();

        for (int[] ints : dp) {
            for (int anInt : ints) {
                System.out.print(" " + anInt);
            }
            System.out.println();
        }

        int maxLen = 0;
        int maxI = 0;
        int maxJ = 0;

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                if (maxLen < dp[i][j]) {
                    maxLen = dp[i][j];
                    maxI = i;
                    maxJ = j;
                }
            }
        }

        String result = "";
        for (int i = maxI; i <= maxJ; i++) {
            result += s.charAt(i);
        }

        return result;




    }


}



