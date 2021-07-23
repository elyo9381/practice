package elyowon.divAndCon;

import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;


public class skyline {


    public static void main(String[] args) {

        int[][] buildings = {{0,2,3},{2,5,3}};
        List<List<Integer>> skyline = getSkyline(buildings);

        for (List<Integer> integers : skyline) {
            for (Integer integer : integers) {
                System.out.println("integer = " + integer);
            }
        }
    }

    public static List<List<Integer>> getSkyline(int[][] buildings) {

        LinkedList<int[]> merge = merge(buildings,0,buildings.length - 1);

        List<List<Integer>> result = new ArrayList<>();
        for (int[] ints : merge) {
            result.add(Arrays.asList(ints[0],ints[1]));
        }
        return result;
    }



    private static LinkedList<int[]> merge(int[][] buildings,int low,int high) {
        LinkedList<int[]> res = new LinkedList<>();

        if (low > high) {
            return res;
        } else if (low == high) {
            res.add(new int[]{buildings[low][0],buildings[low][2]});
            res.add(new int[]{buildings[low][1],0});
            return res;
        }

        int mid = low + (high + low) / 2;

        LinkedList<int[]> left = merge(buildings,low,mid);
        LinkedList<int[]> right = merge(buildings,mid + 1,high);

        int leftH = 0, rightH = 0;

        conquer(res,left,right,leftH,rightH);
        return res;
    }

     protected static void conquer(LinkedList<int[]> res,LinkedList<int[]> left,LinkedList<int[]> right,int leftH,int rightH) {
        while (!left.isEmpty() || !right.isEmpty()) {
            long x1 = left.isEmpty() ? Long.MAX_VALUE : left.peekFirst()[0];
            long x2 = right.isEmpty() ? Long.MAX_VALUE : right.peekFirst()[0];

            int x = 0;
            if (x1 < x2) {
                int[] temp = left.pollFirst();
                x = temp[0];
                leftH = temp[1];
            } else if (x1 > x2) {
                int[] temp = right.pollFirst();
                x = temp[0];
                rightH = temp[1];
            } else {
                x = left.peekFirst()[0];
                leftH = left.pollFirst()[1];
                rightH = right.pollFirst()[1];
            }

            int h = Math.max(leftH,rightH);
            if (res.isEmpty() || h != res.peekLast()[1]) {
                res.add(new int[]{x,h});
            }
        }
    }
}

class Solution {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        List<int[]> heights = new ArrayList<>();
        for (int[] b : buildings) {
            heights.add(new int[]{b[0],-b[2]});
            heights.add(new int[]{b[1],b[2]});
        }
        Collections.sort(heights,(a,b) -> (a[0] == b[0]) ? a[1] - b[1] : a[0] - b[0]);
        TreeMap<Integer, Integer> heightMap = new TreeMap<>(Collections.reverseOrder());
        heightMap.put(0,0);
        int prevHeight = 0;
        List<List<Integer>> skyLine = new LinkedList<>();
        for (int[] h : heights) {
            if (h[1] < 0) {
                Integer cnt = heightMap.get(-h[1]);
                cnt = (cnt == null) ? 0 : cnt;
                heightMap.put(-h[1],cnt);
            } else {
                Integer cnt = heightMap.get(h[1]);
                if (cnt == 0) {
                    heightMap.remove(h[1]);
                } else {
                    heightMap.put(h[1],cnt);
                }
            }
            int currHeight = heightMap.firstKey();// treeMap은 이진트리이고 defalut는 오름 차순이라.
            if (prevHeight != currHeight) {
                List<Integer> list = new ArrayList<>();
                list.add(h[0]);
                list.add(currHeight);
                skyLine.add(list);
                prevHeight = currHeight;
            }
        }
        return skyLine;
    }
}
