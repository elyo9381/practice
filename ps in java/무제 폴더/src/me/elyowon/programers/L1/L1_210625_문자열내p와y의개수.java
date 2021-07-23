package me.elyowon.programers.L1;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

/**
 * 문자열의 문자 하나를 비교하고 같으면 문자열 자체를 비교하는 방법으로 풀었다.
 *
 * 생각의 전환을 해보면 해당 문자를 앞으로 빼서 sort하면 해당 문자 정렬 + 사전순이 진행되고
 * 추후에 substring으로 해당문자를 제거하면 손쉽게 간능하다.
 *
 */
public class L1_210625_문자열내p와y의개수 {
    boolean solution(String s) {
        boolean answer = true;

        s = s.toLowerCase();
        int pCnt = 0;
        int yCnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == 'p') pCnt++;
            else if (s.charAt(i) == 'y') yCnt++;
        }

        if( pCnt == yCnt) return true;
        else return false;
    }

    boolean solution1(String s) {
        s = s.toUpperCase();

        // 문자열 스트림 하는 방법
        return s.chars().filter( e -> 'P'== e).count() == s.chars().filter( e -> 'Y'== e).count();
    }
}

