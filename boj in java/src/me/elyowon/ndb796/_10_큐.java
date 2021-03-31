package me.elyowon.ndb796;

import java.util.LinkedList;

public class _10_큐 {

    /**
     * q.offer() 값넣고 큐가 다찼다면 IllegalSataeException반환
     * q.poll() 삭제한값 반환 없으면 null 반환
     * q.peek() 첫번째 값 참조
     *
     * */
    public static void main(String[] args) {
        LinkedList<Integer> q = new LinkedList<>();

        q.offer(5);
        q.poll();

        while(!q.isEmpty()){
            System.out.println(q.poll());
        }
    }
}