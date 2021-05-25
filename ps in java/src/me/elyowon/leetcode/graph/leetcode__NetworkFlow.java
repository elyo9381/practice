package me.elyowon.leetcode.graph;


import java.util.*;


/**
 *
 * c(u,v) 정점 u 에서 v로 가는 간선의 용량(capacity)
 * f(u,v) 정점 u 에서 v로 실제 흐르는 유량(flow)
 *
 *  유량 네트워크가 만족해야하는 세가지 속성
 *   - 유량 제한 속성 : f(u,v) <= c(u,v)
 *   - 유량의 대칭성 : f(u,v) = -f(v,u)    (각 좌표에서 양방으로 가는게 유량이 같다)
 *      u에서 v로 유량이 흐르면 v에서 u로 음수의 유량이 흐르는것과 동일
 *   - 유량의 보존 : 써메이션v f(u,v) = 0   (두 버텍스에서 오고가는 유량의 합은 0이라는 것이다.)
 *      각 정점에 들어오는 유량과 나가는 유량은 같음
 *
 *
 *  포드 풀커슨 알고리즘 :
 *    s(source) : 출발점
 *    t(sink) : 도착점
 *
 *    간선은 초기 0으로 설정한다.
 *
 */


public class leetcode__NetworkFlow {


    public class FordFulkerson {

        public int networkFlow(int source, int sink,int vertexNum,int[][] capacity,int[][] flow){
            int totalFlow = 0;
            while(true){ //최대 maxflow번 반복함
                int[] parent = new int[vertexNum];
                Arrays.fill(parent, -1);
                Queue<Integer> q = new LinkedList<>();
                parent[source] = source;
                q.add(source);
                while(!q.isEmpty() && parent[sink] == -1){
                    int here = q.poll();
                    for(int there=0; there<vertexNum; there++){
                        if(capacity[here][there] - flow[here][there] > 0 && parent[there] == -1){
                            q.add(there);
                            parent[there] = here;
                        }
                    }
                }
                if(parent[sink] == -1) break;
                int amount = Integer.MAX_VALUE;
                for(int p = sink; p != source; p = parent[p]){
                    amount = Math.min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
                }
                for(int p = sink; p != source; p = parent[p]){
                    flow[parent[p]][p] += amount;
                    flow[p][parent[p]] -= amount;
                }
                totalFlow += amount;
            }
            return totalFlow;
        }
    }
}