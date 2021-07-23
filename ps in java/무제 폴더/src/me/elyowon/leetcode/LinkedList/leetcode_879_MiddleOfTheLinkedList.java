package me.elyowon.leetcode.LinkedList;


import me.elyowon.leetcode.ListNode;

public class leetcode_879_MiddleOfTheLinkedList {


    public static void main(String[] args) {

        ListNode ll = new ListNode(1);
        ll.append(3);
        ll.append(5);
        ll.append(7);
        ll.append(9);

        int result = middle(ll);

        System.out.println("result = " + result);
//        ll.find(result);

    }

    // Fast And Slow Pointer
    private static int middle(ListNode ll) {

        ListNode fast = ll;
        ListNode slow = ll;

        while(fast!=null){
            if(fast.next !=null){
                slow = slow.next;
                fast = fast.next.next;
            }
            else
                break;
        }


        return slow.val;
    }


}
