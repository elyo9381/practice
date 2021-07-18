package me.elyowon.programers.prgmStudy.week_1;


import java.util.*;

/**
 * 요구사항 학생을 추가할수있음 ( 찍기 배열도 마찬가지)
 */
public class 영어길이 {

    public class Solution {
        public int[] solution(int n, String[] words) {


            HashSet<String> hs = new HashSet<String>();

            int failWordsIdx = 0;
            hs.add(words[0]);
            for(int i = 1; i < words.length; i++){

                if(hs.contains(words[i])) break;
                hs.add(words[i]);

                char lastChar = words[i-1].charAt(words[i-1].length()-1);
                char firstChar = words[i].charAt(0);
                if(lastChar != firstChar) break;


            }
            if(failWordsIdx == words.length) return new int[]{0,0};

            return new int[]{(failWordsIdx)%n + 1,(failWordsIdx)/n + 1};
        }
    }
}