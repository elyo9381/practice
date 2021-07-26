package elyowon.leetcode.array;


import static java.util.Arrays.sort;

public class leetcode_1 {


    /**
     *
     * twoSum은 부르트포스, 정렬후 투포인트, 해쉬맵을 이용해서 풀수있다.
     *
     *
     * @param args
     */

    public static void main(String[] args) {

        int[] nums = {1,3,7,4,8};
//        int[] arr = {-1,0,1,2,-1,-4};

        int [] result = twoSum(nums,5);

        for (int i : result) {
            System.out.println("i = " + i);
        }
    }

    private static int[] um(int[] nums,int i) {
        return new int[0];
    }

    private static int[] twoSum(int[] nums,int target) {

        sort(nums);

        int pL = 0, pR = nums.length-1;
        int[] answer = new int[2];

        while(pL < pR){
            int result = nums[pL] + nums[pR];

            if( result == target){
                answer[0] = pL;
                answer[1] = pR;
                return answer;
            }
            if( result > target ){
                pR--;
            } else {
                pL++;
            }
        }

        return null;
    }


}
