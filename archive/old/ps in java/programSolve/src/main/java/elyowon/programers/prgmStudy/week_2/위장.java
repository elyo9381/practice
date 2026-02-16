package elyowon.programers.prgmStudy.week_2;

import java.util.Arrays;
import java.util.Stack;


/**
 * 생각해보기 해쉬맵을 이용해서 푸는것과
 * 그냥 솔루션으로 푸는것 무엇이 더 효율적인 것인가.?
 *
 * 정답은 없으나. 본인의 눈에 익숙한 코드가 좋은코드이다. 또한
 * 다른사람눈에도 readability 가 좋은 코드가 분명있다.
 *
 */
public class 위장 {
    public int solution(String[][] clothes) {
        int ints = Arrays.stream(clothes).map(clothe -> clothe[1])
                .distinct()
                .mapToInt(strings -> (int) Arrays.stream(clothes).filter(s -> s[1].equals(strings)).count()+1)
                .reduce(1,(a,b) -> (a) * (b)) -1;

        return ints;
    }
}