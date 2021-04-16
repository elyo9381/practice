package me.elyowon.programers;

import java.util.*;
import java.util.Stack;

/**
 *
 *  s	result
 * "[](){}"	3
 * "}]()[{"	2
 * "[)(]"	0
 * "}}}"	0
 *
 * 1. 올바른괄호인지 확인
 * 2. 하나의 요소 왼쪽으로 옮기기(제거)
 * 3. 문자열의 맨뒤에 추가
 * 4. 1,2,3 반복
 *
 */

public class 괄호회전하기 {

    boolean check(String s) {

        Stack<Character> stack = new Stack<Character>();
        boolean f = true;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else if (!stack.isEmpty()) {
                if (stack.peek() == '(' && c == ')') {
                    stack.pop();
                } else if (stack.peek() == '[' && c == ']') {
                    stack.pop();
                } else if (stack.peek() == '{' && c == '}') {
                    stack.pop();
                }

            } else {
                return false;
            }
        }

        if (!stack.isEmpty()) {
            return false;
        }


        return true;

    }


    public int solution(String s) {
        int answer = -1;
        int cnt = 0;

        for (int i = 0; i < s.length(); i++) {
            if (check(s)) {
                cnt++;
            }
            // System.out.println(s);
            s = s.substring(1,s.length()) + s.charAt(0);

        }
        return cnt;
    }
}
