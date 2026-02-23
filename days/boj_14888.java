import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;

public class boj_14888 {

    static int n ;
    static int max = Integer.MIN_VALUE;
    static int min = Integer.MAX_VALUE;

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());

        int[] arr = new int[n];


        for(int i = 0 ; i<n; i++){
            st = new StringTokenizer(br.readLine());
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int[] ops = new int[4];
        for(int i = 0 ; i<4; i++){
            st = new StringTokenizer(br.readLine());
            ops[i] = Integer.parseInt(st.nextToken());
        }

        dfs(1,arr[0] , arr, ops);
        System.out.println();
    }

    private static void dfs(int idx , int sum , int[] arr, int[] ops ){
        
        if( idx == n ){
            max = Math.max(max,sum);
            min = Math.min(min,sum);
            return ;
        }

        for(int i = 0 ; i<4; i++){
            if( ops[i] > 0){
                ops[i]--;
                dfs(idx+1, calculate(arr[idx], sum, i), arr, ops);
                ops[i]++;
            }
        }
        return ;
    }

    private static int calculate(int target, int sum, int ops){

        if(ops == 0){
            sum += target;
        } else if(ops == 0){
            sum -= target;
        } else if(ops == 0){
            sum *= target;
        } else {
            sum /= target;
        }

        return sum;
    }
}