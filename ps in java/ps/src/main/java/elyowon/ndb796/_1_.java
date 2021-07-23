package elyowon.ndb796;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

import static java.lang.System.exit;
import static java.lang.System.in;

public class _1_ {

    public static ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();
    public static boolean ch[] = new boolean[30];
    public static int t[] = new int[30];
    public static int p[] = new int[101];


    static int n;
    static int res = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());

        for (int i = 0; i <n; i++) {
        st = new StringTokenizer(br.readLine());
            int a;
            int b;

            a = Integer.parseInt((st.nextToken()));
            b = Integer.parseInt((st.nextToken()));
            t[i] = a;
            p[i] = b;

        }


        dfs(0,0);
        System.out.println(res);

    }

    private static void dfs(int idx,int sum) {

        if (idx == n) {
            if (sum > res) res = sum;
        } else {
            if (idx + t[idx] <= n + 1) dfs(idx + t[idx],sum + p[idx]);
            dfs(idx + 1,sum);
        }
    }
}


//7
//4 20
//2 10
//3 15
//3 20
//2 30
//2 20
//1 10
