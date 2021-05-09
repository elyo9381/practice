package me.elyowon.leetcode.dp;


import me.elyowon.leetcode.Pos;

import static java.lang.Math.*;

public class leetcode_152_MaxiumProductSubarray {


    /**
     *
     * dp를 이용한 최대곱 서브어레이는 sum서브어레이랑 비슷하게 푼다.
     * 하지만 점화식이 두개라는 점이 다르다.
     * 결과값 리턴이 아닌 서브 어레이를 리턴하면 인덱스를 계산해야한다.
     *
     * 이때 min,max의 파라미터가 3개이므로 이를 계산해야한다.
     *
     *
     * @param args
     */
    public static void main(String[] args) {

        int[] nums = {3,-2,1,0,-8,-9};
//        int[] nums = {2,3,-2,4};


        int[] result = calMaxProductSubarray(nums);

//        for (int i : result) {
//            System.out.println("i = " + i);
//        }

    }

    private static int[] calMaxProductSubarray(int[] nums) {
        // min  = y
        // max = x

        int max = (int) -1e9;
        int min = (int) 1e9;

        int[] minDp = new int[nums.length];
        int[] maxDp = new int[nums.length];

        minDp[0] = nums[0];
        maxDp[0] = nums[0];

        Pos[] pos = new Pos[nums.length];


        for (int i = 0; i < pos.length; i++) {
            pos[i] = new Pos(0,0);
        }


        for (int i = 1; i < nums.length; i++) {
            int a = minDp[i - 1] * nums[i];
            int b = maxDp[i - 1] * nums[i];
            minDp[i] = min(min(a,b),nums[i]);
            maxDp[i] = max(max(a,b),nums[i]);

            if( minDp[i-1] >= minDp[i]){
                pos[i].setY(pos[i-1].getY());
                if(minDp[i] == nums[i]){
                    pos[i].setY(i);
                }
            } else {
                pos[i].setY(i);
                if(minDp[i] == nums[i]){
                    pos[i].setY(pos[i-1].getY());
                }
            }

            if( maxDp[i-1] < maxDp[i]){
                pos[i].setX(pos[i-1].getY());
                if(maxDp[i] == nums[i]){
                    pos[i].setX(i);
                }
            } else if(maxDp[i-1] > maxDp[i]) {
                pos[i].setX(i);
            } else {
                pos[i].setX(pos[i-1].getX());
            }

            min = min(min,minDp[i]);
            max = max(max,maxDp[i]);
        }

        int maxStartMaxIndex = 0;
        int maxEndIndex = 0;
        for (int i = 0; i < maxDp.length; i++) {
            if (maxDp[i] == max) {
                maxStartMaxIndex = pos[i].getX();
                maxEndIndex = i;
            }
        }
        int minStartMaxIndex = 0;
        int minEndIndex = 0;
        for (int i = 0; i < maxDp.length; i++) {
            if (minDp[i] == min) {
                minStartMaxIndex = pos[i].getY();
                minEndIndex = i;
            }
        }

        System.out.println("minStartMaxIndex = " + minStartMaxIndex);
        System.out.println("minEndIndex = " + minEndIndex);


        System.out.println("startMaxIndex = " + maxStartMaxIndex);
        System.out.println("endIndex = " + maxEndIndex);



        for (Pos po : pos) {
            System.out.println("po.getY() = " + po.getY());
            System.out.println("po.getX() = " + po.getX());
            System.out.println();
        }


        System.out.println("max = " + max);
        System.out.println("min = " + min);


        for (int i : minDp) {
            System.out.println("i = " + i);
        }

        return new int[1];
    }


}



