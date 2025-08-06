package elyowon.programers.L2;


import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

/**
 *
 */
public class L2_210629_더맵게 {

    public int solution(int[] scoville,int K) {
        int answer = 0;


        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();

        for (int i : scoville) {
            pq.add(i);
        }


        while (pq.peek() < K) {
            if (pq.size() == 1) return -1;
            int firstData = pq.poll();
            int secondData = pq.poll();


            int _scoville = firstData + (secondData * 2);

            pq.add(_scoville);
            answer++;
        }


        return answer;
    }
}