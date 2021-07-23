package elyowon.leetcode.Queue;


import java.util.Comparator;
import java.util.PriorityQueue;

public class leetcode_MaxQueue {

    /**
     *
     */


    public static void main(String[] args) {
        String[] ops = {"I 16","I -5643","D -1","D 1","D 1","I 123","D -1"};
        int[] result = new leetcode_MaxQueue().solution(ops);

        for (int i : result) {
            System.out.println("i = " + i);
        }
    }

    private int[] solution(String[] ops) {

        int[] answer = {};

        PriorityQueue<Integer> maxQueue = new PriorityQueue<>(Comparator.reverseOrder());
        PriorityQueue<Integer> minQueue = new PriorityQueue<>();

        for (String op : ops) {
            String[] split = op.split(" ");
            String operation = split[0];
            int value = Integer.parseInt(split[1]);

            if (operation.equals("I")) {
                maxQueue.add(value);
                minQueue.add(value);
            } else {
                if (maxQueue.isEmpty() || minQueue.isEmpty())
                    continue;
                if (value == 1) {
                    int max = maxQueue.poll();
                    minQueue.remove(max);
                } else {
                    int min = minQueue.poll();
                    maxQueue.remove(min);
                }
            }
        }

        if (maxQueue.isEmpty()) {
            answer = new int[]{0,0};
        } else {
            answer = new int[]{maxQueue.peek(),minQueue.peek()};
        }
        return answer;
    }

}
