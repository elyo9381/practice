package me.elyowon.programers.L2;


import java.util.*;
import java.util.stream.IntStream;

/**
 * 하나의 정점에서 다른 정점의에서의 거리를 체크하는 문제이다.
 * 다익스크라 및 플루이드 워샬로 풀수있는 문제이다.
 *
 */
public class L2_210707_배달 {

    static class Edge{
        int vertex;
        int weight;

        public Edge(int a, int b){
            this.vertex= a;
            this.weight = b;
        }
    }
    public static int INF = Integer.MAX_VALUE;

    public static ArrayList<Edge>[] graph;




    public int solution(int N, int[][] road, int k){
        int answer = 0;

        int[] d = new int[N+1];
        graph = new ArrayList[N+1];
        IntStream.rangeClosed(1,N).forEach(i -> d[i] = INF);
        IntStream.rangeClosed(1,N).forEach(
                i -> graph[i] = new ArrayList<>()
        );

        for(int[] street : road){
            int nodeA = street[0];
            int nodeB = street[1];
            int distance = street[2];

            graph[nodeA].add(new Edge(nodeB,distance));
            graph[nodeB].add(new Edge(nodeA,distance));
        }

        return dijstra(1,d,k,N);


    }

    private static int dijstra(int start,int[] d,int k,int N) {

        d[start] = 0;

        PriorityQueue<Edge> minHeap = new PriorityQueue<>((a,b)-> a.weight - b.weight);
        minHeap.add(new Edge(start,0));

        while(!minHeap.isEmpty()){
            Edge edge = minHeap.poll();

            int current = edge.vertex;
            int dis = edge.weight;

            if(d[current] < dis) continue;

            int bound = graph[current].size();

            for(int i =0; i<bound; i++){
                int next = graph[current].get(i).vertex;
                int nextDis = graph[current].get(i).weight + dis;

                if( nextDis < d[next]){
                    d[next] = nextDis;
                    minHeap.offer(new Edge(next, nextDis));
                }
            }
        }

        int count = 0;

        for(int i =1; i<=N; i++){
            if(d[i] <= k) count +=1;
            System.out.println(d[i]);
        }

        return count;
    }


    public int solution1(int N ,int[][] road , int k){
        int answer = 0;

        ArrayList<Edge>[] graph = new ArrayList[N+1];

        IntStream.rangeClosed(1,N).forEach(i-> graph[i] = new ArrayList<>());

        for(int[] street : road){
            int nodeA = street[0];
            int nodeB = street[1];
            int distance = street[2];
            graph[nodeA].add(new Edge(nodeB, distance));
        }

        floydWarshall(graph,N,k,road);


        return answer;
    }

    private int floydWarshall(ArrayList<Edge>[] graph,int n,int z ,int[][] road) {
        int[][] d = new int[n+1][n+1];


        for (int i = 1; i <=n; i++) {
            for (int j = 1; j <= n; j++) {
                if(i == j) d[i][j] = 0;
                d[i][j] = INF;
            }
        }

        for(int[] street : road){
            int a = street[0];
            int b = street[1];
            int c = street[2];
            if( d[a][b] < c) continue;
            d[a][b] = c;
            d[b][a] = c;
        }

        for (int k = 1; k <= n; k++) {
            //출발 노드
            for (int i = 1; i <= n; i++) {
                //도착노드
                for (int j = 1; j <= n; j++) {
                    if(d[i][k] + d[k][j] < d[i][j]){
                        d[i][j] = d[i][k] + d[k][j];
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                System.out.print(" " + d[i][j]);
            }
            System.out.println();
        }

        return 0;
    }
}
