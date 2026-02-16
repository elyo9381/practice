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

    public static int solution(){
        int answer = 0;

        for(int i = 0 ; i<N; i++){
            for(int j = 0 ;j<M;j++){
                if(!visited[i][j] && maps[i][j] ==){
                    dfs(i,j);
                    answer++;
                }
            }
        }
        return answer;
    }

    private static void dfs(int x , int y ){
        if( x < 0 || y < 0 || x >= N || y >=M ) return ;
        if(visited[x][y] || maps[x][y] == 0) return ;
        visited[x][y]= true;
        
        dfs(x+1,y);
        dfs(x,y+1);
        dfs(x-1,y);
        dfs(x,y-1);
    }
}
