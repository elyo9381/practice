package elyowon.leetcode;

import org.w3c.dom.Node;

public class ListNode {
    public int val;
    public ListNode next = null;

    public ListNode(int val) {
        this.val = val;
    }

    public ListNode() {

    }

    // 성공 실패는 사실 boolean타입을 넘겨줘야한다.
    public void append(int data){
        ListNode end = new ListNode(data);
        ListNode n = this;
        while(n.next !=null){
            n = n.next;
        }
        n.next = end;
    }

    public void delete(int data){
        ListNode n = this;
        while(n.next != null){
            if(n.next.val == data ){
                n.next = n.next.next;
            } else {
                n = n.next;
            }
        }
    }

    public void retrieve(){
        ListNode n = this;
        while(n.next != null){
            System.out.print(n.val + "->");
            n = n.next;
        }
        System.out.println(n.val);
    }


}