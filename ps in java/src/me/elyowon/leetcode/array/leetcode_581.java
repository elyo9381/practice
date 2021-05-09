package me.elyowon.leetcode.array;


public class leetcode_581 {




    public static void main(String[] args) {

        int[] arr = {2,5,7,6,3,9,15};

        int result = shortUnsortedContinuousSubarray(arr);
        System.out.println("result = " + result);


    }

    private static int shortUnsortedContinuousSubarray(int[] nums) {
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        int left = 0, rigth = 0;

        for (int i = 0; i < nums.length-1; i++) {
            if(nums[i] > nums[i+1]){
                min = Math.min(min,nums[i+1]);
            }
        }

        for (int i = nums.length-1; i>0; i--) {
            if(nums[i] < nums[i-1]){
                max = Math.max(max,nums[i-1]);
            }
        }

        for (int i = nums.length-1; i>=0; i--) {
            if(nums[i] < max){
                rigth = i;
                break;
            }
        }

        for (int i = 0; i< nums.length -1; i++){
            if(min < nums[i] ){
                left = i;
                break;
            }
        }

        return rigth-left >=0 ? rigth-left+1 : 0;
    }


    private static void swap(int[] nums,int num,int num1) {
        int temp ;
        temp = nums[num];
        nums[num] = nums[num1];
        nums[num1] = temp;
    }


}
