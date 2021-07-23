package me.elyowon.programers.L1;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.stream.Stream;

/**
 * Long.parseLong 을통해서 문자열을 숫자화 할수있다.
 */
public class L1_210626_정수내림차순으로배치하기 {
    public long solution(long n) {
        String num = String.valueOf(n);
        String ansnum = "";
        char[] arr = num.toCharArray();
        Arrays.sort(arr);

        StringBuilder sb = new StringBuilder(new String(arr));
        Long.parseLong(sb.reverse().toString());

//        for (int i = arr.length - 1; i >= 0; i--) {
//            ansnum += arr[i];
//        }
//        long answer = Long.parseLong(ansnum);

        return Long.parseLong(sb.reverse().toString());
    }
}

