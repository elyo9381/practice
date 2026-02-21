import java.util.*;

public class call_list {

    public static boolean Solution(String[] phone_book){
        boolean answer = true;
        Set<String> set = new HashSet<>();

        for( String e : phone_book){
            set.add(e);
        }

        for( String e : phone_book){
            for(int j = 1 ; j < e.length(); j++){
                String s = e.substring(0,j);
                if( set.contains(s) ){
                    return false;
                }
            }
        }
        return answer;
    }
}
