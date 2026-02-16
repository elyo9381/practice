package elyowon.programers.prgmStudy.week_4;

import java.util.Arrays;

public class 입국심사 {
    public long solution(int n, int[] times) {
        long answer = 0;

        Arrays.sort(times);


        long start=times[0], end=(long)n*times[times.length-1];

        while(start <= end) {
            long mid = (start + end) / 2;
            long sum = 0;

            for(int i=0; i<times.length; i++) {
                sum += mid / times[i];

                if(sum >= n) break;
            }

            if(sum < n) {
                start = mid+1;
            }else {
                end = mid-1;
                answer = mid;
            }
        }
        return answer;
    }
}