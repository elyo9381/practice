package me.elyowon.programers;


import java.util.LinkedList;

/**
 */
public class L1_210625_다트게임 {

    public static void main(String[] args) {
        String s = "1S2D*3T*";
        int solution = solution(s);
        System.out.println(solution);
    }

    public static int solution(String dartResult) {
        int answer = 0;

        int prev = 0;
        boolean bisPrevNum = false;

        LinkedList<Integer> list = new LinkedList<>();
        for (int i = 0; i < dartResult.length(); i++) {
            int c = dartResult.charAt(i);


            int num = 0;
            if (c >= '0' && c <= '9') {
                num = c - '0';
                if (bisPrevNum) {
                    prev = prev * 10 + num;
                    continue;
                }
                prev = num;
                bisPrevNum = true;
            } else {
                bisPrevNum = false;
                if (c == 'S') {
                    list.add((int) Math.pow(prev,1));
                } else if (c == 'D') {
                    list.add((int) Math.pow(prev,2));
                } else if (c == 'T') {
                    list.add((int) Math.pow(prev,3));
                } else if (c == '#') {
                    if (list.isEmpty()) continue;
                    Integer last = list.getLast() * -1;
                    list.pollLast();
                    list.add(last);
                } else if (c == '*') {
                    if (list.isEmpty()) continue;
                    if (list.size() >= 2) {
                        Integer tmp1 = list.pollLast();
                        int now = tmp1 * 2;

                        Integer tmp2 = list.pollLast();
                        int previous = tmp2 * 2;

                        list.add(previous);
                        list.add(now);
                    } else if (list.size() == 1) {
                        Integer tmp1 = list.pollLast();
                        int now = tmp1 * 2;
                        list.add(now);
                    }
                }
                prev = 0;
            }
        }

        while (!list.isEmpty()) {
            answer += list.poll();
        }

        return answer;
    }
}

