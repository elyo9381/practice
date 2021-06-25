package me.elyowon.programers;


import java.util.ArrayList;

/**
 *
 */
public class L1_210625_나누어떨어지는숫자배열 {
    public int[] solution(int[] arr, int divisor) {
        int[] answer = {};

        ArrayList<Integer> arrayList = new ArrayList<>();

        for (int i : arr) {
            if(i % divisor == 0){
                arrayList.add(i);
            }
        }


        if( arrayList.size() == 0){
            arrayList.add(-1);
        }

        answer = arrayList.stream().sorted().mapToInt(i-> i).toArray();
        return answer;
    }
}

