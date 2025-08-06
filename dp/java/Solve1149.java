import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.*;

/**
 * https://www.acmicpc.net/problem/1149
 */


public class Solve1149 {

    static int N ;
    static int[][] dp;
    static int[][] board;

    public void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        dp = new int[N+1][3];
        board = new int[N+1][N+1];

        for(int i = 0 ; i< N ; i++){
             StringTokenizer st1 = new StringTokenizer(br.readLine());
            for(int j  = 0 ; j< N ;j++){
                board[i][j] = Integer.parseInt(st1.nextToken());
            }
        }
        
        dp[0][0] = board[0][0];
        dp[0][1] = board[0][1];
        dp[0][2] = board[0][2];

        for(int i = 1 ; i<=N ; i++){
            dp[i][0] =  Math.min(dp[i-1][1], dp[i-1][2]) + board[i][0];
            dp[i][1] =  Math.min(dp[i-1][0], dp[i-1][2]) + board[i][1];
            dp[i][2] =  Math.min(dp[i-1][1], dp[i-1][0]) + board[i][2];
        }



    }
}
