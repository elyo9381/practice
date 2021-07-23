package me.elyowon.programers.L2;


import java.util.*;

/**
 * 순열을 가지고 서브셋을 만드는경우는
 * 루프안에 순열을 넣고 i 를 타겟으로 각갯수를 구하는것이다.
 */
public class L2_210706_소수찾기 {



    public int solution(String numbers) {
        int answer = 0;

        ArrayList<Integer> result = new ArrayList<>();
        String curr = "";
        boolean[] visited = new boolean[numbers.length()];

        for (int i = 1; i <= numbers.length(); i++) {
            permu(numbers,curr,i,visited,result);
        }
        for (int x : result) {
            answer += cal(x);
        }

        return answer;
    }

    public static void permu(String numbers,String curr,int target,boolean[] visited,ArrayList<Integer> result) {
        if (curr.length() == target) {
            if (!result.contains(Integer.parseInt(curr)))
                result.add(Integer.parseInt(curr));
            return;
        }

        for (int j = 0; j < numbers.length(); j++) {
            if (!visited[j]) {
                curr += numbers.charAt(j);
                visited[j] = true;
                permu(numbers,curr,target,visited,result);
                visited[j] = false;
                curr = curr.substring(0,curr.length() - 1);
            }

        }
    }

    public static int cal(int n) {
        if (n == 0) return 0;
        if (n == 1) return 0;

        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) return 0;
        }

        return 1;
    }

    public int solution1(String numbers) {
        HashSet<Integer> set = new HashSet<>();
        permutation("", numbers, set);
        int count = 0;
        while(set.iterator().hasNext()){
            int a = set.iterator().next();
            set.remove(a);
            if(a==2) count++;
            if(a%2!=0 && isPrime(a)){
                count++;
            }
        }
        return count;
    }

    public boolean isPrime(int n){
        if(n==0 || n==1) return false;
        for(int i=3; i<=(int)Math.sqrt(n); i+=2){
            if(n%i==0) return false;
        }
        return true;
    }

    public void permutation(String prefix, String str, HashSet<Integer> set) {
        int n = str.length();
        //if (n == 0) System.out.println(prefix);
        if(!prefix.equals("")) set.add(Integer.valueOf(prefix));
        for (int i = 0; i < n; i++)
            permutation(prefix + str.charAt(i), str.substring(0, i) + str.substring(i+1, n), set);

    }
}
