package elyowon.leetcode.graph;


import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;


/**
 * directed Graph
 * 방향이 있는 그래프
 * DAG(directed Acyclic Graph)
 * <p>
 * weight graph
 * 가중치가 있는 그래프
 * <p>
 * cyclic graph
 * <p>
 * 그래프 표현 두가지 방법
 * value 와 link로 표현
 * matric로 표현(2차원 배열)
 * <p>
 * graph traversals
 * DFS
 * pre,in,post (order)와 비슷하다.
 * BFS
 */


public class leetcode_841_graph {

    public boolean canVisitAllRooms(List<List<Integer>> rooms) {

        LinkedList<Integer> queue = new LinkedList<>();
        HashSet<Integer> visited = new HashSet<>();

        visited.add(0);
        queue.add(0);

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                for (int room : rooms.get(queue.pollFirst())) {
                    if (!visited.contains(room)) {
                        queue.add(room);
                        visited.add(room);
                    }
                }
            }
        }

        return visited.size() == rooms.size() ? true : false;
    }

    public boolean canVisitAllRooms2(List<List<Integer>> rooms) {
        HashSet<Integer> visited = new HashSet<>();
        dfs(0,visited,rooms);
        return visited.size() == rooms.size();
    }

    private void dfs(int room,HashSet<Integer> visited,List<List<Integer>> rooms) {
        visited.add(room);
        for (int key : rooms.get(room)) {
            if (!visited.contains(key)) dfs(key,visited,rooms);
        }
    }
}