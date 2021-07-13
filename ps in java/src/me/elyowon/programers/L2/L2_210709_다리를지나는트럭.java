package me.elyowon.programers.L2;


import java.util.HashMap;
import java.util.LinkedList;
import java.util.Stack;

/**
 *
 */
public class L2_210709_다리를지나는트럭 {

    public static void main(String[] args) {
        int solution = solution(2,10,new int[]{7,4,5,6});

        System.out.println("solution = " + solution);



    }




    public static int solution(int bridge_length,int weight,int[] truck_weights) {
        int time = 0;

        LinkedList<Integer> q = new LinkedList<Integer>();

        int max = 0;

        for (int w : truck_weights) {

            while (true) {
                if (q.isEmpty()) {
                    q.offer(w);
                    max += w;
                    time++;
                    break;
                } else if (q.size() == bridge_length) {
                    max -= q.poll();
                } else {
                    if (max + w > weight) {
                        q.offer(0);
                        time++;
                    } else {
                        q.offer(w);
                        max += w;
                        time++;
                        break;
                    }
                }
            }
        }
        return time + bridge_length;
    }

    static class Truck {
        int weight;
        int move;

        public Truck(int wight) {
            this.weight = wight;
            this.move = 1;
        }

        public void moving() {
            move++;
        }
    }

    public static int solution1(int bridge_length,int weight,int[] truck_weights) {

        LinkedList<Truck> moveQ = new LinkedList<>();
        LinkedList<Truck> waitQ = new LinkedList<>();

        for (int e : truck_weights) {
            waitQ.add(new Truck(e));
        }

        int answer = 0;
        int totalWeight = 0;

        while (!waitQ.isEmpty() || !moveQ.isEmpty()) {
            answer += 1;

            if (moveQ.isEmpty()) {
                Truck t = waitQ.poll();
                totalWeight += t.weight;
                moveQ.add(t);
            }

            for (Truck t : moveQ) {
                t.moving();
            }

            if (moveQ.peek().move > bridge_length) {
                Truck t = moveQ.poll();
                totalWeight -= t.weight;
            }

            if (!waitQ.isEmpty() && totalWeight + waitQ.peek().weight <= weight) {
                Truck t = waitQ.poll();
                totalWeight += t.weight;
                moveQ.add(t);
            }
        }
        return answer;
    }


    public static int solution3(int bridge_length,int weight,int[] truck_weights) {

        Stack<Integer> truckStack = new Stack<>();
        HashMap<Object, Object> bridgeMap = new HashMap<>();

        for (int i = truck_weights.length - 1; i >= 0; i--) {
            truckStack.push(truck_weights[i]);
        }

        int answer = 0;
        int sum = 0;

        while (true) {
            answer++;


            if (bridgeMap.get(answer) != null) {
                sum -= (int) bridgeMap.get(answer);
                bridgeMap.remove(answer);
            }

            // 불필요한 루프
//          sum = bridgeMap.values().stream().mapToInt(i -> (int) i).sum();

            if (!truckStack.isEmpty()) {
                if (sum + truckStack.peek() <= weight) {
                    int num = truckStack.pop();
                    bridgeMap.put(answer + bridge_length,num);
                    sum += num;
                }
            }

            if (bridgeMap.isEmpty() && truckStack.isEmpty()) {
                break;
            }
        }

        return answer;
    }
}