package me.elyowon.programers.L1;


import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.stream.Collectors;

/**
 * 2021.06.22
 */
public class 레벨1_실패율 {


    public int[] solution1(int N, int [] stages) {
        List<Integer> list = new ArrayList<>();
        HashMap<Integer, Double> hash = new HashMap<>();
        int people = stages.length;
        for(int i = 1 ; i<= N; i++)
            hash.put(i, 0d);
        for(int stage : stages) {
            double tmp = hash.get(stage)+1;
            hash.replace(stage, tmp);
        }
        for(int i = 1; i<= N; i++) {
            double tmp = hash.get(i);
            if(people != 0)
                hash.replace(i, tmp/people);
            list.add(i);
            people-=tmp;
        }
        Collections.sort(list, (o1, o2) -> {
            Double v1 = hash.get(o1);
            Double v2 = hash.get(o2);
            return (v2).compareTo(v1);
        });
        return list.stream().mapToInt(value -> value).toArray();
    }

    public int[] solution(int N,int[] lastStages) {
        int nPlayers = lastStages.length;
        int[] nStagePlayers = new int[N + 2];
        for (int stage : lastStages) {
            nStagePlayers[stage] += 1;
        }

        int remainingPlayers = nPlayers;
        List<Stage> stages = new ArrayList<>();
        for (int id = 1; id <= N; id++) {
            double failure = (double) nStagePlayers[id] / remainingPlayers;
            remainingPlayers -= nStagePlayers[id];

            Stage s = new Stage(id,failure);
            stages.add(s);
        }

        stages.sort(Collections.reverseOrder());

        int[] answer = new int[N];
        for (int i = 0; i < N; i++) {
            answer[i] = stages.get(i).id;
        }
        return answer;
    }

    class Stage implements Comparable<Stage> {
        public int id;
        public double failure;

        public Stage(int id_,double failure_) {
            id = id_;
            failure = failure_;
        }

        @Override
        public int compareTo(Stage o) {
            if (failure < o.failure) {
                return -1;
            }
            if (failure > o.failure) {
                return 1;
            }
            return 0;
        }
    }

}

