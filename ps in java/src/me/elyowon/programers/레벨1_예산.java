package me.elyowon.programers;


import java.util.Arrays;

/**
 * 2021.06.22
 * 최대한 많은 부서의 물품을 구매해 줄수 있도록 하려한다.
 */
public class 레벨1_예산 {


    public int solution(int[] d, int budget) {
        int answer = 0;



        Arrays.sort(d);
        int sum = 0;
        for (int i : d) {
            if (i <= budget) {
                budget -= i;
                answer++;
            }
        }

        return answer;
    }


}
