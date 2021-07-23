
package elyowon.leetcode.greedy;


import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.stream.IntStream;

/**
 *
 */

public class leetcode__MeetingRooms {


    public static void main(String[] args) {
        int[][] meetings = {{9,11},{9,12},{10,14},{12,16},{13,16},{15,17}};

        int result = meetingRooms(meetings);

        System.out.println(result);
    }

    public static int meetingRooms(int[][] meetings) {

        if (meetings.length == 0) return 0;

        Arrays.sort(meetings,(a,b) -> a[0] - b[0]); // 내림 차순으로 진행



        // 우선순위큐 기본의 최소힙, reverse하면 최대힙
        PriorityQueue<Integer> minHeap = new PriorityQueue<>((a,b) -> a - b);


        int roomCount = 0;

        for (int[] meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];

            if (minHeap.isEmpty()) {
                roomCount++;
                minHeap.add(meeting[1]);
            } else {
                if (minHeap.peek() <= start) {
                    minHeap.poll();
                    minHeap.add(end);
                } else {
                    minHeap.add(end);
                    roomCount += 1;
                }
            }
        }
        return roomCount;
    }
}