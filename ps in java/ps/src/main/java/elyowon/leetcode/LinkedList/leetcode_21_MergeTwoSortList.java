package elyowon.leetcode.LinkedList;


import elyowon.leetcode.ListNode;

public class leetcode_21_MergeTwoSortList {


    public static void main(String[] args) {

        ListNode ll = new ListNode(1);
        ll.append(3);
        ll.append(5);

        ListNode ll2 = new ListNode(1);
        ll2.append(2);
        ll2.append(5);


        ListNode remove = mergeSort(ll,ll2);

        remove.retrieve();


    }

    private static ListNode mergeSort(ListNode l1,ListNode l2) {

        ListNode dummy = new ListNode();
        ListNode cur = dummy;

        while( l1 != null && l2 != null){
            if(l1.val <= l2.val){
                cur.next = l1;
                l1 = l1.next;
            } else {
                cur.next = l2;
                l2 = l2.next;
            }
            cur = cur.next;
        }

        if(l1 == null){
            cur.next = l2;
        } else {
            cur.next = l1;
        }
        return dummy.next;
    }


}
