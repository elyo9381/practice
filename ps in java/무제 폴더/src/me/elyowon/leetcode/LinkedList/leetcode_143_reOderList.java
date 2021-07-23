package me.elyowon.leetcode.LinkedList;


import me.elyowon.leetcode.ListNode;

public class leetcode_143_reOderList {

    /**
     * 주어진 리스트를
     * 1 , 9 , 3, 7 ,5 로 배치하여 리스트 반환하기
     *
     *
     * @param args
     */

    public static void main(String[] args) {
        ListNode l1 = new ListNode(1);
        l1.append(3);
        l1.append(5);
        l1.append(7);
        l1.append(9);

        ListNode result = partitionList(l1,2);
        result.retrieve();
    }

    private static ListNode partitionList(ListNode heap,int n) {


        return null;
    }

}
