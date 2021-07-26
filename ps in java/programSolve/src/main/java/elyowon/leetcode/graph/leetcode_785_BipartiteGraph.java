package elyowon.leetcode.graph;


import java.util.LinkedList;
import java.util.Queue;

/**
 *
 *
 * BiPartite graph
 * 두가지로 나눌수잇는 그래프이다.
 * 즉 같은 vertex가 한 엣지로 연결되면 두개의 파티션 존재하지 않는것이다.
 * 즉 번갈아가면서 이다. 단순하게 말하자
 *
 * 그래프 탐색하면서 엣지로 연결된 노드가 현재 노드와 다른지만 확인하면된다.
 */


public class leetcode_785_BipartiteGraph {

    public boolean isBipartite(int[][] graph){
        int n = graph.length;
        // 하나의 엣지로 이어진 버텍스가 다른 색이여야 하므로
        // 버텍스 갯수만큼 check할 배열을 만든다. map으로 만들어도 된다.
        int[] colors = new int[n];


        // 각각의 버텍스의 유효성을 체크한다.
        for (int i = 0; i < n; i++) {
            if(colors[i] == 0 && vaildColor(graph,colors,1,i)){
                return false;
            }
        }

        return true;
    }

    private boolean vaildColor(int[][] graph,int[] colors,int color,int node) {
        if(colors[node] != 0){
            return colors[node] == color;
        }

        colors[node] = color;
        for(int next : graph[node])
            if(!vaildColor(graph,colors, -color,next)){
                return false;
            }
        return true;
    }


    public boolean isBipartite_bfs(int[][] graph){
        int len = graph.length;
        int [] colors = new int[len];

        for (int i = 0; i < len; i++) {
            if(colors[i] != 0) continue;
            Queue<Integer> queue = new LinkedList<>();
            queue.add(i);
            colors[i] = 1;

            while(!queue.isEmpty()){
                int cur = queue.poll();
                for (int next : graph[cur]) {
                    if(colors[next] == 0){
                        colors[next] = -colors[cur];
                        queue.offer(next);
                    } else if(colors[next] != -colors[cur]){
                        return false;
                    }
                }
            }
        }

        return true;
    }

}
