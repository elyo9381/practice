package me.elyowon.leetcode.LinkedList;


import me.elyowon.leetcode.LinkedListNode;
import me.elyowon.leetcode.ListNode;

public class leetcode_LinkedList {



    public static void main(String[] args) {

//        ListNodeTest();

        LinkedListNodeTest();



    }

    private static void LinkedListNodeTest() {
        LinkedListNode ll = new LinkedListNode();
        ll.addHead(1);
        ll.addHead(2);
        ll.addback(3);
        LinkedListNode.ListNode listNode1 = ll.find(1);
        ll.addAfter(listNode1,4);
        LinkedListNode.ListNode listNode2 = ll.find(3);
        ll.deleteAfter(listNode2);

        ll.retrieve();



    }

    private static void ListNodeTest() {
        ListNode head = new ListNode(1);

        head.append(2);
        head.append(3);
        head.delete(3);
        head.append(4);
        head.retrieve();
    }
}
