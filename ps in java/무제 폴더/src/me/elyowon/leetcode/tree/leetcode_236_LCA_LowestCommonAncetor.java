package me.elyowon.leetcode.tree;


import java.util.HashMap;
import java.util.Stack;

/**
 * 여러가지 노드가 파라미터가 주어질때 공통 부모 노드 찾기
 * <p>
 * - 심플한 풀이
 * 각 노드별 트리 순회를 진행한다.
 * <p>
 * - 리커시브 포스트 order를 사용하자
 */

public class leetcode_236_LCA_LowestCommonAncetor {

    public TreeNode lowestCommonAncestor(TreeNode root,TreeNode p,TreeNode q) {

        if (root == null) {
            return null;
        }

        if (root == p || root == q) {
            return root;
        }

        TreeNode left = lowestCommonAncestor(root.left,p,q);
        TreeNode right = lowestCommonAncestor(root.right,p,q);
        if (!(left == null && right == null)) {
            return root;
        }

        if (left == null) {
            return right;
        }
        if (right == null) {
            return left;
        }
        return null;
    }
}
