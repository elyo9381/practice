package elyowon.programers.L1;


import java.util.stream.IntStream;

/**
 * return new String(new char [n/2+1]).replace("\0", "수박").substring(0,n);
 * new char[] 하게 되면 빈배열이 생기고 char 형은 \0이 생성된다.
 *
 */
public class L1_210626_수박 {
    public String solution(int n) {
        String answer = "";

        String s = "수박";
        if(n % 2 == 0){
            for(int i =0 ; i<n/2; i++){
                answer += s;
            }
        } else {
            for(int i =0 ; i<n/2; i++){
                answer += s;
            }
            answer +="수";
        }
        return answer;
    }
}

