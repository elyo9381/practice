package elyowon.leetcode.Heap;


import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.PriorityQueue;

public class leetcode_295_Median {

    /**
     * maxheap, minheap을 통해서 median값을 구할수있다.
     * <p>
     * 브루트 포스를 사용하면 매번 솔트 해줘야하고 중앙값을 찾아야하므로
     * O(n) + O(nlogn)이 된다. >> O(n)이다.
     * <p>
     * 이대신에 힙을 이용해서 min,max힙을 구성하고 각 힙의 사이즈를 기준으로 min,max를 구성하면
     * O(logN)의 시간복잡도에 구성이 가능하다.
     */


    public class MedianFinder {
        PriorityQueue<Integer> minHeap;
        PriorityQueue<Integer> maxHeap;
        private boolean even = true;

        public MedianFinder() {
            minHeap = new PriorityQueue<>((a,b)->a-b);
            maxHeap = new PriorityQueue<>();
        }


        public void addNum(int num) {
            if (minHeap.size() == 0 && maxHeap.size() == 0) {
                minHeap.add(num);
                return;
            }

            double median = findMedian();
            if (median < num) {
                maxHeap.add(num);
            } else {
                minHeap.add(num);
            }

//            if(maxHeap.isEmpty() || num <= maxHeap.peek()) {
//                maxHeap.add(num);
//            } else {
//                minHeap.add(num);
//            }

            if (maxHeap.size() + 1 < minHeap.size()) {
                maxHeap.add(minHeap.poll());
            } else if (minHeap.size() + 1 < maxHeap.size()) {
                minHeap.add(maxHeap.poll());
            }
        }

        public double findMedian() {
            if (minHeap.size() == maxHeap.size()) {
                return (double) (minHeap.peek() + maxHeap.peek()) / 2;
            } else if (minHeap.size() < maxHeap.size()) {
                return maxHeap.peek();
            } else {
                return minHeap.peek();
            }
        }
    }
}
