package me.elyowon.leetcode.backtracking;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class leetcode_51_NQueens {



    /**
     *
     * 백트래킹으로 모든 퀸의 경우 체크
     *
     * 유효성을 체크해야한다. ? > 어떻게 ? 해쉬셋 & 각 행 열 대각선을 타면서
     *
     * 알고리즘은
     * 유효성을 체크하고 퀸을 놓을수있다면 백트레킹으로 경우의 수를 확인한다.
     *
     * 주의할점 stringbuilder 그리고 return 형을 주의하자.
     *
     * @param args
     */

    public static void main(String[] args) {

        List<List<String>> result = solveNQueens(4);


        for (List<String> strings : result) {
            for (String string : strings) {
                System.out.println(string);
            }
            System.out.println();
        }

    }

    static List<List<String>> answer = new ArrayList<>();
    static ArrayList<String> buffer = new ArrayList<>();
    static int[][] directions = {
            {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}
    };

    public static List<List<String>> solveNQueens(int n){
        char[][] check  = new char[n][n];
        for(int  i = 0; i<check.length; i++){
            Arrays.fill(check[i],'.');
        }
        queens(check,0);

        return answer;
    }

    private static void queens(char[][] check,int row) {

        if(check.length == row){
            ArrayList<String> temp = new ArrayList<>(buffer);
            answer.add(temp);
            return;
        }

        for (int i = 0; i <check.length; i++) {
            if(isGood(check,row,i)){
                check[row][i] = 'Q';
                StringBuilder temp = new StringBuilder("");
                for (int j = 0; j < check.length; j++) {
                    temp.append('.');
                }
                temp.setCharAt(i,'Q');
                buffer.add(temp.toString());
                queens(check, row+1);
                buffer.remove(row);
                check[row][i]='.';
            }
        }
    }

    private static boolean isGood(char[][] check,int x,int y) {
        for(int[] direction : directions){
            if(!isOk(check,x+direction[0],y+direction[1],direction)){
                return false;
            }
        }
        return true;
    }

    private static boolean isOk(char[][] check,int x,int y,int[] direction) {
        if(x < 0 || y < 0) return true;
        if(x >= check.length || y >= check[0].length) return true;
        if(check[x][y] =='Q') return false;
        return isOk(check,x + direction[0], y + direction[1], direction);
    }
}
