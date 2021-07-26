package elyowon.leetcode.LinkedList;


import elyowon.leetcode.ListNode;

public class leetcode_86_partitionList {

    /**
     * 문제 : 주어진 List를 x보다 작은수를 먼저, x보다 큰수를 나중에 나오도록 partition하여라.
     * 이때 순서가 list안 node의 순서가 바뀌면 안된다
     *
     * @param args
     */

    public static void main(String[] args) {
        ListNode l1 = new ListNode(1);
        l1.append(7);
        l1.append(2);
        l1.append(5);
        l1.append(6);
        l1.append(3);

        ListNode result = partitionList(l1,2);
        result.retrieve();
    }

    private static ListNode partitionList(ListNode heap,int n) {
        ListNode lessHead = new ListNode(-1);
        ListNode moreHead = new ListNode(-1);
        ListNode less = lessHead;
        ListNode more = moreHead;
        ListNode node = heap;

        while( node != null){
            if(node.val < n){
                less.next = node;
                less = less.next;
            }
            else {
                more.next = node;
                more = more.next;
            }
            node = node.next;
        }
        more.next = null;
        less.next = moreHead.next;

        return lessHead.next;
    }

}
