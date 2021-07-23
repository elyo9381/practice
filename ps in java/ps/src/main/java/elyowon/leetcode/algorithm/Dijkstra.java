package elyowon.leetcode.algorithm;

import java.util.*;
import java.util.stream.IntStream;

/**
 * 다익스트라 알고리즘 : 최단경로를 찾기 위한 알고리즘
 * 하나의 정점에서 다른 모든 정점으로 가는 최단경로를 알려줍니다.
 * <p>
 * 1 출발노드를 설정합니다.
 * 2 출발노드를 기준으로 각 노드의 최소비용을 저장합니다.
 * 3 방문하지 않는 노드중에서 가장 비용이 적은 노드를 선택합니다.
 * 4 해당노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소비용을 갱신합니다.
 * 5 위 과정에서 3-4을 반복합니다.
 */

public class Dijkstra {
    public static class Edge {
        int vertex;
        int weight;

        public Edge(int vertex,int weight) {
            this.vertex = vertex;
            this.weight = weight;
        }
    }

    ;

    public static int number = 6;
    public static int INF = Integer.MAX_VALUE;

    public static ArrayList<Edge>[] graph = new ArrayList[number + 1];
    public static int[] d = new int[7];


    public static void main(String[] args) {

        for (int i = 1; i <= number; i++) {
            d[i] = INF;
        }


        IntStream.rangeClosed(1,number).forEach(i -> graph[i] = new ArrayList<>());

        graph[1].add(new Edge(2,2));
        graph[1].add(new Edge(3,5));
        graph[1].add(new Edge(4,1));

        graph[2].add(new Edge(1,2));
        graph[2].add(new Edge(3,3));
        graph[2].add(new Edge(4,2));

        graph[3].add(new Edge(1,5));
        graph[3].add(new Edge(2,3));
        graph[3].add(new Edge(4,3));
        graph[3].add(new Edge(5,1));
        graph[3].add(new Edge(6,5));

        graph[4].add(new Edge(1,1));
        graph[4].add(new Edge(2,2));
        graph[4].add(new Edge(3,3));
        graph[4].add(new Edge(5,1));

        graph[5].add(new Edge(3,1));
        graph[5].add(new Edge(4,1));
        graph[5].add(new Edge(6,2));

        graph[6].add(new Edge(3,5));
        graph[6].add(new Edge(5,2));

        dijstra(1);


        for (int i = 1; i <= number; i++) {
            System.out.println("d[i] = " + d[i]);
        }


    }

    private static void dijstra(int start) {
        d[start] = 0;
        PriorityQueue<Edge> minHeap = new PriorityQueue<Edge>((a,b)-> a.weight - b.weight);

        minHeap.offer(new Edge(start,0));

        while (!minHeap.isEmpty()) {
            Edge edge = minHeap.poll();
            int current = edge.vertex;
            int dis = edge.weight;

            // 더 작은 비용으로 갈수있는 노드가 존재한다는 뜻이다.
            if(d[current] < dis) continue;

            // edge.first].get(i).first;
            // next의 노드의 길의 중에 가장 작은 값을 선별
            int bound = graph[current].size();

            for (int i = 0; i < bound; i++) {
                int next = graph[current].get(i).vertex;
                int nextDis = graph[current].get(i).weight + dis;

                // nextDis가 더 작은 비용으로 움직일수있는 노드라는 뜻이다.
                if (nextDis < d[next]) {
                    d[next] = nextDis;
                    minHeap.offer(new Edge(next,nextDis));
                }
            }
        }
    }
}

