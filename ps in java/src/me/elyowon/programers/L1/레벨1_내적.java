package me.elyowon.programers.L1;


/**
 * 2021.06.20
 */
public class 레벨1_내적 {


    public int solution(int[] a, int[] b) {

        int answer = 0;


        int len = a.length;
        while(len > 0){
            long sum = a[len] * b[len];

            answer +=sum;
        }
        return answer;
    }
}
