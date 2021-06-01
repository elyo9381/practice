
package me.elyowon.leetcode.greedy;


import java.util.Arrays;
import java.util.stream.IntStream;

/**
 *
 */

public class leetcode_1029_TwoCityScheduling {


    public static void main(String[] args) {
        int[][] a = {{10,20},{30,200},{400,50},{30,20}};


        int result = TwoCityScheduling(a);

        System.out.println(result);
    }

    public static int TwoCityScheduling(int[][] costs) {

        Arrays.sort(costs, ((a,b) ->  (b[1]-b[0]) - (a[1]-a[0])));

        int result = IntStream.range(0,costs.length / 2).map(i -> costs[i][0]).sum()
                + IntStream.range(costs.length / 2,costs.length).map(i -> costs[i][1]).sum();


        return result;
    }
}