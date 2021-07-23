package elyowon.leetcode.array;

public class leetcode_209 {

    /**
     *
     * if find max ? >> 29 line change -> min <= (end - start +1);
     * ans local value 'min' change -1e9;
     *
     * @param target
     * @param nums
     * @return
     */

    private static int minSubArray(int target,int[] nums) {
        int len = nums.length;
        if (len == 0) return 0;
        int start = 0, end = 0, sum = nums[0], min = (int) 1e9;
        boolean findRetValue = false;

        while (start <= end && end < len) {
            if (sum < target) {
                end += 1;
                if (end < len) {
                    sum += nums[end];
                }
            } else if (sum >= target) {

                if( sum == target){
                    if (min >= (end - start + 1)) {
                        min = end - start + 1;
                        findRetValue = true;
                    }
                }

                if (sum > target) {
                    sum -= nums[start++];
                } else {
                    end += 1;
                    if (end < len) {
                        sum += nums[end];
                    }
                }
            }
        }
        if (findRetValue) return min;
        return -1;
    }


    public static void main(String[] args) {

        int[] arr = {3,4,2,1,3,2};
        int result;

        result = minSubArray(7,arr);

        System.out.println("result = " + result);
    }

}
