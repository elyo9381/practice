package me.elyowon.programers.L2;


import java.util.*;
import java.util.stream.Stream;

/**
 * 그리디문제인것은 인지하였으나 구현을 못하였다.
 * 가장작은값을 카운트솔트로 체크후 그것을 제거하려고 구현하려 하였으나 실패
 * 스택을 이용아면 효율적이다.
 */
public class L2_210706_큰수만들기 {

    public String solution(String number, int k){
        char[] result = new char[number.length() - k];
        Stack<Character> stack = new Stack<>();

        for(int i = 0; i<number.length(); i++){
            char c = number.charAt(i);
            while( ! stack.isEmpty() && stack.peek() < c && k-- > 0){
                stack.pop();
            }

            stack.push(c);
        }

        stack.stream().toString();
        String answer = "";
        for(Character c : stack){
            answer += c;
        }

        return answer;
    }
}
