
/**
* https://www.acmicpc.net/problem/2629
*/
public class Solve2629 {

    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int maxWeight = 0 ;
        int[] weights = new int[n+1];

        for(int i = 1; i<=n ;i++){
            weights[i] = Integer.parseInt(st.nextToken());
            maxWeight += weights[i];
        }

        boolean[][] dp = new boolean[n+1][maxWeight*2 + 1];
        dp[0][maxWeight] = true;

        for(int i = 1; i <=n ; i++){
            int weight = weights[i];
            for(int w = 0; w<=maxWeight*2 ; w++){
                dp[i][w] = dp[i-1][w];

                if( w - weight >= 0){
                    dp[i][w] |= dp[i-1][w-weight];
                }

                if( w+weight <= maxWeight*2 ){
                    dp[i][w] |= dp[i-1][w+weight];
                }
            }
        }

        int m = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());

        for(int i = 0; i<m ;i++){
            int bizWeight = Integer.parseInt(st.nextToken());

            if ( bizWeight > maxWeight){
                System.out.print("N ");
            } else {
                if( dp[n][maxWeight - bizWeight] ) System.out.print("Y ")
                else System.out.print("N ");
            }
        }
        
    }
}