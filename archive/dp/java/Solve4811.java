import java.util.*;

public class Solve4811 {
    static int n ;
    static long[][] dp;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); 
        
        dp = new long[31][31];
        
        while( (n = sc.nextInt())  != 0) {
            System.out.println(solve(n,0));
        }
    }

    public static long solve(int w, int h) {
        if (w == 0) return 1;
        if(dp[w][h] != 0) return dp[w][h];
        
        long result = 0;
        result += solve(w-1 , h+1);

        if( h > 0) {
            result += solve(w, h-1);
        }
        return dp[w][h] = result;
    }
}