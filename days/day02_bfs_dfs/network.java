import java.util.*;
import java.io.*;

// 네트워크 
public class Main {

    // 이 메서드를 작성해
    public static int solution(int n, int[][] computers) {
        int answer = 0;
        boolean[] visited = new boolean[n];

        for(int i = 0; i<n; i++){
                if( !visited[i] ){
                    dfs(i,computers,visited, n);
                    answer++;
            }
        }
        return answer;
    }

    private static void dfs(int node , int[][] computers , boolean[] visited, int n ){
        if( visited[node] ) return;
        visited[node] = true;

        for(int i = 0 ; i < n ; i++){
            if(node == i ) continue;
            if(computers[node][i] == 1 && !visited[i] ) {
                dfs(i, computers, visited, n);
            }
        }
    }
}
