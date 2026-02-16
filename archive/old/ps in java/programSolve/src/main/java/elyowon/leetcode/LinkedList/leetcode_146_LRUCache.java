package elyowon.leetcode.LinkedList;



import elyowon.leetcode.ListNode;
import java.util.HashMap;

public class leetcode_146_LRUCache {

    /**
     * LRU를 만들때 hashMap을 생각할수있다. 검색후에 가장늦게 사용된 데이터를 제거해야하기 떄문이다.
     *
     * 그렇다면 가장 늦게 사용된 데이터는 어떻게 구하는가.?
     * 맵에 배열or리스트를 통해서 구할수있다.
     *
     * 이때 가장 좋은 방법은 해쉬와 더블링크드리스트로 구성하는것이다.
     *
     * 해쉬와 링크드리스트는 각각 접근할수있어야하므로 해쉬는 노드정보, 리스트는 해쉬 key값을 가지고 있어야한다.
     *
     */

    private class Node{
        int key;
        int value;
        Node prev;
        Node next;

        public Node(int key,int value) {
            this.key = key;
            this.value = value;
            this.prev = null;
            this.next = null;
        }
    }


    private int capacity;
    private HashMap<Integer,Node> hs = new HashMap<Integer, Node>();
    private Node head = new Node(-1,-1);
    private Node tail = new Node(-1,-1);


    public leetcode_146_LRUCache(int capacity){
        this. capacity = capacity;
        tail.prev = head;
        head.next = tail;
    }

    public int get(int key) {
        if( !hs.containsKey(key)) {
            return -1;
        }
        Node current = hs.get(key);
        current.prev.next = current.next;
        current.next.prev = current.prev;
        moveToTail(current);

        return hs.get(key).value;
    }

    public void set(int key, int value) {
        if( get(key) != -1) {
            hs.get(key).value = value;
            return;
        }

        if (hs.size() == capacity) {
            hs.remove(head.next.key);
            head.next = head.next.next;
            head.next.prev = head;
        }

        Node insert = new Node(key, value);
        hs.put(key, insert);
        moveToTail(insert);
    }

    // 뒤로 붙여야 하니깐
    private void moveToTail(Node current) {
        current.prev = tail.prev;
        tail.prev = current;
        current.prev.next = current;
        current.next = tail;
    }
}


