package me.elyowon.leetcode.Heap;


import java.util.PriorityQueue;
import java.util.Stack;

public class leetcode__Heap {

    /**
     *
     * 주어진 배열에서 k번째로 큰 수를 리턴하라
     * maxheap을 통해서 k번째 pop을 통해서 구할수있다.
     * 이는 매우큰 공간복잡도를 가진다 왜냐? k에 따라서 공간이 늘어날수있는 가능성이 존재한다.
     *
     * 그렇기 때문에 minheap을 통해서 k개의 공간을 할당하고
     * minheap의 size가 k를 넘긴다면 삭제후 다시 추가하는 방법을 통해서
     * 100만의 K가 주어진다고 하여도 이를 빠른 시간과 복잡도로 컨트롤 가능하다.
     *
     */

    public static void main(String[] args) {

        int[] nums = {1,3,5,7,8,9,11,13};

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int num : nums) {
            pq.add(num);
            if(3 < pq.size()){
                pq.poll();
            }
        }
    }

}
