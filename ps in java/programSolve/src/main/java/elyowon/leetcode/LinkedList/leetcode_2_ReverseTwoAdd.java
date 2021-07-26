package elyowon.leetcode.LinkedList;


import elyowon.leetcode.ListNode;

public class leetcode_2_ReverseTwoAdd {

    /**
     * 두개의 리스트를 역방향 순방향으로 더해서 각 자리수를 리스트로 만들어라
     *
     * 445
     *
     * @param args
     */

    public static void main(String[] args) {
        ListNode l1 = new ListNode(7);
        l1.append(5);
        l1.append(3);

        ListNode l2 = new ListNode(4);
        l2.append(8);
        l2.append(2);

        ListNode listNode = addReverse(l1,l2);
        listNode.retrieve();
        ListNode result = addForward(l1,l2);
        result.retrieve();
    }

    private static ListNode addReverse(ListNode l1,ListNode l2) {
        ListNode dummy = new ListNode(-1);
        ListNode cur = dummy;

        ListNode nodeA = l1;
        ListNode nodeB = l2;

        int carry = 0;

        while (nodeA != null || nodeB != null) {
            int numA = 0;
            int numB = 0;

            if( nodeA != null){
                numA = nodeA.val;
                nodeA = nodeA.next;
            }
            if( nodeB != null){
                numB = nodeB.val;
                nodeB = nodeB.next;
            }

            int sum = numA + numB + carry;
            carry = sum / 10;
            int val = sum % 10;

            ListNode newNode = new ListNode(val);
            cur.next = newNode;
            cur = cur.next;
        }
        if( carry > 0) {
            cur.next = new ListNode(carry);
        }

        return dummy.next;


    }

    private static ListNode addForward(ListNode l1,ListNode l2) {
        ListNode reNodeA = reverseList(l1);
        ListNode reNodeB = reverseList(l2);

        ListNode sumReverse = addReverse(reNodeA,reNodeB);

        ListNode result = reverseList(sumReverse);

        return result;
    }

    private static ListNode reverseList(ListNode head) {
        if(head == null){
            return null;
        } else if( head.next == null){
            return null;
        }

        ListNode cur = head.next;
        ListNode pre = head;
        head.next = null;

        while(cur != null){
            ListNode tmp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = tmp;
        }

        return pre;
    }


}
