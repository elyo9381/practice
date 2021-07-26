package elyowon.leetcode.graph;


import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.stream.Stream;


/**
 * 그래프를 복사할때
 *
 * bfs를 이용해서 노드 탐색
 * 해쉬맵에 vertex를 동일하게 가지는 vertex'(버텍스프라임)을 만든다.
 * 그리고 해쉬맵에서 노드를 검색했을때 검색되면 노드의 엣지를 연결한다.
 *
 * 대체적으로 val과 link로 자료구조를 갖는거같다.
 * 그래프는 리스트를 활용해서 사용한다.
 *
 *
 */
class Node {
    int val;
    List<Node> neighbors;

    Node(int x) {
        val = x;
        neighbors = new ArrayList<Node>();
    }
};

public class leetcode_133_CloneGraph {

    public Node cloneGraph(Node node){
        if(node == null){
            return null;
        }

        LinkedList<Node> q = new LinkedList<>();
        HashMap<Integer, Node> map = new HashMap<>();
        q.add(node);
        map.put(node.val, new Node(node.val));

        while(!q.isEmpty()){
            Node now = q.pollFirst();
            Node copied = map.get(now.val);

            now.neighbors.forEach(neighbor -> {
                if (map.get(neighbor.val) == null) {
                    q.add(neighbor);
                    map.put(neighbor.val,new Node(neighbor.val));
                }
                copied.neighbors.add(map.get(neighbor.val));
            });
        }// while
        return map.get(node.val);
    }
}