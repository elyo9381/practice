package me.elyowon.programers.prgmStudy.week_1;


import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 *
 */
public class L1_210714_소수만들기 {

    public int solution(int[] nums){

        // 조합으로 3자리 합 결과 리스트
        int target = 3;
        List<Integer> result = new ArrayList<>();
        List<Integer> curr = new LinkedList<>();
        sumComb1to3(nums,target,0,curr,result);

        // 소수체크
        return PrimeNumCount(result);
    }

    private int PrimeNumCount(List<Integer> result) {
         return (int) result.stream().filter(this::isPrimeNum).count();
    }

    private boolean isPrimeNum(Integer integer) {

        if(integer == 2) return true;
        if(integer % 2 == 0 && integer >= 3){
            for (int i = 3; i < Math.sqrt(integer); i += 2) {
                if(integer % i == 0) return false;
            }
        }
        return true;
    }

    private void sumComb1to3(int[] nums,int target,int i,List<Integer> curr,List<Integer> result) {

        if( target == i-1){
            ArrayList<Integer> temp = new ArrayList<>(curr);
            int sum = temp.stream().mapToInt(Integer::intValue).sum();
            result.add(sum);
        }

        for(int j = i; j<nums.length; j++){
            curr.add(nums[j]);
            sumComb1to3(nums,target,j+1,curr,result);
            curr.add(curr.size()-1);
        }
    }
}