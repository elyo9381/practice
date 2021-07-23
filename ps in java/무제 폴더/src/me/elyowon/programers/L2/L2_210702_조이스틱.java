package me.elyowon.programers.L2;


import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

/**
 * 그리디 ( 중복해서 지나는 - 왔다갔다- 의 방법을 풀어야한다. )
 * A일때 되돌아 가는게 유리하므로 nextIdx를 설정해서 되돌아갈 카운트를 센다.
 */
public class L2_210702_조이스틱 {

    public static void main(String[] args) {
        String name = "JEROEN";

        solution(name);
    }

    public static int solution(String name) {
        int min = name.length() - 1;


        int sum = 0;
        for (int i = 0; i < name.length(); i++) {
            int n = name.charAt(i) - 'A';
            if (n >= 13) {
                n = 26 - n;
            }
            sum += n;

            int nextIndex = i + 1;

            while (nextIndex < name.length() && name.charAt(nextIndex) == 'A')
                nextIndex++;

            min = Math.min(min,(i * 2) + name.length() - nextIndex);
            System.out.println("nextIndex = " + nextIndex);

        }

        sum += min;


        return sum;
    }

}
