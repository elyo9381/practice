package me.elyowon.programers.prgmStudy.week_1;


import java.util.ArrayList;
import java.util.Arrays;

/**
 *
 */
public class L1_210714_K번째 {

    public int[] solution(int[] array, int[][] commands) {

        ArrayList<Integer> result = new ArrayList<>();
        for(int[] command : commands){
            int start = command[0]-1;
            int end = command[1];
            int find = command[2]-1;

            int[] list = Arrays.stream(array,start,end).sorted().toArray();

            result.add(list[find]);
        }
        return result.stream().mapToInt(Integer::intValue).toArray();
    }

}