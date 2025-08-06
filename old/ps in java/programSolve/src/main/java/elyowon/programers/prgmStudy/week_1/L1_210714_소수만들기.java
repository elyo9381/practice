package elyowon.programers.prgmStudy.week_1;


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
        List<Integer> curr = new ArrayList<>();
        sumComb1to3(nums,target,0,curr,result);
        // 소수 체크 및 count 리턴
        return countPrimeNumbers(result);
    }

    private int countPrimeNumbers(List<Integer> result) {
        return (int) result.stream().filter(this::isPrimeNum).count();
    }

    private boolean isPrimeNum(Integer integer) {

        int sqrt = (int) Math.sqrt(integer);
        for (int i = 2; i <= sqrt; i++) {
            if(integer % i == 0) return false;
        }
        return true;
    }

    private void sumComb1to3(int[] nums,int target,int i,List<Integer> curr,List<Integer> result) {

        if( target == 0){
            ArrayList<Integer> temp = new ArrayList<>(curr);
            int sum = temp.stream().mapToInt(Integer::intValue).sum();
            result.add(sum);
            return ;
        }

        for(int j = i; j<nums.length; j++){
            curr.add(nums[j]);
            sumComb1to3(nums,target-1,j+1,curr,result);
            curr.remove(curr.size()-1);
        }
    }
}