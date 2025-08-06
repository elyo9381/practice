package elyowon.programers.prgmStudy.week_3;

import java.util.PriorityQueue;

public class 네트워크 {
    public int solution(int n, int[][] computers) {
        int answer = 0;
        boolean[] visited = new boolean[n];

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(n,i,computers,visited);
                answer++;
            }
        }
        return answer;
    }

    private void dfs(int n,int index,int[][] computers,boolean[] visited) {
        visited[index] = true;

        for (int i = 0; i < n; i++) {
            if (computers[index][i] == 1 && i != index && !visited[i])
                dfs(n,i,computers,visited);
        }
    }
}