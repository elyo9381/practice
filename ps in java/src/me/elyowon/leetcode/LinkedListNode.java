package me.elyowon.leetcode;

public class LinkedListNode {

    ListNode header;

    public static class ListNode{
        public int val;
        public ListNode next = null;

    }

    public LinkedListNode() {
        header = new ListNode();
    }

    public void addHead(int data){
        ListNode n = header;
        ListNode first = new ListNode();
        first.val = data;

        first.next = n.next;
        n.next = first;
    }

    // 성공 실패는 사실 boolean타입을 넘겨줘야한다.
    public void addback(int data){
        ListNode end = new ListNode();
        end.val = data;
        ListNode n = header;
        while(n.next !=null){
            n = n.next;
        }
        n.next = end;
    }

    public ListNode find(int data){
        ListNode n = header;
        while(n.next != null){
            if(n.val == data){
                return n;
            }
            n = n.next;
        }

        return null;
    }

    public void addAfter(ListNode node, int data){
        ListNode newNode = new ListNode();
        newNode.val = data;
        newNode.next = node.next;
        node.next = newNode;
    }

    public void deleteAfter(ListNode preNode){
        if(preNode.next != null){
            preNode.next = preNode.next.next;
        }
    }

    public void delete(int data){
        ListNode n = header;
        while(n.next != null){
            if(n.next.val == data ){
                n.next = n.next.next;
            } else {
                n = n.next;
            }
        }
    }

    public void retrieve(){
        ListNode n = header.next;
        while(n.next != null){
            System.out.print(n.val + "->");
            n = n.next;
        }
        System.out.println(n.val);
    }

    public void removeDups(){
        ListNode n = header;
        while(n != null && n.next !=null){
            ListNode r = n;
            while(r.next != null){
                if(n.val == r.next.val){
                    r.next = r.next.next;
                } else {
                    r = r.next;
                }
            n = n.next;
            }
        }
    }



}