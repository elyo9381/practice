package me.elyowon.leetcode;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Set;

import static java.util.Arrays.sort;

public class leetcode_18_4sum {


    /**
     * 4sum은 백트래킹, 정렬후 투포인터 , 해쉬맵을 이용해서 풀수있다.
     *
     *  여기서 중요한것은 kSum이다.
     *  어떻게 풀지를 아마 면접관들을 중요하게 생각할것이다.
     *
     *
     * @param args
     */

    public static void main(String[] args) {


        int[] nums = {1,0,-1,0,-2,2,0,0,0,0,0,0,0,0};

        List<List<Integer>> result = fourSum(nums,3);

        for (List<Integer> integers : result) {
            System.out.println(integers);
        }

    }

    public static List<List<Integer>> fourSum(int[] nums,int target) {
        Arrays.sort(nums);

        return kSum(nums, 0, 4, target);
    }

    public static List<List<Integer>> kSum(int[] nums,int start,int k,int target) {
        List<List<Integer>> res = new ArrayList<>();
        if (start == nums.length || k*nums[start] > target || k*nums[nums.length-1] < target)
            return res;

        if (k==2) {
            return twoSum(nums, start, target);
        }

        for (int i=start; i<nums.length; i++) {
            if (i!=start && nums[i-1]==nums[i]) continue;
            for (var set : kSum(nums, i+1, k-1, target-nums[i])) {
                res.add(new ArrayList<>(Arrays.asList(nums[i])));
                res.get(res.size()-1).addAll(set);
            }
        }
        return res;
    }

    public static List<List<Integer>> twoSum(int[] nums,int start,int target) {
        List<List<Integer>> res = new ArrayList<>();
        int lo = start;
        int hi = nums.length-1;
        while (lo<hi) {
            int sum = nums[lo]+nums[hi];
            if (target == sum) {
                res.add(Arrays.asList(nums[lo++], nums[hi--]));
                while (lo<hi && nums[lo-1]==nums[lo]) lo++;
            }
            else if (target < sum) hi--;
            else lo++;
        }
        return res;
    }

}
