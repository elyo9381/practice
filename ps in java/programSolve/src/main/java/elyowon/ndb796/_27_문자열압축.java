package elyowon.ndb796;



import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;


/*
input
K1KA5CB7

*/
public class _27_문자열압축 {

    public static void main(String[] args) {
        String s ="aabbaccc";

        int result = solution(s);
        System.out.println(result);
    }

    public static int solution(String s) {
        int answer = s.length();
        for (int step = 1; step < s.length() / 2 + 1; step++) {
            String compressed = "";
            String prev = s.substring(0,step);
            int cnt = 1;

            for (int j = step; j < s.length(); j += step) {
                String sub = "";
                for (int k = j; k < j + step; k++) {
                    if( k < s.length()) sub += s.charAt(k);
                }

                if(prev.equals(sub)) cnt+=1;
                else {
                    compressed += (cnt>=2)? cnt + prev : prev;
                    sub = "";
                    for (int k = j; k < j+ step; k++) {
                        if(k < s.length()) sub += s.charAt(k);
                    }
                    prev = sub;
                    cnt =1;
                }
            }

            compressed += (cnt >= 2) ? cnt + prev : prev;
            answer = Math.min(answer,compressed.length());
        }

        return answer;
    }
}
