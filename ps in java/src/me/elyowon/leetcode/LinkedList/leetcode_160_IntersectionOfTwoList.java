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

        ListNode l3 = new ListNode(8);
        l3.append(4);
        l3.append(5);

        ListNode l4 = l3;

        ListNode l1 = new ListNode(4);
        l1.append(1);

        l1.next.next = l3;


        ListNode l2 = new ListNode(5);
        l2.append(6);
        l2.append(1);

        l2.next.next.next = l4;

        System.out.println();

        l1.retrieve();
        System.out.println();
        l2.retrieve();

        ListNode ret = interSectionListPoint(l1,l2);
        ret.retrieve();



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
