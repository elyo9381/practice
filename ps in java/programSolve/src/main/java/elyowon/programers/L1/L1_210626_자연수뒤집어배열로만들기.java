package elyowon.programers.L1;


import java.util.ArrayList;
import java.util.Collections;

/**
 * String s = new StringBuilder(String.valueOf(n)).reverse().toString();
 * return s.chars().map(Character::getNumericValue).toArray();
 */
public class L1_210626_자연수뒤집어배열로만들기 {
    public int[] solution(long n) {
        String s = new String(String.valueOf(n));
        StringBuilder sb = new StringBuilder(s);
        String[] split = sb.reverse().toString().split("");


        int[] answer = new int[split.length];
        for (int i = 0; i < split.length; i++) {
            answer[i] = Integer.parseInt(split[i]);
        }

        return answer;
    }
}

