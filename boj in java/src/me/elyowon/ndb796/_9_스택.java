package me.elyowon.ndb796;

import java.util.Stack;

public class _9_스택 {

    /**
     *
     * s.push()
     * s.pop()
     * s.peek() 최상단 값보기
     *
     * @param args
     */

    public static void main(String[] args) {
        Stack<Integer> s = new Stack<>();


        s.push(5);
        s.push(2);
        s.push(3);
        s.push(7);
        s.pop();
        s.push(1);
        s.push(4);
        s.pop();

        while(!s.empty()){
            System.out.println(s.peek());
            s.pop();
        }
    }

}