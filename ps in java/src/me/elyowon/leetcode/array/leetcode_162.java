package me.elyowon.leetcode.array;


public class leetcode_162 {




    public static void main(String[] args) {

        int[] arr = {1,3,2,4,5,7,6};

        int peakElement = findPeakElement(arr);

        System.out.println(peakElement);

    }

    /**
     * 최대값을 구하여 그 인덱스를 반환하면 O(n)으로 풀수있다.
     * 하지만 이보다 더 빠르게 풀어보라고 하면 어떻게 해야할것인가?
     * O(n) 보다 빠른것은 O(logN), O(1)이 존재한다 하지만 O(1)은 있을수없는 일이므로
     * O(logN)의 경우의 수를 생각해보자 !!
     * O(logN)로 접근하려면 이분탐색이 필요하다
     *
     * @param nums
     * @return
     */
    public static int findPeakElement(int[] nums){
        int left = 0, right = nums.length-1;

        if(nums.length <= -1){
            return 0;
        }

        while(left < right){
            int pivot = (left + right)/2;
            int num = nums[pivot];
            int nextNum = nums[pivot+1];

            if(num < nextNum){
                left = pivot +1;
            } else {
                right = pivot;
            }
        }
        return left;
    }

    private static void swap(int[] nums,int num,int num1) {
        int temp ;
        temp = nums[num];
        nums[num] = nums[num1];
        nums[num1] = temp;
    }


}
