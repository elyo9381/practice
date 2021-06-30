package me.elyowon.programers.L2;


import java.util.Arrays;

/**
 */
public class L2_210630_기능개발 {


        public int[] solution(int[] progresses, int[] speeds) {
            int[] dayOfend = new int[100];
            int day = 1;
            for(int i=0; i<progresses.length; i++) {
                while(progresses[i] + (day*speeds[i]) < 100) {
                    day++;
                }
                dayOfend[day]++;
            }
            return Arrays.stream(dayOfend).filter(i -> i!=0).toArray();
        }
}
