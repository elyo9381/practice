package me.elyowon.programers.L2;


import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

/**
 */
public class L2_210702_행렬테두리회전하기 {

    public static void main(String[] args) {
        int[][] a ={{2,2,5,4}} ;
        int[] solution = solution(6,6,a);
        for (int i : solution) {
            System.out.print(" "  + i);
        }
    }

    public static int[] solution(int rows,int columns,int[][] queries) {
        int[] answer = {};

        int[][] board = new int[rows+1][columns+1];
        int idx = 1;
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= columns; j++) {
                board[i][j] = idx++;
            }
        }

        ArrayList<Integer> minValueList= new ArrayList<>();
        for (int[] query : queries) {
            ArrayList<Integer> list = new ArrayList<>();
            int sx = query[0];
            int sy = query[1];
            int ex = query[2];
            int ey = query[3];

            int temp = board[sx][sy];

            for (int i = sx; i < ex; i++) {
                board[i][sy] = board[i+1][sy];
                list.add(board[i][sy]);
            }

            for (int i = sy; i < ey; i++) {
                board[ex][i] = board[ex][i+1];
                list.add(board[ex][i]);
            }
            for (int i = ex; i > sx; i--) {
                board[i][ey] = board[i-1][ey];
                list.add(board[i][ey]);
            }

            for (int i = ey ; i > sy; i--) {
                board[sx][i] = board[sx][i-1];
                list.add(board[sx][i]);
            }

            board[sx][sy+1] = temp;
            list.add(temp);
            Collections.sort(list);
            minValueList.add(list.get(0));

            for (int i = 1; i <= rows; i++) {
                for (int j = 1; j <= columns; j++) {
                    System.out.print(board[i][j] + " ");
                }
                System.out.println();
            }
            System.out.println();
        }

        return minValueList.stream().mapToInt(i-> i).toArray();
    }

}
