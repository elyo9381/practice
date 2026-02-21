import java.util.*;
import java.io.*;

/**
 * Union-Find (Disjoint Set Union) 템플릿
 * 시간복잡도: O(alpha(N)) per operation (거의 O(1))
 *
 * 사용 상황:
 * - 집합 합치기 / 같은 집합인지 판별
 * - Kruskal MST
 * - 연결 요소 판별 (동적 간선 추가)
 * - "여행 가자" 류 문제 (두 노드가 연결되어 있는가?)
 *
 * 최적화:
 * - 경로 압축 (path compression): find 시 루트로 직접 연결
 * - 랭크 기반 합치기 (union by rank): 작은 트리를 큰 트리에 붙임
 */
public class unionfind_template {

    static int[] parent;
    static int[] rank;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        init(N);

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int cmd = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            if (cmd == 0) {
                union(a, b);
            } else {
                sb.append(find(a) == find(b) ? "YES" : "NO").append("\n");
            }
        }
        System.out.print(sb);
    }

    static void init(int n) {
        parent = new int[n + 1];
        rank = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    static int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // 경로 압축
        }
        return parent[x];
    }

    static void union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB) return;

        // 랭크 기반 합치기
        if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
    }

    /**
     * Kruskal MST 예시
     * edges: {weight, u, v} 배열
     */
    static long kruskal(int n, int[][] edges) {
        Arrays.sort(edges, (a, b) -> a[0] - b[0]); // 가중치 오름차순
        init(n);

        long totalWeight = 0;
        int edgeCount = 0;

        for (int[] edge : edges) {
            int w = edge[0], u = edge[1], v = edge[2];
            if (find(u) != find(v)) {
                union(u, v);
                totalWeight += w;
                edgeCount++;
                if (edgeCount == n - 1) break; // MST 완성
            }
        }
        return totalWeight;
    }
}
