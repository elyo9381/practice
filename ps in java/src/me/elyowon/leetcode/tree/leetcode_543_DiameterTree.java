package me.elyowon.leetcode.tree;


import java.util.HashMap;
import java.util.Stack;

/**
 *
 * 주어진 트리에서 하나의 노드에서 다른 노드의 길이가 최대인것
 * 꼭 root를 거칠 필요는 없다.
 *
 * 트리 순회를 잘이용하자 트리문제에서는
 * 자 그러면 이를 iter로 풀어보자
 *
 */

public class leetcode_543_DiameterTree {

    public int DiameterTree(TreeNode root) {
        int[] res = new int[1];
        res[0] = 0;
        process(root,res);
        return res[0];
    }

    private void process(TreeNode node,int[] res) {
        // left,right 모두 null일때 parent로 올라가며 이때 left의 마지막 노드를 방문 체크 노드
        TreeNode lastNode = null;
        TreeNode curNode = node;

        // post의 포인터가 될 스택 ( left,right 모두 null일때 parent로 돌아가야하므로)
        Stack<TreeNode> s = new Stack<TreeNode>();
        s.add(curNode);

        // post의 left,right 정보를 저장한 해쉬
        HashMap<TreeNode, Integer> map = new HashMap<>();


        while(true){
            if(curNode != null){
                s.add(curNode);
                curNode = curNode.left;
            } else if (!s.empty()){
                // 스택으로 들어왔다는 의미는 left -> right 노드를 옮겼다는 의미
                TreeNode peekNode = s.peek();
                // 노드의 오른쪽 자식이 있음을 의미
                if(peekNode.right != null && lastNode != peekNode.right){
                    curNode = peekNode.right;
                } else {
                    // 노드의 자식이 모두 null 일때
                    lastNode = s.pop();
                    // 해당 노드의 left,right의 뎁스를 구함
                    // getOrDefault(key,defultValue) : 키를 찾고 없으면 디폴트 반환
                    int leftDepth = map.getOrDefault(peekNode.left, 0);
                    int rightDepth = map.getOrDefault(peekNode.right, 0);
                    // 현재 peekNode를 키로 뎁스를 저장
                    map.put(peekNode, 1 + Math.max(leftDepth, rightDepth));
                    res[0] = Math.max(res[0], leftDepth + rightDepth);
                }
            } else
                break;
        }
        return ;
    }


//    private int process(TreeNode node,int[] res) {
//        if(node == null){
//            return 0;
//        }
//        int lDepth = 0;
//        int rDepth = 0;
//        lDepth = process(node.left,res);
//        rDepth = process(node.right,res);
//        res[0] = Math.max(res[0], lDepth+rDepth);
//
//        return Math.max(lDepth,rDepth)+1;
//    }


}
