package me.elyowon.programers.L1;


import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

/**
 * 문자열의 문자 하나를 비교하고 같으면 문자열 자체를 비교하는 방법으로 풀었다.
 *
 * 생각의 전환을 해보면 해당 문자를 앞으로 빼서 sort하면 해당 문자 정렬 + 사전순이 진행되고
 * 추후에 substring으로 해당문자를 제거하면 손쉽게 간능하다.
 *
 */
public class L1_210625_문자열내마음대로정렬하기 {
    public String[] solution(String[] strings,int n) {

        ArrayList<String> str = new ArrayList<>();

        for (String string : strings) {
            str.add(string);
        }


        Collections.sort(str,(a,b) -> {

            Character c1 = a.charAt(n);
            Character c2 = b.charAt(n);

            if (c1 == c2) {
                return a.compareTo(b);
            } else return c1 - c2;

        });

        String[] answer = new String[str.size()];

        for (int i = 0; i < str.size(); i++) {
            answer[i] = str.get(i);
        }

        return answer;
    }
}

