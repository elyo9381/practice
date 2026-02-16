
/**
* https://www.acmicpc.net/problem/11049
*/
public class Solve11049 {

    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n ;
        int[] row , cols;
        int[][] dp ;

        n = Integer.parseInt(br.readLine());

        row = new int[n+1];
        cols = new int[n+1];

        for(int i = 1; i <=n ; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            row[i] = Integer.parseInt(st.nextToken());
            cols[i] = Integer.parseInt(st.nextToken());
        }

        dp = new int[n+1][n+1];
        int INF = Integer.MAX_VALUE;
        for(int i = 0 ; i<=n ; i++){
            Arrays.fill(dp[i], INF);
            dp[i][i] = 0 ;

        for(int len =  2; len <=n; len++){
            for(int i = 1 ; i<= n - len +1 ; i++){
                int j = len - 1 + i;
                for(int k = i ; k< j; k++){
                    int cost = row[i] * cols[k] * cols[j];
                    dp[i][j] = Math.min ( dp[i][j]  , dp[i][k] + dp[k+1][j] + cost);
                }
            }
        }
        System.out.println(dp[1][n]);
    }
}