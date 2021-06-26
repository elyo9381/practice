package me.elyowon.programers.L1;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;

/**
 */
public class L1_210625_같은숫자는싫어 {
    public int[] solution(int []arr) {
        int[] answer = new int[10];
        int prev =0;

        ArrayList<Integer> list = new ArrayList<>();

        list.add(arr[prev]);

        for (int i = 1; i < arr.length; i++) {
            if(arr[i] == arr[prev++]){
                continue;
            }
            list.add(arr[i]);
        }

        answer = list.stream().mapToInt(i->i).toArray();

        return answer;
    }
}

