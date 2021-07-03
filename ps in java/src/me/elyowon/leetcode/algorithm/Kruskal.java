package me.elyowon.leetcode.algorithm;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.stream.IntStream;

/**
 * 가장 적은 비용으로 모든 노드를 연결하기 위한 알고리즘
 * 유니온 파인을 이용해서 노드를 연결합니다.
 * <p>
 * 유니온 파인에 의해서 사이클이 존재하는지 확인합니다.
 * <p>
 * 1 정렬된 순서에 맞게 그래프에 포함시킵니다.
 * 2 포함시키전에 사이클 테이블을 확인합니다.
 * 3 사이클을 형성하는 경우 간선을 포함하지 않습니다.
 * <p>
 * timeComplex : O(nlogn) + O(n) >> 노드 정렬 +  정렬된 노드 n번 탐색후 모든 모드 연결
 * spaceComplex : O(n)
 */

public class Kruskal {

    public static class Edge {
        int[] node = new int[2];
        int distacne;

        public Edge(int a,int b,int distacne) {
            this.node[0] = a;
            this.node[1] = b;
            this.distacne = distacne;
        }

    }

    ;

    public static void main(String[] args) {

        int n = 7;
        int m = 11;

        ArrayList<Edge> v = new ArrayList<Edge>();
        v.add(new Edge(1,7,12));
        v.add(new Edge(1,4,28));
        v.add(new Edge(1,2,67));
        v.add(new Edge(1,5,17));
        v.add(new Edge(2,4,24));
        v.add(new Edge(2,5,62));
        v.add(new Edge(3,5,20));
        v.add(new Edge(3,6,37));
        v.add(new Edge(4,7,13));
        v.add(new Edge(5,6,45));
        v.add(new Edge(5,7,73));


        Collections.sort(v,(a,b) -> a.distacne - b.distacne);

        int[] set = IntStream.range(0,n).toArray();

        int sum = 0;

        for (int i = 0; i < v.size(); i++) {
            if (!isfind(set,v.get(i).node[0] - 1,v.get(i).node[1] - 1)) {
                sum += v.get(i).distacne;
                unionParent(set,v.get(i).node[0] - 1,v.get(i).node[1] - 1);
          }
        }

        System.out.println("sum = " + sum);

    }

    private static void unionParent(int[] set,int a,int b) {
        a = getParent(set,a);
        b = getParent(set,b);
        if (a < b) set[b] = a;
        else set[a] = b;

    }

    // a,b는 좌표를 받아서 set함수에 부모가 존재하는지 확인한다.
    private static boolean isfind(int[] set,int a,int b) {
        a = getParent(set,a);
        b = getParent(set,b);
        if (a == b) return true;
        else return false;
    }

    private static int getParent(int[] set,int x) {
        if (set[x] == x) return x;
        return set[x] = getParent(set,set[x]);
    }
}

