package me.elyowon.leetcode.backtracking;


import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

public class leetcode_78_Subset {


    /**
     *
     * leetcod 37, 22
     *
     * 백트래킹을 통해서 subsets을 구할수있다
     * 이때 주의할점은 subset의 recursion파라미터의 i+1을 넘기는것이다.
     * 이러한 이유는 이전 인덱스의 값을 중복되게 사용하지 않기 위해서이다.
     *
     * @param args
     */

    public static void main(String[] args) {

        int[] nums = {1,2,3};

        List<List<Integer>> result = subsets(nums);

        for (List<Integer> integers : result) {
            System.out.println(integers);
        }



    }

    public static List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new LinkedList<List<Integer>>();
        Arrays.sort(nums);
        process(0, nums, result, new LinkedList<Integer>());
        return result;
    }
    private static void process(int start, int[] nums, List<List<Integer>> result, List<Integer> curr) {
        result.add(new LinkedList<Integer>(curr));
        for (int i = start; i < nums.length; i ++) {
            curr.add(nums[i]);
            process(i+1, nums, result, curr);
            curr.remove(curr.size() - 1);
        }
    }
}

