package me.elyowon.programers.L2;


import java.util.*;

/**
 *
 */
public class L2_210704_네이버웹툰 {

    //abcxyasdfasdfxyabc
    public static void main(String[] args) {
        String s = "aabcbcd";
        String t = "abc";
//        int i = solution3(s,t);
        String[] strings = solution2("abcxyasdfasdfxyabc");
        for (String string : strings) {
            System.out.println("string = " + string);
        }
    }

    public static String[] solution2(String s) {
        List<String> list = new ArrayList<>();
        String[] answer = {};
        int start = 0;
        int size = s.length();
        for(int i = 1; i < size; i++) {
            if(s.substring(start, i).equals(s.substring(size-i))) {
                list.add(s.substring(start, i));
                s = s.substring(i, size-i);
                i=0;
                size = s.length();
            }
        }
        if(s.length() != 0) {
            answer = new String[list.size()*2+1];
            answer[list.size()] = s;
        }else {
            answer = new String[list.size()*2];
        }
        for(int i = 0; i < list.size(); i++) {
            answer[i] = list.get(i);
        }
        for(int i = 0; i < list.size(); i++) {
            answer[i+(answer.length+1)/2] = list.get(list.size()-i-1);
        }
        return answer;
    }

    public static int solution3(String s,String t) {
        int result = -1;

        Stack<String> stack = new Stack<String>();


        for (int i = 0; i < s.length(); i++) {
            stack.add(s.substring(i,i + 1));

            if (isFindTarget(stack,t)) {
                int idx = t.length();
                while (idx >= 1) {
                    stack.pop();
                    idx--;
                }
                result++;
            }
        }
        return result;
    }


    public static boolean isFindTarget(Stack<String> stack,String target) {
        if (stack.size() < target.length()) return false;

        Stack<String> s = new Stack<>();
        s = (Stack<String>) stack.clone();

        int targetSize = target.length();

        String str = "";
        for (int i = 0; i < targetSize; i++) {
            str += s.pop();

        }
        StringBuilder sb = new StringBuilder();
        sb.append(str);


        String temp = sb.reverse().toString();
        System.out.println("stackSize = " + temp);
        if (temp.equals(target)) return true;

        return false;
    }


    public int solution1(int[] prices, int[] discounts) {
        int answer = 0;


        ArrayList<Integer> priceList = new ArrayList<Integer>();
        for (int price : prices) {
            priceList.add(price);
        }
        ArrayList<Integer> discountList = new ArrayList<Integer>();
        for (int num : discounts) {
            discountList.add( num);
        }

        priceList.sort(Collections.reverseOrder());
        discountList.sort(Collections.reverseOrder());

        int i = 0;
        for (; i < discountList.size(); i++) {
            answer += priceList.get(i) * (discountList.get(i) / 100);

            System.out.println(" 가격 "+ priceList.get(i));
        }

        for(; i< priceList.size(); i++){
            answer += priceList.get(i);
        }


        return answer;
    }
}
