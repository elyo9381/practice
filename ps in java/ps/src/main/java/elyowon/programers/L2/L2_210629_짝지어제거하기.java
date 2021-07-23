package elyowon.programers.L2;


import java.util.Stack;

/**
 * 무조건 짝수로 나온다. 왜냐? 짝지어제거하기 이므로
 * 분할정복을 통해서 나눈다음 합칠때 조건으로 거르면 된다고 생각했는데
 * 멍청한 접근이었다.
 */
public class L2_210629_짝지어제거하기 {

    public static void main(String[] args) {
        int baabaa = solution("abccba");
        System.out.println("abccba = " + baabaa);
    }

    public static int solution(String s)
    {
        int answer = 0;

        int lo = 0;
        int hi = s.length()-1;
        int m = (lo + hi) /2;

        String solve = solve(lo,hi,s);

        sovle2(s);


        return answer;
    }

    private static int sovle2(String s) {
        Stack<String> stack = new Stack<>();

        for(int i =0; i<s.length(); i++){
            if(stack.isEmpty()){
                stack.add(s.substring(i,i+1));
            } else if(stack.peek().equals(s.substring(i,i+1))){
                stack.pop();
            } else {
                stack.add(s.substring(i,i+1));
            }
        }

        if(stack.isEmpty()){
            return 1;
        }else {
            return 0;
        }
    }

    private static String solve(int low,int high,String s) {

        int m ;
        String  left, right ,lt;
        m = (low+high)/2;

        if(low == high) return String.valueOf(s.charAt(low));

        left = solve(low,m,s);
        right = solve(m+1,high,s);

        if(left.length() >= 1){
            lt = String.valueOf(left.charAt(left.length()-1));
        } else {
          lt = left;
        }
        if(lt.equals(right)){
            return "";
        } else if ( lt.equals("") ){
            return right;

        } else if (right.equals("")){
            return lt;
        } else {
            return left+right;
        }
    }

}