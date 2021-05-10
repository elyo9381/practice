package me.elyowon.leetcode.backtracking;


import java.util.LinkedList;
import java.util.List;

public class leetcode_46_permutation {


    /**
     * @param args
     */

    public static void main(String[] args) {
        int[] nums = {1,1,3};

        List<List<Integer>> permute = permute(nums);

        for (List<Integer> integers : permute) {
            System.out.println(integers);
        }
    }

    public static List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new LinkedList<>();
        boolean[] visited = new boolean[nums.length];
        dfs(nums,res,new LinkedList<Integer>(),visited);
        return res;
    }

    private static void dfs(int[] nums,List<List<Integer>> res,List<Integer> curr,boolean[] visited) {
        if (curr.size() == nums.length) {
            res.add(new LinkedList<Integer>(curr));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if(visited[i] == true){
                continue;
            }
//            //permutation의 중복을 허용할떄 그리고 순서대로 정렬할때
//            if (i == 0 || nums[i] != nums[i - 1] || (nums[i] == nums[i - 1] && visited[i - 1] == true)) {
                visited[i] = true;
                curr.add(nums[i]);
                dfs(nums,res,curr,visited);
                curr.remove(curr.size() - 1);
                visited[i] = false;
//            }
        }
    }
}

