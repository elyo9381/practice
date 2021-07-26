package elyowon.boj.dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.stream.IntStream;

/**
 *
 * 8
 * 1 2
 * 1 3
 * 1 4
 * 2 5
 * 2 6
 * 4 7
 * 4 8
 */
public class 사회망서비스_2533 {

    static ArrayList<Integer>[] adj;
    static ArrayList<Integer>[] child;
    static boolean[] visited;
    static int N;
    static int[][] dp;
    static int INF = (int) 1e9;
    private static boolean[][] picked;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        adj = new ArrayList[N + 2];
        child = new ArrayList[N + 2];
        dp = new int[N + 2][2];
        picked = new boolean[N + 2][2];
        visited = new boolean[N + 2];

        IntStream.range(0,N + 2).forEach(i -> adj[i] = new ArrayList<>());
        IntStream.range(0,N + 2).forEach(i -> child[i] = new ArrayList<>());
        Arrays.stream(dp).forEach(ints -> Arrays.fill(ints,-1));


        for (int i = 0; i < N; i++) {
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
        trackAnswer(1,1);

        for(int i =0; i<N+1; i++){
//            if(picked[i][0]) System.out.println("i = " + i);
//            if(picked[i][1]) System.out.println("i = " + i);
        }

    }

    private static int SNS(int curr,int pe) {
        int ret = dp[curr][pe];
        if (ret != -1) return ret;

        int notPick = INF, pick = 1;
        for (int next : child[curr])
            pick += SNS(next,1);

        if (pe == 1) {
            notPick = 0;
            for (int next : child[curr])
                notPick += SNS(next,0);
        }
        picked[curr][pe] = (pick < notPick);
        return dp[curr][pe] = Math.min(notPick,pick);
    }

    private static void dfs(int curr) {
        visited[curr] = true;

        for (int next : adj[curr]) {
            if (!visited[next]) {
                child[curr].add(next);
                dfs(next);
            }
        }
    }

    static void trackAnswer(int curr,int pe) {
        int notPick = INF, pick = 1;
        for (Integer next : child[curr]) {
            pick += SNS(next,1);
        }

        if (pe == 1) {
            notPick = 0;
            for (Integer next : child[curr]) {
                notPick += SNS(next,0);
            }
        }
        if (pick < notPick) {
            System.out.println(" " + (curr));
            for (Integer next : child[curr]) {
                trackAnswer(next,1);
            }
        } else {
            for (Integer next : child[curr]) {
                trackAnswer(next,0);
            }
        }
    }
}

//8
//1 3
//2 3
//3 4
//4 5
//4 6
//4 7
//7 8
//7 9