package me.elyowon.leetcode.tree;


import java.util.LinkedList;
import java.util.List;


/**
 *
 * 주어진 트리에서 패스섬을 찾으라.
 *      5
 *    4   8
 *  11   13  4
 * 7  2     5  1
 *
 *
 * 방법은 트리순회및 백트래킹을 이용해서 풀수있다.
 *
 */

public class leetcode_113_tree {

    public List<List<Integer>> pathSum(TreeNode root,int sum) {
        List<List<Integer>> result = new LinkedList<List<Integer>>();

        process(root,sum,new LinkedList<Integer>(),result);
        return result;

    }

    private void process(TreeNode node,int sum,LinkedList<Integer> curr,List<List<Integer>> result) {

        if (node == null) {
            return;
        }
        curr.add(node.val);
        if ((node.left == null && node.right == null) & node.val == sum) {
            result.add(new LinkedList<Integer>(curr));
        }
        process(node.left,sum - node.val,curr,result);
        process(node.right,sum - node.val,curr,result);
        curr.remove(curr.size() - 1);
    }

}
