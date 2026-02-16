package elyowon.leetcode.LinkedList;


import elyowon.leetcode.ListNode;

public class leetcode_19_nNodeDelete {

    /**
     * 두개의 리스트를 역방향 순방향으로 더해서 각 자리수를 리스트로 만들어라
     *
     * 445
     *
     * @param args
     */

    public static void main(String[] args) {
        ListNode l1 = new ListNode(1);
        l1.append(2);
        l1.append(3);
        l1.append(4);
        l1.append(5);

        ListNode result = nNodeDelete(l1,2);
        result.retrieve();
    }

    private static ListNode nNodeDelete(ListNode head,int n) {
        ListNode fakeHead = new ListNode(-1);

        fakeHead.next = head;
        ListNode first = fakeHead;
        ListNode second = fakeHead;

        for (int i = 0; i < n; i++) {
            first = first.next;
        }

        while(first.next != null){
            first = first.next;
            second = second.next;
        }

        second.next = second.next.next;

        return fakeHead.next;





    }

}
