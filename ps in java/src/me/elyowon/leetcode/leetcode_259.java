package me.elyowon.leetcode;


import java.util.ArrayList;

import static java.util.Arrays.sort;

public class leetcode_259 {


    /**
     * 3 Sum은 부르트포스, 정렬후 쓰리포인트, 해쉬맵을 이용해서 풀수있다.
     *
     * 3Sum에서 확장된 인사이트를 요하는 문제이다.
     * 풀이방법은 N^2으로 정렬후 투포인터로 풀었다.
     * 이떄 조건을 넣어 총합이 2보다 작은 3개의 값을 구하여 반환한다.
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




        ArrayList<int[]> list = new ArrayList<int[]>();

        for (int i = 0; i < nums.length; i++) {
            int p2 = i + 1, p3 = nums.length - 1;

            while (p2 < p3) {
                int result = nums[i] + nums[p2] + nums[p3];

                if (result < target) {
                    int[] ints = new int[3];
                    ints[0] = i;
                    ints[1] = p2;
                    ints[2] = p3;
                    list.add(ints);
                    p3--;
                } else {
                    p2++;
                }
            }
        }

        return list;
    }


}
