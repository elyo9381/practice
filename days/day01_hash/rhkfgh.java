import java.util.Stack;

public static void main(String[] args) {

    public boolean solution(String s){

        Stack<Charactor> st = new Stack<>();

        for( char c : s.toCharArray()){
        
            if( c == '(') {
                st.push(c);
            } else {
                if( st.isEmpty) return false;
                st.pop();
            }
        }
        return true;
    }
}