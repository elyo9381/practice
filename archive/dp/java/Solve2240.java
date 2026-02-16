import java.util.Arrays;
import java.util.Scanner;

public class Solve2240 {

    static int t,w,n;
    static int[] fruits;
    static int[][][] dp ;

    
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        t = sc.nextInt();
        w = sc.nextInt();
        n = 2;
        fruits = new int[t+1];
        dp = new int[t+1][w+1][2];

        for(int i = 1; i<=t; i++){
            fruits[i] = sc.nextInt();
        }

        for(int i = 1; i<=t; i++){
            for(int j = 0; j<=w; j++){
                for(int pos = 0; pos<n; pos++){
                    dp[i][j][pos] = dp[i-1][j][pos] + (fruits[i] == pos+1 ? 1 : 0);

                    if ( j > 0) {
                        for(int prev = 0 ; prev < n; prev++){
                            if(prev != pos){
                                dp[i][j][pos] = Math.max(dp[i][j][pos] , 
                                dp[i-1][j-1][prev] + (fruits[i] == pos+1 ? 1 : 0)) ;
                            }
                        }
                    }
                }
            }
        }
        
        System.out.println( 
            Arrays.stream(dp[t])
                .flatMapToInt(Arrays::stream)
                .max()
                .getAsInt());
    }
}