package me.elyowon.leetcode.backtracking;


import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.stream.IntStream;

public class leetcode_17_phoneKeypad {


    /**
     * 백트래킹
     * 래퍼런스타입으로 넘길지
     * 밸류타입으로 넘길지에 따라 메모리 해제 등의 코딩스타일이 요구됨
     *
     * @param args
     */

    public static void main(String[] args) {

        String s = "23";

        List<String> result = letterCombinations(s);

        System.out.println(result.size());
        for (String s1 : result) {
            System.out.print(" " + s1);
        }

    }

    private static List<String> letterCombinations(String digits) {

        HashMap<Character, String> keyboard = new HashMap<Character, String>();
        initKeyboard(keyboard);
        List<String> result = new LinkedList<String>();
        if(digits.length() == 0) {
            return result;
        }

        backTracking(digits, "" , 0, keyboard, result);
        return result;
    }

    private static void backTracking(String digits, String prefix, int start, HashMap<Character, String> keyboard,List<String> result) {
        if(start == digits.length()){
            result.add(prefix);
            return;
        }

        String cand = keyboard.get(digits.charAt(start));
        IntStream.range(0,cand.length()).forEach(i -> backTracking(digits,prefix + cand.charAt(i),start + 1,keyboard,result));

    }

    private static void initKeyboard(HashMap<Character, String> keyboard) {
        keyboard.put('2', "abc");
        keyboard.put('3', "def");
        keyboard.put('4', "ghi");
        keyboard.put('5', "jkl");
        keyboard.put('6', "mno");
        keyboard.put('7', "pqrs");
        keyboard.put('8', "tuv");
        keyboard.put('9', "wxyz");
    }

}



