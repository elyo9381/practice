package elyowon.leetcode.LinkedList;



import elyowon.leetcode.ListNode;
import java.util.LinkedList;

public class leetcode_203_RemoveLinkedListElement {



    public static void main(String[] args) {

        ListNode ll = new ListNode(1);
        ll.append(3);
        ll.append(5);
        ll.append(7);
        ll.append(3);
        ll.append(1);

        ListNode remove = remove(ll,3);
        ListNode iter = iterator(ll,3);

        iter.retrieve();


    }

    private static ListNode iterator(ListNode header,int data) {
        ListNode n = new ListNode();
        n.next = header;

        ListNode curNode = header;
        ListNode preNode = n;

        while(curNode.next != null){
            if(curNode.val == data){
                preNode.next = curNode.next;
                curNode = curNode.next;
            }
            else {
                curNode = curNode.next;
                preNode = preNode.next;

            }
        }

        return n.next;

    }

    private static ListNode remove(ListNode header,int data) {
        if( header == null){
            return header;
        }

        ListNode nextNode = remove(header.next,3);
        if(header.val == data){
            return nextNode;
        }
        else {
            header.next = nextNode;
        }
        return header;
    }

}
