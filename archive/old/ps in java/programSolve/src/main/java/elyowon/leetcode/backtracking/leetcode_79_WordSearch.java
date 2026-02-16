package elyowon.leetcode.backtracking;


import java.util.ArrayList;
import java.util.List;

public class leetcode_79_WordSearch {


    /**
     * @param args
     */

    public static void main(String[] args) {
        char[][] board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
        String word = "ABCE";
        boolean result = exist(board,word);
        System.out.println(result);

    }

    private static int[][] direction = {{-1,0},{0,-1},{0,1},{1,0}};
    private static int m;
    private static int n;

    public static boolean exist(char[][] board,String word) {
        m = board.length;
        if (m == 0) return false;
        n = board[0].length;
        if (n == 0) return false;
        boolean[][] visited = new boolean[m][n];
        char[] ch = word.toCharArray();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
//                if (backtrack(board,visited,0,ch,i,j)) return true;
                if (backtrack(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
    private static boolean backtrack(char[][] board,String word,int i,int j,int matched) {
        if (matched == word.length()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= board.length || j >= board[0].length || board[i][j] != word.charAt(matched)) {
            return false;
        }
        board[i][j] = '#';
        boolean result = backtrack(board, word, i - 1, j, matched + 1) || backtrack(board, word, i, j - 1, matched + 1) || backtrack(board, word, i + 1, j, matched + 1) ||  backtrack(board, word, i, j + 1, matched + 1);
        board[i][j] = word.charAt(matched);
        return result;

    }

    private static boolean backtrack(char[][] board,boolean[][] visited,int start,char[] ch,int x,int y) {
        if (start == ch.length - 1) return board[x][y] == ch[start];
        if (board[x][y] == ch[start]) {
            visited[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int nx = direction[i][0] + x;
                int ny = direction[i][1] + y;
                if (!inArea(nx,ny) || visited[nx][ny]) continue;
                if (backtrack(board,visited,start + 1,ch,nx,ny)) return true;
            }
            visited[x][y] = false;
        }
        return false;
    }

    private static boolean inArea(int x,int y) {
        return (x >= 0 && y >= 0 && x < m && y < n);
    }
}
