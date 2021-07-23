package me.elyowon.leetcode.Heap;


import me.elyowon.leetcode.ListNode;

import java.util.*;

public class leetcode_23_Merge_k_sortedList {

    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length == 0){
            return null;
        }
        PriorityQueue<ListNode> minHeap = new PriorityQueue<>((a, b) -> b.val - a.val);

        for (ListNode list : lists) {
            if(list != null){
                minHeap.add(list);
            }
        }

        ListNode dummyHead = new ListNode(-1);
        ListNode curNode = dummyHead;
        while (!minHeap.isEmpty()) {
            ListNode n = minHeap.poll();
            if (n.next != null) {
                minHeap.add(n.next);
            }
            n.next = null;
            curNode.next = n;
            curNode = n;
        }
        return dummyHead.next;

    }


}
