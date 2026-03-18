import java.io.*;
import java.util.*;

public class boj_1238 {
    static final int INF = 1_000_000_000;
    static int n, m, x;
    static List<int[]>[] graph;
    static List<int[]>[] rev;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(br.readLine().trim());

        graph = new ArrayList[n + 1];
        rev = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
            rev[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            graph[u].add(new int[]{v, w});
            rev[v].add(new int[]{u, w});
        }

        int[] distToParty = dijkstra(graph, x); // X -> i
        int[] distFromParty = dijkstra(rev, x); // X -> i in reversed == i -> X in original

        int answer = 0;
        for (int i = 1; i <= n; i++) {
            int roundTrip = distToParty[i] + distFromParty[i];
            if (roundTrip < INF * 2 && roundTrip > answer) {
                answer = roundTrip;
            }
        }

        System.out.print(answer);
    }

    private static int[] dijkstra(List<int[]>[] g, int start) {
        int[] dist = new int[n + 1];
        Arrays.fill(dist, INF);
        dist[start] = 0;

        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.offer(new int[]{0, start});

        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int d = cur[0];
            int u = cur[1];

            if (d != dist[u]) continue;

            for (int[] edge : g[u]) {
                int v = edge[0];
                int w = edge[1];
                int nd = d + w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.offer(new int[]{nd, v});
                }
            }
        }

        return dist;
    }
}
