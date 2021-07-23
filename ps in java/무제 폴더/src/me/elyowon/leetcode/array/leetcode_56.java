package me.elyowon.leetcode.array;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class leetcode_56 {


    /**
     * Given a collection of intervals, merge all overlapping intervals.
     * if start index is small than that is new Interval second index, new Interval index change old interval second index
     *
     * @param args
     */
    public static void main(String[] args) {

        int[][] nums = {{2,6},{1,3},{8,10},{15,18}};

        int[][] m = merge(nums);


        for (int[] ints : m) {
            System.out.println(ints[0] + " "  + ints[1]);
        }

    }

    public static int[][] merge(int[][] intervals) {
        if (intervals.length <= 1)
            return intervals;
        
        Arrays.sort(intervals,(i1,i2) -> Integer.compare(i1[0],i2[0]));
        List<int[]> result = new ArrayList<>();
        int[] newInterval = intervals[0];
        
        result.add(newInterval);
        for (int[] interval : intervals) {
            if (interval[0] <= newInterval[1])
                newInterval[1] = Math.max(newInterval[1],interval[1]);
            else {
                newInterval = interval;
                result.add(newInterval);
            }
        }

        return result.toArray(new int[result.size()][]);
    }


    private static void swap(int[] nums,int num,int num1) {
        int temp;
        temp = nums[num];
        nums[num] = nums[num1];
        nums[num1] = temp;
    }


}
