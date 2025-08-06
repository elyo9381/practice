package backjoon.greedy


fun main() {

    val (n,l,k) = readLine()?.split(" ")?.map { it.toInt() }?.toIntArray() ?: return
    println((1..n).fold(mutableListOf<Int>()) { result, _ ->
        val count = readLine()
            ?.split(" ")
            ?.map { it.toInt() }
            ?.toIntArray()
            ?.count { it <= l } ?: -1

        result.also { it += calculateScore(count) }
    }.sortedByDescending { it }.slice(0 until k).sum())


}
private fun calculateScore(count: Int) = when {
    count > 1 -> 140
    count == 1 -> 100
    else -> 0
}
