package me.elyowon.programers.L1;


/**
 *
 */
public class L1_210626_자릿수더하기 {
    public int solution(int n) {
        int answer = 0;

        while (n>0) {
            answer += n % 10;
            n /= 10;
        }

        return answer;
    }
}

