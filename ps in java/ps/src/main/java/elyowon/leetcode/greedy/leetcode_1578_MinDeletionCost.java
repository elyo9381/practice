
package elyowon.leetcode.greedy;


import java.util.Arrays;

/**
 *
 */

public class leetcode_1578_MinDeletionCost {


    public static void main(String[] args) {
        int[] a = {1,2,3,4,5};
        String s = "abaac";

        int result = minDeleteionCost(s, a);

        System.out.println(result);
    }
    public static int minDeleteionCost(String s,int[] cost) {

        int maxCost = 0;
        int totalCost = 0;
        char lastCh = 0;

        totalCost = getMinDeleteCost(s,cost,maxCost,totalCost,lastCh);


        return totalCost;
    }

    private static int getMinDeleteCost(String s,int[] cost,int maxCost,int totalCost,char lastCh) {
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch != lastCh) {
                lastCh = ch;
                maxCost = cost[i];
            } else {
                if (cost[i] <= maxCost) {
                    totalCost += cost[i];
                } else {
                    totalCost += maxCost;
                    maxCost = cost[i];
                }
            }
        }
        return totalCost;
    }

}
