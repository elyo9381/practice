package elyowon.programers.L1;


import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;

/**
 * 2021.06.23
 */
public class 레벨1_3진법뒤집기 {

    public int solution(int n) {
        int answer = 0;


        // 3진법 함수-> 리스트 저장

        ArrayList<Integer> list = new ArrayList<>();
        int tmp = n;
        while(n>0){
            list.add(n % 3);
            n = n/3;
        }

        // 리스트 리버스
        // Collections.reverse(list);
        // 3 to 10 진법
        int len = list.size();

        for (int i = 0; i < list.size(); i++) {
            answer += list.get(--len) *Math.pow(3,i);

        }

        return answer;
    }

}

