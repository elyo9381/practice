
import java.util.*;
import java.lang.*;


public class Solution {

    public int solution(String s){

        int len = s.length();
        if(len == 1) return 1;
        int min = len;

        for(int i = 1; i<=len/2; i++){
            StringBuilder sb = new StringBuilder();
            String prev = s.substring(0,i);
            int count = 1;

            for(int j = i; j<len ;j+=i){
                int end = Math.min(i+j,len);
                String cur = s.substring(j,end);

                if( prev.equals(cur) ){
                    count++;
                } else {
                    if( count > 1) sb.append(count);
                    sb.append(prev);
                    prev = cur;
                    count = 1;
                }
            }

            if( count > 1 ) sb.append(count);
            sb.append(prev);
            min = Math.min(min, sb.length());
        }

        return min;
    }
}