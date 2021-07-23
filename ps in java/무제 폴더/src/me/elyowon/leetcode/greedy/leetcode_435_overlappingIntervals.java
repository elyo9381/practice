
package me.elyowon.leetcode.greedy;


import java.util.Arrays;
import java.util.PriorityQueue;

/**
 * 최소로 겹치는 구간은 ????
 * 최대로 안겹치는 구간을 구하면 된다.
 *
 *
 * 끝나는 구간으로 소팅한뒤 첫째구간과 겹치는 부분은 삭제하고
 * 겹치지 않는 구간은 선택한다.
 */

public class leetcode_435_overlappingIntervals {


    public static void main(String[] args) {
        int[][] intervals = {{1,2},{2,3},{3,4},{1,3}};

        int result = eraseOverlapIntervals(intervals);

        System.out.println(result);
    }

    public static int eraseOverlapIntervals(int[][] intervals) {
        if(intervals.length == 0) return 0;

        Arrays.sort(intervals, (a,b) -> a[0] - b[0]);

        int lastEnd = Integer.MIN_VALUE;
        int intervalCount = 0;

        for (int[] interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            if( start < lastEnd) continue;


            if(lastEnd <= end){
                intervalCount +=1;
                lastEnd = end;

            }
        }
        return intervalCount;
    }
}