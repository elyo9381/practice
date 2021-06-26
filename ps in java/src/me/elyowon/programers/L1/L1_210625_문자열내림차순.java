package me.elyowon.programers.L1;


import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 * 문자열의 문자 하나를 비교하고 같으면 문자열 자체를 비교하는 방법으로 풀었다.
 *
 * 생각의 전환을 해보면 해당 문자를 앞으로 빼서 sort하면 해당 문자 정렬 + 사전순이 진행되고
 * 추후에 substring으로 해당문자를 제거하면 손쉽게 간능하다.
 *
 */
public class L1_210625_문자열내림차순 {
    public String solution(String s) {
        String answer = "";

        char[] chars = s.toCharArray();
        Arrays.sort(chars);
        return new StringBuilder(new String(chars)).reverse().toString();
    }

    public String reverseStr(String str){
        return Stream.of(str.split(""))// "" 단위로 쪼갠다.
                .sorted(Comparator.reverseOrder()) // 쪼갠 문자열을 정렬한다.
                .collect(Collectors.joining());  // 쪼갠 문자열을 다시 붙인다.
    }

}

