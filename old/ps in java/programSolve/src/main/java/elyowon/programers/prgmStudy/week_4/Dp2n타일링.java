package elyowon.programers.prgmStudy.week_4;

import java.io.BufferedReader;
import java.util.Arrays;

public class Dp2n타일링 {
    public static final int MOD = 1000000007;

    public int solution(int n) {
        int[] cache = new int[n + 1];
//        int[] clone = cache.clone();
//        Arrays.fill(clone,-1);
//        answer = dp(n,clone);
        cache[0] = 1;
        cache[1] = 1;

        for (int i = 2; i <= n; i++) {
            cache[i] = (cache[i - 1] + cache[i - 2]) % MOD;
        }

        return cache[n];
    }

    private int dp(int n,int[] cache) {

        if (n == 0 || n == 1) return 1;

        if (cache[n] != -1) return cache[n];

        cache[n] = (dp(n - 2,cache) + dp(n - 1,cache)) % MOD;
        return cache[n];

    }
}