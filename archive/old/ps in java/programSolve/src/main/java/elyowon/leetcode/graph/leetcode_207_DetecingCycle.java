package elyowon.leetcode.graph;


import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import static java.util.stream.Collectors.toCollection;


/**
 * DAG 에서 사이클이 존재하는지 체크하는 그래프
 *
 * 방향성이 없는곳에선 dfs가 편하다.
 * dfs에서 지나간곳을 다시 간다면 사이클이 존재한다고 볼수있다.
 *
 * 방향성 그래프에서 사이클을 못찾는 경우가 생길수있다.
 * 이럴때 O(v+e) * v 즉 모든 노드를 체크하면 확인한다면 O(v^2)에 검색가능하다.
 *
 * 하지만 이는 느리다. 더 효율적인 방법은 무엇인가.?
 *
 * postOder DFS
 * [] visited, []checked 을 생성해서
 * check는 cycle을 체크하는 배열이며 visited는 노드 방문 체크하는 배열이다.
 * 이를 통해서 O(v+e)가능 물론 메모리는 더쓴다.
 */


public class leetcode_207_DetecingCycle {

    public boolean canFinish(int numCourse,int[][] prerequisites) {
        HashMap<Integer, List<Integer>> adj = new HashMap<>();

        for (int[] prerequisite : prerequisites) {
            int prevCourse = prerequisite[0];
            int nextCourse = prerequisite[1];
            if (adj.get(prevCourse) != null) {
                adj.get(prevCourse).add(nextCourse);
            } else {
                List<Integer> nextList = new ArrayList<>();
                nextList.add(nextCourse);
                adj.put(prevCourse,nextList);
            }
        }

        boolean[] cyclePath = new boolean[numCourse];
        boolean[] visited = new boolean[numCourse];
        for (int currCourse = 0; currCourse < numCourse; currCourse++) {
            if (isCyclic(adj,currCourse,visited,cyclePath)) {
                return false;
            }
        }

        return true;
    }

    private boolean isCyclic(HashMap<Integer, List<Integer>> adj,int currCourse,boolean[] visited,boolean[] cyclePath) {

        if (visited[currCourse]) return false;
        if (cyclePath[currCourse]) return true;

        if (adj.get(currCourse) == null) return false;

        cyclePath[currCourse] = true;

        boolean ret = false;
        for (int nextCourse : adj.get(currCourse)) {
            ret = isCyclic(adj,nextCourse,visited,cyclePath) ;
            if (ret) {
                break;
            }
        }

        cyclePath[currCourse] = false;
        visited[currCourse] = true;

        return ret;
    }
}