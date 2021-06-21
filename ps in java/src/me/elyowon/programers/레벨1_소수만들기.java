package me.elyowon.programers;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.IntStream;

/**
 * 2021.06.21
 * 조합으로 3개 묶고
 * 그 조합이 소수인지 판별 후 카운트
 *
 * 조합으로 하다보니 투 포인터도 가능할것같다.
 */
public class 레벨1_소수만들기 {


    public int solution(int[] nums) {
        int answer = -1;


        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if(nums == null || nums.length == 0) return 0;

        ArrayList<Integer> current = new ArrayList<Integer>();
        Arrays.sort(nums);
        int target = 3;
        int resultNum = 0;

        combination(nums,target,0,current,result);

        for (List<Integer> integers : result) {
            System.out.println("integers = " + integers);
            if(PrimeNumber(integers)){
                resultNum++;
            }
        }


        return resultNum;
    }

    public static void combination(int[] nums, int target, int j, ArrayList<Integer> curr, List<List<Integer>> result){
        if (target == 0) {
            ArrayList<Integer> temp = new ArrayList<Integer>(curr);
            result.add(temp);

            return;
        }

        IntStream.range(j,nums.length).forEach(i-> {
            curr.add(nums[i]);
            combination(nums, target -1, i+1, curr, result);
            curr.remove(curr.size()-1);
        });
    }

    private static boolean PrimeNumber(List<Integer> temp) {

        int sum = temp.stream().mapToInt(integer -> integer).sum();


//        boolean isPrime = IntStream
//                .iterate(2,i -> i < Math.sqrt(sum),i -> i + 1)
//                .anyMatch(i -> sum % i == 0);
        boolean isPrime = false;
        for (int i = 2; i < Math.sqrt(sum); i++) {
            if(sum % i == 0){
                isPrime = true;
                break;
            }
        }

        if(isPrime) return false;
        else return true;
    }
}
