import java.util.*;
import java.io.*;

// BOJ 1012 - 유기농 배추
// 입력: T(테스트케이스) → 각 케이스마다 M(가로) N(세로) K(배추수) → K줄에 좌표(x,y)
public class Main {

    static int[][] maps;
    static boolean[][] visited;
    static int M, N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());

        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            M = Integer.parseInt(st.nextToken()); // 가로
            N = Integer.parseInt(st.nextToken()); // 세로
            int K = Integer.parseInt(st.nextToken()); // 배추 수

            maps = new int[N][M];
            visited = new boolean[N][M];

            for (int i = 0; i < K; i++) {
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                maps[y][x] = 1;
            }

            // ======= 여기부터 풀이 작성 =======
            int answer = solution();
            System.out.println(answer);
        }
    }

    // 이 메서드를 작성해
    public static int solution(int n, int[][] computers) {
        int answer = 0;
        boolean[] visited = new boolean[n];

        for(int i = 0; i<n; i++){
                if( !visited[i] ){
                    dfs(i,computers,visited, n);
                    answer++;
            }
        }
        return answer;
    }

    private static void dfs(int node , int[][] computers , boolean[] visited, int n ){
        if( visited[node] ) return;

        visited[node] = true;

        for(int i = 0 ; i < n ; i++){
            if(node == i ) continue;
            if(computers[node][i] == 1 && !visited[i] ) {
                dfs(i, computers, visited, n);
            }
        }
    }
}
