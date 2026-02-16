package leetcode.greedy

import java.util.*
import kotlin.math.min


data class Node(val index: Int, val speed: Int, val instructions: Int)



fun checkInterval(intervals: Array<Pair<Int,Int>>): Int {

    val minHeap = PriorityQueue<Pair<Int,Int>> { o1, o2 -> o1.second - o2.second }
    val maxHeap = PriorityQueue<Pair<Int,Int>> { o1, o2 -> o2.second - o1.second }

    var roomCnt = 0

    intervals.sortBy { it.first }

    intervals.forEach {
        if(minHeap.isEmpty()){
            minHeap.add(it)
            roomCnt++
            return@forEach
        }

        if (minHeap.peek().second > it.first) {
            minHeap.add(it)
            roomCnt++
        } else {
            minHeap.poll()
            minHeap.add(it)
        }
    }

    return roomCnt
}
fun checkInterval(intervals: Array<IntArray>): Int {

    val maxHeap = PriorityQueue<Int>(Collections.reverseOrder())
    val minHeap = PriorityQueue<Int>()
    var roomCnt = 0

    intervals.sortBy { it.first() }

    minHeap.add(intervals[0][1])
    roomCnt++


    for (it in 1 until intervals.size) {
        if (minHeap.peek() > intervals[it].first()) {
            minHeap.add(intervals[it].last())
            roomCnt++
        } else {
            minHeap.poll()
            minHeap.add(intervals[it].last())
        }
    }

    return roomCnt
}

fun main(){

    val intervals = arrayOf(
        intArrayOf(9, 11),
        intArrayOf(9, 12),
        intArrayOf(10, 14),
        intArrayOf(12, 16),
        intArrayOf(13, 16),
        intArrayOf(15, 17)
    )
    val intervalsWithPair = arrayOf(
        Pair(9, 11),
        Pair(9, 12),
        Pair(10, 14),
        Pair(12, 16),
        Pair(13, 16),
        Pair(15, 17)
    )
    println(checkInterval(intervals))
    println(checkInterval(intervalsWithPair))
}