package me.elyowon.programers.prgmStudy.week_1;


import java.util.*;

/**
 * 요구사항 학생을 추가할수있음 ( 찍기 배열도 마찬가지)
 */
public class 모의고사 {

    class Student {
        int[] randomPick;
        int randomPickPattenSize;

        Student(int[] randomPick,int randomPickPattenSize) {
            this.randomPick = randomPick;
            this.randomPickPattenSize = randomPickPattenSize;
        }

        public Integer checkPatten(int[] answers,int idx){
            HashMap<Integer,Integer> hs = new HashMap<>();
            for(int i =0 ; i<answers.length; i++){
                if(answers[i] == randomPick[i%randomPickPattenSize]) hs.put(idx,hs.getOrDefault(idx,0)+1);
            }
            Integer result = hs.get(idx);
            return (result == null) ? 0 : result;
        }

    }

    private ArrayList<Student> init(){
        ArrayList<Student> students = new ArrayList<>();
        students.add(new Student(new int[]{1,2,3,4,5},5));
        students.add(new Student(new int[]{2,1,2,3,2,4,2,5},8));
        students.add(new Student(new int[]{3,3,1,1,2,2,4,4,5,5},10));
        return students;
    }


    public int[] solution(int[] answers) {

        ArrayList<Student> students = init();
        HashMap<Integer,Integer> hs = new HashMap<>();


        for (int idx = 0; idx <students.size(); idx++) {

            Integer value = students.get(idx).checkPatten(answers,idx + 1);
            hs.put(idx+1,value);
//            for(int i =0 ; i<answers.length; i++){
//                int pattensize = students.get(idx).getRandomPickPattenSize();
//                if(answers[i] == students.get(idx).randomPick[i%pattensize]) hs.put(idx+1,hs.getOrDefault(idx+1,0)+1);
//            }
        }

        List<Map.Entry<Integer,Integer>> list = new LinkedList<>(hs.entrySet());
        int max = list.stream().mapToInt(i->i.getValue()).max().getAsInt();

        return list.stream().filter(v -> v.getValue() == max).mapToInt(v -> v.getKey()).toArray();
    }
}