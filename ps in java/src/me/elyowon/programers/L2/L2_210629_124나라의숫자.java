package me.elyowon.programers.L2;


import java.util.Stack;

/**
 * 무조건 짝수로 나온다. 왜냐? 짝지어제거하기 이므로
 * 분할정복을 통해서 나눈다음 합칠때 조건으로 거르면 된다고 생각했는데
 * 멍청한 접근이었다.
 */
public class L2_210629_124나라의숫자 {

   public String solution(int n){
       String answer = "";
       StringBuilder sb = new StringBuilder();
       while(n != 0){
           if( n%3 == 0){
               sb.insert(0,4);
               n = n/3 - 1;
           } else {
               sb.insert(0,n%3);
               n = n/3;
           }
       }
       return sb.toString();
   }

}