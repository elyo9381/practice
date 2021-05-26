package me.elyowon.leetcode.algorithm;

import java.util.ArrayList;
import java.util.Stack;

/**
 *
 * 같은 scc에 속하는 두정점은 서로 도달이가능하다.
 *
 * scc는 사이클이 발생하는 경우 무조건 해당하는 특징이 있습니다.
 * 무향 그래프라면 무조건 scc이기에 의미가 없습니다.
 *
 * 타잔 알고리즘 부모와의 사이클이 존재해야 scc가 존재할수있다.
 *
 *
 */

public class SCC_StronlyConnectedComponent {

    public static int MAX = 1001;

    public static int id = 0;
    public static int[] d = new int[MAX];

    public static boolean[] finished = new boolean[MAX];

    public static ArrayList<Integer>[] a = new ArrayList[MAX];

    public static ArrayList<ArrayList<Integer>> SCC = new ArrayList<ArrayList<Integer>>();

    public static Stack<Integer> s = new Stack<>();

    public static int dfs(int x){
        d[x] = ++id;
        s.push(x);

        int parent  = d[x];
        for (int i = 0; i < a[x].size(); i++) {
            int y = a[x].get(i);
            if(d[y] == 0) parent = Math.min(parent,dfs(y));
            else if( !finished[y] ) parent = Math.min(parent,d[y]);
        }

        if(parent == d[x]){
            ArrayList<Integer> scc = new ArrayList<>();
            while(true) {
                int t = s.pop();
                scc.add(t);
                finished[t] = true;
                if (t == x) break;
            }
            SCC.add(scc);
        }

        return parent;
    }

    public static void main(String[] args) {

        int v = 11;

        for (int i = 0; i < 13; i++) {
            a[i] = new ArrayList<Integer>();
        }

        a[1].add(2);
        a[2].add(3);
        a[3].add(1);
        a[4].add(2);
        a[4].add(5);
        a[5].add(7);
        a[6].add(5);
        a[7].add(6);
        a[8].add(5);
        a[8].add(9);
        a[9].add(10);
        a[10].add(11);
        a[11].add(3);
        a[11].add(8);

        for (int i = 1; i < v; i++) {
            if(d[i] == 0) dfs(i);
        }

        for (int i = 0; i < SCC.size(); i++) {
            System.out.print(i+1 + " SCC번째 : ");
            for (int j = 0; j < SCC.get(i).size(); j++) {
                System.out.print (" " + SCC.get(i).get(j));
            }
            System.out.println();
        }


    }


}

