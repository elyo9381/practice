package me.elyowon.boj.dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class RGB거리 {

    static int INF = 1000000000;

    static int N;
    static int[][] cost = new int[1000][3];
    static int[][] dp = new int[1001][4];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 3; j++) {
                cost[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        Arrays.stream(dp).forEach(row -> Arrays.fill(row,-1));
        System.out.println(RGB(0,3));
        trackAnswer(0,3);
    }

    private static void trackAnswer(int pos,int prev){
        if( pos == N) return ;
        for(int i =0; i<3; i++){
            if(prev!= i && RGB(pos+1,i) + cost[pos][i] == RGB(pos,prev)){
                System.out.println( RGB(pos+1,i) + cost[pos][i]+" : "+RGB(pos,prev));

                System.out.println(pos+1 + "th town color : " + i);
                trackAnswer(pos+1,i);
                return;
            }
        }
    }

    private static int RGB(int pos,int prev) {
        int ret = dp[pos][prev];

        if (ret != -1) return ret;
        if (pos == N) return ret = 0;

        ret = INF;
        for (int i = 0; i < 3; i++) {
            if (prev != i) ret = Math.min(ret,RGB(pos + 1,i) + cost[pos][i]);
        }
        return ret;
    }

}