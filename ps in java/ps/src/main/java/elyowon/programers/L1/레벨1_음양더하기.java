package elyowon.programers.L1;


import java.util.Arrays;
import java.util.HashMap;

/**
 * 2021.06.20
 */
public class 레벨1_음양더하기 {

    public static void main(String[] args) {
        int[] lost = {3,1};
        int[] reverse = {2,3};

        int n = 5;


    }

    public static int solution(int[] absolutes,boolean[] signs) {
        int sum = 0;
        int i = 0;
        for (int absolute : absolutes) {
              if(signs[i] == true){
                  sum +=absolute;
              }
              else{
                  sum +=-absolute;
              }
              i++;

        }
        return sum;
    }



}
