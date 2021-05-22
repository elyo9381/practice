package me.elyowon.leetcode.graph;


import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;


/**
 * edges가 주어지고 이를 그래프로 만들고
 * 만들어진 그래프의 component가 몇개인지 구하는 문제
 *
 *
 */


public class leetcode_323_connectedComponent {
    public static void main(String[] args) {

        int[][] edges = {{3,4},{2,1},{3,2}};
        int n = 5;
        int i = countComponents1(n,edges);
        System.out.println("i = " + i);

    }

    public static int countComponents1(int n,int[][] edges) {
        int[] root = new int[n];
        for (int i = 0; i < n; i ++) {
            root[i] = i;
        }
        int count = n;
        for (int i = 0; i < edges.length; i ++) {
            int r1 = getRoot(root, edges[i][0]);
            int r2 = getRoot(root, edges[i][1]);
            if (r1 != r2) {
                root[r1] = r2;
                count --;
            }
        }
        return count;
    }
    private static int getRoot(int[] root,int i) {
        while (root[i] != i) {
            root[i] = root[root[i]];
            i = root[i];
        }
        return i;
    }

    public static int countComponents(int n,int[][] edges) {
        HashMap<Integer, List<Integer>> adj = new HashMap<>();
        init(adj,edges,n);
        boolean[] visited = new boolean[n];
        int count = 0;
        for (int i = 0; i < n; i++) {
            if(visited[i] == false){
                count ++;
                dfs(adj, i,visited);
            }
        }
        return count;
    }

    private static void dfs(HashMap<Integer, List<Integer>> adj,int index,boolean[] visited) {
        visited[index] = true;
        for ( Integer j : adj.get(index)){
            if ( visited[j] == false){
                dfs(adj,j,visited);
            }
        }

    }

    private static void init(HashMap<Integer, List<Integer>> adj,int[][] edges,int n) {
        for (int i = 0; i < n; i++) {
            adj.put(i, new LinkedList<Integer>());
        }

        for (int i = 0; i < edges.length; i++) {
            adj.get(edges[i][0]).add(edges[i][1]);
            adj.get(edges[i][1]).add(edges[i][0]);
        }
    }

}
