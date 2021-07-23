package elyowon.programers.L1;


import java.util.ArrayList;

/**
 * int min = Arrays.stream(arr).min().getAsInt();
 * return Arrays.stream.filter(i-> i!=min).toArray();
 */
public class L1_210626_제일작은수제거하기 {
    public int[] solution(int[] arr) {

        int[] answer ={};

        if(arr.length == 1){
            int[] ints = new int[1];
            ints[0] = -1;
            return ints;
        } else {
            int min = Integer.MAX_VALUE;
            for (int i : arr) {
                if(min > i) min = i;
            }

            answer = new int[arr.length-1];
            int idx =0;

            for (int i = 0; i < arr.length; i++) {
                if(arr[i] == min){
                    continue;
                }
                answer[idx++] = arr[i];
            }
        }
        return answer;
    }
}

