package elyowon.leetcode.tree;


/**
 *
 *
 */

public class leetcode_98_BinarySearchTree {

    public boolean isBST(TreeNode root){
        return validate(root,Integer.MIN_VALUE,Integer.MAX_VALUE);
    }

    private boolean validate(TreeNode node,long min,long max) {

        if (node == null){
            return true;
        }

        if(node.val < min || node.val > max){
            return false;
        }
        return validate(node.left, min, (long)node.val - 1) &&
                validate(node.right, (long)node.val + 1, max);
    }
}
