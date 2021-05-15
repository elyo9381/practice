package me.elyowon.leetcode.LinkedList;


import me.elyowon.leetcode.ListNode;

public class leetcode_160_IntersectionOfTwoList {

    /**
     * 교차점 찾기 문제
     * 4,1,8,4,5
     * 5,6,1,8,4,5
     *
     * @param args
     */

    public static void main(String[] args) {
        ListNode l1 = new ListNode(4);
        l1.append(2);
        l1.append(8);
        l1.append(4);
        l1.append(5);

        ListNode l2 = new ListNode(8);
        l1.append(4);
        l1.append(5);
        System.out.println();

        ListNode ret = interSectionListPoint(l1,l2);
        if(ret != null){
            ret.retrieve();
        }




    }

    private static ListNode interSectionListPoint(ListNode l1,ListNode l2) {
        if(l1 == null || l2 == null) return null;
        ListNode a = l1;
        ListNode b = l2;

        while (a != b) {
            a = a == null ? l2 : a.next;
            b = b == null ? l1 : b.next;
        }
        return a;
    }



}
