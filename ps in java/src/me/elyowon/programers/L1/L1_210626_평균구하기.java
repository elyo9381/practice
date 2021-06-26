package me.elyowon.programers.L1;


import java.util.Arrays;

/**
 */
public class L1_210626_평균구하기 {
    public double solution(int[] arr) {
        return Arrays.stream(arr).average().getAsDouble();
    }
}

