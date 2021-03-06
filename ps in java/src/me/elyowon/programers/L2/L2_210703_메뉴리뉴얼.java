package me.elyowon.programers.L2;


import java.util.*;

/**
 * 수량 별 갯수의 조합을 구현한다.
 * 그리고 각 조합의 최대 max를 확인하고 비교하여 최대로 주문된 조합을 우선순위큐에 넣는다.
 * 우선순위큐는 솔트를 하기위한 편법이다.
 */
public class L2_210703_메뉴리뉴얼 {

    //abcxyasdfasdfxyabc
    public static void main(String[] args) {
        String s = "aabcbcd";
        String t = "abc";
        int i = solution3(s,t);
    }

    public String[] solution2(String s) {
        String[] answer = {};
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

    int max = 0;
    HashMap<String,Integer> hm ;
    public String[] solution(String[] orders,int[] course) {
        String[] answer = {};

        PriorityQueue<String> pq = new PriorityQueue<>();

        for (int i : course) {
            hm = new HashMap<>();
            max = 0;
            for (String order : orders) {
                StringBuilder sb =new StringBuilder();
                char[] chars = order.toCharArray();
                comb(chars,i,0,sb);
            }

            for (String s : hm.keySet()) {
                if(hm.get(s) == max && max > 1){
                    pq.offer(s);
                }
            }
        }
        answer = new String[pq.size()];
        int idx = 0;
        while(!pq.isEmpty()){
            answer[idx++] =  pq.poll();
        }

        return answer;
    }

    private void comb(char[] chars,int target,int j ,StringBuilder builder) {
        if( target == 0 ){
            char[] temp = builder.toString().toCharArray();
            Arrays.sort(temp);
            String s ="";
            for (int i = 0; i < temp.length; i++) {
                s+=temp[i];
            }
            hm.put(s,hm.getOrDefault(s,0) +1);
            max = Math.max(max, hm.get(s));
            return ;
        }


        for (int i = j; i < chars.length; i++) {
            builder.append(chars[i]);
            comb(chars, target -1, i+1, builder);
            builder.deleteCharAt(builder.length() - 1);
        }
    }


}
