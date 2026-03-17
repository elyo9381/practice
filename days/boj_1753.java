import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;

public class boj_1753 {

    static int v, e , k;
    static List<int[]>[] graph ;
    static final int INF = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        v = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());

        k = Integer.parseInt(br.readLine());


        ArrayList<int[]>[] g = new ArrayList[v+1];
        graph = g;
        for(int i = 0 ; i<=v; i++){
            graph[i] = new ArrayList<>();
        }
        
        for(int i = 0 ; i< e; i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            graph[u].add(new int[]{v,w});
        }


        // 다익스트라 !
        int[] dist = dijkstra2(v,k);

        StringBuilder sb = new StringBuilder();
        for(int i = 1; i<=v ; i++){
            sb.append(dist[i] == INF ? "INF": dist[i]).append("\n");
        }
        System.out.println(sb);
    }

    private static int[] dijkstra2(int numNodes, int start){
        int[] dist = new int[numNodes+1];
        Arrays.fill(dist,INF);
        dist[start] = 0;

        PriorityQueue<int[]> pq = new PriorityQueue<>( (a,b) -> Integer.compare(a[0],b[0]) );
        pq.offer(new int[]{0,start});

        while(!pq.isEmpty()){
            int[] cur = pq.poll();
            int curDist = cur[0], u =cur[1];

            if( curDist > dist[u]) continue;
            
            for(int[] edge: graph[u]){
                int nv = edge[0], nw = edge[1];
                if(dist[u] != INF && dist[u] + nw < dist[nv]){
                    dist[nv] = dist[u]+nw;
                    pq.offer(new int[]{dist[nv],nv});
                }
            }
        }
        return dist;
    }
}



