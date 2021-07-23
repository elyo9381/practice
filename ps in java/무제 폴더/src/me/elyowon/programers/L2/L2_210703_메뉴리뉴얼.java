package me.elyowon.programers.L2;


import java.util.*;

/**
 * 수량 별 갯수의 조합을 구현한다.
 * 그리고 각 조합의 최대 max를 확인하고 비교하여 최대로 주문된 조합을 우선순위큐에 넣는다.
 * 우선순위큐는 솔트를 하기위한 편법이다.
 */
public class L2_210703_메뉴리뉴얼 {

    
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
