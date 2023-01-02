package backjoon.greedy

import java.util.*
fun main() {
    var n = readLine()?.toInt() ?: return
    var dasom = readLine()?.toInt()?: return
    val pq = PriorityQueue(Collections.reverseOrder<Int>())
    while (n-- > 1) pq.add(readLine()?.toInt())
    var cnt = 0
    while (!pq.isEmpty() && pq.peek() >= dasom) {
        cnt++
        dasom++
        pq.add(pq.poll() - 1)
    }
    println(cnt)
}





