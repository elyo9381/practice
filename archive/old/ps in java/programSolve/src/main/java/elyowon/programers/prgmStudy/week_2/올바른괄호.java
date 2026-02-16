package elyowon.programers.prgmStudy.week_2;

import java.util.Stack;

public class 올바른괄호 {
    boolean solution(String s) {
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            if (stack.isEmpty()) {
                stack.add(c);
                continue;
            }
            if (c == '(') {
                stack.add(c);
            } else {
                stack.pop();
            }
        }
        return stack.isEmpty() ? true : false;
    }
}