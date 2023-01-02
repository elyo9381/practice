package backjoon.greedy

import java.util.Collections.max
import kotlin.math.max

fun main(){
    val n = readLine()?.toInt()
    val dragons = readLine()?.split(" ")?.map { it.toInt() }?.toMutableList() ?: return

    var maxValue = 0
    var cnt = 0
    var killer = 0
    (1 until dragons.size).forEach { index ->
        if( dragons[killer] < dragons[index]) {
            killer = index
            cnt = 0
        } else {
            cnt++;
        }
        maxValue = max( maxValue, cnt)
    }
    println(maxValue)

}