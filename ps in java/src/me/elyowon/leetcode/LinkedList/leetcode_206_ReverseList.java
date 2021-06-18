package me.elyowon.leetcode.LinkedList;


import me.elyowon.leetcode.ListNode;

public class leetcode_206_ReverseList {

    /**
     * reverse list 만들기
     *
     * iterator , recursion 방법들
     *
     * @param args
     */

    public static void main(String[] args) {
        ListNode l1 = new ListNode(1);
        l1.append(2);
        l1.append(4);
        l1.append(5);
        l1.append(8);

//        ListNode ret = reverseList_iter(l1);
        ListNode ret = reverseList_recur(l1);
        ret.retrieve();



    }

    private static ListNode reverseList_recur(ListNode head) {
        if (head == null) {
            return head;
        } else if (head.next == null){
            return head;
        }

        ListNode back = reverseList_recur(head.next);
        head.next.next = head;
        head.next = null;
        return back;
    }

    private static ListNode reverseList_iter(ListNode head) {

        if( head == null ) return null;
        else if( head.next == null) return null;

        ListNode cur = head.next;
        ListNode prev = head;
        head.next = null;

        while(cur != null){
            ListNode tmp = cur.next;
            cur.next = prev;
            prev = cur;
            cur = tmp;
        }

        return prev;
    }
}
