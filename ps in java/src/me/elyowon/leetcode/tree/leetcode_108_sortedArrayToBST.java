package me.elyowon.leetcode.tree;


/**
 * height banlanced tree 만들기
 *
 */

public class leetcode_108_sortedArrayToBST {


    public static void main(String[] args) {
        int[] nums = {1,2,3,4,5,6,7,8,9};

        TreeNode result = sortdArrayToBST(nums);
    }

    private static TreeNode sortdArrayToBST(int[] nums) {

        if(nums.length ==0)return null;
        return buildBST(nums,0,nums.length-1);
    }

    private static TreeNode buildBST(int[] nums,int s,int e) {
        if(s > e) return null;
        else {
            int mid = (s + e) /2;
            TreeNode node = new TreeNode((nums[mid]));
            node.left = buildBST(nums,s,mid-1);
            node.right = buildBST(nums,mid+1,e);
            return node;
        }
    }


}
