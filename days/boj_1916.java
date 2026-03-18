import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;

public class boj_1916 {
    static int n, m;
    static ArrayList<int[]>[] q ;
    static int INF = 987654321;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());

        q = new ArrayList[n+1];
        
        for(int i = 0 ; i<=n ;i++){
            q[i] = new ArrayList<>();
        }

        for(int i = 0 ; i<m; i++){
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            q[s].add(new int[]{e,w});
        }


        st = new StringTokenizer(br.readLine());
        int s = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());
        int[] result = dijkstra3(s);
        

        System.out.print(result[e]);
        return;
    }

    private static int[] dijkstra3(int start ){
        int[] dist = new int[n+1];
        Arrays.fill(dist, INF);
        dist[start] = 0 ;

        PriorityQueue<int[]> pq = new PriorityQueue<>( (a,b) -> Integer.compare(a[0],b[0]));
        pq.offer(new int[]{0,start});

        while(!pq.isEmpty()){
            int[] cur = pq.poll();
            int curDist = cur[0] , u = cur[1];

            if( curDist > dist[u] ) continue;

            for(int[] edge : q[u]){
                int v = edge[0] , w = edge[1];
                if(  dist[v] > dist[u]+w ){
                    dist[v] = dist[u]+w;
                    pq.offer(new int[]{dist[v], v});
                }
            }
        }
        return dist;
    }
}