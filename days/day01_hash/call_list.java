import java.util.*;

public static void main(String[] args) {

    
    public static boolean Solution(String[] phone_book){
        boolean answer = true;
        Set set = new HashSet<>();

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