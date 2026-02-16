package elyowon.programers.L1;


import java.util.ArrayList;
import java.util.Collections;

/**
 * 문자열 문제확인 문제는 왠만하면 regex 사용하자
 */
public class L1_210625_문자열다루기기본 {


    public boolean solution(String s){
        boolean answer = true;

//        for(int i =0 ;i<s.length(); i++){
//            if( !(s.charAt(i) >= '0' && s.charAt(i) <= '9')) answer= false;
//        }
     if(s.length() == 4 || s.length() == 6) return s.matches("(^[0-9]*$)");
     return false;


//        return answer;
    }

}