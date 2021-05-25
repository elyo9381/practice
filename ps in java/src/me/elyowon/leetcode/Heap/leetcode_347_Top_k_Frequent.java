package me.elyowon.leetcode.Heap;


import java.util.*;

public class leetcode_347_Top_k_Frequent {

    /**
     *   기본읜 최소힙이다.
     *
     *     최대힙 구성
     *     PriorityQueue<Integer> pq =
     *     new PriorityQueue<>(1000000, Collections.reverseOrder());
     *
     *
     *     HashMap에서 탐색
     *     key.set() :  키탐색
     *     values.forEach(value -> System.out.println(value)); : 밸류탐색
     *     Set<Map.Entry<String, Double>> entries = productPrice.entrySet(); : 키,밸류 탐
     *
     *     // 비교
     *     (e1,e2) -> {return map.get(e1).compareTo(map.get(e2));}
     *     e1.compareTo(e2) : e1이 e2보다 작으면 오름차순 반대이면 내림차순
     *     e1 - e2  < 0 이면 오름차순 ==0 이면 같고 >0 이면 내림차
     *     // 오름차순 가정할때
     *     // 현재 객체가 target 보다 작은 수 라면 -1
     *     // 큰 수라면 1
     *     // 동일하다면 0을 반환
     *
     *
     *
     *
     */

    public static void main(String[] args) {

        int[] nums = {1,3,5,3,9,3,7,5};
        int k = 2;

        HashMap<Integer, Integer> map = new HashMap<>();

        for (int num : nums) {
            map.put(num, map.getOrDefault(num,0)+1);
        }

        PriorityQueue<Integer> minHeap = new PriorityQueue<>(k,(e1,e2) -> map.get(e1).compareTo(map.get(e2)));
        for (Integer num : map.keySet()) {
            minHeap.offer(num);
            if(minHeap.size() > k){
                minHeap.poll();
            }
        }

        ArrayList<Integer> result = new ArrayList<>(minHeap);

        for (Integer integer : result) {
            System.out.println("integer = " + integer);
        }

    }

}
