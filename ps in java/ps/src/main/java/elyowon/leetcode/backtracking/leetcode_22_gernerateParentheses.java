package elyowon.leetcode.backtracking;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class leetcode_22_gernerateParentheses {


    /**
     * @param args
     */

    public static void main(String[] args) {

        List<String> result = generateParenthesis(3);

        for (String s : result) {
            System.out.println("s = " + s);
        }
        
        
    }

    public static List<String> generateParenthesis(int n){
        List<String> result = new LinkedList<String>();
        process("" , n , n , result);
        return result;
    }

    private static void process(String prefix,int left,int right,List<String> result) {


        if(left == 0 && right == 0){
            if(validParentheis(prefix)){
                result.add(prefix);
            }
            return ;
        }

        if(left > 0){
            process(prefix + "(" , left-1, right, result);
        }
        if(right > 0){
//        if(right > left){
            process(prefix + ")" , left, right-1, result);
        }

    }

    private static boolean validParentheis(String prefix) {
        int count = 0;
        for (int i = 0; i <prefix.length(); i++) {
            if(prefix.charAt(i) == '('){
                count++;
            }
            else {
                if(count == 0){
                    return false;
                }
                count--;
            }
        }
        return true;
    }
}


