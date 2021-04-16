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