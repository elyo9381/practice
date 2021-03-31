package me.elyowon.ndb796;

public class _12_factorial {


    private static int factorialRecursive(int n) {
        if(n<=1) return 1;
        return n * factorialRecursive(n-1);
    }
    public static int factorialIterative(int n) {
        int result = 1;
        for(int i = 1; i<=n ; i++){
            result *= i;
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println("반복적으로 구현 " + factorialIterative(5));
        System.out.println("반복적으로 구현 " + factorialRecursive(5));
    }

}