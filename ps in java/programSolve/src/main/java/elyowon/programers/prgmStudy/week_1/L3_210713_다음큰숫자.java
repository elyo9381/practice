package elyowon.programers.prgmStudy.week_1;


import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Stack;
import java.util.stream.IntStream;

/**
 *
 */
public class L3_210713_다음큰숫자 {

    // n+i > n
// n+i , n 의 이진수의 갯수는 같습니다.
// 1,2를 만족하는 수들 중 가장 작은 수

    /*
     n 부터 시작해서 매번 이진수 비교 같은수가 나오면 그 수가 최소값
    */
    public int solution(int n) {
        int num1 =0;
        int num2 =0;
        int idx = n;
        num1 = BinaryOneCount(n);
        while(num1 != num2){
            idx++;
            num2 = BinaryOneCount(idx);
        }
        int answer = idx;
        return answer;

    }

    private int BinaryOneCount(int n) {
        int result = 0;
//        String s = Integer.toBinaryString(n);
//        result = (int) IntStream.range(0,s.length()).filter(i -> s.charAt(i) == '1').count();
        int temp = 1;
        while(temp <= n){
            result += (n & temp) != 0 ? 1 : 0;
            temp = temp << 1;
        }
        return result;
    }
}