package elyowon.leetcode.array;


import static java.util.Collections.swap;

public class leetcode_75 {




    public static void main(String[] args) {

        int[] arr = {2,0,2,1,1,0};
        int result;

        sorColor(arr);

        for (int i : arr) {
            System.out.print(" " + i);
        }
    }


    // inPlaceSwap 을 이용해서 정렬을 하라  >> quickSort
    private static void sorColor(int[] nums) {
        int idx0 = 0;
        int idx2 = nums.length - 1;
        int i = 0;

        while( i<= idx2){
            if(nums[i] == 0){
                swap(nums,i,idx0);
                idx0++;
                i++;
            } else if(nums[i] == 2){
                swap(nums,i,idx2);
                idx2--;
            } else {
                i++;
            }
        }
    }

    private static void swap(int[] nums,int num,int num1) {
        int temp ;
        temp = nums[num];
        nums[num] = nums[num1];
        nums[num1] = temp;
    }


}
