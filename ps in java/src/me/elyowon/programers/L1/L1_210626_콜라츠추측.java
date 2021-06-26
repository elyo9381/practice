package me.elyowon.programers.L1;


import java.util.Arrays;

/**
 *
 */
public class L1_210626_콜라츠추측 {
    public int solution(int num) {
        int answer = 0;
        int tmp = num;

        while (true) {
            if(tmp == 1 || answer >500) break;
            answer++;
            if (tmp % 2 == 0) {
                tmp /= 2;
            } else {
                tmp *= 3;
                tmp += 1;
            }
        }


        if(answer > 500) answer = -1;

        return answer;
    }
}

