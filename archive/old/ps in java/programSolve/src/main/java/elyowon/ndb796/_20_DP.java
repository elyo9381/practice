package elyowon.ndb796;


import java.util.Arrays;
import java.util.Scanner;

public class _20_DP {


    static long[] d = new long[100];

    public static void main(String[] args) {

        System.out.println(fibo(50));

        //buttom-up
        d[1] = 1;
        d[2] = 1;
        int n = 50;

        for(int i = 3; i<=n; i++){
            d[i] = d[i-1] + d[i-2];
        }
        System.out.println(d[n]);
    }




    /**
     *
     * 이건 메모이제이션이고
     * top-down
     * @param x
     * @return
     */
    private static long fibo(int x) {

        if(x == 1 || x == 2){
            return 1;
        }
        if(d[x] != 0){
            return d[x];
        }
        d[x] = fibo(x-1) + fibo(x-2);
        return d[x];
    }

}