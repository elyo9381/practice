package backjoon.greedy

import kotlin.math.min


fun main() {
    val n = readLine()?.trim()?.toInt() ?: return
    val seatInfo = readLine()?.trim()?.split("") ?: return
    // 컵을 꽂을 수 있는 최대 사람의 수
    val coupleCnt = seatInfo.count { it == "L" } / 2
    println(min((n + 1 - coupleCnt), n))

}