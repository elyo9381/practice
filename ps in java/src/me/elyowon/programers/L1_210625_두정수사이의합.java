package me.elyowon.programers;


import java.util.ArrayList;

/**
 *
 */
public class L1_210625_두정수사이의합 {
    public long solution(int a,int b) {
        long answer = 0;

        if (a < b) {

            for (int i = a; i <= b; i++) {
                answer += i;
            }
        } else {
            for (int i = b; i <= a; i++) {
                answer += i;
            }
        }
        return answer;
    }
}

