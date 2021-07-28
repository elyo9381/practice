package elyowon.programers.prgmStudy.week_3;

import java.util.PriorityQueue;

public class 더맵게 {
    public int solution(int[] scoville,int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int e : scoville) {
            pq.add(e);
        }

        int count = 0;
        while (pq.peek() < k) {
            if (pq.size() < 2) return -1;
            count++;
            int firstScoville = pq.poll();
            int secondScoville = pq.poll();
            int newScoville = firstScoville + (secondScoville * 2);

            pq.add(newScoville);
        }
        return count;
    }
}