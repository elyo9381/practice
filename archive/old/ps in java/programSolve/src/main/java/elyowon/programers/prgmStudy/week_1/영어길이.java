package elyowon.programers.prgmStudy.week_1;


import java.util.*;

/**
 * 요구사항 학생을 추가할수있음 ( 찍기 배열도 마찬가지)
 */
public class 영어길이 {

    public class Solution {
        public int[] solution(int n, String[] words) {

            int[] answer = new int[2];

            HashSet<String> hs = new HashSet<String>();

            hs.add(words[0]);
            for(int i = 1; i <words.length; i++){

                char lastChar = words[i-1].charAt(words[i-1].length()-1);
                char firstChar = words[i].charAt(0);

                if(lastChar != firstChar || hs.contains(words[i])){
                    answer[0]= i % n +1;
                    answer[1]= i / n +1;
                    break;
                }
                hs.add(words[i]);
            }

            return answer;
        }
    }
}