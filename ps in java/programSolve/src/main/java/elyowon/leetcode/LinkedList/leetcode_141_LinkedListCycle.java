package elyowon.leetcode.LinkedList;



import elyowon.leetcode.ListNode;
import java.util.HashSet;

public class leetcode_141_LinkedListCycle {


    public static void main(String[] args) {

        ListNode ll = new ListNode(1);
        ll.append(2);
        ListNode cur = ll;
        ll.append(3);
        ll.append(4);
        ll.append(5);
        ll.append(6);
        ll.next = cur.next;

        boolean result = cycleList(ll);

        System.out.println("result = " + result);
        ll.retrieve();


    }

//        HashSet<Integer> check = new HashSet<>(); O(n),O(n)
    // 하지만 공간O(1)로 풀어라 ? >> fast*slow
    private static boolean cycleList(ListNode ll) {
        if (ll == null)
            return false;
        ListNode faster = ll;
        ListNode slower = ll;

        while(faster !=null && slower !=null){
            if(faster == slower) return true;

            if(faster.next != null){
                slower = slower.next;
                faster = faster.next.next;
            } else {
                break;
            }
        }

        return false;
    }


}
