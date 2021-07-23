package me.elyowon.leetcode.dp;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;

public class leetcode_139_wordBreak {



    /**
     *
     * 단어를 쪼갤수있는지 확인하는 문제
     * 이 문제의 핵심은 dp와 해시셋이다.
     * 리스트로 주어진 문자들을 헤시샛에 넣고 substring을 해시셋에 있는지 비교한다면 확인할수있다.
     *
     *
     *
     * @param args
     */
    public static void main(String[] args) {

        String s = "nocope";
        String[] wordDict = {"e","no","cop"};
        List<String> wordDicts = Arrays.asList(wordDict);

        boolean result = wordBreak(s,wordDicts);


        System.out.println(result);

    }

    private static boolean wordBreak(String s,List<String> wordDicts) {

        if(s == null || s.length() == 0){
            return false;
        }

        HashSet<String> hs = new HashSet<>();

        for (String wordDict : wordDicts) {
            hs.add(wordDict);
        }
        boolean[] dp = new boolean[s.length()+1];
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++) {
            for (int j = i-1; j >=0; j--) {
                if(dp[j] && hs.contains(s.substring(j,i))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];

    }

}



