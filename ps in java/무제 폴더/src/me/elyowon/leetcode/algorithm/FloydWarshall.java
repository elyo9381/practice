package me.elyowon.leetcode.algorithm;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.stream.IntStream;

/**
 *
 * 다익스트라는 한정점에서 모든정점으로 가는 최단경로이다.
 *
 * 플로이드 와샬은 모든 정점에서 모든정점으로 가는 최단경로이다.
 *
 *
 */

public class FloydWarshall {
    public static class Edge {
        int vertex;
        int weight;

        public Edge(int vertex,int weight) {
            this.vertex = vertex;
            this.weight = weight;
        }
    }

    public static int number = 4;
    public static int INF = 100000;

    public static ArrayList<Edge>[] graph = new ArrayList[number + 1];


    public static void main(String[] args) {

        int bound = number;
        for (int i = 0; i < bound; i++) {
            graph[i] = new ArrayList<>();
        }

        graph[0].add(new Edge(1,0));
        graph[0].add(new Edge(2,5));
        graph[0].add(new Edge(3,INF));
        graph[0].add(new Edge(4,8));

        graph[1].add(new Edge(1,7));
        graph[1].add(new Edge(2,0));
        graph[1].add(new Edge(3,9));
        graph[1].add(new Edge(4,INF));

        graph[2].add(new Edge(1,2));
        graph[2].add(new Edge(2,INF));
        graph[2].add(new Edge(3,0));
        graph[2].add(new Edge(4,4));

        graph[3].add(new Edge(1,INF));
        graph[3].add(new Edge(2,INF));
        graph[3].add(new Edge(3,3));
        graph[3].add(new Edge(4,0));

        floydWarshall();

    }

    private static void floydWarshall() {

        int[][] d = new int[number][number];

        for (int i = 0; i < number; i++) {
            for (int j = 0; j < number; j++) {
                d[i][j] = graph[i].get(j).weight;
            }
        }

        // k거쳐가는 노드
        for (int k = 0; k < number; k++) {
            //출발 노드
            for (int i = 0; i < number; i++) {
                //도착노드
                for (int j = 0; j < number; j++) {
                    if(d[i][k] + d[k][j] < d[i][j]){
                        d[i][j] = d[i][k] + d[k][j];
                    }
                }
            }
        }

        for (int i = 0; i < number; i++) {
            for (int j = 0; j < number; j++) {
                System.out.print(" " + d[i][j]);
            }
            System.out.println();
        }
    }

}

