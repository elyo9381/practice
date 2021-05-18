package me.elyowon.leetcode.tree;

import java.util.Stack;

public class TreeNode {

    public int val;
    public TreeNode left;
    public TreeNode right;

    public TreeNode(int val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }

    public void recurPreOrder(TreeNode node) {
        if (node == null) {
            return;
        }

        System.out.print(" " + node.val);
        recurPreOrder(node.left);
        recurPreOrder(node.right);
    }

    public void iterPreOrder(TreeNode node) {
        if (node == null) {
            return;
        }

        Stack<TreeNode> s = new Stack<>();
        s.add(node);
        while (!s.isEmpty()) {
            TreeNode pop = s.pop();
            System.out.print(" " + pop.val);
            if (pop.right != null) {
                s.add(pop.right);
            }
            if (pop.left != null) {
                s.add(pop.left);
            }
        }
    }

    public void recurInOrder(TreeNode node) {
        if (node == null) {
            return;
        }

        recurInOrder(node.left);
        System.out.print(" " + node.val);
        recurInOrder(node.right);
    }

    public void iterInOrder(TreeNode node) {
        TreeNode crntNode = node;
        Stack<TreeNode> s = new Stack<>();

        while (true) {
            if (crntNode != null) {
                s.add(crntNode);
                crntNode = crntNode.left;
            } else if (!s.isEmpty()) {
                crntNode = s.pop();
                System.out.print(" " + crntNode.val);
                crntNode = crntNode.right;
            } else
                break;
        }
    }

    public void recurPostOrder(TreeNode node) {
        if (node == null) {
            return;
        }
        recurPostOrder(node.left);
        recurPostOrder(node.right);
        System.out.print(" " + node.val);
    }

    public void iterPostOrder(TreeNode node) {
        TreeNode crntNode = node;
        TreeNode lastVisitNode = null;
        Stack<TreeNode> s = new Stack<>();

        while (true) {
            if (crntNode != null) {
                s.add(crntNode);
                crntNode = crntNode.left;
            } else if (!s.isEmpty()) {
                TreeNode peekNode = s.peek();
                if (peekNode.right != null && (lastVisitNode != peekNode.right)) {
                    crntNode = peekNode.right;
                } else {
                    System.out.print(" " + peekNode.val);
                    lastVisitNode = s.pop();
                }
            } else {
                break;
            }
        }
    }
}