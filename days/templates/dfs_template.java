import java.util.*;
import java.io.*;

/**
 * DFS 템플릿 - 탐색/백트래킹 용
 * 시간복잡도: O(V + E) 또는 백트래킹 O(N!)
 *
 * 사용 상황:
 * - 연결 요소 카운팅 (단지번호 등)
 * - 순열/조합 생성
 * - 백트래킹 (N-Queen, 연산자 끼워넣기 등)
 */
public class dfs_template {

    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int N, M;
    static int[][] map;
    static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new int[N][M];
        visited = new boolean[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // 연결 요소 카운팅 예시
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && map[i][j] == 1) {
                    dfsGrid(i, j);
                    count++;
                }
            }
        }
        System.out.println(count);
    }

    // 그리드 DFS
    static void dfsGrid(int x, int y) {
        if (x < 0 || y < 0 || x >= N || y >= M) return;
        if (visited[x][y] || map[x][y] == 0) return;

        visited[x][y] = true;
        for (int d = 0; d < 4; d++) {
            dfsGrid(x + dx[d], y + dy[d]);
        }
    }

    // 백트래킹 (순열 생성) 예시
    static int[] result;
    static boolean[] used;

    static void permutation(int depth, int n, int r) {
        if (depth == r) {
            // result[0..r-1] 사용
            System.out.println(Arrays.toString(Arrays.copyOf(result, r)));
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (used[i]) continue;
            used[i] = true;
            result[depth] = i;
            permutation(depth + 1, n, r);
            used[i] = false;
        }
    }

    // 조합 생성 예시
    static void combination(int start, int depth, int n, int r) {
        if (depth == r) {
            System.out.println(Arrays.toString(Arrays.copyOf(result, r)));
            return;
        }
        for (int i = start; i <= n; i++) {
            result[depth] = i;
            combination(i + 1, depth + 1, n, r);
        }
    }
}
