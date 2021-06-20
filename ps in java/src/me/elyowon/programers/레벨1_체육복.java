package me.elyowon.programers;


import java.util.Arrays;
import java.util.HashMap;
import java.util.Set;

/**
 * 2021.06.20
 */
public class 레벨1_체육복 {

    public static void main(String[] args) {
        int[] lost = {3,1};
        int[] reverse = {2,3};

        int n = 5;


        int solution = solution(n,lost,reverse);
        System.out.println("solution = " + solution);
    }
    public static int solution(int n,int[] lost,int[] reserve) {
        int answer = 0;

        HashMap<Integer,Boolean> hm = new HashMap<>();
        boolean[] check = new boolean[n+1];

        for (int i = 1; i <=n; i++) {
            check[i]= true;
        }
        for (int i : lost) {
            check[i] = false;
        }

        for (int i : reserve) {
            hm.put(i,true);
        }

        Arrays.sort(lost);

        for (int i : lost) {
            if( hm.get(i) != null){
                check[i]= true;
                hm.remove(i);
                continue;
            }

            if( hm.get(i-1) != null ){
                if(check[i-1] == false){
                    check[i-1] = true;
                    hm.remove(i - 1);
                    continue;
                }

                check[i] = true;
                hm.remove(i-1);
                continue;
            }
            if(hm.get(i+1) != null) {
                if(check[i+1] == false){
                    check[i+1] = true;
                    hm.remove(i + 1);
                    continue;
                }
                check[i] = true;
                hm.remove(i + 1);
                continue;
            }
        }

        for(int i = 1 ; i<=n; i++){
            if(check[i] == true){
                answer++;
            }
        }
        return answer;
    }
}
