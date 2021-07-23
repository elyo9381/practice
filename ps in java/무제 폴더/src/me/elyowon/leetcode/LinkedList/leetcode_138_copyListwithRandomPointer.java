package me.elyowon.leetcode.LinkedList;


import java.util.HashMap;

public class leetcode_138_copyListwithRandomPointer {

    /**
     * r 이라는 랜덤 포인터가 존재한다. 이를 deep 카피 해야하는 문제이다
     * 이때 r을 딥카피 하는 방법은 두가지가 존재한다.
     * 해쉬맵을 이용하여 매칭한다음 그것을 확인하며 r을 복사하는 방법
     *
     *  curr_r 를 통하여 curr_w, 작성하고 curr_w에서 curr_r의 방향으로 연결리스트를 작성한다.
     *  그리고 한번 더 돌아서 r의 연결을 진행하고
     *  또 마지막으로 한번 더돌아 각각의 노드를 다음노드로 바꿔주면된다.
     *
     *  전자는 n,n으로 진행되며, 후자는 n,1로진행된다.
     *
     * @param args
     */

    public static void main(String[] args) {

    }

    private static Node copyListwithRandomPointer(Node head) {
        HashMap<Node, Node> map = new HashMap<Node, Node>();

        Node original = head;

        while(original != null){
            Node node = new Node(original.val);
            map.put(original, node);
            original = original.next;
        }

        original = head;

        while( original != null){
            Node copied = map.get(original);
            copied.next = map.get(original.next);
            copied.random = map.get(original.random);
            original = original.next;
        }
        return map.get(head);
    }

    private static Node copyRandomList(Node head){
        if(head == null) return null;
        Node node = head;
        while(node != null){
            Node copied = new Node(node.val);
            copied.next = node.next;
            node.next = copied;
            node = node.next.next;
        }

        Node res = head.next;
        node = head;
        while( node != null){
            Node copied = node.next;
            if(node.random != null){
                node.next.random = node.random.next;
            }
            node = node.next.next;
        }

        node = head;
        while(node != null){
            Node copied = node.next;
            node.next = copied.next;
            node = copied.next;
            copied.next = node == null? null:node.next;
        }

        return res;
    }


      static class Node {
          int val;
          Node next, random;
          Node(int x) { this.val = x; }
      };


}
