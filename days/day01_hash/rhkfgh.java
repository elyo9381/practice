import java.util.Stack;

// 올바른 괄호
public class rhkfgh {

    public boolean solution(String s){

        Stack<Character> st = new Stack<>();

        for( char c : s.toCharArray()){

            if( c == '(') {
                st.push(c);
            } else {
                if( st.isEmpty()) return false;
                st.pop();
            }
        }
        return st.isEmpty();
    }
}
