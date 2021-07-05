package me.elyowon.programers.L2;


import java.util.ArrayList;
import java.util.PriorityQueue;

/**
 */
public class L2_210704_예상대진표 {


    public int solution(int n, int a, int b){
        int answer = 0;

        int temp = n;
        int result ;
        while(true){
            int divN = temp / 2;

            if( a < divN  && divN <= b){
                result = temp *2;
                break;
            }

            if( divN < a && divN < b){
            }


            temp = divN;

        }


        while( result != 1){
            result /=2;
            answer++;
        }
        return answer;
    }
}