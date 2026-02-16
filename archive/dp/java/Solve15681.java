import java.io.*;
import java.util.*;

public class Solve15681 {

    static int n, r, q;
    static ArrayList<Integer>[] adj;
    static int queries[];
    static int dp[];

    public static void main(String[] args)throws IOException{


        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());
        q = Integer.parseInt(st.nextToken());

        adj = new ArrayList[n + 1];
        dp = new int[n + 1];
        queries = new int[q];

        for(int i = 0; i<=n ;i++){
            adj[i] = new ArraysList<>();
        }

        for(int i =0 ; i < n-1 ; i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            adj[u].add(v);
            adj[v].add(u);
        }

        for(int i = 0 ; i<q; i++){
            queries[i] = Integer.parseInt(br.readLine());
        }


        dfs(r,-1);
        for(int i = 0; i < q; i++){
            System.out.println(dp[queries[i]]);
        }
    }

    static void dfs(int node , int parent){
        dp[node] = 1;

        for(int child : adj[node]){
            if( child == parent) continue;
            dfs(child, node);
            dp[node] += dp[child];
        }
    }
}