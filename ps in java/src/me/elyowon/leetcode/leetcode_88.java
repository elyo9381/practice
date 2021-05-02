package me.elyowon.leetcode;


public class leetcode_88 {


    public static void main(String[] args) {

        int[] arr1 = {4,5,6,0,0,0};
        int[] arr2 = {1,2,3};

        int m = 3, n = 3;

        MergeSort(arr1,arr2,m,n);

        for (int i : arr1) {
            System.out.print(" " + i);
        }
        System.out.println();

        char[] src = {'d','e','c','a','f','f','e','i','n','a','t','e','d'};
        char[] dst = new char[7];
        System.arraycopy(src,2,dst,0,7);
        System.out.println(new String(dst));


    }

    private static int[] MergeSort(int[] nums1,int[] nums2,int m,int n) {

        int num1Idx = m - 1;
        int num2Idx = n - 1;

        int wIdx = nums1.length - 1;

        if (m < 0) {
            return null;
        }

        while (0 <= num1Idx && 0 <= num2Idx) {
            int num1 = nums1[num1Idx];
            int num2 = nums2[num2Idx];

            if (num2 <= num1) {
                int num = num1;
                nums1[wIdx] = num;
                num1Idx--;
                wIdx--;
            } else {
                int num = num2;
                nums1[wIdx] = num;
                num2Idx--;
                wIdx--;
            }
        }
        // memory copy
        if (0 < num2Idx) {
            System.arraycopy(nums2,0,nums1,0,3);
        }
//        while(0<=num2Idx){
//            nums1[wIdx] = num2Idx;
//            num2Idx--;
//            wIdx--;
//        }


        return null;
    }

    private static void swap(int[] nums,int num,int num1) {
        int temp;
        temp = nums[num];
        nums[num] = nums[num1];
        nums[num1] = temp;
    }


}
