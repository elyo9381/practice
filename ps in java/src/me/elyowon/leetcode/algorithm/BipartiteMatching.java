package me.elyowon.leetcode.algorithm;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;


/**
 *
 *
 */

public class BipartiteMatching {


    private static final int MAX = 101;

    public static int[] d = new int[MAX]; // 특정 vertex의 정보
    public static boolean[] c = new boolean[MAX]; // vertex를 이미 처리했는지 여부
    public static ArrayList<Integer>[] a = new ArrayList[MAX]; // edge 정보를 담음
    public static int n = 3, m = 0, s = 0;


    // 매핑에 성공한 경우 true, 실패한 경우 false

    static boolean dfs(int x){
        // 연결된 모든 노드에 대해서 들어갈 수 있는 시도
        for (int i = 0; i < a[x].size(); i++) {
            // 이미 처리한 노드는 더 이상 볼 필요가 없음
            int t = a[x].get(i);
            // 이미 처이한 노드는 더이상 볼 필요가 없음
            if(c[t]) continue;
            c[t] = true;
            // 비어있거나 점유 노드에 더 들어갈 공간이 있는 경우
            if(d[t] == 0 || dfs(d[t])){
                d[t] = x;
                return true;
            }
        }
        return false;
    }


    public static void main(String[] args) {

        for (int i = 0; i < 4; i++) {
            a[i] = (new ArrayList<Integer>());
        }

        a[1].add(1);
        a[1].add(2);
        a[1].add(3);
        a[2].add(1);
        a[3].add(2);

        int count = 0;
        for (int i = 1; i <= n; i++) {
            Arrays.fill(c,false);
            if(dfs(i)) count++;
        }

        for (int i = 1; i <=MAX; i++) {
            if(d[i] != 0){
                System.out.println(d[i] + " -> " + i );
            }
        }
    }

}