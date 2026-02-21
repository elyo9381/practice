import java.util.*;
import java.io.*;

/**
 * Dijkstra 최단경로 템플릿
 * 시간복잡도: O((V + E) log V) - PriorityQueue 사용
 *
 * 사용 상황:
 * - 가중치가 있는 그래프의 단일 출발점 최단경로
 * - 음수 가중치 없을 때만 사용 (음수 있으면 Bellman-Ford)
 *
 * 주의:
 * - dist 배열 INF 초기화 잊지 말 것
 * - PQ에서 꺼낸 후 dist 비교로 중복 스킵
 * - 2D 그리드에서도 사용 가능 (가중치가 다른 BFS)
 */
public class dijkstra_template {

    static final int INF = Integer.MAX_VALUE;
    static List<int[]>[] graph; // graph[u] = list of {v, weight}

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int V = Integer.parseInt(st.nextToken()); // 정점 수
        int E = Integer.parseInt(st.nextToken()); // 간선 수
        int start = Integer.parseInt(br.readLine().trim());

        @SuppressWarnings("unchecked")
        List<int[]>[] g = new ArrayList[V + 1];
        graph = g;
        for (int i = 0; i <= V; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            graph[u].add(new int[]{v, w});
        }

        int[] dist = dijkstra(V, start);

        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= V; i++) {
            sb.append(dist[i] == INF ? "INF" : dist[i]).append("\n");
        }
        System.out.print(sb);
    }

    static int[] dijkstra(int V, int start) {
        int[] dist = new int[V + 1];
        Arrays.fill(dist, INF);
        dist[start] = 0;

        // PQ: {거리, 노드} - 거리 기준 오름차순
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[]{0, start});

        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int curDist = cur[0], u = cur[1];

            // 이미 더 짧은 경로로 방문한 경우 스킵
            if (curDist > dist[u]) continue;

            for (int[] edge : graph[u]) {
                int v = edge[0], w = edge[1];
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.offer(new int[]{dist[v], v});
                }
            }
        }
        return dist;
    }

    /**
     * 2D 그리드 Dijkstra (가중치 BFS)
     * 예: BOJ 4485 녹색 옷 입은 애가 젤다지
     */
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    static int dijkstraGrid(int[][] grid, int N) {
        int[][] dist = new int[N][N];
        for (int[] row : dist) Arrays.fill(row, INF);
        dist[0][0] = grid[0][0];

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[2] - b[2]);
        pq.offer(new int[]{0, 0, grid[0][0]});

        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int x = cur[0], y = cur[1], cost = cur[2];

            if (cost > dist[x][y]) continue;
            if (x == N - 1 && y == N - 1) return cost;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                int newCost = cost + grid[nx][ny];
                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.offer(new int[]{nx, ny, newCost});
                }
            }
        }
        return dist[N - 1][N - 1];
    }
}
