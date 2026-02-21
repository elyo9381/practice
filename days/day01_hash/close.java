import java.util.*;

// 위장
public static void main(String[] args) {

    public static int Solution(String[][] clothes){
        int answer =0 ;

        Map map = new HashMap<String,Integer>();

        for(String[] c : clothes){
            map.put(c[1], map.getOrDefault(c[1], 0)+1);
        }

        answer = 1;
        for(Integer e : map.values()){
            answer *= (e+1);
        }
        return answer -1;
    }


}