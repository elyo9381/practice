package elyowon.leetcode.tree;


import java.util.HashMap;

/**
 * 3
 * 9  20
 * 15  7
 * 를 만들어라
 * <p>
 * preOrder, inOrder가 주어질떄
 * 방법 1
 * preorder의 배열의 첫번째 인덱스는 최상위 루트인 특성
 * inorder의 루트 전까지는 왼쪽 노드라는 특성을 이용해서
 * 내부적으로 계속 배열을 만들고 root노드를 반환하게 한다.
 * 재귀적으로 끝나면 root노드에 붙여주면 left,right를 붙여주면 트리가 만들어진다.
 * <p>
 * 방법2
 * 방법1은 preoder의 첫번째 인덱스가 루트란점 그리고 이를 inorder에서 반복적으로 찾아야하는점에서 o(n^2)이다.
 * inorder에서 조금더 빠르게 찾을수있다면 시간복잡도를 줄일수있을것이다.
 * 이를 위해서 inorder에서 hashmap을 이용해서 빠른 검색을 만들고 재귀를 돌린다.
 */

public class leetcode_105_ConstructTreeTraversal {

    public static void main(String[] args) {
        int[] preOrder = {1,3,7,5,2,4};
        int[] inOrder = {7,3,1,2,5,4};
        TreeNode result = buildTree(preOrder,inOrder);

        result.iterPreOrder(result);

        System.out.println();
        int num = 10;
        int ret = countBit(num);
        System.out.println("ret = " + ret);


    }

    public static int countBit(int value) {
        int count = 0;
        while (value != 0) {
            System.out.println("(value-1) = " + (value-1));
            value = value & (value - 1);

            count++;
        }
        return count;
    }

    public static TreeNode buildTree(int[] preorder,int[] inorder) {
        if (preorder == null || inorder == null || preorder.length == 0 || inorder.length == 0 || preorder.length != inorder.length) {
            return null;
        }
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < inorder.length; i++) {
            map.put(inorder[i],i);
        }
        return build(preorder,inorder,0,preorder.length - 1,0,inorder.length - 1,map);
    }

    private static TreeNode build(int[] preOrder,int[] inOrder,int preL,int preR,int inL,int inR,HashMap<Integer, Integer> map) {
        if (preL > preR) {
            return null;
        }
        TreeNode root = new TreeNode(preOrder[preL]);
        int rootIndex = map.get(preOrder[preL]);
        int leftNum = rootIndex - inL;
        TreeNode left = build(preOrder,inOrder,preL + 1,preL + 1 + leftNum - 1,inL,rootIndex - 1,map);
        TreeNode right = build(preOrder,inOrder,preL + leftNum + 1,preR,rootIndex + 1,inR,map);
        root.left = left;
        root.right = right;
        return root;
    }
}