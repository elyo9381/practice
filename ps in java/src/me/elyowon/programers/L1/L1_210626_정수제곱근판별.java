package me.elyowon.programers.L1;


import java.util.Arrays;

/**
 * Long.parseLong 을통해서 문자열을 숫자화 할수있다.
 */
public class L1_210626_정수제곱근판별 {
    public long solution(long n) {
        Double sqrt = Math.sqrt(n);

        if(sqrt == sqrt.intValue()){
            return (long) Math.pow(sqrt+1,2);
        } return -1;
    }
}

