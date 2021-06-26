package me.elyowon.programers.L1;


import java.util.stream.IntStream;

/**
 *
 */
public class L1_210626_소수찾기 {
    public int solution(int n) {
        int answer = 0;

        int[] checkList = new int[n];


        for (int i =2; i<= n ; i++){
            checkList[i]++;
        }

//        for (int i = 2; i <=n; i++) {
//            if(checkList[i] == 0) continue;
//
//            for (int j = i*2 ; j <= n ; j +=i){
//                checkList[j] = 0;
//            }
//        }

        IntStream.rangeClosed(2,n)
                .filter(i -> checkList[i] != 0)
                .flatMap(i -> IntStream.iterate(i * 2,j -> j <= n,j -> j + i))
                .forEach(j -> checkList[j] = 0);

        for (int i = 2; i <=n ; i++) {
            if(checkList[i]!=0) answer++;
        }
        return answer;
    }
}

