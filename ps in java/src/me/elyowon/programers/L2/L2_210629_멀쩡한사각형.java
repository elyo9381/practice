package me.elyowon.programers.L2;


/**
 *
 */
public class L2_210629_멀쩡한사각형 {

    public long solution(int w,int h) {
        long answer = 1;
        long line = w * h - gcd(w,h);

        answer = w * h - (line);
        return answer;
    }

    public long gcd(long w,long h){
        if(h == 0) return w;
        else return gcd(h, w%h);
    }


}