package elyowon.programers.prgmStudy.special;

import java.util.HashSet;

public class 빙고 {

    public int solution(int[][] board,int[] nums) {

        HashSet hs = new HashSet();
        for (int num : nums) {
            hs.add(num);
        }


        for (int i = 0; i < board.length; i++) {
            int[] ints = board[i];
            for (int j = 0; j < ints.length; j++) {
                if (hs.contains(ints[j])) {
                    ints[j] = 0;
                    hs.remove(ints[j]);
                }
            }
        }

        return correctBingGo(board);
    }

    private int correctBingGo(int[][] board) {

        int result = 0;
        int n = board.length;

        int checkDiagonal = 0;
        int j = 0;
        for (int i = 0; i < board.length; i++) {
            if (board[i][j++] == 0) checkDiagonal++;
            if (checkDiagonal == n) result++;
        }

        j = n - 1;
        checkDiagonal = 0;
        for (int i = 0; i < board.length; i++) {
            if (board[i][j--] == 0) checkDiagonal++;
            if (checkDiagonal == n) result++;
        }

        for (int i = 0; i < n; i++) {
            int checkRow = 0;
            for (int r = 0; r < n; r++) {
                if (board[i][r] == 0) checkRow++;
                if (checkRow == n) result++;
                // System.out.println(checkRow);
            }

            int checkColumn = 0;
            for (int c = 0; c < n; c++) {
                if (board[c][i] == 0) checkColumn++;
                if (checkColumn == n) result++;
            }
        }


        return result;
    }
}