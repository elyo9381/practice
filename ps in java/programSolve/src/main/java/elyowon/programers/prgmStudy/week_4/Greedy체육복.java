package elyowon.programers.prgmStudy.week_4;

import java.util.Arrays;
import java.util.stream.IntStream;

public class Greedy체육복 {
    public int solution1(int n, int[] lost, int[] reserve) {
        int[] partIn = new int[n];

        Arrays.fill(partIn,1);
        Arrays.stream(lost).forEach(i -> partIn[i - 1]--);
        Arrays.stream(reserve).forEach(i -> partIn[i - 1]++);

        Arrays.stream(partIn).filter(i -> partIn[i] == 2).forEach(i -> {
            if (i > 0 && partIn[i - 1] == 0) {
                partIn[i - 1] = 1;
                partIn[i] = 1;
            } else if (i < n - 1 && partIn[i + 1] == 0) {
                partIn[i] = 1;
                partIn[i + 1] = 1;
            }
        });

        return (int) Arrays.stream(partIn).filter(i-> i>=1).count();
    }
}