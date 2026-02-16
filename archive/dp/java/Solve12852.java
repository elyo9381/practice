public class Solve12852 {

    static int n ;
    static int[] dp;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        dp = new dp[n+1];

        dp[1] = 0;
        for(int i = 2 ; i<=n; i++) {
            dp[i] = Math.min(dp[i] , dp[i-1]+1);

            if( i % 2 == 0) dp[i] = Math.min(dp[i] , dp[i/2]+1);
            if( i % 3 == 0) dp[i] = Math.min(dp[i] , dp[i/3]+1);
        }


        ArrayList path = new ArrayList<>();
        int cur = n ;

        while( cur > 0) {
            path.add(cur);

            if ( cur % 3 == 0 && dp[cur] == dp[cur/3] + 1) {
                cur = cur / 3;
            } else if (  cur % 2 == 0 && dp[cur] == dp[cur/2] + 1) {
                cur = cur / 2;
            } else {
                cur = cur - 1;
            }
        }
        path.add(cur);

        System.out.println(dp[n]);
        for(int i = 0 ; i<path.size(); i++){
            System.out.println(path.get(i) + " ");
        }

    }
}