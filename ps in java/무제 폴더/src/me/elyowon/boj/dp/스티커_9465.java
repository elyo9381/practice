package me.elyowon.boj.dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 *
 */
public class 스티커_9465 {

    static int MAX = 100000;
    static int T, N;
    static int[][] dp;
    static int[][] value;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        T = Integer.parseInt(st.nextToken());

        for(int t =0; t<T; t++){
            st = new StringTokenizer(br.readLine());
            N=Integer.parseInt(st.nextToken());
            dp = new int[N][3];
            value = new int[2][N];
            for (int i = 0; i <2; i++) {
                st = new StringTokenizer(br.readLine());
                for(int j = 0 ;j<N; j++){
                    value[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            Arrays.stream(dp).forEach(i -> Arrays.fill(i, -1));
            System.out.println(sticker(0,0));
        }
    }

    private static int sticker(int c,int status) {

        if( c == N) return 0;
        if(dp[c][status] != -1) return dp[c][status];

         dp[c][status] = sticker(c+1,0);
        if(status != 1) dp[c][status] = Math.max(dp[c][status], sticker(c+1,1) + value[0][c]);
        if(status != 2) dp[c][status] = Math.max(dp[c][status], sticker(c+1,2) + value[1][c]);

        return dp[c][status];
    }
}