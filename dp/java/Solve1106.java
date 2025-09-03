

public class Solve1106 {

    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int c = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());

        int[][] dp = new int[n+1][1001];

        int[] cost = new int[n+1];
        int[] count = new int[n+1];

        for(int i = 1; i<=n; i++){
            st = new StringTokenizer(br.readLine());

            cost[i] = Integer.parseInt(st.nextToken());
            count[i] = Integer.parseInt(st.nextToken());
        }

        int INF = Integer.MAX_VALUE;
        for(int i = 0; i <= n; i++){
            Arrays.fill(dp[i], INF);
        }
        dp[0][0] = 0;
        for(int i = 1; i<=n; i++){
            for(int person = 0; person < 1001; person++){
                
                dp[i][person] = dp[i-1][person];
                if ( count[i] <= person && dp[i][person - count[i]] != INF){
                    dp[i][person] = Math.min(dp[i][person] ,dp[i][person - count[i]] + cost[i]);
                }
            }
        }

        System.out.println(dp[n][c]);
    }
}