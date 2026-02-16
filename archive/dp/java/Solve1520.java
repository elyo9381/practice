/**
 * https://www.acmicpc.net/problem/1520
 */
public class Solve1520 {
    
    static int m , n ;
    static int[][] map ;
    static int[][] dp  ;
    static int[] dx = {0,1,0,-1};
    static int[] dy = {1,0,-1,0};

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n+1][m+1];

        for(int i = 0 ; i<n; i++){
            Arrays.fill(dp[i] , -1);
        }

        for(int i = 0 ; i<n ; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0 ; j<m ; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        System.out.print(solve(0,0));
    }

    static int solve(int x, int y){

        if ( x == n-1 && y == m-1) {
            return 1;
        }
        if( dp[x][y] != -1) return dp[x][y];
        dp[x][y] = 0 ;

        for(int i = 0 ; i<4; i++){
            int nx = dx[i] + x;
            int ny = dy[i] + y;

            if( nx < 0 || nx >= n || ny < 0 || ny >= m || map[x][y] <= map[nx][ny] ) continue;
            dp[x][y] += solve(nx,ny);
        }
        return dp[x][y];
    }
}
