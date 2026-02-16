package elyowon.programers.prgmStudy.week_4;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;

/**
 * 규칙 1: 한 메서드에 오직 한 단계의 들여쓰기만 한다.
 * 규칙 2: else 예약어를 쓰지 않는다.
 * 규칙 3: 모든 원시값과 문자열을 포장한다.
 * 규칙 4: 한 줄에 점을 하나만 찍는다.
 * 규칙 5: 줄여쓰지 않는다(축약 금지).
 * 규칙 6: 모든 엔티티를 작게 유지한다.
 * 규칙 7: 3개 이상의 인스턴스 변수를 가진 클래스를 쓰지 않는 다.
 * 규칙 8: 일급 콜렉션을 쓴다.
 * 규칙 9: 게터/세터/프로퍼티를 쓰지 않는다.
 */

public class 구명보트 {
    public int solution(int[] people,int limit) {
        int answer = 0;

        LinkedList<Integer> list = new LinkedList<>();

        Arrays.sort(people);


        int lIdx = 0;
        int rIdx = people.length - 1;
        while (lIdx < rIdx) {
            if (people[lIdx] + people[rIdx] <= limit) {
                lIdx++;
            }
            answer++;
            rIdx--;
        }

        return answer;
    }
}