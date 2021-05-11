package me.elyowon.leetcode.backtracking;


import java.util.ArrayList;
import java.util.List;

public class leetcode_93_IPAddresses {


    /**
     * dfs로 된 풀이이다.
     * backtracking으로 푼 풀이가 아니다.
     *
     * @param args
     */

    public static void main(String[] args) {

       String s  = "2000935";
//       String s  = "25525511135";
        List<String> result = restoreIpAddresses(s);
        for (String s1 : result) {
            System.out.println("s1 = " + s1);
        }

    }
    private static List<String> restoreIpAddresses(String s) {

        List<String> res = new ArrayList<>();
        backtracking(s, res, new StringBuilder(), 0, 0);
        return res;
    }


    private static void backtracking(String s,List<String> res,StringBuilder sb,int index,int level){
        if(index > s.length() || level > 4) return;
        else if(index == s.length() && level == 4){
            res.add(sb.toString());
            return;
        }
        for(int i = 1; i <= 3; i++){
            if(index + i > s.length()) break;
            int num = Integer.valueOf(s.substring(index, index + i));
            if(i == 1 || i==2 && num >=10 && num <=99 || i == 3 && num >= 100 && num <= 255){
                sb.append(num);
                if(level < 3) sb.append(".");
                backtracking(s,res,sb,index+i,level+1);
                if(level < 3) sb.deleteCharAt(sb.length()-1);
                sb.delete(sb.length()-i,sb.length());
            }
        }
    }



//    private static void dfs(String s,List<String> result,String curr,int start,int max,int min) {
//        if (s.length() - start > max || s.length() - start < min) {
//            return;
//        }
//        if (max == 0 && start == s.length()) {
//            result.add(curr.substring(1));
//            return;
//        }
//        if (s.charAt(start) == '0') {
//            dfs(s, result, curr + ".0", start + 1, max - 3, min - 1);
//            return;
//        }
//        for (int i = 0; i < 3; i ++) {
//            if (start + i + 1 <= s.length()) {
//                int tmp = Integer.parseInt(s.substring(start, start + i + 1));
//                if (tmp >=0 && tmp <= 255) {
//                    dfs(s, result, curr + "." + tmp, start + i + 1, max - 3, min - 1);
//                }
//            }
//        }
//
//    }
}

