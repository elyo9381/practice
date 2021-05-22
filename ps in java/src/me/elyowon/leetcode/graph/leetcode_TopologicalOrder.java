package me.elyowon.leetcode.graph;


import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;


/**
 * DAG 이 존재하면서 사이클이 없는 그래프이다.
 * 이를 linear하게 정렬하는 그래프이다.
 *
 * 이는 여러가지의값이 나올수있다.
 *
 * 1. vertex만큼 공간을 만든뒤
 * 0 으로 초기화 한다.
 *
 * 2. 다른 vertex에 종속되지 않는 vertex 찾기
 * 각 노드에 indegree가 필요하다 (노드에 들어오는 엣지) , outdegree(노드에서 나가는 엣지)
 * indegree가 0 이면 종속되지 않는 노드이다.
 * indegree를 계산하고 이를 1에 기록한다.
 *
 * 3.큐에 indegree가 0인 노드를 큐에 넣고
 * dequeue하면서 해당 노드의 edge가 있는 노드의 indegree를 줄인다.
 *
 * 4.3반복
*
 * 예제 269-leetcode
 *
 */


public class leetcode_TopologicalOrder {

    public static void main(String[] args) {
        int[][] vertex = {{1,3},{2,5},{},{2},{1},{}};

        List<List<Integer>> graph =  new ArrayList<List<Integer>>();



        for (int i = 0; i <vertex.length; i++) {
            List<Integer> list = new ArrayList<Integer>();
            for (int j = 0; j < vertex[i].length; j++) {
                list.add(vertex[i][j]);
            }
            graph.add(list);
        }

        List result = topologicalOrder(graph);

        for (Object sortedIndex : result) {
            System.out.println("sortedIndex = " + sortedIndex);
        }
    }

    private static List topologicalOrder(List<List<Integer>> graph) {
        int vertexNum = graph.size();
        int[] indegree = new int[vertexNum];

        Arrays.fill(indegree,0);

        for (List<Integer> vertexs : graph) {
            for (Integer vertex : vertexs) {
                indegree[vertex] +=1;
            }
        }

        Queue<Integer> q = new LinkedList<>();

        for (int i = 0; i < indegree.length; i++) {
            if(indegree[i] == 0){
                q.add(i);
            }
        }

        List<Integer> result = new ArrayList<Integer>();

        while(!q.isEmpty()){
            Integer indegreeZeroVertex = q.poll();
            result.add(indegreeZeroVertex);

            List<Integer> vertex = graph.get(indegreeZeroVertex);
            for (Integer checkingVertex : vertex) {
                indegree[checkingVertex] -=1;
                if(indegree[checkingVertex] == 0){
                    q.add(checkingVertex);
                }
            }
        }

        return result;
    }
}