package me.elyowon.leetcode.graph;


import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

import static java.util.stream.Collectors.toCollection;


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

    public static void main(String[] args) throws IOException {
        int[][] vertex = {{1,3},{2,5},{},{2},{1},{}};

        List<List<Integer>> graph = Arrays.stream(vertex)
                .map(ints -> Arrays.stream(ints).boxed().collect(Collectors.toList()))
                .collect(Collectors.toList());

        List result = topologicalOrder(graph);

        result.stream().map(x -> x + " ").forEach(System.out::print);

        Files.walk(Paths.get("."))
                .filter(p -> !p.toString().contains(File.separator + "."))
                .forEach(x1 -> System.out.println(x1));

        List<Integer> list =
                IntStream.range(0, 10)
                        .boxed()
                        .collect(toCollection(ArrayList::new));

        list.stream()
                // remove(Object), not remove(int)!
                .sorted()
                .parallel()
                .peek(list::remove)
                .forEach(System.out::println);



    }

    private static List<Integer> topologicalOrder(List<List<Integer>> graph) {
        int vertexNum = graph.size();
        int[] indegree = new int[vertexNum];

        Arrays.fill(indegree,0);

        graph.forEach(vertexs -> vertexs.forEach(vertex -> indegree[vertex] += 1));

        Queue<Integer> q = IntStream.range(0,indegree.length).filter(i -> indegree[i] == 0).boxed().collect(toCollection(LinkedList::new));

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