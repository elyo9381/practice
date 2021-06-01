package me.elyowon.leetcode.greedy;


import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

/**
 *
 */

public class leetcode_1710_MaximumUnitsOnTruck {


    public static void main(String[] args) {
        int[][] a = {{1,3},{2,2},{3,1}};
        int truckSize = 2;

        int result = maximumUnits(a,truckSize);

        System.out.println(result);
    }
    public static int maximumUnits(int[][] boxTypes,int truckSize) {

        Arrays.sort(boxTypes,(a,b) -> b[1] - a[1]);

        int boxes = 0;
        for (int[] box : boxTypes) {
            if (truckSize >= box[0]) {
                boxes += box[0] * box[1];
                truckSize -= box[0];
            } else {
                boxes += truckSize * box[1];
                return boxes;
            }
        }

        return boxes;
    }

}
