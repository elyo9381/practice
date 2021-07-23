package elyowon.leetcode.graph;


import java.util.*;


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
        ArrayList<int[]> temp1 = new ArrayList<int[]>();
        ArrayList<int[]> temp2 = new ArrayList<int[]>();
        temp1.clear();
        temp1.remove(0);
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

    public int solution(int n, int[][] wires) {

        int count = 0;

        int x = wires.length;
        int y = wires[0].length;

        boolean visited[] = new boolean[x];

        ArrayList<int[]> temp1 = new ArrayList<int[]>();
        ArrayList<int[]> temp2 = new ArrayList<int[]>();

        for(int i = 0 ; i< wires.length; i++){
            visited[i] = true;
            for(int j =0; j<wires.length; j++){
                if( visited[j] != false){
                    temp1.add(wires[j]);
                } else {
                    temp2.add(wires[j]);
                }
            }

            findNodeCount(temp1,n);


            visited[i] = false;
        }

        return count;

    }


    private int findNodeCount(ArrayList<int[]> temp1,int n) {
        int[] root = new int[n];
        for (int i = 0; i < n; i ++) {
            root[i] = i;
        }
        int count = n;
        for (int i = 0; i < temp1.size(); i ++) {
            int r1 = getRoot1(root, temp1.get(i)[0]-1);
            int r2 = getRoot1(root,temp1.get(i)[0]-1);
            if (r1 != r2) {
                root[r1] = r2;
                count --;
            }
        }
        return count;
    }
    private static int getRoot1(int[] root,int i) {
        while (root[i] != i) {
            root[i] = root[root[i]];
            i = root[i];
        }
        return i;
    }

}
