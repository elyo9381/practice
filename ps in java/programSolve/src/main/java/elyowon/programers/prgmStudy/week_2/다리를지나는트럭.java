package elyowon.programers.prgmStudy.week_2;

import java.util.Arrays;
import java.util.LinkedList;


/**
 * 생각해보기 해쉬맵을 이용해서 푸는것과
 * 그냥 솔루션으로 푸는것 무엇이 더 효율적인 것인가.?
 *
 * 정답은 없으나. 본인의 눈에 익숙한 코드가 좋은코드이다. 또한
 * 다른사람눈에도 readability 가 좋은 코드가 분명있다.
 * 
 */
public class 다리를지나는트럭 {
    class Truck{
        int weight;
        int move;

        public Truck(int weight) {
            this.weight = weight;
            this.move = 0;
        }

        public void moving() {move++;}

        public int getWeight() {
            return weight;
        }

        public int getMove() {
            return move;
        }
    }
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        LinkedList<Truck> moveQueue = new LinkedList<>();
        LinkedList<Truck> waitQueue = new LinkedList<>();


        for(int e : truck_weights){
            waitQueue.add(new Truck(e));
        }

        int sumWeight = 0;

        while(!waitQueue.isEmpty() || !moveQueue.isEmpty()){
            answer+=1;

            if(moveQueue.isEmpty()){
                Truck passingTruck = waitQueue.poll();
                sumWeight += passingTruck.weight;
                moveQueue.add(passingTruck);
                continue;
            }

            for (Truck truck : moveQueue) {
                truck.moving();
            }

            if(moveQueue.peek().getMove() >= bridge_length){
                Truck passedTruck = moveQueue.poll();
                sumWeight -= passedTruck.getWeight();
            }

            if(!waitQueue.isEmpty() && sumWeight + waitQueue.peek().getWeight() <= weight){
                Truck passingTruck = waitQueue.poll();
                sumWeight += passingTruck.weight;
                moveQueue.add(passingTruck);
            }
        }

        return answer;
    }
}