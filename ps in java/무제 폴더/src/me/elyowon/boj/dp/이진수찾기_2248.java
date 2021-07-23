package me.elyowon.boj.dp;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 *
 */
public class 이진수찾기_2248 {

    static int N, I, L;
    static int[][] dp;
    static char[] result;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());


        N = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());
        I = Integer.parseInt(st.nextToken());
        dp = new int[N + 1][N + 1];
        result = new char[N + 1];

        Arrays.stream(dp).forEach(i -> Arrays.fill(i,-1));

        skip(N,L,I - 1,0);
        String s = "";
        for (char c : result) {
            s += c;
        }

        String collect = Stream.of(result).map(String::valueOf).collect(Collectors.joining());
        System.out.println("s = " + collect);

//        for (int[] ints : dp) {
//            for (int anInt : ints) {
//                System.out.println("anInt = " + anInt);
//            }
//            System.out.println();
//        }
    }

    private static int binary(int n,int m) {
        int ret = dp[n][m];
        if (ret != -1) return ret;
        if (m == 0 || n == 0) return ret = 1;

        dp[n][m] = binary(n - 1,m);
        if (m > 0) {
            dp[n][m] += binary(n - 1,m - 1);
        }
        return dp[n][m];

    }

    private static void skip(int n,int m,int k,int p) {
        if (n == 0) return;
        if (m == 0) {
            for (int i = 0; i < n; i++)
                result[p + i] = '0';
            return;
        }

        int pivot = binary(n - 1,m);
        if (k < pivot) {
            result[p] = '0';
            skip(n - 1,m,k,p + 1);
        } else {
            result[p] = '1';
            skip(n - 1,m - 1,k - pivot,p + 1);
        }
    }

}
