package elyowon.programers.prgmStudy.week_1;


import java.util.*;
import java.util.stream.IntStream;
import java.util.stream.Stream;

/**
 * 요구사항 학생을 추가할수있음 ( 찍기 배열도 마찬가지)
 */
public class 모의고사 {

    class Student {
        int[] randomPick;
        int correct;
        int studentNumber;

        public int getCorrect() {
            return correct;
        }

        public int getStudentNumber() {
            return studentNumber;
        }

        Student(int[] randomPick,int number) {
            this.randomPick = randomPick;
            this.studentNumber = number;
        }

        private void checkPatten(int[] answers) {

            int count = 0;
            for (int i = 0; i < answers.length; i++) {
                if (answers[i] == randomPick[i % randomPick.length]){
                    count++;
                }
            }
            this.correct = count;
            return;
        }

    }

    private ArrayList<Student> init() {

        int[][] initStudents = {
                {1,2,3,4,5},
                {2,1,2,3,2,4,2,5},
                {3,3,1,1,2,2,4,4,5,5}
        };

        ArrayList<Student> students = new ArrayList<>();
        for(int i =0; i<initStudents.length; i++){
            students.add(new Student(initStudents[i],i+1));
        }
        return students;
    }


    public int[] solution(int[] answers) {

        ArrayList<Student> students = init();

        IntStream.range(0,students.size()).forEach(idx -> students.get(idx).checkPatten(answers));

        int max = students.stream().mapToInt(student -> student.getCorrect()).max().getAsInt();

        return students.stream().filter(student -> student.getCorrect() == max)
                .mapToInt(student -> student.getStudentNumber()).toArray();

    }
}