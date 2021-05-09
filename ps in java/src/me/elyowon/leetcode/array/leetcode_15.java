package me.elyowon.leetcode.array;


import java.util.ArrayList;

import static java.util.Arrays.asList;
import static java.util.Arrays.sort;

public class leetcode_15 {


    /**
     * 3 Sum은 부르트포스, 정렬후 투포인트, 해쉬맵을 이용해서 풀수있다.
     * <p>
     * O(n^2)으로 플수있다.
     *
     * @param args
     */

    public static void main(String[] args) {

        int[] nums = {-2,0,1,3};

        ArrayList<int[]> result = threeSum(nums,2);

        System.out.println(result.size());
//        if (result.size() == 0) System.out.println(0);
//        else {
//            for (int[] ints : result) {
//                for (int anInt : ints) {
//                    System.out.print(anInt);
//                }
//                System.out.println();
//            }
//        }
    }


    private static ArrayList<int[]> threeSum(int[] nums,int target) {

        sort(nums);

        for (int i : nums) {
            System.out.print(" " + i);
        }
        System.out.println();

        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;

        int p1 = 0;


        ArrayList<int[]> list = new ArrayList<int[]>();

        for (int i = p1; i < nums.length; i++) {
            int p2 = i + 1, p3 = nums.length - 1;

            while (p2 < p3) {
                int result = nums[i] + nums[p2] + nums[p3];

                if(result == target){
                    int[] ints = new int[3];
                    ints[0] = i;
                    ints[1] = p2;
                    ints[2] = p3;
                    list.add(ints);
                }

                if (result < target) {
                    p3--;
                } else {
                    p2++;
                }
            }
        }

        return list;
    }


}
