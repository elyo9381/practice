package me.elyowon.programers.L3;


import java.util.HashMap;
import java.util.LinkedList;
import java.util.Stack;

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
    class Solution {
        public int solution(int n) {
            int answer = 0;
            // 이진수 비교하는 함수
            int idx = n;
            int num1 = 0;
            int num2 = 0;
            num1 = BinaryNumCount(n);

            while (true) {
                idx++;
                num2 = BinaryNumCount(idx);
                if (num1 == num2) break;
            }
            answer = idx;
            return answer;
        }

        private int BinaryNumCount(int n) {
            int result = 0;
            int temp = 0;
            while (n != 0) {
                temp = n % 2;
                if (temp == 1) result++;
                n /= 2;
            }
            return result;
        }
    }
}