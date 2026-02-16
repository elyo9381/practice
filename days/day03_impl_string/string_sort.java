
import java.util.*;

/**
 * 주의 할거 최소 , 최대 인 상황에서의
 * @param numbers
 * @return
 */

public int sulution(int[] numbers){

    ArrayList<String> arr = new ArrayList<>();

    for(int it : numbers){
        arr.add(String.valueOf(it));
    }

    arr.sort((a,b) -> (b+a).compareTo(a+b));

    StringBuilder sb = new StringBuilder();

    for(String s : arr){
        sb.append(s);
    }
    String str = sb.toString();
    return str.startsWith("0") ? "0" :str;
}