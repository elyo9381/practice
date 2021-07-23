package elyowon.leetcode.array;


public class leetcode_581 {


    /**
     *
     * 주어진 배열에서 서브어레이만 정렬한다고 가정하였을때
     * 오름 차순이 되게하는 서브레이의 길이를 반환해라
     *
     * 서브어레이를 찾아서 바꾸는 방법은 여러가지 존재한다.
     * 배열을 복사하고 정렬하여서 두 배열을 비교하여 다른 정렬을 찾고 길이를 찾는방법
     * 이는 빅오-엔로그엔으로 진행된다.
     *
     * 빅오엔으로 푸려면 어떻게 풀어야 할까?? 빅오 1은 안되므로
     * 빅오엔으로 풀어보쟈
     * 그러면 정렬은 안하고 풀어야한다. 그렇다면 서브어레이의 인덱스를 찾아야하 그 길이를 알수있고
     * 각각의 루프를 통해서 min,max를 구한다.
     * 또 구한 min, max를 통해서 맥스보다 작은값, 민보다 큰값을 찾아 서브어레이를 구할수 있다.
     * @param args
     */

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
            if(nums[i-1] > nums[i]){
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
