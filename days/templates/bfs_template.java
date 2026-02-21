import java.util.*;
import java.io.*;

/**
 * BFS 템플릿 - 최단거리/레벨탐색 용
 * 시간복잡도: O(V + E)
 *
 * 사용 상황:
 * - 최단 거리 (가중치 없는 그래프)
 * - 레벨별 탐색 (토마토, 불, 바이러스 확산 등)
 * - 3차원 BFS (visited[z][y][x] 또는 visited[y][x][state])
 */
public class bfs_template {

    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[][] map = new int[N][M];
        boolean[][] visited = new boolean[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // BFS 시작
        System.out.println(bfs(map, visited, N, M, 0, 0));
    }

    static int bfs(int[][] map, boolean[][] visited, int N, int M, int startX, int startY) {
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{startX, startY, 1}); // {x, y, distance}
        visited[startX][startY] = true;

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int x = cur[0], y = cur[1], dist = cur[2];

            // 도착 조건
            if (x == N - 1 && y == M - 1) {
                return dist;
            }

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if (visited[nx][ny]) continue;
                if (map[nx][ny] == 0) continue; // 벽이면 스킵 (문제에 맞게 수정)

                visited[nx][ny] = true;
                queue.offer(new int[]{nx, ny, dist + 1});
            }
        }
        return -1; // 도달 불가
    }

    /**
     * 3차원 BFS 예시 (벽 부수기 등 상태 추가)
     * visited[x][y][state] 사용
     */
    static int bfs3D(int[][] map, int N, int M) {
        boolean[][][] visited = new boolean[N][M][2]; // [x][y][벽 부순 횟수]
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 0, 0, 1}); // {x, y, 벽부순횟수, 거리}
        visited[0][0][0] = true;

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int x = cur[0], y = cur[1], broken = cur[2], dist = cur[3];

            if (x == N - 1 && y == M - 1) return dist;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

                // 빈 칸
                if (map[nx][ny] == 0 && !visited[nx][ny][broken]) {
                    visited[nx][ny][broken] = true;
                    queue.offer(new int[]{nx, ny, broken, dist + 1});
                }
                // 벽인데 아직 안 부쉈으면
                if (map[nx][ny] == 1 && broken == 0 && !visited[nx][ny][1]) {
                    visited[nx][ny][1] = true;
                    queue.offer(new int[]{nx, ny, 1, dist + 1});
                }
            }
        }
        return -1;
    }
}
