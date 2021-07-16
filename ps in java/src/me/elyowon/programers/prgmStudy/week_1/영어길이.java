package me.elyowon.programers.prgmStudy.week_1;


import java.util.*;

/**
 * 요구사항 학생을 추가할수있음 ( 찍기 배열도 마찬가지)
 */
public class 영어길이 {

    public class Solution {
        public int[] solution(int n, String[] words) {


            HashSet<String> hs = new HashSet<String>();

            int wordIdx2 = 1;
            for(int wordIdx1 = 0; wordIdx1 < words.length-1; wordIdx1++, wordIdx2++){

                hs.add(words[wordIdx1]);

                char FirstStr_LastChar = words[wordIdx1].charAt(words[wordIdx1].length()-1);
                char SecondStr_FirstChar = words[wordIdx2].charAt(0);

                if(hs.contains(words[wordIdx2])) break;
                if(SecondStr_FirstChar != FirstStr_LastChar) break;

            }
            if(wordIdx2 == words.length) return new int[]{0,0};

            return new int[]{(wordIdx2)%n + 1,(wordIdx2)/n + 1};
        }
    }
}