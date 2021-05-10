package me.elyowon.leetcode.backtracking;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class leetcode_39_combination {


    /**
     * combination의 이해가 더욱 깊어졌다.
     * implement부분에서 루프의 i,j의 인덱스의 관계를 계산하기 힘들었는데
     * 트리를 통해서 조합을 이용하니 조금 이해하기 쉬운것같다.
     * <p>
     * 조합을 통해서 인덱스와 같은값을 계속 블러올수있다. recursion(start(i)...
     * 또는 recursion(start(i+1)... 등을 통해서 인덱스+1의 상황을 불러올수있다.
     *
     * @param args
     */

    public static void main(String[] args) {
//        int[] nums = {2,3,6,7};
//        int target = 7;
        int[] nums = {10,1,2,7,6,1,5};
        int target = 8;

        List<List<Integer>> results = combinationSum(nums,target);

        for (List<Integer> result : results) {
            System.out.println(result);
        }
    }

    private static List<List<Integer>> combinationSum(int[] candidates,int target) {

        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if (candidates == null || candidates.length == 0) return result;
        ArrayList<Integer> current = new ArrayList<Integer>();
        Arrays.sort(candidates);
        combinationSum(candidates,target,0,current,result);
        return result;
    }

    public static void combinationSum(int[] candidates,int target,int j,ArrayList<Integer> curr,List<List<Integer>> result) {
        if (target == 0) {
            ArrayList<Integer> temp = new ArrayList<Integer>(curr);
            result.add(temp);
            return;
        }
        for (int i = j; i < candidates.length; i++) {
            // target 보다 큰거는 방문 하지 않으려고 미리 제거함
            // 만약에 방문하면? 무한루프 빠진다. 위에서 리턴 조건을 설정해줘야함
            if (target < candidates[i]) {
                return;
            }
            // 조건같은 상황은 처음에 인덱스에서 벗어난다 i = -1이 되어 그렇기에 i==j를 지정해주는것
            if (i == j || candidates[i] != candidates[i - 1]) {
                curr.add(candidates[i]);
                combinationSum(candidates,target - candidates[i],i + 1,curr,result);
                curr.remove(curr.size() - 1);
            }
        }//for i
    }//combinationSum

}

