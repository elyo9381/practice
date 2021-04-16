package me.elyowon.programers;

import java.util.ArrayList;
import java.util.HashMap;

/**
 *
 * answers	return
 * [1,2,3,4,5]	[1]
 * [1,3,2,4,2]	[1,2,3]
 *
 *
 * 1. participant을 배열 or 맵에 넣기
 * 2. completion을 배열or 맵에서 확인하고 값변경
 * 3. 혼자남거나 갑이 다른 하나를 반환
 *
 */

public class 모의고사_1 {

    /**
     *
     * 1번은 1~5 2번반복
     * 2번은 21232425 반복
     * 3번은 3311224455 반복
     */

    public int[] solution(int[] answers) {
        int[] answer = new int[3];

        int[] person1 = {1,2,3,4,5};
        int[] person2 = {2,1,2,3,2,4,2,5};
        int[] person3 = {3,3,1,1,2,2,4,4,5,5};
        int answer1 = 0, answer2 = 0, answer3= 0 ;

        for(int i=0; i<answers.length; i++){
            if(answers[i] == person1[i%5]) answer1++;
            if(answers[i] == person2[i%8]) answer2++;
            if(answers[i] == person3[i%10]) answer3++;
        }

        int max = Math.max(Math.max(answer1,answer2),answer3);

        ArrayList<Integer> list = new ArrayList<Integer>();
        if ( max == answer1) list.add(1);
        if ( max == answer2) list.add(2);
        if ( max == answer3) list.add(3);

        answer = new int[list.size()];
        for( int i=0; i<list.size(); i++){
            answer[i] = list.get(i);
        }

        return answer;
    }
}
