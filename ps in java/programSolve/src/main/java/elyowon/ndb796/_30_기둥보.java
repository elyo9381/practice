package elyowon.ndb796;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/*
input
K1KA5CB7

*/


class Piece implements Comparable<Piece> {
    private int x;
    private int y;
    private int stuff;

    public Piece(int x,int y,int stuff) {
        this.x = x;
        this.y = y;
        this.stuff = stuff;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getStuff() {
        return stuff;
    }

    @Override
    public int compareTo(Piece o) {
        if(this.x == o.x && this.y == o.y){
            return Integer.compare(this.stuff, o.stuff);
        }
        if(this.x == o.x){
            return Integer.compare(this.y,o.y);
        }
        return Integer.compare(this.x,o.x);
    }
}

public class _30_기둥보{

    public static int n = 5;
    public static int[][] build_frame = {{0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},
                                        {1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},
                                        {1,1,1,0},{2,2,0,1}};

    public static void main(String[] args) {
        int[][] solution = solution(n,build_frame);

        for (int i = 0; i < solution.length; i++) {
            System.out.println(solution[i][0] + " " + solution[i][1] + " " + solution[i][2]);
        }

    }

    private static int[][] solution(int n,int[][] build_frame) {

        ArrayList<ArrayList<Integer>> answer = new ArrayList<ArrayList<Integer>>();

        for (int i = 0; i < build_frame.length; i++) {

            int x = build_frame[i][0];
            int y = build_frame[i][1];
            int stuff = build_frame[i][2];
            int operator = build_frame[i][3];

            if(operator == 0){
                int index = 0;
                for (int j = 0; j < answer.size(); j++) {
                    if(x == answer.get(j).get(0) && y == answer.get(j).get(1) && stuff == answer.get(j).get(2)){
                        index = j;
                    }
                }
                ArrayList<Integer> erased = answer.get(index);
                answer.remove(index);
                if(!possible(answer)){
                    answer.add(erased);
                }
            }
            if(operator == 1){
                ArrayList<Integer> inserted = new ArrayList<Integer>();
                inserted.add(x);
                inserted.add(y);
                inserted.add(stuff);
                answer.add(inserted);
                if(!possible(answer)){
                    answer.remove(answer.size()-1);
                }
            }

        }

        ArrayList<Piece> ans = new ArrayList<Piece>();
        for (int i = 0; i < answer.size(); i++) {
            ans.add(new Piece(answer.get(i).get(0),answer.get(i).get(1),answer.get(i).get(2)));
        }

        Collections.sort(ans);

        int[][] res = new int[ans.size()][3];
        for (int i = 0; i < ans.size(); i++) {
            res[i][0] = ans.get(i).getX();
            res[i][1] = ans.get(i).getY();
            res[i][2] = ans.get(i).getStuff();
        }

        return res;
    }

    private static boolean possible(ArrayList<ArrayList<Integer>> answer) {
        for (int i = 0; i <answer.size() ; i++) {
            int x = answer.get(i).get(0);
            int y = answer.get(i).get(1);
            int stuff = answer.get(i).get(2);
            if(stuff == 0){ // 기둥일
                boolean check = false;
                if(y == 0) check = true;
                for (int j = 0; j < answer.size(); j++) {
                    if(x - 1 ==  answer.get(j).get(0) && y == answer.get(j).get(1)  && 1 == answer.get(j).get(2)){
                        check = true;
                    }
                    if(x ==  answer.get(j).get(0) && y == answer.get(j).get(1)  && 1 == answer.get(j).get(2)) {
                        check = true;
                    }
                    if(x==answer.get(j).get(0) &&  y -1 ==  answer.get(j).get(1)  && 0 == answer.get(j).get(2)){
                        check = true;
                    }
                }
                if(!check ) return false;
            }
            else {
                boolean check = false;
                boolean left = false;
                boolean right = false;

                for (int j = 0; j < answer.size(); j++) {
                    if(x == answer.get(j).get(0) &&  y-1  ==  answer.get(j).get(1)  && 0 == answer.get(j).get(2)) {
                        check = true;
                    }
                    if(x+1 == answer.get(j).get(0) &&  y-1  ==  answer.get(j).get(1)  && 0 == answer.get(j).get(2)) {
                        check = true;
                    }
                    if(x-1==answer.get(j).get(0) &&  y  ==  answer.get(j).get(1)  && 1 == answer.get(j).get(2)) {
                        left = true;
                    }
                    if(x+1==answer.get(j).get(0) &&  y  ==  answer.get(j).get(1)  && 1 == answer.get(j).get(2)) {
                        right = true;
                    }

                }
                if(left && right) check =true;
                if(!check) return false;
            }

        }
        return true;
    }




}