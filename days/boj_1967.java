import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;

public class Main {
    static int n, m;
    static int farNode = 0 , farDist = 0 ;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());

        ArrayList<int[]>[] graph = new ArrayList[n+1];

        for(int i = 0 ; i<=n; i++) graph[i] = new ArrayList<>();

        for(int i = 0 ; i<n-1; i++){
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            graph[e].add(new int[]{s,w});
            graph[s].add(new int[]{e,w});
        }

        boolean[] visited = new boolean[n+1];

        dfs(1, 0 , graph, visited );

        visited = new boolean[n+1];

        farDist = 0;
        dfs(farNode, 0 , graph, visited );
        
        System.out.println(farDist);
    }

    private static void dfs(int u , int dist , ArrayList<int[]>[] graph , boolean[] visited){
        visited[u] = true;

        if( dist > farDist) {
            farDist = dist;
            farNode = u;
        }

        for(int[] edge : graph[u]){
            int v = edge[0];
            int w = edge[1];
            if(!visited[v]){
                dfs(v, dist+w , graph,visited);
            }
        }

    }
}