package practice.dp.java;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solve1103 {

    static int N , M ;
    static int[][] board;
    static int[][] dp;
    static boolean[][] visited;
    static int[] dx = {-1,1,0,0};
    static int[] dy = {0,0,-1,1};


    public static void main(String[] args) throws IOException{ 

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        board = new int[N][M];
        dp = new int[N][M];
        visited = new boolean[N][M];

        for(int i = 0 ; i<N; i++){
            String  line = br.readLine();
            for(int j = 0 ; j < M; j++){
                if( line.charAt(j) == 'H'){
                    board[i][j] = -1;
                } else {
                    board[i][j] = line.charAt(j) - '0';
                }
            }
        }

        for(int i = 0 ; i< N ; i++){
            Arrays.fill(dp[i], -1);
        }

        int result = dfs(0,0);
        System.out.println(result);

    }

    static int dfs(int x, int y){

        if(dp[x][y] != -1){
            return dp[x][y];
        }

        if( visited[x][y] ){
            System.out.println(-1);
            System.exit(0);
        }

        visited[x][y] = true;
        int maxMoves = 0 ;

        int moveDistance = board[x][y];
        for(int dir = 0 ; dir <4 ; dir++){
            int nx = x + dx[dir] * moveDistance;
            int ny = y + dy[dir] * moveDistance;

            if( nx >= 0 && ny >= 0 && nx < N && ny < M && board[nx][ny] != -1){
                int moves = dfs(nx,ny);
                maxMoves = Math.max(maxMoves, moves);
            }
        }
        visited[x][y] = false;

        dp[x][y] = maxMoves + 1;
        return dp[x][y];
    }
}