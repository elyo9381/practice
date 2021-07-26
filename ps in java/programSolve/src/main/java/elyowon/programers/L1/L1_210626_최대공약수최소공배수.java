package elyowon.programers.L1;


import java.util.ArrayList;

/**
 */
public class L1_210626_최대공약수최소공배수 {
    public int[] solution(int n, int m) {
        int[] answer = new int[2];
        int gcd = gcd(n,m);
        answer[0] = gcd;
        answer[1] = n*(m / gcd);
        return answer;

    }

    private int gcd(int n,int m) {
        if(m == 0) return n;
        else return gcd(m,n%m);
    }
}

