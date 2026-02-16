package elyowon.programers.prgmStudy.week_4;

public class Dp3n타일링 {

    public int solution(int n) {
        final int MODULER = 1000000007;
        int size = (n+1)/2;
        long[] cache = new long[size];

        cache[0] = 1;
        cache[1] = 3;

        for(int i = 2; i<=n; i+=1){
            cache[i] = (cache[i-1] *3) ;
            for(int j = i-2; j>=0; j-=1){
                cache[i] = cache[i] + cache[j] *2;
            }
            cache[i] = cache[i] % MODULER;
        }

        return (int)cache[n];
    }
}