package me.elyowon.leetcode.backtracking;


import java.util.ArrayList;
import java.util.List;

public class leetcode_37_sudoku {


    /**
     * @param args
     */

    public static void main(String[] args) {


    }

    public void solveSudoku(char[][] board) {
        solve(board,0,0);
    }

    private boolean solve(char[][] board,int i,int j) {
        if (i == board.length - 1 && j == board[0].length) {
            return true;
        }

        // 행을 검사중에 행이 원소가 마지막일경우 다음행으로 이동
        if (j == board[0].length) {
            i = i + 1;
            j = 0;
        }

        if (board[i][j] == '.') {
            for (int k = 1; k <= 9; k++) {
                board[i][j] = (char) ((int) '0' + k);
                if (valid(board,i,j) == true) {
                    boolean tmp = solve(board,i,j + 1);
                    if (tmp == true) {
                        return true;
                    }
                }
            }
            board[i][j] = '.';
        }
        else { // 빈칸이 아니면 다음 원소를 추가하여 검사
            return solve(board,i,j + 1);
        }

        return false;
    }

    private boolean valid(char[][] board,int x,int y) {
        // 행검사 비트마스크를 통해서 검사 10자리
        int check = 0;
        for (int j = 0; j < board[0].length; j++) {
            int val = board[x][j] - '0';
            if (board[x][j] == '.') {
                continue;
            }
            // 중복수 체크
            if ((check & (1 << (val - 1))) == 1 << (val - 1)) {
                return false;
            } else { //
                check = check | 1 << (val - 1);
            }
        }

        // 열검사
        check = 0;
        for (int i = 0; i < board.length; i++) {
            int val = board[i][y] - '0';
            if (board[i][y] == '.') {
                continue;
            }
            if ((check & (1 << (val - 1))) == 1 << (val - 1)) {
                return false;
            } else {
                check = check | 1 << (val - 1);
            }
        }

        //서브 매트릭스 검사
        int ib = x / 3;
        int jb = y / 3;
        check = 0;
        for (int i = ib * 3; i < (ib + 1) * 3; i++) {
            for (int j = jb * 3; j < (jb + 1) * 3; j++) {
                int val = board[i][j] - '0';
                if (board[i][j] == '.') {
                    continue;
                }
                if ((check & (1 << (val - 1))) == 1 << (val - 1)) {
                    return false;
                } else {
                    check = check | 1 << (val - 1);
                }
            }
        }


        return true;
    }
}