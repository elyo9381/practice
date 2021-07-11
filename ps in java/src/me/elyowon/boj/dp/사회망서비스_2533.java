package me.elyowon.boj.dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.stream.IntStream;

public class 사회망서비스_2533 {

    static ArrayList<Integer>[] adj ;
    static ArrayList<Integer>[] child ;
    static boolean[] visited;
    static int N;
    static int[][] dp;
    static int INF = (int) 1e9;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        adj = new ArrayList[N+1];
        child = new ArrayList[N+1];
        dp = new int[N+1][2];
        visited = new boolean[N+1];

        IntStream.range(0,N+1).forEach(i -> adj[i] = new ArrayList<>());
        IntStream.range(0,N+1).forEach(i -> child[i] = new ArrayList<>());
        Arrays.stream(dp).forEach(ints -> Arrays.fill(ints,-1));



        for(int i =0; i< N-1; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
//            u--; v--;

            adj[u].add(v);
            adj[v].add(u);
        }


        dfs(1);
        for (ArrayList<Integer> arrayList : child) {
            System.out.println("arrayList = " + arrayList);
        }

        System.out.println(SNS(1,1));


    }

    private static int SNS(int curr,int pe) {
        int ret = dp[curr][pe];
        if(ret != -1) return ret;

        int notPick = INF, pick = 1;
        for(int next : child[curr])
            pick += SNS(next, 1);

        if(pe == 1){
            notPick = 0;
            for(int next : child[curr])
                notPick += SNS(next,0);
        }
        return ret = Math.min(notPick,pick);
    }

    private static void dfs(int curr) {
        visited[curr] = true;

        for(int next : adj[curr]){
            if(!visited[next]){
                child[curr].add(next);
                dfs(next);
            }
        }
    }

    void trackAnsewr(int curr, int pe){
        int notPick = INF, pick = 1;
        for (Integer next : child[curr]) {
            pick += SNS(next,1);
        }

        if(pe == 1){
            notPick = 0;
            for (Integer next : child[curr]) {
                notPick += SNS(next,0);
            }
        }
        if(pick < notPick){
            System.out.println(" " + curr+1);
            for (Integer next : child[curr]) {
                trackAnsewr(next,1);
            }
        } else {
            for (Integer next : child[curr]) {
                trackAnsewr(next,0);
            }
        }
    }
}