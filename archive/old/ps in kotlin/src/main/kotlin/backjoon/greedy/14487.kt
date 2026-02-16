package backjoon.greedy


fun main() {

    val n = readLine()?.trim()?.toInt() ?: return
    val movePrices = readLine()?.split(" ") ?: return
    println(movePrices.sumOf { it.toInt() }.minus(movePrices.maxOf { it.toInt() }))

}