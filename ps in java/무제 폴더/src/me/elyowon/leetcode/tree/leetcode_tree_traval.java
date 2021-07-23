package me.elyowon.leetcode.tree;


public class leetcode_tree_traval {

    /**
     *
     *
     *
     *
     *
     */

    public static void main(String[] args) {

        TreeNode node1 = new TreeNode(1);
        TreeNode node2 = new TreeNode(2);
        TreeNode node3 = new TreeNode(3);
        TreeNode node4 = new TreeNode(4);
        TreeNode node5 = new TreeNode(5);
        TreeNode node6 = new TreeNode(6);
        TreeNode node7 = new TreeNode(7);

        node1.left = node2;
        node1.right = node3;
        node2.left = node4;
        node2.right = node5;
        node3.left = node6;
        node3.right = node7;


        node1.recurPreOrder(node1);
        System.out.println();
        node1.iterPreOrder(node1);

        System.out.println();
        System.out.println("==================");
        node1.recurInOrder(node1);
        System.out.println();
        node1.iterInOrder(node1);

        System.out.println();
        System.out.println("==================");
        node1.recurPostOrder(node1);
        System.out.println();
        node1.iterPostOrder(node1);


    }

}
