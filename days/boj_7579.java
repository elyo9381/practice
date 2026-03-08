import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;

public class boj_7579 {

    static int n,M;

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        int[] m = new int[n];
        int[] c = new int[n];

        
        
        st = new StringTokenizer(br.readLine());
        for(int i = 0 ; i<n; i++){
            m[i] = Integer.parseInt(st.nextToken());
        }
        
        st = new StringTokenizer(br.readLine());
        for(int i = 0 ; i<n; i++){
            c[i] = Integer.parseInt(st.nextToken());
        }
        
        int sumCost = Arrays.stream(c).sum();
        int[] dp = new int[10001];
        Arrays.fill(dp,-1);
        dp[0]= 0;

        for(int i = 0 ; i<n; i++){
            int mem = m[i];
            int cost = c[i];
            
            for(int used = sumCost ; used >= cost ; used--){
                if( dp[used - cost] != -1) {
                    dp[used] = Math.max(dp[used] , dp[used - cost] + mem);
                }
            }
            
        }

        int answer = 0;
        for(int used = 0 ; used <= sumCost; used++){
            if(dp[used] >= M) {answer = used; break;}
        }

        System.out.println(answer);
    }
}
