package me.elyowon.leetcode.tree;


import java.util.HashMap;

/**
 *
 *        3
 *     9     20
 *   5  8  15  7
 *
 * TreeNode {
 *     val
 *     left
 *     right
 *     next : 같은 레벨의 오른 노드를 가르킨다.
 * }
 *
 * 만드는 방법은 두가지가 존재한다.
 * 방법1
 * 큐를 이용해서 같은 레벨일때 next를 연결하는 방법
 *
 * 방법2
 * 임시 노드를 생성해서 next를 노드를 비동기적으로 사용하는 방법
 *
 */

public class leetcode_117_nextRightPointers {

    public void connect(TreeNode root){
        TreeNode fakeHead = new TreeNode(0);
        TreeNode node = fakeHead;
        while(root != null){
            if(root.left != null){
                node.next = root.left;
                node = node.next;
            }
            if(root.right != null){
                node.next = root.right;
                node = node.next;
            }
            root = root.next;
            if(root == null){
                node = fakeHead;
                root = fakeHead.next;
                fakeHead.next=null;
            }
        }
    }
}
