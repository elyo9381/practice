package me.elyowon.programers;


import java.util.Stack;

/**
 * 2021.06.22
 *
 * 사라진 인형의 갯수 ...
 * 문제를 잘읽자
 */
public class 레벨1_크레인인형 {

    public static void main(String[] args) {
        int[][] board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
        int[] moves = {1,5,3,5,1,2,1,4};

        int solution = solution(board,moves);
        System.out.println("solution = " + solution);
    }

    public static int solution(int[][] board,int[] moves) {
        int answer = 0;
        int row = board.length;
        Stack<Integer> s = new Stack<Integer>();

        for (int i = 0; i < moves.length; i++) {
            int move = moves[i]-1;


            for (int j = 0; j < row; j++) {
                int tmp = board[j][move];
                if (board[j][move] != 0) {

                    if (s.isEmpty()) {
                        s.push(board[j][move]);
                        board[j][move] = 0;
                        break;
                    } else {
                        if (tmp == s.peek()) {
                            s.pop();
                            board[j][move] = 0;
                            answer++;
                            break;
                        }
                        s.push(board[j][move]);
                        board[j][move] = 0;
                        break;
                    }
                }

            }


        }


        return answer;
    }


}
