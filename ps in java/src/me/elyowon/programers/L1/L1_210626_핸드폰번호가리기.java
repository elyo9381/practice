package me.elyowon.programers.L1;


import java.util.Arrays;

/**
 * phone_number.replaceAll(".(?=.{4})","*");
 */
public class L1_210626_핸드폰번호가리기 {
    public String solution(String phone_number) {
        String answer = "";
        int backNumber = phone_number.length()-4;
        String starNum = phone_number.substring(0,backNumber);
        String s = starNum.replaceAll("[0-9]","*");
        answer = s+phone_number.substring(backNumber,phone_number.length());

        return answer;
    }
}

