package me.elyowon.ndb796;

import java.util.Scanner;

public class _4_일이될때까지 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int result = 0;

        while(true){
            int target = (n / k)  * k;
            result += (n - target);
            n = target;

            if(n < k) break;
            result +=1;
            n /= k;
        }

        result +=(n-1);
        System.out.println(result);
    }
}

//
//    private static void dfs(int idx,int sum) {
//
//        if (idx == n) {
//            if (sum > res) res = sum;
//        } else {
//            if (idx + t[idx] <= n + 1) dfs(idx + t[idx],sum + p[idx]);
//            dfs(idx + 1,sum);
//        }
//    }