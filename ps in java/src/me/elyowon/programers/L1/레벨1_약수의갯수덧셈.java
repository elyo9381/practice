package me.elyowon.programers.L1;


import java.util.Stack;

/**
 * 2021.06.22
 */
public class 레벨1_약수의갯수덧셈 {


    public int solution(int left,int right) {
        int answer = 0;


        for (int i = left; i <= right; i++) {
            int num = findDivisorNum(i);

            if (num % 2 == 0) {
                answer += i;
            } else {
                answer -= i;
            }
        }

        return answer;
    }

    private int findDivisorNum(int num) {

        int result = 0;


        for (int i = 1; i <= num; i++) {
            if (num % i == 0) {
                result++;
            }
        }

        return result;
    }


}
